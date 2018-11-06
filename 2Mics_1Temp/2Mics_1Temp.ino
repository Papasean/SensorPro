
//SetUp TempSensor
#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

//SetUp Microphones
int  sensorPin1  =  A0;     // select the input  pin for the potentiometer on Mic 1
int  sensorPin2  =  A1;     // select the input  pin for the potentiometer on Mic 2
int  sensorPin3  =  A2;     // select the input  pin for the photoresistor
int  ledPin  =  13;   // select the pin for  the LED
int  sensorValue1 =  0;  // variable to store the value coming from the sensor 1
int  sensorValue2 =  0;  // variable to store the value coming from the sensor 2
int  sensorValue3 =  0;  // variable to store the value coming from the sensor 2

void setup()
{
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}


void loop()
{

 // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Temp = ");
  Serial.print((int)temperature); Serial.print(" deg. C, ");
  Serial.print("Humidity = "); 
  Serial.print((int)humidity); Serial.println("%");


sensorValue1 =  analogRead(sensorPin1);
sensorValue2 =  analogRead(sensorPin2);
sensorValue3 =  analogRead(sensorPin3);
//digitalWrite(ledPin,  HIGH); 
//delay(1000); 
//digitalWrite(ledPin,  LOW);
//delay(1000);
Serial.print("Mic 1 = "); Serial.println(sensorValue1,  DEC);
Serial.print("Mic 2 = "); Serial.println(sensorValue2,  DEC);
Serial.print("Light Value = "); Serial.println(sensorValue3,  DEC);
delay(2000);

}
