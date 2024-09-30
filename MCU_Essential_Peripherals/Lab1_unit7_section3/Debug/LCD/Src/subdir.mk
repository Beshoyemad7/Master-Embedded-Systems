################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LCD/Src/HAL_LCD.c 

OBJS += \
./LCD/Src/HAL_LCD.o 

C_DEPS += \
./LCD/Src/HAL_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
LCD/Src/HAL_LCD.o: ../LCD/Src/HAL_LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/GPIO/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/GPIO/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/LCD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/LCD/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/KEYPAD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/KEYPAD/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"LCD/Src/HAL_LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

