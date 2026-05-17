#include "ring_buffer.h"

void rb_init(ring_buffer_t *rb)
{
    rb->head = 0;
    rb->tail = 0;
}

void rb_push(ring_buffer_t *rb, float value)
{
    rb->buffer[rb->head++] = value;
    rb->head %= RB_SIZE;
}

float rb_pop(ring_buffer_t *rb)
{
    float v = rb->buffer[rb->tail++];
    rb->tail %= RB_SIZE;
    return v;
}
