INCLUDE "symbols.ld"

MEMORY {
    BIOS2 : ORIGIN = 0x8000C000, LENGTH = 0x1F00
    LOADER : ORIGIN = 0x8000B070, LENGTH = 0x800
    BIOS3 : ORIGIN = 0x8000E400, LENGTH = 0x1C00
    RAM : ORIGIN = 0x80010000, LENGTH = 0x1F0000
}

SECTIONS
{
    .header : AT(0) {
        build/src/asm/header.o(.text)
        build/src/c/Sp2x2LoadText.o(.text)
        build/src/c/Sp2x2Swap.o(.text)
        build/src/c/Sp2x2InitPad.o(.text)
        build/src/c/Sp2x2VSyncCallback.o(.text)
        build/src/c/Sp2x2RenderParticles.o(.bss)
        build/src/c/Sp2x280021610.o(.text)
        build/src/c/Sp2x2Flame.o(.rodata*)
        build/src/c/Sp2x2Flame.o(.text)
        build/src/c/Sp2x2StopCutscene.o(.text)
        build/src/c/Sp2x2InitSpyroTwin.o(.text)
    } > LOADER

    .main : AT(0x800) {
        build/src/asm/main.o(.text)
    } > RAM

    .wad71 : {
        build/src/c/Sp2x2RenderParticles.o(.rodata*)
        build/src/c/Sp2x2Graphics.o(.rodata*)
        build/src/c/Sp2x2LogicSpyro.o(.text)
        build/src/c/Sp2x2LogicController.o(.text)
        build/src/c/Sp2x2LogicCamera.o(.text)
        build/src/c/Sp2x2Graphics.o(.text)
        build/src/c/Sp2x2Graphics.o(.data)
        build/src/c/Sp2x2TeleportSpyro.o(.text)
        build/src/c/Sp2x2RenderParticles.o(.text)
        build/src/c/Sp2x2LogicDialogue.o(.text)
        build/src/c/Sp2x2Graphics.o(.bss)
        build/src/c/Sp2x2.o(.bss)
    } > BIOS2

    .wad73 : {
        build/src/c/Sp2x2RenderEntities.o(.rodata*)
        build/src/c/Sp2x2UpdateMobys.o(.rodata*)
        build/src/c/Sp2x2UpdateMobys.o(.text)
        build/src/c/Sp2x2GetSoundVolumeFromDistance.o(.text)
        build/src/c/Sp2x2RenderEntities.o(.text)
        build/src/c/Sp2x2LogicGameWrapper.o(.text)
        build/src/c/Sp2x2UpdateMobys.o(.bss)
        build/src/c/Sp2x2RenderEntities.o(.bss)
    } > BIOS3
}
