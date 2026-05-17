#include "pac_quality.h"

float compute_pac_quality(float *features, int len)
{
    float sum = 0.0f;

    for (int i = 0; i < len; i++)
        sum += features[i];

    return sum / len;
}
