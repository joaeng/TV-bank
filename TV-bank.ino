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
  
if (temp >= 23)
{
  Serial.println("Temperatur hög - Fläkt på  ");
  digitalWrite(fan, LOW);
  delay(600);
}
else if(temp <= 20)
{
  Serial.println("Temperatur ok - Av");
  digitalWrite(fan, HIGH);
  }
  else
{
  Serial.println("Temperatur ok  ");
//  digitalWrite(fan, HIGH);
  delay(600);
}
delay(3000);
}

