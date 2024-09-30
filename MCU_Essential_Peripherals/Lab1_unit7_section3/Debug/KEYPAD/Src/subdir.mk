################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../KEYPAD/Src/HAL_KEYPAD.c 

OBJS += \
./KEYPAD/Src/HAL_KEYPAD.o 

C_DEPS += \
./KEYPAD/Src/HAL_KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
KEYPAD/Src/HAL_KEYPAD.o: ../KEYPAD/Src/HAL_KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/GPIO/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/GPIO/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/LCD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/LCD/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/KEYPAD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/KEYPAD/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"KEYPAD/Src/HAL_KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

