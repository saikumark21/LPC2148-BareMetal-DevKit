CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy

CFLAGS = -mcpu=arm7tdmi -mthumb-interwork -O0 -g -Wall
LDFLAGS = -T linker/lpc2148.ld -nostartfiles
INCLUDES = -Iheader

SRC_DIR = src
OBJ_DIR = build
STARTUP = startup/startup.s

# Automatically get all .c files from src/
C_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_FILES))

all: $(OBJ_DIR)/lpc2148.hex

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/startup.o: $(STARTUP)
	$(AS) -mcpu=arm7tdmi $< -o $@

$(OBJ_DIR)/lpc2148.elf: $(OBJ_FILES) $(OBJ_DIR)/startup.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/lpc2148.hex: $(OBJ_DIR)/lpc2148.elf
	$(OBJCOPY) -O ihex $< $@

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.elf $(OBJ_DIR)/*.hex
