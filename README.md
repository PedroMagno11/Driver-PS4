# PS4 Controller Driver (HID) - Linguagem C

Este projeto implementa um driver em linguagem C para leitura 
de comandos do controle DualShock 4 (PS4), utilizando a 
biblioteca [hidapi](https://github.com/libusb/hidapi). O 
driver é capaz de detectar o controle, abrir comunicação via USB e mapear todos os botões e eixos do controle.

## 📦 Funcionalidades

- Detecta automaticamente o controle PS4 conectado via USB
- Lê pacotes de dados do controle em tempo real
- Mapeia os principais botões e eixos analógicos (X, O, L1, R1, analógicos, etc.)
- Permite expansão para suporte a feedback tátil (rumble), LED e touchpad

## 🛠 Requisitos

- CMake
- GCC ou MinGW (Windows)
- [hidapi](https://github.com/libusb/hidapi) instalado no sistema
