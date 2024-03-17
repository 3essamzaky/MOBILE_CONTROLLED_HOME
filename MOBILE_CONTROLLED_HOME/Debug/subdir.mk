################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_program.c \
../SPI_program.c \
../TIMER_program.c \
../UART_program.c \
../app.c 

OBJS += \
./CLCD_program.o \
./DIO_program.o \
./SPI_program.o \
./TIMER_program.o \
./UART_program.o \
./app.o 

C_DEPS += \
./CLCD_program.d \
./DIO_program.d \
./SPI_program.d \
./TIMER_program.d \
./UART_program.d \
./app.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


