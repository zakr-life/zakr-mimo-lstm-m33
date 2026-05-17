#include "cli_score.h"

float compute_cli_score(float *features, int len)
{
    float score = 0.0f;

    for (int i = 0; i < len; i++)
        score += features[i] * 0.01f;

    return score;
}
