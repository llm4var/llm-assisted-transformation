#include "light_controller.h"
#include "rte.h"

typedef enum
{
    LIGHT_OFF, /**< Represents a state where the light is turned off. */
    LIGHT_ON   /**< Represents a state where the light is turned on with a specific color. */
} LightState;

static LightState currentLightState = LIGHT_OFF; /**< Current state of the light. */

static int blinkCounter = 0;
static boolean blinkState = FALSE;

const RGBColor OFF_COLOR = {.red = 0, .green = 0, .blue = 0};

static unsigned int getBrightnessValue()
{
    return 128;
}

static void turnLightOff(void)
{
    blinkState = FALSE;
    RteSetLightValue(OFF_COLOR);
}

static void turnLightOn(void)
{
    RGBColor color = OFF_COLOR;
    color.blue = getBrightnessValue();

    blinkState = TRUE;

    RteSetLightValue(color);
}

unsigned int calculateBlinkPeriod(percentage_t mainKnobValue)
{
    // Calculate blink period based on main knob value
    unsigned int blinkPeriod = 100 - (mainKnobValue); // Adjust this formula as needed

    // Ensure there's a minimum blink period
    blinkPeriod = (blinkPeriod > 10) ? blinkPeriod : 10; // Adjust the minimum period as needed

    return blinkPeriod;
}

void lightController(void)
{

    PowerState powerState = RteGetPowerState();

    percentage_t mainKnobValue = RteGetMainKnobValue();
    unsigned int blinkPeriod = calculateBlinkPeriod(mainKnobValue);

    switch (currentLightState)
    {
    case LIGHT_OFF:
        blinkCounter = 0;
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
            blinkCounter++;
            if (blinkCounter >= blinkPeriod)
            {
                // Toggle the LED state
                if (blinkState == TRUE)
                {
                    turnLightOff();
                }
                else
                {
                    turnLightOn();
                }
                blinkCounter = 0;
            }
        }
        break;
    }
}
