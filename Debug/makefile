################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/viewport/subdir.mk
-include src/transformacao/tipos/translacao/subdir.mk
-include src/transformacao/tipos/rotacao/subdir.mk
-include src/transformacao/tipos/escalonamento/subdir.mk
-include src/transformacao/tipos/subdir.mk
-include src/transformacao/subdir.mk
-include src/modelo.interno/window/subdir.mk
-include src/modelo.interno/subdir.mk
-include src/main/subdir.mk
-include src/dto/transformacao/subdir.mk
-include src/dto/matriz/subdir.mk
-include src/dto/geometrico/subdir.mk
-include src/clipping/subdir.mk
-include src/application/subdir.mk
-include src/adicionar/objetos/reta/subdir.mk
-include src/adicionar/objetos/ponto/subdir.mk
-include src/adicionar/objetos/poligono/subdir.mk
-include src/adicionar/objetos/curva/subdir.mk
-include src/adicionar/objetos/subdir.mk
-include src/adicionar/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: cg

# Tool invocations
cg: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/usr/lib/x86_64-linux-gnu -o "cg" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) cg
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
