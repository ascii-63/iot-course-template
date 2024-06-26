cmake_minimum_required(VERSION 3.12...3.18)
set(CMAKE_CXX_STANDARD 11)

project(electrometer-edge)

find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

find_package(eclipse-paho-mqtt-c REQUIRED)

if(eclipse-paho-mqtt-c_FOUND)
    message(">_ paho.mqtt.c found!")
endif()

find_package(PahoMqttCpp REQUIRED)

if(PahoMqttCpp_FOUND)
    message(">_ paho.mqtt.cpp found!")
endif()

find_package(jsoncpp REQUIRED)

if(jsoncpp_FOUND)
    message(">_ jsoncpp found!")
endif()

find_package(PkgConfig REQUIRED)
pkg_search_module(LIBMODBUS REQUIRED libmodbus)

if(LIBMODBUS_FOUND)
    message(">_ libmodbus found!")
endif()

add_executable(pub-node ./mqtt/pub-node.cpp)
target_link_libraries(pub-node
    PahoMqttCpp::paho-mqttpp3
)

add_executable(sub-node ./mqtt/sub-node.cpp)
target_link_libraries(sub-node
    PahoMqttCpp::paho-mqttpp3
)