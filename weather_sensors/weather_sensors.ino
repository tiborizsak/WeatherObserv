#include <DHT.h>
#include <DHT_U.h>
#include <ArduinoJson.h>

#define DHTPIN 12
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT); //Photoresistor 5V
  pinMode(11, OUTPUT);//DH11 5V
  dht.begin();
}

void loop() {
  int phresistorvalue = analogRead(A0);
  int moistvalue = analogRead(A1);
  int t = dht.readTemperature();
  int h = dht.readHumidity();
  digitalWrite(9, HIGH);
  digitalWrite(11, HIGH);

  delay(5000);

  StaticJsonDocument<200> phresist;
  phresist["sensor"] = "Photoresistor";
  phresist["value"] = phresistorvalue;

  serializeJsonPretty(phresist, Serial);

  delay(5000);
  
  StaticJsonDocument<200> moist;
  moist["sensor"] = "Moisturesensor";
  moist["value"] = moistvalue;

  serializeJsonPretty(moist, Serial);

  delay(5000);

  StaticJsonDocument<200> temphum;
  temphum["sensor"] = "TempHumsensor";
  temphum["temperature"] = t;
  temphum["humidity"] = h;

  serializeJsonPretty(temphum, Serial);

}
