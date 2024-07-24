#@copyright : Beshoy_Emad
#@Date      : 22/7/2024

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
Project_name=cortex_m3

ALL: $(Project_name).bin

%.o:%.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS)  $< -o $@
	
$(Project_name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld  $(LIBS) $(OBJ) $(ASOBJ) -o $@  -Map=Map_file

$(Project_name).bin:$(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.bin *.elf
	
clean:
	rm *.bin *.elf