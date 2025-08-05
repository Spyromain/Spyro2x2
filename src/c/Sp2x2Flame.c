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

SpyroMoby *Sp2x2Flame(
    int *param_1,
    unsigned int param_2,
    unsigned int param_3,
    unsigned int *param_4,
    unsigned int attack_flags,
    SpyroMoby *ignore_moby
)
{
    int distances[3];
    Sp2Vec3Sub(distances, (int *)&sp2x2_spyro[0], param_1);
    int distance = Sp2Hypot(distances, 1);
    // printf("%d %d\n", distance, param_2);
    if (distance <= param_2) {
        *(int *)&sp2x2_spyro[36] |= 1;
    }

    return Sp2Flame(param_1, param_2, param_3, param_4, attack_flags, ignore_moby);
}
