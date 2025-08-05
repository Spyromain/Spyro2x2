#include "Sp2.h"
#include "Sp2x2.h"


void Sp2x280021610(int param_1, int param_2)
{
    unsigned char *cameras[] = {sp2_camera, sp2x2_camera};

    for (int i = 0; i < ((sp2_is_demo_mode || sp2x2_pad[0] < 2) ? 1 : 2); i++) {
        if (*(int *)&cameras[i][76] + 0xfffffff7 > 1) {
            Sp280020e38(
                (int *)&cameras[i][360 + 28 + 3*4],
                (int *)&cameras[i][124],
                0
            );
        }
        *(int *)&cameras[i][360 + 0] = 10;
        *(int *)&cameras[i][360 + 60] = param_1;
        *(int *)&cameras[i][360 + 64] = 0;
        *(int *)&cameras[i][360 + 76] = param_2;
    }

    // if (*(int *)&sp2x2_camera[76] + 0xfffffff7 > 1) {
    //     Sp280020e38(
    //         (int *)&sp2x2_camera[360 + 28 + 3*4],
    //         (int *)&sp2x2_camera[124],
    //         0
    //     );
    // }
    // *(int *)&sp2x2_camera[360 + 0] = 10;
    // *(int *)&sp2x2_camera[360 + 60] = param_1;
    // *(int *)&sp2x2_camera[360 + 64] = 0;
    // *(int *)&sp2x2_camera[360 + 76] = param_2;
}
