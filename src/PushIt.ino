#include "HttpClient.h"

 int LED = D7;
 bool on = false;
 unsigned int nextTime = 0;

 HttpClient http;

 void setup() {
   pinMode(LED, OUTPUT);

 }

 void loop() {
   if (nextTime > millis()) {
       return;
   }
   else
   {
       if (on)
       {
           digitalWrite(LED, LOW);
           on = false;
       }
       else
       {
           digitalWrite(LED, HIGH);
           on = true;
       }
   }
   nextTime = millis() + 3000;

 }
