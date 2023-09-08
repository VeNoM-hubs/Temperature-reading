#define BLYNK_TEMPLATE_ID "TMPL31ezSPiUB"
#define BLYNK_TEMPLATE_NAME "DHT IoT sensor"
#define BLYNK_AUTH_TOKEN "gJtw5djx9cNp3RJeOXo4jov5m0eghWS9"
#include<DHT.h> 
#include<BlynkSimpleEsp8266.h>
#define DHTPIN 4 // Data pin is connected to D2 on GPIO pin 4
#define DHTTYPE DHT11 // Name the sensor as an object


DHT dht(DHTPIN, DHTTYPE);
char auth[]="gJtw5djx9cNp3RJeOXo4jov5m0eghWS9";
char ssid[]="OnePlus Nord";
char pass[]="15042006";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT test Successful!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Succesfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f)) //isnan= is not a number
  {
    Serial.println("Something is not working as intented");
    return; 
  }
  Serial.println("------------------------------------------------------------");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\n");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" degrees celsius. \n");
  Serial.println("------------------------------------------------------------");
  Blynk.virtualWrite(V0, t); 
  Blynk.virtualWrite(V1, h);
  delay(2000);

}
