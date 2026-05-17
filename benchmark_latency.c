#include <stdio.h>
#include "nrfx_timer.h"
#include "inference_pipeline.h"

#define TEST_ITERATIONS 1000

static int8_t input_data[64 * 32];

void benchmark_run(void)
{
    uint32_t start;
    uint32_t end;

    float total_ms = 0.0f;

    for(int i = 0; i < TEST_ITERATIONS; i++)
    {
        start = nrfx_timer_capture();

        inference_run(input_data);

        end = nrfx_timer_capture();

        float elapsed_ms = (end - start) / 1000.0f;

        total_ms += elapsed_ms;

        printf("Inference %d: %.3f ms\n", i, elapsed_ms);
    }

    printf(
        "Mean latency: %.3f ms\n",
        total_ms / TEST_ITERATIONS
    );
}
