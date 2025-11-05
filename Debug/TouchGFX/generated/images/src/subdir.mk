################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/SVGDatabase.cpp \
../TouchGFX/generated/images/src/image_ActionSetup.cpp \
../TouchGFX/generated/images/src/image_ActionShowHelp.cpp \
../TouchGFX/generated/images/src/image_ActionShutdown.cpp \
../TouchGFX/generated/images/src/image_Bottom-Bar-Enter.cpp \
../TouchGFX/generated/images/src/image_Bottom-Bar-Home.cpp \
../TouchGFX/generated/images/src/image_Bottom-Bar-Tara.cpp \
../TouchGFX/generated/images/src/image_Bottom-Bar-Zero.cpp \
../TouchGFX/generated/images/src/image_menuAktualizacja.cpp \
../TouchGFX/generated/images/src/image_menuInne.cpp \
../TouchGFX/generated/images/src/image_stabilityIcon.cpp \
../TouchGFX/generated/images/src/image_wifi3.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/SVGDatabase.o \
./TouchGFX/generated/images/src/image_ActionSetup.o \
./TouchGFX/generated/images/src/image_ActionShowHelp.o \
./TouchGFX/generated/images/src/image_ActionShutdown.o \
./TouchGFX/generated/images/src/image_Bottom-Bar-Enter.o \
./TouchGFX/generated/images/src/image_Bottom-Bar-Home.o \
./TouchGFX/generated/images/src/image_Bottom-Bar-Tara.o \
./TouchGFX/generated/images/src/image_Bottom-Bar-Zero.o \
./TouchGFX/generated/images/src/image_menuAktualizacja.o \
./TouchGFX/generated/images/src/image_menuInne.o \
./TouchGFX/generated/images/src/image_stabilityIcon.o \
./TouchGFX/generated/images/src/image_wifi3.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/SVGDatabase.d \
./TouchGFX/generated/images/src/image_ActionSetup.d \
./TouchGFX/generated/images/src/image_ActionShowHelp.d \
./TouchGFX/generated/images/src/image_ActionShutdown.d \
./TouchGFX/generated/images/src/image_Bottom-Bar-Enter.d \
./TouchGFX/generated/images/src/image_Bottom-Bar-Home.d \
./TouchGFX/generated/images/src/image_Bottom-Bar-Tara.d \
./TouchGFX/generated/images/src/image_Bottom-Bar-Zero.d \
./TouchGFX/generated/images/src/image_menuAktualizacja.d \
./TouchGFX/generated/images/src/image_menuInne.d \
./TouchGFX/generated/images/src/image_stabilityIcon.d \
./TouchGFX/generated/images/src/image_wifi3.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/%.o TouchGFX/generated/images/src/%.su TouchGFX/generated/images/src/%.cyclo: ../TouchGFX/generated/images/src/%.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src

clean-TouchGFX-2f-generated-2f-images-2f-src:
	-$(RM) ./TouchGFX/generated/images/src/BitmapDatabase.cyclo ./TouchGFX/generated/images/src/BitmapDatabase.d ./TouchGFX/generated/images/src/BitmapDatabase.o ./TouchGFX/generated/images/src/BitmapDatabase.su ./TouchGFX/generated/images/src/SVGDatabase.cyclo ./TouchGFX/generated/images/src/SVGDatabase.d ./TouchGFX/generated/images/src/SVGDatabase.o ./TouchGFX/generated/images/src/SVGDatabase.su ./TouchGFX/generated/images/src/image_ActionSetup.cyclo ./TouchGFX/generated/images/src/image_ActionSetup.d ./TouchGFX/generated/images/src/image_ActionSetup.o ./TouchGFX/generated/images/src/image_ActionSetup.su ./TouchGFX/generated/images/src/image_ActionShowHelp.cyclo ./TouchGFX/generated/images/src/image_ActionShowHelp.d ./TouchGFX/generated/images/src/image_ActionShowHelp.o ./TouchGFX/generated/images/src/image_ActionShowHelp.su ./TouchGFX/generated/images/src/image_ActionShutdown.cyclo ./TouchGFX/generated/images/src/image_ActionShutdown.d ./TouchGFX/generated/images/src/image_ActionShutdown.o ./TouchGFX/generated/images/src/image_ActionShutdown.su ./TouchGFX/generated/images/src/image_Bottom-Bar-Enter.cyclo ./TouchGFX/generated/images/src/image_Bottom-Bar-Enter.d ./TouchGFX/generated/images/src/image_Bottom-Bar-Enter.o ./TouchGFX/generated/images/src/image_Bottom-Bar-Enter.su ./TouchGFX/generated/images/src/image_Bottom-Bar-Home.cyclo ./TouchGFX/generated/images/src/image_Bottom-Bar-Home.d ./TouchGFX/generated/images/src/image_Bottom-Bar-Home.o ./TouchGFX/generated/images/src/image_Bottom-Bar-Home.su ./TouchGFX/generated/images/src/image_Bottom-Bar-Tara.cyclo ./TouchGFX/generated/images/src/image_Bottom-Bar-Tara.d ./TouchGFX/generated/images/src/image_Bottom-Bar-Tara.o ./TouchGFX/generated/images/src/image_Bottom-Bar-Tara.su ./TouchGFX/generated/images/src/image_Bottom-Bar-Zero.cyclo ./TouchGFX/generated/images/src/image_Bottom-Bar-Zero.d ./TouchGFX/generated/images/src/image_Bottom-Bar-Zero.o ./TouchGFX/generated/images/src/image_Bottom-Bar-Zero.su ./TouchGFX/generated/images/src/image_menuAktualizacja.cyclo ./TouchGFX/generated/images/src/image_menuAktualizacja.d ./TouchGFX/generated/images/src/image_menuAktualizacja.o ./TouchGFX/generated/images/src/image_menuAktualizacja.su ./TouchGFX/generated/images/src/image_menuInne.cyclo ./TouchGFX/generated/images/src/image_menuInne.d ./TouchGFX/generated/images/src/image_menuInne.o ./TouchGFX/generated/images/src/image_menuInne.su ./TouchGFX/generated/images/src/image_stabilityIcon.cyclo ./TouchGFX/generated/images/src/image_stabilityIcon.d ./TouchGFX/generated/images/src/image_stabilityIcon.o ./TouchGFX/generated/images/src/image_stabilityIcon.su ./TouchGFX/generated/images/src/image_wifi3.cyclo ./TouchGFX/generated/images/src/image_wifi3.d ./TouchGFX/generated/images/src/image_wifi3.o ./TouchGFX/generated/images/src/image_wifi3.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src

