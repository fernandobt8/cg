################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/first.view/Widget.cpp 

OBJS += \
./src/first.view/Widget.o 

CPP_DEPS += \
./src/first.view/Widget.d 


# Each subdirectory must supply rules for building sources it contributes
src/first.view/%.o: ../src/first.view/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


