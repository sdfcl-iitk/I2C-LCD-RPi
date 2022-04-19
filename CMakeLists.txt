
cmake_minimum_required(VERSION 3.15)
project(i2c-lcd-rpi)

add_library(i2c-lcd-rpi include/LiquidCrystal_I2C.cpp)
target_link_libraries(i2c-lcd-rpi i2c)
set_target_properties(i2c-lcd-rpi PROPERTIES LINKER_LANGUAGE CXX)
