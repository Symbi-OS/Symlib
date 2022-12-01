#ifndef __ARCH_X86_64_SYM_LIB__
#define __ARCH_X86_64_SYM_LIB__

/* #include <unistd.h> */
/* #include <sys/syscall.h> */

/* #include "L0/sym_lib.h" */
//TODO: make this save for migrated processes. As it stands a migrated symbiote will have a gs base pointer into the wrong core

#define GET_KERN_GS_CLOBBER_USER_GS                           \
  asm("movl $0xc0000102, %%ecx; rdmsr; movl $0xc0000101, %%ecx; wrmsr; sti;" :: :"%rax", "%edx", "%ecx");

#endif //__ARCH_X86_64_SYM_LIB__
