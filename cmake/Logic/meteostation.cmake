set(USE_FREERTOS 0)
set(USE_I2CRTC 1)
set(USE_BME280 1)
set(USE_MHZ19 1)
set(USE_LCD 1)

add_definitions(-DUSE_FREERTOS=${USE_FREERTOS})