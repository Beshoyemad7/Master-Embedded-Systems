################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO/Src/MCAL_DIO.c 

OBJS += \
./DIO/Src/MCAL_DIO.o 

C_DEPS += \
./DIO/Src/MCAL_DIO.d 


# Each subdirectory must supply rules for building sources it contributes
DIO/Src/%.o: ../DIO/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Beshoy Emad\OneDrive\Desktop\IMT\IMT SDK\AVR_Workspace\Calculator\DIO\Src" -I"C:\Users\Beshoy Emad\OneDrive\Desktop\IMT\IMT SDK\AVR_Workspace\Calculator\DIO\Inc" -I"C:\Users\Beshoy Emad\OneDrive\Desktop\IMT\IMT SDK\AVR_Workspace\Calculator\KEYPAD\Src" -I"C:\Users\Beshoy Emad\OneDrive\Desktop\IMT\IMT SDK\AVR_Workspace\Calculator\KEYPAD\Inc" -I"C:\Users\Beshoy Emad\OneDrive\Desktop\IMT\IMT SDK\AVR_Workspace\Calculator\LCD\Inc" -I"C:\Users\Beshoy Emad\OneDrive\Desktop\IMT\IMT SDK\AVR_Workspace\Calculator\LCD\Src" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=12000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


