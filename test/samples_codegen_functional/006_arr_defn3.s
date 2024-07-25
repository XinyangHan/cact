   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -96
   sd s0, 88(sp)
   sd ra, 80(sp)
   sd s1, 72(sp)
   sd s2, 64(sp)
   addi s0, sp, 96
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
   sw s1, -40(s0)
   li s1, 0
   sw s1, -36(s0)
   li s1, 1
   sw s1, -96(s0)
   li s1, 2
   sw s1, -92(s0)
   li s1, 3
   sw s1, -88(s0)
   li s1, 4
   sw s1, -84(s0)
   li s1, 5
   sw s1, -80(s0)
   li s1, 6
   sw s1, -76(s0)
   li s1, 7
   sw s1, -72(s0)
   li s1, 8
   sw s1, -68(s0)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 3
   li s3, 8
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 1
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 0
   li s3, 0
   add s2, s2, s3
   li s3, 0
   li s4, 8
   mul s3, s3, s4
   add s2, s2, s3
   li s3, 0
   li s4, 4
   mul s3, s3, s4
   add s2, s2, s3
   add s1, s0, s1
   lw s1, -96(s1)
   add s2, s0, s2
   lw s2, -96(s2)
   add s1, s1, s2
   li s2, 0
   li s3, 0
   add s2, s2, s3
   li s3, 0
   li s4, 8
   mul s3, s3, s4
   add s2, s2, s3
   li s3, 1
   li s4, 4
   mul s3, s3, s4
   add s2, s2, s3
   add s2, s0, s2
   lw s2, -96(s2)
   add s1, s1, s2
   li s2, 0
   li s3, 0
   add s2, s2, s3
   li s3, 2
   li s4, 8
   mul s3, s3, s4
   add s2, s2, s3
   li s3, 0
   li s4, 4
   mul s3, s3, s4
   add s2, s2, s3
   add s2, s0, s2
   lw s2, -64(s2)
   add s1, s1, s2
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

