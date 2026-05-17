cmake_minimum_required(VERSION 3.20)
project(zakr_mimo_lstm C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    firmware
    firmware/dsp
    firmware/tflm
)

add_executable(zakr_firmware
    firmware/main.c
    firmware/inference_pipeline.c
    firmware/sensor_fusion.c
    firmware/feature_extract.c
    firmware/ring_buffer.c
    firmware/pac_quality.c
    firmware/cli_score.c
    firmware/dsp/fft.c
    firmware/dsp/filters.c
    benchmark/benchmark_latency.c
)
