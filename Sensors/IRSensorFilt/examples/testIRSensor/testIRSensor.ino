#include <IRFilter.h>

const byte sensorPin = A0;
const byte mediumFilterWindowSize = 5;
IRFilter medFilt(mediumFilterWindowSize,1500);

void setup() {
  Serial.begin(9600);
}

void loop() {
   int dist = 0;
  //Read the IR Sensor value
  int senseRead = analogRead(sensorPin);
  Serial.print(senseRead);
  Serial.print(", ");
  
  //Put the value into the filter
  medFilt.in(senseRead);

  //Get the filtered value
  dist = medFilt.out();
  Serial.print(dist);

  //Some delay before the next meeting
  delay(50);

}
