#include "dimmable_light.h"
#include "rte.h"

int main(void)
{
    RteSetPowerState(POWER_STATE_ON);
    while (1)
    {
        dimmable_light();
    }

    return 0;
}
