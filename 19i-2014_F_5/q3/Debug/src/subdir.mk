################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SimpleGraph.cpp \
../src/SimpleNode.cpp \
../src/attributeGraph2.cpp \
../src/attributedNode2.cpp \
../src/q3.cpp 

OBJS += \
./src/SimpleGraph.o \
./src/SimpleNode.o \
./src/attributeGraph2.o \
./src/attributedNode2.o \
./src/q3.o 

CPP_DEPS += \
./src/SimpleGraph.d \
./src/SimpleNode.d \
./src/attributeGraph2.d \
./src/attributedNode2.d \
./src/q3.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


