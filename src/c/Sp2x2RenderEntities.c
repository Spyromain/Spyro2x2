#include "Sp2.h"
#include "Sp2x2.h"

#define MOBYS_SIZE 0x200


typedef struct SpyroMoby
{
    void *data;
    struct SpyroMoby *collision_neighbor;
    void *_maybe_model;
    int position[3];
    unsigned int attack_flags;
    int _a;
    int rotation_matrix[5];
    short collision_id;
    short id;
    short _b;
    signed char sub_id;
    char _c;
    signed char model_id;
    signed char next_model_id;
    signed char key_frame;
    signed char next_key_frame;
    char _d;
    signed char is_animated;
    unsigned char _unknown_mask;
    signed char _unknown_bool_index;
    signed char euler_rotation[4];
    signed char update_state;
    signed char variant_id;
    signed char updated_distance;
    signed char _unknown_bool;
    char _e;
    signed char is_drawn;
    signed char lod_distance;
    char _f;
    signed char gem_value;
    char _g;
    char _h;
    signed char kill_amount;
    signed char color[4];
} SpyroMoby;


void Sp2x2RenderEntities(void)
{
    if (
        sp2_game_state != 0
        && sp2_game_state != 1
        && sp2_game_state != 3
        && sp2_game_state != 4
        && sp2_game_state != 7
        || sp2_is_demo_mode
        || sp2x2_pad[0] < 2
    ) {
        Sp2RenderEntities();
        return;
    }

    Sp2MemSetAlign16((void *)((int)sp2_primitives_end - 0x3000), 0, 0xc00);
    Sp280045bb8();
    Sp2RenderMobs();
    Sp2RenderObjects();
    Sp2RenderMobShadows();

    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(&sp2_spyro_shadow, &sp2x2_spyro_shadow, sizeof sp2_spyro_shadow);
    Sp2x2Swap(&sp2_spyro_flames, &sp2x2_spyro_flames, sizeof sp2_spyro_flames);

    sp2_spyro_flames[154] = 1;
    int tmp[5];
    Sp2MemCpy(tmp, &sp2_spyro_flames[176], sizeof tmp);

    int iVar2 = *(int *)&sp2_spyro[44];
    unsigned char bVar1 = sp2_spyro[30];
    if (*(int *)&sp2_spyro[608] == 0) {
        if (*(int *)&sp2_spyro[44] != 0) {
            ((int *)&sp2_spyro[0])[2] += *(int *)&sp2_spyro[44] * -2;
            int iVar3 = Sp28002d1c0(*(int *)&sp2_spyro[276]);
            sp2_spyro[30] = 0xf4;
            if (iVar3 == 4) {
                sp2_spyro[30] = 0xfa;
            }
            Sp2RenderSpyro();
            iVar3 = *(int *)&sp2_spyro[44];
            *(int *)&sp2_spyro[44] = 0;
            ((int *)&sp2_spyro[0])[2] += iVar3 * 2;
        }
        sp2_spyro[30] = bVar1;
        Sp2RenderSpyro();
        Sp2RenderSpyroShadow();
        if (sp2_spyro_flames[152] != 0) {
            Sp2RenderFlames();
        }
    }
    *(int *)&sp2_spyro[44] = iVar2;

    Sp2MemCpy(&sp2_spyro_flames[176], tmp, sizeof tmp);

    Sp2x2Swap(&sp2_spyro_flames, &sp2x2_spyro_flames, sizeof sp2_spyro_flames);
    Sp2x2Swap(&sp2_spyro_shadow, &sp2x2_spyro_shadow, sizeof sp2_spyro_shadow);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);

    sp2_spyro_flames[154] = 1;
    Sp2MemCpy(tmp, &sp2_spyro_flames[176], sizeof tmp);

    iVar2 = *(int *)&sp2_spyro[44];
    bVar1 = sp2_spyro[30];
    if (*(int *)&sp2_spyro[608] == 0) {
        if (*(int *)&sp2_spyro[44] != 0) {
            ((int *)&sp2_spyro[0])[2] += *(int *)&sp2_spyro[44] * -2;
            int iVar3 = Sp28002d1c0(*(int *)&sp2_spyro[276]);
            sp2_spyro[30] = 0xf4;
            if (iVar3 == 4) {
                sp2_spyro[30] = 0xfa;
            }
            Sp2RenderSpyro();
            iVar3 = *(int *)&sp2_spyro[44];
            *(int *)&sp2_spyro[44] = 0;
            ((int *)&sp2_spyro[0])[2] += iVar3 * 2;
        }
        sp2_spyro[30] = bVar1;
        Sp2RenderSpyro();
        Sp2RenderSpyroShadow();
        if (sp2_spyro_flames[152] != 0) {
            Sp2RenderFlames();
        }
    }
    *(int *)&sp2_spyro[44] = iVar2;

    Sp2MemCpy(&sp2_spyro_flames[176], tmp, sizeof tmp);

    if (sp2_game_state != 0) {
        return;
    }

    static signed char animated_mobys[MOBYS_SIZE] = {0};

    if (sp2x2_current_player == 0) { // Player 1
        Sp2MemSetAlign16(animated_mobys, 0, MOBYS_SIZE);
        int i = 0;
        for (SpyroMoby *moby = sp2_first_moby; moby->update_state != -1; moby++) {
            if (i < MOBYS_SIZE) {
                animated_mobys[i] = moby->is_drawn;
            }
            i += 1;
        }
        if (i > MOBYS_SIZE) {
            printf("=== MEMORY OVERFLOW 0x%x > 0x%x ===\n", i, MOBYS_SIZE);
        }
    }
    else { // Player 2
        int i = 0;
        for (SpyroMoby *moby = sp2_first_moby; moby->update_state != -1; moby++) {
            if (i < MOBYS_SIZE && animated_mobys[i] > moby->is_drawn) {
                moby->is_drawn = animated_mobys[i];
            }
            i += 1;
        }
    }
}
