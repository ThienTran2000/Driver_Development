CC_FILE_TO_BUILD += \
	$(ROOT_FOLDER)\module\pwm\src\Pwm.c \
	$(ROOT_FOLDER)\module\pwm\src\PwmLLDriver.c

CC_INCLUDE_PATH += \
	-I$(ROOT_FOLDER)\module\pwm\include

CC_SRC_PATH += \
	$(ROOT_FOLDER)\module\pwm\src