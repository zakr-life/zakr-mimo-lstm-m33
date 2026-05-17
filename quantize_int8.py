import tensorflow as tf

converter = tf.lite.TFLiteConverter.from_saved_model(
    "mimo_lstm_fp32"
)

converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.target_spec.supported_ops = [
    tf.lite.OpsSet.TFLITE_BUILTINS_INT8
]

converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8


def representative_dataset():
    for _ in range(1000):
        yield [tf.random.normal([1, 64, 32])]

converter.representative_dataset = representative_dataset

quantized_model = converter.convert()

with open("mimo_lstm_int8.tflite", "wb") as f:
    f.write(quantized_model)
