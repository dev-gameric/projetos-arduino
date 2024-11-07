#include <Servo.h>

// angulo inicial do motor
#define ANGULO_180 180
#define ANGULO_90 90
#define ANGULO_45 45
#define ANGULO_0 0

// Mapeamento dos joysticks 
#define joystick1x A0
#define joystick1y A1
#define joystick2x A2
#define joystick2y A3
#define joystick3x A4
#define joystick3y A5

// Mapeamento dos servos
Servo motorBase;
Servo motorOmbro;
Servo motorCotovelo;
Servo motorAntebraco;
Servo motorPunho;
Servo motorGarra;

void setup() {
  motorBase.attach(3);
  motorOmbro.attach(5);
  motorCotovelo.attach(6);
  motorAntebraco.attach(9);
  motorPunho.attach(10);
  motorGarra.attach(11);
  pinMode(joystick1x, INPUT);
  pinMode(joystick1y, INPUT);
  pinMode(joystick2x, INPUT);
  pinMode(joystick2y, INPUT);
  pinMode(joystick3x, INPUT);
  pinMode(joystick3y, INPUT);
  motorBase.write(ANGULO_90);
  motorOmbro.write(ANGULO_90);
  motorCotovelo.write(ANGULO_45);
  motorAntebraco.write(ANGULO_0);
  motorPunho.write(ANGULO_90);
  motorGarra.write(ANGULO_45);
}

void loop() {
  int posX = analogRead(joystick1x);
  int posY = analogRead(joystick1y);
  int posX2 = analogRead(joystick2x);
  int posY2 = analogRead(joystick2y);
  int posX3 = analogRead(joystick3x);
  int posY3 = analogRead(joystick3y);
  posX = map(posX, 0, 1023, 0, 180);
  posY = map(posY, 0, 1023, 180, 50);
  posX2 = map(posX2, 0, 1023, 135, 10);
  posY2 = map(posY2, 0, 1023, 135, 0);
  posX3 = map(posX3, 0, 1023, 0, 180);
  posY3 = map(posY3, 0, 1023, 0, 180);
  motorBase.write(posX);
  motorOmbro.write(posX2);
  motorCotovelo.write(posY);
  motorPunho.write(posY2);
  motorAntebraco.write(posX3);
  motorGarra.write(posY3);
  delay(100);
}

