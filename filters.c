void lowpass_filter(float *data, int len)
{
    for (int i = 1; i < len; i++)
    {
        data[i] = 0.8f * data[i - 1] + 0.2f * data[i];
    }
}
