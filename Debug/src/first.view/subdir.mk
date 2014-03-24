################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/first.view/AdicionarWindow.cpp \
../src/first.view/Widget.cpp \
../src/first.view/moc_adicionarwindow.cpp \
../src/first.view/moc_widget.cpp 

OBJS += \
./src/first.view/AdicionarWindow.o \
./src/first.view/Widget.o \
./src/first.view/moc_adicionarwindow.o \
./src/first.view/moc_widget.o 

CPP_DEPS += \
./src/first.view/AdicionarWindow.d \
./src/first.view/Widget.d \
./src/first.view/moc_adicionarwindow.d \
./src/first.view/moc_widget.d 


# Each subdirectory must supply rules for building sources it contributes
src/first.view/%.o: ../src/first.view/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -I/usr/include/qt5 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


