   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global doubleWhile
   .type doubleWhile, @function
   doubleWhile:
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s1, 0
   sw s1, -36(s0)
   li s1, 5
   sw s1, -36(s0)
   li s2, 0
   sw s2, -40(s0)
   li s2, 7
   sw s2, -40(s0)
L0:
   lw s1, -36(s0)
   li s2, 100
   bge s1, s2, L1
   lw s1, -36(s0)
   li s2, 30
   add s1, s1, s2
   sw s1, -36(s0)
L2:
   lw s2, -40(s0)
   li s1, 100
   bge s2, s1, L3
   lw s1, -40(s0)
   li s2, 6
   add s1, s1, s2
   sw s1, -40(s0)
   j L2
L3:
   lw s2, -40(s0)
   li s1, 100
   sub s1, s2, s1
   sw s1, -40(s0)
   j L0
L1:
   lw s2, -40(s0)
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
   call doubleWhile
   mv s2, a0
   mv a0, s2
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

