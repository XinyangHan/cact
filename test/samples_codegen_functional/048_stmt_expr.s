   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s1, 0
   sw s1, -36(s0)
   li s1, 1
   la s2, GVar0
   sw s1, 0(s2)
L0:
   la s2, GVar1
   lw s2, 0(s2)
   li s1, 1
   sub s1, s2, s1
   lw s2, -36(s0)
   blt s1, s2, L1
   lw s1, -36(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -36(s0)
   la s2, GVar0
   lw s2, 0(s2)
   li s1, 1
   add s1, s2, s1
   la s1, GVar0
   lw s1, 0(s1)
   add s1, s2, s1
   la s2, GVar0
   sw s1, 0(s2)
   j L0
L1:
   la s2, GVar0
   lw s2, 0(s2)
   mv a0, s2
   call print_int
   mv a0, s2
   ld s0, 40(sp)
   ld ra, 32(sp)
   ld s1, 24(sp)
   ld s2, 16(sp)
   addi sp, sp, 48
   ret
   ld s0, 40(sp)
   ld ra, 32(sp)
   ld s1, 24(sp)
   ld s2, 16(sp)
   addi sp, sp, 48
   ret

   .globl GVar0
   .bss
   .align 2
   .type GVar0, @object
   .size GVar0, 4
   GVar0:
   .zero 4

   .globl GVar1
   .data
   .align 2
   .type GVar1, @object
   .size GVar1, 4
   GVar1:
   .word 10
