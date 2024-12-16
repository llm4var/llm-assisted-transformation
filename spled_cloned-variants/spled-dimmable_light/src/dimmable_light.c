#include "dimmable_light.h"

#include "keyboard_interface.h"
#include "power_signal_processing.h"
#include "light_controller.h"
#include "main_control_knob.h"
#include "console_interface.h"
#include "brightness_controller.h"
#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#define usleep(microseconds) Sleep((microseconds) / 1000)
#else
#include <unistd.h>
#endif

void dimmable_light(void)
{
    keyboardInterface();
    powerSignalProcessing();
    mainControlKnob();
    brightnessController();
    lightController();
    consoleInterface();
    // simple main loop of 10 milliseconds
    usleep(10000);
}
