OUTPUT_FORMAT("ss-coff-little", "ss-coff-big",
	      "ss-coff-little")
 SEARCH_DIR(/home/zhoutao/Desktop/Arch/sslittle-na-sstrix/lib);
ENTRY(__start)
SECTIONS
{
  . = 0x400000 + SIZEOF_HEADERS;
  .text : {
     _ftext = . ;
    *(.init)
     eprol  =  .;
    *(.text)
    *(.fini)
     etext  =  .;
     _etext  =  .;
  }
  . = 0x10000000;
  .rdata : {
    *(.rdata)
  }
   _fdata = .;
  .data : {
    *(.data)
    CONSTRUCTORS
  }
   _gp = ALIGN(16) + 0x8000;
  .lit8 : {
    *(.lit8)
  }
  .lit4 : {
    *(.lit4)
  }
  .sdata : {
    *(.sdata)
  }
   edata  =  .;
   _edata  =  .;
   _fbss = .;
  .sbss : {
    *(.sbss)
    *(.scommon)
  }
  .bss : {
    *(.bss)
    *(COMMON)
  }
   end = .;
   _end = .;
}
