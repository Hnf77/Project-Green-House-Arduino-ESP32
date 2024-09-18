#define BLYNK_TEMPLATE_ID "TMPL6ZhQqT4wl"
#define BLYNK_TEMPLATE_NAME "Project UAS"
#define BLYNK_AUTH_TOKEN "8OnblcoXu4usO6LL05UTNQbajDbVmlC5"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Blynk Auth Token
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
char ssid[] = "FREE WIFI";
char pass[] = "";

// Variabel untuk menyimpan data sensor
float temperature;
float humidity;
int soilMoisture;
String lightValue;

// Blynk Virtual Pins
#define V1 1
#define V2 2
#define V3 3
#define V4 4

void setup() {
  Serial.begin(9600, SERIAL_8N1, 17, 16); // Serial1 untuk komunikasi dengan Arduino (TX pin di GPIO17 dan RX pin di GPIO16)
  delay(1000); // Delay untuk memberikan waktu serial monitor untuk memulai
  
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

  // Cek apakah ada data yang tersedia dari Arduino
  if (Serial.available() > 0) {
    // Baca data dari Arduino
    String data = Serial.readStringUntil('\n');
    // Pisahkan data berdasarkan tanda koma
    int commaIndex1 = data.indexOf(',');
    int commaIndex2 = data.indexOf(',', commaIndex1 + 1);
    int commaIndex3 = data.indexOf(',', commaIndex2 + 1);

    temperature = data.substring(0, commaIndex1).toFloat();
    humidity = data.substring(commaIndex1 + 1, commaIndex2).toFloat();
    soilMoisture = data.substring(commaIndex2 + 1, commaIndex3).toInt();
    lightValue = data.substring(commaIndex3 + 1);

    // Kirim data ke Blynk
    Blynk.virtualWrite(V1, temperature);
    Blynk.virtualWrite(V2, humidity);
    Blynk.virtualWrite(V3, soilMoisture);
    Blynk.virtualWrite(V4, lightValue);
  }


  delay(100); // Tunda sedikit sebelum membaca data berikutnya
}
