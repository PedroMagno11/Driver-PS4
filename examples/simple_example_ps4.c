#include "driver_ps4.h"
#include <stdio.h>
#include <windows.h>

int main() {
     if (ps4_init() != 0) {
         printf("Erro ao inicializar controle PS4.\n");
         return 1;
     }

     ps4_input_t input;
     while (1) {
         if (ps4_read_input(&input) == 0) {
             if (input.cross)    printf("[X] ");
             if (input.circle)   printf("[O] ");
             if (input.square)   printf("[■] ");
             if (input.triangle) printf("[▲] ");
             if (input.l1)       printf("[L1] ");
             if (input.r1)       printf("[R1] ");
             if (input.l2_digital) printf("[L2] ");
             if (input.r2_digital) printf("[R2] ");
             if (input.share)    printf("[SHARE] ");
             if (input.options)  printf("[OPTIONS] ");
             if (input.ps)       printf("[PS] ");
             if (input.touchpad) printf("[TPAD] ");
             if (input.l3)       printf("[L3] ");
             if (input.r3)       printf("[R3] ");
             if (input.dpad_up)    printf("[↑] ");
             if (input.dpad_down)  printf("[↓] ");
             if (input.dpad_left)  printf("[←] ");
             if (input.dpad_right) printf("[→] ");
             printf("\n");
         }
         Sleep(50);
     }

     ps4_close();
     return 0;
}


