#include "arm_math.h"
#include "feature_extract.h"

#define FFT_SIZE 256

static float32_t fft_input[FFT_SIZE];
static float32_t fft_output[FFT_SIZE];

arm_rfft_fast_instance_f32 fft_instance;

void feature_extract_init(void)
{
    arm_rfft_fast_init_f32(&fft_instance, FFT_SIZE);
}

void compute_theta_beta_ratio(
    float* eeg,
    float* theta_beta_ratio
)
{
    arm_rfft_fast_f32(
        &fft_instance,
        eeg,
        fft_output,
        0
    );

    float theta_power = 0.0f;
    float beta_power  = 0.0f;

    for(int i = 4; i < 8; i++)
    {
        theta_power += fft_output[i] * fft_output[i];
    }

    for(int i = 13; i < 30; i++)
    {
        beta_power += fft_output[i] * fft_output[i];
    }

    *theta_beta_ratio = theta_power / (beta_power + 1e-6f);
}
