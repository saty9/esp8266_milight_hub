cmake_minimum_required(VERSION 3.10)

# set the project name
project("milight_hub" VERSION 0.1)

# add the executable
add_executable(milight_hub src/main.cpp)

target_include_directories(milight_hub PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

include_directories(
        lib/DataStructures
        lib/Helpers
        lib/LEDStatus
        lib/MiLight
        lib/MiLightState
        lib/MQTT
        lib/Radio
        lib/Settings
        lib/SSDP
        lib/Transitions
        lib/Types
        lib/Udp
        lib/WebServer
        includes/single_json
        includes/CircularBuffer
        #includes/PiDuino_Library
        #includes/PiDuino_Library/Arduinoh
        includes/WiringPi/wiringPi
        includes/RF24
        #includes/rich_http_server/src
        #includes/path_variable_handlers/src
        #includes/arduinoWebSockets/src
)


add_custom_target(
        RF24
        COMMAND export C_INCLUDE_PATH=${CMAKE_SOURCE_DIR}/includes/WiringPi/wiringPi; make
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/includes/RF24"
)
#add_executable(myexecutable myexcutable.c)
target_link_libraries(milight_hub PUBLIC rf24)
add_dependencies(milight_hub RF24)