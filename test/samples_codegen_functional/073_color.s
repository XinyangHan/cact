   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global equal
   .type equal, @function
   equal:
   addi sp, sp, -48
   sd s0, 40(sp)
   sd ra, 32(sp)
   sd s1, 24(sp)
   sd s2, 16(sp)
   addi s0, sp, 48
   bne a0, a1, L0
   li s1, 1
   mv a0, s1
   ld s0, 40(sp)
   ld ra, 32(sp)
   ld s1, 24(sp)
   ld s2, 16(sp)
   addi sp, sp, 48
   ret
L0:
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
   .text
   .align 2
   .global dfs
   .type dfs, @function
   dfs:
   addi sp, sp, -64
   sd s0, 56(sp)
   sd ra, 48(sp)
   sd s1, 40(sp)
   sd s2, 32(sp)
   addi s0, sp, 64
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 2939328
   mul s2, a0, s2
   add s1, s1, s2
   li s2, 163296
   mul s2, a1, s2
   add s1, s1, s2
   li s2, 9072
   mul s2, a2, s2
   add s1, s1, s2
   li s2, 504
   mul s2, a3, s2
   add s1, s1, s2
   li s2, 28
   mul s2, a4, s2
   add s1, s1, s2
   li s2, 4
   mul s2, a5, s2
   add s1, s1, s2
   li s2, 1
   neg s3, s2
   la s4, GVar2
   add s1, s4, s1
   lw s1, 0(s1)
   beq s1, s3, L1
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 2939328
   mul s2, a0, s2
   add s1, s1, s2
   li s2, 163296
   mul s2, a1, s2
   add s1, s1, s2
   li s2, 9072
   mul s2, a2, s2
   add s1, s1, s2
   li s2, 504
   mul s2, a3, s2
   add s1, s1, s2
   li s2, 28
   mul s2, a4, s2
   add s1, s1, s2
   li s2, 4
   mul s2, a5, s2
   add s1, s1, s2
   la s2, GVar2
   add s1, s2, s1
   lw s1, 0(s1)
   mv a0, s1
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
L1:
   add s1, a0, a1
   add s1, s1, a2
   add s1, s1, a3
   add s1, s1, a4
   li s2, 0
   bne s1, s2, L2
   li s1, 1
   mv a0, s1
   ld s0, 56(sp)
   ld ra, 48(sp)
   ld s1, 40(sp)
   ld s2, 32(sp)
   addi sp, sp, 64
   ret
L2:
   li s1, 0
   sw s1, -60(s0)
   li s1, 0
   beq a0, s1, L3
   sw a0, -36(s0)
   mv a0, a5
   sw a1, -40(s0)
   li s1, 2
   mv a1, s1
   call equal
   lw a1, -40(s0)
   mv s1, a0
   lw a0, -36(s0)
   sub s1, a0, s1
   li s2, 1
   sub s2, a0, s2
   sw a0, -36(s0)
   mv a0, s2
   sw a1, -40(s0)
   mv a1, a1
   sw a2, -44(s0)
   mv a2, a2
   sw a3, -48(s0)
   mv a3, a3
   sw a4, -52(s0)
   mv a4, a4
   sw a5, -56(s0)
   li s2, 1
   mv a5, s2
   call dfs
   lw a1, -40(s0)
   lw a2, -44(s0)
   lw a3, -48(s0)
   lw a4, -52(s0)
   lw a5, -56(s0)
   mv s2, a0
   lw a0, -36(s0)
   mul s1, s1, s2
   lw s2, -60(s0)
   add s1, s2, s1
   la s2, GVar1
   lw s2, 0(s2)
   rem s1, s1, s2
   sw s1, -60(s0)
L3:
   li s1, 0
   beq a1, s1, L4
   sw a0, -36(s0)
   mv a0, a5
   sw a1, -40(s0)
   li s1, 3
   mv a1, s1
   call equal
   lw a1, -40(s0)
   mv s1, a0
   lw a0, -36(s0)
   sub s1, a1, s1
   li s2, 1
   add s2, a0, s2
   sw a0, -36(s0)
   mv a0, s2
   li s2, 1
   sub s2, a1, s2
   sw a1, -40(s0)
   mv a1, s2
   sw a2, -44(s0)
   mv a2, a2
   sw a3, -48(s0)
   mv a3, a3
   sw a4, -52(s0)
   mv a4, a4
   sw a5, -56(s0)
   li s2, 2
   mv a5, s2
   call dfs
   lw a1, -40(s0)
   lw a2, -44(s0)
   lw a3, -48(s0)
   lw a4, -52(s0)
   lw a5, -56(s0)
   mv s2, a0
   lw a0, -36(s0)
   mul s1, s1, s2
   lw s2, -60(s0)
   add s1, s2, s1
   la s2, GVar1
   lw s2, 0(s2)
   rem s1, s1, s2
   sw s1, -60(s0)
