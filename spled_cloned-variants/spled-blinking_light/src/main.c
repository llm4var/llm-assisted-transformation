#include "blinking_light.h"
#include "rte.h"

int main(void)
{
    RteSetPowerState(POWER_STATE_ON);
    while (1)
    {
        blinking_light();
    }

    return 0;
}
