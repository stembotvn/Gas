#include "Arduino.h" 
#include <Gas.h>
Gas gas; 
int MQ_PIN = A0;

void setup() {
Serial.begin(9600);

  pinMode(13,OUTPUT);   // set up LED
  digitalWrite(13,HIGH); // turn on LED for indicate starting calibration
  Serial.print("Calibrating...");   
 int R0= gas.MQCalibration(MQ_PIN);                         //Calibrating the sensor. Please make sure the sensor is in clean air         
  digitalWrite(13,LOW);              
   
   Serial.println("    done!");                                 //LCD display
  Serial.print("Ro= ");
  Serial.print(R0);
  Serial.println("kohm");
  delay(3000);
}

void loop(){
long ppm = gas.MQGetPPM(MQ_PIN,GAS_LPG);

   Serial.print("LPG: ");
   Serial.print(ppm);
   Serial.println(" ppm"); 
   delay(500);

}