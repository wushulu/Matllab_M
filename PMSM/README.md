# PMSM Motor Control Project

## 简介 Introduction
本项目是一个基于 Matlab/Simulink 的永磁同步电机 (PMSM) 控制系统设计与仿真项目。项目采用了基于模型的设计 (Model-Based Design, MBD) 方法，涵盖了从基础算法仿真到针对 STM32 微控制器的代码生成与硬件在环测试。

## 环境要求 Prerequisites
-   **Matlab/Simulink**: 推荐使用较新版本以支持代码生成功能。
-   **硬件支持包**:
    -   STM32CubeMX
    -   Simulink Coder / Embedded Coder
    -   STMicroelectronics STM32 Processors support package
-   **目标硬件**: 主要针对 STM32G4 系列 (如 Nucleo-G431RB) 及 STM32F4 系列。

## 文件结构说明 File Structure Description

本目录下的子文件夹按功能模块和开发阶段进行划分：

### 基础算法与变换
-   **`01`**: 基础测试或初始模型。
-   **`02Clarke Park`**: Clarke 变换和 Park 变换的仿真与实现。
-   **`03SVPWM`**: 空间矢量脉宽调制 (SVPWM) 算法模型。

### 控制环路设计
-   **`04PI`**: PI 控制器设计与仿真。
-   **`10G431currentloop`**: 针对 G431 芯片的电流环控制模型。
-   **`15PICurrentLoop`**: PI 电流环相关设计。

### 传感器处理
-   **`05Hall`**: Hall 传感器信号处理基础。
-   **`06Hallhareware`**: Hall 传感器硬件接口与处理。
-   **`07Hallcorrection`**: Hall 角度校准算法。
-   **`09G431Hallcorrection`**: 针对 G431 的 Hall 校准实现。

### 高级控制与启动
-   **`14IFstart`**: I/F (电流/频率) 开环启动策略。
-   **`16Motorparasmeters` / `16MotorparasmetersM`**: 电机参数辨识相关模型与脚本。
-   **`13PowerCaculate`**: 功率计算模块。

### 硬件运行与调试
-   **`08Runmotor`**: 实机运行测试模型。
-   **`11F4demotest`**: STM32F4 系列的演示测试工程。
-   **`12RunG4withVOFA`**: 配合 VOFA+ 串口示波器进行 G4 系列芯片的实时调试与波形监控。

## 使用说明 Usage
1.  **打开模型**: 使用 Matlab 打开对应的文件夹，双击 `.slx` 文件加载 Simulink 模型。
2.  **加载参数**: 部分模型可能依赖参数脚本 (如 `Motorparasmeters` 文件夹下的 `.m` 文件)，请先运行脚本加载变量到 workspace。
3.  **代码生成**: 确保已安装对应的 STM32 硬件支持包，并在模型配置参数中选择了正确的硬件板卡 (Hardware Board)，即可进行 Build 和下载。

---
*Created by Antigravity Assistant*
