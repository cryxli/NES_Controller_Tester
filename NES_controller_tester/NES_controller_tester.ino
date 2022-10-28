// -------------------------------------------------
// NES Controller Tester, v2.0
// by cryxli, August 2022
// 
// Based on a Heltec Wifi Kit 32 with a 128x64 pixel
// OLED display.
//
// This version supports NES and SNES controllers.
// -------------------------------------------------
#include "Arduino.h"
#include "heltec.h"

// include our bitmaps for the controller layout and buttons
#include "nes.h"
#include "snes.h"

// pins for communication with controller
//      5V          red
//      GND         black
#define DATA  17 // yellow
#define LATCH  5 // blue
#define CLOCK 18 // green

// define some delays [ms]
#define LATCH_DELAY 5
#define PULSE_DELAY 1
#define CLOCK_DELAY 5
#define DATA_DELAY 5
#define LOOP_DELAY 20

// bitmap masks for the NES buttons
#define NES_A      1<<7
#define NES_B      1<<6
#define NES_SELECT 1<<5
#define NES_START  1<<4
#define NES_UP     1<<3
#define NES_DOWN   1<<2
#define NES_LEFT   1<<1
#define NES_RIGHT  1<<0

// bitmap masks for the SNES buttons
#define SNES_B      1<<11
#define SNES_Y      1<<10
#define SNES_SELECT 1<<9
#define SNES_START  1<<8
#define SNES_UP     1<<7
#define SNES_DOWN   1<<6
#define SNES_LEFT   1<<5
#define SNES_RIGHT  1<<4
#define SNES_A      1<<3
#define SNES_X      1<<2
#define SNES_L      1<<1
#define SNES_R      1<<0

// you can set LoRa band directly, e.g. 868E6,915E6
#define BAND 868E6 

void setup() {
    // define pins
    pinMode(DATA, INPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLOCK, OUTPUT);
    // set default state
    digitalWrite(LATCH, LOW);
    digitalWrite(CLOCK, HIGH);

    // init OLED etc.
    Heltec.begin(
        true  /* DisplayEnable Enable*/, 
        false /* LoRa Enable         */, 
        true  /* Serial Enable       */, 
        false /* LoRa use PABOOST    */, 
        BAND  /* LoRa RF working band*/
    );
}

/**
 * Quickly change the state of an output pin, then revert to stand-by.
 */
void pulseWire(int wire, bool pulse) {
    if (pulse == 1) {
        digitalWrite(wire, HIGH);
        delay(PULSE_DELAY);
        digitalWrite(wire, LOW);
    } else {
        digitalWrite(wire, LOW);
        delay(PULSE_DELAY);
        digitalWrite(wire, HIGH);
    }
}

void loop() {
    // have controller read button states
    pulseWire(LATCH, 1);
    delay(DATA_DELAY);

    //  NES buttons: A, B, SELECT, START, UP, DOWN, LEFT, RIGHT
    // SNES buttons: B, Y, SELECT, START, UP, DOWN, LEFT, RIGHT, A, X, L, R
    int buttons = 0;
    for(int index = 1<<15; index > 0; index = index >> 1) {
        buttons = (buttons << 1) + 1 - digitalRead(DATA);
        pulseWire(CLOCK, 0);
        delay(DATA_DELAY);
    }
    // for debugging
    // Serial.print("Buttons: ");
    // Serial.println(buttons);

    // display the result
    if (buttons & 15 > 0) {
        displayNoControllerConnected();
    } else if (buttons & 255 > 0) {
        displayNesButtons(buttons>>8);
    } else {
        displaySnesButtons(buttons>>4);
    }

    delay(LOOP_DELAY);
}

/**
 * "All" buttons are pressed, therefore no controller is connected. Show a
 * hint to connect a controller.
 */
void displayNoControllerConnected() {
    // reset display buffer
    Heltec.display -> clear();
    // draw the empty controller layout
//    Heltec.display -> drawXbm(0, 0, NES_Layout_width, NES_Layout_height, NES_Layout_bits);
    // show hint
    Heltec.display -> drawString(10, 5, "Connect a controller...");

    Heltec.display -> drawString(10, 25, "Support for NES and");
    Heltec.display -> drawString(10, 35, "SNES controllers.");

    Heltec.display -> drawString(10, 50, "v2.0");
    Heltec.display -> drawString(80, 50, "by cryxli");
    
    // update display
    Heltec.display -> display();
}

