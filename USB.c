/*
 * USB.c
 *
 * Created on: Oct 24, 2024
 * Author: V.V. Don Gladson
 *
 * LinkedIn: https://www.linkedin.com/in/don-gladson/
 * YouTube: https://www.youtube.com/@GladsonTechie
 * Instagram: https://www.instagram.com/gladson_techie/
 * GitHub: https://github.com/Gladson-23-06
 */

// Include the header file
#include "USB.h"

// HID keyboard report global variable definition
keyboardReportDes HIDkeyBoard = {0, 0, 0, 0, 0, 0, 0, 0};

// Private function prototypes
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void Error_Handler(void);
static uint8_t CharToKeycode(char c, uint8_t* modifier);

static uint8_t CharToKeycode(char c, uint8_t* modifier) {
    *modifier = 0x00;  // No modifier by default

    // Check if character is uppercase 'A' to 'Z'
    if (c >= 'A' && c <= 'Z') {
        *modifier = LSHIFT;  // Shift modifier for uppercase
        return (c - 'A' + 0x04);  // Map to HID keycode
    }
    // Check if character is lowercase 'a' to 'z'
    else if (c >= 'a' && c <= 'z') {
        return (c - 'a' + 0x04);  // Map to HID keycode
    }
    // Check if character is space
    else if (c == ' ') {
        return SPACE;  // HID keycode for space
    }
    // Check if character is a digit '0' to '9'
    else if (c >= '0' && c <= '9') {
        if (c == '0') {
            return 0x27;  // HID keycode for '0'
        } else {
            return (c - '1' + 0x1E);  // Map to HID keycode for '1' to '9'
        }
    }

    // Check for special characters
    switch (c) {
        case '-': return 0x2D;
        case '=': return 0x2E;
        case '[': return 0x2F;
        case ']': return 0x30;
        case '\\': return 0x31;
        case ';': return 0x33;
        case '\'': return 0x34;
        case '`': return 0x35;
        case ',': return 0x36;
        case '.': return 0x37;
        case '/': return 0x38;
        case ':': *modifier = LSHIFT; return 0x33;
        case '\"': *modifier = LSHIFT; return 0x34;
        case '!': *modifier = LSHIFT; return 0x1E;
        case '@': *modifier = LSHIFT; return 0x1F;
        case '#': *modifier = LSHIFT; return 0x20;
        case '$': *modifier = LSHIFT; return 0x21;
        case '%': *modifier = LSHIFT; return 0x22;
        case '^': *modifier = LSHIFT; return 0x23;
        case '&': *modifier = LSHIFT; return 0x24;
        case '*': *modifier = LSHIFT; return 0x25;
        case '(': *modifier = LSHIFT; return 0x26;
        case ')': *modifier = LSHIFT; return 0x27;
        case '<': *modifier = LSHIFT; return 0x36;
        case '>': *modifier = LSHIFT; return 0x37;
        case '?': *modifier = LSHIFT; return 0x38;
        default: return 0;  // Return 0 if character is not supported
    }
}


// Function to send a string as keystrokes via USB HID
void SendString(const char* str) {
    while (*str) {
        uint8_t modifier = 0;
        uint8_t keycode = CharToKeycode(*str, &modifier);

        // Set the modifier and keycode
        HIDkeyBoard.MODIFIER = modifier;
        HIDkeyBoard.KEYCODE1 = keycode;

        // Send the key press report
        USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&HIDkeyBoard, sizeof(HIDkeyBoard));
        HAL_Delay(20);  // Short delay to emulate key press duration

        // Release the key
        HIDkeyBoard.MODIFIER = 0x00;
		HIDkeyBoard.KEYCODE1 = 0x00;
		USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&HIDkeyBoard, sizeof(HIDkeyBoard));
        HAL_Delay(80);  // Delay between keystrokes

        str++;  // Move to the next character
    }
}

// Function to send a shortcut with modifiers
void Short_Cut(uint8_t modifiers, uint8_t key) {
	HAL_Delay(50);
    // Set the modifier keys and keycode
    HIDkeyBoard.MODIFIER = modifiers;
    HIDkeyBoard.KEYCODE1 = key;

    // Send the key press report
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&HIDkeyBoard, sizeof(HIDkeyBoard));
    HAL_Delay(20);  // Short delay to emulate key press duration

    // Release all keys
    HIDkeyBoard.MODIFIER = 0x00;
	HIDkeyBoard.KEYCODE1 = 0x00;
	USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&HIDkeyBoard, sizeof(HIDkeyBoard));
    HAL_Delay(100);  // Delay after releasing the keys
}

// Function to send a single key press
void Press_Key(uint8_t key) {
	HAL_Delay(50);
    // Set the keycode
    HIDkeyBoard.MODIFIER = 0x00;
    HIDkeyBoard.KEYCODE1 = key;

    // Send the key press report
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&HIDkeyBoard, sizeof(HIDkeyBoard));
    HAL_Delay(20);  // Short delay to emulate key press duration

    // Release all keys
    HIDkeyBoard.MODIFIER = 0x00;
    HIDkeyBoard.KEYCODE1 = 0x00;
    USBD_HID_SendReport(&hUsbDeviceFS, (uint8_t*)&HIDkeyBoard, sizeof(HIDkeyBoard));
    HAL_Delay(100);  // Delay after releasing the keys
}

// System clock configuration
void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                                  |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
    PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL_DIV1_5;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit);
}

// GPIO initialization
void MX_GPIO_Init(void) {
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
}

// Error handler function
void Error_Handler(void) {
    __disable_irq();
    while (1) {}
}
