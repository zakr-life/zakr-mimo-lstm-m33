#include "inference_pipeline.h"
#include "model_data.h"

#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
#include "tensorflow/lite/version.h"

#define TENSOR_ARENA_SIZE (192 * 1024)

static uint8_t tensor_arena[TENSOR_ARENA_SIZE];

static tflite::MicroInterpreter* interpreter;
static TfLiteTensor* input_tensor;
static TfLiteTensor* output_tensor;

float cli_score;
float pac_score;
float risk_probability;
float confidence_score;

void inference_init(void)
{
    const tflite::Model* model =
        tflite::GetModel(g_mimo_lstm_int8_tflite);

    static tflite::MicroMutableOpResolver<8> resolver;

    resolver.AddFullyConnected();
    resolver.AddReshape();
    resolver.AddQuantize();
    resolver.AddDequantize();
    resolver.AddSoftmax();
    resolver.AddUnidirectionalSequenceLSTM();
    resolver.AddBidirectionalSequenceLSTM();

    static tflite::MicroInterpreter static_interpreter(
        model,
        resolver,
        tensor_arena,
        TENSOR_ARENA_SIZE
    );

    interpreter = &static_interpreter;

    interpreter->AllocateTensors();

    input_tensor = interpreter->input(0);
    output_tensor = interpreter->output(0);
}

void inference_run(const int8_t* input_buffer)
{
    for(int i = 0; i < INPUT_TIMESTEPS * INPUT_FEATURES; i++)
    {
        input_tensor->data.int8[i] = input_buffer[i];
    }

    interpreter->Invoke();

    cli_score         = output_tensor->data.int8[0] / 127.0f;
    pac_score         = output_tensor->data.int8[1] / 127.0f;
    risk_probability  = output_tensor->data.int8[2] / 127.0f;
    confidence_score  = output_tensor->data.int8[3] / 127.0f;
}
