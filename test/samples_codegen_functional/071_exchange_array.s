   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -160
   sd s0, 152(sp)
   sd ra, 144(sp)
   sd s1, 136(sp)
   sd s2, 128(sp)
   addi s0, sp, 160
   li s1, 1
   sw s1, -136(s0)
   li s1, 1
   sw s1, -132(s0)
   li s1, 1
   sw s1, -128(s0)
   li s1, 1
   sw s1, -124(s0)
   li s1, 1
   sw s1, -120(s0)
   li s1, 2
   sw s1, -116(s0)
   li s1, 2
   sw s1, -112(s0)
   li s1, 2
   sw s1, -108(s0)
   li s1, 2
   sw s1, -104(s0)
   li s1, 2
   sw s1, -100(s0)
   li s1, 3
   sw s1, -96(s0)
   li s1, 3
   sw s1, -92(s0)
   li s1, 3
   sw s1, -88(s0)
   li s1, 3
   sw s1, -84(s0)
   li s1, 3
   sw s1, -80(s0)
   li s1, 4
   sw s1, -76(s0)
   li s1, 4
   sw s1, -72(s0)
   li s1, 4
   sw s1, -68(s0)
   li s1, 4
   sw s1, -64(s0)
   li s1, 4
   sw s1, -60(s0)
   li s1, 5
   sw s1, -56(s0)
   li s1, 5
   sw s1, -52(s0)
   li s1, 5
   sw s1, -48(s0)
   li s1, 5
   sw s1, -44(s0)
   li s1, 5
   sw s1, -40(s0)
   li s1, 0
   sw s1, -140(s0)
   li s1, 0
   sw s1, -144(s0)
   li s1, 0
   sw s1, -148(s0)
   li s1, 0
   sw s1, -152(s0)
   li s1, 2
   sw s1, -140(s0)
   li s2, 3
   sw s2, -144(s0)
   li s1, 0
   sw s1, -152(s0)
L0:
   lw s2, -152(s0)
   li s1, 5
   bge s2, s1, L1
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -140(s0)
   li s3, 1
   sub s3, s2, s3
   li s4, 20
   mul s3, s3, s4
   add s1, s1, s3
   lw s3, -152(s0)
   li s4, 4
   mul s4, s3, s4
   add s1, s1, s4
   add s1, s0, s1
   lw s1, -136(s1)
   sw s1, -148(s0)
   li s4, 0
   li s5, 0
   add s4, s4, s5
   li s5, 1
   sub s2, s2, s5
   li s5, 20
   mul s2, s2, s5
   add s2, s4, s2
   li s4, 4
   mul s4, s3, s4
   add s2, s2, s4
   li s4, 0
   li s5, 0
   add s4, s4, s5
   lw s5, -144(s0)
   li s6, 1
   sub s6, s5, s6
   li s7, 20
   mul s6, s6, s7
   add s4, s4, s6
   li s6, 4
   mul s6, s3, s6
   add s4, s4, s6
   add s4, s0, s4
   lw s4, -136(s4)
   add s2, s0, s2
   sw s4, -136(s2)
   li s2, 0
   li s4, 0
   add s2, s2, s4
   li s4, 1
   sub s4, s5, s4
   li s5, 20
   mul s4, s4, s5
   add s2, s2, s4
   li s4, 4
   mul s4, s3, s4
   add s2, s2, s4
   add s2, s0, s2
   sw s1, -136(s2)
   li s2, 1
   add s2, s3, s2
   sw s2, -152(s0)
   j L0
L1:
   li s3, 0
   li s2, 0
   add s2, s3, s2
   li s3, 2
   li s4, 20
   mul s3, s3, s4
   add s2, s2, s3
   li s3, 0
   li s4, 4
   mul s3, s3, s4
   add s2, s2, s3
   add s2, s0, s2
   lw s2, -136(s2)
   mv a0, s2
   ld s0, 152(sp)
   ld ra, 144(sp)
   ld s1, 136(sp)
   ld s2, 128(sp)
   addi sp, sp, 160
   ret
   ld s0, 152(sp)
   ld ra, 144(sp)
   ld s1, 136(sp)
   ld s2, 128(sp)
   addi sp, sp, 160
   ret

