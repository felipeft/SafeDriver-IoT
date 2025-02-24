<<<<<<< HEAD
# 🚗 SafeDriverRTOS - Carro Autônomo com FreeRTOS

SafeDriverRTOS é um projeto de um carro autônomo utilizando **Raspberry Pi Pico** e **FreeRTOS**. O veículo se movimenta de forma autônoma, utilizando um **sensor ultrassônico** para detectar obstáculos e ajustar sua rota. Os motores são controlados por uma **ponte H**, garantindo uma resposta eficiente às leituras do sensor.

---

## 🎯 **Características**
- ✅ **Plataforma:** Raspberry Pi Pico
- ✅ **RTOS:** FreeRTOS para gerenciamento de tarefas em tempo real
- ✅ **Sensoriamento:** Sensor ultrassônico para evitar obstáculos
- ✅ **Movimentação:** 4 motores (2 ligados em série), controlados por uma ponte H
- ✅ **Estrutura modular:** Código organizado para facilitar manutenção e expansão

---

## 📸 **Demonstração**
(Aqui você pode adicionar imagens ou GIFs do carro em funcionamento)

![Carro Autônomo](./images/demo.gif)  
📌 _Imagem ilustrativa do funcionamento do SafeDriverRTOS_

---

## 🛠 **Componentes Utilizados**
### 🔹 Hardware
- Raspberry Pi Pico
- Sensor Ultrassônico HC-SR04
- Ponte H (para controle dos motores)
- 4 motores (2 pares ligados em série)
- Fonte de alimentação compatível
- Estrutura do chassi e rodas

### 🔹 Software
- FreeRTOS
- Pico SDK
- Código-fonte em C

=======
# Raspberry Pi Pico W FreeRTOS Starter - In C

This is a simple blinky starter project for Raspberry Pi Pico W that uses FreeRTOS

## Important Setup

- Clone [Pico SDK](https://github.com/raspberrypi/pico-sdk) and inside the cloned SDK directory run `git submodule update --init` to init all submodules

- Clone [FreeRTOS Kernel](https://github.com/FreeRTOS/FreeRTOS-Kernel)

- Pico SDK should be present in the machine and it's path should be used as an environment variable as `PICO_SDK_PATH` pointing to the cloned Pico SDK dir

- FreeRTOS-Kernel should be present in the machine and it's path should be used as an environment variable as `FREERSTOS_KERNEL_PATH` pointing to the cloned FreeRTOS-Kernel dir

These environment variable should be used when calling `CMake` or defined in VSCode(**RECOMENDED**) using [this setup](https://www.youtube.com/watch?v=BAoTBg8MJJ4) that uses the `CMake Tools` extension.

## Project Rename

To rename the project simply open the root `CMakeLists.txt` and change `project(pico_freertos C CXX ASM)` to `project(your_project_name C CXX ASM)`.

## Outputs

After building, your binary will be under `build/src/src.uf2`. Take the `src.uf2` and push it you Pico W with `BOOTSEL`.

NOTE: The [setup video](https://www.youtube.com/watch?v=BAoTBg8MJJ4) mentioned before should show you how to build on VS Code.

### HAPPY CODING & TINKERING

**Inspired by the [Learn Embedded Systems video series](https://www.youtube.com/watch?v=jCZxStjzGA8&list=PLEB5F4gTNK68IlRIJtcJ_2cW4dSdmreTw&index=14) on YouTube.**
>>>>>>> abb5161 (Adicionando arquivos do projeto SafeDriverRTOS)
