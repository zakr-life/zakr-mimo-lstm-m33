import tensorflow as tf

converter = tf.lite.TFLiteConverter.from_saved_model('.')
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.inference_input_type = tf.int8
converter.inference_output_type = tf.int8

model = converter.convert()

with open('mimo_lstm_int8.tflite', 'wb') as f:
    f.write(model)
