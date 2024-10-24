/*
 * USB.h
 *
 * Created on: Oct 24, 2024
 * Author: V.V. Don Gladson
 *
 * LinkedIn: https://www.linkedin.com/in/don-gladson/
 * YouTube: https://www.youtube.com/@GladsonTechie
 * Instagram: https://www.instagram.com/gladson_techie/
 * GitHub: https://github.com/Gladson-23-06
 */

#ifndef INC_USB_H_
#define INC_USB_H_

// Include necessary headers
#include "usb_device.h"
#include "usbd_hid.h"

// Extern declaration for the USB device handle
extern USBD_HandleTypeDef hUsbDeviceFS;

// Keyboard Report Descriptor Structure
typedef struct {
    uint8_t MODIFIER;  // Modifier keys
    uint8_t RESERVED;  // Reserved byte (always 0)
    uint8_t KEYCODE1;  // Keycode 1
    uint8_t KEYCODE2;  // Keycode 2
    uint8_t KEYCODE3;  // Keycode 3
    uint8_t KEYCODE4;  // Keycode 4
    uint8_t KEYCODE5;  // Keycode 5
    uint8_t KEYCODE6;  // Keycode 6
} keyboardReportDes;

// Extern declaration for the keyboard report descriptor
extern keyboardReportDes HIDkeyBoard;

// ---------------------------------------------- Function Declarations ----------------------------------------- //

// Send a shortcut with modifiers
void Short_Cut(uint8_t modifiers, uint8_t key);

// Send a single key press
void Press_Key(uint8_t key);

// Send a string as keystrokes via USB HID
void SendString(const char* str);

// System-specific functions
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void Error_Handler(void);


// --------------------------------------------- Keys Declarations ----------------------------------------------- //

// Modifier Key Definitions
#define LCTRL      0x01  // Left Control
#define LSHIFT     0x02  // Left Shift
#define LALT       0x04  // Left Alt
#define LGUI       0x08  // Left GUI (Windows/Command key)
#define RCTRL      0x10  // Right Control
#define RSHIFT     0x20  // Right Shift
#define RALT       0x40  // Right Alt
#define RGUI       0x80  // Right GUI (Windows/Command key)

// Alphabet Keycodes (HID usage IDs)
#define A          0x04
#define B          0x05
#define C          0x06
#define D          0x07
#define E          0x08
#define F          0x09
#define G          0x0A
#define H          0x0B
#define I          0x0C
#define J          0x0D
#define K          0x0E
#define L          0x0F
#define M          0x10
#define N          0x11
#define O          0x12
#define P          0x13
#define Q          0x14
#define R          0x15
#define S          0x16
#define T          0x17
#define U          0x18
#define V          0x19
#define W          0x1A
#define X          0x1B
#define Y          0x1C
#define Z          0x1D

// Digit Keycodes
#define N1         0x1E
#define N2         0x1F
#define N3         0x20
#define N4         0x21
#define N5         0x22
#define N6         0x23
#define N7         0x24
#define N8         0x25
#define N9         0x26
#define N0         0x27

// Special Keycodes
#define ENTER      0x28
#define ESC        0x29
#define BACKSPACE  0x2A
#define TAB        0x2B
#define SPACE      0x2C
#define MINUS      0x2D
#define EQUAL      0x2E
#define LEFT_BRACE 0x2F
#define RIGHT_BRACE 0x30
#define BACKSLASH  0x31
#define HASH_TILDE 0x32
#define SEMICOLON  0x33
#define APOSTROPHE 0x34
#define GRAVE      0x35
#define COMMA      0x36
#define DOT        0x37
#define SLASH      0x38
#define CAPS_LOCK  0x39

// Function Keycodes
#define F1         0x3A
#define F2         0x3B
#define F3         0x3C
#define F4         0x3D
#define F5         0x3E
#define F6         0x3F
#define F7         0x40
#define F8         0x41
#define F9         0x42
#define F10        0x43
#define F11        0x44
#define F12        0x45

// Control Keycodes
#define PRINT      0x46
#define SCROLL_LOCK 0x47
#define PAUSE      0x48
#define INSERT     0x49
#define HOME       0x4A
#define PAGE_UP    0x4B
#define DELETE     0x4C
#define END        0x4D
#define PAGE_DOWN  0x4E
#define RIGHT_ARROW 0x4F
#define LEFT_ARROW  0x50
#define DOWN_ARROW  0x51
#define UP_ARROW    0x52
#define NUM_LOCK    0x53

// Numeric Keypad Keycodes
#define KP_SLASH   0x54
#define KP_ASTERISK 0x55
#define KP_MINUS   0x56
#define KP_PLUS    0x57
#define KP_ENTER   0x58
#define KP_1       0x59
#define KP_2       0x5A
#define KP_3       0x5B
#define KP_4       0x5C
#define KP_5       0x5D
#define KP_6       0x5E
#define KP_7       0x5F
#define KP_8       0x60
#define KP_9       0x61
#define KP_0       0x62
#define KP_DOT     0x63

#endif /* INC_USB_H_ */
