
#include "Arduino.h"
#include "heltec.h"

#include "nes.h"

#define BAND    868E6  //you can set band here directly,e.g. 868E6,915E6

#define BAUD 74880

// 5V red
// GND black
#define DATA 17 // yellow
#define LATCH 5 // blue
#define CLOCK 18 // green

#define LATCH_DELAY 5
#define PULSE_DELAY 1
#define CLOCK_DELAY 5
#define DATA_DELAY 5
#define LOOP_DELAY 20

#define NES_A      0b10000000
#define NES_B      0b01000000
#define NES_SELECT 0b00100000
#define NES_START  0b00010000
#define NES_UP     0b00001000
#define NES_DOWN   0b00000100
#define NES_LEFT   0b00000010
#define NES_RIGHT  0b00000001

void setup() {    
    pinMode(DATA, INPUT);
    pinMode(LATCH, OUTPUT);
    pinMode(CLOCK, OUTPUT);

    digitalWrite(LATCH, LOW);
    digitalWrite(CLOCK, HIGH);

    Heltec.begin(
        true /*DisplayEnable Enable*/, 
        false /*LoRa Enable*/, 
        true /*Serial Enable*/, 
        false /*LoRa use PABOOST*/, 
        BAND /*LoRa RF working band*/
    );
}

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
    pulseWire(LATCH, 1);
    delay(DATA_DELAY);

    // A B SELECT START UP DOWN LEFT RIGHT
    int buttons = 0b00000000;
    for(int index = 0b10000000; index > 0; index = index >> 1) {
        buttons = (buttons << 1) + 1 - digitalRead(DATA);
        pulseWire(CLOCK, 0);
        delay(DATA_DELAY);
    }
    //Serial.print("Buttons: ");
    //Serial.println(buttons);

    if (buttons == 0b11111111) {
        displayNoControllerConnected();
    } else {
        displayButtons(buttons);
    }

    delay(LOOP_DELAY);
}

void displayNoControllerConnected() {
    Heltec.display -> clear();
    Heltec.display -> drawXbm(0, 0, NES_Layout_width, NES_Layout_height, NES_Layout_bits);
    Heltec.display -> drawString(10, 3, "Connect a controller...");
    Heltec.display -> display();
}

void displayButtons(int buttons) {
    // display pressed buttons
    Heltec.display -> clear();
    Heltec.display -> drawXbm(0, 0, NES_Layout_width, NES_Layout_height, NES_Layout_bits);
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
    Heltec.display -> display();
}
