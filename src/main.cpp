#include <Arduino.h>

const uint8_t A []= {2,3,4,5};
const uint8_t B []= {6,7,8};


void setPinsToMode(const uint8_t* array, size_t size,const uint8_t mode)
{
  for(uint8_t i {0}; i<size; i++)
  {
    pinMode(array[i], mode);
  }
}

void unsignedByteToBinaryPins(const uint8_t dec, const uint8_t *pins, size_t size)
{
  for (uint8_t bitNumber {0}; bitNumber<size; bitNumber++)
  {
    digitalWrite(pins[bitNumber], bitRead(dec, bitNumber));
  }
}
void signedByteToBinaryPins(const int8_t dec, const uint8_t *pins, size_t size)
{
  for (uint8_t bitNumber {0}; bitNumber<size; bitNumber++)
  {
    digitalWrite(pins[bitNumber], bitRead(dec, bitNumber));
  }
}


void setup() 
{
  Serial.begin(115200);
  setPinsToMode(A, sizeof(A),OUTPUT);
  setPinsToMode(B,sizeof(B), OUTPUT);
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

