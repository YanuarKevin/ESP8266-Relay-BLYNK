#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Ganti dengan detail WiFi Anda
char ssid[] = "YOUR_SSID";
char pass[] = "YOUR_PASSWORD";

// Ganti dengan Auth Token dari Blynk
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Pin relay
#define RELAY1_PIN D1
#define RELAY2_PIN D2
#define RELAY3_PIN D3
#define RELAY4_PIN D4

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(RELAY3_PIN, OUTPUT);
  pinMode(RELAY4_PIN, OUTPUT);

  // Mematikan relay pada awal jika relay aktif low, jika aktif high rubah ke low
  digitalWrite(RELAY1_PIN, HIGH);
  digitalWrite(RELAY2_PIN, HIGH);
  digitalWrite(RELAY3_PIN, HIGH);
  digitalWrite(RELAY4_PIN, HIGH);
}

void loop() {
  Blynk.run(); 
}

// Fungsi untuk mengontrol relay melalui Blynk
BLYNK_WRITE(V0) {
  digitalWrite(RELAY1_PIN, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(RELAY2_PIN, param.asInt());
}

BLYNK_WRITE(V2) {
  digitalWrite(RELAY3_PIN, param.asInt());
}

BLYNK_WRITE(V3) {
  digitalWrite(RELAY4_PIN, param.asInt());
}
