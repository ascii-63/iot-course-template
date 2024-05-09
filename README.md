# IoT Course Demo Templates
This repository comprises a collection of C++ code templates utilized in demos for the Mobiphone IoT Course.

## Important note:
Ensure that your machine is running Ubuntu or Windows Subsystem for Linux (WSL) with Ubuntu, preferably version 20.04 and above.

## Requirement:
```bash
sudo apt-get update 
sudo apt-get install pkg-config git \
sudo apt-get install mosquitto mosquitto-clients
```
```bash
sudo apt-get install build-essential gcc make cmake cmake-gui cmake-curses-gui \
&& sudo apt-get install libssl-dev \
&& sudo apt-get install doxygen graphviz
```
## Dependencies:
  1. Paho MQTT C library:
```bash
git clone https://github.com/eclipse/paho.mqtt.c.git
cd paho.mqtt.c
git checkout v1.3.13

cmake -Bbuild -H. -DPAHO_ENABLE_TESTING=OFF -DPAHO_BUILD_STATIC=ON \
    -DPAHO_WITH_SSL=ON -DPAHO_HIGH_PERFORMANCE=ON
sudo cmake --build build/ --target install
sudo ldconfig
```
  2. Paho MQTT CPP library:
```bash
git clone https://github.com/eclipse/paho.mqtt.cpp
cd paho.mqtt.cpp

cmake -Bbuild -H. -DPAHO_BUILD_STATIC=ON \
    -DPAHO_BUILD_DOCUMENTATION=ON -DPAHO_BUILD_SAMPLES=ON
sudo cmake --build build/ --target install
sudo ldconfig
```
