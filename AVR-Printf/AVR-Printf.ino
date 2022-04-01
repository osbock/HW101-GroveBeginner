#include <stdio.h>

//Note, this probably only works on avr-gcc supported arduinos

// create a FILE structure to reference our UART output function

static FILE uartout = {0} ;

// create a output function
// This works because Serial.write, although of
// type virtual, already exists.
static int uart_putchar (char c, FILE *stream)
{
    Serial.write(c) ;
    return 0 ;
}
void setup() {
  Serial.begin(115200);
  // fill in the UART file descriptor with pointer to writer.
   fdev_setup_stream (&uartout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
   // The uart is the standard output device STDOUT.
   stdout = &uartout ;

   printf("hello,World!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