L4:
   li s1, 0
   beq a2, s1, L5
   sw a0, -36(s0)
   mv a0, a5
   sw a1, -40(s0)
   li s1, 4
   mv a1, s1
   call equal
   lw a1, -40(s0)
   mv s1, a0
   lw a0, -36(s0)
   sub s1, a2, s1
   sw a0, -36(s0)
   mv a0, a0
   li s2, 1
   add s2, a1, s2
   sw a1, -40(s0)
   mv a1, s2
   li s2, 1
   sub s2, a2, s2
   sw a2, -44(s0)
   mv a2, s2
   sw a3, -48(s0)
   mv a3, a3
   sw a4, -52(s0)
   mv a4, a4
   sw a5, -56(s0)
   li s2, 3
   mv a5, s2
   call dfs
   lw a1, -40(s0)
   lw a2, -44(s0)
   lw a3, -48(s0)
   lw a4, -52(s0)
   lw a5, -56(s0)
   mv s2, a0
   lw a0, -36(s0)
   mul s1, s1, s2
   lw s2, -60(s0)
   add s1, s2, s1
   la s2, GVar1
   lw s2, 0(s2)
   rem s1, s1, s2
   sw s1, -60(s0)
L5:
   li s1, 0
   beq a3, s1, L6
   sw a0, -36(s0)
   mv a0, a5
   sw a1, -40(s0)
   li s1, 5
   mv a1, s1
   call equal
   lw a1, -40(s0)
   mv s1, a0
   lw a0, -36(s0)
   sub s1, a3, s1
   sw a0, -36(s0)
   mv a0, a0
   sw a1, -40(s0)
   mv a1, a1
   li s2, 1
   add s2, a2, s2
   sw a2, -44(s0)
   mv a2, s2
   li s2, 1
   sub s2, a3, s2
   sw a3, -48(s0)
   mv a3, s2
   sw a4, -52(s0)
   mv a4, a4
   sw a5, -56(s0)
   li s2, 4
   mv a5, s2
   call dfs
   lw a1, -40(s0)
   lw a2, -44(s0)
   lw a3, -48(s0)
   lw a4, -52(s0)
   lw a5, -56(s0)
   mv s2, a0
   lw a0, -36(s0)
   mul s1, s1, s2
   lw s2, -60(s0)
   add s1, s2, s1
   la s2, GVar1
   lw s2, 0(s2)
   rem s1, s1, s2
   sw s1, -60(s0)
L6:
   li s1, 0
   beq a4, s1, L7
   sw a0, -36(s0)
   mv a0, a0
   sw a1, -40(s0)
   mv a1, a1
   sw a2, -44(s0)
   mv a2, a2
   li s1, 1
   add s1, a3, s1
   sw a3, -48(s0)
   mv a3, s1
   li s1, 1
   sub s1, a4, s1
   sw a4, -52(s0)
   mv a4, s1
   sw a5, -56(s0)
   li s1, 5
   mv a5, s1
   call dfs
   lw a1, -40(s0)
   lw a2, -44(s0)
   lw a3, -48(s0)
   lw a4, -52(s0)
   lw a5, -56(s0)
   mv s1, a0
   lw a0, -36(s0)
   mul s1, a4, s1
   lw s2, -60(s0)
   add s1, s2, s1
   la s2, GVar1
   lw s2, 0(s2)
   rem s1, s1, s2
   sw s1, -60(s0)
L7:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   li s2, 2939328
   mul s2, a0, s2
   add s1, s1, s2
   li s2, 163296
   mul s2, a1, s2
   add s1, s1, s2
   li s2, 9072
   mul s2, a2, s2
   add s1, s1, s2
   li s2, 504
   mul s2, a3, s2
   add s1, s1, s2
   li s2, 28
   mul s2, a4, s2
   add s1, s1, s2
   li s2, 4
   mul s2, a5, s2
   add s1, s1, s2
   lw s2, -60(s0)
   la s3, GVar1
   lw s3, 0(s3)
   rem s2, s2, s3
   la s3, GVar2
   add s1, s3, s1
   sw s2, 0(s1)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   li s2, 2939328
   mul s2, a0, s2
   add s1, s1, s2
   li s2, 163296
   mul s2, a1, s2
   add s1, s1, s2
   li s2, 9072
   mul s2, a2, s2
   add s1, s1, s2
   li s2, 504
   mul s2, a3, s2
   add s1, s1, s2
   li s2, 28
   mul s2, a4, s2
   add s1, s1, s2
   li s2, 4
   mul s2, a5, s2
   add s1, s1, s2
   add s1, s3, s1
   lw s1, 0(s1)
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
   call get_int
   mv s1, a0
   sw s1, -36(s0)
   li s2, 0
   sw s2, -40(s0)
   li s2, 0
   sw s2, -40(s0)
L8:
   lw s1, -40(s0)
   la s2, GVar0
   lw s2, 0(s2)
   bge s1, s2, L9
   li s1, 0
   sw s1, -44(s0)
L10:
   lw s1, -44(s0)
   la s2, GVar0
   lw s2, 0(s2)
   bge s1, s2, L11
   li s1, 0
   sw s1, -48(s0)
