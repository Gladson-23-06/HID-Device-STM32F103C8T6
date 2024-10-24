#include "main.h"
#include "USB.h"

// Function Prototypes
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void Error_Handler(void);

int main(void)
{
    // Initialize HAL Library
    HAL_Init();

    // Configure the system clock
    SystemClock_Config();

    // Initialize all configured peripherals
    MX_GPIO_Init();
    MX_USB_DEVICE_Init();

    // Main Loop
    while (1)
    {
        // Delay for 500 ms
        HAL_Delay(500);

        // Open Run dialog (Windows + R)
        Short_Cut(LGUI, R);

        // Type 'CMD' and press Enter
        SendString("CMD");
        Press_Key(ENTER);

        // Wait for command prompt to open
        HAL_Delay(1000);

        // Send PowerShell command to show a message box
        SendString(
            " powershell -Command \"Add-Type -AssemblyName PresentationFramework; "
            "[System.Windows.MessageBox]::Show('You Are Hacked')\""
        );
        Press_Key(ENTER);

        // Wait for message box to appear
        HAL_Delay(10000);

        // Close the message box by pressing Enter
        Press_Key(ENTER);

        // Delay before closing Run dialog (ALT + F4)
        HAL_Delay(50);
        Short_Cut(LALT, F4);

        // Short delay before the next iteration
        HAL_Delay(50);
    }
}
