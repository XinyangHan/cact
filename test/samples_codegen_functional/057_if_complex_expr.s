   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -64
   sd s0, 56(sp)
   sd ra, 48(sp)
   sd s1, 40(sp)
   sd s2, 32(sp)
   addi s0, sp, 64
   li s1, 0
   sw s1, -36(s0)
   li s1, 0
   sw s1, -40(s0)
   li s1, 0
   sw s1, -44(s0)
   li s1, 0
   sw s1, -48(s0)
   li s1, 0
   sw s1, -52(s0)
   li s1, 5
   sw s1, -36(s0)
   li s2, 5
   sw s2, -40(s0)
   li s1, 1
   sw s1, -44(s0)
   li s2, 2
   neg s1, s2
   sw s1, -48(s0)
   li s2, 2
   sw s2, -52(s0)
   li s2, 1
   mul s2, s1, s2
   li s3, 2
   div s2, s2, s3
   li s3, 0
   blt s2, s3, L1
   lw s2, -36(s0)
   lw s3, -40(s0)
   sub s2, s2, s3
   li s3, 0
   beq s2, s3, L0
   lw s2, -44(s0)
   li s3, 3
   add s2, s2, s3
   li s3, 2
   rem s2, s2, s3
   li s3, 0
   beq s2, s3, L0
L1:
   lw s2, -52(s0)
   mv a0, s2
   call print_int
L0:
   lw s2, -48(s0)
   li s3, 2
   rem s2, s2, s3
   li s3, 67
   add s2, s2, s3
   li s3, 0
   blt s2, s3, L3
   lw s2, -36(s0)
   lw s3, -40(s0)
   sub s2, s2, s3
   li s3, 0
   beq s2, s3, L2
   lw s2, -44(s0)
   li s3, 2
   add s2, s2, s3
   li s3, 2
   rem s2, s2, s3
   li s3, 0
   beq s2, s3, L2
L3:
   li s2, 4
   sw s2, -52(s0)
   mv a0, s2
   call print_int
L2:
   li s3, 0
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

