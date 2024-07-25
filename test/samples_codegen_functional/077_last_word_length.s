   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global lengthOfLastWord
   .type lengthOfLastWord, @function
   lengthOfLastWord:
   addi sp, sp, -64
   sd s0, 56(sp)
   sd ra, 48(sp)
   sd s1, 40(sp)
   sd s2, 32(sp)
   addi s0, sp, 64
   li s1, 0
   bne a1, s1, L0
   li s1, 0
   mv a0, s1
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
L0:
   li s1, 0
   sw s1, -48(s0)
   li s1, 1
   sub s1, a1, s1
   sw s1, -48(s0)
L1:
   li s2, 1
   neg s1, s2
   lw s3, -48(s0)
   bge s1, s3, L2
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -48(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   add s1, a0, s1
   lw s1, 0(s1)
   li s2, 0
   bne s1, s2, L2
   lw s1, -48(s0)
   li s2, 1
   sub s1, s1, s2
   sw s1, -48(s0)
   j L1
L2:
   li s2, 1
   neg s1, s2
   lw s3, -48(s0)
   bne s3, s1, L3
   li s1, 0
   mv a0, s1
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
L3:
   li s1, 0
   sw s1, -52(s0)
   lw s1, -48(s0)
   sw s1, -52(s0)
L4:
   li s2, 1
   neg s1, s2
   lw s3, -52(s0)
   bge s1, s3, L5
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   add s1, a0, s1
   lw s1, 0(s1)
   li s2, 0
   bne s1, s2, L6
   lw s1, -52(s0)
   sub s1, a1, s1
   li s2, 1
   sub s1, s1, s2
   li s2, 1
   sub s2, a1, s2
   lw s3, -48(s0)
   sub s2, s2, s3
   sub s1, s1, s2
   mv a0, s1
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
L6:
   lw s1, -52(s0)
   li s2, 1
   sub s1, s1, s2
   sw s1, -52(s0)
   j L4
L5:
   lw s2, -48(s0)
   lw s1, -52(s0)
   sub s1, s2, s1
   mv a0, s1
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
   addi sp, sp, -80
   sd s0, 72(sp)
   sd ra, 64(sp)
   sd s1, 56(sp)
   sd s2, 48(sp)
   addi s0, sp, 80
   li s1, 0
   sw s1, -36(s0)
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
   li s2, 4
   neg s3, s2
   add s1, s0, s1
   sw s3, -80(s1)
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
   li s2, 2
   neg s3, s2
   add s1, s0, s1
   sw s3, -80(s1)
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
   li s2, 6
   neg s3, s2
   add s1, s0, s1
   sw s3, -80(s1)
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
   li s3, 0
   add s2, s2, s3
   addi s3, s0, -80
   add s2, s3, s2
   mv a0, s2
   mv a1, s1
   call lengthOfLastWord
   mv s1, a0
   sw s1, -36(s0)
   mv a0, s1
   ld s0, 72(sp)
   ld ra, 64(sp)
   ld s1, 56(sp)
   ld s2, 48(sp)
   addi sp, sp, 80
   ret
   ld s0, 72(sp)
   ld ra, 64(sp)
   ld s1, 56(sp)
   ld s2, 48(sp)
   addi sp, sp, 80
   ret

