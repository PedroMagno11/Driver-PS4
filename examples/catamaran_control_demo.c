#include "driver_ps4.h"
#include <stdio.h>
#include <unistd.h>

// Simula envio para motores e servo (Quando for ser usado em cenário real, deve ser substituido por comando real via UART, PWM, etc)
void controlar_motor(float aceleracao) {
    printf("Motores: aceleração %.2f\n", aceleracao);
}

void controlar_freio(float intensidade) {
    printf("Freio: intensidade %.2f\n", intensidade);
}

void controlar_leme(float angulo) {
    printf("Leme: ângulo %.2f graus\n", angulo * 30);  // ±30°
}

void controlar_camera(float direcao) {
    printf("Câmera: rotação %.2f graus\n", direcao * 60); // ±60°
}

int main() {
    if (ps4_init() != 0) {
        printf("Erro ao inicializar o controle PS4.\n");
        return 1;
    }

    ps4_input_t input;

    while (1) {
        if (ps4_read_input(&input) == 0) {
            // Interpretação do controle

            float aceleracao = input.norm_r2;  // 0.0 a 1.0
            float freio      = input.norm_l2;  // 0.0 a 1.0

            float direcao_leme = input.norm_left_stick_x;  // -1.0 a 1.0
            float direcao_camera = input.norm_right_stick_x;

            // Controle dos atuadores
            controlar_motor(aceleracao);
            controlar_freio(freio);
            controlar_leme(direcao_leme);
            controlar_camera(direcao_camera);

            printf("-----------------------------\n");
        }

        usleep(50000); // 50ms (20Hz)
    }

    ps4_close();
    return 0;
}
