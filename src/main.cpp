#include <Arduino.h>

const uint8_t A []= {2,3,4,5};
const uint8_t B []= {6,7,8};

const uint8_t arrPointer[]={*A, *B};

void unsignedByteToBinaryPins(uint8_t dec, uint8_t *pins, size_t size)
{
  for (uint8_t bitNumber = 0; bitNumber<size; bitNumber++)
  {
    digitalWrite(pins[bitNumber], bitRead(dec, bitNumber));
  }
}
void signedByteToBinaryPins(int8_t dec, uint8_t *pins, size_t size)
{
  for (uint8_t bitNumber = 0; bitNumber<size; bitNumber++)
  {
    digitalWrite(pins[bitNumber], bitRead(dec, bitNumber));
  }
}

void setup() 
{
  Serial.begin(115200);
  for(uint8_t pin: A)
  {
    pinMode(pin, OUTPUT);
  }
  for(uint8_t pin: B)
  {
    pinMode(pin, OUTPUT);
  }
}

void loop() 
{
  signedByteToBinaryPins(0b1111, A, sizeof(A));//Example -1 decimal
  
  //Counting 0-7
  for (uint8_t i= 0; i<8; i++)
  {
    unsignedByteToBinaryPins(i, B, sizeof(B));
    delay(1000);
  }   
}

