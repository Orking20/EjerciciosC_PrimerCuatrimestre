################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Automovil.c \
../src/Propietario.c \
../src/Relacion.c \
../src/main.c \
../src/utn.c 

OBJS += \
./src/Automovil.o \
./src/Propietario.o \
./src/Relacion.o \
./src/main.o \
./src/utn.o 

C_DEPS += \
./src/Automovil.d \
./src/Propietario.d \
./src/Relacion.d \
./src/main.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


