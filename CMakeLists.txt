cmake_minimum_required(VERSION 3.23)
project(KeyboardCombo C)

set(CMAKE_C_STANDARD 11)

add_executable(KeyboardCombo main.c keyboard/linkedlist.c keyboard/media_combo.c keyboard/process_combo.c)
