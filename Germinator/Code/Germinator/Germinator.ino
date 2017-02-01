/*
*
*
*
*/

#include <Firmata.h>
#include <Boards.h>
#include <LiquidCrystal.h>                               

//#include "LowPower.h"
#include "DHT.h"

// Définit le type de capteur utilisé
#define DHTTYPE DHT11

// Pin du capteur DHT11
#define DHTPIN A0 

// Water Sensor
#define WATERPIN  A1

// Moisture Sensor
#define MOISTUREPIN  A0

// Affectation des bropches sur l"ecran LCD
#define EN 8                                                            
#define RS 9
#define D7 2
#define D6 3
#define D5 4
#define D4 5

// Définition de lobjet LCD
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);    
         
// Définition du capteur DHT11
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
   Serial.begin(9600);
   Serial.println("Germinator v1.0!");
 
   dht.begin();
   lcd.begin(16,2);   
}

void loop() {
	
	 
	// Lecture de l'hygrométrie
	float humidity = dht.readHumidity();
	 
	// Lecture de la température en °C
	float temperature = dht.readTemperature();

	// Lecture capteur moisture
        //analogWrite(MOISTUREPIN, HIGH);
	int moistureSensor = analogRead(MOISTUREPIN);
	//analogWrite(MOISTUREPIN, LOW);

	// Lecture capteur water
	int waterSensor = analogRead(WATERPIN);


	//On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
	if (isnan(humidity) || isnan(temperature) ) {
	  //Serial.print("h:");Serial.println(humidity);
	  Serial.println("Failed to read data!");
	  return;
	}
	
	// Affichage LCD
	
	lcd.setCursor(0,0);                                               // placement du curseur 1ére ligne
	lcd.print("H:");
	lcd.print(humidity);
	lcd.print("% ");
	lcd.print("T:");
	lcd.print(temperature);
		
	lcd.setCursor(0,1);                                               // placement du curseur 2ème ligne
	lcd.print("M:");
	lcd.print(moistureSensor);
	lcd.print(" W:");
	lcd.print(waterSensor);
	
	//delay(100);
	//Affichages :
	Serial.print("Hum: ");
	Serial.print(humidity);
	Serial.print("%\t");
	Serial.print("Temp: ");
	Serial.print(temperature);
	Serial.print("C\t");
	Serial.print("Mois: ");
	Serial.println(moistureSensor);
	
	Serial.print("Niveau: ");
	Serial.println(waterSensor);
	
       // LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
       delay(10000);
       lcd.noDisplay();
        delay(50000);

}
