#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>

#define RB_SIZE 256

typedef struct
{
    float buffer[RB_SIZE];
    uint16_t head;
    uint16_t tail;
} ring_buffer_t;

void rb_init(ring_buffer_t *rb);
void rb_push(ring_buffer_t *rb, float value);
float rb_pop(ring_buffer_t *rb);

#endif
