   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global fun
   .type fun, @function
   fun:
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s1, 0
   sw s1, -44(s0)
L0:
   li s1, 0
   bge s1, a1, L1
   rem s1, a0, a1
   sw s1, -44(s0)
   mv a0, a1
   mv a1, s1
   j L0
L1:
   mv a0, a0
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
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s2, 0
   sw s2, -36(s0)
   li s2, 0
   sw s2, -40(s0)
   li s2, 0
   sw s2, -44(s0)
   call get_int
   mv s2, a0
   sw s2, -40(s0)
   call get_int
   mv s3, a0
   sw s3, -36(s0)
   mv a0, s2
   mv a1, s3
   call fun
   mv s4, a0
   sw s4, -44(s0)
   mv a0, s4
   call print_int
   li s5, 0
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

