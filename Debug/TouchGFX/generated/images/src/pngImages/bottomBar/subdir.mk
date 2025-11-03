################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.cpp \
../TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.cpp 

OBJS += \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.o \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.d \
./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/pngImages/bottomBar/%.o TouchGFX/generated/images/src/pngImages/bottomBar/%.su TouchGFX/generated/images/src/pngImages/bottomBar/%.cyclo: ../TouchGFX/generated/images/src/pngImages/bottomBar/%.cpp TouchGFX/generated/images/src/pngImages/bottomBar/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H743xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/generated/videos/include -I../TouchGFX/gui/include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-pngImages-2f-bottomBar

clean-TouchGFX-2f-generated-2f-images-2f-src-2f-pngImages-2f-bottomBar:
	-$(RM) ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIcon.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_enterIconPressed.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIcon.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_homeIconPressed.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIcon.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_tareIconPressed.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIcon.su ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.cyclo ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.d ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.o ./TouchGFX/generated/images/src/pngImages/bottomBar/image_zeroIconPressed.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src-2f-pngImages-2f-bottomBar

