# STM32_CustomBootloader_SDCard

Custom Bootloader for STM32 to read a binary file from SD card and store it in main memory. 

The main memory is divided into two parts. Sector-0 stores the bootloader code and Sector-2 stores the user application. If user-button is not pressed then code jumps to user application. Otherwise, it continues the boot loading mode. 
![Alt Text](https://github.com/Sijan123/STM32_CustomBootloader_SDCard/blob/master/images/memorymap.JPG)

In Boot-Loading mode, Serial-Monitor can be used to configure the boot process. 
![Alt Text](https://github.com/Sijan123/STM32_CustomBootloader_SDCard/blob/master/images/hterm.JPG)

The binary image is stored in SD-Card.This data is read via SD-Card interface and written to main memory. 
![Alt Text](https://github.com/Sijan123/STM32_CustomBootloader_SDCard/blob/master/images/sd-card.JPG)


main.c :STM32_CustomBootloader_SDCard/Bootload_SD/Core/Src/

Drivers : STM32_CustomBootloader_SDCard/Bootload_SD/sp_drivers/
