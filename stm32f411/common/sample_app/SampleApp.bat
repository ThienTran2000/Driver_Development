@echo off
setlocal EnableDelayedExpansion

IF "%~1" == "" (
    GOTO HELP
) ELSE (
    SET MODULE=%~1
)

IF "%~2" == "" (
    GOTO HELP
) ELSE (
    SET PATH_TO_MAIN_FILE=%~2
    SET IMAGE_FILE=
    SET CC_SRC_PATH_MAIN=
    for /F "delims=" %%i in ("!PATH_TO_MAIN_FILE!") do (
        SET IMAGE_FILE=%%~nxi
        SET CC_SRC_PATH_MAIN=%%~dpi
    )
    SET IMAGE_FILE=!IMAGE_FILE:.c=.elf!
    SET CC_SRC_PATH=!CC_SRC_PATH_MAIN:~0,-1!
)

IF "%~3" == "" (
    GOTO HELP
) ELSE (
    SET PATH_TO_INCLUDE_DIR=%~3
    call make -f ../make/Common.mak clean > NUL
    call make -f ../make/Common.mak test
    call make -f ../make/Common.mak !IMAGE_FILE!
    GOTO END
)

:HELP
echo.
echo ====================================================================================================
echo                                            HELP TO BUILD               
echo ====================================================================================================
echo.
echo Usage:
echo.
echo SampleApp.bat MODULE PATH_TO_MAIN_FILE PATH_TO_INCLUDE_DIR
echo.
echo MODULE(*)               -   Module short name: adc, dio, i2c, port, pwm, spi, uart.
echo.                            We can pass multi-module to this argument by separating modules by the
echo.                            commas. Example: "dio port".
echo.
echo.PATH_TO_MAIN_FILE       -   This is the absolute or relative path to source file that contains the
echo.                            main function.
echo.
echo.PATH_TO_INCLUDE_DIR     -   This is the absolute or relative path to the folder contain the header
echo.                            files.
echo.

GOTO END

:END

ENDLOCAL

@echo on