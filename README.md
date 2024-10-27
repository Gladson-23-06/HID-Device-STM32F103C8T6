

# STM32 USB HID Keyboard Implementation

## Overview
This project implements a USB Human Interface Device (HID) using an STM32 microcontroller. It enables the STM32 board to act as a USB keyboard, facilitating basic keyboard interactions across multiple operating systems, including Windows, Linux, and Mac.

## Features
- **USB HID Configuration:** Fully integrated HID support for STM32 microcontrollers.
- **Keyboard Simulation:** Simulates standard keyboard inputs.
- **Cross-Platform Compatibility:** Works seamlessly across Windows, Linux, and Mac.
- **Example Code:** Includes examples for keystroke generation and USB communication.

## Getting Started

### Prerequisites
- **Hardware:**
  - STM32 development board (e.g., STM32F103C8T6).
  - USB cable for interfacing with the host computer.
- **Software:**
  - [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html) (or another compatible IDE).
  - ARM-GCC toolchain installed and configured.

### Installation

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/your-repository-name.git
   ```
   
2. **Navigate to the Project Directory:**
   ```bash
   cd your-repository-name
   ```

3. **Set Up Environment Variables:**
   Add the following paths to your environment variables:
   ```
   HID\Tools\arm-gnu-toolchain-13.3\bin
   HID\Tools\Make\bin
   HID\Tools\OpenOCD\bin
   ```
 

4. **Verify the Toolchain Installation:**
   - open a command prompt.  
  ```
   make --version

   openocd --version

   arm-none-eabi-gcc --version
   

   ```
4. **Open CMD in the Project Path:**
   - Navigate to the directory where your project is located and open a command prompt.

5. **Compile the Code:**
   Use the following command to compile the text files into binary:
   ```bash
   HID.exe -I "C:\Users\don\Desktop\Cube MX\Script 2.txt"
   ```

6. **Upload Code to STM32 Board:**
   Execute the following command to flash the compiled code to the STM32 board:
   ```bash
   make flash
   ```

## File Structure
- **`main.c`**: Contains the main logic for the USB HID keyboard implementation.
- **`USB.c` / `USB.h`**: Handles USB communication and HID descriptor definitions.
- **`keyboard_Report_Descriptor.h`**: Defines the report descriptor for the HID keyboard.
- **`startup_stm32f103xb.s`**: Startup file for STM32F103C8T6 microcontroller.
- **`Makefile`**: Build script for compiling and flashing the code.

## How to Use
1. **Open the project** in STM32CubeIDE or your preferred IDE.
2. **Connect the STM32 board** to the host computer using a USB cable.
3. **Build and flash** the code to your STM32 board.
4. The board will be recognized as a USB keyboard by the host system, allowing simulated keystrokes.

## Next Steps
- Add more complex keyboard functionalities (e.g., macros, multimedia keys).
- Optimize the HID report descriptor for different use cases.
- Enhance compatibility with various OS-specific keyboard shortcuts.

## Contributing
Contributions are welcome! Please **fork** the repository, create a new branch, and submit a **pull request** with your enhancements.

## Connect with Me
- **[LinkedIn](https://www.linkedin.com/in/don-gladson/)**
- **[YouTube](https://www.youtube.com/@GladsonTechie)**
- **[Instagram](https://www.instagram.com/gladson_techie/)**

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
Special thanks to the STM32 community and all contributors for their valuable resources and guidance.

---

Feel free to edit this README further to better suit your project or add any additional information!
