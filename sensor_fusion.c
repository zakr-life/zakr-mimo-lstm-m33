#include "sensor_fusion.h"
#include <stdlib.h>

void sensor_fusion_init(void)
{
}

void sensor_fusion_update(sensor_frame_t *frame)
{
    for (int i = 0; i < 8; i++)
        frame->eeg[i] = (float)rand() / RAND_MAX;

    frame->ppg = 0.5f;
    frame->eda = 0.2f;
}
