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
   li s1, 0
   sw s1, -40(s0)
   li s1, 0
   sw s1, -44(s0)
   li s1, 0
   sw s1, -48(s0)
   li s1, 10
   sw s1, -36(s0)
   li s2, 4
   sw s2, -40(s0)
   li s3, 2
   sw s3, -44(s0)
   li s4, 2
   sw s4, -48(s0)
   add s5, s3, s1
   sub s6, s2, s4
   mul s5, s5, s6
   mv a0, s5
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

