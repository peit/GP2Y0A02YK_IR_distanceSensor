#include <Console.h>

int distance;

void setup()
{
  Bridge.begin();
  Console.begin();

while (!Console);

  //Serial.begin(115200);
  Console.println("sharp Range Test");
}

void loop() {
  distance = get_Sharp_GP2Y0A02YK_Distance(0);
  Console.println("Range: ");
  Console.println(distance);
  Console.println("cm ");
  delay(5000);

}

float get_Sharp_GP2Y0A02YK_Distance(int PinID)
{
  // Read analog to digital converter value
  float ADCValue = (float)analogRead(PinID);

  // Convert in millimeters and return distance
  return  2583.711122992086
          - 20.197897855471 * ADCValue
          + 0.071746539329 * ADCValue * ADCValue
          - 0.000115854182 * ADCValue * ADCValue * ADCValue
          + 0.000000068590 * ADCValue * ADCValue * ADCValue * ADCValue;
}
