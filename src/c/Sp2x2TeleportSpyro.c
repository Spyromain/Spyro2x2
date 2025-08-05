#include "Sp2.h"
#include "Sp2x2.h"


static void _Sp2x2TeleportSpyro(int *position, int angle, int *param_3, int param_4);


void Sp2x2TeleportSpyro(int *position, int angle, int *param_3, int param_4)
{
    if (sp2_is_demo_mode || sp2x2_pad[0] < 2) {
        _Sp2x2TeleportSpyro(position, angle, param_3, param_4);
        return;
    }

    // TODO for icy speedway minigame
    *(int *)&sp2x2_spyro[536] = *(int *)&sp2_spyro[536];
    _Sp2x2TeleportSpyro(position, angle, param_3, param_4);

    Sp2x2Swap(sp2_spyro, sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(sp2_camera, sp2x2_camera, sizeof sp2_camera);

    _Sp2x2TeleportSpyro(position, angle, param_3, param_4);

    Sp2x2Swap(sp2_spyro, sp2x2_spyro, sizeof sp2_spyro);
    Sp2x2Swap(sp2_camera, sp2x2_camera, sizeof sp2_camera);
}


static void _Sp2x2TeleportSpyro(int *position, int angle, int *param_3, int param_4)
{
    if (*(int *)&sp2_spyro[600] >= 0) {
        Sp2Vec3Move((int *)&sp2_spyro[556], position);
        *(int *)&sp2_spyro[568] = angle << 4;
        *(int *)&sp2_camera[360] = 11;
        *(int *)&sp2_spyro[572] = param_4;

        if (!param_3) {
            Sp2Vec3Clear((int *)&sp2_camera[388]);
        }
        else {
            Sp2Vec3Move((int *)&sp2_camera[388], param_3);
        }

        int _a = 0;
        if (*(int *)&sp2_camera[76] == 9 && sp2_fading_alpha >= 0x80) {
            _a = 0x10;
        }
        Sp280023828(11);
        *(int *)&sp2_camera[84] = _a;
    }
}
