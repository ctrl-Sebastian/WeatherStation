#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define I2C_SDA 21
#define I2C_SCL 22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

DHT dht(DHT_PIN, DHT_TYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
	Serial.begin(115200);

	dht.begin();

	Wire.begin(I2C_SDA, I2C_SCL);
	display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
	display.clearDisplay();
	display.setTextColor(SSD1306_WHITE);
	display.setTextSize(2);
	display.display();

}

void loop()
{
	float temperature;
	float humidity;

	temperature = dht.readTemperature();
	humidity = dht.readHumidity();
	display.setTextSize(2);
	display.setCursor(0, 0);
	display.println("Weather");
	display.setTextSize(1);
	display.println((String)"temp: " + temperature);
	display.println((String)"humid: " + humidity);
	display.display();
	delay(1000);
	display.clearDisplay();
}
