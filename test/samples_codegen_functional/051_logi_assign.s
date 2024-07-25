   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
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
   call get_int
   mv s1, a0
   la s2, GVar0
   sw s1, 0(s2)
   call get_int
   mv s2, a0
   la s3, GVar1
   sw s2, 0(s3)
   li s3, 0
   sw s3, -36(s0)
   bne s1, s2, L1
   la s3, GVar0
   lw s3, 0(s3)
   li s4, 3
   beq s3, s4, L1
   li s3, 1
   sw s3, -36(s0)
   j L0
L1:
   li s4, 0
   sw s4, -36(s0)
L0:
   lw s3, -36(s0)
   mv a0, s3
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
   .bss
   .align 2
   .type GVar0, @object
   .size GVar0, 4
   GVar0:
   .zero 4

   .globl GVar1
   .bss
   .align 2
   .type GVar1, @object
   .size GVar1, 4
   GVar1:
   .zero 4

