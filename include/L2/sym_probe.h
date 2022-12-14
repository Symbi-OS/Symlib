#ifndef __SYM_PROBE_LIB__
#define __SYM_PROBE_LIB__
#include "L0/sym_structs.h"

#ifdef CONFIG_X86_64
#include "../../arch/x86_64/L2/sym_probe.h"
#endif

// License C 2021-
// Author: Thomas Unger
// Level: 2

#define X86_TRAP_BP		 3
#define X86_TRAP_DB		 1


#define TRAP_HANDLER(LAB, TARG)                \
  NEW_HANDLER(LAB)                             \
    PUSH_FAKE_ERROR                               \
    PUSH_REGS                                  \
    GET_PT_REG_PTR                                \
    CALL_TARG(TARG)                              \
    POP_REGS                                   \
    DROP_FAKE_ERROR                               \
    IRET

#define DB_REGS			4

enum db_flag{
  DB_LOCAL,
  DB_GLOBAL
};

void sym_probe_init();

// Place a software interrupt generating instruction at addr.
unsigned char sym_set_probe(uint64_t addr);
unsigned char sym_set_db_probe(uint64_t addr, uint64_t reg, uint64_t db_flag);

// Replace software interrupt generating instruction with byte.
void sym_remove_probe(void *addr, unsigned char old_byte);
void sym_remove_db_probe(void *addr, unsigned char old_byte);

void sym_interpose_on_int3_ft_asm(unsigned char* new_idt);
void sym_interpose_on_int3_ft_c(unsigned char* new_idt);

void int3_jmp_to_c(void);
void db_jmp_to_c(void);

void sym_interpose_on_db_ft_asm(unsigned char* new_idt);
void sym_interpose_on_db_ft_c(unsigned char* new_idt);

// Get current idt handler page / scratchpad page installed on a given core
uint64_t get_hdl_pg(int core);
uint64_t get_scratch_pg(int core);

#endif
