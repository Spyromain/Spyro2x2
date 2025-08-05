#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2LogicDialogue(void)
{
    if (sp2_is_demo_mode || sp2x2_pad[0] < 2) {
        Sp2LogicDialogue();
        return;
    }

    if (sp2x2_current_dialogue_player == 1) {
        Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
        Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);
        Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
        Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
        unsigned char skin_color = sp2_extras[20];
        sp2_extras[20] = sp2x2_skin_color;
        sp2x2_skin_color = skin_color;
    }

    *(int *)&sp2x2_spyro[524] |= 0x10000002;
    Sp2LogicDialogue();

    if (sp2x2_current_dialogue_player == 1) {
        Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
        Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);
        Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
        Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
        unsigned char skin_color = sp2_extras[20];
        sp2_extras[20] = sp2x2_skin_color;
        sp2x2_skin_color = skin_color;
    }

    if (sp2_game_state != 1) {
        sp2x2_current_dialogue_player = 0;
        // Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    }
}
