@echo off
REM #######################################################################################################################
REM # DISCLAIMER
REM # This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
REM # other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
REM # applicable laws, including copyright laws.
REM # THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
REM # THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
REM # FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
REM # EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
REM # SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
REM # THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
REM # Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
REM # this software. By using this software, you agree to the additional terms and conditions found by accessing the
REM # following link:
REM # http://www.renesas.com/disclaimer
REM #
REM # Copyright (C) 2025 Renesas Electronics Corporation. All rights reserved.
REM #######################################################################################################################

REM Check whether Python 3.10 is installed
py -3.10 --version > nul
if errorlevel 1 (
    echo [ERROR] Python 3.10 not found. Install it or ensure it's in PATH.
    goto error
)

REM Check whether CONVERSION_TOOL_E2STUDIO_PLUGIN_PYTHON_VENV_LOC variable exists 
if not defined CONVERSION_TOOL_E2STUDIO_PLUGIN_PYTHON_VENV_LOC (
    echo [ERROR] Failed to find the environment variable: "CONVERSION_TOOL_E2STUDIO_PLUGIN_PYTHON_VENV_LOC"
    echo [ERROR] Set the Python virtual environment path as environment variable: "CONVERSION_TOOL_E2STUDIO_PLUGIN_PYTHON_VENV_LOC"
    echo [ERROR] If it is already set, restart e2studio to reload the environment variables.
    goto error
)

REM Check whether activate bat exists
set "ACTIVATOR_PATH=%CONVERSION_TOOL_E2STUDIO_PLUGIN_PYTHON_VENV_LOC%\.venv\Scripts\activate.bat"
if not exist "%ACTIVATOR_PATH%" (
    echo [ERROR] Failed to find the activate file: %ACTIVATOR_PATH%
    echo [ERROR] Confirm that the virtual environment folder:.venv exists under %CONVERSION_TOOL_E2STUDIO_PLUGIN_PYTHON_VENV_LOC%
    goto error
)

@REM REM Activate the virtual environment
call "%ACTIVATOR_PATH%"

REM Run the python command
python %*
if errorlevel 1 (
    echo [ERROR] Failed to execute the command
    goto error
)
goto end

:error
    exit /b 1

:end
    echo [INFO] Success to execute the command
