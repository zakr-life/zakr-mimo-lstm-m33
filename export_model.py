import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM
from tensorflow.keras.layers import Dense
from tensorflow.keras.layers import Bidirectional

SEQ_LEN = 64
FEATURES = 32

model = Sequential([
    Bidirectional(
        LSTM(64, return_sequences=True),
        input_shape=(SEQ_LEN, FEATURES)
    ),
    LSTM(32),
    Dense(16, activation='relu'),
    Dense(4, activation='sigmoid')
])

model.compile(
    optimizer='adam',
    loss='mse',
    metrics=['mae']
)

model.summary()

model.save("mimo_lstm_fp32")
