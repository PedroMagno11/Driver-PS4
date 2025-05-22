// #include <stdio.h>
// #include <wchar.h>
// #include <string.h>
// #include "hidapi.h"
//
// int main(void) {
//     struct hid_device_info *devs, *cur_dev;
//     hid_device *handle = NULL;
//     unsigned char buf[64];
//     int res;
//
//     hid_init();
//     devs = hid_enumerate(0x0, 0x0);
//     cur_dev = devs;
//
//     while (cur_dev) {
//         if (cur_dev->product_string && wcsstr(cur_dev->product_string, L"Wireless Controller")) {
//             printf("Controle PS4 encontrado!\n");
//             printf("  VID: 0x%04hx\n", cur_dev->vendor_id);
//             printf("  PID: 0x%04hx\n", cur_dev->product_id);
//             printf("  Abrindo o dispositivo...\n");
//
//             handle = hid_open_path(cur_dev->path);
//             break;
//         }
//         cur_dev = cur_dev->next;
//     }
//
//     hid_free_enumeration(devs);
//
//     if (!handle) {
//         printf("Erro: não foi possível abrir o controle PS4.\n");
//         hid_exit();
//         return 1;
//     }
//
//     printf("Lendo dados do controle PS4...\n(pressione botões para ver os pacotes)\n");
//
//     while (1) {
//         res = hid_read(handle, buf, sizeof(buf));
//         if (res > 0) {
//             printf("Pacote recebido (%d bytes): ", res);
//             for (int i = 0; i < res; i++) {
//                 printf("%02X ", buf[i]);
//             }
//
//             printf("\n");
//         }
//     }
//
//     hid_close(handle);
//     hid_exit();
//     return 0;
// }

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
