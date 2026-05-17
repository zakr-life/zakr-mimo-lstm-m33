cmake_minimum_required(VERSION 3.20)
project(zakr_mimo_lstm C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

include_directories(
    firmware
    firmware/dsp
    firmware/tflm
