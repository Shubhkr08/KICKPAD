#pragma once

// Matrix Size
#define MATRIX_ROWS 4
#define MATRIX_COLS 3

// Row Pins
#define MATRIX_ROW_PINS { GP0, GP1, GP2, GP3 }

// Column Pins
#define MATRIX_COL_PINS { GP26, GP27, GP28 }

// Diode Direction
#define DIODE_DIRECTION COL2ROW

// Encoder Pins
#define ENCODERS_PAD_A { GP4 }
#define ENCODERS_PAD_B { GP5 }

// OLED I2C Pins
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP6
#define I2C1_SCL_PIN GP7

// OLED
#define OLED_DISPLAY_128X64

// Debounce
#define DEBOUNCE 5