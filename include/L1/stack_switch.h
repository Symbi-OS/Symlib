#ifndef __SYM_STACK_SWITCH__
#define __SYM_STACK_SWITCH__

#ifdef CONFIG_X86_64
#include "../../arch/x86_64/L1/stack_switch.h"
#endif

// These must be used as a pair
#define SYM_ON_KERN_STACK() \
    uint64_t user_stack; \
    SYM_PRESERVE_USER_STACK(user_stack); \
    SYM_SWITCH_TO_KERN_STACK();

#define SYM_ON_USER_STACK() \
    SYM_RESTORE_USER_STACK(user_stack);

// Combine the two above so we don't have to remember to call both
// but put all of user code inbetween
#define SYM_ON_KERN_STACK_DO(fn) \
    SYM_ON_KERN_STACK(); \
    fn; \
    SYM_ON_USER_STACK();
#endif
