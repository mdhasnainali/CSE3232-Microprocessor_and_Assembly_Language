
# LED Blinking Examples on STM32F103C8T6

This repository contains various examples for implementing LED blinking on the STM32F103C8 microcontroller. Each example demonstrates a different method for controlling an LED on the board using registers and configurations provided by the STM32 HAL. 

## Project Structure

Each project example is contained in its own folder with the necessary files for building and running the code.

```
.
├── LED_Blink_Using_Loop
│   └── main.c                # LED Blinking with simple loop delay
├── LED_Blink_Using_SysTick
│   └── main.c                # LED Blinking using SysTick timer
├── LED_Blink_Using_TIM2
│   └── main.c                # LED Blinking using Timer 2
├── Resister_Level_Programming_SysTick
│   └── main.c                # LED Blinking with SysTick at register level
└── Resister_Level_Programming_TIM2
    └── main.c                # LED Blinking with Timer 2 at register level
```

## Getting Started

1. Clone this repository.
2. Open any example project (main.c file) in your preferred IDE for STM32 development (e.g., Keil, STM32CubeIDE). I have used the Kail IDE.
3. Compile and upload the code to the STM32F103C8T6 microcontroller.

## Examples

### 1. LED Blink Using Loop Delay
- **Path**: `LED_Blink_Using_Loop/main.c`
- **Description**: This example toggles an LED connected to GPIO pin PC13 using a simple loop delay. It is a basic method that relies on software delay.

### 2. LED Blink Using SysTick
- **Path**: `LED_Blink_Using_SysTick/main.c`
- **Description**: This example configures the SysTick timer to create a delay, allowing the LED to toggle periodically. SysTick provides a more reliable timing solution than a loop delay.

### 3. LED Blink Using Timer 2 (TIM2)
- **Path**: `LED_Blink_Using_TIM2/main.c`
- **Description**: This example utilizes Timer 2 to control the LED blink timing. It shows how to configure TIM2 and use its update event to toggle the LED.

### 4. Register-Level Programming with SysTick
- **Path**: `Resister_Level_Programming_SysTick/main.c`
- **Description**: This example demonstrates direct register manipulation for configuring the SysTick timer, providing an in-depth look at SysTick's operation at the hardware level.

### 5. Register-Level Programming with TIM2
- **Path**: `Resister_Level_Programming_TIM2/main.c`
- **Description**: Similar to the previous example, this code directly accesses hardware registers to configure TIM2, offering low-level control over the timer and LED blinking.

## Requirements

- **Hardware**: STM32F103C8T6 microcontroller 
- **Software**: STM32 development IDE such as Keil uVision (You can use any IDE like STM32CubeIDE, or any other environment supporting STM32 development. Just use the main.c files)

## License

This project is open-source and available under the MIT License.

## Author

Md. Hasnain Ali  
Github: [mdhasnainali](https://github.com/mdhasnainali/CSE3232-Microprocessor_and_Assembly_Language)
