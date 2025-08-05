#include "Sp2.h"
#include "Sp2x2.h"

#define PARTICLES_SIZE 0x100


void Sp2x2RenderParticles(void)
{
    Sp2RenderParticles();

    if (sp2_is_demo_mode || sp2_game_state != 0 || sp2x2_pad[0] < 2) {
        return;
    }

    static unsigned char animated_particles[PARTICLES_SIZE] = {0};

    if (sp2x2_current_player == 0) { // Player 1
        Sp2MemSetAlign16(animated_particles, 0, PARTICLES_SIZE);
        int i = 0;
        for (unsigned char *particle = sp2_first_particle; particle[1] != 0xff; particle += 0x20) {
            if (i < PARTICLES_SIZE) {
                animated_particles[i] = particle[3];
            }
            i += 1;
        }
        if (i > PARTICLES_SIZE) {
            printf("=== MEMORY OVERFLOW 0x%x > 0x%x ===\n", i, PARTICLES_SIZE);
        }
    }
    else { // Player 2
        int i = 0;
        for (unsigned char *particle = sp2_first_particle; particle[1] != 0xff; particle += 0x20) {
            if (i < PARTICLES_SIZE && animated_particles[i] > particle[3]) {
                particle[3] = animated_particles[i];
            }
            i += 1;
        }
    }
}
