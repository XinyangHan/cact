   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global binary_insert
   .type binary_insert, @function
   binary_insert:
   addi sp, sp, -96
   sd s0, 88(sp)
   sd ra, 80(sp)
   sd s1, 72(sp)
   sd s2, 64(sp)
   sd s3, 56(sp)
   sd s4, 48(sp)
   addi s0, sp, 96
   li s1, 0
   sw s1, -72(s0)
   li s1, 0
   sw s1, -76(s0)
   li s1, 0
   sw s1, -80(s0)
   li s1, 0
   sw s1, -84(s0)
   li s1, 0
   sw s1, -88(s0)
   li s1, 0
   sw s1, -92(s0)
   mv s1, a2
   sw s1, -72(s0)
L0:
   lw s2, -72(s0)
   blt a3, s2, L1
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -72(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   add s3, a0, s3
   lw s3, 0(s3)
   sw s3, -92(s0)
   mv s4, a1
   sw s4, -80(s0)
   li s4, 1
   sub s2, s2, s4
   sw s2, -84(s0)
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   add s1, a0, s1
   lw s1, 0(s1)
   bge s3, s1, L2
L3:
   lw s1, -80(s0)
   lw s2, -84(s0)
   blt s2, s1, L4
   lw s1, -84(s0)
   lw s2, -80(s0)
   sub s1, s1, s2
   li s3, 2
   div s1, s1, s3
   add s1, s2, s1
   sw s1, -88(s0)
   li s2, 0
   li s3, 0
   add s2, s2, s3
   li s3, 4
   mul s1, s1, s3
   add s1, s2, s1
   lw s2, -92(s0)
   add s1, a0, s1
   lw s1, 0(s1)
   bge s2, s1, L5
   lw s1, -88(s0)
   li s2, 1
   sub s1, s1, s2
   sw s1, -84(s0)
   j L3
L5:
   lw s2, -88(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -80(s0)
   j L3
L4:
   lw s2, -72(s0)
   li s1, 1
   sub s1, s2, s1
   sw s1, -76(s0)
L6:
   lw s2, -76(s0)
   lw s1, -80(s0)
   blt s2, s1, L7
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -76(s0)
   li s3, 1
   add s3, s2, s3
   li s4, 4
   mul s3, s3, s4
   add s3, s1, s3
   li s4, 4
   mul s4, s2, s4
   add s1, s1, s4
   add s1, a0, s1
   lw s1, 0(s1)
   add s3, a0, s3
   sw s1, 0(s3)
   li s1, 1
   sub s1, s2, s1
   sw s1, -76(s0)
   j L6
L7:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   lw s2, -80(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -92(s0)
   add s1, a0, s1
   sw s2, 0(s1)
L2:
   lw s1, -72(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -72(s0)
   j L0
L1:
   ld s0, 88(sp)
   ld ra, 80(sp)
   ld s1, 72(sp)
   ld s2, 64(sp)
   ld s3, 56(sp)
   ld s4, 48(sp)
   addi sp, sp, 96
   ret
   .text
   .align 2
   .global merge_sort
   .type merge_sort, @function
   merge_sort:
   addi sp, sp, -80
   sd s0, 72(sp)
   sd ra, 64(sp)
   sd s1, 56(sp)
   sd s2, 48(sp)
   sd s3, 40(sp)
   sd s4, 32(sp)
   addi s0, sp, 80
   li s2, 0
   sw s2, -72(s0)
   li s2, 0
   sw s2, -76(s0)
   li s2, 0
   sw s2, -80(s0)
   mv s1, a1
   sw s1, -72(s0)
   mv s1, a2
   sw s1, -76(s0)
   li s2, 0
   sw s2, -80(s0)
L8:
   lw s1, -72(s0)
   bge s1, a2, L9
   lw s1, -76(s0)
   blt a3, s1, L9
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -72(s0)
   li s3, 4
   mul s2, s2, s3
   add s2, s1, s2
   lw s3, -76(s0)
   li s4, 4
   mul s3, s3, s4
   add s1, s1, s3
   add s2, a0, s2
   lw s2, 0(s2)
   add s1, a0, s1
   lw s1, 0(s1)
   blt s1, s2, L11
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -80(s0)
   li s3, 4
   mul s2, s2, s3
   add s2, s1, s2
   lw s3, -72(s0)
   li s4, 4
   mul s4, s3, s4
   add s1, s1, s4
   add s1, a0, s1
   lw s1, 0(s1)
   la s4, GVar1
   add s2, s4, s2
   sw s1, 0(s2)
   li s1, 1
   add s1, s3, s1
   sw s1, -72(s0)
   j L10
L11:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   lw s2, -80(s0)
   li s3, 4
   mul s2, s2, s3
   add s2, s1, s2
   lw s3, -76(s0)
   li s4, 4
   mul s4, s3, s4
   add s1, s1, s4
   add s1, a0, s1
   lw s1, 0(s1)
   la s4, GVar1
   add s2, s4, s2
   sw s1, 0(s2)
   li s1, 1
   add s1, s3, s1
   sw s1, -76(s0)
L10:
   lw s2, -80(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -80(s0)
   j L8
L9:
   lw s2, -72(s0)
   bge s2, a2, L12
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -80(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   lw s4, -72(s0)
   li s5, 4
   mul s5, s4, s5
   add s1, s1, s5
   add s1, a0, s1
   lw s1, 0(s1)
   la s5, GVar1
   add s3, s5, s3
   sw s1, 0(s3)
   li s1, 1
   add s1, s4, s1
   sw s1, -72(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -80(s0)
   j L9
L12:
   lw s2, -76(s0)
   blt a3, s2, L13
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -80(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   lw s4, -76(s0)
   li s5, 4
   mul s5, s4, s5
   add s1, s1, s5
   add s1, a0, s1
   lw s1, 0(s1)
   la s5, GVar1
   add s3, s5, s3
   sw s1, 0(s3)
   li s1, 1
   add s1, s4, s1
   sw s1, -76(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -80(s0)
   j L12
L13:
   mv s1, a1
   sw s1, -72(s0)
L14:
   lw s2, -72(s0)
   blt a3, s2, L15
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -72(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   sub s4, s2, a1
   li s5, 4
   mul s4, s4, s5
   add s1, s1, s4
   la s4, GVar1
   add s1, s4, s1
   lw s1, 0(s1)
   add s3, a0, s3
   sw s1, 0(s3)
   li s1, 1
   add s1, s2, s1
   sw s1, -72(s0)
   j L14
L15:
   ld s0, 72(sp)
   ld ra, 64(sp)
   ld s1, 56(sp)
   ld s2, 48(sp)
   ld s3, 40(sp)
   ld s4, 32(sp)
   addi sp, sp, 80
   ret
   .text
   .align 2
   .global simplified_tim_sort
   .type simplified_tim_sort, @function
   simplified_tim_sort:
   addi sp, sp, -96
   sd s0, 88(sp)
   sd ra, 80(sp)
   sd s1, 72(sp)
   sd s2, 64(sp)
   sd s3, 56(sp)
   sd s4, 48(sp)
   addi s0, sp, 96
   li s2, 0
   sw s2, -64(s0)
   li s2, 0
   sw s2, -68(s0)
   li s2, 0
   sw s2, -72(s0)
   li s2, 0
   sw s2, -76(s0)
   li s2, 0
   sw s2, -80(s0)
   li s2, 0
   sw s2, -84(s0)
   li s2, 0
   sw s2, -88(s0)
   li s1, 1
   add s1, a1, s1
   sw s1, -68(s0)
L16:
   lw s2, -68(s0)
   li s1, 64
   bge s1, s2, L17
   lw s1, -68(s0)
   li s2, 2
   div s1, s1, s2
   sw s1, -68(s0)
   j L16
L17:
   lw s2, -68(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -68(s0)
   li s2, 1
   neg s1, s2
   sw s1, -72(s0)
   li s2, 0
   sw s2, -84(s0)
L18:
   lw s1, -72(s0)
   bge s1, a1, L19
   lw s1, -72(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -72(s0)
   li s2, 0
   li s3, 0
   add s2, s2, s3
   lw s3, -84(s0)
   li s4, 4
   mul s3, s3, s4
   add s2, s2, s3
   la s3, GVar0
   add s2, s3, s2
   sw s1, 0(s2)
   bge s1, a1, L20
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -72(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   li s4, 1
   add s2, s2, s4
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   add s2, a0, s3
   lw s2, 0(s2)
   add s1, a0, s1
   lw s1, 0(s1)
   blt s1, s2, L21
L22:
   lw s1, -72(s0)
   bge s1, a1, L20
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -72(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   li s4, 1
   add s2, s2, s4
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   add s2, a0, s3
   lw s2, 0(s2)
   add s1, a0, s1
   lw s1, 0(s1)
   blt s1, s2, L20
   lw s1, -72(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -72(s0)
   j L22
   j L20
L21:
   lw s2, -72(s0)
   bge s2, a1, L23
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -72(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   li s4, 1
   add s2, s2, s4
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   add s2, a0, s3
   lw s2, 0(s2)
   add s1, a0, s1
   lw s1, 0(s1)
   bge s1, s2, L23
   lw s1, -72(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -72(s0)
   j L21
L23:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   lw s2, -84(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar0
   add s1, s2, s1
   lw s1, 0(s1)
   sw s1, -76(s0)
   lw s2, -72(s0)
   sw s2, -80(s0)
L24:
   lw s1, -76(s0)
   lw s2, -80(s0)
   bge s1, s2, L20
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -76(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   add s4, a0, s3
   lw s4, 0(s4)
   sw s4, -64(s0)
   lw s5, -80(s0)
   li s6, 4
   mul s6, s5, s6
   add s1, s1, s6
   add s6, a0, s1
   lw s6, 0(s6)
   add s3, a0, s3
   sw s6, 0(s3)
   add s1, a0, s1
   sw s4, 0(s1)
   li s1, 1
   add s1, s2, s1
   sw s1, -76(s0)
   li s1, 1
   sub s1, s5, s1
   sw s1, -80(s0)
   j L24
L20:
   lw s2, -84(s0)
   li s1, 0
   bge s1, s2, L25
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -84(s0)
   li s3, 1
   sub s2, s2, s3
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar0
   add s1, s2, s1
   lw s1, 0(s1)
   lw s2, -68(s0)
   add s1, s1, s2
   lw s2, -72(s0)
   bge s2, s1, L25
   li s1, 0
   li s2, 0
   add s1, s1, s2
   sd a0, -56(s0)
   add s2, a0, s1
   mv a0, s2
   lw s2, -84(s0)
   li s3, 1
   sub s3, s2, s3
   li s4, 4
   mul s4, s3, s4
   add s4, s1, s4
   sw a1, -60(s0)
   la s5, GVar0
   add s4, s5, s4
   lw s4, 0(s4)
   mv a1, s4
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   add s1, s5, s1
   lw s1, 0(s1)
   mv a2, s1
   lw s1, -72(s0)
   mv a3, s1
   call binary_insert
   ld a0, -56(s0)
   lw a1, -60(s0)
   sw s3, -84(s0)
L25:
   lw s1, -84(s0)
   li s2, 0
   bge s2, s1, L26
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -84(s0)
   li s3, 4
   mul s3, s2, s3
   add s3, s1, s3
   lw s4, -72(s0)
   la s5, GVar0
   add s6, s5, s3
   lw s6, 0(s6)
   sub s4, s4, s6
   li s6, 2
   mul s4, s4, s6
   li s6, 1
   sub s2, s2, s6
   li s6, 4
   mul s2, s2, s6
   add s1, s1, s2
   add s2, s5, s3
   lw s2, 0(s2)
   la s3, GVar0
   add s1, s3, s1
   lw s1, 0(s1)
   sub s1, s2, s1
   blt s1, s4, L27
   j L26
L27:
   li s1, 0
   li s2, 0
   add s1, s1, s2
   sd a0, -56(s0)
   add s2, a0, s1
   mv a0, s2
   lw s2, -84(s0)
   li s3, 1
   sub s3, s2, s3
   li s4, 4
   mul s4, s3, s4
   add s4, s1, s4
   sw a1, -60(s0)
   la s5, GVar0
   add s4, s5, s4
   lw s4, 0(s4)
   mv a1, s4
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   add s1, s5, s1
   lw s1, 0(s1)
   mv a2, s1
   lw s1, -72(s0)
   mv a3, s1
   call merge_sort
   ld a0, -56(s0)
   lw a1, -60(s0)
   sw s3, -84(s0)
   j L25
L26:
   lw s1, -84(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -84(s0)
   j L18
L19:
   lw s2, -84(s0)
   li s1, 1
   bge s1, s2, L28
   li s1, 0
   li s2, 0
   add s1, s1, s2
   sd a0, -56(s0)
   add s2, a0, s1
   mv a0, s2
   lw s2, -84(s0)
   li s3, 2
   sub s3, s2, s3
   li s4, 4
   mul s3, s3, s4
   add s3, s1, s3
   sw a1, -60(s0)
   la s4, GVar0
   add s3, s4, s3
   lw s3, 0(s3)
   mv a1, s3
   li s3, 1
   sub s2, s2, s3
   li s3, 4
   mul s3, s2, s3
   add s1, s1, s3
   add s1, s4, s1
   lw s1, 0(s1)
   mv a2, s1
   lw s1, -72(s0)
   mv a3, s1
   call merge_sort
   ld a0, -56(s0)
   lw a1, -60(s0)
   sw s2, -84(s0)
   j L19
L28:
   ld s0, 88(sp)
   ld ra, 80(sp)
   ld s1, 72(sp)
   ld s2, 64(sp)
   ld s3, 56(sp)
   ld s4, 48(sp)
   addi sp, sp, 96
   ret
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
   sd s3, 24(sp)
   sd s4, 16(sp)
   addi s0, sp, 64
   li s1, 0
   sw s1, -52(s0)
   li s1, 0
   sw s1, -56(s0)
   call get_int
   mv s1, a0
   sw s1, -56(s0)
   li s2, 0
   li s3, 0
   add s2, s2, s3
   la s3, GVar2
   add s2, s3, s2
   mv a0, s2
   mv a1, s1
   call simplified_tim_sort
L29:
   lw s1, -52(s0)
   lw s2, -56(s0)
   blt s2, s1, L30
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 4
   mul s3, s2, s3
   add s1, s1, s3
   la s3, GVar2
   add s1, s3, s1
   lw s1, 0(s1)
   mv a0, s1
   call print_int
   li s1, 1
   add s1, s2, s1
   sw s1, -52(s0)
   j L29
L30:
   li s2, 0
   mv a0, s2
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   ld s3, 24(sp)
   ld s4, 16(sp)
   addi sp, sp, 64
   ret
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   ld s3, 24(sp)
   ld s4, 16(sp)
   addi sp, sp, 64
   ret

   .globl GVar0
   .bss
   .align 3
   .type GVar0, @object
   .size GVar0, 20040
   GVar0:
   .zero 20040

   .globl GVar1
   .bss
   .align 3
   .type GVar1, @object
   .size GVar1, 20040
   GVar1:
   .zero 20040

   .globl GVar2
   .data
   .align 3
   .type GVar2, @object
   .size GVar2, 20000
   GVar2:
   .word -601
   .word 776
   .word -386
   .word -1342
   .word 988
   .word 1334
   .word 1332
   .word -786
   .word -1072
   .word -1043
   .word 168
   .word -1022
   .word -1310
   .word -1290
   .word -1007
   .word -557
   .word 205
   .word -890
   .word 58
   .word -417
   .word -1064
   .word 245
   .word 947
   .word -870
   .word -399
   .word 38
   .word -906
   .word -690
   .word 855
   .word 17
   .word 427
   .word 66
   .word -135
   .word -42
   .word -910
   .word 1195
   .word 1142
   .word -1059
   .word 174
   .word -201
   .word 1273
   .word 1245
   .word 1107
   .word -1030
   .word 1324
   .word 848
   .word -970
   .word 218
   .word 1407
   .word -1260
   .word 553
   .word 1179
   .word 1059
   .word 287
   .word 401
   .word 234
   .word -1008
   .word 904
   .word 835
   .word 775
   .word -1247
   .word -892
   .word -205
   .word -744
   .word -567
   .word -383
   .word 310
   .word 851
   .word -285
   .word -1268
   .word -351
   .word 754
   .word 620
   .word 1193
   .word 62
   .word 1185
   .word 376
   .word 1320
   .word 182
   .word -905
   .word 663
   .word 178
   .word -131
   .word -486
   .word 803
   .word -1070
   .word -360
   .word -868
   .word 1126
   .word 782
   .word -44
   .word 361
   .word -416
   .word 314
   .word -657
   .word 1273
   .word 209
   .word 182
   .word -317
   .word -87
   .word -757
   .word -311
   .word -49
   .word 271
   .word -480
   .word -132
   .word -1332
   .word -248
   .word -1227
   .word -546
   .word -337
   .word -221
   .word 800
   .word 1120
   .word 109
   .word -508
   .word 778
   .word -778
   .word -839
   .word -790
   .word -1097
   .word 1295
   .word -1347
   .word 609
   .word 1130
   .word -1405
   .word 276
   .word -1050
   .word 841
   .word -854
   .word -290
   .word -700
   .word -1048
   .word 166
   .word 532
   .word 7
   .word 716
   .word -926
   .word 678
   .word 1192
   .word -485
   .word 773
   .word 6
   .word -81
   .word -1047
   .word -744
   .word -583
   .word -1041
   .word 141
   .word 1380
   .word -135
   .word -337
   .word -653
   .word -416
   .word -687
   .word 1033
   .word -200
   .word -514
   .word 734
   .word 809
   .word 651
   .word -748
   .word 678
   .word 237
   .word 883
   .word 592
   .word -56
   .word 118
   .word 284
   .word 376
   .word -1382
   .word 1126
   .word 162
   .word 1355
   .word 1038
   .word 0
   .word 290
   .word 325
   .word -265
   .word -712
   .word -852
   .word -216
   .word -1341
   .word -1274
   .word 116
   .word 1003
   .word 784
   .word 1417
   .word 337
   .word 475
   .word -1179
   .word -140
   .word -344
   .word 479
   .word 1378
   .word 1389
   .word 231
   .word -445
   .word -473
   .word 1346
   .word -310
   .word 1347
   .word 1374
   .word -847
   .word 167
   .word 15
   .word -371
   .word -1033
   .word -84
   .word 880
   .word -60
   .word 43
   .word -11
   .word -758
   .word -1413
   .word 655
   .word 4
   .word 1221
   .word -895
   .word 189
   .word 1181
   .word 1234
   .word -1164
   .word 1257
   .word 811
   .word 167
   .word 15
   .word -1373
   .word 959
   .word 1155
   .word 975
   .word 171
   .word 522
   .word -1290
   .word 1159
   .word -1390
   .word -769
   .word 456
   .word -599
   .word -387
   .word -1416
   .word -1189
   .word 364
   .word 368
   .word 190
   .word 702
   .word 1113
   .word 354
   .word -1257
   .word 1274
   .word -1166
   .word -1177
   .word 356
   .word 207
   .word -235
   .word -618
   .word 1040
   .word 326
   .word -128
   .word 675
   .word -61
   .word -205
   .word 411
   .word 532
   .word -755
   .word 830
   .word -1267
   .word 358
   .word -18
   .word 155
   .word -868
   .word 560
   .word 1351
   .word 1356
   .word -705
   .word -915
   .word -815
   .word 1154
   .word -136
   .word 593
   .word -978
   .word -986
   .word -1088
   .word -493
   .word -749
   .word -1294
   .word 1365
   .word 1292
   .word -841
   .word 1154
   .word 408
   .word 327
   .word 149
   .word -692
   .word -1083
   .word 1388
   .word 974
   .word -313
   .word 19
   .word 499
   .word 549
   .word -646
   .word -562
   .word 1423
   .word -256
   .word 684
   .word -522
   .word 1427
   .word 372
   .word -720
   .word -1352
   .word -73
   .word -1324
   .word 1116
   .word 542
   .word 972
   .word -952
   .word 360
   .word -139
   .word 657
   .word 256
   .word -268
   .word 1202
   .word 843
   .word 1071
   .word 424
   .word 458
   .word -757
   .word 21
   .word -481
   .word -1310
   .word 1238
   .word -1199
   .word 1079
   .word -266
   .word 1342
   .word 92
   .word -1190
   .word -9
   .word -82
   .word -1051
   .word -924
   .word -1299
   .word 509
   .word 298
   .word 523
   .word -837
   .word -778
   .word 534
   .word 612
   .word 1001
   .word -1351
   .word -390
   .word 1040
   .word 347
   .word -227
   .word -951
   .word -565
   .word -248
   .word 288
   .word 175
   .word 66
   .word -1103
   .word 228
   .word -202
   .word -840
   .word 108
   .word -1386
   .word -951
   .word -710
   .word -213
   .word -872
   .word 1257
   .word 541
   .word -814
   .word -1406
   .word 686
   .word 424
   .word 962
   .word -1388
   .word -363
   .word 975
   .word -88
   .word 808
   .word -213
   .word 834
   .word -826
   .word 132
   .word -826
   .word 460
   .word 180
   .word -155
   .word -996
   .word 810
   .word 744
   .word -611
   .word -499
   .word 994
   .word 476
   .word 1028
   .word 905
   .word 1051
   .word 533
   .word -1120
   .word -1097
   .word 355
   .word 1237
   .word 1352
   .word 238
   .word 118
   .word -997
   .word -465
   .word 748
   .word 759
   .word 772
   .word 919
   .word -703
   .word -816
   .word -209
   .word -508
   .word -793
   .word 166
   .word 95
   .word -946
   .word 1193
   .word 196
   .word -1139
   .word -1146
   .word 743
   .word -917
   .word -1378
   .word -401
   .word 1152
   .word -378
   .word -1389
   .word -1223
   .word 1144
   .word -1097
   .word 210
   .word -51
   .word -383
   .word -291
   .word -769
   .word 1228
   .word -899
   .word 746
   .word -110
   .word -1364
   .word 768
   .word -323
   .word -198
   .word -52
   .word -875
   .word 1207
   .word 964
   .word -134
   .word 1038
   .word 542
   .word -315
   .word -420
   .word -1053
   .word -1157
   .word -1212
   .word 1314
   .word 944
   .word 1388
   .word 1174
   .word 142
   .word -858
   .word 345
   .word 247
   .word 89
   .word -1252
   .word 946
   .word 1114
   .word 1228
   .word -448
   .word 589
   .word -754
   .word 1283
   .word 230
   .word 169
   .word 738
   .word -1206
   .word -1349
   .word 828
   .word 1203
   .word 404
   .word 292
   .word -1360
   .word -895
   .word 968
   .word 627
   .word 583
   .word -1091
   .word 449
   .word 720
   .word -2
   .word -1195
   .word -177
   .word 636
   .word 1029
   .word 404
   .word -648
   .word 653
   .word 97
   .word 289
   .word -738
   .word 196
   .word 1105
   .word -814
   .word -700
   .word -46
   .word 1093
   .word 703
   .word -1018
   .word 364
   .word -30
   .word -945
   .word 1388
   .word 291
   .word -1237
   .word -1341
   .word 70
   .word 936
   .word 602
   .word 2
   .word -544
   .word -392
   .word 60
   .word -501
   .word 1132
   .word -670
   .word -698
   .word -801
   .word 804
   .word 897
   .word 1280
   .word 1266
   .word -986
   .word -1007
   .word 678
   .word 1005
   .word -890
   .word 1034
   .word 376
   .word 1337
   .word 1236
   .word 149
   .word 109
   .word -681
   .word -478
   .word -1359
   .word -509
   .word 880
   .word -1378
   .word -75
   .word -1368
   .word -267
   .word -1102
   .word 1320
   .word 1426
   .word 112
   .word 63
   .word -785
   .word -1392
   .word 1278
   .word 676
   .word 187
   .word 456
   .word -906
   .word 401
   .word 400
   .word 562
   .word -393
   .word 759
   .word 513
   .word 1419
   .word 1105
   .word 1182
   .word -661
   .word -630
   .word 1274
   .word 868
   .word -346
   .word 92
   .word 794
   .word 816
   .word 1204
   .word 424
   .word -875
   .word 1040
   .word -1327
   .word 291
   .word -718
   .word 41
   .word 1003
   .word 750
   .word -1035
   .word -1328
   .word 1024
   .word -490
   .word -1365
   .word 675
   .word -343
   .word 209
   .word -1071
   .word 1404
   .word -321
   .word 1105
   .word -748
   .word 742
   .word -849
   .word -427
   .word -1203
   .word -830
   .word 610
   .word 812
   .word -1249
   .word 58
   .word 900
   .word -1198
   .word -90
   .word 806
   .word 1117
   .word 663
   .word -812
   .word 99
   .word 595
   .word 167
   .word -931
   .word 202
   .word 434
   .word 1359
   .word 710
   .word -1194
   .word -1091
   .word -324
   .word 1256
   .word 647
   .word -1274
   .word 154
   .word 1356
   .word -120
   .word -759
   .word -322
   .word 722
   .word -948
   .word -1188
   .word 505
   .word 1062
   .word -685
   .word -384
   .word 145
   .word -269
   .word 612
   .word 302
   .word 1243
   .word 1161
   .word -69
   .word -1026
   .word -78
   .word 1072
   .word -1106
   .word -532
   .word -1236
   .word -331
   .word 49
   .word -1248
   .word -1160
   .word 188
   .word -610
   .word -187
   .word 1198
   .word -1154
   .word -1026
   .word -1136
   .word 582
   .word -1414
   .word -767
   .word 596
   .word 392
   .word -907
   .word 116
   .word -24
   .word -686
   .word 491
   .word -918
   .word -719
   .word 1033
   .word -1222
   .word -720
   .word 1422
   .word 760
   .word 697
   .word -438
   .word 912
   .word 1016
   .word 1
   .word -796
   .word -1083
   .word 1068
   .word -617
   .word -1094
   .word 725
   .word 1098
   .word -68
   .word -435
   .word 422
   .word 911
   .word -277
   .word 363
   .word -1151
   .word -135
   .word 632
   .word -728
   .word 69
   .word -867
   .word -417
   .word -507
   .word -1023
   .word 750
   .word 1428
   .word -680
   .word -249
   .word 1024
   .word 1242
   .word -952
   .word 1032
   .word -1210
   .word 554
   .word 972
   .word 1055
   .word 106
   .word -763
   .word -1269
   .word -1362
   .word -428
   .word 381
   .word 1103
   .word 445
   .word 1280
   .word -537
   .word -702
   .word -685
   .word -899
   .word -375
   .word -93
   .word -1320
   .word -1422
   .word -40
   .word 111
   .word -780
   .word -1386
   .word 78
   .word -41
   .word -1014
   .word -374
   .word -192
   .word -1011
   .word 1420
   .word 1139
   .word -601
   .word 757
   .word -358
   .word -567
   .word -365
   .word -580
   .word -613
   .word -640
   .word 738
   .word -979
   .word 910
   .word -480
   .word 943
   .word 1282
   .word 946
   .word -408
   .word -67
   .word 357
   .word -188
   .word -499
   .word 423
   .word -1129
   .word 532
   .word -1259
   .word 97
   .word -771
   .word -863
   .word -246
   .word 148
   .word -1156
   .word 1093
   .word -576
   .word 310
   .word -769
   .word -1369
   .word -665
   .word 396
   .word 1013
   .word -194
   .word 1031
   .word 26
   .word 710
   .word -1188
   .word -76
   .word -1066
   .word 922
   .word -947
   .word 821
   .word -879
   .word -213
   .word 861
   .word -680
   .word -962
   .word -955
   .word -625
   .word 510
   .word 788
   .word 656
   .word 1397
   .word 765
   .word -406
   .word 710
   .word -175
   .word 487
   .word 1089
   .word 95
   .word -1317
   .word 985
   .word -656
   .word -47
   .word -112
   .word 640
   .word 845
   .word -116
   .word 686
   .word 277
   .word 118
   .word 827
   .word 759
   .word 51
   .word -583
   .word 88
   .word 289
   .word -1329
   .word -330
   .word -715
   .word 1116
   .word 1096
   .word -444
   .word 297
   .word 337
   .word -948
   .word 371
   .word -954
   .word 850
   .word 1395
   .word 977
   .word -273
   .word 1081
   .word -617
   .word -5
   .word -793
   .word -426
   .word 446
   .word -1275
   .word -1246
   .word 1319
   .word -645
   .word 262
   .word -255
   .word -455
   .word -323
   .word 563
   .word 274
   .word -876
   .word 1356
   .word -736
   .word 1355
   .word 1411
   .word -1404
   .word -583
   .word 852
   .word 441
   .word 1033
   .word -755
   .word 516
   .word 945
   .word -942
   .word 1325
   .word 804
   .word 350
   .word 444
   .word -676
   .word -346
   .word -929
   .word 461
   .word 82
   .word 1290
   .word -1259
   .word 795
   .word 76
   .word -64
   .word 1362
   .word 532
   .word -241
   .word 1111
   .word -361
   .word 1145
   .word 1419
   .word -85
   .word -689
   .word 1072
   .word 0
   .word -501
   .word -1144
   .word -1248
   .word 338
   .word 96
   .word -516
   .word -393
   .word 1157
   .word 846
   .word 1341
   .word -1011
   .word 393
   .word 1049
   .word 1108
   .word -697
   .word -147
   .word -167
   .word -604
   .word 219
   .word 288
   .word 567
   .word 913
   .word -1137
   .word -1191
   .word 1081
   .word 528
   .word 1023
   .word 615
   .word 18
   .word 674
   .word -655
   .word 1309
   .word -426
   .word -1319
   .word -724
   .word -492
   .word 1342
   .word 19
   .word -1280
   .word 5
   .word 1320
   .word -1419
   .word 175
   .word 960
   .word -134
   .word 217
   .word 1261
   .word -800
   .word -376
   .word 1069
   .word -966
   .word -204
   .word -137
   .word 412
   .word -1275
   .word 27
   .word -1002
   .word 274
   .word -546
   .word -930
   .word -240
   .word -128
   .word 429
   .word 458
   .word -545
   .word -1129
   .word -1052
   .word -96
   .word 1154
   .word -630
   .word -980
   .word -1400
   .word -253
   .word 593
   .word 371
   .word 556
   .word 183
   .word -792
   .word 1401
   .word 851
   .word 1249
   .word 941
   .word -765
   .word -1144
   .word -618
   .word -1261
   .word 1151
   .word 1237
   .word 1351
   .word 649
   .word -1303
   .word 1383
   .word 648
   .word -378
   .word -171
   .word 1036
   .word 128
   .word -308
   .word -691
   .word 263
   .word -86
   .word 691
   .word 565
   .word -278
   .word -118
   .word -917
   .word 570
   .word 131
   .word -592
   .word 577
   .word -112
   .word -801
   .word -514
   .word 598
   .word 471
   .word -853
   .word 377
   .word 561
   .word 638
   .word -294
   .word 771
   .word 1355
   .word -1392
   .word 344
   .word 317
   .word 733
   .word -501
   .word 889
   .word 430
   .word -1226
   .word -711
   .word -162
   .word -1144
   .word -1105
   .word 353
   .word 1081
   .word 1309
   .word -396
   .word 716
   .word 12
   .word -1149
   .word -99
   .word -1051
   .word -232
   .word 1305
   .word -858
   .word -247
   .word -189
   .word 793
   .word 733
   .word 1122
   .word -1274
   .word 941
   .word -129
   .word 1230
   .word -1423
   .word 1399
   .word 1163
   .word -129
   .word 130
   .word 191
   .word -806
   .word 1010
   .word -454
   .word 398
   .word 723
   .word 1362
   .word -328
   .word -61
   .word -172
   .word 444
   .word 339
   .word 696
   .word 544
   .word 11
   .word -1407
   .word -906
   .word -628
   .word -1001
   .word -529
   .word -1295
   .word 916
   .word 832
   .word -337
   .word -1322
   .word -896
   .word -3
   .word 1294
   .word -842
   .word 353
   .word -320
   .word 158
   .word 229
   .word -242
   .word -1284
   .word 442
   .word -188
   .word 712
   .word 98
   .word 420
   .word -1159
   .word 336
   .word 355
   .word 287
   .word 1248
   .word 1113
   .word -698
   .word 470
   .word -561
   .word -259
   .word -148
   .word 360
   .word 258
   .word 962
   .word 637
   .word 841
   .word 845
   .word 1272
   .word -521
   .word 388
   .word -1053
   .word 93
   .word -803
   .word -1166
   .word 736
   .word 670
   .word 388
   .word -992
   .word 643
   .word -902
   .word -1184
   .word -36
   .word -1052
   .word 725
   .word -179
   .word 792
   .word 450
   .word 1126
   .word -1378
   .word -168
   .word -464
   .word 692
   .word -999
   .word 87
   .word -927
   .word 502
   .word -459
   .word -1249
   .word 1047
   .word 533
   .word -815
   .word -1275
   .word -608
   .word 891
   .word -1322
   .word 314
   .word -49
   .word 454
   .word 171
   .word -848
   .word -120
   .word 92
   .word -1304
   .word -528
   .word 1090
   .word -1008
   .word -363
   .word 542
   .word -297
   .word 577
   .word 368
   .word -46
   .word -419
   .word 1348
   .word 16
   .word 176
   .word -1015
   .word 852
   .word -409
   .word 1365
   .word 20
   .word -644
   .word 1130
   .word -1250
   .word 302
   .word 197
   .word -401
   .word 946
   .word -412
   .word -1219
   .word -333
   .word -602
   .word -353
   .word 21
   .word -271
   .word 125
   .word 999
   .word 1229
   .word -220
   .word 238
   .word 279
   .word -591
   .word 1053
   .word 1027
   .word -1158
   .word 553
   .word 835
   .word -1045
   .word 612
   .word 158
   .word -415
   .word 1104
   .word 95
   .word -64
   .word 86
   .word 1224
   .word 23
   .word -1153
   .word 1008
   .word 698
   .word 710
   .word 887
   .word 1216
   .word 407
   .word -885
   .word -428
   .word -1259
   .word 1107
   .word 1032
   .word -481
   .word -1324
   .word -939
   .word 466
   .word 1238
   .word 1167
   .word 1293
   .word -246
   .word -848
   .word 288
   .word 517
   .word 827
   .word 1106
   .word 617
   .word 1178
   .word 1354
   .word 94
   .word -293
   .word 1137
   .word 207
   .word 1349
   .word 486
   .word -302
   .word -1283
   .word 545
   .word 1001
   .word -864
   .word -1066
   .word -1376
   .word -570
   .word -1313
   .word 157
   .word 806
   .word -309
   .word 1201
   .word 983
   .word 62
   .word 76
   .word 1196
   .word 661
   .word -55
   .word 1115
   .word 882
   .word 329
   .word -234
   .word -982
   .word -1277
   .word -964
   .word 830
   .word 871
   .word 867
   .word -691
   .word -1090
   .word 900
   .word -1117
   .word -864
   .word -60
   .word 1274
   .word 822
   .word 1163
   .word -354
   .word 102
   .word 786
   .word -1291
   .word -350
   .word 1124
   .word -841
   .word -794
   .word -598
   .word 123
   .word -441
   .word -220
   .word 251
   .word -1046
   .word 816
   .word 899
   .word 999
   .word 1107
   .word 195
   .word -470
   .word -177
   .word -733
   .word -1158
   .word 1414
   .word 545
   .word 854
   .word 1219
   .word 884
   .word -761
   .word 121
   .word 813
   .word -131
   .word -594
   .word -1082
   .word -1183
   .word -768
   .word 528
   .word -141
   .word -1143
   .word -1034
   .word 73
   .word 611
   .word 167
   .word 588
   .word -977
   .word 842
   .word 1418
   .word 1028
   .word 484
   .word 592
   .word -1307
   .word 412
   .word -595
   .word 932
   .word -222
   .word 1278
   .word -779
   .word -223
   .word -434
   .word -289
   .word 580
   .word 614
   .word -712
   .word 916
   .word 652
   .word 1001
   .word -574
   .word -145
   .word 420
   .word -841
   .word -748
   .word -809
   .word -1095
   .word 880
   .word 175
   .word -1014
   .word -232
   .word -1046
   .word 1015
   .word 1364
   .word -570
   .word 712
   .word -213
   .word -1264
   .word 1051
   .word 643
   .word -204
   .word -1064
   .word -108
   .word -1185
   .word 1293
   .word 748
   .word -129
   .word -280
   .word -343
   .word 218
   .word -843
   .word 105
   .word -1170
   .word -540
   .word -190
   .word 535
   .word 308
   .word 1073
   .word -1019
   .word -380
   .word -8
   .word -1343
   .word 1186
   .word -1209
   .word -494
   .word 1306
   .word -415
   .word -448
   .word -743
   .word 233
   .word 250
   .word -1300
   .word 955
   .word 1123
   .word -1066
   .word -36
   .word 1010
   .word -1161
   .word 1114
   .word 68
   .word 754
   .word -48
   .word 778
   .word -588
   .word -1117
   .word -1394
   .word -1418
   .word 512
   .word 345
   .word 924
   .word 1420
   .word 1232
   .word -225
   .word -918
   .word 92
   .word 25
   .word 898
   .word -761
   .word 201
   .word 1337
   .word -1400
   .word 1357
   .word -460
   .word -661
   .word 620
   .word -583
   .word 624
   .word -222
   .word -50
   .word 40
   .word 324
   .word 1197
   .word -1039
   .word 1376
   .word -1358
   .word 61
   .word -507
   .word 804
   .word -255
   .word -1045
   .word -1102
   .word -11
   .word -374
   .word 231
   .word -23
   .word 342
   .word 159
   .word -588
   .word -445
   .word 452
   .word 113
   .word -90
   .word -522
   .word 710
   .word -528
   .word -570
   .word -368
   .word -510
   .word -879
   .word -981
   .word 1322
   .word -1111
   .word -32
   .word -1399
   .word 615
   .word -1322
   .word 856
   .word 144
   .word -355
   .word 1003
   .word 428
   .word -792
   .word 1170
   .word -763
   .word -1129
   .word 1155
   .word -338
   .word -1342
   .word -700
   .word 458
   .word 1024
   .word -341
   .word 421
   .word 138
   .word 1215
   .word 268
   .word 165
   .word -144
   .word 878
   .word -508
   .word -444
   .word 322
   .word -855
   .word -562
   .word -107
   .word 262
   .word -1031
   .word -812
   .word -613
   .word -300
   .word -1196
   .word 267
   .word -1095
   .word 283
   .word -766
   .word -2
   .word -1375
   .word 1006
   .word -107
   .word 155
   .word -234
   .word -1375
   .word -113
   .word 1254
   .word -840
   .word 1060
   .word 637
   .word -372
   .word -1310
   .word 8
   .word 197
   .word -4
   .word -1258
   .word 128
   .word -665
   .word -1247
   .word 1246
   .word 711
   .word -286
   .word 849
   .word 787
   .word 180
   .word 664
   .word -1237
   .word -870
   .word -1312
   .word -1325
   .word 1
   .word 223
   .word 691
   .word 1070
   .word -620
   .word 1095
   .word -783
   .word 446
   .word 990
   .word 15
   .word 491
   .word -807
   .word 763
   .word -198
   .word -1364
   .word -1273
   .word -921
   .word 1243
   .word -1260
   .word -702
   .word 16
   .word 1183
   .word 1415
   .word -1348
   .word -573
   .word -274
   .word 247
   .word -1107
   .word -1283
   .word 1374
   .word -160
   .word -223
   .word -966
   .word 1035
   .word 1253
   .word 482
   .word -574
   .word 1319
   .word 1036
   .word 369
   .word -796
   .word 555
   .word 418
   .word -461
   .word 1319
   .word 20
   .word -1266
   .word 328
   .word 341
   .word -123
   .word 446
   .word -1157
   .word -1279
   .word 1105
   .word 573
   .word 1408
   .word -223
   .word -195
   .word 165
   .word 790
   .word 1420
   .word -790
   .word -1056
   .word -581
   .word -1391
   .word 5
   .word -1026
   .word 930
   .word -298
   .word -570
   .word -1416
   .word -420
   .word 725
   .word 418
   .word -580
   .word -1340
   .word 867
   .word -1324
   .word 1022
   .word -115
   .word -371
   .word 1316
   .word -745
   .word 1060
   .word 1096
   .word 354
   .word 993
   .word -1285
   .word -794
   .word 1181
   .word 25
   .word -116
   .word 439
   .word 801
   .word -603
   .word 903
   .word 976
   .word 33
   .word 493
   .word -515
   .word -365
   .word 1337
   .word 586
   .word 471
   .word -349
   .word 611
   .word -154
   .word -343
   .word -1176
   .word 160
   .word -1141
   .word 735
   .word -448
   .word 140
   .word 783
   .word 787
   .word 1125
   .word -229
   .word 1410
   .word -1281
   .word 149
   .word 13
   .word 1240
   .word 762
   .word -228
   .word -1359
   .word -1226
   .word 468
   .word 537
   .word 1093
   .word -569
   .word -60
   .word 334
   .word -695
   .word -826
   .word -234
   .word -278
   .word 1320
   .word -400
   .word -395
   .word -351
   .word 266
   .word 523
   .word 72
   .word 713
   .word 12
   .word 943
   .word -905
   .word -861
   .word -1091
   .word 1377
   .word 1337
   .word -83
   .word -1340
   .word 400
   .word -423
   .word -808
   .word -177
   .word -1408
   .word -993
   .word -991
   .word 1403
   .word 60
   .word -670
   .word 752
   .word -1127
   .word -344
   .word -811
   .word 262
   .word 1123
   .word 1274
   .word 1002
   .word 901
   .word -850
   .word -996
   .word 1061
   .word -500
   .word -354
   .word 300
   .word -566
   .word 1314
   .word 16
   .word -1347
   .word 649
   .word 1185
   .word -319
   .word 293
   .word 669
   .word 105
   .word 1109
   .word -1293
   .word -250
   .word 343
   .word 627
   .word -554
   .word -106
   .word 362
   .word 391
   .word -491
   .word 185
   .word -1351
   .word 53
   .word -857
   .word 901
   .word 1306
   .word 426
   .word -378
   .word 437
   .word -1270
   .word 958
   .word 228
   .word 806
   .word -124
   .word -724
   .word 189
   .word 1187
   .word -923
   .word 1284
   .word -1414
   .word -1235
   .word -801
   .word 440
   .word -376
   .word 570
   .word 130
   .word -380
   .word -1227
   .word 860
   .word 508
   .word -678
   .word 804
   .word 177
   .word -467
   .word 79
   .word -402
   .word 1280
   .word -870
   .word 130
   .word -690
   .word 100
   .word -421
   .word -883
   .word 1273
   .word -1277
   .word -1264
   .word 464
   .word -549
   .word -278
   .word 942
   .word 610
   .word 395
   .word 1159
   .word -592
   .word 867
   .word -294
   .word 989
   .word -784
   .word 19
   .word 1164
   .word -1041
   .word -560
   .word 194
   .word 70
   .word 521
   .word 379
   .word 133
   .word 432
   .word 1288
   .word -527
   .word -576
   .word -752
   .word -693
   .word -1281
   .word 1288
   .word 466
   .word 801
   .word 1239
   .word 1372
   .word 292
   .word 614
   .word 660
   .word 51
   .word -386
   .word -988
   .word 883
   .word 130
   .word 1289
   .word -910
   .word -1116
   .word -18
   .word -290
   .word -168
   .word 1403
   .word 655
   .word 1377
   .word 950
   .word 1295
   .word 1374
   .word 653
   .word -867
   .word -244
   .word -854
   .word -313
   .word -1344
   .word 1297
   .word 704
   .word 140
   .word -18
   .word -1176
   .word -1392
   .word 799
   .word 637
   .word -89
   .word -1135
   .word -1386
   .word 268
   .word 307
   .word 217
   .word 897
   .word -1127
   .word 1054
   .word -878
   .word 1141
   .word -984
   .word -739
   .word -1110
   .word -1017
   .word -914
   .word -672
   .word 432
   .word -859
   .word -889
   .word 1227
   .word 83
   .word -311
   .word -185
   .word -55
   .word 28
   .word 621
   .word -930
   .word 1025
   .word -181
   .word -1152
   .word -45
   .word -1143
   .word -1324
   .word 443
   .word 1063
   .word -128
   .word 586
   .word 1128
   .word 1260
   .word 233
   .word -128
   .word 559
   .word 600
   .word -563
   .word 510
   .word -1119
   .word -48
   .word -750
   .word -1221
   .word 1167
   .word -1361
   .word -637
   .word -639
   .word 478
   .word -344
   .word -928
   .word 811
   .word 1240
   .word -1302
   .word -163
   .word -643
   .word -104
   .word -1134
   .word -48
   .word -1133
   .word -1400
   .word -646
   .word 981
   .word -1428
   .word 894
   .word -58
   .word 382
   .word -105
   .word -437
   .word 206
   .word 1188
   .word 65
   .word -611
   .word 1243
   .word 995
   .word -912
   .word 1371
   .word -931
   .word 883
   .word 233
   .word 1371
   .word 933
   .word 720
   .word -344
   .word 1068
   .word 1184
   .word 858
   .word 176
   .word -1014
   .word 231
   .word -1398
   .word -1141
   .word -798
   .word 1107
   .word 1369
   .word -622
   .word 478
   .word 291
   .word 1308
   .word 726
   .word -487
   .word 417
   .word -474
   .word 1402
   .word -748
   .word -511
   .word 472
   .word -1268
   .word -787
   .word -407
   .word 1199
   .word 227
   .word 539
   .word 9
   .word 1125
   .word -943
   .word 941
   .word 903
   .word 20
   .word 145
   .word -1100
   .word -648
   .word 745
   .word 1402
   .word -1180
   .word -1317
   .word 396
   .word -777
   .word 90
   .word 855
   .word -405
   .word 420
   .word -769
   .word -1410
   .word 240
   .word -1086
   .word 1051
   .word -1208
   .word -285
   .word -618
   .word 848
   .word -374
   .word -174
   .word -882
   .word 515
   .word -1018
   .word 941
   .word 1049
   .word -1166
   .word -934
   .word -540
   .word -1175
   .word 460
   .word 960
   .word 958
   .word 15
   .word -1029
   .word -798
   .word -448
   .word -972
   .word -671
   .word 922
   .word 917
   .word -576
   .word 615
   .word 988
   .word -181
   .word 365
   .word -1291
   .word 496
   .word -262
   .word -1243
   .word 457
   .word 832
   .word -341
   .word 323
   .word 789
   .word -1394
   .word 1300
   .word 415
   .word -943
   .word -345
   .word -827
   .word 887
   .word 922
   .word 624
   .word 563
   .word 871
   .word 979
   .word 353
   .word -250
   .word -202
   .word 578
   .word 437
   .word -555
   .word -1309
   .word -2
   .word -238
   .word -88
   .word -637
   .word 134
   .word 1222
   .word 847
   .word 689
   .word 219
   .word 1099
   .word 668
   .word -747
   .word 598
   .word 659
   .word -517
   .word -275
   .word 1216
   .word 836
   .word 1030
   .word 596
   .word 1295
   .word 1260
   .word 1271
   .word -953
   .word 535
   .word 846
   .word -936
   .word 1128
   .word -84
   .word 241
   .word 721
   .word 625
   .word 91
   .word -128
   .word 603
   .word -803
   .word -225
   .word -1184
   .word 1066
   .word 874
   .word -1051
   .word -197
   .word 265
   .word -940
   .word 1341
   .word 1247
   .word -41
   .word -1235
   .word -1160
   .word -116
   .word -1087
   .word -1217
   .word -1256
   .word -41
   .word -49
   .word 873
   .word -116
   .word -1039
   .word -1082
   .word 1212
   .word 157
   .word -1232
   .word 522
   .word -270
   .word -1176
   .word 1395
   .word -640
   .word -795
   .word 400
   .word 740
   .word -681
   .word -462
   .word 1042
   .word -1030
   .word -566
   .word 1268
   .word 293
   .word 763
   .word -353
   .word -1409
   .word 1043
   .word 429
   .word -604
   .word 1327
   .word 99
   .word 634
   .word 83
   .word -821
   .word -170
   .word -1053
   .word 1000
   .word 184
   .word -1268
   .word 229
   .word -814
   .word 239
   .word 110
   .word 726
   .word -1150
   .word 249
   .word 1285
   .word -140
   .word 560
   .word -1033
   .word 163
   .word 869
   .word 245
   .word -145
   .word -250
   .word 1360
   .word -194
   .word -647
   .word -1364
   .word 1277
   .word 572
   .word -776
   .word 801
   .word 1244
   .word 576
   .word -551
   .word -1401
   .word -815
   .word -32
   .word -755
   .word 400
   .word -1281
   .word -1161
   .word 778
   .word -1120
   .word 93
   .word -228
   .word -389
   .word -908
   .word -839
   .word -333
   .word -19
   .word -89
   .word 334
   .word -416
   .word -1413
   .word 1094
   .word -1010
   .word 9
   .word -773
   .word -1377
   .word -1095
   .word 1343
   .word 529
   .word -1414
   .word 1109
   .word 186
   .word 12
   .word -150
   .word 378
   .word -225
   .word -631
   .word -647
   .word -315
   .word 1386
   .word 415
   .word -732
   .word 112
   .word -871
   .word -31
   .word -1031
   .word -547
   .word -76
   .word -328
   .word 511
   .word -1316
   .word 1158
   .word -792
   .word -283
   .word -775
   .word -815
   .word 117
   .word -1104
   .word 608
   .word 410
   .word 1281
   .word 1232
   .word 1001
   .word 791
   .word 1083
   .word 591
   .word -497
   .word 726
   .word 1243
   .word -802
   .word 225
   .word -224
   .word 230
   .word 150
   .word -1102
   .word -1143
   .word -1095
   .word 130
   .word -1276
   .word 45
   .word 78
   .word 207
   .word -1102
   .word 142
   .word 288
   .word -443
   .word 851
   .word -658
   .word 707
   .word -1005
   .word 1386
   .word -117
   .word 7
   .word -24
   .word 889
   .word 316
   .word -1279
   .word -767
   .word -357
   .word -65
   .word 1410
   .word 58
   .word -238
   .word 1083
   .word 1044
   .word 595
   .word -1006
   .word -126
   .word -101
   .word -450
   .word -1420
   .word -1039
   .word 476
   .word 119
   .word 368
   .word 1
   .word -1413
   .word 1318
   .word -569
   .word 736
   .word 22
   .word -871
   .word 1159
   .word 389
   .word 1284
   .word 660
   .word -875
   .word 588
   .word -855
   .word 312
   .word 717
   .word -511
   .word -30
   .word 800
   .word -438
   .word 281
   .word 106
   .word 714
   .word -1124
   .word -696
   .word 719
   .word -129
   .word -1407
   .word -689
   .word -559
   .word 956
   .word -599
   .word -522
   .word 465
   .word -951
   .word 279
   .word -1087
   .word 679
   .word 709
   .word -113
   .word -1278
   .word 767
   .word -764
   .word 1053
   .word 1400
   .word 654
   .word 456
   .word 110
   .word 457
   .word 309
   .word 112
   .word 827
   .word 342
   .word -1281
   .word -543
   .word 332
   .word 1239
   .word 368
   .word 103
   .word 628
   .word -162
   .word -1133
   .word -1358
   .word -1389
   .word -720
   .word -769
   .word 1062
   .word 159
   .word -1088
   .word 228
   .word 966
   .word -264
   .word 823
   .word -14
   .word -1156
   .word 411
   .word -255
   .word 1114
   .word -85
   .word 804
   .word -174
   .word 42
   .word 91
   .word 651
   .word -521
   .word 375
   .word 1070
   .word 929
   .word -800
   .word -91
   .word 243
   .word -835
   .word 1223
   .word -1082
   .word 1331
   .word -1005
   .word 513
   .word 749
   .word 77
   .word -670
   .word -932
   .word -1231
   .word 1265
   .word -1011
   .word -1286
   .word -812
   .word 558
   .word 933
   .word 1346
   .word 667
   .word -177
   .word -439
   .word 1342
   .word -980
   .word 767
   .word 473
   .word -13
   .word 628
   .word 111
   .word -1199
   .word -824
   .word 164
   .word -233
   .word -583
   .word 730
   .word -348
   .word -1171
   .word -1420
   .word 1261
   .word 210
   .word 1248
   .word 291
   .word -1110
   .word 1179
   .word -485
   .word 222
   .word 1386
   .word 890
   .word 837
   .word -726
   .word 248
   .word -946
   .word 864
   .word -175
   .word 1398
   .word -755
   .word -1162
   .word -637
   .word -1069
   .word -1186
   .word 306
   .word -176
   .word 795
   .word -1275
   .word -978
   .word 1137
   .word 989
   .word -626
   .word 1289
   .word -1217
   .word -102
   .word -151
   .word 1059
   .word -796
   .word -281
   .word -705
   .word 1033
   .word -29
   .word -614
   .word 505
   .word -1225
   .word 790
   .word 414
   .word 1143
   .word -1425
   .word -546
   .word 791
   .word -20
   .word 283
   .word 1153
   .word -1263
   .word 126
   .word 1411
   .word -648
   .word 459
   .word -1176
   .word -1085
   .word 432
   .word -436
   .word -1403
   .word -52
   .word 776
   .word 473
   .word -760
   .word 1272
   .word -709
   .word -448
   .word 1198
   .word -715
   .word -736
   .word 939
   .word 445
   .word -708
   .word -918
   .word -960
   .word 1264
   .word -559
   .word 599
   .word -805
   .word 414
   .word -797
   .word 846
   .word 529
   .word -732
   .word -654
   .word 391
   .word -853
   .word 542
   .word 1300
   .word 673
   .word 217
   .word -690
   .word -371
   .word -378
   .word -824
   .word 153
   .word -898
   .word 238
   .word 732
   .word 1340
   .word -618
   .word -479
   .word 1328
   .word -414
   .word -320
   .word 1287
   .word 535
   .word 921
   .word -1305
   .word -1364
   .word 866
   .word 1266
   .word -464
   .word -1017
   .word 887
   .word -396
   .word -50
   .word -245
   .word 235
   .word 132
   .word -320
   .word 302
   .word 1379
   .word 933
   .word 477
   .word -540
   .word 1053
   .word 196
   .word -1423
   .word -474
   .word -1041
   .word 1044
   .word -1390
   .word 530
   .word -1295
   .word 475
   .word -19
   .word -289
   .word -1026
   .word 584
   .word 579
   .word 777
   .word -69
   .word -739
   .word 821
   .word 1243
   .word 1387
   .word -1200
   .word 435
   .word 257
   .word -756
   .word 441
   .word 1315
   .word 215
   .word -884
   .word -938
   .word 1346
   .word -174
   .word 851
   .word 1152
   .word 1347
   .word 448
   .word 821
   .word -401
   .word 1380
   .word 1163
   .word -215
   .word -797
   .word -549
   .word 922
   .word -1015
   .word -292
   .word 56
   .word 697
   .word -748
   .word -747
   .word 603
   .word -157
   .word -142
   .word 867
   .word 1211
   .word 65
   .word -994
   .word 384
   .word -784
   .word 1093
   .word -1321
   .word -384
   .word 727
   .word -968
   .word -976
   .word 520
   .word 479
   .word -548
   .word 835
   .word -1023
   .word 332
   .word -720
   .word 27
   .word 1133
   .word 1085
   .word -128
   .word 912
   .word 606
   .word -840
   .word 452
   .word -431
   .word -1297
   .word 1166
   .word -886
   .word 479
   .word 1132
   .word -129
   .word -150
   .word 1242
   .word 1279
   .word 634
   .word 240
   .word -138
   .word -800
   .word -859
   .word -951
   .word 15
   .word -711
   .word 529
   .word -764
   .word -396
   .word 154
   .word -978
   .word -44
   .word 557
   .word 1144
   .word -296
   .word -253
   .word 627
   .word -54
   .word -77
   .word 372
   .word -811
   .word -232
   .word -1326
   .word 625
   .word 1038
   .word -8
   .word 260
   .word 365
   .word -467
   .word -181
   .word -1293
   .word 994
   .word -869
   .word 233
   .word -1121
   .word 733
   .word 248
   .word -621
   .word -1012
   .word -524
   .word 239
   .word -819
   .word 729
   .word -413
   .word -1242
   .word 519
   .word -1199
   .word 41
   .word 1058
   .word 901
   .word -733
   .word 703
   .word -919
   .word 683
   .word 334
   .word -191
   .word -205
   .word -498
   .word 1267
   .word 482
   .word 273
   .word 1246
   .word -352
   .word -807
   .word -694
   .word 1236
   .word 221
   .word 1055
   .word -1369
   .word -89
   .word 124
   .word 793
   .word 335
   .word 354
   .word 32
   .word 1107
   .word -1389
   .word -904
   .word -221
   .word 322
   .word 986
   .word 580
   .word -1191
   .word -1234
   .word -459
   .word -313
   .word -151
   .word -566
   .word 845
   .word -1036
   .word -582
   .word 777
   .word -1178
   .word -1126
   .word -468
   .word 577
   .word 345
   .word 1154
   .word -94
   .word 853
   .word 662
   .word -85
   .word 582
   .word 952
   .word -22
   .word 732
   .word 133
   .word 372
   .word 403
   .word -296
   .word 268
   .word -391
   .word 857
   .word -604
   .word -421
   .word -1145
   .word 922
   .word -26
   .word 426
   .word -23
   .word 720
   .word 951
   .word 560
   .word 852
   .word -923
   .word 547
   .word -1129
   .word -1080
   .word -1254
   .word -863
   .word -972
   .word 108
   .word -959
   .word 756
   .word 287
   .word 698
   .word 763
   .word -1066
   .word 695
   .word 38
   .word -747
   .word 1348
   .word -36
   .word 1425
   .word -915
   .word -94
   .word 567
   .word 1030
   .word 725
   .word -173
   .word 859
   .word 823
   .word 902
   .word -525
   .word 1291
   .word -1189
   .word 1374
   .word -108
   .word -1380
   .word -319
   .word -273
   .word -1156
   .word -196
   .word 793
   .word 454
   .word 42
   .word 8
   .word 751
   .word 1400
   .word 1239
   .word -1302
   .word 643
   .word 412
   .word -780
   .word -163
   .word 180
   .word -629
   .word 1393
   .word 834
   .word -837
   .word -439
   .word 844
   .word -1375
   .word 466
   .word 1180
   .word -1306
   .word 70
   .word -217
   .word 533
   .word 324
   .word -331
   .word 983
   .word 1260
   .word 1171
   .word -1283
   .word -837
   .word -562
   .word 716
   .word -1195
   .word -942
   .word 213
   .word 1348
   .word -1227
   .word 666
   .word 1222
   .word 664
   .word -1258
   .word -433
   .word -1257
   .word -511
   .word -321
   .word 884
   .word 965
   .word 1282
   .word 618
   .word 266
   .word 1278
   .word -537
   .word 968
   .word 201
   .word -704
   .word -123
   .word -1422
   .word 608
   .word -1400
   .word 144
   .word 671
   .word -751
   .word -226
   .word -800
   .word -1394
   .word 810
   .word 738
   .word -1048
   .word 30
   .word -742
   .word 620
   .word 90
   .word 1367
   .word -340
   .word 250
   .word -591
   .word -960
   .word -104
   .word -903
   .word -1264
   .word 953
   .word 28
   .word -421
   .word 901
   .word 1161
   .word -72
   .word 1339
   .word -505
   .word -789
   .word -1052
   .word 952
   .word -1357
   .word -448
   .word 830
   .word 630
   .word 731
   .word -901
   .word -1148
   .word 1240
   .word 1144
   .word -1242
   .word 1321
   .word -1304
   .word -91
   .word 1254
   .word -395
   .word -839
   .word 1377
   .word 1321
   .word -312
   .word -468
   .word -1188
   .word 828
   .word 914
   .word -744
   .word -1324
   .word -144
   .word -1350
   .word -372
   .word 667
   .word 518
   .word -493
   .word -332
   .word 852
   .word 337
   .word -1125
   .word -567
   .word 1109
   .word 781
   .word 818
   .word 335
   .word 684
   .word -1145
   .word -1204
   .word -128
   .word 590
   .word 1042
   .word -790
   .word 1174
   .word -619
   .word 1203
   .word -1423
   .word 439
   .word 813
   .word -1399
   .word 1348
   .word 247
   .word -132
   .word 1081
   .word -197
   .word -1085
   .word 991
   .word -1111
   .word -217
   .word -602
   .word 543
   .word 650
   .word 1326
   .word -99
   .word 181
   .word -41
   .word -1010
   .word 131
   .word -1171
   .word -552
   .word 171
   .word 1067
   .word -10
   .word 1002
   .word -1151
   .word 1090
   .word -729
   .word 552
   .word -123
   .word -1196
   .word -296
   .word 752
   .word 1197
   .word 312
   .word 189
   .word -1200
   .word -875
   .word -1122
   .word -1136
   .word 753
   .word -1274
   .word -489
   .word -1222
   .word -908
   .word -746
   .word 920
   .word 44
   .word -498
   .word -355
   .word -685
   .word 1236
   .word -805
   .word 965
   .word 1221
   .word -1010
   .word 360
   .word 1370
   .word 115
   .word 561
   .word -770
   .word -1251
   .word -919
   .word 1260
   .word -1379
   .word 286
   .word -892
   .word -259
   .word 816
   .word 89
   .word 1103
   .word 311
   .word 1109
   .word 637
   .word 230
   .word -294
   .word 590
   .word -626
   .word 505
   .word -1048
   .word -522
   .word -818
   .word -1079
   .word -662
   .word 202
   .word 241
   .word 778
   .word 1391
   .word -1320
   .word 796
   .word 77
   .word 543
   .word 515
   .word 92
   .word -170
   .word 105
   .word 1317
   .word -758
   .word 482
   .word -248
   .word -323
   .word -943
   .word 344
   .word 459
   .word 468
   .word -725
   .word -151
   .word -819
   .word -350
   .word -59
   .word 720
   .word 923
   .word -1278
   .word -314
   .word -466
   .word 1353
   .word 88
   .word -980
   .word -1100
   .word -909
   .word -1124
   .word 1426
   .word 482
   .word 539
   .word 514
   .word 37
   .word -111
   .word -522
   .word 928
   .word -522
   .word -1332
   .word -888
   .word 1225
   .word -1411
   .word -1156
   .word -1254
   .word 25
   .word 1349
   .word -459
   .word 483
   .word -252
   .word -1211
   .word -279
   .word 1225
   .word 230
   .word -1153
   .word -759
   .word 720
   .word 460
   .word 917
   .word -770
   .word 1290
   .word -387
   .word 361
   .word -641
   .word -709
   .word -1063
   .word -691
   .word -238
   .word 1371
   .word 103
   .word -819
   .word -632
   .word -358
   .word -844
   .word -655
   .word -48
   .word -1005
   .word 945
   .word 170
   .word 653
   .word 220
   .word 239
   .word -224
   .word 38
   .word 169
   .word 792
   .word -813
   .word 292
   .word 831
   .word 1074
   .word 1255
   .word -401
   .word 196
   .word -1033
   .word -858
   .word 1157
   .word -963
   .word 103
   .word -727
   .word 1298
   .word -153
   .word 1349
   .word -610
   .word -670
   .word 1303
   .word 606
   .word -1137
   .word 579
   .word 1075
   .word -1413
   .word 1130
   .word -865
   .word -1269
   .word 696
   .word 77
   .word -1321
   .word -543
   .word -480
   .word 766
   .word -656
   .word 798
   .word -119
   .word 435
   .word -75
   .word 943
   .word -953
   .word 610
   .word -576
   .word 553
   .word -91
   .word 340
   .word 814
   .word 850
   .word 959
   .word 227
   .word 1398
   .word -1339
   .word -858
   .word 323
   .word -976
   .word -685
   .word 159
   .word 1147
   .word -26
   .word 754
   .word 1170
   .word -1166
   .word -436
   .word -237
   .word -112
   .word -991
   .word -353
   .word 1163
   .word -1253
   .word -639
   .word -1087
   .word -825
   .word 876
   .word -524
   .word -158
   .word 42
   .word -286
   .word -1232
   .word -1360
   .word -486
   .word 421
   .word 1086
   .word -477
   .word 233
   .word -397
   .word 980
   .word -821
   .word -1324
   .word -1393
   .word -479
   .word 1171
   .word 545
   .word -983
   .word -504
   .word 1020
   .word -291
   .word 86
   .word 673
   .word 805
   .word 843
   .word -520
   .word 500
   .word 57
   .word 229
   .word -1370
   .word 1373
   .word 430
   .word 1357
   .word 1425
   .word 1322
   .word 157
   .word -95
   .word -505
   .word -332
   .word -335
   .word 18
   .word -1418
   .word -968
   .word -311
   .word 481
   .word -44
   .word 327
   .word 314
   .word -1122
   .word -552
   .word 602
   .word 766
   .word -982
   .word 389
   .word -852
   .word -210
   .word -846
   .word -878
   .word 1251
   .word 141
   .word -92
   .word -784
   .word -204
   .word 554
   .word -505
   .word 269
   .word 540
   .word -1087
   .word 380
   .word 236
   .word 1137
   .word 158
   .word -109
   .word -838
   .word 155
   .word -974
   .word -1034
   .word 1227
   .word 1184
   .word 554
   .word -1015
   .word -1030
   .word -1025
   .word -377
   .word -522
   .word 1264
   .word 1052
   .word -1394
   .word -1244
   .word 822
   .word -1145
   .word 364
   .word -108
   .word -463
   .word -760
   .word -454
   .word -128
   .word 420
   .word -1131
   .word 1280
   .word -565
   .word 620
   .word 678
   .word 457
   .word -1391
   .word 1317
   .word -581
   .word 1087
   .word -1122
   .word -195
   .word 234
   .word 841
   .word -693
   .word 75
   .word -591
   .word -596
   .word -959
   .word 398
   .word -1103
   .word -1359
   .word 59
   .word 85
   .word -1393
   .word 354
   .word 1336
   .word -744
   .word -464
   .word 1282
   .word -1272
   .word -1357
   .word -1136
   .word -584
   .word -1098
   .word -123
   .word -869
   .word 191
   .word 928
   .word -450
   .word 1284
   .word -402
   .word 751
   .word 764
   .word -672
   .word 243
   .word -279
   .word 1285
   .word 1377
   .word -57
   .word -1359
   .word 1258
   .word 121
   .word 1189
   .word -807
   .word 756
   .word 1409
   .word -722
   .word -214
   .word 692
   .word -60
   .word -630
   .word -1162
   .word -870
   .word 635
   .word 739
   .word 1427
   .word -1242
   .word -1035
   .word -1392
   .word -682
   .word 286
   .word 1116
   .word 928
   .word -821
   .word -194
   .word -1263
   .word 1127
   .word 417
   .word 240
   .word 904
   .word 1043
   .word 723
   .word -1221
   .word -523
   .word -1313
   .word 383
   .word -1345
   .word 281
   .word 558
   .word 1418
   .word -594
   .word -244
   .word 1090
   .word 511
   .word 253
   .word -1221
   .word 1258
   .word 395
   .word -81
   .word -16
   .word -1074
   .word -1064
   .word -553
   .word -1347
   .word 315
   .word -390
   .word -186
   .word 863
   .word 115
   .word 406
   .word -458
   .word -640
   .word -63
   .word 1052
   .word -1411
   .word -546
   .word -584
   .word -226
   .word 1081
   .word -438
   .word -480
   .word 631
   .word -1090
   .word -589
   .word 968
   .word -603
   .word -82
   .word -879
   .word 701
   .word -1227
   .word -674
   .word -608
   .word -1184
   .word -602
   .word 509
   .word 871
   .word -1060
   .word -55
   .word 604
   .word 943
   .word 187
   .word 798
   .word 1199
   .word 945
   .word 780
   .word -316
   .word 465
   .word -651
   .word -519
   .word -524
   .word 832
   .word 192
   .word 373
   .word 676
   .word 298
   .word -329
   .word -625
   .word -1237
   .word -1420
   .word 682
   .word 633
   .word 708
   .word -604
   .word -1231
   .word 54
   .word -1109
   .word 852
   .word -739
   .word -948
   .word 1240
   .word 107
   .word 1187
   .word -213
   .word -683
   .word -1092
   .word -1260
   .word -461
   .word -361
   .word -952
   .word 988
   .word -825
   .word -823
   .word 880
   .word 289
   .word 1112
   .word 1136
   .word 787
   .word -1065
   .word -264
   .word -1411
   .word -797
   .word -679
   .word -421
   .word 1031
   .word -895
   .word -364
   .word -894
   .word -1078
   .word 111
   .word -517
   .word 366
   .word 88
   .word 747
   .word 1055
   .word -1303
   .word 1211
   .word -1302
   .word -281
   .word 1115
   .word 742
   .word 492
   .word 457
   .word -202
   .word 1297
   .word -1044
   .word -1121
   .word -1044
   .word -1310
   .word 11
   .word 949
   .word -210
   .word 577
   .word -1287
   .word 959
   .word -832
   .word 403
   .word 977
   .word -129
   .word -1005
   .word 1272
   .word -487
   .word -589
   .word -1381
   .word -639
   .word 1109
   .word 349
   .word -584
   .word 1131
   .word 1299
   .word -982
   .word 656
   .word -733
   .word 128
   .word -933
   .word -125
   .word -826
   .word -1299
   .word 296
   .word -373
   .word -297
   .word 1014
   .word 197
   .word 822
   .word 883
   .word -1018
   .word -119
   .word -191
   .word 122
   .word 1137
   .word -152
   .word 1147
   .word 38
   .word 716
   .word -222
   .word 696
   .word -1414
   .word -181
   .word -947
   .word 1319
   .word 1115
   .word -639
   .word -316
   .word 1241
   .word -520
   .word -810
   .word -336
   .word 957
   .word 100
   .word 107
   .word -1223
   .word -1173
   .word 763
   .word 95
   .word -440
   .word 1059
   .word 1367
   .word -611
   .word 49
   .word -1355
   .word -222
   .word 1358
   .word 437
   .word 1292
   .word -905
   .word -1371
   .word 1009
   .word -656
   .word -301
   .word -1301
   .word -1132
   .word 81
   .word -1354
   .word -1071
   .word -313
   .word 1399
   .word 544
   .word -654
   .word 155
   .word -133
   .word -232
   .word -1096
   .word 808
   .word 915
   .word -564
   .word -1051
   .word -1404
   .word 1373
   .word -1325
   .word 920
   .word 123
   .word -950
   .word 330
   .word -961
   .word -643
   .word -349
   .word -401
   .word 1109
   .word 1320
   .word -1072
   .word -1187
   .word -685
   .word 1105
   .word -851
   .word -60
   .word 142
   .word 197
   .word 726
   .word -1236
   .word -1029
   .word 1006
   .word -741
   .word -64
   .word 731
   .word -1023
   .word 1183
   .word -680
   .word -256
   .word 1267
   .word -879
   .word -283
   .word 440
   .word 1233
   .word 1265
   .word 442
   .word -590
   .word -168
   .word -832
   .word -178
   .word 979
   .word 529
   .word 840
   .word -296
   .word 474
   .word -431
   .word 674
   .word 429
   .word 203
   .word 1391
   .word -1218
   .word 192
   .word -697
   .word -1293
   .word 155
   .word 254
   .word -457
   .word -693
   .word -968
   .word 1174
   .word 315
   .word -633
   .word -1393
   .word -52
   .word -765
   .word -1173
   .word -692
   .word -209
   .word 188
   .word -1346
   .word 752
   .word -1115
   .word 866
   .word -54
   .word 306
   .word 34
   .word 563
   .word -454
   .word 282
   .word 1101
   .word -1084
   .word 1029
   .word 1018
   .word 1406
   .word -876
   .word -924
   .word 1366
   .word -294
   .word -1077
   .word 740
   .word 492
   .word 1274
   .word 452
   .word 891
   .word 767
   .word -98
   .word -719
   .word -288
   .word -671
   .word -607
   .word 916
   .word -753
   .word 450
   .word -923
   .word 1262
   .word 1061
   .word -394
   .word 942
   .word 725
   .word 99
   .word -147
   .word 600
   .word 661
   .word -1311
   .word -173
   .word 74
   .word -571
   .word -593
   .word -1065
   .word -522
   .word 1117
   .word 1052
   .word -1394
   .word 444
   .word -956
   .word 513
   .word 835
   .word -1086
   .word 833
   .word -1391
   .word -1
   .word -840
   .word 182
   .word -1348
   .word -360
   .word -1352
   .word 1128
   .word 932
   .word -246
   .word 171
   .word -605
   .word 576
   .word -869
   .word -913
   .word 1356
   .word -821
   .word 563
   .word 1290
   .word 576
   .word -924
   .word 627
   .word 910
   .word 157
   .word -434
   .word -236
   .word 1246
   .word 66
   .word -174
   .word -902
   .word -219
   .word -784
   .word -1295
   .word 374
   .word -223
   .word 669
   .word -593
   .word -991
   .word -1258
   .word 1023
   .word 690
   .word -352
   .word 954
   .word -1134
   .word -910
   .word -886
   .word 186
   .word -438
   .word -1390
   .word 886
   .word 1076
   .word -1108
   .word -1247
   .word -1078
   .word 961
   .word -169
   .word 1051
   .word -1261
   .word 164
   .word 315
   .word -1180
   .word 1026
   .word -1356
   .word 579
   .word 291
   .word -1313
   .word 880
   .word 126
   .word -902
   .word 236
   .word -817
   .word -594
   .word -1085
   .word -835
   .word 1158
   .word 286
   .word -322
   .word -1399
   .word 468
   .word 1093
   .word -436
   .word -1376
   .word 551
   .word -391
   .word 657
   .word 133
   .word -1051
   .word -957
   .word -585
   .word -1203
   .word -1108
   .word -1205
   .word -762
   .word 1364
   .word 182
   .word 1363
   .word -805
   .word -159
   .word -688
   .word 180
   .word 260
   .word 787
   .word -119
   .word -1408
   .word 844
   .word 934
   .word -894
   .word 690
   .word -1146
   .word -995
   .word 298
   .word -877
   .word -1250
   .word 1096
   .word -984
   .word 819
   .word -751
   .word -483
   .word 138
   .word -1245
   .word 1381
   .word 852
   .word 26
   .word -889
   .word 506
   .word -782
   .word -342
   .word -865
   .word 426
   .word -395
   .word -608
   .word -461
   .word -703
   .word 498
   .word -1114
   .word 655
   .word -822
   .word -1314
   .word -1113
   .word -1243
   .word -345
   .word 228
   .word 1084
   .word -819
   .word -256
   .word 1027
   .word 592
   .word 977
   .word -200
   .word -808
   .word -153
   .word -80
   .word -1423
   .word 941
   .word 384
   .word 502
   .word -1231
   .word 159
   .word -224
   .word -1220
   .word 33
   .word 1312
   .word 1342
   .word -1148
   .word -474
   .word -1086
   .word -981
   .word 726
   .word -204
   .word 1157
   .word 133
   .word 307
   .word 1016
   .word 204
   .word 1069
   .word 559
   .word 933
   .word 799
   .word -616
   .word -49
   .word 372
   .word -597
   .word 4
   .word -1189
   .word 1274
   .word 1367
   .word -853
   .word -1179
   .word 1335
   .word 540
   .word 1000
   .word 325
   .word -1036
   .word 1410
   .word -324
   .word -143
   .word 596
   .word -759
   .word 806
   .word -267
   .word 380
   .word -547
   .word 772
   .word -697
   .word 609
   .word -1052
   .word 322
   .word -84
   .word -866
   .word 1055
   .word -407
   .word 1021
   .word 478
   .word -659
   .word 349
   .word 1310
   .word -1402
   .word 1409
   .word 1192
   .word 1203
   .word -3
   .word -591
   .word 451
   .word -272
   .word 1000
   .word 1368
   .word 1056
   .word 691
   .word 873
   .word -1291
   .word 355
   .word 855
   .word -51
   .word -570
   .word 473
   .word -1154
   .word -120
   .word 1210
   .word 863
   .word 709
   .word -952
   .word 649
   .word -698
   .word -39
   .word 1045
   .word 1232
   .word 1256
   .word -1363
   .word 1161
   .word -192
   .word -168
   .word -982
   .word -118
   .word 253
   .word 453
   .word -88
   .word -602
   .word 1100
   .word -1334
   .word 596
   .word -31
   .word -180
   .word 1000
   .word 691
   .word -587
   .word -52
   .word 1176
   .word 252
   .word 1127
   .word 1050
   .word 502
   .word -874
   .word 1344
   .word 1235
   .word 446
   .word -188
   .word 815
   .word 3
   .word -1081
   .word 347
   .word 148
   .word 1219
   .word 891
   .word -582
   .word -56
   .word -1186
   .word 154
   .word 251
   .word -1333
   .word 814
   .word -57
   .word 1383
   .word -922
   .word -62
   .word -322
   .word 175
   .word 1111
   .word 556
   .word 483
   .word 1223
   .word 226
   .word 811
   .word -800
   .word 500
   .word 865
   .word -1195
   .word -1098
   .word -164
   .word 447
   .word -1420
   .word 1183
   .word 1334
   .word -987
   .word -5
   .word -571
   .word -517
   .word 165
   .word 519
   .word -767
   .word 92
   .word -859
   .word 1103
   .word 1292
   .word 895
   .word 802
   .word 788
   .word -1394
   .word 107
   .word 1335
   .word 31
   .word -1080
   .word -657
   .word 154
   .word -1064
   .word -522
   .word 1010
   .word -404
   .word -6
   .word -487
   .word 1304
   .word 407
   .word 352
   .word -792
   .word -860
   .word 1346
   .word 824
   .word -120
   .word -28
   .word 211
   .word -1124
   .word -755
   .word -200
   .word -199
   .word -174
   .word 1258
   .word -1303
   .word -8
   .word -327
   .word -1245
   .word -663
   .word 687
   .word -18
   .word -900
   .word 282
   .word -744
   .word -84
   .word -833
   .word -804
   .word 330
   .word 1045
   .word -663
   .word -24
   .word 46
   .word -1373
   .word 1026
   .word 1001
   .word 774
   .word 489
   .word 440
   .word 51
   .word -1129
   .word 64
   .word 813
   .word 701
   .word 789
   .word 996
   .word -416
   .word 508
   .word -1397
   .word 1019
   .word -649
   .word 162
   .word -1043
   .word 1017
   .word 687
   .word -368
   .word 572
   .word -664
   .word -1412
   .word -1087
   .word -847
   .word -1258
   .word 1289
   .word 1039
   .word -1288
   .word -910
   .word -774
   .word -73
   .word 336
   .word 683
   .word 275
   .word -549
   .word 989
   .word -695
   .word -1085
   .word -837
   .word 57
   .word 325
   .word -1021
   .word -1380
   .word 559
   .word -673
   .word -485
   .word 958
   .word -644
   .word 337
   .word -259
   .word 775
   .word -1275
   .word 25
   .word -1109
   .word -1222
   .word 1109
   .word -572
   .word 538
   .word -534
   .word 1320
   .word 190
   .word -618
   .word 352
   .word -276
   .word 87
   .word 883
   .word 1191
   .word 1194
   .word -1344
   .word 783
   .word -814
   .word -518
   .word -775
   .word -1059
   .word 896
   .word 469
   .word -515
   .word 963
   .word 1205
   .word 1269
   .word -1230
   .word -151
   .word -1315
   .word 530
   .word -1291
   .word -1000
   .word -710
   .word 285
   .word -216
   .word -1225
   .word 235
   .word -741
   .word 1226
   .word -1153
   .word 1415
   .word -310
   .word -364
   .word -329
   .word -1189
   .word 876
   .word 66
   .word -212
   .word 993
   .word -845
   .word -1025
   .word -26
   .word 625
   .word 129
   .word -671
   .word -367
   .word -1084
   .word -885
   .word 821
   .word 501
   .word -438
   .word 432
   .word 212
   .word 1147
   .word -217
   .word -1142
   .word -1106
   .word 739
   .word -59
   .word -707
   .word -1287
   .word -1416
   .word -252
   .word -1403
   .word -1002
   .word -932
   .word 1320
   .word 895
   .word -58
   .word 826
   .word 192
   .word -720
   .word -227
   .word 1267
   .word -889
   .word -1096
   .word 1336
   .word -847
   .word 682
   .word -1037
   .word -165
   .word 862
   .word 1335
   .word -1103
   .word 605
   .word -824
   .word 357
   .word -1092
   .word -702
   .word 671
   .word 445
   .word -421
   .word 1259
   .word -679
   .word -82
   .word -296
   .word -612
   .word 577
   .word 861
   .word 1244
   .word 429
   .word 396
   .word 641
   .word -870
   .word 1262
   .word -1338
   .word -1133
   .word 553
   .word 944
   .word -1385
   .word -120
   .word -637
   .word -831
   .word -1407
   .word 630
   .word -363
   .word 966
   .word -1045
   .word 986
   .word -238
   .word 166
   .word -105
   .word 1044
   .word -338
   .word 1369
   .word 629
   .word 300
   .word -232
   .word 94
   .word 403
   .word -1393
   .word -79
   .word -664
   .word 823
   .word -299
   .word -691
   .word -895
   .word -701
   .word 482
   .word 11
   .word 937
   .word 1052
   .word -943
   .word 98
   .word 1219
   .word 1248
   .word -6
   .word 615
   .word 1256
   .word -569
   .word -1205
   .word -1103
   .word -229
   .word 892
   .word -1057
   .word 202
   .word -1284
   .word -800
   .word -983
   .word 652
   .word 814
   .word -1150
   .word 271
   .word -1101
   .word -503
   .word 1215
   .word 827
   .word 906
   .word 683
   .word -1379
   .word -1187
   .word -309
   .word 981
   .word 1376
   .word -76
   .word -1388
   .word 1374
   .word -867
   .word -1401
   .word -435
   .word -1001
   .word -177
   .word -61
   .word -983
   .word -140
   .word 471
   .word 1331
   .word -693
   .word -1312
   .word 381
   .word 1362
   .word -1143
   .word 1360
   .word -503
   .word 812
   .word -264
   .word 484
   .word 1121
   .word 331
   .word 1190
   .word 1350
   .word 394
   .word -407
   .word 750
   .word -909
   .word -227
   .word -900
   .word 181
   .word -1033
   .word -839
   .word 1198
   .word 246
   .word 1284
   .word -744
   .word 1279
   .word -525
   .word -1086
   .word 880
   .word 1279
   .word -1291
   .word -1213
   .word 305
   .word 38
   .word 107
   .word 46
   .word 177
   .word -179
   .word 1390
   .word -1405
   .word 893
   .word -728
   .word -871
   .word 1215
   .word -1287
   .word 971
   .word -1383
   .word -920
   .word 253
   .word 1239
   .word -1134
   .word 338
   .word 1156
   .word 52
   .word 745
   .word -1341
   .word -422
   .word 603
   .word -679
   .word -342
   .word -1360
   .word -1084
   .word 195
   .word -162
   .word -632
   .word -1042
   .word 279
   .word 526
   .word 277
   .word -350
   .word 978
   .word 186
   .word 225
   .word -1068
   .word -1052
   .word 971
   .word -589
   .word 124
   .word 729
   .word 1327
   .word 9
   .word -886
   .word -612
   .word 229
   .word 154
   .word -511
   .word -964
   .word -522
   .word 217
   .word 808
   .word 1033
   .word 403
   .word 1282
   .word 1099
   .word -668
   .word 1114
   .word 62
   .word 989
   .word -56
   .word -960
   .word -1416
   .word -1285
   .word 1411
   .word 328
   .word 1350
   .word 456
   .word -871
   .word 673
   .word 1042
   .word -926
   .word -327
   .word 304
   .word -979
   .word -1384
   .word 519
   .word 470
   .word -616
   .word -1222
   .word 887
   .word 908
   .word -963
   .word -1135
   .word -1215
   .word -1269
   .word 974
   .word -268
   .word 1273
   .word 762
   .word -669
   .word 1355
   .word -343
   .word -472
   .word -1139
   .word -554
   .word 1015
   .word -578
   .word -1018
   .word 30
   .word -588
   .word -1082
   .word -249
   .word -858
   .word 709
   .word -406
   .word -1054
   .word -222
   .word -654
   .word 1062
   .word -698
   .word -1333
   .word 593
   .word -1175
   .word -1412
   .word -251
   .word 919
   .word -1270
   .word -124
   .word -75
   .word -549
   .word 974
   .word 146
   .word 1291
   .word -839
   .word 868
   .word 1354
   .word 706
   .word 462
   .word 423
   .word -913
   .word 400
   .word -1056
   .word -1101
   .word -196
   .word 783
   .word 834
   .word -487
   .word 1390
   .word -546
   .word 103
   .word 195
   .word -113
   .word -683
   .word 439
   .word -694
   .word 282
   .word 619
   .word -266
   .word 1256
   .word -626
   .word -652
   .word 324
   .word 1374
   .word -733
   .word -313
   .word 869
   .word 1136
   .word 1127
   .word 1225
   .word 270
   .word -1145
   .word 844
   .word 477
   .word 559
   .word 1129
   .word -195
   .word -796
   .word -626
   .word -799
   .word -1324
   .word 936
   .word 599
   .word 376
   .word 238
   .word -352
   .word -319
   .word -990
   .word -570
   .word -260
   .word 1193
   .word -383
   .word 1179
   .word 977
   .word 576
   .word 1276
   .word 1144
   .word 633
   .word 827
   .word 1066
   .word -852
   .word -838
   .word 309
   .word -1185
   .word 1306
   .word 1149
   .word 131
   .word -389
   .word -885
   .word -167
   .word 336
   .word -760
   .word -88
   .word -235
   .word -1185
   .word 1310
   .word 391
   .word 1388
   .word 1047
   .word 6
   .word -335
   .word 428
   .word 743
   .word 72
   .word -876
   .word 1013
   .word -1348
   .word -702
   .word -1041
   .word -1016
   .word -868
   .word 1111
   .word 980
   .word 1006
   .word 248
   .word 932
   .word 1388
   .word 878
   .word -259
   .word 1240
   .word -79
   .word -651
   .word 1100
   .word -669
   .word 254
   .word 1195
   .word 195
   .word 1408
   .word 1376
   .word 410
   .word -1070
   .word 929
   .word -1337
   .word 1166
   .word 310
   .word 852
   .word -349
   .word 272
   .word 702
   .word 224
   .word -521
   .word 124
   .word -1153
   .word 740
   .word 122
   .word -1083
   .word -1313
   .word 424
   .word 1255
   .word 1111
   .word -288
   .word -759
   .word 738
   .word -796
   .word -181
   .word -277
   .word 354
   .word -222
   .word 1347
   .word -1073
   .word -374
   .word 1257
   .word 387
   .word -376
   .word 768
   .word 153
   .word -1243
   .word -1374
   .word -1200
   .word 976
   .word 940
   .word -927
   .word -1241
   .word 754
   .word 1172
   .word 1267
   .word -29
   .word 718
   .word 805
   .word -1107
   .word -306
   .word -350
   .word -819
   .word -540
   .word -734
   .word -1155
   .word -156
   .word -1250
   .word -785
   .word -391
   .word -733
   .word 1375
   .word -988
   .word -493
   .word 1048
   .word -720
   .word 499
   .word 645
   .word -1134
   .word 450
   .word 137
   .word -103
   .word -1189
   .word -490
   .word -147
   .word -526
   .word -190
   .word 1289
   .word 496
   .word 1120
   .word -1029
   .word 630
   .word 1169
   .word 104
   .word -762
   .word -267
   .word 544
   .word 1331
   .word -628
   .word 873
   .word 272
   .word 394
   .word 1088
   .word 1171
   .word -511
   .word -395
   .word -534
   .word -1288
   .word 332
   .word 1051
   .word -932
   .word 1258
   .word -57
   .word 369
   .word -1306
   .word -1015
   .word 1180
   .word -1152
   .word 1070
   .word 421
   .word -298
   .word -1217
   .word 703
   .word -715
   .word 1345
   .word 571
   .word 1046
   .word -981
   .word 10
   .word 977
   .word -931
   .word 1159
   .word 1239
   .word -430
   .word 739
   .word 403
   .word 301
   .word -1026
   .word -565
   .word -579
   .word -690
   .word 598
   .word -1334
   .word -1021
   .word 246
   .word 98
   .word -239
   .word 516
   .word -1032
   .word 814
   .word -1389
   .word -145
   .word -877
   .word -554
   .word -695
   .word 693
   .word 1035
   .word -514
   .word 1377
   .word -988
   .word 401
   .word 541
   .word 1396
   .word 72
   .word -402
   .word -307
   .word 828
   .word 1113
   .word 211
   .word -536
   .word -1360
   .word -910
   .word 1032
   .word 1276
   .word 747
   .word 686
   .word -887
   .word 211
   .word -112
   .word 154
   .word 1109
   .word 1078
   .word 375
   .word 194
   .word -1082
   .word -826
   .word -749
   .word 1222
   .word 252
   .word 441
   .word -514
   .word 72
   .word 456
   .word 622
   .word 148
   .word 879
   .word 1251
   .word 1076
   .word 1210
   .word 18
   .word -690
   .word -294
   .word 915
   .word -360
   .word -645
   .word -402
   .word 898
   .word 569
   .word -1347
   .word 908
   .word 578
   .word -220
   .word 17
   .word 1120
   .word 63
   .word -1063
   .word -58
   .word -754
   .word -173
   .word 870
   .word 482
   .word -410
   .word 1109
   .word 1269
   .word 42
   .word -478
   .word -381
   .word -978
   .word -417
   .word -391
   .word -263
   .word -1399
   .word 445
   .word -313
   .word -1026
   .word -594
   .word -469
   .word -700
   .word 331
   .word -550
   .word -436
   .word 1307
   .word 1078
   .word 1035
   .word 538
   .word -1309
   .word -144
   .word 331
   .word -1088
   .word 483
   .word -710
   .word 965
   .word 1424
   .word 1203
   .word -641
   .word -757
   .word 1333
   .word -98
   .word 1147
   .word -292
   .word 707
   .word -107
   .word 105
   .word -423
   .word 615
   .word -843
   .word -906
   .word 1317
   .word 531
   .word 691
   .word -870
   .word 716
   .word 1390
   .word 1357
   .word -953
   .word -1315
   .word -506
   .word 350
   .word 225
   .word -639
   .word -530
   .word -522
   .word -338
   .word -1085
   .word 718
   .word 1320
   .word 1144
   .word 1087
   .word -46
   .word 506
   .word -779
   .word 263
   .word 402
   .word 1134
   .word -1242
   .word -622
   .word 1313
   .word -697
   .word -143
   .word -1291
   .word -220
   .word 622
   .word 1294
   .word 634
   .word -703
   .word -771
   .word 378
   .word -448
   .word -1177
   .word 675
   .word 178
   .word -209
   .word -484
   .word 1163
   .word 1123
   .word -1052
   .word 1408
   .word 1299
   .word -1137
   .word 163
   .word -1322
   .word -463
   .word -1132
   .word -127
   .word -1307
   .word 1084
   .word 1398
   .word 615
   .word -765
   .word 289
   .word -345
   .word 979
