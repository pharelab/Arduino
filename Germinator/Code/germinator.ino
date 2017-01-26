/*
*
*
*
*/

#include <Firmata.h>
#include <Boards.h>
#include <LiquidCrystal.h>                               

#include "DHT.h"

// Définit le type de capteur utilisé
#define DHTTYPE DHT11

// Pin du capteur DHT11
#define DHTPIN 3 

// Affectation des bropches sur l"ecran LCD
#define en 8                                                            
#define rs 9
#define d7 13
#define d6 12
#define d5 11
#define d4 10


// Définition de lobjet LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);    
         
// Définition du capteur DHT11
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
   Serial.begin(115200);
   Serial.println("Germinator!");
 
   dht.begin();
   lcd.begin(16,2);   
}

void loop() {
	delay(5000);
	 
	// Lecture de l'hygrométrie
	float humidityValue = dht.readHumidity();
	 
	// Lecture de la température en °C
	float temparatureValue = dht.readTemperature();

	// Lecture capteur moisture
	int moistureSensor = analogRead(0);
	
	// Lecture capteur water
	int waterSensor = analogRead(1);


	//On verifie si la lecture a echoue, si oui on quitte la boucle pour recommencer.
	if (isnan(h) || isnan(t) ) {
		Serial.print("h:");Serial.println(h);
		Serial.println("Failed to read data!");
		return;
	}
	
	// Affichage LCD
	
	lcd.setCursor(0,0);                                               // placement du curseur 1ére ligne
	lcd.print("H:");
	lcd.print(h);
	lcd.print("% ");
	lcd.print("T:");
	lcd.print(t);
		
	lcd.setCursor(0,1);                                               // placement du curseur 2ème ligne
	lcd.print("M:");
	lcd.print(moistureSensor);
	lcd.print(" W:");
	lcd.print(waterSensor);
	
	//delay(100);
	//Affichages :
	Serial.print("Hum: ");
	Serial.print(h);
	Serial.print("%\t");
	Serial.print("Temp: ");
	Serial.print(t);
	Serial.print("C\t");
	Serial.print("Mois: ");
	Serial.println(m);
	
	Serial.print("Niveau: ");
	Serial.println(water);
	
	/*
	if(t > 20)
	 digitalWrite(13,HIGH);
	else
	 digitalWrite(13, LOW);
	*/
	 
}
