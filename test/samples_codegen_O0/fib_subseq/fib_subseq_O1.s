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
   .word 0
   .word 5
   .word 7
   .word 8
   .word 9
   .word 12
   .word 15
   .word 17
   .word 21
   .word 28
   .word 30
   .word 35
   .word 37
   .word 46
   .word 50
   .word 52
   .word 55
   .word 62
   .word 65
   .word 72
   .word 76
   .word 83
   .word 84
   .word 89
   .word 91
   .word 93
   .word 98
   .word 99
   .word 102
   .word 108
   .word 118
   .word 120
   .word 123
   .word 124
   .word 125
   .word 127
   .word 128
   .word 132
   .word 136
   .word 143
   .word 145
   .word 147
   .word 148
   .word 152
   .word 154
   .word 157
   .word 158
   .word 170
   .word 174
   .word 176
   .word 179
   .word 180
   .word 181
   .word 184
   .word 187
   .word 189
   .word 192
   .word 193
   .word 195
   .word 196
   .word 204
   .word 205
   .word 210
   .word 212
   .word 213
   .word 219
   .word 220
   .word 221
   .word 223
   .word 224
   .word 225
   .word 226
   .word 234
   .word 236
   .word 237
   .word 241
   .word 249
   .word 250
   .word 256
   .word 257
   .word 260
   .word 261
   .word 266
   .word 267
   .word 269
   .word 274
   .word 276
   .word 279
   .word 280
   .word 282
   .word 283
   .word 284
   .word 286
   .word 292
   .word 294
   .word 300
   .word 307
   .word 309
   .word 310
   .word 314
   .word 320
   .word 323
   .word 326
   .word 327
   .word 329
   .word 330
   .word 332
   .word 337
   .word 346
   .word 347
   .word 348
   .word 350
   .word 351
   .word 353
   .word 354
   .word 355
   .word 356
   .word 358
   .word 362
   .word 363
   .word 365
   .word 368
   .word 371
   .word 372
   .word 375
   .word 376
   .word 378
   .word 380
   .word 381
   .word 385
   .word 392
   .word 394
   .word 395
   .word 397
   .word 402
   .word 407
   .word 408
   .word 413
   .word 414
   .word 417
   .word 419
   .word 420
   .word 425
   .word 432
   .word 433
   .word 434
   .word 439
   .word 442
   .word 443
   .word 445
   .word 448
   .word 449
   .word 452
   .word 453
   .word 458
   .word 460
   .word 462
   .word 470
   .word 471
   .word 475
   .word 476
   .word 477
   .word 479
   .word 480
   .word 482
   .word 487
   .word 493
   .word 498
   .word 503
   .word 506
   .word 508
   .word 510
   .word 514
   .word 517
   .word 521
   .word 522
   .word 525
   .word 529
   .word 532
   .word 534
   .word 535
   .word 540
   .word 545
   .word 549
   .word 555
   .word 556
   .word 558
   .word 560
   .word 564
   .word 566
   .word 567
   .word 569
   .word 573
   .word 575
   .word 581
   .word 586
   .word 589
   .word 591
   .word 595
   .word 596
   .word 598
   .word 599
   .word 601
   .word 602
   .word 605
   .word 611
   .word 613
   .word 616
   .word 617
   .word 618
   .word 621
   .word 623
   .word 629
   .word 630
   .word 633
   .word 636
   .word 639
   .word 642
   .word 643
   .word 652
   .word 655
   .word 658
   .word 661
   .word 665
   .word 666
   .word 667
   .word 671
   .word 672
   .word 679
   .word 681
   .word 682
   .word 683
   .word 684
   .word 686
   .word 689
   .word 691
   .word 693
   .word 696
   .word 700
   .word 701
   .word 712
   .word 718
   .word 719
   .word 723
   .word 725
   .word 728
   .word 729
   .word 730
   .word 735
   .word 736
   .word 749
   .word 751
   .word 758
   .word 761
   .word 763
   .word 769
   .word 772
   .word 773
   .word 776
   .word 777
   .word 783
   .word 788
   .word 789
   .word 790
   .word 795
   .word 799
