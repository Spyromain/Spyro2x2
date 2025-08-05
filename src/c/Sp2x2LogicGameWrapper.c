#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2LogicGameWrapper(void)
{
    if (sp2_is_demo_mode || sp2x2_pad[0] < 2) {
        Sp2LogicGameWrapper();
        return;
    }

    if (*(int *)&sp2x2_pad[52] & 0x100) {
        *(int *)&sp2_hud[48] = 0x4b;
    }

    int direct_buttons[] = {*(int *)&sp2_pad[52], *(int *)&sp2x2_pad[52]};
    int held_buttons[] = {*(int *)&sp2_pad[48], *(int *)&sp2x2_pad[48]};
    unsigned char *skin_colors[] = {&sp2_extras[20], &sp2x2_skin_color};

    for (int i = 0; i < 2; i++) {
        if (direct_buttons[i] & 0x100) {
            *skin_colors[i] = 0;
        }
        else if (held_buttons[i] & 0x100) {
            if (held_buttons[i] & 0x20) {
                *skin_colors[i] = 1;
            }
            else if (held_buttons[i] & 0x40) {
                *skin_colors[i] = 2;
            }
            else if (held_buttons[i] & 0x80) {
                *skin_colors[i] = 3;
            }
            else if (held_buttons[i] & 0x10) {
                *skin_colors[i] = 4;
            }
            else if (held_buttons[i] & 0x1000) {
                *skin_colors[i] = 5;
            }
            else if (held_buttons[i] & 0x4000) {
                *skin_colors[i] = 6;
            }
        }
    }

    Sp2LogicGameWrapper();

    if (
        *(int *)&sp2x2_pad[52] & 0x800
        && !sp2_display_letterbox
        && sp2_letterbox_height == 0
        && sp2_fading_alpha == 0
        && *(int *)&sp2x2_spyro[600] >= 0
        && sp2_game_state == 0
    ) {
        Sp2LogicGuidebookRequested();
    }
}
