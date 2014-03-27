################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.view/window/WindowView.cpp \
../src/main.view/window/moc_windowview.cpp 

OBJS += \
./src/main.view/window/WindowView.o \
./src/main.view/window/moc_windowview.o 

CPP_DEPS += \
./src/main.view/window/WindowView.d \
./src/main.view/window/moc_windowview.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.view/window/%.o: ../src/main.view/window/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


