
/**
  @page RC5_Receiver_Demo AN3174 RC5_Receiver_Demo Readme file
  
  @verbatim
  ******************** (C) COPYRIGHT 2010 STMicroelectronics *******************
  * @file RC5_Receiver_Demo/readme.txt 
  * @author  MCD Application Team
  * @version  V1.0.0
  * @date  03/16/2010
  * @brief  Description of the AN3174 Application note's RC5_Receiver_Demo. 
  ******************************************************************************
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  ******************************************************************************
   @endverbatim

@par Description

This application note shows how to implement a RC5 receiver by software using
STM32 microcontrollers. The demo consists of receiving RC5 messages and then sent
it to the hyperterminal. 
USART1 is used for this purpose to connect the board to the PC. Please configure the 
hyperterminal as the following:

 -  115200 baud,
 -  8-bit data,
 -  No parity,
 -  No Flow Control.


@par Directory contents 

  - RC5_Receiver_Demo/inc/stm32f10x_conf.h  Library Configuration file
  - RC5_Receiver_Demo/src/stm32f10x_it.c    Interrupt handlers
  - RC5_Receiver_Demo/inc/stm32f10x_it.h    Interrupt handlers header file
  - RC5_Receiver_Demo/src/main.c            Main program



@par Hardware and Software environment

  - This example runs on STM32F10x High-Density, Medium-Density, Connectivity line,
    Medium-Density Value line, Low-Density and Low-Density Value line Devices.
  
  - This example has been tested with STMicroelectronics STM32100B-EVAL 
    (STM32F10x Medium-Density Value line), STM3210B-EVAL (STM32F10x Medium-Density),
    STM3210E-EVAL (STM32F10x High-Density) evaluation boards. The STM3210C-EVAL board
    (STM32F10x Connectivity-Line) is not supported by the demo. However Connectivity-Line
    product supports the demo.
   
  - STM32100B-EVAL, STM3210B-EVAL and STM3210E-EVAL Set-up 
     - Connect the IR module output to GPIOB.01.
     - Connect the board (USART1) to the PC via RS232 cable.
      
@par How to use it 

In order to load the RC5_Receiver_Demo demo, you have do the following:
  
- RVMDK (v4.00)
    - Open the RC5_Receiver_Demo.uvopt project
    - In the build toolbar select the project config:
        - STM32100B-EVAL: to configure the project for STM32 Medium-Density Value-line devices
        - STM3210B-EVAL: to configure the project for STM32 Medium-density devices
        - STM3210E-EVAL: to configure the project for STM32 High-density devices
        - STM3210x-Connectivity: to configure the project for STM32 Connectivity-Line devices
    - Rebuild all files: Project->Rebuild all target files
    - Load project image: Debug->Start/Stop Debug Session
    - Run program: Debug->Run (F5)

 - EWARMv5 (v5.40) 
    - Open the RC5_Receiver_Demo.eww workspace.
    - In the workspace toolbar select the project config:
        - STM32100B-EVAL: to configure the project for STM32 Medium-Density Value-line devices
        - STM3210B-EVAL: to configure the project for STM32 Medium-density devices
        - STM3210E-EVAL: to configure the project for STM32 High-density devices
        - STM3210x-Connectivity: to configure the project for STM32 Connectivity-Line devices
    - Rebuild all files: Project->Rebuild all
    - Load project image: Project->Debug
    - Run program: Debug->Go(F5)

 - RIDE (RIDE7)
    - Open the RC5_Receiver_Demo.rprj project.
    - In the configuration toolbar(Project->properties) select the project config:
        - STM32100B-EVAL: to configure the project for STM32 Medium-Density Value-line devices
        - STM3210B-EVAL: to configure the project for STM32 Medium-density devices
        - STM3210E-EVAL: to configure the project for STM32 High-density devices
        - STM3210x-Connectivity: to configure the project for STM32 Connectivity-Line devices
    - Rebuild all files: Project->build project
    - Load project image: Debug->start(ctrl+D)
    - Run program: Debug->Run(ctrl+F9)  

 - HiTOP (v5.31)
    - Open the HiTOP toolchain.
    - Browse to open the RC5_Receiver_Demo.htp
    - A "Download application" window is displayed, click "cancel".
    - Rebuild all files: Project->Rebuild all
    - Load project image : Click "ok" in the "Download application" window.
    - Run the "RESET_GO_MAIN" script to set the PC at the "main"
    - Run program: Debug->Go(F5).

@note the JTAG connector should be removed and power off/on should be applied otherwise the system
remains halted

@note
 - Low-density Value line devices are STM32F100xx microcontrollers where the 
   Flash memory density ranges between 16 and 32 Kbytes.
 - Low-density devices are STM32F101xx, STM32F102xx and STM32F103xx 
   microcontrollers where the Flash memory density ranges between 16 and 32 Kbytes.
 - Medium-density Value line devices are STM32F100xx microcontrollers where
   the Flash memory density ranges between 64 and 128 Kbytes.  
 - Medium-density devices are STM32F101xx, STM32F102xx and STM32F103xx 
   microcontrollers where the Flash memory density ranges between 64 and 128 Kbytes.
 - High-density devices are STM32F101xx and STM32F103xx microcontrollers where
   the Flash memory density ranges between 256 and 512 Kbytes.
 - Connectivity line devices are STM32F105xx and STM32F107xx microcontrollers.

 * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
 */
