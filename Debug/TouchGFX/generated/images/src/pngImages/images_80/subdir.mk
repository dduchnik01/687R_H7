################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_folder.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.cpp \
../TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.cpp 

OBJS += \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_folder.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.o \
./TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_folder.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.d \
./TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/pngImages/images_80/%.o TouchGFX/generated/images/src/pngImages/images_80/%.su TouchGFX/generated/images/src/pngImages/images_80/%.cyclo: ../TouchGFX/generated/images/src/pngImages/images_80/%.cpp TouchGFX/generated/images/src/pngImages/images_80/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-pngImages-2f-images_80

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-pngImages-2f-images_80:
	-$(RM) ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionChangeMod.su ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionLogout.su ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectOperator.su ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSelectProfil_80.su ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionSetup.su ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShowHelp.su ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.d ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.o ./TouchGFX/generated/images/src/pngImages/images_80/image_ActionShutdown.su ./TouchGFX/generated/images/src/pngImages/images_80/image_folder.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_folder.d ./TouchGFX/generated/images/src/pngImages/images_80/image_folder.o ./TouchGFX/generated/images/src/pngImages/images_80/image_folder.su ./TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.d ./TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.o ./TouchGFX/generated/images/src/pngImages/images_80/image_menuAktualizacja.su ./TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.d ./TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.o ./TouchGFX/generated/images/src/pngImages/images_80/image_menuBazyDanych.su ./TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.d ./TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.o ./TouchGFX/generated/images/src/pngImages/images_80/image_menuInne.su ./TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.d ./TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.o ./TouchGFX/generated/images/src/pngImages/images_80/image_menuRaporty.su ./TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.cyclo ./TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.d ./TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.o ./TouchGFX/generated/images/src/pngImages/images_80/image_uniwStatystyka.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-pngImages-2f-images_80

