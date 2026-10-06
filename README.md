# FOC 电机控制代码仓库

STM32G431 平台的 FOC（磁场定向控制）学习与开发代码。
开发工具链：**STM32CubeMX + Keil MDK(uVision) + VS Code(EIDE 插件)**。

## 目录结构

```
FOC-3.0t/                  FOC 3.0T 主工程（CubeMX 工程）
├── FOC-3.0t.ioc           CubeMX 图形化配置（改外设就开它）
├── .mxproject             CubeMX 工程元数据
├── Core/                  CubeMX 自动生成的外设初始化代码
│   ├── Inc/               main.h / adc.h / tim.h ...
│   └── Src/               main.c / adc.c / tim.c ...
└── MDK-ARM/               Keil MDK 工程目录
    ├── FOC-3.0t.uvprojx   Keil 工程文件（双击打开）
    ├── FOC-3.0t.uvoptx    调试器/断点配置
    ├── startup_stm32g431xx.s
    ├── .eide/             EIDE 插件配置（VS Code 编译用）
    └── foc_*.c / bsp_*.c / app_*.c    ← 自己写的代码都在这里
docs/git-guide.md          Git / GitHub 日常使用手册
```

## 自己写的代码在哪

全部在 `FOC-3.0t/MDK-ARM/` 下：

| 文件 | 作用 |
|---|---|
| `foc_loop.c/h` | 电流环、速度环 PI 调节器 |
| `foc_svpwm.c/h` | SVPWM 空间矢量调制 |
| `foc_math.c/h` | Clark / Park 变换等数学工具 |
| `foc_filter.c/h` | 滤波器（低通、陷波等） |
| `foc_state.c/h` | 电机运行状态机 |
| `foc_config.c/h` | 参数配置 |
| `app_motor.c/h` | 电机应用层 |
| `app_filter.c/h` | 滤波应用层 |
| `app_vofa.c/h` | VOFA+ 上位机波形通信 |
| `bsp_adc.c/h` | 电流采样 ADC |
| `bsp_pwm.c/h` | PWM 输出 |
| `bsp_tim.c/h` | 定时器 |
| `bsp_encoder.c/h` | 编码器接口 |
| `bsp_io.c/h` `bsp_led.c/h` | IO / LED |
| `bsp_protect.c/h` | 过流、过压保护 |
| `bsp_config.h` | 底层参数配置 |

## 怎么编译

- **Keil uVision**：打开 `FOC-3.0t/MDK-ARM/FOC-3.0t.uvprojx`，直接 Build / Download。
- **VS Code**：用 **EIDE** 插件打开该工程，可编译、烧录、串口监视，不用开 Keil。

## ⚠️ 换电脑要注意

本工程的 HAL 库和 CMSIS 是通过**绝对路径**引用的 CubeMX 仓库：

```
E:/STM32CubeMX/STM32Cube_FW_G4_V1.6.3/Drivers/STM32G4xx_HAL_Driver/...
```

也就是说 **仓库里只存了你自己写的代码**，没有存 ST 的 HAL 库源码。
在新电脑上克隆后，需要：

1. 装好 **STM32CubeMX**，并在 `Help → Manage embedded software packages` 里安装
   **STM32Cube MCU Package for STM32G4 Series V1.6.3**（版本要一致）；
2. 或者把 CubeMX 仓库放到与原来一致的路径 `E:\STM32CubeMX\` 下。

> 想彻底解决这个问题，可以在 CubeMX 里改：
> `Project Manager → Code Generator → 勾选 "Copy only the necessary library files"`，
> 重新生成后工程根目录会出现 `Drivers/` 文件夹，仓库就自包含了（代价是多约 10 MB）。

## 版本管理

日常提交看 [docs/git-guide.md](docs/git-guide.md)。
