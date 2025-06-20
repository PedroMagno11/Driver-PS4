#include "driver_ps4.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    if (ps4_init() != 0) {
        printf("Erro ao inicializar o controle PS4.\n");
        return 1;
    }

    ps4_input_t input;
    while (1) {
        if (ps4_read_input(&input) == 0) {
            printf("LS: (%.2f, %.2f) | RS: (%.2f, %.2f) | R2: %.2f | L2: %d\n",
                input.norm_left_stick_x, input.norm_left_stick_y,
                input.norm_right_stick_x, input.norm_right_stick_y,
                input.norm_r2,
                input.l2_analog
            );
        }
        usleep(20000); // 20ms = 50 FPS
    }

    ps4_close();
    return 0;
}