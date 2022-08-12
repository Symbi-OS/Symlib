#ifndef __ARCH_X86_64_SYM_LIB__
#define __ARCH_X86_64_SYM_LIB__

/* #include <unistd.h> */
/* #include <sys/syscall.h> */

/* #include "L0/sym_lib.h" */
#define ARLO_GS
//TODO: make this save for migrated processes. As it stands a migrated symbiote will have a gs base pointer into the wrong core
#ifdef ARLO_GS
#define GET_KERN_GS_CLOBBER_USER_GS                           \
  asm("movl $0xc0000102, %%ecx; rdmsr; movl $0xc0000101, %%ecx; wrmsr; sti;" :: :"%rax", "%edx", "%ecx");
#else
// get onto kern gs
// Store kern gs
// get onto user gs
// Overwrite user gs with kern gs
// make interruptable
#define GET_KERN_GS_CLOBBER_USER_GS                           \
  asm("swapgs");                                              \
  asm("rdgsbase %0" : "=rm"(kern_gs) :: );                    \
  asm("swapgs");                                              \
  asm("wrgsbase %0" :: "r"(kern_gs) );                        \
  asm("sti");

#endif //ARLO_GS
#endif
