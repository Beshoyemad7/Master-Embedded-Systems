################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO/Src/MCAL_GPIO.c 

OBJS += \
./GPIO/Src/MCAL_GPIO.o 

C_DEPS += \
./GPIO/Src/MCAL_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO/Src/MCAL_GPIO.o: ../GPIO/Src/MCAL_GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/GPIO/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/GPIO/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/LCD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/LCD/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/KEYPAD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_section3/KEYPAD/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GPIO/Src/MCAL_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

