################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Date.cpp \
../src/Gregorian.cpp \
../src/Julian.cpp \
../src/Kattistime.cpp \
../src/main.cpp 

OBJS += \
./src/Date.o \
./src/Gregorian.o \
./src/Julian.o \
./src/Kattistime.o \
./src/main.o 

CPP_DEPS += \
./src/Date.d \
./src/Gregorian.d \
./src/Julian.d \
./src/Kattistime.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


