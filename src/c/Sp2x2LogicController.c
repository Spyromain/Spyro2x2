#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x2LogicController(void)
{
    Sp2LogicController(0);

    if (sp2_is_demo_mode) {
        return;
    }

    Sp2x2Swap(&sp2_ticks, &sp2x2_ticks, sizeof sp2_ticks);
    Sp2x2Swap(&sp2_tick_counter, &sp2x2_tick_counter, sizeof sp2_tick_counter);
    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    // swapped = 1;
    EnterCriticalSection();
    Sp2x2Swap(&sp2_pad_queue, &sp2x2_pad_queue, sizeof sp2_pad_queue);
    Sp2x2Swap(&sp2_actuator_data, &sp2x2_actuator_data, sizeof sp2_actuator_data);

    Sp2LogicController(1);

    Sp2x2Swap(&sp2_ticks, &sp2x2_ticks, sizeof sp2_ticks);
    Sp2x2Swap(&sp2_tick_counter, &sp2x2_tick_counter, sizeof sp2_tick_counter);
    Sp2x2Swap(&sp2_pad, &sp2x2_pad, sizeof sp2_pad);
    Sp2x2Swap(&sp2_pad_queue, &sp2x2_pad_queue, sizeof sp2_pad_queue);
    // swapped = 0;
    ExitCriticalSection();
    Sp2x2Swap(&sp2_actuator_data, &sp2x2_actuator_data, sizeof sp2_actuator_data);

    if (
        sp2x2_pad[0] >= 2
        && sp2_game_state != 0
        // && sp2_game_state != 1
        && sp2_game_state != 3
    ) {
        if (sp2x2_current_dialogue_player == 0) {
            *(int *)&sp2_pad[52] |= *(int *)&sp2x2_pad[52];
        }
        else {
            *(int *)&sp2x2_pad[52] |= *(int *)&sp2_pad[52];
        }
    }
}
