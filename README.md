# UART Driver | Basic Setup
## Overview
* Get up and running fast in your Bare-Metal C project by using this UART data transmission (Tx) driver configured for the STM32F4 Nucleo development board.
* This driver initializes the UART module for data transmission, configures the baud rate and provides the user with a basic “write” function for debugging purposes.
## Dependencies
* STM32F4 Datasheet, Reference Manual, and Nucleo64 Board User manual
* CMSIS header files

[Datasheet]: Search “STM32F4[your version] Datasheet” <br />
[Reference Manual]: Search “STM32F4[your version] Reference Manual” <br />
[Nucleo64 Board User Manual]: Search “Nucleo64 Board User Manual” <br />
** Always download from ST Microelectronics <br />

## Steps for Getting CMSIS Header Files
*	Go to St.com and navigate to the home page. Once there click on the search bar at the top of the page and search for “stm32f4”
*	Filter the results by clicking on the “Tools and Software” tab located at the top left corner of the search screen.
*	The software package download should be the fourth option down from the top. Check to make sure the Part Number is STM32CubeF4, Status is Active, Type is Embedded Software, Category is Mcu mpu embedded software, and the description is as follows: “STM32Cube MCU Package for STM32F4 series (HAL, Low-Layer APIs and CMSIS, USB, TCP/IP, File system, RTOS, Graphic - and examples running on ST boards)”
*	Download this software package, extract the Zip file, rename it to chip headers, and place it inside of your project folder

## Steps for Including CMSIS Header Files Inside Project
* Inside the Cube IDE, over on the left side of the screen on the file explorer, right click on the project name and click “properties”
*	Within in the property’s menu, navigate to C/C++ General, then click Paths and Symbols
*	In the Paths and Symbols menu, make sure the “Include” tab is selected
*	In the Include tab, click Add, File System, and paste the path to your chip headers folder for both the include folders that exist in this software package.
*	In the Symbols tab, you will need to add a symbol for your version of the STM32F4 you are using. (Ex: STM32F4446RE)

## Installation
Download the files, open the project folder using the STM32 Cube IDE (for this project I used version 1.6.1) which can be downloaded at st.com.
From the Src folder, open the “main.c” and “uart.c” files. You can start developing on top of this driver by adding more files to the Src folder and including them in the “main.c” file.



