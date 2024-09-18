#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define LDR_PIN_DO 3
#define RELAY_PUMP_PIN 7
#define RELAY_LIGHT_PIN 8
#define SOIL_PIN A1

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial espSerial(4, 5); // SoftwareSerial untuk komunikasi dengan ESP32 (TX, RX)


// Kalibrasi nilai kelembapan tanah (sesuaikan dengan sensor dan kondisi tanah Anda)
const int soilDryValue = 800; // Nilai saat tanah sangat kering
const int soilWetValue = 300; // Nilai saat tanah sangat basah

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600); // Mulai komunikasi serial dengan baud rate 9600
  dht.begin();
  pinMode(RELAY_PUMP_PIN, OUTPUT);
  digitalWrite(RELAY_PUMP_PIN, LOW);
  pinMode(RELAY_LIGHT_PIN, OUTPUT);
  digitalWrite(RELAY_LIGHT_PIN, LOW);
  lcd.init();
  lcd.backlight();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int lightValue = digitalRead(LDR_PIN_DO);
  int soilMoistureRaw = analogRead(SOIL_PIN);

  // Konversi nilai kelembapan tanah ke persen (0% sangat kering, 100% sangat basah)
  int soilMoisturePercent = map(soilMoistureRaw, soilDryValue, soilWetValue, 0, 100);
  soilMoisturePercent = constrain(soilMoisturePercent, 0, 100);

  // Mengirim data ke ESP32 melalui SoftwareSerial
  espSerial.print(temperature);
  espSerial.print(",");
  espSerial.print(humidity);
  espSerial.print(",");
  espSerial.print(soilMoisturePercent);
  espSerial.print(",");
  if (lightValue == HIGH) {
    espSerial.println("Gelap");
  } else {
    espSerial.println("Terang");
  }

  // Tampilkan data di Serial Monitor
  Serial.print("Temperature: ");
  Serial.println(temperature);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Soil Moisture: ");
  Serial.println(soilMoisturePercent);
  Serial.print("Light Value: ");
  Serial.println(lightValue == HIGH ? "Gelap" : "Terang");


  // Kontrol pompa otomatis berdasarkan sensor
  if (soilMoisturePercent > 69) { // Ambang batas kelembapan yang diinginkan
    digitalWrite(RELAY_PUMP_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PUMP_PIN, LOW);
  }


  // Kontrol lampu berdasarkan intensitas cahaya
  if (lightValue == LOW) {
    digitalWrite(RELAY_LIGHT_PIN, HIGH);
  } else {
    digitalWrite(RELAY_LIGHT_PIN, LOW);
  }

  // Tampilkan data di LCD
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(temperature);
  lcd.print("C");
  lcd.print(" H: ");
  lcd.print(humidity);                                                                                                                               
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("L: ");
  lcd.print(lightValue == HIGH ? "Gelap" : "Terang");
  lcd.print(" S: ");
  lcd.print(soilMoisturePercent);
  lcd.print("%");

  delay(5000);  // Tunda selama 5 detik
}
