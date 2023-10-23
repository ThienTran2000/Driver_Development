CC_FILE_TO_BUILD += \
	$(ROOT_FOLDER)\module\i2c\src\I2c.c \
	$(ROOT_FOLDER)\module\i2c\src\I2cLLDriver.c

CC_INCLUDE_PATH += \
	-I$(ROOT_FOLDER)\module\i2c\include

CC_SRC_PATH += \
	$(ROOT_FOLDER)\module\i2c\src