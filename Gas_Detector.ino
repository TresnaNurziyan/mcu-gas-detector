#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space

char auth[] = "dzBCqV9cKD1eibZoB-KSfNnXVR4qTZXu"; //Enter Authentication code sent by Blynk on your regested email
char ssid[] = "GRYFFINDOR"; // Enter WIFI Name Here
char pass[] = "Al0homor4"; // Enter WIFI Password Here

int mq2 = A0; // smoke sensor is connected with the analog pin A0 
int data = 0;

const int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, getSendData);
}

void loop() {
  // put your main code here, to run repeatedly:
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}

void getSendData() {
  data = analogRead(mq2); 
  Blynk.virtualWrite(V2, data);
 
  if (data > 800 )
  {
    Blynk.notify("Smoke Detected!"); 
    tone(buzzer, 1000);
  } else {
    noTone(buzzer);
  }
}
