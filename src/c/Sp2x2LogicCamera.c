#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2LogicCamera(void)
{
    Sp2LogicCamera();

    if (sp2_is_demo_mode || sp2_game_state != 0 || sp2x2_pad[0] < 2) {
        return;
    }

    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    Sp2x2Swap(&sp2_pad_2, &sp2x2_pad_2, sizeof sp2_pad_2);
    // swapped = 1;
    EnterCriticalSection();
    Sp2x2Swap(&sp2_pad_queue, &sp2x2_pad_queue, sizeof sp2_pad_queue);
    Sp2x2Swap(&sp2_8006c7e0, &sp2x2_8006c7e0, sizeof sp2_8006c7e0);
    Sp2x2Swap(&sp2_ticks, &sp2x2_ticks, sizeof sp2_ticks);
    Sp2x2Swap(&sp2_actuator_data, &sp2x2_actuator_data, sizeof sp2_actuator_data);
    Sp2x2Swap(&sp2_tick_counter, &sp2x2_tick_counter, sizeof sp2_tick_counter);

    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);

    Sp2x2Swap(&sp2_is_reticle_displayed, &sp2x2_is_reticle_displayed, sizeof sp2_is_reticle_displayed);

    Sp2LogicCamera();

    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    Sp2x2Swap(&sp2_pad_2, &sp2x2_pad_2, sizeof sp2_pad_2);
    Sp2x2Swap(&sp2_pad_queue, &sp2x2_pad_queue, sizeof sp2_pad_queue);
    // swapped = 0;
    ExitCriticalSection();
    Sp2x2Swap(&sp2_8006c7e0, &sp2x2_8006c7e0, sizeof sp2_8006c7e0);
    Sp2x2Swap(&sp2_ticks, &sp2x2_ticks, sizeof sp2_ticks);
    Sp2x2Swap(&sp2_actuator_data, &sp2x2_actuator_data, sizeof sp2_actuator_data);
    Sp2x2Swap(&sp2_tick_counter, &sp2x2_tick_counter, sizeof sp2_tick_counter);

    Sp2x2Swap(&sp2_camera, &sp2x2_camera, sizeof sp2_camera);
    Sp2x2Swap(&sp2_spyro, &sp2x2_spyro, sizeof sp2_spyro);

    Sp2x2Swap(&sp2_is_reticle_displayed, &sp2x2_is_reticle_displayed, sizeof sp2_is_reticle_displayed);
}
