#include <Arduino.h>

int count = 0;
char c;
String id;

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.println("EScanear Etiqueta RFID");
}

void loop()
{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);

  while (!Serial.available())
  {
  }
  id = Serial.readString();
  id += c;

  Serial.print(id);
  // AB123456789B;

  if (id == "ISPC")
  {
    Serial.println(" Etiqueta RFID Valida");
    digitalWrite(13, HIGH);
    delay(1500);
  }
  else
  {

    Serial.println(" Etiqueta RFID Invalida");
    digitalWrite(12, HIGH);
    delay(1500);
  }

  count = 0;
  id = "";
  delay(500);
}