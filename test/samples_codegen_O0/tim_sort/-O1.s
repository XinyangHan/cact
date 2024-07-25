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
   .word -1153
   .word 968
   .word -443
   .word -277
   .word 740
   .word -266
   .word -818
   .word -607
   .word -1011
   .word -336
   .word 1392
   .word 932
   .word -307
   .word 642
   .word 725
   .word 348
   .word -526
   .word -225
   .word 595
   .word -522
   .word 1006
   .word -389
   .word 373
   .word 367
   .word -1099
   .word -1226
   .word 864
   .word -90
   .word -1366
   .word -832
   .word 656
   .word 0
   .word -1404
   .word -1413
   .word 156
   .word -637
   .word 1169
   .word -1050
   .word -790
   .word 367
   .word 957
   .word 759
   .word -975
   .word 410
   .word 1428
   .word -1071
   .word 152
   .word -233
   .word -529
   .word -203
   .word -824
   .word -162
   .word 381
   .word -968
   .word 1290
   .word 1115
   .word -33
   .word -1049
   .word -442
   .word -1358
   .word -1152
   .word 11
   .word 495
   .word 1143
   .word -178
   .word 1110
   .word -725
   .word -869
   .word -564
   .word 312
   .word 1292
   .word 42
   .word -744
   .word 690
   .word -384
   .word -223
   .word 1304
   .word 1123
   .word -1201
   .word -1042
   .word 1014
   .word -551
   .word -1069
   .word -1060
   .word 721
   .word -452
   .word 130
   .word -808
   .word -488
   .word 1227
   .word 898
   .word -810
   .word 481
   .word -1056
   .word -244
   .word 314
   .word -594
   .word -185
   .word -649
   .word 637
   .word -1166
   .word 521
   .word -367
   .word -1389
   .word -217
   .word 454
   .word -751
   .word -987
   .word 51
   .word -576
   .word -1272
   .word -1024
   .word -907
   .word 1378
   .word 1028
   .word 648
   .word -301
   .word -329
   .word -203
   .word -279
   .word 48
   .word 589
   .word 27
   .word -886
   .word -884
   .word -463
   .word 1179
   .word 1144
   .word -430
   .word -1411
   .word 1286
   .word -208
   .word -909
   .word 228
   .word -410
   .word 1317
   .word -213
   .word 1401
   .word -1036
   .word 979
   .word 828
   .word 901
   .word -1324
   .word -309
   .word -801
   .word 979
   .word -774
   .word 673
   .word 1339
   .word -1370
   .word 809
   .word 876
   .word -779
   .word -383
   .word -361
   .word -1045
   .word 124
   .word -732
   .word -1196
   .word 684
   .word -556
   .word -797
   .word 38
   .word -478
   .word -186
   .word -1110
   .word -15
   .word -22
   .word 1392
   .word -556
   .word -412
   .word -1067
   .word 608
   .word -313
   .word 149
   .word -732
   .word 284
   .word 68
   .word -907
   .word -1048
   .word 268
   .word 815
   .word -358
   .word 155
   .word 385
   .word -358
   .word -1021
   .word -583
   .word 649
   .word 69
   .word 1302
   .word -735
   .word 1110
   .word -161
   .word 124
   .word -940
   .word -37
   .word -1374
   .word 288
   .word 354
   .word 1226
   .word 788
   .word 1004
   .word 570
   .word 82
   .word -864
   .word 1299
   .word 241
   .word -841
   .word -1122
   .word -982
   .word -266
   .word -39
   .word -1023
   .word -588
   .word -368
   .word -142
   .word -977
   .word -1164
   .word -1363
   .word -1071
   .word -77
   .word -1247
   .word -279
   .word -1314
   .word 883
   .word 1199
   .word -268
   .word 157
   .word -1299
   .word 192
   .word 864
   .word -1262
   .word -778
   .word 240
   .word -906
   .word -319
   .word 1030
   .word 611
   .word -1068
   .word 375
   .word -1401
   .word 1101
   .word -77
   .word 505
   .word -699
   .word 933
   .word 217
   .word 1089
   .word 1102
   .word 39
   .word -1087
   .word -798
   .word -166
   .word 559
   .word 1213
   .word 766
   .word -469
   .word 1220
   .word 958
   .word -473
   .word 1265
   .word -680
   .word 1196
   .word 895
   .word -984
   .word -909
   .word 341
   .word 995
   .word -1218
   .word -1290
   .word 341
   .word 1076
   .word 881
   .word 467
   .word 1164
   .word 587
   .word 1025
   .word 749
   .word -78
   .word 160
   .word 1145
   .word 137
   .word 506
   .word 34
   .word -162
   .word 114
   .word -1100
   .word 897
   .word 486
   .word -503
   .word -28
   .word 948
   .word 228
   .word 453
   .word -1010
   .word 800
   .word 1335
   .word -183
   .word 540
   .word 1395
   .word 1044
   .word 1365
   .word 597
   .word -839
   .word -210
   .word 18
   .word 1404
   .word -694
   .word 1412
   .word 1191
   .word 190
   .word -1204
   .word 1224
   .word 681
   .word 304
   .word -640
   .word -787
   .word 1095
   .word -1274
   .word 1267
   .word 1335
   .word -763
   .word -431
   .word -321
   .word 848
   .word -272
   .word 770
   .word -1158
   .word -808
   .word -478
   .word 1179
   .word 1181
   .word -726
   .word 1024
   .word -201
   .word 1217
   .word 567
   .word 418
   .word 626
   .word -1273
   .word 696
   .word -198
   .word -446
   .word 143
   .word -148
   .word -1372
   .word 434
   .word -46
   .word 242
   .word 614
   .word 970
   .word -1040
   .word -885
   .word -851
   .word 272
   .word -1102
   .word -1077
   .word 338
   .word 880
   .word -1353
   .word -1199
   .word -1379
   .word -1205
   .word -294
   .word -638
   .word -1082
   .word 1156
   .word -578
   .word 48
   .word 787
   .word -557
   .word 383
   .word 1159
   .word 505
   .word -230
   .word 773
   .word 718
   .word 691
   .word 849
   .word -296
   .word 865
   .word -987
   .word 503
   .word -206
   .word -936
   .word 139
   .word 675
   .word 785
   .word 7
   .word 181
   .word -359
   .word -1127
   .word 1236
   .word 585
   .word -1189
   .word 452
   .word -709
   .word 805
   .word 451
   .word -92
   .word 1312
   .word -361
   .word -1140
   .word 311
   .word 436
   .word 95
   .word 682
   .word -1364
   .word 1003
   .word 240
   .word 659
   .word -521
   .word 218
   .word 865
   .word -745
   .word -213
   .word -1378
   .word 389
   .word 822
   .word 955
   .word 508
   .word -412
   .word -1365
   .word -775
   .word 35
   .word 1279
   .word 821
   .word -838
   .word -568
   .word -147
   .word 1309
   .word 973
   .word -149
   .word 283
   .word 43
   .word -1121
   .word -1112
   .word -332
   .word -351
   .word 1003
   .word -1151
   .word -407
   .word 653
   .word -756
   .word -191
   .word 1088
   .word 540
   .word -1300
   .word -517
   .word 1153
   .word -1111
   .word 808
   .word -1172
   .word -1028
   .word -937
   .word -760
   .word 615
   .word -423
   .word -1364
   .word 626
   .word -96
   .word 1061
   .word 750
   .word -1331
   .word -1215
   .word -959
   .word 549
   .word 913
   .word -241
   .word 158
   .word 593
   .word 782
   .word -247
   .word 1090
   .word 449
   .word 1386
   .word 767
   .word -1221
   .word 1248
   .word -328
   .word -890
   .word -1299
   .word -1384
   .word -581
   .word -1404
   .word -36
   .word 1396
   .word -130
   .word 734
   .word 1193
   .word -508
   .word -1298
   .word -1200
   .word -1185
   .word -1394
   .word -1062
   .word 1165
   .word 720
   .word -835
   .word -858
   .word -1033
   .word 1070
   .word 1201
   .word -699
   .word 1116
   .word 248
   .word 1244
   .word 1293
   .word 543
   .word -1353
   .word 970
   .word 359
   .word 288
   .word 513
   .word -1259
   .word -307
   .word -1374
   .word -787
   .word 378
   .word 1073
   .word -584
   .word -455
   .word 1348
   .word -131
   .word -436
   .word -134
   .word 1249
   .word 623
   .word -1181
   .word 710
   .word -579
   .word 627
   .word -371
   .word -1095
   .word 863
   .word 902
   .word -1259
   .word -1250
   .word 1049
   .word -419
   .word -1293
   .word 520
   .word -748
   .word 1126
   .word -1198
   .word -593
   .word 468
   .word 1333
   .word -756
   .word 341
   .word 321
   .word -1031
   .word 344
   .word 552
   .word 1366
   .word -797
   .word 1236
   .word 332
   .word -265
   .word -466
   .word 49
   .word -148
   .word -597
   .word -847
   .word 939
   .word 801
   .word 1385
   .word -1156
   .word -221
   .word 157
   .word -592
   .word 1299
   .word 1078
   .word -268
   .word 240
   .word -1105
   .word -664
   .word 175
   .word -341
   .word -272
   .word -1116
   .word -1283
   .word 585
   .word 1054
   .word 342
   .word -472
   .word -404
   .word -12
   .word 4
   .word 1419
   .word -1386
   .word -319
   .word 953
   .word 353
   .word 304
   .word -570
   .word 272
   .word 631
   .word -366
   .word -699
   .word 749
   .word -1393
   .word -1371
   .word 958
   .word -1404
   .word 276
   .word -523
   .word -1334
   .word 631
   .word -375
   .word 760
   .word -1254
   .word -668
   .word 739
   .word -1015
   .word 573
   .word -1106
   .word 451
   .word 782
   .word -282
   .word 1145
   .word 17
   .word 85
   .word 1077
   .word -1089
   .word -332
   .word 486
   .word -1168
   .word -240
   .word -246
   .word 997
   .word -383
   .word -636
   .word -1185
   .word 101
   .word -1366
   .word -1291
   .word 1126
   .word 1133
   .word -958
   .word 417
   .word -1230
   .word 102
   .word -1374
   .word 1377
   .word 311
   .word -1126
   .word -878
   .word -1056
   .word -834
   .word -656
   .word 1009
   .word -1428
   .word -580
   .word -868
   .word 1066
   .word -678
   .word 137
   .word -560
   .word 717
   .word 1079
   .word 123
   .word 1158
   .word -252
   .word -1111
   .word -1139
   .word 1101
   .word -467
   .word -656
   .word -1153
   .word -976
   .word -22
   .word -1115
   .word -823
   .word 1267
   .word -62
   .word -1043
   .word 575
   .word -798
   .word 1375
   .word 104
   .word -516
   .word 908
   .word -1247
   .word -205
   .word 1074
   .word -1159
   .word -1011
   .word 440
   .word 860
   .word -902
   .word -677
   .word 521
   .word 972
   .word 483
   .word -628
   .word -969
   .word -1420
   .word 837
   .word -750
   .word 735
   .word -22
   .word 1304
   .word -70
   .word -747
   .word 731
   .word 888
   .word 242
   .word 1051
   .word 1209
   .word 1395
   .word -386
   .word -1293
   .word 661
   .word 70
   .word -697
   .word 120
   .word 16
   .word 183
   .word 175
   .word 143
   .word 1379
   .word 1024
   .word -665
   .word 262
   .word -414
   .word -264
   .word -1200
   .word 470
   .word 124
   .word 633
   .word -20
   .word 32
   .word -941
   .word 1154
   .word 1086
   .word -1256
   .word -898
   .word 867
   .word 898
   .word -107
   .word 889
   .word -308
   .word 705
   .word -141
   .word -1087
   .word 725
   .word -1260
   .word 402
   .word -760
   .word 83
   .word 1258
   .word 636
   .word 154
   .word 906
   .word -1353
   .word 93
   .word -1099
   .word -719
   .word 1410
   .word -680
   .word 794
   .word 130
   .word 1118
   .word -544
   .word -1330
   .word -52
   .word 638
   .word 60
   .word -1157
   .word -840
   .word -792
   .word -869
   .word -189
   .word -260
   .word 790
   .word -1370
   .word 409
   .word -938
   .word 948
   .word -102
   .word -837
   .word -737
   .word -608
   .word 397
   .word 325
   .word 1393
   .word 895
   .word -469
   .word 867
   .word -550
   .word -875
   .word 325
   .word -1086
   .word 525
   .word -276
   .word -1369
   .word 795
   .word 690
   .word 212
   .word 1399
   .word 224
   .word 1401
   .word -117
   .word 399
   .word -669
   .word 945
   .word -1053
   .word 586
   .word -811
   .word 85
   .word -737
   .word 122
   .word -952
   .word 149
   .word 96
   .word 555
   .word 1060
   .word -783
   .word -1253
   .word -851
   .word 583
   .word -675
   .word -1287
   .word -445
   .word 452
   .word 1150
   .word -324
   .word -1428
   .word -757
   .word 499
   .word 720
   .word -1080
   .word -638
   .word 460
   .word 553
   .word 1117
   .word -1137
   .word -1025
   .word -401
   .word 148
   .word -831
   .word -1183
   .word 1020
   .word -324
   .word -1176
   .word -468
   .word -312
   .word 952
   .word 263
   .word -778
   .word -229
   .word 1371
   .word -1113
   .word 618
   .word 1417
   .word -1141
   .word 1192
   .word -590
   .word -698
   .word 947
   .word 765
   .word -692
   .word 1085
   .word -1234
   .word -1203
   .word 1008
   .word 729
   .word -1089
   .word -1185
   .word -268
   .word -582
   .word 662
   .word -1108
   .word -1189
   .word 1004
   .word -1263
   .word -1103
   .word -490
   .word -56
   .word -23
   .word -1074
   .word 283
   .word -801
   .word 60
   .word 429
   .word -170
   .word -1213
   .word 261
   .word 741
   .word -320
   .word -213
   .word -320
   .word -1391
   .word 841
   .word -299
   .word -1074
   .word 1242
   .word -633
   .word -1140
   .word -835
   .word 1301
   .word 737
   .word 290
   .word 636
   .word 679
   .word 637
   .word 651
   .word -1041
   .word 773
   .word -1242
   .word 1011
   .word 506
   .word -1013
   .word 269
   .word -1210
   .word 1305
   .word 169
   .word 365
   .word 299
   .word 373
   .word -1305
   .word -139
   .word -1338
   .word -1049
   .word 748
   .word -241
   .word 1414
   .word 1167
   .word 198
   .word 820
   .word -164
   .word 689
   .word 468
   .word -353
   .word 469
   .word -1419
   .word -163
   .word 1064
   .word 438
   .word 1410
   .word -569
   .word 603
   .word 762
   .word 1186
   .word -1017
   .word -84
   .word 979
   .word -883
   .word 384
   .word 711
   .word -542
   .word 989
   .word -10
   .word -496
   .word -982
   .word 431
   .word 1089
   .word 707
   .word 1096
   .word 709
   .word 332
   .word 1300
   .word -849
   .word -475
   .word -1316
   .word 1057
   .word 33
   .word 389
   .word -578
   .word -444
   .word -1427
   .word -235
   .word 504
   .word 1094
   .word 115
   .word 723
   .word 257
   .word -807
   .word -145
   .word 254
   .word 463
   .word 175
   .word 843
   .word -971
   .word -42
   .word -293
   .word 1416
   .word 556
   .word 1331
   .word -189
   .word 570
   .word -147
   .word 447
   .word -952
   .word 632
   .word -578
   .word -1037
   .word 647
   .word -210
   .word 810
   .word 352
   .word 683
   .word 1386
   .word 1081
   .word 1185
   .word 709
   .word 481
   .word -1402
   .word 86
   .word -588
   .word 578
   .word -357
   .word -1192
   .word 1391
   .word 767
   .word 852
   .word -186
   .word 230
   .word 705
   .word 1375
   .word 1073
   .word 620
   .word 494
   .word 728
   .word -271
   .word 1049
   .word 235
   .word -664
   .word 486
   .word -652
   .word 24
   .word -1271
   .word 626
   .word 81
   .word -1280
   .word 1107
   .word -576
   .word 800
   .word 1200
   .word 196
   .word -656
   .word -209
   .word -620
   .word 1325
   .word -41
   .word -1327
   .word -191
   .word -375
   .word -410
   .word 834
   .word -1044
   .word -789
   .word -1035
   .word 442
   .word -1381
   .word 560
   .word -1289
   .word 706
   .word 1073
   .word 41
   .word 700
   .word -1120
   .word 956
   .word -200
   .word 1203
   .word -1007
   .word 1015
   .word 323
   .word 287
   .word 283
   .word 145
   .word 465
   .word -1205
   .word -868
   .word -88
   .word -42
   .word 867
   .word -1428
   .word -325
   .word 1025
   .word -897
   .word -1191
   .word -329
   .word -19
   .word -963
   .word 931
   .word -957
   .word -224
   .word 156
   .word -815
   .word 666
   .word -1176
   .word 540
   .word 1326
   .word -933
   .word -478
   .word 340
   .word -149
   .word 1362
   .word 1228
   .word -1089
   .word 745
   .word -207
   .word 1381
   .word 1410
   .word -458
   .word 1051
   .word 1131
   .word 315
   .word -353
   .word -27
   .word 767
   .word -1238
   .word -1020
   .word -476
   .word 503
   .word 1033
   .word 1235
   .word 1056
   .word -106
   .word -1032
   .word 997
   .word 290
   .word -306
   .word -224
   .word 277
   .word 678
   .word -254
   .word -444
   .word 861
   .word 389
   .word 407
   .word -1014
   .word 862
   .word 357
   .word 959
   .word 75
   .word 1283
   .word -2
   .word -19
   .word 1093
   .word 1425
   .word -1229
   .word 376
   .word -92
   .word -1114
   .word -956
   .word -461
   .word -27
   .word -522
   .word -178
   .word 101
   .word -246
   .word -987
   .word -1376
   .word 124
   .word -536
   .word -272
   .word -918
   .word -861
   .word -720
   .word -1326
   .word 941
   .word -1309
   .word -247
   .word -899
   .word -257
   .word 505
   .word 273
   .word 737
   .word -612
   .word -1089
   .word -1228
   .word -562
   .word -1071
   .word 507
   .word 315
   .word -1266
   .word 411
   .word 1397
   .word 57
   .word -334
   .word 566
   .word 1094
   .word 1263
   .word 499
   .word 531
   .word -886
   .word 1309
   .word 542
   .word -47
   .word -931
   .word -731
   .word 1147
   .word -245
   .word -1006
   .word 723
   .word 421
   .word 592
   .word 458
   .word 721
   .word -266
   .word -583
   .word -146
   .word 346
   .word 759
   .word -767
   .word -1216
   .word -355
   .word -1418
   .word -561
   .word -1073
   .word -965
   .word 566
   .word 1292
   .word -876
   .word 842
   .word 202
   .word 20
   .word -979
   .word 300
   .word -274
   .word -981
   .word 525
   .word -977
   .word -93
   .word 1381
   .word -251
   .word 85
   .word 530
   .word -81
   .word -1046
   .word 764
   .word 1334
   .word -998
   .word -902
   .word -1013
   .word -63
   .word -1215
   .word 1403
   .word 1008
   .word 229
   .word 1061
   .word -1211
   .word 481
   .word -134
   .word 1044
   .word -721
   .word 1396
   .word -715
   .word 514
   .word 109
   .word -558
   .word -139
   .word -1367
   .word -1072
   .word 211
   .word -1417
   .word 144
   .word 687
   .word 418
   .word -1066
   .word 1202
   .word 752
   .word -1268
   .word -635
   .word 939
   .word 622
   .word 982
   .word 265
   .word -1083
   .word -403
   .word -402
   .word -622
   .word 1160
   .word -44
   .word 723
   .word -692
   .word -497
   .word -558
   .word -707
   .word -656
   .word 434
   .word 307
   .word -820
   .word -305
   .word 689
   .word -656
   .word -571
   .word 716
   .word 888
   .word 92
   .word -1355
   .word 947
   .word 1034
   .word 1082
   .word -963
   .word 327
   .word -1332
   .word -835
   .word -871
   .word -519
   .word 291
   .word 77
   .word -385
   .word -375
   .word -870
   .word -490
   .word -168
   .word 667
   .word -939
   .word 528
   .word 1377
   .word -261
   .word 831
   .word 238
   .word 943
   .word -1043
   .word 221
   .word -1348
   .word 731
   .word 8
   .word 1178
   .word 1406
   .word -873
   .word -942
   .word -458
   .word -1232
   .word -815
   .word -1002
   .word 724
   .word 47
   .word 187
   .word -360
   .word -830
   .word -1041
   .word 1273
   .word -1167
   .word -662
   .word 1412
   .word 577
   .word -761
   .word 393
   .word 291
   .word 47
   .word 643
   .word 143
   .word 1162
   .word -1399
   .word -2
   .word 1001
   .word -894
   .word 19
   .word 178
   .word 1368
   .word 275
   .word 471
   .word 1173
   .word -215
   .word -1038
   .word -73
   .word 595
   .word -928
   .word -1092
   .word -847
   .word -468
   .word -200
   .word -463
   .word 267
   .word 1346
   .word 1176
   .word 1425
   .word 1330
   .word 558
   .word 1302
   .word -579
   .word -1242
   .word -803
   .word 1301
   .word -1378
   .word -147
   .word 1215
   .word -1043
   .word 282
   .word 1412
   .word -616
   .word 1129
   .word 954
   .word 412
   .word -208
   .word -826
   .word -1061
   .word 640
   .word -1345
   .word 988
   .word -106
   .word -824
   .word 472
   .word -295
   .word -726
   .word -294
   .word 1295
   .word -103
   .word -1046
   .word 449
   .word 390
   .word 102
   .word 282
   .word 1137
   .word -969
   .word -483
   .word -1242
   .word -30
   .word 1127
   .word -649
   .word 457
   .word -181
   .word 230
   .word -1314
   .word -441
   .word -511
   .word -1328
   .word -515
   .word -1293
   .word 320
   .word 636
   .word 220
   .word -49
   .word 387
   .word 152
   .word -1324
   .word 706
   .word 166
   .word -484
   .word -502
   .word 1420
   .word 771
   .word 1216
   .word 743
   .word -126
   .word -1126
   .word 1045
   .word -98
   .word 610
   .word 846
   .word 363
   .word -1318
   .word -183
   .word 1009
   .word -632
   .word 1270
   .word -485
   .word -826
   .word -1379
   .word -180
   .word 256
   .word -735
   .word 821
   .word 401
   .word -287
   .word -602
   .word -972
   .word -421
   .word -708
   .word -575
   .word 1184
   .word -1103
   .word 1290
   .word -606
   .word 949
   .word -255
   .word 99
   .word 1426
   .word -7
   .word 813
   .word 415
   .word 1240
   .word 730
   .word -192
   .word -302
   .word 1020
   .word 52
   .word -364
   .word 1301
   .word 65
   .word 1423
   .word 168
   .word 765
   .word 1409
   .word -551
   .word -608
   .word 167
   .word 936
   .word -1278
   .word 601
   .word 1184
   .word -56
   .word 801
   .word -1379
   .word -532
   .word 2
   .word -1179
   .word -861
   .word 1092
   .word 797
   .word -553
   .word -323
   .word 903
   .word 434
   .word -1166
   .word -1188
   .word -558
   .word -1076
   .word 829
   .word -741
   .word 373
   .word -753
   .word 1039
   .word -717
   .word -306
   .word 963
   .word 445
   .word -1007
   .word 631
   .word -1415
   .word 1115
   .word -1096
   .word -780
   .word -1216
   .word -623
   .word -85
   .word -535
   .word 818
   .word -1152
   .word 1257
   .word 107
   .word 837
   .word 933
   .word -420
   .word 204
   .word 147
   .word -803
   .word 240
   .word 406
   .word 1040
   .word 9
   .word 1285
   .word -757
   .word 162
   .word -1006
   .word -157
   .word -1302
   .word 161
   .word 1206
   .word -77
   .word 366
   .word 167
   .word 295
   .word -756
   .word 27
   .word -535
   .word -810
   .word -258
   .word -1134
   .word 1284
   .word -461
   .word 852
   .word -1165
   .word 1359
   .word 918
   .word -937
   .word -28
   .word -1348
   .word -917
   .word 261
   .word -1316
   .word 1359
   .word 1077
   .word 250
   .word 1241
   .word -1374
   .word -547
   .word -935
   .word -38
   .word -329
   .word -584
   .word 125
   .word 1083
   .word -435
   .word 880
   .word 1427
   .word 1106
   .word -1254
   .word -518
   .word -299
   .word 1294
   .word -1325
   .word 966
   .word -373
   .word -1024
   .word -167
   .word 918
   .word -312
   .word 149
   .word -798
   .word 239
   .word -203
   .word -753
   .word 242
   .word 688
   .word 947
   .word 1370
   .word 289
   .word -932
   .word 505
   .word 1427
   .word 157
   .word 1418
   .word -89
   .word -204
   .word 790
   .word 1129
   .word 837
   .word 793
   .word 147
   .word 1361
   .word -571
   .word 72
   .word -221
   .word -248
   .word -552
   .word 1071
   .word -766
   .word -1338
   .word -324
   .word -221
   .word 876
   .word -989
   .word -296
   .word -59
   .word 1270
   .word 731
   .word -1404
   .word -8
   .word 87
   .word -861
   .word 320
   .word 971
   .word -87
   .word -1035
   .word 112
   .word 176
   .word -864
   .word -187
   .word 794
   .word 1381
   .word -1255
   .word -1083
   .word 537
   .word -669
   .word -538
   .word -840
   .word 964
   .word -1045
   .word -841
   .word -581
   .word -994
   .word -1344
   .word 857
   .word -1130
   .word -70
   .word -1262
   .word -173
   .word 982
   .word 728
   .word 416
   .word 522
   .word 253
   .word 1092
   .word 47
   .word 1402
   .word 459
   .word -887
   .word 1200
   .word 1352
   .word -609
   .word 611
   .word 514
   .word 106
   .word -227
   .word 766
   .word -935
   .word -389
   .word 280
   .word 281
   .word -656
   .word 869
   .word 1069
   .word -1110
   .word -1377
   .word 534
   .word -304
   .word 1277
   .word -1275
   .word -866
   .word 1189
   .word 106
   .word -540
   .word 861
   .word -571
   .word -574
   .word 775
   .word 1427
   .word -779
   .word 1289
   .word -426
   .word -1421
   .word 1206
   .word -1262
   .word 1075
   .word 32
   .word -580
   .word 262
   .word 175
   .word 249
   .word -243
   .word 786
   .word -1035
   .word -92
   .word 897
   .word -646
   .word 199
   .word 992
   .word 649
   .word -1303
   .word -926
   .word -228
   .word 642
   .word 424
   .word -1104
   .word -630
   .word 1048
   .word -920
   .word 540
   .word 901
   .word -184
   .word 599
   .word -1029
   .word 138
   .word -1110
   .word -473
   .word 932
   .word 1328
   .word -1349
   .word 1190
   .word 1250
   .word 1315
   .word -1399
   .word 1379
   .word 727
   .word 645
   .word -1193
   .word 330
   .word 847
   .word 501
   .word -614
   .word -907
   .word 613
   .word -56
   .word -1179
   .word 483
   .word -172
   .word 309
   .word 1234
   .word -511
   .word 1290
   .word 3
   .word -1291
   .word 774
   .word 1084
   .word 480
   .word 183
   .word 1198
   .word 929
   .word 1154
   .word -1110
   .word 941
   .word -936
   .word -1060
   .word 586
   .word 48
   .word -1407
   .word 972
   .word 1235
   .word -904
   .word 432
   .word 1008
   .word 271
   .word 592
   .word -1356
   .word -979
   .word -200
   .word 1113
   .word 348
   .word -377
   .word 390
   .word -571
   .word 515
   .word -1228
   .word -856
   .word 1062
   .word 689
   .word 417
   .word 1150
   .word 1269
   .word 1088
   .word 375
   .word 91
   .word -539
   .word 1269
   .word -402
   .word 86
   .word 683
   .word 401
   .word 587
   .word -643
   .word 1402
   .word 931
   .word -45
   .word 142
   .word 263
   .word -95
   .word 1031
   .word -835
   .word 78
   .word -407
   .word -1384
   .word 318
   .word -346
   .word 1214
   .word 1179
   .word -190
   .word -610
   .word -744
   .word 72
   .word -414
   .word -452
   .word 60
   .word 1423
   .word 134
   .word 99
   .word 870
   .word 539
   .word -1293
   .word 969
   .word -582
   .word 275
   .word -357
   .word 1080
   .word -68
   .word -579
   .word -481
   .word -1053
   .word -651
   .word -697
   .word -891
   .word -132
   .word 1245
   .word -443
   .word -1161
   .word -1314
   .word 955
   .word 1204
   .word 298
   .word -1058
   .word -1326
   .word 148
   .word -846
   .word -1367
   .word 948
   .word 1034
   .word -1268
   .word -1259
   .word 852
   .word -929
   .word -291
   .word -1076
   .word 1196
   .word 1343
   .word 491
   .word -1354
   .word -600
   .word 1044
   .word -1023
   .word -1002
   .word 569
   .word -141
   .word 357
   .word 524
   .word 67
   .word 390
   .word -704
   .word 1199
   .word 717
   .word -516
   .word -13
   .word -463
   .word -1323
   .word 1203
   .word -964
   .word -1260
   .word -146
   .word 232
   .word -666
   .word -528
   .word -1395
   .word -947
   .word 1144
   .word -149
   .word 164
   .word -733
   .word 362
   .word 956
   .word 942
   .word -884
   .word -1181
   .word -1145
   .word 401
   .word 1357
   .word 798
   .word 94
   .word -371
   .word -75
   .word -382
   .word 674
   .word 906
   .word 856
   .word 1120
   .word 959
   .word 1368
   .word -586
   .word -970
   .word -590
   .word 884
   .word -419
   .word 680
   .word -219
   .word 1362
   .word 106
   .word 140
   .word -1300
   .word 868
   .word -582
   .word -797
   .word -484
   .word 264
   .word -959
   .word 883
   .word -345
   .word 743
   .word 956
   .word -514
   .word 605
   .word 1363
   .word -1118
   .word 1278
   .word 1323
   .word 59
   .word -146
   .word -510
   .word -1239
   .word 1240
   .word -391
   .word -157
   .word 933
   .word -158
   .word -706
   .word 410
   .word 693
   .word 712
   .word 1351
   .word -947
   .word 949
   .word -1084
   .word 551
   .word -1135
   .word -762
   .word 1148
   .word -802
   .word 71
   .word -1253
   .word 560
   .word -1018
   .word -606
   .word 190
   .word -353
   .word -421
   .word 975
   .word 39
   .word -549
   .word -192
   .word -901
   .word -942
   .word 1016
   .word -400
   .word 349
   .word -1225
   .word 989
   .word 491
   .word -924
   .word -305
   .word 1002
   .word 271
   .word 864
   .word -360
   .word 171
   .word -62
   .word -845
   .word 1253
   .word 935
   .word 488
   .word -379
   .word -44
   .word -737
   .word -639
   .word -85
   .word -172
   .word -374
   .word -11
   .word -18
   .word 922
   .word -938
   .word -275
   .word -900
   .word 1262
   .word -897
   .word -938
   .word -1217
   .word -1324
   .word 93
   .word 1153
   .word 1166
   .word -1383
   .word -18
   .word -1225
   .word -292
   .word -376
   .word -1310
   .word 300
   .word -12
   .word 1008
   .word 681
   .word -1148
   .word -261
   .word 857
   .word 358
   .word -167
   .word -199
   .word 1172
   .word -988
   .word -1290
   .word -402
   .word -178
   .word 267
   .word 1093
   .word -1324
   .word 1230
   .word 514
   .word 436
   .word -1338
   .word -1152
   .word 59
   .word -75
   .word -919
   .word -1178
   .word 1128
   .word -1190
   .word 264
   .word 276
   .word 1061
   .word 448
   .word -1229
   .word 229
   .word -1196
   .word -383
   .word 924
   .word -338
   .word 387
   .word 337
   .word 602
   .word -783
   .word 487
   .word 822
   .word -1398
   .word -1163
   .word -1425
   .word -696
   .word -224
   .word 1152
   .word -77
   .word 798
   .word 358
   .word 355
   .word 886
   .word 952
   .word 907
   .word -829
   .word -822
   .word 434
   .word -1265
   .word 1190
   .word 1422
   .word -470
   .word -461
   .word -915
   .word -1091
   .word 339
   .word 1106
   .word -156
   .word -777
   .word 1082
   .word 1282
   .word 506
   .word -1191
   .word -759
   .word 107
   .word 480
   .word 1324
   .word 537
   .word 506
   .word 455
   .word -3
   .word -708
   .word -918
   .word -339
   .word -515
   .word -60
   .word 1018
   .word -1320
   .word 542
   .word 27
   .word 301
   .word -444
   .word -505
   .word 1237
   .word -171
   .word 475
   .word -1265
   .word -289
   .word -306
   .word -366
   .word 1349
   .word 947
   .word 1312
   .word 132
   .word 1286
   .word 322
   .word 221
   .word 1367
   .word -1198
   .word -166
   .word -817
   .word -340
   .word 550
   .word -1354
   .word -354
   .word 1327
   .word 905
   .word 893
   .word 1293
   .word 1109
   .word -1374
   .word -1136
   .word 646
   .word -386
   .word -1017
   .word -374
   .word 49
   .word -871
   .word -614
   .word -540
   .word 1025
   .word 838
   .word -395
   .word 1222
   .word 493
   .word -460
   .word -920
   .word -746
   .word 1024
   .word 1304
   .word -1345
   .word -78
   .word -1172
   .word 308
   .word 117
   .word -270
   .word -144
   .word 707
   .word -960
   .word 245
   .word -389
   .word -113
   .word -826
   .word 564
   .word -582
   .word 408
   .word -869
   .word -492
   .word 1387
   .word 496
   .word 298
   .word -160
   .word -1149
   .word -534
   .word 1409
   .word 858
   .word 143
   .word -335
   .word -580
   .word -28
   .word -291
   .word -807
   .word -1332
   .word -1186
   .word 502
   .word -983
   .word -274
   .word -1366
   .word -1417
   .word 935
   .word 928
   .word -1215
   .word -354
   .word -1346
   .word -1346
   .word -825
   .word 984
   .word 950
   .word 1031
   .word -103
   .word 612
   .word -515
   .word -1160
   .word -165
   .word 1391
   .word 1179
   .word 514
   .word -114
   .word -1278
   .word 1294
   .word -1386
   .word 547
   .word 1072
   .word 1005
   .word -1110
   .word 1065
   .word -1357
   .word -967
   .word 450
   .word 578
   .word 716
   .word -539
   .word 1322
   .word 149
   .word 589
   .word -1168
   .word 68
   .word 1016
   .word -399
   .word -88
   .word 811
   .word -539
   .word 1378
   .word -326
   .word 313
   .word 165
   .word 695
   .word 1221
   .word -93
   .word -627
   .word 1055
   .word 290
   .word -264
   .word 429
   .word 422
   .word 664
   .word -1210
   .word -692
   .word 1008
   .word -287
   .word 769
   .word 805
   .word -426
   .word -623
   .word -636
   .word -1270
   .word -842
   .word -830
   .word -961
   .word 807
   .word -957
   .word -143
   .word 1376
   .word 1281
   .word -390
   .word -133
   .word -169
   .word -417
   .word 646
   .word 858
   .word -1286
   .word 1338
   .word 673
   .word 1163
   .word -46
   .word -348
   .word -823
   .word -853
   .word -31
   .word 366
   .word 1248
   .word -711
   .word -268
   .word -346
   .word -956
   .word -1028
   .word 1085
   .word 991
   .word 1342
   .word -531
   .word -348
   .word 262
   .word 463
   .word -167
   .word -189
   .word -601
   .word 259
   .word 344
   .word 1055
   .word 1225
   .word 1194
   .word 1287
   .word 1388
   .word 886
   .word 75
   .word 616
   .word 850
   .word -710
   .word -918
   .word 285
   .word -299
   .word -971
   .word -606
   .word 812
   .word -833
   .word 1020
   .word -987
   .word 96
   .word 174
   .word 744
   .word -513
   .word -372
   .word -1353
   .word -880
   .word -226
   .word 100
   .word 45
   .word -122
   .word 806
   .word -613
   .word -984
   .word -574
   .word -140
   .word -1258
   .word -273
   .word 1094
   .word 92
   .word -1314
   .word -1008
   .word 581
   .word -854
   .word 863
   .word -1038
   .word 1335
   .word -472
   .word -1015
   .word 128
   .word -703
   .word 755
   .word -546
   .word -564
   .word -967
   .word 1148
   .word 524
   .word -812
   .word -392
   .word 945
   .word 936
   .word -814
   .word -108
   .word -823
   .word -1418
   .word 81
   .word -573
   .word 1399
   .word -481
   .word 184
   .word 51
   .word -834
   .word 506
   .word 1384
   .word 107
   .word -756
   .word 649
   .word 617
   .word 480
   .word -1300
   .word 323
   .word 373
   .word 573
   .word 464
   .word -230
   .word -1356
   .word 516
   .word 917
   .word -284
   .word -26
   .word -471
   .word 441
   .word 1350
   .word 1000
   .word -473
   .word -109
   .word -555
   .word -572
   .word -331
   .word -818
   .word -1230
   .word -1302
   .word -18
   .word 921
   .word 1414
   .word 141
   .word 497
   .word 448
   .word 255
   .word 737
   .word 1203
   .word 238
   .word 949
   .word 468
   .word -520
   .word -405
   .word -1104
   .word 334
   .word 881
   .word 1
   .word 171
   .word -227
   .word -600
   .word -1000
   .word -936
   .word 202
   .word -69
   .word -399
   .word 760
   .word 860
   .word -542
   .word -1030
   .word -53
   .word 969
   .word 746
   .word 1037
   .word -254
   .word 1177
   .word 491
   .word -1370
   .word -1424
   .word 297
   .word -622
   .word 1255
   .word 664
   .word -971
   .word -274
   .word 371
   .word -943
   .word -624
   .word -1175
   .word 149
   .word -1390
   .word -469
   .word 1070
   .word -794
   .word -919
   .word -349
   .word -692
   .word 265
   .word -1349
   .word -154
   .word 596
   .word -169
   .word 457
   .word 1068
   .word 982
   .word -1116
   .word -1359
   .word -927
   .word 30
   .word 246
   .word -117
   .word -817
   .word -1037
   .word 634
   .word -1409
   .word -190
   .word 721
   .word 540
   .word -1228
   .word -379
   .word -1006
   .word 609
   .word 613
   .word 287
   .word -1364
   .word -970
   .word 1422
   .word 199
   .word -1416
   .word 1320
   .word -1085
   .word 112
   .word -648
   .word -1071
   .word 1005
   .word -848
   .word -1108
   .word 289
   .word -1058
   .word 130
   .word 72
   .word 1340
   .word 270
   .word 153
   .word 92
   .word 683
   .word 137
   .word 679
   .word 982
   .word -356
   .word 1117
   .word 893
   .word -1208
   .word -563
   .word 269
   .word 841
   .word 898
   .word -87
   .word -821
   .word -894
   .word 931
   .word 405
   .word 1091
   .word -1052
   .word 106
   .word 623
   .word 542
   .word -5
   .word 1293
   .word 711
   .word 68
   .word -612
   .word -983
   .word 602
   .word 291
   .word -721
   .word 1136
   .word 1220
   .word 123
   .word 1326
   .word -1269
   .word -957
   .word 1156
   .word 221
   .word 1218
   .word -523
   .word -493
   .word 337
   .word -652
   .word 613
   .word 70
   .word -1136
   .word 142
   .word 1253
   .word 1284
   .word 1379
   .word -921
   .word -633
   .word 172
   .word 916
   .word -117
   .word -447
   .word 829
   .word 774
   .word -1087
   .word -1107
   .word 445
   .word -551
   .word -448
   .word -1337
   .word -235
   .word 1104
   .word 1253
   .word 732
   .word 1132
   .word 17
   .word -1326
   .word -116
   .word 1016
   .word 267
   .word 900
   .word -240
   .word 956
   .word -402
   .word 514
   .word -153
   .word -866
   .word 513
   .word -1252
   .word 131
   .word -729
   .word -448
   .word 162
   .word -351
   .word -940
   .word -905
   .word 1034
   .word 758
   .word 1108
   .word -809
   .word 577
   .word 185
   .word -1226
   .word 1163
   .word 229
   .word 1390
   .word 206
   .word 284
   .word 848
   .word 823
   .word -593
   .word -361
   .word 450
   .word 127
   .word -804
   .word 236
   .word -871
   .word 94
   .word -971
   .word -90
   .word -1112
   .word -994
   .word 103
   .word 685
   .word -1017
   .word 1275
   .word 1120
   .word -1304
   .word 1006
   .word 527
   .word -541
   .word -1051
   .word -443
   .word 191
   .word 856
   .word 203
   .word -667
   .word -45
   .word 112
   .word 1294
   .word -1229
   .word 581
   .word -549
   .word -1120
   .word 1061
   .word 82
   .word -793
   .word 1116
   .word 1206
   .word 1032
   .word 1316
   .word 449
   .word 257
   .word 476
   .word 878
   .word 975
   .word 1189
   .word -235
   .word 412
   .word 1218
   .word 952
   .word 760
   .word 1424
   .word -702
   .word -1380
   .word 233
   .word -1056
   .word -395
   .word -554
   .word -504
   .word 1389
   .word -801
   .word -1200
   .word 16
   .word 1055
   .word 945
   .word 452
   .word 28
   .word 1086
   .word -119
   .word -629
   .word -1277
   .word 2
   .word -933
   .word -1406
   .word 739
   .word -760
   .word 1400
   .word -528
   .word 430
   .word -305
   .word 449
   .word -1399
   .word -94
   .word -6
   .word -1098
   .word 501
   .word 682
   .word -861
   .word -916
   .word -1154
   .word 22
   .word -1120
   .word 1020
   .word -512
   .word -1008
   .word -935
   .word -1275
   .word -697
   .word -2
   .word -767
   .word 1097
   .word 1396
   .word 905
   .word -616
   .word -503
   .word 227
   .word 119
   .word -1080
   .word -416
   .word -863
   .word -227
   .word -331
   .word 252
   .word 1063
   .word -1138
   .word 271
   .word -345
   .word 78
   .word -461
   .word -75
   .word -1298
   .word -396
   .word 1420
   .word -1321
   .word -367
   .word -1416
   .word -545
   .word 1043
   .word 1365
   .word -919
   .word -531
   .word 1014
   .word 158
   .word 211
   .word -255
   .word -983
   .word -130
   .word -931
   .word 511
   .word -141
   .word 1245
   .word -673
   .word 346
   .word -934
   .word 154
   .word -1183
   .word 1204
   .word -1000
   .word -794
   .word 138
   .word -1384
   .word -1160
   .word -478
   .word 479
   .word 1079
   .word -812
   .word -630
   .word 1117
   .word 501
   .word -561
   .word -699
   .word 1088
   .word -211
   .word 731
   .word -108
   .word -140
   .word 262
   .word -260
   .word 969
   .word 581
   .word 991
   .word -54
   .word -956
   .word -1148
   .word -217
   .word 320
   .word -309
   .word 1138
   .word -645
   .word -737
   .word 852
   .word -400
   .word -1012
   .word 791
   .word 1051
   .word 1178
   .word -1044
   .word 770
   .word -673
   .word -533
   .word -390
   .word 60
   .word -1309
   .word 1016
   .word 40
   .word 365
   .word 1358
   .word 283
   .word 163
   .word -1295
   .word -394
   .word 253
   .word -1064
   .word 1245
   .word -1418
   .word 219
   .word -1408
   .word -252
   .word -1088
   .word 283
   .word -521
   .word -605
   .word 616
   .word -287
   .word 898
   .word -1161
   .word -1417
   .word -954
   .word -1313
   .word -1202
   .word -376
   .word 1127
   .word 1193
   .word -256
   .word -269
   .word -500
   .word -1336
   .word -806
   .word 444
   .word 1056
   .word 973
   .word 205
   .word -1220
   .word 143
   .word -779
   .word -697
   .word -694
   .word 54
   .word 255
   .word 998
   .word 1186
   .word -1371
   .word -991
   .word 655
   .word 182
   .word -1073
   .word -857
   .word 208
   .word -477
   .word 576
   .word -1049
   .word 868
   .word 544
   .word -556
   .word -32
   .word 103
   .word -853
   .word 348
   .word 1220
   .word -75
   .word -845
   .word -1424
   .word -203
   .word -1159
   .word 1041
   .word 104
   .word 407
   .word -977
   .word 262
   .word 1248
   .word 826
   .word 1297
   .word 1265
   .word 554
   .word -654
   .word 426
   .word 582
   .word 845
   .word 289
   .word 256
   .word 664
   .word 854
   .word 900
   .word 1274
   .word 376
   .word -632
   .word -448
   .word -299
   .word -354
   .word -363
   .word 255
   .word -44
   .word -1294
   .word -451
   .word 528
   .word -1017
   .word 623
   .word -891
   .word 688
   .word 1418
   .word -107
   .word -1083
   .word 1137
   .word -904
   .word -626
   .word 1334
   .word -646
   .word -1189
   .word 1037
   .word 1220
   .word 269
   .word -396
   .word -1369
   .word 209
   .word -896
   .word 918
   .word 793
   .word -568
   .word -713
   .word 660
   .word -818
   .word -108
   .word -713
   .word -524
   .word -65
   .word 240
   .word 746
   .word -693
   .word 684
   .word 1261
   .word -895
   .word -78
   .word 1131
   .word 253
   .word -252
   .word -1358
   .word -382
   .word 111
   .word 577
   .word 1096
   .word -1159
   .word 368
   .word -701
   .word -1082
   .word 1355
   .word 361
   .word -725
   .word 553
   .word -1248
   .word -1056
   .word -221
   .word -298
   .word 1218
   .word 538
   .word 1108
   .word 1090
   .word 233
   .word 720
   .word 295
   .word -622
   .word 992
   .word 983
   .word 438
   .word -284
   .word 1298
   .word -380
   .word 480
   .word -1091
   .word -122
   .word 542
   .word -1274
   .word 1233
   .word 841
   .word 302
   .word 240
   .word -955
   .word -689
   .word 980
   .word 143
   .word -1010
   .word -910
   .word -909
   .word -580
   .word -860
   .word -285
   .word 25
   .word 710
   .word -685
   .word -56
   .word -596
   .word -1328
   .word 41
   .word 547
   .word 1069
   .word 605
   .word -590
   .word -704
   .word -1379
   .word 82
   .word -473
   .word -407
   .word 428
   .word -1334
   .word -1
   .word -802
   .word -1040
   .word 94
   .word 450
   .word -679
   .word 1242
   .word 872
   .word 698
   .word 48
   .word -606
   .word -126
   .word -1068
   .word -686
   .word 1136
   .word 565
   .word -245
   .word 659
   .word -201
   .word 733
   .word 484
   .word -326
   .word 934
   .word 397
   .word -1144
   .word -867
   .word 541
   .word -194
   .word -509
   .word 1323
   .word 200
   .word 158
   .word 1074
   .word 764
   .word -55
   .word 693
   .word 916
   .word 443
   .word 419
   .word 1419
   .word -1377
   .word -469
   .word -696
   .word 240
   .word 1225
   .word 341
   .word 1286
   .word 1170
   .word 883
   .word -385
   .word 1127
   .word 688
   .word -1352
   .word 445
   .word 229
   .word 1250
   .word 61
   .word -95
   .word -914
   .word 868
   .word -508
   .word -867
   .word 587
   .word 521
   .word -1059
   .word 729
   .word 280
   .word -679
   .word -17
   .word 347
   .word 423
   .word -1374
   .word -307
   .word 188
   .word 774
   .word -1398
   .word -1130
   .word -1348
   .word 779
   .word 1381
   .word 429
   .word 181
   .word 947
   .word 1270
   .word -205
   .word -715
   .word 1408
   .word -767
   .word -951
   .word 176
   .word 203
   .word 407
   .word 145
   .word 249
   .word -621
   .word 171
   .word 652
   .word -520
   .word -230
   .word -1140
   .word -941
   .word -799
   .word 840
   .word -117
   .word 382
   .word 272
   .word -147
   .word -983
   .word -1400
   .word 632
   .word -213
   .word 770
   .word 72
   .word 537
   .word -993
   .word 1362
   .word 436
   .word 406
   .word 1278
   .word 58
   .word -710
   .word -908
   .word -614
   .word 917
   .word -323
   .word 654
   .word -486
   .word -1358
   .word 425
   .word 321
   .word 134
   .word 213
   .word 1168
   .word 864
   .word -191
   .word 794
   .word -1094
   .word 137
   .word 781
   .word 773
   .word -238
   .word 1105
   .word -931
   .word 688
   .word -1336
   .word -433
   .word -445
   .word 1423
   .word 404
   .word -1106
   .word -690
   .word -269
   .word 128
   .word -894
   .word 169
   .word 333
   .word -352
   .word -125
   .word -62
   .word -650
   .word 356
   .word 520
   .word 810
   .word 907
   .word -1136
   .word 1013
   .word -959
   .word -1188
   .word -466
   .word -1066
   .word 453
   .word 1059
   .word -301
   .word -396
   .word 554
   .word 776
   .word 102
   .word -809
   .word -1211
   .word 343
   .word 509
   .word 328
   .word -1345
   .word 581
   .word -1312
   .word 476
   .word -739
   .word 554
   .word 256
   .word 1412
   .word -892
   .word -1151
   .word 1269
   .word -354
   .word -1095
   .word 401
   .word 104
   .word 646
   .word -146
   .word -1043
   .word 132
   .word -783
   .word -776
   .word -425
   .word -1331
   .word -1216
   .word 1350
   .word -804
   .word -520
   .word -1001
   .word 962
   .word -972
   .word -863
   .word -742
   .word 1004
   .word -1248
   .word 1283
   .word -1277
   .word -429
   .word -603
   .word 905
   .word 1213
   .word -614
   .word 921
   .word 0
   .word -210
   .word 385
   .word 258
   .word -393
   .word -1422
   .word -1230
   .word 541
   .word -70
   .word 265
   .word 51
   .word -160
   .word -1208
   .word 880
   .word 197
   .word -92
   .word 929
   .word -352
   .word -534
   .word -151
   .word 540
   .word 195
   .word -747
   .word 1338
   .word 1341
   .word 1201
   .word 595
   .word 962
   .word -5
   .word -223
   .word -831
   .word -1221
   .word -362
   .word -1238
   .word -324
   .word 180
   .word -363
   .word -981
   .word 794
   .word -929
   .word -915
   .word -530
   .word 55
   .word -1153
   .word 573
   .word 258
   .word -219
   .word -1418
   .word 477
   .word 631
   .word -1238
   .word -1105
   .word -404
   .word -991
   .word -1024
   .word -1151
   .word -994
   .word 318
   .word 1055
   .word 1421
   .word 11
   .word -429
   .word -323
   .word -1309
   .word 661
   .word 1188
   .word -712
   .word -349
   .word -1373
   .word -665
   .word -428
   .word 200
   .word 846
   .word 1293
   .word 585
   .word -492
   .word -467
   .word -486
   .word 346
   .word -177
   .word 775
   .word 863
   .word -702
   .word -414
   .word -413
   .word -245
   .word -807
   .word 678
   .word -652
   .word 425
   .word 1057
   .word 469
   .word -1056
   .word 853
   .word 860
   .word -814
   .word 132
   .word -1177
   .word -7
   .word 877
   .word 1065
   .word -304
   .word 223
   .word 905
   .word 322
   .word -751
   .word 481
   .word 1030
   .word 951
   .word -819
   .word -906
   .word -1386
   .word -691
   .word -1277
   .word -399
   .word -22
   .word -276
   .word 453
   .word -126
   .word 439
   .word -954
   .word -120
   .word 437
   .word 457
   .word 105
   .word 1050
   .word 827
   .word 132
   .word -432
   .word 1058
   .word 841
   .word 634
   .word 132
   .word -219
   .word -1282
   .word -143
   .word 773
   .word 1090
   .word 1413
   .word 905
   .word 1001
   .word 322
   .word -192
   .word 514
   .word -812
   .word 669
   .word 780
   .word -1375
   .word -327
   .word -811
   .word -1175
   .word 325
   .word 829
   .word 903
   .word 706
   .word -499
   .word 246
   .word -437
   .word -1071
   .word 593
   .word -1422
   .word 1404
   .word -366
   .word 1104
   .word 787
   .word 758
   .word -1119
   .word -116
   .word -297
   .word 1304
   .word 940
   .word -784
   .word -718
   .word 652
   .word 603
   .word 245
   .word -267
   .word 684
   .word 1169
   .word 1110
   .word 712
   .word 1219
   .word -992
   .word 911
   .word 65
   .word -612
   .word -1261
   .word -539
   .word 927
   .word 601
   .word 398
   .word 1092
   .word 332
   .word 829
   .word -1413
   .word -268
   .word -652
   .word -960
   .word 386
   .word 424
   .word 473
   .word 888
   .word -799
   .word 75
   .word -814
   .word 1132
   .word -500
   .word 1047
   .word 881
   .word 846
   .word 724
   .word -725
   .word 988
   .word 1038
   .word -713
   .word 1153
   .word 704
   .word -174
   .word -510
   .word -909
   .word -642
   .word 1233
   .word 46
   .word 523
   .word 1322
   .word 489
   .word 714
   .word -629
   .word -45
   .word 507
   .word 942
   .word 310
   .word 1398
   .word -357
   .word 993
   .word 356
   .word 247
   .word 1132
   .word 13
   .word -48
   .word 1086
   .word 71
   .word -760
   .word 1170
   .word 116
   .word -1226
   .word 138
   .word 1340
   .word -291
   .word 625
   .word -803
   .word -1301
   .word -1179
   .word 697
   .word -802
   .word 370
   .word -1086
   .word 1320
   .word 1316
   .word 512
   .word 1234
   .word 1163
   .word 1126
   .word 35
   .word -866
   .word 1123
   .word -614
   .word 130
   .word -1069
   .word -799
   .word -677
   .word -443
   .word 987
   .word -88
   .word -1034
   .word 1417
   .word 812
   .word 288
   .word 761
   .word -439
   .word -1355
   .word 173
   .word 453
   .word -730
   .word 62
   .word 906
   .word 462
   .word -1360
   .word 681
   .word -1179
   .word 934
   .word 417
   .word -1156
   .word -384
   .word 1342
   .word -493
   .word 1184
   .word -456
   .word -242
   .word -1042
   .word -967
   .word -69
   .word 222
   .word -299
   .word 1226
   .word -639
   .word 292
   .word -210
   .word -908
   .word -1372
   .word -498
   .word 17
   .word 606
   .word -1241
   .word 204
   .word 1363
   .word -1421
   .word -1032
   .word -861
   .word -387
   .word -753
   .word 107
   .word 244
   .word 855
   .word 468
   .word -1052
   .word 780
   .word 467
   .word 1038
   .word -1374
   .word 420
   .word -656
   .word 526
   .word 674
   .word -706
   .word -464
   .word 685
   .word -1009
   .word 1295
   .word -1251
   .word 895
   .word 821
   .word -1189
   .word -771
   .word -393
   .word 1252
   .word 221
   .word -852
   .word -1029
   .word -520
   .word -1165
   .word -127
   .word 436
   .word 258
   .word -1327
   .word 312
   .word -1096
   .word 1093
   .word 775
   .word 434
   .word -779
   .word 723
   .word 631
   .word 1008
   .word 1409
   .word -331
   .word 137
   .word -1116
   .word 668
   .word -114
   .word -1008
   .word -261
   .word -999
   .word 1149
   .word 1042
   .word -431
   .word -1192
   .word 475
   .word -155
   .word 1050
   .word 537
   .word -1227
   .word -1367
   .word 885
   .word 176
   .word -564
   .word 1378
   .word 1248
   .word -1375
   .word 793
   .word 857
   .word 609
   .word -748
   .word 1236
   .word 1041
   .word 946
   .word 276
   .word -1123
   .word 393
   .word 378
   .word 858
   .word -1107
   .word -1098
   .word -668
   .word -78
   .word 679
   .word 991
   .word -252
   .word -750
   .word -895
   .word 1118
   .word -420
   .word -1235
   .word -774
   .word -169
   .word 1275
   .word -811
   .word -529
   .word -279
   .word -1241
   .word 1141
   .word -348
   .word -867
   .word 643
   .word -596
   .word -267
   .word -1163
   .word 273
   .word 856
   .word 197
   .word -477
   .word 1385
   .word -38
   .word 1130
   .word 783
   .word -465
   .word 392
   .word 388
   .word 60
   .word -90
   .word -823
   .word 1202
   .word 1354
   .word 695
   .word 868
   .word 883
   .word 768
   .word 132
   .word -722
   .word 481
   .word -165
   .word 1083
   .word -701
   .word 121
   .word 16
   .word 1060
   .word -1359
   .word 691
   .word -795
   .word -625
   .word 357
   .word 108
   .word 734
   .word 227
   .word 20
   .word -1245
   .word 27
   .word -647
   .word 136
   .word 543
   .word -780
   .word -222
   .word 423
   .word 528
   .word 856
   .word 1267
   .word -556
   .word -612
   .word -274
   .word 1043
   .word 808
   .word -631
   .word 957
   .word -1409
   .word -481
   .word -323
   .word 219
   .word 202
   .word 818
   .word 145
   .word -1064
   .word 1007
   .word 419
   .word 750
   .word 998
   .word 298
   .word -561
   .word -249
   .word 675
   .word -868
   .word -1292
   .word -434
   .word 182
   .word -244
   .word -524
   .word -541
   .word 111
   .word 481
   .word 506
   .word -698
   .word -6
   .word 213
   .word 16
   .word -555
   .word -311
   .word 715
   .word 648
   .word 1414
   .word 130
   .word -907
   .word 333
   .word 525
   .word -734
   .word 1264
   .word -664
   .word -893
   .word -1284
   .word -1279
   .word -892
   .word 1311
   .word 730
   .word 674
   .word 855
   .word -178
   .word 649
   .word 297
   .word -607
   .word 155
   .word 542
   .word 711
   .word -507
   .word -70
   .word 192
   .word -1104
   .word -300
   .word -1407
   .word 1086
   .word -604
   .word 962
   .word -944
   .word 579
   .word -1218
   .word 870
   .word 1021
   .word -824
   .word 754
   .word 742
   .word 1165
   .word 1347
   .word -1334
   .word -1366
   .word 371
   .word -66
   .word -1035
   .word -441
   .word -870
   .word -1203
   .word 872
   .word 10
   .word 148
   .word 50
   .word -961
   .word 525
   .word 1202
   .word -1350
   .word -428
   .word -9
   .word -881
   .word -67
   .word -797
   .word 552
   .word -646
   .word -323
   .word 383
   .word 667
   .word 832
   .word 721
   .word -1234
   .word -278
   .word 766
   .word -98
   .word 1422
   .word -809
   .word 1026
   .word -1001
   .word 203
   .word 1144
   .word 1082
   .word -238
   .word -980
   .word -233
   .word 1155
   .word 717
   .word -806
   .word -435
   .word -270
   .word -532
   .word 984
   .word 99
   .word 869
   .word -1276
   .word -833
   .word 691
   .word 643
   .word -462
   .word 978
   .word -382
   .word -730
   .word -711
   .word 508
   .word 1301
   .word -584
   .word -1346
   .word -806
   .word -479
   .word -826
   .word 471
   .word -653
   .word 1427
   .word 90
   .word 1112
   .word 1264
   .word -911
   .word -559
   .word -658
   .word -859
   .word 1338
   .word -985
   .word 661
   .word 1203
   .word 469
   .word 61
   .word -1327
   .word 1265
   .word 399
   .word -858
   .word 1172
   .word 318
   .word 32
   .word -1009
   .word 332
   .word -936
   .word -955
   .word 1237
   .word -56
   .word -1225
   .word -1350
   .word -1240
   .word 51
   .word -1109
   .word 177
   .word -224
   .word 977
   .word 714
   .word 395
   .word 978
   .word 498
   .word 1316
   .word -351
   .word 153
   .word -506
   .word -1139
   .word 1165
   .word -77
   .word -779
   .word -119
   .word 66
   .word -60
   .word -41
   .word 1254
   .word -1211
   .word 1247
   .word 5
   .word 646
   .word -451
   .word 418
   .word 772
   .word 1280
   .word 1362
   .word -554
   .word 271
   .word 312
   .word -536
   .word -866
   .word -1242
   .word 1171
   .word -1196
   .word 878
   .word 877
   .word 713
   .word 301
   .word -1300
   .word 1074
   .word -1382
   .word 13
   .word -1229
   .word 489
   .word -771
   .word -1182
   .word 212
   .word 115
   .word 765
   .word -483
   .word 242
   .word -898
   .word 567
   .word -1175
   .word 108
   .word -420
   .word 1068
   .word -804
   .word -1298
   .word -1253
   .word 914
   .word -1414
   .word -749
   .word -85
   .word -942
   .word -388
   .word 818
   .word -924
   .word 1170
   .word 146
   .word 829
   .word -438
   .word 1426
   .word -642
   .word 1078
   .word -390
   .word -191
   .word 139
   .word -1331
   .word 44
   .word -1420
   .word -591
   .word -125
   .word -212
   .word -377
   .word -1017
   .word 101
   .word -148
   .word 1318
   .word -26
   .word -319
   .word 883
   .word 308
   .word 876
   .word -1108
   .word 1302
   .word -1198
   .word -1012
   .word 1397
   .word -771
   .word 1047
   .word 152
   .word 757
   .word 390
   .word 475
   .word 842
   .word 597
   .word -387
   .word -1
   .word 1206
   .word 435
   .word 652
   .word 1380
   .word -165
   .word 332
   .word 935
   .word 82
   .word -1185
   .word -1218
   .word 10
   .word -176
   .word -332
   .word -1189
   .word 1073
   .word 1261
   .word 722
   .word 657
   .word -379
   .word 208
   .word 430
   .word 522
   .word -1064
   .word 727
   .word 796
   .word 662
   .word -968
   .word 1220
   .word 645
   .word -305
   .word -263
   .word -584
   .word 567
   .word -90
   .word -1143
   .word 3
   .word 14
   .word -766
   .word 146
   .word -493
   .word 399
   .word -1073
   .word -253
   .word 318
   .word -731
   .word -748
   .word -1119
   .word -220
   .word 602
   .word -180
   .word 360
   .word -330
   .word -528
   .word 1169
   .word 1389
   .word -1214
   .word -1225
   .word 1415
   .word 376
   .word -396
   .word 1277
   .word -545
   .word 1411
   .word 1008
   .word 222
   .word 490
   .word 671
   .word -857
   .word -1245
   .word -35
   .word 293
   .word -397
   .word -976
   .word 674
   .word -1146
   .word -1068
   .word -287
   .word -797
   .word -1096
   .word 1062
   .word -117
   .word -37
   .word 701
   .word 1248
   .word -129
   .word 526
   .word -1116
   .word -555
   .word -837
   .word 316
   .word -1320
   .word 409
   .word 959
   .word 113
   .word 1092
   .word 1397
   .word 761
   .word -888
   .word -421
   .word 1288
   .word 77
   .word -776
   .word -195
   .word -1088
   .word -1096
   .word 1081
   .word -1
   .word -70
   .word -703
   .word 303
   .word 251
   .word 176
   .word 366
   .word 1284
   .word -691
   .word -543
   .word -190
   .word 505
   .word -313
   .word -1236
   .word 279
   .word -600
   .word 571
   .word -703
   .word 372
   .word 940
   .word 1092
   .word -55
   .word -617
   .word -513
   .word -161
   .word 303
   .word -647
   .word -294
   .word -1139
   .word 1344
   .word -806
   .word 1222
   .word 975
   .word 857
   .word 1252
   .word 195
   .word -752
   .word -1016
   .word -440
   .word 169
   .word 948
   .word 1205
   .word 963
   .word -91
   .word -1111
   .word -954
   .word 235
   .word -1060
   .word -1096
   .word -683
   .word -837
   .word -152
   .word 180
   .word 1039
   .word -458
   .word 1091
   .word 285
   .word -881
   .word 742
   .word -1360
   .word -652
   .word -573
   .word 506
   .word 797
   .word -180
   .word -190
   .word -959
   .word -696
   .word 937
   .word -1229
   .word 965
   .word 1362
   .word 1144
   .word -394
   .word 14
   .word 875
   .word -818
   .word -409
   .word -725
   .word -356
   .word -499
   .word 1025
   .word -872
   .word -1405
   .word -119
   .word 560
   .word 548
   .word 860
   .word -1297
   .word 850
   .word -1328
   .word 329
   .word 1170
   .word 935
   .word -640
   .word 516
   .word 561
   .word 102
   .word -124
   .word -40
   .word -225
   .word -934
   .word 1304
   .word 299
   .word -615
   .word 268
   .word -665
   .word 1372
   .word -83
   .word -640
   .word -1351
   .word -621
   .word 710
   .word 886
   .word 1346
   .word 289
   .word 682
   .word 625
   .word 164
   .word 1319
   .word 312
   .word 745
   .word 81
   .word -556
   .word -567
   .word -522
   .word -849
   .word -737
   .word 826
   .word -451
   .word 222
   .word -1160
   .word 1311
   .word -563
   .word 894
   .word 197
   .word 111
   .word 204
   .word 378
   .word 524
   .word -481
   .word -319
   .word 928
   .word -491
   .word 963
   .word 360
   .word 459
   .word 1349
   .word 546
   .word -504
   .word 301
   .word -1182
   .word 64
   .word 1137
   .word -1196
   .word -603
   .word 195
   .word 1318
   .word -1320
   .word -209
   .word 432
   .word 526
   .word 415
   .word -267
   .word 888
   .word 1032
   .word -1347
   .word -798
   .word 428
   .word 923
   .word -1121
   .word -1286
   .word -10
   .word -720
   .word 713
   .word -67
   .word -138
   .word -24
   .word -517
   .word -1266
   .word -556
   .word -279
   .word -257
   .word 441
   .word 1382
   .word -96
   .word 590
   .word -1073
   .word -138
   .word 618
   .word 1240
   .word -1379
   .word -240
   .word -1131
   .word 192
   .word 1263
   .word -718
   .word 1006
   .word 621
   .word -163
   .word 1247
   .word 1094
   .word 448
   .word -433
   .word -517
   .word 253
   .word 1136
   .word 1002
   .word 1254
   .word -484
   .word 745
   .word -1248
   .word -760
   .word 147
   .word 136
   .word 161
   .word 706
   .word 1313
   .word -51
   .word 915
   .word 224
   .word -1128
   .word -413
   .word 1356
   .word 1384
   .word 36
   .word 1005
   .word 295
   .word 870
   .word 360
   .word -1231
   .word -1393
   .word 955
   .word 772
   .word 815
   .word 536
   .word -704
   .word 78
   .word 139
   .word 917
   .word 939
   .word -736
   .word -368
   .word 880
   .word 1148
   .word -985
   .word -364
   .word -1009
   .word -68
   .word -1180
   .word -48
   .word -1039
   .word 1142
   .word -1407
   .word 1199
   .word 377
   .word 494
   .word -1127
   .word 1154
   .word -1130
   .word -1099
   .word 294
   .word -1155
   .word 477
   .word -1180
   .word -509
   .word -775
   .word -1384
   .word -1118
   .word 387
   .word -128
   .word -942
   .word 383
   .word -1311
   .word -319
   .word 927
   .word 204
   .word -934
   .word -1136
   .word 604
   .word -278
   .word 351
   .word 1148
   .word 413
   .word 164
   .word -455
   .word 627
   .word -1321
   .word -759
   .word 673
   .word -1242
   .word 1416
   .word -537
   .word -399
   .word 822
   .word 305
   .word 197
   .word -1192
   .word -559
   .word -283
   .word 876
   .word 685
   .word 443
   .word 355
   .word -1160
   .word -214
   .word -198
   .word -707
   .word -177
   .word -404
   .word -971
   .word -752
   .word 447
   .word 644
   .word -650
   .word -844
   .word -496
   .word 124
   .word -393
   .word 235
   .word -1298
   .word -137
   .word -549
   .word -658
   .word -279
   .word -888
   .word 586
   .word -297
   .word -786
   .word 1338
   .word -30
   .word 1062
   .word -539
   .word 318
   .word -353
   .word -766
   .word -677
   .word -332
   .word 179
   .word -89
   .word 387
   .word 831
   .word -338
   .word 175
   .word 1245
   .word 827
   .word -682
   .word -1307
   .word -167
   .word 1334
   .word 104
   .word 1046
   .word -1163
   .word -1354
   .word 1175
   .word 1144
   .word -34
   .word -1194
   .word -874
   .word 291
   .word 245
   .word 543
   .word 796
   .word -1307
   .word -1113
   .word -696
   .word 314
   .word 379
   .word 1117
   .word 36
   .word 1428
   .word 984
   .word -1332
   .word 1142
   .word 465
   .word 340
   .word -372
   .word 1401
   .word -103
   .word 313
   .word 707
   .word 142
   .word -185
   .word 265
   .word -972
   .word -1324
   .word 971
   .word 1100
   .word 1059
   .word 1428
   .word -1205
   .word -439
   .word -1191
   .word 133
   .word 949
   .word 660
   .word 69
   .word 16
   .word 487
   .word -885
   .word 526
   .word 987
   .word 739
   .word -309
   .word -211
   .word -996
   .word -299
   .word 734
   .word 1393
   .word 74
   .word -405
   .word 1400
   .word -1271
   .word -137
   .word 764
   .word 1340
   .word 16
   .word -591
   .word 936
   .word 1202
   .word 857
   .word 635
   .word 486
   .word 124
   .word 1256
   .word -1318
   .word 373
   .word -579
   .word 353
   .word -618
   .word -1330
   .word -467
   .word -1180
   .word 955
   .word 553
   .word 81
   .word -776
   .word -206
   .word 655
   .word -934
   .word 859
   .word 209
   .word 1173
   .word 549
   .word -958
   .word 538
   .word 593
   .word 274
   .word -150
   .word 398
   .word -108
   .word -1247
   .word 349
   .word -1285
   .word -283
   .word -1272
   .word 708
   .word -851
   .word 770
   .word -1099
   .word -850
   .word 829
   .word 269
   .word 928
   .word -654
   .word -465
   .word -256
   .word -743
   .word 420
   .word 1173
   .word 259
   .word -85
   .word -126
   .word -615
   .word -92
   .word -610
   .word -958
   .word -948
   .word -456
   .word -972
   .word 855
   .word 1277
   .word 492
   .word -512
   .word 1138
   .word 74
   .word 209
   .word -236
   .word 1217
   .word 948
   .word -712
   .word 489
   .word 1354
   .word 354
   .word -461
   .word 682
   .word 752
   .word 692
   .word 179
   .word 1262
   .word -866
   .word 144
   .word -176
   .word -28
   .word 750
   .word 274
   .word 23
   .word 222
   .word 618
   .word -1229
   .word 118
   .word -600
   .word 424
   .word 1223
   .word -680
   .word -16
   .word -1037
   .word 902
   .word -250
   .word -421
   .word -635
   .word 581
   .word 765
   .word 581
   .word -300
   .word -484
   .word 1389
   .word -645
   .word -1003
   .word 1403
   .word 925
   .word -1215
   .word -521
   .word 1125
   .word -321
   .word -344
   .word 260
   .word -1322
   .word 928
   .word 174
   .word 1006
   .word 466
   .word -284
   .word 293
   .word 784
   .word -966
   .word 774
   .word -1342
   .word -662
   .word 213
   .word 1172
   .word -861
   .word 885
   .word 894
   .word 1334
   .word -486
   .word -371
   .word 522
   .word 436
   .word -1206
   .word 622
   .word -1082
   .word -1160
   .word 1360
   .word -176
   .word 719
   .word -146
   .word 456
   .word 540
   .word 226
   .word -289
   .word -169
   .word 2
   .word -1074
   .word 1208
   .word -939
   .word 1244
   .word 357
   .word -196
   .word -103
   .word -1207
   .word 643
   .word 154
   .word -956
   .word 1157
   .word -1044
   .word 579
   .word -740
   .word -927
   .word 451
   .word -987
   .word -307
   .word 1082
   .word -1340
   .word 101
   .word -786
   .word -938
   .word 373
   .word -828
   .word -260
   .word -191
   .word -1313
   .word -739
   .word 823
   .word -581
   .word -1218
   .word 866
   .word -460
   .word -1081
   .word 1221
   .word 862
   .word -157
   .word -854
   .word -350
   .word -1306
   .word -736
   .word 1422
   .word -797
   .word -221
   .word 264
   .word -1128
   .word -1203
   .word -283
   .word -936
   .word 1294
   .word -528
   .word -684
   .word 542
   .word -761
   .word 1355
   .word 286
   .word -854
   .word 917
   .word 43
   .word 937
   .word -700
   .word 889
   .word -270
   .word -468
   .word 24
   .word -556
   .word -798
   .word -743
   .word 866
   .word 708
   .word -858
   .word 168
   .word 122
   .word -1267
   .word 70
   .word -429
   .word -1172
   .word 1265
   .word -168
   .word 363
   .word -1192
   .word -1385
   .word -1037
   .word -638
   .word -361
   .word -460
   .word -4
   .word 411
   .word 427
   .word 467
   .word 363
   .word 1291
   .word 426
   .word -977
   .word -844
   .word 1323
   .word 1207
   .word -918
   .word -438
   .word -799
   .word 676
   .word 269
   .word -1043
   .word 1330
   .word -1
   .word 112
   .word -548
   .word -56
   .word -893
   .word -528
   .word -111
   .word -220
   .word 1104
   .word -1240
   .word -737
   .word -774
   .word 994
   .word 300
   .word -1193
   .word -680
   .word -422
   .word -1345
   .word 317
   .word -825
   .word 232
   .word 257
   .word -940
   .word -993
   .word 1037
   .word -278
   .word 324
   .word -806
   .word 914
   .word -448
   .word -982
   .word 589
   .word 910
   .word 951
   .word -1159
   .word -1181
   .word 489
   .word -804
   .word 9
   .word -455
   .word 294
   .word 1126
   .word 887
   .word -386
   .word 1282
   .word 844
   .word -355
   .word -827
   .word 1416
   .word 296
   .word -1083
   .word -411
   .word 223
   .word 1249
   .word 179
   .word -1219
   .word 424
   .word 1227
   .word 836
   .word 688
   .word 268
   .word -44
   .word -1191
   .word 347
   .word -1158
   .word 925
   .word 324
   .word 605
   .word 739
   .word 97
   .word 928
   .word 861
   .word 168
   .word 1352
   .word -545
   .word -1075
   .word 1059
   .word 990
   .word -983
   .word -1343
   .word -900
   .word 1084
   .word 246
   .word 506
   .word 1122
   .word 1197
   .word -1040
   .word 1212
   .word 115
   .word 341
   .word 683
   .word 523
   .word 548
   .word 589
   .word 1210
   .word 216
   .word 449
   .word -108
   .word 191
   .word 985
   .word -901
   .word 974
   .word -1403
   .word 1298
   .word -74
   .word 988
   .word -1068
   .word 896
   .word -492
   .word 750
   .word -887
   .word -622
   .word -287
   .word -23
   .word 744
   .word -1221
   .word -1294
   .word 752
   .word -492
   .word 497
   .word 786
   .word 706
   .word -155
   .word 1003
   .word -1106
   .word 370
   .word -793
   .word -446
   .word 1196
   .word 1143
   .word 481
   .word -1386
   .word 105
   .word 1124
   .word 263
   .word 985
   .word 423
   .word -652
   .word -1344
   .word -481
   .word 31
   .word -376
   .word -183
   .word -312
   .word -193
   .word -1227
   .word 1164
   .word 121
   .word -909
   .word -1418
   .word 1359
   .word 175
   .word 145
   .word 0
   .word -917
   .word -625
   .word 1161
   .word 1255
   .word -595
   .word 322
   .word 1339
   .word 1306
   .word -993
