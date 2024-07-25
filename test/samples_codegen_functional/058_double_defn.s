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
   ld s2, 0(s1)
   sd s2, -40(s0)
   la s1, IMM1
   fld ft0, 0(s1)
   fneg.d ft1, ft0
   fsd ft1, -40(s0)
   fmv.d fa0, ft1
   call print_double
   la s1, LVar1
   ld s2, 0(s1)
   sd s2, -48(s0)
   fld ft0, -48(s0)
   fmv.d fa0, ft0
   call print_double
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
   .align 3
   .type LVar0, @object
   .size LVar0, 8
   LVar0:
   .dword 0
   .data
   .align 3
   .type IMM1, @object
   .size IMM1, 8
   IMM1:
   .dword 4623507967449235456
   .data
   .align 3
   .type LVar1, @object
   .size LVar1, 8
   LVar1:
   .dword 4536524183238306033
