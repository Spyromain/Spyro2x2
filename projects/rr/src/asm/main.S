.set noreorder

.incbin "rom/SCUS_944.25", 0x800, 0x1afc

/* 0x80011afc */ jal Sp2x2Graphics

.incbin "rom/SCUS_944.25", 0x2300, 0x2a0

/* 0x80011da0 */ jal Sp2x2InitPad

.incbin "rom/SCUS_944.25", 0x25a4, 0x8

/* 0x80011dac */ la $a0, Sp2x2VSyncCallback
/* 0x80011db0 */

.incbin "rom/SCUS_944.25", 0x25b4, 0x160

/* 0x80011f14 */ jal Sp2x2LoadText

.incbin "rom/SCUS_944.25", 0x2718, 0x814 # 0x7ec

# /* 0x80012704 */ jal Sp2x2UpdatePadQueue

# .incbin "rom/SCUS_944.25", 0x2f08, 0x24

/* 0x8001272c */ sw $s6, 0x34($sp)

.incbin "rom/SCUS_944.25", 0x2f30, 0x14

/* 0x80012744 */ addu $s6, $a0, $zero

.incbin "rom/SCUS_944.25", 0x2f48, 0x4

/* 0x8001274c */ sw $s5, 0x2c($sp)

.incbin "rom/SCUS_944.25", 0x2f50, 0x9c

/* 0x800127ec */ sw $s0, 0x18($sp)

.incbin "rom/SCUS_944.25", 0x2ff0, 0x160

/* 0x80012950 */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x3154, 0x5c

/* 0x800129b0 */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x31b4, 0x14

/* 0x800129c8 */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x31cc, 0x1c

/* 0x800129e8 */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x31ec, 0x1c

/* 0x80012a08 */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x320c, 0x40

/* 0x80012a4c */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x3250, 0x18

/* 0x80012a68 */ addu $a0, $s6, $zero

.incbin "rom/SCUS_944.25", 0x326c, 0x48

/* 0x80012ab4 */ lw $s6, 0x34($sp)

.incbin "rom/SCUS_944.25", 0x32b8, 0x4

/* 0x80012abc */ addiu $sp, $sp, 0x38

.incbin "rom/SCUS_944.25", 0x32c0, 0x2b04

/* 0x800155c4 */ jal Sp2x2RenderEntities

.incbin "rom/SCUS_944.25", 0x5dc8, 0xc4

/* 0x8001568c */ jal Sp2x2RenderParticles

.incbin "rom/SCUS_944.25", 0x5e90, 0x250

/* 0x800158e0 */ nop
/* 0x800158e4 */ nop
/* 0x800158e8 */ nop
/* 0x800158ec */ nop

.incbin "rom/SCUS_944.25", 0x60f0, 0x1bcc

/* 0x800174bc */ jal Sp2x2InitSpyroTwin

.incbin "rom/SCUS_944.25", 0x7cc0, 0xb0

/* 0x80017570 */ jal Sp2x2InitSpyroTwin

.incbin "rom/SCUS_944.25", 0x7d74, 0x30d4

/* 0x8001a648 */ jal Sp2x2InitSpyroTwin

.incbin "rom/SCUS_944.25", 0xae4c, 0xa64

/* 0x8001b0b0 */ jal Sp2x2UpdateMobys
/* 0x8001b0b4 */ addiu $a0, $zero, 0

.incbin "rom/SCUS_944.25", 0xb8b8, 0xc

/* 0x8001b0c4 */ jal Sp2x2LogicSpyro

.incbin "rom/SCUS_944.25", 0xb8c8, 0x48

/* 0x8001b110 */ jal Sp2x2LogicCamera

.incbin "rom/SCUS_944.25", 0xb914, 0x3c

/* 0x8001b150 */ jal Sp2x2LogicController

.incbin "rom/SCUS_944.25", 0xb954, 0x3c

/* 0x8001b190 */ jal Sp2x2LogicGameWrapper

.incbin "rom/SCUS_944.25", 0xb994, 0xc

/* 0x8001b1a0 */ jal Sp2x2LogicDialogue

.incbin "rom/SCUS_944.25", 0xb9a4, 0x23c4

/* 0x8001d568 */ jal Sp2x2UpdateMobys
/* 0x8001d56c */ addiu $a0, $zero, 1

.incbin "rom/SCUS_944.25", 0xdd70, 0x1d74

/* 0x8001f2e4 */ j Sp2x2StopCutscene
/* 0x8001f2e8 */ nop
/* 0x8001f2ec */ addiu $sp, $sp, -0x20
/* 0x8001f2f0 */ sw $s2, 0x18($sp)
/* 0x8001f2f4 */ la $s2, sp2_camera + 0x4c # Camera.State
/* 0x8001f2f8 */
/* 0x8001f2fc */ sw $ra, 0x1c($sp)
/* 0x8001f300 */ lw $v1, 0x0($s2)
/* 0x8001f304 */ sw $s1, 0x14($sp)
/* 0x8001f308 */ bne $v1, $a1, LAB_8001f3c0
/* 0x8001f30c */ sw $s0, 0x10($sp)

