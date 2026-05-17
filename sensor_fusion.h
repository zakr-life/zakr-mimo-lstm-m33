#ifndef SENSOR_FUSION_H
#define SENSOR_FUSION_H

#include <stdint.h>

typedef struct
{
    float eeg[8];
    float ppg;
    float eda;
    float imu[3];
} sensor_frame_t;

void sensor_fusion_init(void);
void sensor_fusion_update(sensor_frame_t *frame);

#endif
