#include "Sp2.h"
#include "Sp2x2.h"


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
    unsigned char key_frame_progress_index;
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

static void _Sp2x2UpdateFodderSpawner(SpyroMoby *moby);

void Sp2x2UpdateMobys(int init)
{
    static int shark_player = 0;

    if (sp2_is_demo_mode || sp2x2_pad[0] < 2) {
        if (sp2x2_rayz) {
            Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
            Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);

            int hit_points = *(int *)&sp2_spyro[600];
            *(int *)&sp2_spyro[600] = 0;

            sp2_active_mobys[0] = sp2_sparx;
            sp2_active_mobys[1] = 0;

            sp2_update_mobys_function();

            *(int *)&sp2_spyro[600] = hit_points;

            Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
            Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);
        }
        Sp2800431fc(&sp2_active_synchronised_mobys);
        sp2_update_mobys_function();
        return;
    }

    int previous_game_state = sp2_game_state;

    if (init) {
        unsigned char *rayz = sp2_create_moby_function(0x78, 0);
        sp2x2_rayz = rayz;
        // Sp2800431fc(&sp2_active_synchronised_mobys);
        // sp2_update_mobys_function();
        // return;
    }

    if (*(int *)&sp2x2_spyro[600] > 0 && !sp2x2_rayz) {
        Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
        unsigned char *rayz = sp2_create_moby_function(0x78, 0);
        sp2x2_rayz = rayz;
        Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    }

    // *(int *)&sp2_spyro[600] = 3;
    // *(int *)&sp2x2_spyro[600] = 3;

    // if (sp2_game_state == 0 && sp2x2_current_dialogue_player == 1) {
    //     sp2x2_current_dialogue_player = 0;
    //     Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    //     Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    //     Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);
    // }

    // if (sp2_game_state == 1) {
    //     sp2_update_mobys_function();
    //     return;
    // }

    if (sp2x2_current_dialogue_player == 1) {
        // Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    }

    int i = 0;
    SpyroMoby *moneybags = 0;
    SpyroMoby *dance = 0;
    for (SpyroMoby *moby = sp2_first_moby; moby->update_state != -1; moby++) {
        if (moby->update_state < 0) {
            continue;
        }
        if (moby->id == 0x78) {
            if (moby == sp2_sparx) {
                moby->_unknown_bool = 1;
                sp2_active_mobys[i] = moby;
                i += 1;
            }
            continue;
        }
        if (moby->id == 0x62 && moby->update_state == 3) {
            dance = moby;
            moby->_unknown_bool = 1;
            sp2_active_mobys[i] = moby;
            i += 1;
            continue;
        }
        if (moby->id == 3) {
            _Sp2x2UpdateFodderSpawner(moby);
            continue;
        }
        if (moby->id == 0xa4) {
            if (*(signed char *)moby->data == 2) {
                if (((int *)&sp2_spyro[0])[2] <= 0x7800) {
                    *(int *)&sp2_spyro[580] = 0;
                }
                else {
                    *(int *)&sp2_spyro[580] = 7;
                    Sp2Vec3Move(
                        (int *)&sp2_spyro[584],
                        (int *)&(*(char **)&((char *)moby->data)[0x2c])[0x1c]
                    );
                    *(int *)&sp2_spyro[596] = 0x66d2;
                    ((int *)&sp2_spyro[584])[2] -= 0xc00;
                }

                if (((int *)&sp2x2_spyro[0])[2] <= 0x7800) {
                    *(int *)&sp2x2_spyro[580] = 0;
                }
                else {
                    *(int *)&sp2x2_spyro[580] = 7;
                    Sp2Vec3Move(
                        (int *)&sp2x2_spyro[584],
                        (int *)&(*(char **)&((char *)moby->data)[0x2c])[0x1c]
                    );
                    *(int *)&sp2x2_spyro[596] = 0x66d2;
                    ((int *)&sp2x2_spyro[584])[2] -= 0xc00;
                }
            }
        }
        if (moby->id == 0x149) {
            if (moby->update_state >= 2) {
                moneybags = moby;
                if (shark_player == 0) {
                    shark_player = 2;
                    // printf("Player 2\n");
                }
                if (shark_player != 2) {
                    moby->_unknown_bool = 1;
                    sp2_active_mobys[i] = moby;
                    i += 1;
                }
                continue;
            }
        }
        if (moby->id == 0x406) {
            continue;
        }
        // if (moby->id == 0xa4) {
        //     moby->_unknown_bool = 1;
        //     sp2_active_mobys[i] = moby;
        //     i += 1;
        //     continue;
        // }
        if (moby->id == 0x61 && moby->update_state == 3) {
            if (*(short *)&((char *)moby->data)[0x44] == 3) {
                for (
                    unsigned short *oskour = sp2_8006c6a8[(unsigned char)moby->_unknown_bool_index];
                    ;
                    oskour++
                ) {
                    SpyroMoby *icebuilder = &((SpyroMoby *)sp2_first_moby)[*oskour & 0x7fff];
                    if (
                        icebuilder->update_state == 3
                        && *(short *)&((char *)icebuilder->data)[0x44] == 0
                    ) {
                        icebuilder->update_state = 22;
                        break;
                    }
                    if (icebuilder->update_state == 23) {
                        moby->update_state = 22;
                        *(short *)&((char *)moby->data)[0x44] = 0;
                        break;
                    }
                    if ((short)*oskour < 0) {
                        break;
                    }
                }
            }
            else if (*(short *)&((char *)moby->data)[0x44] == 5) {
                for (
                    unsigned short *oskour = sp2_8006c6a8[(unsigned char)moby->_unknown_bool_index];
                    ;
                    oskour++
                ) {
                    SpyroMoby *icebuilder = &((SpyroMoby *)sp2_first_moby)[*oskour & 0x7fff];
                    if (icebuilder->update_state == 23) {
                        moby->update_state = 22;
                        *(short *)&((char *)moby->data)[0x44] = 0;
                        break;
                    }
                    if ((short)*oskour < 0) {
                        break;
                    }
                }
            }
        }
        if (
            moby->id == 0x2af
            && moby->update_state == 99
            // && moby->variant_id == 1
            && ((signed char *)moby->data)[6] == 3
        ) {
            // *(int *)&sp2_spyro[0x1d4] = 0x400;
            *(int *)&sp2x2_spyro[0x1d4] = 0x400;
        }
        if (
            moby->id == 0x2af
            && moby->update_state != 100
            && ((signed char *)moby->data)[6] == 4
        ) {
            if (*(int *)&sp2x2_spyro[0x1d4] != 0) {
                // *(int *)&sp2_spyro[0x1d4] = 0;
                *(int *)&sp2x2_spyro[0x1d4] = 0;


                *(int *)&sp2_spyro[580] = 5;
                ((int *)&sp2_spyro[584])[0] = ((int *)&(*(char **)&((char *)moby->data)[24])[0xc])[0];
                ((int *)&sp2_spyro[584])[1] = ((int *)&(*(char **)&((char *)moby->data)[24])[0xc])[1];
                *(int *)&sp2_spyro[596] = 0x8000;
                ((int *)&sp2_spyro[584])[2] = ((int *)&(*(char **)&((char *)moby->data)[24])[0xc])[2] + 0xc00;

                *(int *)&sp2_spyro[600] = *(int *)&sp2_level_extras[0];
                if (!sp2_sparx) {
                    sp2_sparx = sp2_create_moby_function(0x78, moby);
                }

                *(int *)&sp2_spyro[456] = 1;
                *(int *)&sp2_spyro[256] = 100000;
                Sp2Vec3Move(
                    (int *)&sp2_spyro[0],
                    (int *)&(*(char **)&((char *)moby->data)[32])[0xc]
                );
                int *pVar23 = *(int **)&((char *)moby->data)[32];
                int iVar23 = Sp2Atan2(pVar23[7] - pVar23[3], pVar23[8] - pVar23[4], 0);
                ((int *)&sp2_spyro[100])[2] = iVar23 << 4;
                *(unsigned int *)&sp2_spyro[572] = 33;
                ((int *)&sp2_spyro[100])[1] = 0;
                *(unsigned int *)&sp2_spyro[524] = 0x10000080;


                *(int *)&sp2x2_spyro[580] = 5;
                ((int *)&sp2x2_spyro[584])[0] = ((int *)&(*(char **)&((char *)moby->data)[24])[0xc])[0];
                ((int *)&sp2x2_spyro[584])[1] = ((int *)&(*(char **)&((char *)moby->data)[24])[0xc])[1];
                *(int *)&sp2x2_spyro[596] = 0x8000;
                ((int *)&sp2x2_spyro[584])[2] = ((int *)&(*(char **)&((char *)moby->data)[24])[0xc])[2] + 0xc00;

                *(int *)&sp2x2_spyro[600] = *(int *)&sp2_level_extras[0];
                if (!sp2x2_rayz) {
                    sp2x2_rayz = sp2_create_moby_function(0x78, moby);
                }

                *(int *)&sp2x2_spyro[456] = 1;
                *(int *)&sp2x2_spyro[256] = 100000;
                Sp2Vec3Move(
                    (int *)&sp2x2_spyro[0],
                    (int *)&(*(char **)&((char *)moby->data)[32])[0xc]
                );
                int *pVar24 = *(int **)&((char *)moby->data)[32];
                int iVar24 = Sp2Atan2(pVar24[7] - pVar24[3], pVar24[8] - pVar24[4], 0);
                ((int *)&sp2x2_spyro[100])[2] = iVar24 << 4;
                *(unsigned int *)&sp2x2_spyro[572] = 33;
                ((int *)&sp2x2_spyro[100])[1] = 0;
                *(unsigned int *)&sp2x2_spyro[524] = 0x10000080;
            }
            *(int *)&sp2_spyro[0x1d8] = 8;
            *(int *)&sp2_spyro[0x1c4] = 8;

            *(int *)&sp2x2_spyro[0x1d8] = 8;
            *(int *)&sp2x2_spyro[0x1c4] = 8;
        }
        if ((0x2db <= moby->id && moby->id <= 0x2de) || moby->id == 0x424/* || moby->id == 0x2af*/ || moby->id == 0x41d || (moby->id == 0x29f && *(signed char *)moby->data == 3) || moby->id == 0x41c || (moby->id == 0x29f && *(signed char *)moby->data == 4)) {
            moby->_unknown_bool = 1;
            sp2_active_mobys[i] = moby;
            i += 1;
            continue;
        }
        int distances[3];
        Sp2Vec3Sub(distances, (int *)sp2_spyro, moby->position);
        int distance_p1 = Sp2Hypot(distances, 1);
        Sp2Vec3Sub(distances, (int *)sp2x2_spyro, moby->position);
        int distance_p2 = Sp2Hypot(distances, 1);
        if (distance_p1 <= distance_p2) {
            moby->_unknown_bool = 1;
            sp2_active_mobys[i] = moby;
            i += 1;
            if (
                moby->id == 0x23d && moby->update_state == 1
                || moby->id == 0x153 && moby->update_state == 6
                || moby->id == 0x34 && moby->update_state == 1
                || moby->id == 0x3f && moby->update_state == 1
                || moby->id == 0x12b && moby->update_state == 1
                || moby->id == 0x91 && moby->update_state == 1
                || moby->id == 0x249 && moby->update_state == 1
                || moby->id == 0x198 && moby->update_state == 1
                || moby->id == 0xab && moby->update_state == 1
                || moby->id == 0x27a && moby->update_state == 1
                || moby->id == 0x299 && moby->update_state == 1
            ) {
                Sp2Vec3Move(moby->position, (int *)&sp2_spyro[0]);
            }
        }
    }
    sp2_active_mobys[i] = 0;

    sp2_update_mobys_function();
    if (moneybags && moneybags->update_state < 2) {
        shark_player = 0;
        // printf("End1\n");
    }
    if (dance) {
        dance->update_state = 3;
    }

    if (previous_game_state != sp2_game_state) {
        if (sp2x2_current_dialogue_player == 1) {
            // Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
        }
        return;
    }

    // if (sp2_game_state != 0) {
    //     if (sp2_game_state == 1) {
    //         sp2x2_current_dialogue_player = 0;
    //     }
    //     return;
    // }

    i = 0;
    moneybags = 0;
    for (SpyroMoby *moby = sp2_first_moby; moby->update_state != -1; moby++) {
        if (moby->update_state < 0) {
            continue;
        }
        if (moby->id == 0x78) {
            if (moby == sp2x2_rayz) {
                moby->_unknown_bool = 1;
                sp2_active_mobys[i] = moby;
                i += 1;
            }
            continue;
        }
        if (moby == dance) {
            moby->_unknown_bool = 1;
            sp2_active_mobys[i] = moby;
            i += 1;
            continue;
        }
        if (moby->id == 0x149) {
            if (moby->update_state >= 2) {
                moneybags = moby;
                if (shark_player == 0) {
                    shark_player = sp2x2_current_dialogue_player + 1;
                    // printf("Player %d\n", shark_player);
                }
                if (shark_player != 1) {
                    // printf("Added!\n");
                    moby->_unknown_bool = 1;
                    sp2_active_mobys[i] = moby;
                    i += 1;
                }
                continue;
            }
        }
        if (moby->id == 3 || moby->id == 0x406 || (0x2db <= moby->id && moby->id <= 0x2de) || moby->id == 0x424/* || moby->id == 0x2af*/ || moby->id == 0x41d || (moby->id == 0x29f && *(signed char *)moby->data == 3) || moby->id == 0x41c || (moby->id == 0x29f && *(signed char *)moby->data == 4)) {
            continue;
        }
        // if (moby->id == 0xa4) {
        //     moby->_unknown_bool = 1;
        //     sp2_active_mobys[i] = moby;
        //     i += 1;
        //     continue;
        // }
        int distances[3];
        Sp2Vec3Sub(distances, (int *)sp2_spyro, moby->position);
        int distance_p1 = Sp2Hypot(distances, 1);
        Sp2Vec3Sub(distances, (int *)sp2x2_spyro, moby->position);
        int distance_p2 = Sp2Hypot(distances, 1);
        if (distance_p2 < distance_p1) {
            moby->_unknown_bool = 1;
            sp2_active_mobys[i] = moby;
            i += 1;
            if (
                moby->id == 0x23d && moby->update_state == 1
                || moby->id == 0x153 && moby->update_state == 6
                || moby->id == 0x34 && moby->update_state == 1
                || moby->id == 0x3f && moby->update_state == 1
                || moby->id == 0x12b && moby->update_state == 1
                || moby->id == 0x91 && moby->update_state == 1
                || moby->id == 0x249 && moby->update_state == 1
                || moby->id == 0x198 && moby->update_state == 1
                || moby->id == 0xab && moby->update_state == 1
                || moby->id == 0x27a && moby->update_state == 1
                || moby->id == 0x299 && moby->update_state == 1
            ) {
                Sp2Vec3Move(moby->position, (int *)&sp2x2_spyro[0]);
            }
        }
    }
    sp2_active_mobys[i] = 0;

    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);
    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);

    sp2_update_mobys_function();
    if (moneybags && moneybags->update_state < 2) {
        shark_player = 0;
        // printf("End2\n");
    }

    // if (sp2_game_state == 1) {
    //     sp2x2_current_dialogue_player = 1;
    //     Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    //     return;
    // }

    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_sparx, &sp2x2_rayz, sizeof sp2_sparx);
    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);

    if (sp2x2_current_dialogue_player == 1) {
        // Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    }

    if (previous_game_state != sp2_game_state) {
        if (sp2_game_state == 1) {
            sp2x2_current_dialogue_player = 1;
            // Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
        }
    }

    return;

    for (void **moby = sp2_active_mobys; *moby != 0; moby++) {
        if (((unsigned char *)*moby)[72] >= 0x80) {
            continue;
        }

        if (*(short *)&((unsigned char *)*moby)[54] == 1) {
            int distance = Sp2FastHypot2d((int *)&((unsigned char *)*moby)[12], (int *)&sp2x2_spyro[0]);

            if (
                distance < 0x200
                && -0x180 < ((int *)&sp2x2_spyro[0])[2] - ((int *)&((unsigned char *)*moby)[12])[2]
                && ((int *)&sp2x2_spyro[0])[2] - ((int *)&((unsigned char *)*moby)[12])[2] < 0x200
            ) {
                Sp2UpdateMoby(*moby, 0x4);
                sp2_create_particles_function(4, 0xc, *moby, ((unsigned char *)*moby)[73]);
                Sp2CollectGem(*moby);
                Sp2PlayMobySound(*moby, 0, 0);
                Sp2RemoveMoby(*moby);
            }
        }
        else if (*(short *)&((unsigned char *)*moby)[54] == 0x400) {
            if (*(int *)&sp2x2_spyro[88] == 6) {
                continue;
            }

            int distances[3];
            Sp2Vec3Sub(distances, (int *)&sp2x2_spyro[0], (int *)&((unsigned char *)*moby)[12]);
            int distance = Sp2Hypot(distances, 0);

            unsigned char *data = *(void **)&((unsigned char *)*moby)[0];
            if (
                *(int *)&sp2x2_spyro[80] != 18
                && distance < *(int *)&data[4]
                && -0x400 < distances[2] && distances[2] < *(int *)&data[0]
                && ((int *)&sp2x2_spyro[0])[2] + 0xc00 < ((int *)&((unsigned char *)*moby)[12])[2] + *(int *)&data[0]
            ) {
                *(int *)&sp2x2_spyro[524] = 0x10000020;
                *(void **)&sp2x2_spyro[536] = *moby;
            }
        }
    }
}


