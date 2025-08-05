#include "Sp2.h"

#include "Sp2x2.h"

#ifndef SP2X2_BIOS2_WAD
#define SP2X2_BIOS2_WAD 71
#endif

#ifndef SP2X2_BIOS3_WAD
#define SP2X2_BIOS3_WAD 73
#endif

#define SP2X2_BIOS2_ADDR (void *)0x8000c000
#define SP2X2_BIOS3_ADDR (void *)0x8000e400


void Sp2x2LoadText(void)
{
    unsigned char tmp[0x100];
    Sp2MemCpy(tmp, (void *)0x8000df00, sizeof tmp);
    Sp2ReadCd(SP2_WAD_WAD_SECTOR, SP2X2_BIOS2_ADDR, sp2_wad_header[SP2X2_BIOS2_WAD][1], sp2_wad_header[SP2X2_BIOS2_WAD][0]);
    Sp2MemCpy((void *)0x8000df00, tmp, sizeof tmp);

    unsigned char tmp2[0x400];
    Sp2MemCpy(tmp2, (void *)0x80010000, sizeof tmp2);
    Sp2ReadCd(SP2_WAD_WAD_SECTOR, SP2X2_BIOS3_ADDR, sp2_wad_header[SP2X2_BIOS3_WAD][1], sp2_wad_header[SP2X2_BIOS3_WAD][0]);
    Sp2MemCpy((void *)0x80010000, tmp2, sizeof tmp2);

    *(int *)&sp2x2_spyro[600] = *(int *)&sp2_level_extras[0];

    // Sp2x2HelloWorld();
    Sp2IntroInit();
    // Sp2InitNewGame();
    // Sp2IntroLoadChapterBook();
    // Sp2InitChapterBook(3);
}
