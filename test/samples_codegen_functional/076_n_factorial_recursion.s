   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global factorial
   .type factorial, @function
   factorial:
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s1, 1
   bne a0, s1, L1
   mv a0, a0
   ld s0, 40(sp)
   ld ra, 32(sp)
   ld s1, 24(sp)
   ld s2, 16(sp)
   addi sp, sp, 48
   ret
   j L0
L1:
   li s1, 1
   sub s1, a0, s1
   sw a0, -36(s0)
   mv a0, s1
   call factorial
   mv s1, a0
   lw a0, -36(s0)
   mul s1, a0, s1
   mv a0, s1
   ld s0, 40(sp)
   ld ra, 32(sp)
   ld s1, 24(sp)
   ld s2, 16(sp)
   addi sp, sp, 48
   ret
L0:
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
   call get_int
   mv s1, a0
   sw s1, -36(s0)
   li s2, 1
   bge s2, s1, L3
   lw s2, -36(s0)
   mv a0, s2
   call factorial
   mv s2, a0
   sw s2, -40(s0)
   j L2
L3:
   li s3, 1
   sw s3, -40(s0)
L2:
   lw s2, -40(s0)
   mv a0, s2
   call print_int
   li s2, 0
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

