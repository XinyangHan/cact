   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global func
   .type func, @function
   func:
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   li s1, 0
   sw s1, -36(s0)
   la s1, GVar0
   lw s1, 0(s1)
   sw s1, -36(s0)
   li s2, 1
   sw s2, -40(s0)
   lw s2, -40(s0)
   bne s2, s1, L1
   lw s2, -40(s0)
   li s3, 1
   add s2, s2, s3
   sw s2, -40(s0)
   li s3, 1
   mv a0, s3
   ld s0, 40(sp)
   ld ra, 32(sp)
   ld s1, 24(sp)
   ld s2, 16(sp)
   addi sp, sp, 48
   ret
   j L0
L1:
   li s3, 0
   mv a0, s3
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
   li s3, 0
   sw s3, -36(s0)
   li s3, 0
   sw s3, -40(s0)
L2:
   lw s3, -40(s0)
   li s2, 100
   bge s3, s2, L3
   call func
   mv s2, a0
   li s3, 1
   bne s2, s3, L4
   lw s2, -36(s0)
   li s3, 1
   add s2, s2, s3
   sw s2, -36(s0)
L4:
   lw s3, -40(s0)
   li s2, 1
   add s2, s3, s2
   sw s2, -40(s0)
   j L2
L3:
   lw s3, -36(s0)
   li s2, 100
   bge s3, s2, L6
   li s2, 1
   mv a0, s2
   call print_int
   j L5
L6:
   li s2, 0
   mv a0, s2
   call print_int
L5:
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

   .globl GVar0
   .data
   .align 2
   .type GVar0, @object
   .size GVar0, 4
   GVar0:
   .word 7
