   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -32
   sd s0, 24(sp)
   sd ra, 16(sp)
   sd s1, 8(sp)
   sd s2, 0(sp)
   addi s0, sp, 32
   la s1, GVar0
   lw s1, 0(s1)
   la s2, GVar1
   lw s2, 0(s2)
   add s3, s1, s2
   la s4, GVar2
   sw s3, 0(s4)
   add s1, s1, s2
   mv a0, s1
   ld s0, 24(sp)
   ld ra, 16(sp)
   ld s1, 8(sp)
   ld s2, 0(sp)
   addi sp, sp, 32
   ret
   ld s0, 24(sp)
   ld ra, 16(sp)
   ld s1, 8(sp)
   ld s2, 0(sp)
   addi sp, sp, 32
   ret

   .globl GVar0
   .data
   .align 2
   .type GVar0, @object
   .size GVar0, 4
   GVar0:
   .word 3
   .globl GVar1
   .data
   .align 2
   .type GVar1, @object
   .size GVar1, 4
   GVar1:
   .word 5
   .globl GVar2
   .bss
   .align 2
   .type GVar2, @object
   .size GVar2, 4
   GVar2:
   .zero 4

   .globl GVar3
   .data
   .align 3
   .type GVar3, @object
   .size GVar3, 16
   GVar3:
   .word 1
   .word -1
   .word 0
   .word 0
