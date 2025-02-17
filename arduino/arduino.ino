#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "pin_config.h"
#include "epd2in13d.h"
#include "imagedata.h"

Adafruit_BMP280 bmp(BMP280_CS_PIN,&SPI);
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();
Epd epd;

void print_aa_logo(void){
	Serial.println();
	Serial.println(F(" _      ____  ___   __    __   _____   __    __   "));
	Serial.println(F("\\ \\  / | |_  | |_) ( (`  / /\\   | |   / /\\  / /`_ "));
	Serial.println(F(" \\_\\/  |_|__ |_| \\ _)_) /_/--\\  |_|  /_/--\\ \\_\\_/ "));
	Serial.println();
}

void ensure_bmp_configured(void){
  unsigned status = bmp.begin(BMP280_ADDRESS_ALT,BMP280_CHIPID);
  if (!status) {
		Serial.println(F("Failed to find BMP280 sensor, check wiring!"));

		unsigned sensorID = bmp.sensorID();
    Serial.print("SensorID was: 0x"); Serial.println(bmp.sensorID(),16);
		Serial.print("Presumed cause: ");

		if (sensorID ==0xFF || sensorID == 0x00) {
			Serial.println(F("A bad address or BMP 180 or BMP 085 connected"));
		} else if (sensorID >= 0x56 && sensorID <= 0x58) {
			Serial.println(F("There might be a BMP280 connected, but the chip ID doesn't match."));
		} else if(sensorID == 0x60 ){
			Serial.println(F("You might have a BME280 connected, instead of a BMP280."));
		}else if (sensorID == 0x61){
			Serial.println(F("You might have a BME680 connected, instead of a BMP280."));
		}else{
			Serial.print("Unknown");
		}

    while (1) delay(10);
	}

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

	Serial.println(F("BMP280 Sensor Configured!"));
  bmp_temp->printSensorDetails();
}

void setup() {
  Serial.begin(115200);
	SPI.begin(18,36,26,-1);//SCK, MISO, MOSI, SS

	print_aa_logo();
	Serial.println(F("Starting..."));

	ensure_bmp_configured();


	Serial.println(F("Initializing EPD..."));
	if(epd.Init()!=0){
		Serial.println(F("EPD Init failed"));
		while(1);
	}

	epd.Clear();
	Serial.print("Displayimage\n");
	epd.Display(gImage_IMAGE);
	delay(2000);
	epd.Sleep();
}

void loop() {

  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  
  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  Serial.println();
  delay(2000);

}
