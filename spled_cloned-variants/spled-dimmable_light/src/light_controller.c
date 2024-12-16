#include "light_controller.h"
#include "rte.h"

typedef enum
{
    LIGHT_OFF, /**< Represents a state where the light is turned off. */
    LIGHT_ON   /**< Represents a state where the light is turned on with a specific color. */
} LightState;

static LightState currentLightState = LIGHT_OFF; /**< Current state of the light. */

const RGBColor OFF_COLOR = {.red = 0, .green = 0, .blue = 0};

static unsigned int getBrightnessValue()
{
    return RteGetBrightnessValue();
}

static void turnLightOff(void)
{
    RteSetLightValue(OFF_COLOR);
}

static void turnLightOn(void)
{
    RGBColor color = OFF_COLOR;
    color.blue = getBrightnessValue();

    RteSetLightValue(color);
}

void lightController(void)
{

    PowerState powerState = RteGetPowerState();

    switch (currentLightState)
    {
    case LIGHT_OFF:

        if (powerState != POWER_STATE_OFF)
        {
            turnLightOn();
            currentLightState = LIGHT_ON;
        }
        break;

    case LIGHT_ON:
        if (powerState == POWER_STATE_OFF)
        {
            turnLightOff();
            currentLightState = LIGHT_OFF;
        }
        else
        {
            turnLightOn();
        }
        break;
    }
}