L12:
   lw s1, -48(s0)
   la s2, GVar0
   lw s2, 0(s2)
   bge s1, s2, L13
   li s1, 0
   sw s1, -52(s0)
L14:
   lw s1, -52(s0)
   la s2, GVar0
   lw s2, 0(s2)
   bge s1, s2, L15
   li s1, 0
   sw s1, -56(s0)
L16:
   lw s1, -56(s0)
   la s2, GVar0
   lw s2, 0(s2)
   bge s1, s2, L17
   li s1, 0
   sw s1, -60(s0)
L18:
   lw s1, -60(s0)
   li s2, 7
   bge s1, s2, L19
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -40(s0)
   li s3, 2939328
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -44(s0)
   li s3, 163296
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -48(s0)
   li s3, 9072
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -52(s0)
   li s3, 504
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -56(s0)
   li s3, 28
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -60(s0)
   li s3, 4
   mul s3, s2, s3
   add s1, s1, s3
   li s3, 1
   neg s4, s3
   la s3, GVar2
   add s1, s3, s1
   sw s4, 0(s1)
   li s1, 1
   add s1, s2, s1
   sw s1, -60(s0)
   j L18
L19:
   lw s2, -56(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -56(s0)
   j L16
L17:
   lw s2, -52(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -52(s0)
   j L14
L15:
   lw s2, -48(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -48(s0)
   j L12
L13:
   lw s2, -44(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -44(s0)
   j L10
L11:
   lw s2, -40(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -40(s0)
   j L8
L9:
   li s2, 0
   sw s2, -40(s0)
L20:
   lw s1, -40(s0)
   lw s2, -36(s0)
   bge s1, s2, L21
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -40(s0)
   li s3, 4
   mul s3, s2, s3
   add s1, s1, s3
   call get_int
   mv s3, a0
   la s4, GVar3
   add s1, s4, s1
   sw s3, 0(s1)
   li s1, 0
   li s3, 0
   add s1, s1, s3
   li s3, 0
   li s5, 0
   add s3, s3, s5
   li s5, 4
   mul s5, s2, s5
   add s3, s3, s5
   add s3, s4, s3
   lw s3, 0(s3)
   li s5, 4
   mul s3, s3, s5
   add s1, s1, s3
   li s3, 0
   li s5, 0
   add s3, s3, s5
   li s5, 0
   li s6, 0
   add s5, s5, s6
   li s6, 4
   mul s6, s2, s6
   add s5, s5, s6
   add s4, s4, s5
   lw s4, 0(s4)
   li s5, 4
   mul s4, s4, s5
   add s3, s3, s4
   la s4, GVar4
   add s3, s4, s3
   lw s3, 0(s3)
   li s5, 1
   add s3, s3, s5
   add s1, s4, s1
   sw s3, 0(s1)
   li s1, 1
   add s1, s2, s1
   sw s1, -40(s0)
   j L20
L21:
   li s2, 0
   sw s2, -64(s0)
   li s2, 0
   li s1, 0
   add s1, s2, s1
   li s2, 1
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar4
   add s1, s2, s1
   lw s1, 0(s1)
   mv a0, s1
   li s1, 0
   li s3, 0
   add s1, s1, s3
   li s3, 2
   li s4, 4
   mul s3, s3, s4
   add s1, s1, s3
   add s1, s2, s1
   lw s1, 0(s1)
   mv a1, s1
   li s1, 0
   li s3, 0
   add s1, s1, s3
   li s3, 3
   li s4, 4
   mul s3, s3, s4
   add s1, s1, s3
   add s1, s2, s1
   lw s1, 0(s1)
   mv a2, s1
   li s1, 0
   li s3, 0
   add s1, s1, s3
   li s3, 4
   li s4, 4
   mul s3, s3, s4
   add s1, s1, s3
   add s1, s2, s1
   lw s1, 0(s1)
   mv a3, s1
   li s1, 0
   li s3, 0
   add s1, s1, s3
   li s3, 5
   li s4, 4
   mul s3, s3, s4
   add s1, s1, s3
   add s1, s2, s1
   lw s1, 0(s1)
   mv a4, s1
   li s1, 0
   mv a5, s1
   call dfs
   mv s1, a0
   sw s1, -64(s0)
   mv a0, s1
   call print_int
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
   .align 2
   .type GVar0, @object
   .size GVar0, 4
   GVar0:
   .word 18
   .globl GVar1
   .data
   .align 2
   .type GVar1, @object
   .size GVar1, 4
   GVar1:
   .word 1000000007
   .globl GVar2
   .bss
   .align 3
   .type GVar2, @object
   .size GVar2, 52907904
   GVar2:
   .zero 52907904

   .globl GVar3
   .bss
   .align 3
   .type GVar3, @object
   .size GVar3, 800
   GVar3:
   .zero 800

   .globl GVar4
   .bss
   .align 3
   .type GVar4, @object
   .size GVar4, 80
   GVar4:
   .zero 80

