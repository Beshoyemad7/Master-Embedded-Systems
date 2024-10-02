################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EXTI/Src/MCAL_EXTI.c 

OBJS += \
./EXTI/Src/MCAL_EXTI.o 

C_DEPS += \
./EXTI/Src/MCAL_EXTI.d 


# Each subdirectory must supply rules for building sources it contributes
EXTI/Src/MCAL_EXTI.o: ../EXTI/Src/MCAL_EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_lesson4/EXTI/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_lesson4/EXTI/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_lesson4/GPIO/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_lesson4/GPIO/Src" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_lesson4/LCD/Inc" -I"C:/Users/Beshoy Emad/Downloads/Embedded Systems/Workspace/Lab1_unit7_lesson4/LCD/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"EXTI/Src/MCAL_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

