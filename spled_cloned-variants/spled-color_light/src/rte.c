#include "rte.h"
#include <windows.h>
#include <stdio.h>

static PowerState currentPowerState = POWER_STATE_OFF;
static boolean powerKeyPressed = FALSE;
static boolean arrowUpKeyPressed = FALSE;
static boolean arrowDownKeyPressed = FALSE;
static RGBColor lightValue = {
    .red = 0,
    .green = 0,
    .blue = 0
};
static percentage_t mainKnobValue = 50;
static unsigned int brightnessValue = 0;

void RteSetPowerState(PowerState state) {
    currentPowerState = state;
}

PowerState RteGetPowerState(void) {
    return currentPowerState;
}

void RteSetPowerKeyPressed(boolean value) {
    powerKeyPressed = value;
}

boolean RteGetPowerKeyPressed() {
    return powerKeyPressed;
}

void RteSetLightValue(RGBColor value) {
    lightValue = value;
}

void RteGetLightValue(RGBColor* value) {
    *value = lightValue;
}

boolean RteIsKeyPressed(int key) {
    return (GetAsyncKeyState(key) & 0x8000) != 0;
}


void RteSetMainKnobValue(percentage_t value) {
    if (value > 100) {
        mainKnobValue = 100;
    }
    else {
        mainKnobValue = value;
    }
}

percentage_t RteGetMainKnobValue(void) {
    return mainKnobValue;
}


void RteSetBrightnessValue(unsigned int value) {
    brightnessValue = value;
}

unsigned int RteGetBrightnessValue(void) {
    return brightnessValue;
}
