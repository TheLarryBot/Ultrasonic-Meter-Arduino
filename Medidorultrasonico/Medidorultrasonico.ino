#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define ANCHO_PANTALLA 128  
#define ALTO_PANTALLA 64    

#define OLED_RESET -1            
#define DIRECCION_PANTALLA 0x3C  

Adafruit_SSD1306 display(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, OLED_RESET);

int pinTrig = 8;
int pinEcho = 9;
int time;
int distance;

void setup() {

  if (!display.begin(SSD1306_SWITCHCAPVCC, DIRECCION_PANTALLA)) {
    Serial.println(F("Fallo en la asignacion de SSD1306"));
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.setTextSize(3);
  display.println("Larrybot");
  display.display();

  ///////////////////////////////////////////////////////////////

  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  Serial.begin(9600);
  digitalWrite(pinTrig, LOW);

}

void loop() {
  //put your main code here, to run repeatedly:

  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  time = pulseIn(pinEcho, HIGH);

  distance = time / 59;

  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(25, 16);
  display.print(distance);
  display.print("CM");
  display.display();
  delay(30);
}
