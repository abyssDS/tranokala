#include <SoftwareSerial.h>
#include <GSM.h>
#include <Sim800l.h>
#include <string.h>

#define PINNUMBER ""
#define SoftwareSerial (8,7);
Sim800l Sim800l;


 int led = 9;
 int btn = 6;
 
 const int pingPin = 7;

  //variable to hold the IMEI number of the modem :
  String IMEI =" ";

 void ping_pin (); //connection pin sensor
 void sent_sms();//function d'envoi SMS
 void test_modem(); //function de test
 void serial_event();//function data receiving

 void setup() {
  Serial.begin(9600);
  Sim800l.begin();
  Serial.print("Start of System");
  SerialSim800.begin(9600);
  delay(1000);
  Serial.println("Setup Complete !");
 
}

void loop() {
  // put your main code here, to run repeatedly:

}
/*
void ping_pin(){
  long duration, inches, cm;
  //the ping is triggered by a high pulse of 2 or more microseconds
  //Give a short LOW pulse before hand to ensure a clean HIGH pulse:

  pinMode (ping_pin, OUTPUT);
  digitalWrite (ping_pin, LOW);
  delayMicroseconds (2);
  digitalWrite (ping_pin, HIGH);
  delayMicroseconds (5);
  digitalWrite (ping_pin, LOW);

  //The same pin is used to read the signal from the ping : a HIGH
  //pulse whose duration is the time (in microsenconds)from the sending
  //of the ping to the reception of its echo off of an object

  pinMode (ping_pin, INPUT);
  duration = pulseIn (ping_pin, HIGH);

  //convert a time into distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in ");
  Serial.print(cm);
  Serial.print("cm ");
  Serial.println();

  delay (100);
}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

long microseconsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
*/
void sent_sms(){
  Serial.println("Sending SMS...");
  SerialSim800.write("AT+CMGF=1\r\n");//format text for the sms
  delay(1000);
  /*Sim800l.write("AT+CMGS=\"261326773400\"\r\n"); //new sms command and phone number
  delay(1000);
  Sim800l.write("Test of GSM module and sensor"); //SMS content
  delay(1000);
  Sim800l.write((char)26); //sending Ctrl+Z/Esc to denote SMS message is complete
  delay(1000);
  Serial.println("... SMS Sent.")
  */
}

void test_modem(){
  //Starting Modem test
  Serial.println("Start.Of.Modem.Test ");//Message test for the modem_test
  //Send status message depending on the outcome, and end Setup() :
  if (modem.begin())
    Serial.println("modem.begin()successed");
  else
    Serial.println("ERROR, no modem answer");
  //get modem IMEI
  Serial.println("checking IMEI...");
  IMEI = modem.getIMEI();
  //if there is a valid response from getIMEI(), print it to the serial
  //monitor and reset the modem with modem .begin():
    if (IMEI!=NULL)
    {
      //show IMEI in serial monitor
      Serial.println("Modem's IMEI :" +IMEI);
      //reset modem to check booting:
      Serial.print("Reseting modem...");
      modem.begin();
      //once reset, check the IMEI again, if it is a valid return again,
      //the modem is functionning as expected
    if (modem.getIMEI()!=NULL)
    {
		Serial.println("Modem is functionning properly");
    }
    //if, after resetting the modem, there is not a valid return from getIMEI()
    //report an error:
    else 
    {
		Serial.println("Error : getIMEI() failed after modem.begin()");
    }
