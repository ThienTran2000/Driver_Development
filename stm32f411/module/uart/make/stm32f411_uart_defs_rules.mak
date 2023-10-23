CC_FILE_TO_BUILD += \
	$(ROOT_FOLDER)\module\uart\src\Uart.c \
	$(ROOT_FOLDER)\module\uart\src\UartLLDriver.c

CC_INCLUDE_PATH += \
	-I$(ROOT_FOLDER)\module\uart\include

CC_SRC_PATH += \
	$(ROOT_FOLDER)\module\uart\src