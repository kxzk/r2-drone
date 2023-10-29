<h3 align="center">R2</h3>

<br>

> `Goal` → AI voice & vision autonomous drone + chatbot, à la [R2](https://www.starwars.com/databank/r2-d2/).

<br>
<br>

![droneoverview](https://i.imgur.com/9pmgEsE.jpg)

<br>
<br>

* `v1.5 - chatbot + speaker`

```text
- [ ] get microphone working + parse voice input
- [ ] send to chatGPT API
- [ ] return response via speaker (maybe use 11 labs for voice generation?)
```

<br>

* `v2 - simplify and cleanup`

```text
- [ ] restructure Tello API to C++ class
- [ ] tighten up delays between commands
- [ ] add `forward`, `back` and `turning` commands to class
- [x] re-work layout to function solely from ESP32
```

<br>

* `v3 - infinity and beyond`

```text
- [ ] replace gravity voice sensor with Arduino Nano 33 BLE Sense
- [ ] add voice recognition via Tensorflow TinyML
- [ ] add vision support/segmentation via openCV on main comp
- [ ] work on chatGPT instruction generation via API (see Microsoft paper)
```

<br>

* `v4 - fastSAM + OpenCV`

```text
- [ ] investigate getting FastSAM on microcontroller
```

<br>
<br>

#### `drone`

* [tello drone](https://www.ryzerobotics.com/tello)

<br>

#### `papers`

* [PromptCraft Robotics](https://github.com/microsoft/PromptCraft-Robotics)
* [Unifying Foundation Models with Quadrotor Control for Visual Tracking Beyond Object Categories](https://arxiv.org/pdf/2310.04781.pdf)
* [VOYAGER: An Open-Ended Embodied Agent with Large Language Models](https://arxiv.org/pdf/2305.16291.pdf)
* [HABITAT 3.0: A CO-HABITAT FOR HUMANS, AVATARS AND ROBOTS](https://ai.meta.com/static-resource/habitat3)
* [EUREKA: HUMAN-LEVEL REWARD DESIGN VIA CODING LARGE LANGUAGE MODELS](https://arxiv.org/pdf/2310.12931.pdf)

<br>

#### `arduino`

* [arduino nano esp32](https://store-usa.arduino.cc/products/nano-esp32?selectedStore=us)
* [arduino nano 33 ble sense](https://store-usa.arduino.cc/products/arduino-nano-33-ble-sense?selectedStore=us)
* [gravity: ai offline learning voice recognition sensor](https://www.dfrobot.com/product-2665.html)

<br>

#### `quadcopter math/physics`

* [quadcopter dynamics and simulation](https://andrew.gibiansky.com/blog/physics/quadcopter-dynamics/)
* [3D quadcopter, derivation, simulation, animation](https://www.youtube.com/watch?v=4hlQ2pf842U)

<br>

#### `arduino reference`

* [arduino nano esp32 cheatsheet](https://docs.arduino.cc/tutorials/nano-esp32/cheat-sheet)
* [arduino nano esp32 datasheet](https://docs.arduino.cc/resources/datasheets/ABX00083-datasheet.pdf)
* [arduino libraries documentation](https://www.arduino.cc/reference/en/libraries/)
* [gravity: voice sensor github](https://github.com/DFRobot/DFRobot_DF2301Q?tab=readme-ov-file)
* [gravity: voice sensor docs](https://wiki.dfrobot.com/SKU_SEN0539-EN_Gravity_Voice_Recognition_Module_I2C_UART#target_2)

<br>

#### `c++ libraries`

* [opencv](https://github.com/opencv/opencv)
* [ftxui](https://github.com/ArthurSonzogni/FTXUI)
* [imtui](https://github.com/ggerganov/imtui)

<br>

#### `references`

* [djitellopy lib](https://github.com/damiafuentes/DJITelloPy)
* [tello sdk v1.3](https://dl-cdn.ryzerobotics.com/downloads/tello/20180910/Tello%20SDK%20Documentation%20EN_1.3.pdf)
* [tello python lib](https://github.com/dji-sdk/Tello-Python)
* [tello async lib](https://github.com/robagar/tello-asyncio)
* [tello python examples](https://github.com/dji-sdk/Tello-Python)
* [tello arduino](https://github.com/akshayvernekar/telloArduino)
