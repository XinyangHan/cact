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
   li s1, 5
   sw s1, -36(s0)
   lw s1, -36(s0)
   la s2, GVar1
   lw s2, 0(s2)
   add s1, s1, s2
   mv a0, s1
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
   .data
   .align 2
   .type GVar0, @object
   .size GVar0, 4
   GVar0:
   .word 3
   .globl GVar1
   .data
   .align 2
   .type GVar1, @object
   .size GVar1, 4
   GVar1:
   .word 5
