   .option nopic
   .attribute arch, "rv64i2p0_m2p0_a2p0_f2p0_d2p0_c2p0"
   .attribute unaligned_access, 0
   .attribute stack_align, 16
   .text
   .align 2
   .global lenLongestFibSubseq
   .type lenLongestFibSubseq, @function
   lenLongestFibSubseq:
   addi sp, sp, -96
   sd s0, 88(sp)
   sd ra, 80(sp)
   sd s1, 72(sp)
   sd s2, 64(sp)
   sd s3, 56(sp)
   sd s4, 48(sp)
   addi s0, sp, 96
   li s1, 1
   sw s1, -56(s0)
   li s1, 0
   sw s1, -60(s0)
L0:
   lw s1, -56(s0)
   bge s1, a0, L1
   li s1, 0
   sw s1, -64(s0)
   lw s1, -56(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -64(s0)
L2:
   lw s2, -64(s0)
   bge s2, a0, L3
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -64(s0)
   li s3, 4
   mul s2, s2, s3
   add s2, s1, s2
   lw s3, -56(s0)
   li s4, 4
   mul s3, s3, s4
   add s1, s1, s3
   li s3, 2
   la s4, GVar1
   add s1, s4, s1
   lw s1, 0(s1)
   mul s1, s3, s1
   add s2, s4, s2
   lw s2, 0(s2)
   bge s1, s2, L4
   j L3
L4:
   li s1, 0
   sw s1, -68(s0)
   li s1, 0
   sw s1, -72(s0)
   li s1, 0
   sw s1, -76(s0)
   li s1, 0
   sw s1, -80(s0)
   li s1, 0
   sw s1, -84(s0)
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -64(s0)
   li s3, 4
   mul s2, s2, s3
   add s2, s1, s2
   lw s3, -56(s0)
   li s4, 4
   mul s4, s3, s4
   add s1, s1, s4
   la s4, GVar1
   add s2, s4, s2
   lw s2, 0(s2)
   la s4, GVar1
   add s1, s4, s1
   lw s1, 0(s1)
   sub s1, s2, s1
   sw s1, -68(s0)
   li s2, 0
   sw s2, -72(s0)
   li s1, 1
   sub s1, s3, s1
   sw s1, -76(s0)
   li s2, 1
   neg s1, s2
   sw s1, -80(s0)
L5:
   lw s2, -72(s0)
   lw s1, -76(s0)
   blt s1, s2, L6
   lw s1, -76(s0)
   lw s2, -72(s0)
   sub s1, s1, s2
   li s3, 2
   div s1, s1, s3
   add s1, s1, s2
   sw s1, -84(s0)
   li s2, 0
   li s3, 0
   add s2, s2, s3
   li s3, 4
   mul s1, s1, s3
   add s1, s2, s1
   la s2, GVar1
   add s1, s2, s1
   lw s1, 0(s1)
   lw s2, -68(s0)
   bne s1, s2, L7
   lw s1, -84(s0)
   sw s1, -80(s0)
   j L6
   j L5
L7:
   li s2, 0
   li s1, 0
   add s1, s2, s1
   lw s2, -84(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar1
   add s1, s2, s1
   lw s1, 0(s1)
   lw s2, -68(s0)
   bge s1, s2, L8
   lw s1, -84(s0)
   li s2, 1
   add s1, s1, s2
   sw s1, -72(s0)
   j L5
L8:
   lw s2, -84(s0)
   li s1, 1
   sub s1, s2, s1
   sw s1, -76(s0)
   j L5
L6:
   lw s2, -80(s0)
   li s1, 0
   blt s2, s1, L9
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -56(s0)
   li s3, 1064
   mul s3, s2, s3
   add s3, s1, s3
   lw s4, -64(s0)
   li s5, 4
   mul s4, s4, s5
   add s3, s3, s4
   lw s4, -80(s0)
   li s5, 1064
   mul s4, s4, s5
   add s1, s1, s4
   li s4, 4
   mul s2, s2, s4
   add s1, s1, s2
   la s2, GVar0
   add s1, s2, s1
   lw s1, 0(s1)
   li s4, 1
   add s1, s1, s4
   add s4, s2, s3
   sw s1, 0(s4)
   add s2, s2, s3
   lw s2, 0(s2)
   li s1, 3
   bge s2, s1, L10
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -56(s0)
   li s3, 1064
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -64(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   li s2, 3
   la s3, GVar0
   add s1, s3, s1
   sw s2, 0(s1)
L10:
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -56(s0)
   li s3, 1064
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -64(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar0
   add s1, s2, s1
   lw s1, 0(s1)
   lw s2, -60(s0)
   bge s2, s1, L9
   li s1, 0
   li s2, 0
   add s1, s1, s2
   lw s2, -56(s0)
   li s3, 1064
   mul s2, s2, s3
   add s1, s1, s2
   lw s2, -64(s0)
   li s3, 4
   mul s2, s2, s3
   add s1, s1, s2
   la s2, GVar0
   add s1, s2, s1
   lw s1, 0(s1)
   sw s1, -60(s0)
L9:
   lw s2, -64(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -64(s0)
   j L2
L3:
   lw s2, -56(s0)
   li s1, 1
   add s1, s2, s1
   sw s1, -56(s0)
   j L0
L1:
   lw s2, -60(s0)
   mv a0, s2
   ld s0, 88(sp)
   ld ra, 80(sp)
   ld s1, 72(sp)
   ld s2, 64(sp)
   ld s3, 56(sp)
   ld s4, 48(sp)
   addi sp, sp, 96
   ret
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
   li s2, 0
   sw s2, -52(s0)
   li s2, 0
   sw s2, -56(s0)
   call get_int
   mv s2, a0
   sw s2, -52(s0)
   mv a0, s2
   call lenLongestFibSubseq
   mv s1, a0
   sw s1, -56(s0)
   mv a0, s1
   call print_int
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
   .size GVar0, 283024
   GVar0:
   .zero 283024

   .globl GVar1
   .data
   .align 3
   .type GVar1, @object
   .size GVar1, 1064
   GVar1:
   .word 1
   .word 5
   .word 6
   .word 7
   .word 11
   .word 14
   .word 15
   .word 16
   .word 18
   .word 21
   .word 29
   .word 31
   .word 40
   .word 45
   .word 47
   .word 51
   .word 52
   .word 55
   .word 57
   .word 61
   .word 62
   .word 64
   .word 68
   .word 69
   .word 74
   .word 75
   .word 78
   .word 79
   .word 88
   .word 90
   .word 92
   .word 93
   .word 94
   .word 100
   .word 101
   .word 103
   .word 104
   .word 105
   .word 114
   .word 115
   .word 125
   .word 126
   .word 128
   .word 129
   .word 133
   .word 140
   .word 141
   .word 143
   .word 144
   .word 146
   .word 150
   .word 160
   .word 162
   .word 166
   .word 173
   .word 178
   .word 182
   .word 183
   .word 185
   .word 186
   .word 188
   .word 191
   .word 194
   .word 204
   .word 206
   .word 216
   .word 219
   .word 220
   .word 221
   .word 225
   .word 228
   .word 231
   .word 240
   .word 244
   .word 250
   .word 251
   .word 252
   .word 257
   .word 259
   .word 260
   .word 267
   .word 270
   .word 271
   .word 275
   .word 279
   .word 280
   .word 287
   .word 288
   .word 291
   .word 292
   .word 299
   .word 302
   .word 303
   .word 310
   .word 311
   .word 312
   .word 316
   .word 317
   .word 324
   .word 325
   .word 327
   .word 328
   .word 329
   .word 332
   .word 333
   .word 337
   .word 346
   .word 351
   .word 356
   .word 358
   .word 361
   .word 363
   .word 366
   .word 370
   .word 373
   .word 374
   .word 380
   .word 383
   .word 384
   .word 388
   .word 390
   .word 391
   .word 392
   .word 395
   .word 398
   .word 399
   .word 402
   .word 404
   .word 407
   .word 410
   .word 411
   .word 413
   .word 414
   .word 417
   .word 418
   .word 419
   .word 421
   .word 425
   .word 432
   .word 433
   .word 434
   .word 435
   .word 440
   .word 441
   .word 443
   .word 444
   .word 447
   .word 448
   .word 449
   .word 452
   .word 453
   .word 455
   .word 456
   .word 460
   .word 461
   .word 467
   .word 469
   .word 475
   .word 477
   .word 482
   .word 484
   .word 487
   .word 488
   .word 490
   .word 493
   .word 494
   .word 495
   .word 497
   .word 501
   .word 504
   .word 505
   .word 508
   .word 510
   .word 512
   .word 516
   .word 520
   .word 521
   .word 526
   .word 532
   .word 541
   .word 543
   .word 544
   .word 545
   .word 546
   .word 549
   .word 550
   .word 555
   .word 558
   .word 562
   .word 563
   .word 566
   .word 570
   .word 572
   .word 579
   .word 580
   .word 582
   .word 583
   .word 584
   .word 587
   .word 595
   .word 599
   .word 606
   .word 608
   .word 611
   .word 612
   .word 620
   .word 622
   .word 625
   .word 632
   .word 636
   .word 637
   .word 644
   .word 646
   .word 648
   .word 650
   .word 653
   .word 659
   .word 662
   .word 664
   .word 665
   .word 667
   .word 672
   .word 676
   .word 679
   .word 680
   .word 681
   .word 687
   .word 690
   .word 691
   .word 692
   .word 693
   .word 694
   .word 697
   .word 698
   .word 699
   .word 702
   .word 703
   .word 708
   .word 709
   .word 711
   .word 715
   .word 716
   .word 718
   .word 719
   .word 727
   .word 730
   .word 733
   .word 734
   .word 735
   .word 739
   .word 740
   .word 749
   .word 750
   .word 758
   .word 764
   .word 766
   .word 768
   .word 771
   .word 775
   .word 784
   .word 789
   .word 790
   .word 791
   .word 794
   .word 795
   .word 799
