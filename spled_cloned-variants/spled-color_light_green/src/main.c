#include "light.h"
#include "rte.h"

int main(void) {
    RteSetPowerState(POWER_STATE_ON);
    while (1)
    {
        light();
    }

    return 0;
}
