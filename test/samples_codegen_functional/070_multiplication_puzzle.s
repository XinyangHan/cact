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
   li s1, 6
   sw s1, -36(s0)
   li s2, 0
   sw s2, -40(s0)
   li s2, 0
   sw s2, -44(s0)
   li s2, 0
   sw s2, -48(s0)
   li s2, 0
   sw s2, -52(s0)
   li s2, 0
   sw s2, -56(s0)
   li s2, 3
   sw s2, -40(s0)
L0:
   lw s1, -40(s0)
   lw s2, -36(s0)
   blt s2, s1, L1
   li s1, 0
   sw s1, -44(s0)
L2:
   lw s2, -36(s0)
   lw s1, -40(s0)
   sub s1, s2, s1
   li s2, 1
   add s1, s1, s2
   lw s2, -44(s0)
   bge s2, s1, L3
   lw s1, -44(s0)
   lw s2, -40(s0)
   add s2, s1, s2
   li s3, 1
   sub s2, s2, s3
   sw s2, -52(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -48(s0)
L4:
   lw s2, -48(s0)
   lw s1, -52(s0)
   bge s2, s1, L5
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -44(s0)
   li s3, 40
   mul s3, s2, s3
   add s1, s1, s3
   lw s3, -48(s0)
   li s4, 4
   mul s4, s3, s4
   add s1, s1, s4
   li s4, 0
   li s5, 0
   add s4, s4, s5
   li s5, 40
   mul s5, s3, s5
   add s4, s4, s5
   lw s5, -52(s0)
   li s6, 4
   mul s6, s5, s6
   add s4, s4, s6
   la s6, GVar1
   add s1, s6, s1
   lw s1, 0(s1)
   add s4, s6, s4
   lw s4, 0(s4)
   add s1, s1, s4
   li s4, 0
   li s7, 0
   add s4, s4, s7
   li s7, 4
   mul s7, s2, s7
   add s4, s4, s7
   li s7, 0
   li s8, 0
   add s7, s7, s8
   li s8, 4
   mul s3, s3, s8
   add s3, s7, s3
   la s7, GVar0
   add s4, s7, s4
   lw s4, 0(s4)
   add s3, s7, s3
   lw s3, 0(s3)
   mul s3, s4, s3
   li s4, 0
   li s8, 0
   add s4, s4, s8
   li s8, 4
   mul s8, s5, s8
   add s4, s4, s8
   add s4, s7, s4
   lw s4, 0(s4)
   mul s3, s3, s4
   add s1, s1, s3
   sw s1, -56(s0)
   li s3, 0
   li s1, 0
   add s1, s3, s1
   li s3, 40
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 4
   mul s2, s5, s2
   add s1, s1, s2
   add s1, s6, s1
   lw s1, 0(s1)
   li s2, 0
   beq s1, s2, L7
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -44(s0)
   li s3, 40
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -56(s0)
   la s3, GVar1
   add s1, s3, s1
   lw s1, 0(s1)
   bge s2, s1, L6
L7:
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -44(s0)
   li s3, 40
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -56(s0)
   la s3, GVar1
   add s1, s3, s1
   sw s2, 0(s1)
L6:
   lw s1, -48(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -48(s0)
   j L4
L5:
   lw s2, -44(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -44(s0)
   j L2
L3:
   lw s2, -40(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -40(s0)
   j L0
L1:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   li s2, 0
   li s3, 40
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -36(s0)
   li s3, 1
   sub s2, s2, s3
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar1
   add s1, s2, s1
   lw s1, 0(s1)
   mv a0, s1
   call print_int
   li s1, 0
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

   .globl GVar0
   .data
   .align 3
   .type GVar0, @object
   .size GVar0, 24
   GVar0:
   .word 10
   .word 1
   .word 50
   .word 50
   .word 20
   .word 5
   .globl GVar1
   .bss
   .align 3
   .type GVar1, @object
   .size GVar1, 400
   GVar1:
   .zero 400

