#include <Wire.h>
void setup()
{
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void loop()
{
  delay(1000);

}
void receiveEvent(int howMany)
{
  while(1 < Wire.available())
  {  
    
    char c = Wire.read();
    Serial.print("Data nhan duoc tu master ");
    Serial.println(c);
  }
 byte x = Wire.read();
 Serial.println(x);
}