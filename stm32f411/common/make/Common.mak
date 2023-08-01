
CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F411VETx -DSTM32 -DSTM32F4 -c -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP --specs=nano.specs -mfloat-abi=hard -mthumb
LDFLAGS= -nostdlib -T $(ROOT_FOLDER)\common\linker\linker_script.ld

ROOT_FOLDER=U:\stm32f411
DEBUG_PATH = $(ROOT_FOLDER)\common\obj

CC_FILE_TO_BUILD = \
	$(ROOT_FOLDER)\common\startup\startup.s \
	$(ROOT_FOLDER)\module\dio\src\Dio.c \
	$(ROOT_FOLDER)\module\dio\src\DioLLDriver.c \
	$(ROOT_FOLDER)\module\dio\sample_app\src\App_DIO_Sample.c

CC_INCLUDE_PATH = \
	-I$(ROOT_FOLDER)\common\device \
	-I$(ROOT_FOLDER)\module\dio\include \
	-I$(ROOT_FOLDER)\module\dio\sample_app\include

App_DIO_Sample.elf:$(DEBUG_PATH)\startup.o $(DEBUG_PATH)\Dio.o $(DEBUG_PATH)\DioLLDriver.o $(DEBUG_PATH)\App_DIO_Sample.o
	@echo Linking...
	$(CC) $(LDFLAGS) -o $(DEBUG_PATH)\$@ $^
	@echo Done
	@echo -----------------------------------------------------

$(DEBUG_PATH)\startup.o:$(ROOT_FOLDER)\common\startup\startup.s
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(CC_INCLUDE_PATH) $< -o $@
	@echo Done 
	@echo -----------------------------------------------------

$(DEBUG_PATH)\Dio.o:$(ROOT_FOLDER)\module\dio\src\Dio.c
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(CC_INCLUDE_PATH) $< -o $@
	@echo Done
	@echo -----------------------------------------------------

$(DEBUG_PATH)\DioLLDriver.o:$(ROOT_FOLDER)\module\dio\src\DioLLDriver.c
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(CC_INCLUDE_PATH) $< -o $@
	@echo Done
	@echo -----------------------------------------------------

$(DEBUG_PATH)\App_DIO_Sample.o:$(ROOT_FOLDER)\module\dio\sample_app\src\App_DIO_Sample.c
	@echo Compiling $@ ...
	$(CC) $(CFLAGS) $(CC_INCLUDE_PATH) $< -o $@
	@echo Done
	@echo -----------------------------------------------------

clean:
	rm -rf ../obj/*.*