static void _Sp2x2UpdateFodderSpawner(SpyroMoby *moby)
{
    char *data = moby->data;

    Sp2Vec3Move(moby->position, (int *)&sp2_spyro[0]);

    if (Sp2SubstractTicks((int *)&data[4], 4) == 0) {
        return;
    }

    int iVar4 = *(int *)&data[8];
    if (iVar4 > 5) {
        iVar4 = (iVar4 * 5 + 3) / 6;
    }
    *(int *)&data[4] = iVar4;

    for (
        SpyroMoby *fodder = sp2_first_moby;
        fodder < (SpyroMoby *)sp2_first_dynamic_moby;
        fodder++
    ) {
        if (fodder->id != *(int *)&data[0] || fodder->update_state >= 0) {
            continue;
        }

        char *fodder_data = fodder->data;

        int distance_p1 = Sp2FastHypot2d((int *)&sp2_spyro[0], (int *)&fodder_data[0]);
        int distance_p2 = Sp2FastHypot2d((int *)&sp2x2_spyro[0], (int *)&fodder_data[0]);
        if (distance_p1 <= 0x6000 || distance_p2 <= 0x6000) {
            continue;
        }

        Sp2Vec3Move(fodder->position, (int *)&fodder_data[0]);
        Sp2StartMoby(fodder);
        fodder->attack_flags = 0;
        fodder->_g = 0;
        fodder->update_state = 0;
        fodder->_unknown_mask = 0;
        fodder->model_id = 0;
        fodder->next_model_id = 0;
        fodder->key_frame = 0;
        fodder->next_key_frame = 1;
        fodder->euler_rotation[0] = 0;
        fodder->euler_rotation[1] = 0;
        unsigned char truc = **(unsigned char **)&((char *)sp2_models[fodder->id])[60];
        fodder->key_frame_progress_index = (truc > 1) ? 0x30 : 0;
        Sp28003a3ec(fodder);
        Sp280043e18(fodder);
        break;
    }
}
