################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dto/Coordenada.cpp \
../src/dto/ObjetoGeometrico.cpp \
../src/dto/Ponto.cpp \
../src/dto/Reta.cpp 

OBJS += \
./src/dto/Coordenada.o \
./src/dto/ObjetoGeometrico.o \
./src/dto/Ponto.o \
./src/dto/Reta.o 

CPP_DEPS += \
./src/dto/Coordenada.d \
./src/dto/ObjetoGeometrico.d \
./src/dto/Ponto.d \
./src/dto/Reta.d 


# Each subdirectory must supply rules for building sources it contributes
src/dto/%.o: ../src/dto/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/qt4 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


