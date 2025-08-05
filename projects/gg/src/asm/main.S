.set noreorder

.incbin "rom/SCES_021.04", 0x800, 0x3b00

/* 0x80013b00 */ jal Sp2x2Graphics

.incbin "rom/SCES_021.04", 0x4304, 0x2a4

/* 0x80013da8 */ jal Sp2x2InitPad

.incbin "rom/SCES_021.04", 0x45ac, 0x8

/* 0x80013db4 */ la $a0, Sp2x2VSyncCallback
/* 0x80013db8 */

.incbin "rom/SCES_021.04", 0x45bc, 0x160

/* 0x80013f1c */ jal Sp2x2LoadText

.incbin "rom/SCES_021.04", 0x4720, 0x888 # 0x860

# /* 0x80014780 */ jal Sp2x2UpdatePadQueue

# .incbin "rom/SCES_021.04", 0x4f84, 0x24

/* 0x800147a8 */ sw $s6, 0x34($sp)

.incbin "rom/SCES_021.04", 0x4fac, 0x14

/* 0x800147c0 */ addu $s6, $a0, $zero

.incbin "rom/SCES_021.04", 0x4fc4, 0x4

/* 0x800147c8 */ sw $s5, 0x2c($sp)

.incbin "rom/SCES_021.04", 0x4fcc, 0x9c

/* 0x80014868 */ sw $s0, 0x18($sp)

.incbin "rom/SCES_021.04", 0x506c, 0x160

/* 0x800149cc */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x51d0, 0x5c

/* 0x80014a2c */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x5230, 0x14

/* 0x80014a44 */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x5248, 0x1c

/* 0x80014a64 */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x5268, 0x1c

/* 0x80014a84 */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x5288, 0x40

/* 0x80014ac8 */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x52cc, 0x18

/* 0x80014ae4 */ addu $a0, $s6, $zero

.incbin "rom/SCES_021.04", 0x52e8, 0x48

/* 0x80014b30 */ lw $s6, 0x34($sp)

.incbin "rom/SCES_021.04", 0x5334, 0x4

/* 0x80014b38 */ addiu $sp, $sp, 0x38

.incbin "rom/SCES_021.04", 0x533c, 0x2bbc

/* 0x800176f8 */ jal Sp2x2RenderEntities

.incbin "rom/SCES_021.04", 0x7efc, 0xc4

/* 0x800177c0 */ jal Sp2x2RenderParticles

.incbin "rom/SCES_021.04", 0x7fc4, 0x250

/* 0x80017a14 */ nop
/* 0x80017a18 */ nop
/* 0x80017a1c */ nop
/* 0x80017a20 */ nop

.incbin "rom/SCES_021.04", 0x8224, 0x1bd8

/* 0x800195fc */ jal Sp2x2InitSpyroTwin

.incbin "rom/SCES_021.04", 0x9e00, 0xb0

/* 0x800196b0 */ jal Sp2x2InitSpyroTwin

.incbin "rom/SCES_021.04", 0x9eb4, 0x2fe4

/* 0x8001c698 */ jal Sp2x2InitSpyroTwin

.incbin "rom/SCES_021.04", 0xce9c, 0xa84

/* 0x8001d120 */ jal Sp2x2UpdateMobys
/* 0x8001d124 */ addiu $a0, $zero, 0

.incbin "rom/SCES_021.04", 0xd928, 0xc

/* 0x8001d134 */ jal Sp2x2LogicSpyro

.incbin "rom/SCES_021.04", 0xd938, 0x48

/* 0x8001d180 */ jal Sp2x2LogicCamera

.incbin "rom/SCES_021.04", 0xd984, 0x3c

/* 0x8001d1c0 */ jal Sp2x2LogicController

.incbin "rom/SCES_021.04", 0xd9c4, 0x3c

/* 0x8001d200 */ jal Sp2x2LogicGameWrapper

.incbin "rom/SCES_021.04", 0xda04, 0xc

/* 0x8001d210 */ jal Sp2x2LogicDialogue

.incbin "rom/SCES_021.04", 0xda14, 0x24a0

/* 0x8001f6b4 */ jal Sp2x2UpdateMobys
/* 0x8001f6b8 */ addiu $a0, $zero, 1

.incbin "rom/SCES_021.04", 0xfebc, 0x1d94

/* 0x80021450 */ j Sp2x2StopCutscene
/* 0x80021454 */ nop
/* 0x80021458 */ addiu $sp, $sp, -0x20
/* 0x8002145c */ sw $s2, 0x18($sp)
/* 0x80021460 */ la $s2, sp2_camera + 0x4c # Camera.State
/* 0x80021464 */
/* 0x80021468 */ sw $ra, 0x1c($sp)
/* 0x8002146c */ lw $v1, 0x0($s2)
/* 0x80021470 */ sw $s1, 0x14($sp)
/* 0x80021474 */ bne $v1, $a1, LAB_8002152c
/* 0x80021478 */ sw $s0, 0x10($sp)

