
CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP --specs=nano.specs -mfloat-abi=hard -mthumb
LDFLAGS= -nostdlib -T $(ROOT_FOLDER)\common\linker\linker_script.ld

ROOT_FOLDER=..\..
OBJECT_OUTPUT_PATH = $(ROOT_FOLDER)\common\obj

CC_FILE_TO_BUILD = \
	$(PATH_TO_MAIN_FILE) \

CC_INCLUDE_PATH = \
	-I$(PATH_TO_INCLUDE_DIR) \
	-I$(ROOT_FOLDER)\common\device \

ASM_FILE_TO_BUILD = \
	$(ROOT_FOLDER)\common\startup\startup.s

OBJECT_FILE_NAME = \
	$(CC_FILE_TO_BUILD:.c=.o) \
	$(ASM_FILE_TO_BUILD:.s=.o)

CC_SRC_PATH += \

define include_makefiles
include $(ROOT_FOLDER)\module\$(1)\make\stm32f411_$(2)_defs_rules.mak
endef

$(foreach module, $(MODULE), $(eval $(call include_makefiles,$(module),$(module))))

OBJECT_FILE_BUILD = $(notdir $(OBJECT_FILE_NAME))

OBJECT_PATH_FILE_BUILD = $(addprefix $(OBJECT_OUTPUT_PATH)\,$(notdir $(OBJECT_FILE_NAME)))

EXE_FILE_SUFFIX = .elf

EXE = $(addsuffix $(EXE_FILE_SUFFIX),$(basename $(notdir $(PATH_TO_MAIN_FILE))))

vpath %.c $(CC_SRC_PATH)
vpath %.s $(ROOT_FOLDER)\common\startup

%.o: %.c
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(CC_INCLUDE_PATH) $< -o $(OBJECT_OUTPUT_PATH)\$@
	@echo Done 
	@echo -----------------------------------------------------------

%.o: %.s
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(CC_INCLUDE_PATH) $< -o $(OBJECT_OUTPUT_PATH)\$@
	@echo Done 
	@echo -----------------------------------------------------------

$(EXE):$(OBJECT_FILE_BUILD)
	@echo Linking $@ ...
	$(CC) $(LDFLAGS) -o $(OBJECT_OUTPUT_PATH)\$@ $(OBJECT_PATH_FILE_BUILD)
	@echo Done
	@echo -----------------------------------------------------------

test:
	@echo $(CC_SRC_PATH)

clean:
	rm -rf ../obj/*.*
