#include QMK_KEYBOARD_H

// Layers
enum layers {
    LAYER0,
    LAYER1,
    LAYER2,
    LAYER3
};

// Keymaps
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LAYER0] = LAYOUT(
    KC_1, KC_2, KC_3,
    KC_4, KC_5, KC_6,
    KC_7, KC_8, KC_9,
    KC_A, KC_B, KC_C
),

[LAYER1] = LAYOUT(
    KC_Q, KC_W, KC_E,
    KC_R, KC_T, KC_Y,
    KC_U, KC_I, KC_O,
    KC_P, KC_S, KC_D
),

[LAYER2] = LAYOUT(
    KC_F1, KC_F2, KC_F3,
    KC_F4, KC_F5, KC_F6,
    KC_F7, KC_F8, KC_F9,
    KC_F10, KC_F11, KC_F12
),

[LAYER3] = LAYOUT(
    KC_MPLY, KC_MPRV, KC_MNXT,
    KC_VOLU, KC_VOLD, KC_MUTE,
    RGB_TOG, RGB_MOD, RGB_HUI,
    RGB_SAI, RGB_VAI, KC_ESC
)

};



// Encoder Changes Layers
bool encoder_update_user(uint8_t index, bool clockwise) {

    uint8_t layer = get_highest_layer(layer_state);

    if (clockwise) {
        layer++;

        if (layer > 3) {
            layer = 0;
        }

    } else {

        if (layer == 0) {
            layer = 3;
        } else {
            layer--;
        }
    }

    layer_move(layer);

    return true;
}



#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_0;
}

bool oled_task_user(void) {

    oled_clear();

    oled_set_cursor(0,0);
    oled_write_ln("MacroPad", false);

    oled_set_cursor(0,2);

    switch(get_highest_layer(layer_state)) {

        case LAYER0:
            oled_write_ln("Layer 0", false);
            break;

        case LAYER1:
            oled_write_ln("Layer 1", false);
            break;

        case LAYER2:
            oled_write_ln("Layer 2", false);
            break;

        case LAYER3:
            oled_write_ln("Layer 3", false);
            break;
    }

    return false;
}

#endif