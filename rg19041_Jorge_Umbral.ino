#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <EEPROM.h>

int RST = 9, CE = 10, DC = 11, DIN = 12, CLK = 13;
Adafruit_PCD8544 display = Adafruit_PCD8544(CLK, DIN, DC, CE, RST);
int value = 0, u1 = 0, u2 = 0;
int cx = 0;
int cy = 0;
const int MAX_COORDS = 73;
int coords[MAX_COORDS][2];

void setup() {
  Serial.begin(9600);
  _display_initialization();
  _draw_frame();
  _print_headers();
}

void loop() {
  value = EEPROM.read(0);
  u1 = EEPROM.read(1);
  u2 = EEPROM.read(2);
  _read_potentiometer();
  _draw_graph();
  _print_values();
}

