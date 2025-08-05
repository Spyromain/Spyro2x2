#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2InitSpyroTwin(void)
{
    int hit_points = *(int *)&sp2x2_spyro[600];

    Sp2MemCpy(&sp2x2_camera, sp2_camera, sizeof sp2_camera);
    Sp2MemCpy(&sp2x2_spyro, sp2_spyro, sizeof sp2_spyro);
    Sp2MemCpy(&sp2x2_spyro_shadow, sp2_spyro_shadow, sizeof sp2_spyro_shadow);
    Sp2MemCpy(&sp2x2_spyro_flames, sp2_spyro_flames, sizeof sp2_spyro_flames);

    *(int *)&sp2x2_spyro[600] = hit_points;

    // if (!sp2x2_rayz) {
    //     unsigned char *rayz = sp2_create_moby_function(0x78, 0);
    //     // rayz[80] = 1;
    //     sp2x2_rayz = rayz;
    // }

    if (sp2_game_state == 8) {
        Sp2LogicSpyro();
    }
    else {
        Sp2LogicGame(0x7b);
    }
}
