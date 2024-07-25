   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global main
   .type main, @function
   main:
   addi sp, sp, -112
   sd s0, 104(sp)
   sd ra, 96(sp)
   sd s1, 88(sp)
   sd s2, 80(sp)
   sd s3, 72(sp)
   sd s4, 64(sp)
   sd s5, 56(sp)
   sd s6, 48(sp)
   sd s7, 40(sp)
   sd s8, 32(sp)
   sd s9, 24(sp)
   sd s10, 16(sp)
   sd s11, 8(sp)
   addi s0, sp, 112
   li s1, 3
   mv a0, s1
   ld s0, 104(sp)
   ld ra, 96(sp)
   ld s1, 88(sp)
   ld s2, 80(sp)
   ld s3, 72(sp)
   ld s4, 64(sp)
   ld s5, 56(sp)
   ld s6, 48(sp)
   ld s7, 40(sp)
   ld s8, 32(sp)
   ld s9, 24(sp)
   ld s10, 16(sp)
   ld s11, 8(sp)
   addi sp, sp, 112
   ret
   ld s0, 104(sp)
   ld ra, 96(sp)
   ld s1, 88(sp)
   ld s2, 80(sp)
   ld s3, 72(sp)
   ld s4, 64(sp)
   ld s5, 56(sp)
   ld s6, 48(sp)
   ld s7, 40(sp)
   ld s8, 32(sp)
   ld s9, 24(sp)
   ld s10, 16(sp)
   ld s11, 8(sp)
   addi sp, sp, 112
   ret

