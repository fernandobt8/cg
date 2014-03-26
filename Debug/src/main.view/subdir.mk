################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.view/MainView.cpp \
../src/main.view/moc_mainview.cpp 

OBJS += \
./src/main.view/MainView.o \
./src/main.view/moc_mainview.o 

CPP_DEPS += \
./src/main.view/MainView.d \
./src/main.view/moc_mainview.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.view/%.o: ../src/main.view/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


