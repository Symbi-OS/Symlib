#include <stdio.h>
#include "L0/sym_lib_hacks.h"

#ifdef CONFIG_X86_64
// TODO turn this into a header?
#include "../arch/x86_64/L0/sym_lib_hacks.h"
#endif

#ifndef CONFIG_DYNAMIC
extern char __executable_start;
extern char __etext;
#endif

extern void sym_touch_every_page_text(){
#ifndef CONFIG_DYNAMIC
  unsigned char *p;
  p = (unsigned char *) &__executable_start;

  unsigned char VARIABLE_IS_NOT_USED c;
  for(; p < (unsigned char *)&__etext; p+= (1<<12))
    c = *p;
#else
  // TODO: use this tool to remove unintended use of this fn in the dynam case.
  // fprintf(stderr, "sym_touch_every_page_text() not implemented for dynamic\n");
#endif
}

extern void sym_touch_stack(){
  // Num times to push
  int count = 1<<16;

  int i;
  // Touch a bunch of stack pages
  for(i=0; i < count; i++){
    // TODO put these in .h header.
    PUSH_JUNK
  }

  // Pop them all off
  for(i=0; i < count; i++){
    // Find a way to make clobber rax arch agnostic
    POP_JUNK
  }
}
