#include <math.h>

void compute_fft(float *input, float *output, int n)
{
    for (int i = 0; i < n; i++)
        output[i] = fabs(input[i]);
}
