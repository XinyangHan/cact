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
   li s1, 0
   sw s1, -36(s0)
   li s1, 0
   sw s1, -40(s0)
   li s1, 0
   sw s1, -44(s0)
   li s1, 0
   sw s1, -48(s0)
   li s1, 0
   sw s1, -36(s0)
L0:
   lw s2, -36(s0)
   li s1, 4
   bge s2, s1, L1
   li s1, 0
   sw s1, -40(s0)
L2:
   lw s2, -40(s0)
   li s1, 2
   bge s2, s1, L3
   li s1, 0
   sw s1, -44(s0)
L4:
   lw s2, -44(s0)
   li s1, 2
   bge s2, s1, L5
   li s1, 0
   sw s1, -48(s0)
L6:
   lw s2, -48(s0)
   li s1, 2
   bge s2, s1, L7
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -36(s0)
   li s3, 32
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -40(s0)
   li s3, 16
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -44(s0)
   li s3, 8
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -48(s0)
   li s3, 4
   mul s3, s2, s3
   add s1, s1, s3
   la s3, GVar0
   add s1, s3, s1
   flw ft0, 0(s1)
   fmv.s fa0, ft0
   call print_float
   li s1, 1
   add s1, s2, s1
   sw s1, -48(s0)
   j L6
L7:
   lw s2, -44(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -44(s0)
   j L4
L5:
   lw s2, -40(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -40(s0)
   j L2
L3:
   lw s2, -36(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -36(s0)
   j L0
L1:
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
   .align 3
   .type GVar0, @object
   .size GVar0, 128
   GVar0:
   .word 1065353216
   .word 1073741824
   .word 1077936128
   .word 1082130432
   .word 1084227584
   .word 1086324736
   .word 1088421888
   .word 1090519040
   .word 1091567616
   .word 1092616192
   .word 1093664768
   .word 1094713344
   .word 1095761920
   .word 1096810496
   .word 1097859072
   .word 1098907648
   .word 1099431936
   .word 1099956224
   .word 1100480512
   .word 1101004800
   .word 1101529088
   .word 1102053376
   .word 1102577664
   .word 1103101952
   .word 1103626240
   .word 1104150528
   .word 1104674816
   .word 1105199104
   .word 1105723392
   .word 1106247680
   .word 1106771968
   .word 1107296256
