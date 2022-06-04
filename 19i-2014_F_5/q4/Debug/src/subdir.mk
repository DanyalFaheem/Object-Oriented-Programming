################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SimpleGraph.cpp \
../src/SimpleNode.cpp \
../src/attributeGraph1.cpp \
../src/attributeGraph2.cpp \
../src/attributeWeightedGraph.cpp \
../src/attributedNode1.cpp \
../src/attributedNode2.cpp \
../src/q4.cpp 

OBJS += \
./src/SimpleGraph.o \
./src/SimpleNode.o \
./src/attributeGraph1.o \
./src/attributeGraph2.o \
./src/attributeWeightedGraph.o \
./src/attributedNode1.o \
./src/attributedNode2.o \
./src/q4.o 

CPP_DEPS += \
./src/SimpleGraph.d \
./src/SimpleNode.d \
./src/attributeGraph1.d \
./src/attributeGraph2.d \
./src/attributeWeightedGraph.d \
./src/attributedNode1.d \
./src/attributedNode2.d \
./src/q4.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