/**
 * Graphically show which NES buttons are pressed
 */
void displaySnesButtons(int buttons) {
    // display pressed buttons; reset display buffer
    Heltec.display -> clear();
    // draw the empty controller layout
    Heltec.display -> drawXbm(0, 0, SNES_Layout_width, SNES_Layout_height, SNES_Layout_bits);

    // highlight pressed buttons
    if ((buttons & SNES_UP) > 0) {
        Heltec.display -> drawXbm(17, 17, NES_up_width, NES_up_height, NES_up_bits);
    }
    if ((buttons & SNES_LEFT) > 0) {
        Heltec.display -> drawXbm(3, 29, NES_left_width, NES_left_height, NES_left_bits);
    }
    if ((buttons & SNES_RIGHT) > 0) {
        Heltec.display -> drawXbm(22, 29, NES_right_width, NES_right_height, NES_right_bits);
    }
    if ((buttons & SNES_DOWN) > 0) {
        Heltec.display -> drawXbm(17, 35, NES_down_width, NES_down_height, NES_down_bits);
    }
    if ((buttons & SNES_SELECT) > 0) {
        Heltec.display -> fillRect(44, 37, 16, 6);
    }
    if ((buttons & SNES_START) > 0) {
        Heltec.display -> fillRect(66, 37, 16, 6);
    }
    if ((buttons & SNES_L) > 0) {
        Heltec.display -> fillRect(0, 0, 12, 6);
    }
    if ((buttons & SNES_R) > 0) {
        Heltec.display -> fillRect(116, 0, 12, 6);
    }
    if ((buttons & SNES_Y) > 0) {
        Heltec.display -> fillRect(89, 27, 9, 9);
    }
    if ((buttons & SNES_X) > 0) {
        Heltec.display -> fillRect(101, 15, 9, 9);
    }
    if ((buttons & SNES_B) > 0) {
        Heltec.display -> fillRect(101, 39, 9, 9);
    }
    if ((buttons & SNES_A) > 0) {
        Heltec.display -> fillRect(113, 27, 9, 9);
    }
    // done, update display
    Heltec.display -> display();
}

/**
 * Graphically show which SNES buttons are pressed
 */
void displayNesButtons(int buttons) {
    // display pressed buttons; reset display buffer
    Heltec.display -> clear();
    // draw the empty controller layout
    Heltec.display -> drawXbm(0, 0, NES_Layout_width, NES_Layout_height, NES_Layout_bits);
    // highlight pressed buttons
    if ((buttons & NES_UP) > 0) {
        Heltec.display -> drawXbm(17, 17, NES_up_width, NES_up_height, NES_up_bits);
    }
    if ((buttons & NES_LEFT) > 0) {
        Heltec.display -> drawXbm(3, 29, NES_left_width, NES_left_height, NES_left_bits);
    }
    if ((buttons & NES_RIGHT) > 0) {
        Heltec.display -> drawXbm(22, 29, NES_right_width, NES_right_height, NES_right_bits);
    }
    if ((buttons & NES_DOWN) > 0) {
        Heltec.display -> drawXbm(17, 35, NES_down_width, NES_down_height, NES_down_bits);
    }
    if ((buttons & NES_SELECT) > 0) {
        Heltec.display -> fillRect(44, 37, 16, 6);
    }
    if ((buttons & NES_START) > 0) {
        Heltec.display -> fillRect(66, 37, 16, 6);
    }
    if ((buttons & NES_B) > 0) {
        Heltec.display -> drawXbm(89, 33, NES_a_width, NES_a_height, NES_a_bits);
    }
    if ((buttons & NES_A) > 0) {
        Heltec.display -> drawXbm(109, 33, NES_a_width, NES_a_height, NES_a_bits);
    }
    // done, update display
    Heltec.display -> display();
}
