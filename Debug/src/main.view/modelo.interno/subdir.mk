################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.view/modelo.interno/ModeloInterno.cpp 

OBJS += \
./src/main.view/modelo.interno/ModeloInterno.o 

CPP_DEPS += \
./src/main.view/modelo.interno/ModeloInterno.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.view/modelo.interno/%.o: ../src/main.view/modelo.interno/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


