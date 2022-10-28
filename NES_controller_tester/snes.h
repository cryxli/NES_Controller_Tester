// -------------------------------------------------
// NES Controller Tester
// by cryxli, August 2022
// 
// Based on a Heltec Wifi Kit 32 with a 128x64 pixel
// OLED display.
//
// This file contains the bitmaps for the SNES
// controller layout including pressed buttons.
// -------------------------------------------------

// empty controller layout
#define SNES_Layout_width 128
#define SNES_Layout_height 53

const unsigned char SNES_Layout_bits[] PROGMEM = {
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
    0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x80,
    0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x80,
    0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x80,
    0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x80,
    0x01,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x80,
    0x01,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x80,
    0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0xff,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x3f,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x40,0x00,0x80,
    0x01,0x80,0xff,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x80,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x85,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x82,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x85,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x80,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x40,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0xe3,0x3f,0xfe,0x83,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x04,0x00,0x01,0x84,
    0xf9,0xff,0x00,0xfe,0x3f,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x08,0x80,0x00,0x88,
    0x09,0x00,0x01,0x01,0x20,0x76,0x39,0x39,0xec,0x64,0x8e,0x88,0x08,0x80,0x70,0x88,
    0x09,0x00,0x82,0x00,0x20,0x11,0x89,0x12,0x42,0xaa,0x84,0x88,0x08,0x80,0x88,0x88,
    0x09,0x00,0x44,0x00,0x20,0x32,0x99,0x10,0x44,0x6e,0x84,0x88,0x08,0x80,0x88,0x88,
    0x09,0x00,0x28,0x00,0x20,0x14,0x89,0x12,0x48,0xaa,0x84,0x50,0x08,0x80,0xf8,0x88,
    0x09,0x00,0x10,0x00,0x20,0x73,0x3b,0x11,0x46,0xaa,0x84,0x20,0x08,0x80,0x88,0x88,
    0x09,0x00,0x28,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x80,0x20,0x08,0x80,0x88,0x88,
    0x09,0x00,0x44,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x80,0x20,0x08,0x80,0x88,0x88,
    0x09,0x00,0x82,0x00,0x20,0xf0,0xff,0x0f,0xfc,0xff,0x83,0x00,0x08,0x80,0x00,0x88,
    0x09,0x00,0x01,0x01,0x20,0x08,0x00,0x10,0x02,0x00,0x04,0x01,0x04,0x00,0x01,0x84,
    0xf9,0xff,0x00,0xfe,0x3f,0x04,0x00,0x20,0x01,0x00,0x08,0xfe,0xe3,0x3f,0xfe,0x83,
    0x01,0x80,0x00,0x02,0x00,0x04,0x00,0x20,0x01,0x00,0x08,0x00,0x10,0x40,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x04,0x00,0x20,0x01,0x00,0x08,0x00,0x08,0x80,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x04,0x00,0x20,0x01,0x00,0x08,0x00,0x88,0x87,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x04,0x00,0x20,0x01,0x00,0x08,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x04,0x00,0x20,0x01,0x00,0x08,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x08,0x00,0x10,0x02,0x00,0x04,0x00,0x88,0x87,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0xf0,0xff,0x0f,0xfc,0xff,0x03,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x88,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x87,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x80,0x00,0x80,
    0x01,0x80,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x40,0x00,0x80,
    0x01,0x80,0xff,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x3f,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
    0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};