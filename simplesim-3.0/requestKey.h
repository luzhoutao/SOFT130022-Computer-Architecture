#include "pipe.h"

#ifndef REQUEST_KEY
#define REQUEST_KEY

#ifndef Ready
#define Ready 1
#endif

#define INIT_KEY 101

struct key_buf_t{
  key_t cur_key;
  int status;
};

struct Item_shmid{
  int shmid;
  struct Item_shmid *next;
};

static struct key_buf_t *key_buf;

static key_t key_buf_key;
static int key_buf_shmid;

struct Item_shmid* list1, *list2;
struct Item_shmid** cur_list;

void mem_init_key_buf(){
    key_buf_key = 100;
    key_buf = (struct key_buf_t *)Shmalloc(key_buf_key, sizeof(struct key_buf_t), &key_buf_shmid);
    key_buf->cur_key = INIT_KEY;
    key_buf->status = Ready;

    list1 = NULL;
    list2 = NULL;
    cur_list = &list1;
}

void *mem_get_new_shm(size_t size){
    key_t cur_key;
    WAIT_WHILE_STATUS(key_buf->status, ==, !Ready);
    fprintf(stderr, "get the lock to obtain a new key\n");
    SET_STATUS(key_buf->status, !Ready);
    cur_key = key_buf->cur_key;
    key_buf->cur_key++;
    SET_STATUS(key_buf->status, Ready);
    
    struct Item_shmid *cur_shmid = calloc(1, sizeof(struct Item_shmid));
    cur_shmid->next = (*cur_list);
    (*cur_list) = cur_shmid;  //revise list1
    return Shmalloc(cur_key, size, &(cur_shmid->shmid));
}

void mem_change_shmid_list(){
    cur_list = &list2;
}

void mem_print_shmid_list(){
    fprintf(stderr, "list1 = 0x%x, list2 = 0x%x, cur_list = 0x%x\n", list1, list2, *cur_list);
}
void mem_free_prev_page(){
     Shmfree(key_buf_shmid);

     struct Item_shmid *cur = list1;
     while(cur!=NULL){
         Shmfree(cur->shmid);
         cur = cur -> next;
     }
}

void mem_free_other_pages(){
     struct Item_shmid *cur = list2;
     while(cur!=NULL){
         Shmfree(cur->shmid);
         cur = cur -> next;
     }
}
#endif