.incbin "rom/SCES_021.04", 0x11c7c, 0xb0

LAB_8002152c:

.incbin "rom/SCES_021.04", 0x11d2c, 0xe4

/* 0x80021610 */ j Sp2x280021610
/* 0x80021614 */ nop

.incbin "rom/SCES_021.04", 0x11e18, 0x78

/* 0x80021690 */ j Sp2x2TeleportSpyro
/* 0x80021694 */ nop

.incbin "rom/SCES_021.04", 0x11e98, 0xffa4

/* 0x8003163c */ jal Sp2x2Flame

.incbin "rom/SCES_021.04", 0x21e40, 0x81cc

/* 0x8003980c */ # lui + lw => lw
/* 0x80039810 */ lw $t0, sp2_first_moby
/* 0x80039814 */ sw $s6, 0x88($sp)
/* 0x80039818 */ move $s6, $a0

.incbin "rom/SCES_021.04", 0x2a01c, 0x54

/* 0x80039870 */ lb $t1, 0x48($t0)
/* 0x80039874 */ li $t2, -0x1
/* 0x80039878 */ beq $t1, $t2, LAB_80039a5c
/* 0x8003987c */ move $s5, $t0

.incbin "rom/SCES_021.04", 0x2a080, 0x10

LAB_80039890:

.incbin "rom/SCES_021.04", 0x2a090, 0x1b4

/* 0x80039a44 */ addiu $s5, $s5, 0x58
/* 0x80039a48 */ lb $t1, 0x48($s5)
/* 0x80039a4c */ li $t2, -0x1
/* 0x80039a50 */ bne $t1, $t2, LAB_80039890
/* 0x80039a54 */ nop
/* 0x80039a58 */ nop

LAB_80039a5c:

.incbin "rom/SCES_021.04", 0x2a25c, 0x9798

/* 0x800431f4 */ jr $ra
/* 0x800431f8 */ nop
/* 0x800431fc */ addi $v0, $a0, 0x20
LAB_80043200:
/* 0x80043200 */ sw $zero, 0x0($a0)
/* 0x80043204 */ addi $a0, $a0, 0x8
/* 0x80043208 */ bne $a0, $v0, LAB_80043200
/* 0x8004320c */ sw $zero, -0x4($a0)

.incbin "rom/SCES_021.04", 0x33a10, 0x1270

.set noat
/* 0x80044480 */ addi $a0, $at, 0x7800
/* 0x80044484 */ addi $a1, $at, -0x7800
.set at

.incbin "rom/SCES_021.04", 0x34c88, 0xc

/* 0x80044494 */ addi $a0, $v0, 0x7800
/* 0x80044498 */ addi $a1, $v0, -0x7800

.incbin "rom/SCES_021.04", 0x34c9c, 0x8

/* 0x800444a4 */ addi $a0, $v1, 0x7800
/* 0x800444a8 */ addi $a1, $v1, -0x7800

.incbin "rom/SCES_021.04", 0x34cac, 0xf424 # 0xa554

# /* 0x8004ea00 */ j Sp2x2RenderEntities

# .incbin "rom/SCES_021.04", 0x3f204, 0x4ecc

/* 0x800538d0 */ nop # # lui + addiu => la
/* 0x800538d4 */ nop # la $a2, DAT_8006e12c
/* 0x800538d8 */ sw $ra, 0x28($sp)
/* 0x800538dc */ sw $s0, 0x20($sp)
/* 0x800538e0 */ nop # lw $v0, 0x0($a2)
/* 0x800538e4 */ nop
/* 0x800538e8 */ nop # addiu $v0, $v0, -0x9
/* 0x800538ec */ nop # sltiu $v0, $v0, 0x2
/* 0x800538f0 */ nop # beq $v0, $zero, LAB_80053904
/* 0x800538f4 */ addu $s0, $zero, $zero
/* 0x800538f8 */ nop # addiu $a0, $sp, 0x10
/* 0x800538fc */ j LAB_80053910
/* 0x80053900 */ nop # addiu $a2, $a2, -0x24
LAB_80053904:
/* 0x80053904 */ nop # addiu $a0, $sp, 0x10
/* 0x80053908 */ nop # # lui + addiu => la
/* 0x8005390c */ nop # la $a2, DAT_8006dbf8
LAB_80053910:
/* 0x80053910 */ nop # jal FUN_8001deac
/* 0x80053914 */ nop
/* 0x80053918 */ nop # addiu $a0, $sp, 0x10
/* 0x8005391c */ jal Sp2x2GetSoundVolumeFromDistance # jal FUN_8001da90
/* 0x80053920 */ nop # addiu $a1, $zero, 0x1

.incbin "rom/SCES_021.04", 0x44124 , 0x5b64

/* 0x80059488 */ j VSYNC_OBJ_200
/* 0x8005948c */ sw $ra, 0x18($sp)

.incbin "rom/SCES_021.04", 0x49c90
