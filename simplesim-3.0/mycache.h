typedef struct ucache_line_t{
	unsigned int tag;
	word_t data[4]; //the pointer to 4 word
	unsigned int dirty;
	unsigned int valid;

	struct ucache_line_t *prev;
	struct ucache_line_t *next;
} ucache_line_t;

typedef struct ucache_set_t{
	ucache_line_t* head;
	ucache_line_t* tail;
	ucache_line_t lines[4];
} ucache_set_t;

typedef struct ucache_t{

	ucache_set_t sets[16];
	//some states statistics (20)
	int access;
	int miss;
	int hit;
	int replace;
	int write_back;
} ucache_t;

#define ADDR_TAG(ADDR) (((unsigned int)ADDR)>>8)
// 4 bit index
#define ADDR_INDEX(ADDR) ((((unsigned int)ADDR) & 0xf0)>>4)
// 4 bit line displacement (4 word * 4 byte)
#define ADDR_BLOCK(ADDR) ((((unsigned int)ADDR) & 0xc)>>2) 

struct ucache_t* ucache_init();
struct ucache_t* ucache_shm_init(key_t key, int *shmid);
int							
ucache_access(ucache_t* cp,
			enum mem_cmd cmd,	/*the pointer to the cache*/
			md_addr_t addr,
			word_t* data,    	/*the data to store or the pointer to load data*/
			int size);	/*how many word to read*/

// flush all data that is valid and dirty
void ucache_flush(ucache_t* cp/*the pointer to the cache*/);

