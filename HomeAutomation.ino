#include <SoftwareSerial.h>

SoftwareSerial BT(10,11);   // RX, TX

char command;

const int Relay1 = 7;
const int Relay2 = 8;

void setup()
{
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);

  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);

  BT.begin(9600);
  Serial.begin(9600);

  Serial.println("Bluetooth Home Automation");
}

void loop()
{
  if(BT.available())
  {
    command = BT.read();

    Serial.println(command);

    switch(command)
    {
      case 'A':
        digitalWrite(Relay1, LOW);
        break;

      case 'a':
        digitalWrite(Relay1, HIGH);
        break;

      case 'B':
        digitalWrite(Relay2, LOW);
        break;

      case 'b':
        digitalWrite(Relay2, HIGH);
        break;

      case 'C':
        digitalWrite(Relay1, LOW);
        digitalWrite(Relay2, LOW);
        break;

      case 'c':
        digitalWrite(Relay1, HIGH);
        digitalWrite(Relay2, HIGH);
        break;
    }
  }
}
