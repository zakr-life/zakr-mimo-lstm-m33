#ifndef INFERENCE_PIPELINE_H
#define INFERENCE_PIPELINE_H

#include <stdint.h>

#define INPUT_TIMESTEPS 64
#define INPUT_FEATURES  32
#define OUTPUT_CLASSES  4

void inference_init(void);
void inference_run(const int8_t* input_buffer);

extern float cli_score;
extern float pac_score;
extern float risk_probability;
extern float confidence_score;

#endif
