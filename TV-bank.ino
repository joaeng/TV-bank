#include <dht.h>

dht DHT;

#define DHT21_PIN 3
int fan = 2;


void setup(){
  Serial.begin(9600);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, HIGH);
}

void loop()
{
  int chk = DHT.read21(DHT21_PIN);
  int temp=DHT.temperature;
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  
if (temp >= 25)
{
  Serial.println("Temperatur hög - Fläkt på  ");
  digitalWrite(fan, LOW);
  delay(900000);
}
else if(temp <= 21)
{
  Serial.println("Temperatur ok - Fläktar Av");
  digitalWrite(fan, HIGH);
  delay(120000);
  }
  else
{
  Serial.println("Temperatur ok  ");
//  digitalWrite(fan, HIGH);
delay(120000);
}
delay(3000);
}

