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
   la s1, LVar0
   lw s2, 0(s1)
   sw s2, -36(s0)
   li s1, 1095761920
   fmv.w.x ft0, s1
   fsw ft0, -36(s0)
   fmv.s fa0, ft0
   call print_float
   la s1, LVar1
   lw s2, 0(s1)
   sw s2, -40(s0)
   flw ft1, -40(s0)
   fmv.s fa0, ft1
   call print_float
   li s1, 0
   mv a0, s1
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

   .data
   .align 2
   .type LVar0, @object
   .size LVar0, 4
   LVar0:
   .word 0
   .data
   .align 2
   .type LVar1, @object
   .size LVar1, 4
   LVar1:
   .word 933741996
