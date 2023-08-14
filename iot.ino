//For DHT22 Sensor
#include <DHT.h>
#define DHTPIN D3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

void loop() {

  //take sensor readings
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  
  // Printing the results on the serial monitor
	Serial.print("Temperature = ");
	Serial.print(t);
	Serial.print(" ");
	Serial.print((char)176);//shows degrees character
	Serial.print("C | ");
	Serial.print((t * 9.0) / 5.0 + 32.0);//print the temperature in Fahrenheit
	Serial.print(" ");
	Serial.print((char)176);//shows degrees character
	Serial.println("F ");
	Serial.print("Humidity = ");
	Serial.print(h);
	Serial.println(" % ");

  float T = (t * 9.0) / 5.0 + 32.0;
  float RH = h; 

  //calculate heat index  
  float HI = -42.379 + 2.04901523*T + 10.14333127*RH - .22475541*T*RH - .00683783*T*T - .05481717*RH*RH + .00122874*T*T*RH + .00085282*T*RH*RH - .00000199*T*T*RH*RH;

  //Take Heat index calculations to serial monitor
  Serial.print("Heat Index = ");
  Serial.print(HI);
  Serial.println("");
  Serial.println("");

  //set overall delay
  delay(5000);
}