.incbin "rom/SCUS_944.25", 0xfb10, 0xb0

LAB_8001f3c0:

.incbin "rom/SCUS_944.25", 0xfbc0, 0xe4

/* 0x8001f4a4 */ j Sp2x280021610
/* 0x8001f4a8 */ nop

.incbin "rom/SCUS_944.25", 0xfcac, 0x78

/* 0x8001f524 */ j Sp2x2TeleportSpyro
/* 0x8001f528 */ nop

.incbin "rom/SCUS_944.25", 0xfd2c, 0xffc8

/* 0x8002f4f4 */ jal Sp2x2Flame

.incbin "rom/SCUS_944.25", 0x1fcf8, 0x8114

/* 0x8003760c */ # lui + lw => lw
/* 0x80037610 */ lw $t0, sp2_first_moby
/* 0x80037614 */ sw $s6, 0x88($sp)
/* 0x80037618 */ move $s6, $a0

.incbin "rom/SCUS_944.25", 0x27e1c, 0x54

/* 0x80037670 */ lb $t1, 0x48($t0)
/* 0x80037674 */ li $t2, -0x1
/* 0x80037678 */ beq $t1, $t2, LAB_8003785c
/* 0x8003767c */ move $s5, $t0

.incbin "rom/SCUS_944.25", 0x27e80, 0x10

LAB_80037690:

.incbin "rom/SCUS_944.25", 0x27e90, 0x1b4

/* 0x80037844 */ addiu $s5, $s5, 0x58
/* 0x80037848 */ lb $t1, 0x48($s5)
/* 0x8003784c */ li $t2, -0x1
/* 0x80037850 */ bne $t1, $t2, LAB_80037690
/* 0x80037854 */ nop
/* 0x80037858 */ nop

LAB_8003785c:

.incbin "rom/SCUS_944.25", 0x2805c, 0x9638

/* 0x80040e94 */ jr $ra
/* 0x80040e98 */ nop
/* 0x80040e9c */ addi $v0, $a0, 0x20
LAB_80040ea0:
/* 0x80040ea0 */ sw $zero, 0x0($a0)
/* 0x80040ea4 */ addi $a0, $a0, 0x8
/* 0x80040ea8 */ bne $a0, $v0, LAB_80040ea0
/* 0x80040eac */ sw $zero, -0x4($a0)

.incbin "rom/SCUS_944.25", 0x316b0, 0x1270

.set noat
/* 0x80042120 */ addi $a0, $at, 0x7800
/* 0x80042124 */ addi $a1, $at, -0x7800
.set at

.incbin "rom/SCUS_944.25", 0x32928, 0xc

/* 0x80042134 */ addi $a0, $v0, 0x7800
/* 0x80042138 */ addi $a1, $v0, -0x7800

.incbin "rom/SCUS_944.25", 0x3293c, 0x8

/* 0x80042144 */ addi $a0, $v1, 0x7800
/* 0x80042148 */ addi $a1, $v1, -0x7800

.incbin "rom/SCUS_944.25", 0x3294c, 0xf408 # 0xa518

# /* 0x8004c664 */ j Sp2x2RenderEntities

# .incbin "rom/SCUS_944.25", 0x3ce68, 0x4eec

/* 0x80051554 */ nop # # lui + addiu => la
/* 0x80051558 */ nop # la $a2, DAT_80067ed0
/* 0x8005155c */ sw $ra, 0x28($sp)
/* 0x80051560 */ sw $s0, 0x20($sp)
/* 0x80051564 */ nop # lw $v0, 0x0($a2)
/* 0x80051568 */ nop
/* 0x8005156c */ nop # addiu $v0, $v0, -0x9
/* 0x80051570 */ nop # sltiu $v0, $v0, 0x2
/* 0x80051574 */ nop # beq $v0, $zero, LAB_80051588
/* 0x80051578 */ addu $s0, $zero, $zero
/* 0x8005157c */ nop # addiu $a0, $sp, 0x10
/* 0x80051580 */ j LAB_80051594
/* 0x80051584 */ nop # addiu $a2, $a2, -0x24
LAB_80051588:
/* 0x80051588 */ nop # addiu $a0, $sp, 0x10
/* 0x8005158c */ nop # # lui + addiu => la
/* 0x80051590 */ nop # la $a2, DAT_80069ff0
LAB_80051594:
/* 0x80051594 */ nop # jal FUN_8001be00
/* 0x80051598 */ nop
/* 0x8005159c */ nop # addiu $a0, $sp, 0x10
/* 0x800515a0 */ jal Sp2x2GetSoundVolumeFromDistance # jal FUN_8001ba20
/* 0x800515a4 */ nop # addiu $a1, $zero, 0x1

.incbin "rom/SCUS_944.25", 0x41da8 , 0x7af4

/* 0x8005909c */ j VSYNC_OBJ_200
/* 0x800590a0 */ sw $ra, 0x18($sp)

.incbin "rom/SCUS_944.25", 0x498a4
