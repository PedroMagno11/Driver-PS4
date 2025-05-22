#include "driver_ps4.h"
#include <hidapi.h>
#include <stdio.h>
#include <string.h>

#define VENDOR_ID 0x054C
#define PRODUCT_ID 0x09CC

static hid_device* handle = NULL;

int ps4_init() {
    if (hid_init() != 0) return -1;
    handle = hid_open(VENDOR_ID, PRODUCT_ID, NULL);
    return (handle != NULL) ? 0 : -1;
}

int ps4_read_input(ps4_input_t* input) {
    if(!handle || !input) return -1;

    unsigned char buf[64];
    memset(input,0,sizeof(ps4_input_t));

    int res = hid_read(handle, buf, sizeof(buf));

    if(res <= 0) return -1;

    input->left_stick_x = buf[1];
    input->left_stick_y = buf[2];
    input->right_stick_x = buf[3];
    input->right_stick_y = buf[4];
    input -> l2_analog = buf[8];
    input -> r2_analog = buf[9];

    unsigned char b5 = buf[5];
    unsigned char b6 = buf[6];
    unsigned char b7 = buf[7];

    // D-Pad
    unsigned char dpad = b5 & 0x0F;
    input->dpad_up = (dpad == 0|| dpad == 1 || dpad == 7);
    input->dpad_right = (dpad == 1|| dpad == 2 || dpad == 3);
    input->dpad_down = (dpad == 3 || dpad == 4 || dpad == 5);
    input->dpad_left = (dpad == 5 || dpad == 6 || dpad == 7);

    input->square = (b5 >> 4) & 1;
    input->cross = (b5 >> 5) & 1;
    input->circle   = (b5 >> 6) & 1;
    input->triangle = (b5 >> 7) & 1;

    input->l1          = (b6 >> 0) & 1;
    input->r1          = (b6 >> 1) & 1;
    input->l2_digital  = (b6 >> 2) & 1;
    input->r2_digital  = (b6 >> 3) & 1;
    input->share       = (b6 >> 4) & 1;
    input->options     = (b6 >> 5) & 1;
    input->l3          = (b6 >> 6) & 1;
    input->r3          = (b6 >> 7) & 1;

    input->ps          = (b7 >> 0) & 1;
    input->touchpad    = (b7 >> 1) & 1;

    return 0;
}

void ps4_close() {
    if(handle) {
        hid_close(handle);
        handle = NULL;
    }
    hid_exit();
}
