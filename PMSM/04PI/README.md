# 04PI - PI Controller & Loop Design

## 简介 Introduction
本文件夹用于 PI (比例-积分) 控制器的设计、仿真与参数调试。PI 控制器是 FOC 中电流环和速度环的核心调节器。

## 文件列表 File List
-   **`STMF4Hall.*`**: 包含针对 STM32F4 的带有霍尔传感器的工程编译文件 (elf, hex, bin) 及 Simulink 模型。
-   **`mcb_pmsm_offset_data.m`**: 可能涉及电机参数或传感器偏置校准的数据脚本。
-   **`STM32F4Generation`**: 生成的代码文件存放目录。
