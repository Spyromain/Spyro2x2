#include "Sp2.h"
#include "Sp2x2.h"


int Sp2x2GetSoundVolumeFromDistance(int sound_id, int *sound_position)
{
    int *player_position;
    if (*(int *)&sp2_camera[76] - 9 < 2) {
        player_position = (int *)&sp2_camera[40];
    }
    else {
        player_position = (int *)&sp2_spyro[0];
    }

    int distances[3];
    Sp2Vec3Sub(distances, sound_position, player_position);
    int dist = Sp2Hypot(distances, 1);

    if (sp2_is_demo_mode || sp2_game_state > 1 || sp2x2_pad[0] < 2) {
        return dist;
    }

    if (*(int *)&sp2x2_camera[76] - 9 < 2) {
        player_position = (int *)&sp2x2_camera[40];
    }
    else {
        player_position = (int *)&sp2x2_spyro[0];
    }

    Sp2Vec3Sub(distances, sound_position, player_position);
    int dist2 = Sp2Hypot(distances, 1);

    if (dist2 < dist) {
        dist = dist2;
    }

    return dist;
}
