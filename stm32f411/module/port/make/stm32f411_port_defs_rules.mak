CC_FILE_TO_BUILD += \
	$(ROOT_FOLDER)\module\port\src\Port.c \
	$(ROOT_FOLDER)\module\port\src\PortLLDriver.c

CC_INCLUDE_PATH += \
	-I$(ROOT_FOLDER)\module\port\include

CC_SRC_PATH += \
	$(ROOT_FOLDER)\module\port\src