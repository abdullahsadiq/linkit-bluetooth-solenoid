#include <LBT.h>    //Include the LinkIt ONE Bluetooth Library
#include <LBTServer.h>

int solenoidPin = 9;  //Pin the solenoid is connected to
String command;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
LBTServer.begin((uint8_t*)"My_BTServer");
pinMode(solenoidPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if(LBTServer.connected())
{
  Serial.println("Connected");  //If bluetooth is connected print "Connected" in serial port
  }
else
{
  Serial.println("Retrying");   //Else retry
  LBTServer.accept(5);
  }

command = LBTServer.readStringUntil('t');
if (command == "On"){
  digitalWrite(solenoidPin,HIGH);   //If command is "On", set pin 9 as HIGH
  Serial.println("Pin 9 is high");
  }
else if (command == "Off"){
  digitalWrite(solenoidPin,LOW);   //If command is "Off", set pin 9 as LOW
  Serial.println("Pin 9 is low");
  }
  
}

