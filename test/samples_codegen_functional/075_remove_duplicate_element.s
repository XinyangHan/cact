   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global removeElement
   .type removeElement, @function
   removeElement:
   addi sp, sp, -64
   sd s0, 56(sp)
   sd ra, 48(sp)
   sd s1, 40(sp)
   sd s2, 32(sp)
   addi s0, sp, 64
   li s1, 0
   sw s1, -52(s0)
   li s1, 0
   sw s1, -52(s0)
L0:
   lw s2, -52(s0)
   bge s2, a1, L1
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   add s1, a0, s1
   lw s1, 0(s1)
   bne s1, a2, L2
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 0
   li s3, 0
   add s2, s2, s3
   li s3, 1
   sub s3, a1, s3
   li s4, 4
   mul s3, s3, s4
   add s2, s2, s3
   add s2, a0, s2
   lw s2, 0(s2)
   add s1, a0, s1
   sw s2, 0(s1)
   li s1, 1
   sub s1, a1, s1
   mv a1, s1
   j L0
L2:
   lw s2, -52(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -52(s0)
   j L0
L1:
   mv a0, a1
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
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
   li s2, 0
   sw s2, -36(s0)
   li s2, 0
   sw s2, -80(s0)
   li s2, 0
   sw s2, -76(s0)
   li s2, 0
   sw s2, -72(s0)
   li s2, 0
   sw s2, -68(s0)
   li s2, 0
   sw s2, -64(s0)
   li s2, 0
   sw s2, -60(s0)
   li s2, 0
   sw s2, -56(s0)
   li s2, 0
   sw s2, -52(s0)
   li s2, 0
   sw s2, -48(s0)
   li s2, 0
   sw s2, -44(s0)
   li s2, 0
   li s1, 0
   add s1, s2, s1
   li s2, 0
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 3
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 1
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 3
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 2
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 9
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 3
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 0
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 4
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 0
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 5
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 1
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 6
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 1
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 7
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 5
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 8
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 7
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 9
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 8
   add s1, s0, s1
   sw s2, -80(s1)
   li s1, 10
   sw s1, -36(s0)
   li s2, 0
   sw s2, -84(s0)
   li s2, 3
   sw s2, -84(s0)
   li s3, 0
   li s4, 0
   add s3, s3, s4
   addi s4, s0, -80
   add s3, s4, s3
   mv a0, s3
   mv a1, s1
   mv a2, s2
   call removeElement
   mv s1, a0
   sw s1, -36(s0)
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

