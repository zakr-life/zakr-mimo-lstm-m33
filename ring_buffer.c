#include "ring_buffer.h"

static int8_t circular_buffer[
    INPUT_TIMESTEPS * INPUT_FEATURES
];

static uint32_t write_index = 0;

void ring_buffer_push(int8_t value)
{
    circular_buffer[write_index] = value;

    write_index++;

    if(write_index >= INPUT_TIMESTEPS * INPUT_FEATURES)
    {
        write_index = 0;
    }
}
