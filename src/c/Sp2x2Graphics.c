#include "Sp2.h"
#include "Sp2x2.h"

#ifndef SP2X2_DRAW_HEIGHT
#define SP2X2_DRAW_HEIGHT 0x100
#endif

#ifndef SP2X2_DRAW_HMARGIN
#define SP2X2_DRAW_HMARGIN 0
#endif


static void Sp2x2ReducePrimitives(unsigned int *primitives);


void Sp2x2Graphics(void)
{
    static int sp2x2_previous_game_state = -1;
    static int sp2x2_is_screen_split = 0;

    unsigned char r0, g0, b0;

    if (sp2_is_demo_mode || sp2x2_pad[0] < 2) {
        if (sp2x2_is_screen_split) {
            DrawSync(0);
            r0 = sp2_env_1[25];
            g0 = sp2_env_1[26];
            b0 = sp2_env_1[27];
            SetDefDrawEnv(&sp2_env_1[0], 0, SP2X2_DRAW_HMARGIN, 0x200, SP2X2_DRAW_HEIGHT);
            *(short *)&sp2_env_1[8] = 0;
            *(short *)&sp2_env_1[10] = SP2X2_DRAW_HMARGIN - SP2X2_DRAW_HMARGIN;
            sp2_env_1[24] = 1;
            sp2_env_1[25] = r0;
            sp2_env_1[26] = g0;
            sp2_env_1[27] = b0;
            SetDefDrawEnv(&sp2_env_2[0], 0, SP2X2_DRAW_HMARGIN + SP2X2_DRAW_HEIGHT + SP2X2_DRAW_HMARGIN, 0x200, SP2X2_DRAW_HEIGHT);
            *(short *)&sp2_env_2[8] = 0;
            *(short *)&sp2_env_2[10] = SP2X2_DRAW_HMARGIN + SP2X2_DRAW_HEIGHT + SP2X2_DRAW_HMARGIN - SP2X2_DRAW_HMARGIN;
            sp2_env_2[24] = 1;
            sp2_env_2[25] = r0;
            sp2_env_2[26] = g0;
            sp2_env_2[27] = b0;
            // SetGeomOffset(256, 0x80);
            sp2x2_is_screen_split = 0;
        }
        sp2x2_previous_game_state = sp2_game_state;
        Sp2Graphics();
        return;
    }

    if (
        sp2x2_previous_game_state != 0 && sp2_game_state == 0
        || !sp2x2_is_screen_split && sp2_game_state == 0
    ) {
        DrawSync(0);
        r0 = sp2_env_1[25];
        g0 = sp2_env_1[26];
        b0 = sp2_env_1[27];
        SetDefDrawEnv(&sp2_env_1[0], 0, SP2X2_DRAW_HMARGIN, 0x200, SP2X2_DRAW_HEIGHT / 2);
        *(short *)&sp2_env_1[8] = 0;
        *(short *)&sp2_env_1[10] = SP2X2_DRAW_HMARGIN - SP2X2_DRAW_HMARGIN;
        sp2_env_1[24] = 1;
        sp2_env_1[25] = r0;
        sp2_env_1[26] = g0;
        sp2_env_1[27] = b0;
        SetDefDrawEnv(&sp2_env_2[0], 0, SP2X2_DRAW_HMARGIN + SP2X2_DRAW_HEIGHT + SP2X2_DRAW_HMARGIN, 0x200, SP2X2_DRAW_HEIGHT / 2);
        *(short *)&sp2_env_2[8] = 0;
        *(short *)&sp2_env_2[10] = SP2X2_DRAW_HMARGIN + SP2X2_DRAW_HEIGHT + SP2X2_DRAW_HMARGIN - SP2X2_DRAW_HMARGIN;
        sp2_env_2[24] = 1;
        sp2_env_2[25] = r0;
        sp2_env_2[26] = g0;
        sp2_env_2[27] = b0;
        // SetGeomOffset(256, 0x40);
        sp2x2_is_screen_split = 1;
    }
    else if (sp2x2_previous_game_state == 0 && sp2_game_state != 0) {
        DrawSync(0);
        r0 = sp2_env_1[25];
        g0 = sp2_env_1[26];
        b0 = sp2_env_1[27];
        SetDefDrawEnv(&sp2_env_1[0], 0, SP2X2_DRAW_HMARGIN, 0x200, SP2X2_DRAW_HEIGHT);
        *(short *)&sp2_env_1[8] = 0;
        *(short *)&sp2_env_1[10] = SP2X2_DRAW_HMARGIN - SP2X2_DRAW_HMARGIN;
        sp2_env_1[24] = 1;
        sp2_env_1[25] = r0;
        sp2_env_1[26] = g0;
        sp2_env_1[27] = b0;
        SetDefDrawEnv(&sp2_env_2[0], 0, SP2X2_DRAW_HMARGIN + SP2X2_DRAW_HEIGHT + SP2X2_DRAW_HMARGIN, 0x200, SP2X2_DRAW_HEIGHT);
        *(short *)&sp2_env_2[8] = 0;
        *(short *)&sp2_env_2[10] = SP2X2_DRAW_HMARGIN + SP2X2_DRAW_HEIGHT + SP2X2_DRAW_HMARGIN - SP2X2_DRAW_HMARGIN;
        sp2_env_2[24] = 1;
        sp2_env_2[25] = r0;
        sp2_env_2[26] = g0;
        sp2_env_2[27] = b0;
        // SetGeomOffset(256, 0x80);
        sp2x2_is_screen_split = 0;
    }

    sp2x2_previous_game_state = sp2_game_state;

    if (sp2_game_state != 0) {
        if (sp2x2_current_dialogue_player == 1) {
            Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
        }
        Sp2Graphics();
        if (sp2x2_current_dialogue_player == 1) {
            Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
        }
        return;
    }

    if (sp2_no_graphics) {
        return;
    }

    sp2_current_env = (sp2_current_env == &sp2_env_1) ? &sp2_env_2 : &sp2_env_1;

    // - ATTENTE -
    DrawSync(0);
    if (sp2_8006c624) {
        VSync(0);
    }
    sp2_current_vblank_periods = VSync(-1);
    for (int vblank = sp2_current_vblank_periods - sp2_previous_vblank_periods; vblank < 2; vblank = sp2_current_vblank_periods - sp2_previous_vblank_periods) {
        VSync(0);
        sp2_current_vblank_periods = VSync(-1);
    }
    sp2_previous_vblank_periods = VSync(-1);
    // disp_down (env1)
    PutDispEnv(&((unsigned char *)sp2_current_env)[92]);

    // graphic_up1 (prim1)
    sp2_last_primitive = *(void **)&((unsigned char *)sp2_current_env)[112];
    sp2_8006c5d4 = (void *)((int)sp2_primitive_pointers + 0x1000);
    sp2_primitives_end = (void *)((int)sp2_last_primitive + sp2_primitives_size);

    // same camera for the moment
    Sp2AnglesToMatrix((void *)&sp2_camera[68], (void *)&sp2_camera[20], (void *)&sp2_camera[0]);
    // ((short *)&sp2_camera[0])[4] /= 2;
    Sp2Vec3Move((void *)&sp2_camera[52], (void *)&sp2_camera[40]);

    // switch (sp2_game_state) {
    //     case 0:
    //         Sp2GraphicsGame();
    //         break;
    //     case INTRO:
    //         SpyroGraphicIntroWrapper();
    //         break;
    // }
    sp2x2_current_player = 0;
    Sp2GraphicsGame();

    // draw_up1
    sp2_remaining_primitive_space_size = (int)sp2_primitives_end - (int)sp2_last_primitive;
    PutDrawEnv(&((unsigned char *)sp2_current_env)[0]);
    unsigned int *primitives = Sp2GetOTag(0x580);
    Sp2x2ReducePrimitives(primitives);
    DrawOTag(primitives);

    // graphic_up2 (prim2)
    sp2_last_primitive = *(void **)&((unsigned char *)((sp2_current_env == &sp2_env_1) ? &sp2_env_2 : &sp2_env_1))[112];
    sp2_8006c5d4 = (void *)((int)sp2_primitive_pointers + 0x1000);
    sp2_primitives_end = (void *)((int)sp2_last_primitive + sp2_primitives_size);

    Sp2AnglesToMatrix((void *)&sp2x2_camera[68], (void *)&sp2x2_camera[20], (void *)&sp2x2_camera[0]);
    Sp2Vec3Move((void *)&sp2x2_camera[52], (void *)&sp2x2_camera[40]);

    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(&sp2_spyro_flames, &sp2x2_spyro_flames, sizeof sp2_spyro_flames);
    Sp2x2Swap(&sp2_8006eba8, &sp2x2_8006eba8, sizeof sp2_8006eba8);
    Sp2x2Swap(&sp2_is_reticle_displayed, &sp2x2_is_reticle_displayed, sizeof sp2_is_reticle_displayed);

    // switch (sp2_game_state) {
    //     case 0:
    //         Sp2Render(0x3c);
    //         break;
    //     case INTRO:
    //         SpyroGraphicIntroWrapper();
    //         break;
    // }
    // Sp2Render(0x3c);
    sp2x2_current_player = 1;
    Sp2GraphicsGame();
    sp2x2_current_player = 0;

    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(&sp2_spyro_flames, &sp2x2_spyro_flames, sizeof sp2_spyro_flames);
    Sp2x2Swap(&sp2_8006eba8, &sp2x2_8006eba8, sizeof sp2_8006eba8);
    Sp2x2Swap(&sp2_is_reticle_displayed, &sp2x2_is_reticle_displayed, sizeof sp2_is_reticle_displayed);

    // draw_up2
    sp2_remaining_primitive_space_size = (int)sp2_primitives_end - (int)sp2_last_primitive;
    unsigned char tmp[92];
    Sp2MemCpy(&tmp, &((unsigned char *)sp2_current_env)[0], 92);
    *(short *)&tmp[2] += SP2X2_DRAW_HEIGHT / 2;
    *(short *)&tmp[10] += SP2X2_DRAW_HEIGHT / 2;
    PutDrawEnv(&tmp);
    unsigned int *primitives2 = Sp2GetOTag(0x580);
    Sp2x2ReducePrimitives(primitives2);
    DrawOTag(primitives2);
}


