   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global deepWhileBr
   .type deepWhileBr, @function
   deepWhileBr:
   addi sp, sp, -64
   sd s0, 56(sp)
   sd ra, 48(sp)
   sd s1, 40(sp)
   sd s2, 32(sp)
   addi s0, sp, 64
   li s1, 0
   sw s1, -44(s0)
   add s1, a0, a1
   sw s1, -44(s0)
L0:
   lw s2, -44(s0)
   li s1, 75
   bge s2, s1, L1
   li s1, 0
   sw s1, -48(s0)
   li s1, 42
   sw s1, -48(s0)
   lw s2, -44(s0)
   li s1, 100
   bge s2, s1, L0
   lw s1, -44(s0)
   lw s2, -48(s0)
   add s1, s1, s2
   sw s1, -44(s0)
   li s2, 99
   bge s2, s1, L0
   li s2, 0
   sw s2, -52(s0)
   lw s2, -48(s0)
   li s3, 2
   mul s2, s2, s3
   sw s2, -52(s0)
   li s3, 1
   li s2, 1
   bne s3, s2, L0
   lw s2, -52(s0)
   li s3, 2
   mul s2, s2, s3
   sw s2, -44(s0)
   j L0
L1:
   lw s3, -44(s0)
   mv a0, s3
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
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s3, 0
   sw s3, -36(s0)
   li s3, 2
   sw s3, -36(s0)
   mv a0, s3
   mv a1, s3
   call deepWhileBr
   mv s2, a0
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

