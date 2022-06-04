################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SimpleGraph.cpp \
../src/SimpleNode.cpp \
../src/attributeGraph1.cpp \
../src/attributedNode1.cpp \
../src/q2.cpp 

OBJS += \
./src/SimpleGraph.o \
./src/SimpleNode.o \
./src/attributeGraph1.o \
./src/attributedNode1.o \
./src/q2.o 

CPP_DEPS += \
./src/SimpleGraph.d \
./src/SimpleNode.d \
./src/attributeGraph1.d \
./src/attributedNode1.d \
./src/q2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


