   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -32
   sd s0, 24(sp)
   sd ra, 16(sp)
   sd s1, 8(sp)
   sd s2, 0(sp)
   addi s0, sp, 32
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 4
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar0
   add s1, s2, s1
   lw s1, 0(s1)
   mv a0, s1
   ld s0, 24(sp)
   ld ra, 16(sp)
   ld s1, 8(sp)
   ld s2, 0(sp)
   addi sp, sp, 32
   ret
   ld s0, 24(sp)
   ld ra, 16(sp)
   ld s1, 8(sp)
   ld s2, 0(sp)
   addi sp, sp, 32
   ret

   .globl GVar0
   .data
   .align 3
   .type GVar0, @object
   .size GVar0, 20
   GVar0:
   .word 0
   .word 1
   .word 2
   .word 3
   .word 4