static void Sp2x2ReducePrimitives(unsigned int *primitives)
{
    static unsigned char oskour[][2] = {
        {3, 2}, {3, 4}, {4, 2}, {4, 4},
        {3, 4}, {3, 6}, {4, 4}, {4, 6},
        {2, 2}, {0, 0}, {3, 2}, {4, 2},
        {2, 4}, {0, 0}, {3, 4}, {4, 4},
        {1, 1}, {1, 1}, {1, 1}, {1, 1},
        {1, 1}, {1, 1}, {1, 1}, {1, 1},
    };

    for (unsigned int *current = primitives; (current[0] & 0x00ffffff) != 0xffffff; current = (unsigned int *)(0x80000000 | (current[0] & 0x00ffffff))) {
        unsigned char code = (current[1] & 0xff000000) >> 24;
        short *coords = (short *)&current[2];
        if (code < 0x20 || 0x7c < code) {
            continue;
        }
        code -= 0x20;
        unsigned char len = oskour[code / 4][0];
        unsigned char pad = oskour[code / 4][1];
        for (int i = 1; i < 1 + len * pad; i += pad) {
            coords[i] = coords[i] / 2 + SP2X2_DRAW_HMARGIN / 2;
            // if (code == 0x40) coords[i] -= coords[i + 2] / 2;
            // if (code == 0x44) coords[i] -= coords[i + 4] / 2;
        }
    }
}
