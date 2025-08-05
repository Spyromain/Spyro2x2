#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2StopCutscene(int param_1)
{
    Sp2StopCutscene(param_1, 9);

    if (!param_1 || sp2_is_demo_mode || sp2x2_pad[0] < 2) {
        return;
    }

    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);

    Sp2StopCutscene(param_1, 9);

    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);
}
