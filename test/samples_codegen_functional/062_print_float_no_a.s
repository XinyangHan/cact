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
   call get_float
   fmv.s ft0, fa0
   fmv.s fa0, ft0
   call print_float
   li s1, 0
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

