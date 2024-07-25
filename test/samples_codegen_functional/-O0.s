   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global lengthOfLastWord
   .type lengthOfLastWord, @function
   lengthOfLastWord:
   addi sp, sp, -128
   sd s0, 120(sp)
   sd ra, 112(sp)
   sd s1, 104(sp)
   sd s2, 96(sp)
   sd s3, 88(sp)
   sd s4, 80(sp)
   sd s5, 72(sp)
   sd s6, 64(sp)
   sd s7, 56(sp)
   sd s8, 48(sp)
   sd s9, 40(sp)
   sd s10, 32(sp)
   sd s11, 24(sp)
   addi s0, sp, 128
   li s1, 0
   bne a1, s1, L0
   li s1, 0
   mv a0, s1
   ld s0, 120(sp)
   ld ra, 112(sp)
   ld s1, 104(sp)
   ld s2, 96(sp)
   ld s3, 88(sp)
   ld s4, 80(sp)
   ld s5, 72(sp)
   ld s6, 64(sp)
   ld s7, 56(sp)
   ld s8, 48(sp)
   ld s9, 40(sp)
   ld s10, 32(sp)
   ld s11, 24(sp)
   addi sp, sp, 128
   ret
L0:
   li s1, 0
   sw s1, -120(s0)
   li s1, 1
   sub s1, a1, s1
   sw s1, -120(s0)
L1:
   li s2, 1
   neg s1, s2
   lw s3, -120(s0)
   bge s1, s3, L2
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -120(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   add s1, a0, s1
   lw s1, 0(s1)
   li s2, 0
   bne s1, s2, L2
   lw s1, -120(s0)
   li s2, 1
   sub s1, s1, s2
   sw s1, -120(s0)
   j L1
L2:
   li s2, 1
   neg s1, s2
   lw s3, -120(s0)
   bne s3, s1, L3
   li s1, 0
   mv a0, s1
   ld s0, 120(sp)
   ld ra, 112(sp)
   ld s1, 104(sp)
   ld s2, 96(sp)
   ld s3, 88(sp)
   ld s4, 80(sp)
   ld s5, 72(sp)
   ld s6, 64(sp)
   ld s7, 56(sp)
   ld s8, 48(sp)
   ld s9, 40(sp)
   ld s10, 32(sp)
   ld s11, 24(sp)
   addi sp, sp, 128
   ret
L3:
   li s1, 0
   sw s1, -124(s0)
   lw s1, -120(s0)
   sw s1, -124(s0)
L4:
   li s2, 1
   neg s1, s2
   lw s3, -124(s0)
   bge s1, s3, L5
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -124(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   add s1, a0, s1
   lw s1, 0(s1)
   li s2, 0
   bne s1, s2, L6
   lw s1, -124(s0)
   sub s1, a1, s1
   li s2, 1
   sub s1, s1, s2
   li s2, 1
   sub s2, a1, s2
   lw s3, -120(s0)
   sub s2, s2, s3
   sub s1, s1, s2
   mv a0, s1
   ld s0, 120(sp)
   ld ra, 112(sp)
   ld s1, 104(sp)
   ld s2, 96(sp)
   ld s3, 88(sp)
   ld s4, 80(sp)
   ld s5, 72(sp)
   ld s6, 64(sp)
   ld s7, 56(sp)
   ld s8, 48(sp)
   ld s9, 40(sp)
   ld s10, 32(sp)
   ld s11, 24(sp)
   addi sp, sp, 128
   ret
L6:
   lw s1, -124(s0)
   li s2, 1
   sub s1, s1, s2
   sw s1, -124(s0)
   j L4
L5:
   lw s2, -120(s0)
   lw s1, -124(s0)
   sub s1, s2, s1
   mv a0, s1
   ld s0, 120(sp)
   ld ra, 112(sp)
   ld s1, 104(sp)
   ld s2, 96(sp)
   ld s3, 88(sp)
   ld s4, 80(sp)
   ld s5, 72(sp)
   ld s6, 64(sp)
   ld s7, 56(sp)
   ld s8, 48(sp)
   ld s9, 40(sp)
   ld s10, 32(sp)
   ld s11, 24(sp)
   addi sp, sp, 128
   ret
   ld s0, 120(sp)
   ld ra, 112(sp)
   ld s1, 104(sp)
   ld s2, 96(sp)
   ld s3, 88(sp)
   ld s4, 80(sp)
   ld s5, 72(sp)
   ld s6, 64(sp)
   ld s7, 56(sp)
   ld s8, 48(sp)
   ld s9, 40(sp)
   ld s10, 32(sp)
   ld s11, 24(sp)
   addi sp, sp, 128
   ret
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
   sd s3, 120(sp)
   sd s4, 112(sp)
   sd s5, 104(sp)
   sd s6, 96(sp)
   sd s7, 88(sp)
   sd s8, 80(sp)
   sd s9, 72(sp)
   sd s10, 64(sp)
   sd s11, 56(sp)
   addi s0, sp, 160
   li s1, 0
   sw s1, -108(s0)
   li s1, 0
   sw s1, -152(s0)
   li s1, 0
   sw s1, -148(s0)
   li s1, 0
   sw s1, -144(s0)
   li s1, 0
   sw s1, -140(s0)
   li s1, 0
   sw s1, -136(s0)
   li s1, 0
   sw s1, -132(s0)
   li s1, 0
   sw s1, -128(s0)
   li s1, 0
   sw s1, -124(s0)
   li s1, 0
   sw s1, -120(s0)
   li s1, 0
   sw s1, -116(s0)
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
   sw s3, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 1
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 3
   add s1, s0, s1
   sw s2, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 2
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 9
   add s1, s0, s1
   sw s2, -152(s1)
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
   sw s3, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 4
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 0
   add s1, s0, s1
   sw s2, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 5
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 1
   add s1, s0, s1
   sw s2, -152(s1)
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
   sw s3, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 7
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 5
   add s1, s0, s1
   sw s2, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 8
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 7
   add s1, s0, s1
   sw s2, -152(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 9
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 8
   add s1, s0, s1
   sw s2, -152(s1)
   li s1, 10
   sw s1, -108(s0)
   li s2, 0
   li s3, 0
   add s2, s2, s3
   addi s3, s0, -152
   add s2, s3, s2
   mv a0, s2
   mv a1, s1
   call lengthOfLastWord
   mv s1, a0
   sw s1, -108(s0)
   mv a0, s1
   ld s0, 152(sp)
   ld ra, 144(sp)
   ld s1, 136(sp)
   ld s2, 128(sp)
   ld s3, 120(sp)
   ld s4, 112(sp)
   ld s5, 104(sp)
   ld s6, 96(sp)
   ld s7, 88(sp)
   ld s8, 80(sp)
   ld s9, 72(sp)
   ld s10, 64(sp)
   ld s11, 56(sp)
   addi sp, sp, 160
   ret
   ld s0, 152(sp)
   ld ra, 144(sp)
   ld s1, 136(sp)
   ld s2, 128(sp)
   ld s3, 120(sp)
   ld s4, 112(sp)
   ld s5, 104(sp)
   ld s6, 96(sp)
   ld s7, 88(sp)
   ld s8, 80(sp)
   ld s9, 72(sp)
   ld s10, 64(sp)
   ld s11, 56(sp)
   addi sp, sp, 160
   ret

