//
// Created by pedro on 15/05/2025.
//

#ifndef DRIVER_PS4_H
#define DRIVER_PS4_H

typedef struct {
    int square, cross, circle, triangle;
    int l1, r1, l2_digital, r2_digital;
    int share, options, ps, touchpad;
    int l3, r3;
    int dpad_up, dpad_down, dpad_left, dpad_right;

    // Analógicos
    unsigned char left_stick_x;
    unsigned char left_stick_y;
    unsigned char right_stick_x;
    unsigned char right_stick_y;
    unsigned char l2_analog;
    unsigned char r2_analog;
} ps4_input_t;

int ps4_init();

int ps4_read_input(ps4_input_t *input);

void ps4_close();

#endif //DRIVER_PS4_H
