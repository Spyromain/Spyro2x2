#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2VSyncCallback(void)
{
    Sp2VSyncCallback();

    if (sp2_is_demo_mode) {
        return;
    }

    sp2_cd_counter -= 1;
    if (!sp2_is_demo_mode) {
        sp2_level_timer -= 1;
    }

    Sp2x2Swap(&sp2_actuator_data, &sp2x2_actuator_data, sizeof sp2_actuator_data);
    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    if (!sp2_is_demo_mode) {
        Sp2x2Swap(&sp2_pad_port_1, &sp2_pad_port_2, sizeof sp2_pad_port_1);
        Sp2x2Swap(&sp2_pad_queue, &sp2x2_pad_queue, sizeof sp2_pad_queue);
        Sp2x2Swap(&sp2_tick_counter, &sp2x2_tick_counter, sizeof sp2_tick_counter);
    }

    Sp2VSyncCallback();

    Sp2x2Swap(&sp2_actuator_data, &sp2x2_actuator_data, sizeof sp2_actuator_data);
    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    if (!sp2_is_demo_mode) {
        Sp2x2Swap(&sp2_pad_port_1, &sp2_pad_port_2, sizeof sp2_pad_port_1);
        Sp2x2Swap(&sp2_pad_queue, &sp2x2_pad_queue, sizeof sp2_pad_queue);
        Sp2x2Swap(&sp2_tick_counter, &sp2x2_tick_counter, sizeof sp2_tick_counter);
    }
}
