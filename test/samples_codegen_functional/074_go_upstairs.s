   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global climbStairs
   .type climbStairs, @function
   climbStairs:
   addi sp, sp, -96
   sd s0, 88(sp)
   sd ra, 80(sp)
   sd s1, 72(sp)
   sd s2, 64(sp)
   addi s0, sp, 96
   li s1, 4
   bge a0, s1, L0
   mv a0, a0
   ld s0, 88(sp)
   ld ra, 80(sp)
   ld s1, 72(sp)
   ld s2, 64(sp)
   addi sp, sp, 96
   ret
L0:
   li s1, 0
   sw s1, -80(s0)
   li s1, 0
   sw s1, -76(s0)
   li s1, 0
   sw s1, -72(s0)
   li s1, 0
   sw s1, -68(s0)
   li s1, 0
   sw s1, -64(s0)
   li s1, 0
   sw s1, -60(s0)
   li s1, 0
   sw s1, -56(s0)
   li s1, 0
   sw s1, -52(s0)
   li s1, 0
   sw s1, -48(s0)
   li s1, 0
   sw s1, -44(s0)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 0
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 0
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 1
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 1
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 2
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 2
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   sw s1, -84(s0)
   li s1, 3
   sw s1, -84(s0)
L1:
   li s1, 1
   add s1, a0, s1
   lw s2, -84(s0)
   bge s2, s1, L2
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -84(s0)
   li s3, 4
   mul s3, s2, s3
   add s1, s1, s3
   li s3, 0
   li s4, 0
   add s3, s3, s4
   li s4, 1
   sub s4, s2, s4
   li s5, 4
   mul s4, s4, s5
   add s3, s3, s4
   li s4, 0
   li s5, 0
   add s4, s4, s5
   li s5, 2
   sub s5, s2, s5
   li s6, 4
   mul s5, s5, s6
   add s4, s4, s5
   add s3, s0, s3
   lw s3, -80(s3)
   add s4, s0, s4
   lw s4, -80(s4)
   add s3, s3, s4
   add s1, s0, s1
   sw s3, -80(s1)
   li s1, 1
   add s1, s2, s1
   sw s1, -84(s0)
   j L1
L2:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   li s2, 4
   mul s2, a0, s2
   add s1, s1, s2
   add s1, s0, s1
   lw s1, -80(s1)
   mv a0, s1
   ld s0, 88(sp)
   ld ra, 80(sp)
   ld s1, 72(sp)
   ld s2, 64(sp)
   addi sp, sp, 96
   ret
   ld s0, 88(sp)
   ld ra, 80(sp)
   ld s1, 72(sp)
   ld s2, 64(sp)
   addi sp, sp, 96
   ret
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
   li s1, 5
   sw s1, -40(s0)
   mv a0, s1
   call climbStairs
   mv s2, a0
   sw s2, -36(s0)
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

