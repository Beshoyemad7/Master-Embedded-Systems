################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Lab2_unit6_lesson4.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Lab2_unit6_lesson4.elf secondary-outputs

# Tool invocations
Lab2_unit6_lesson4.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Lab2_unit6_lesson4.map -mmcu=atmega32 -o "Lab2_unit6_lesson4.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Lab2_unit6_lesson4.lss: Lab2_unit6_lesson4.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Lab2_unit6_lesson4.elf  >"Lab2_unit6_lesson4.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Lab2_unit6_lesson4.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Lab2_unit6_lesson4.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Lab2_unit6_lesson4.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
