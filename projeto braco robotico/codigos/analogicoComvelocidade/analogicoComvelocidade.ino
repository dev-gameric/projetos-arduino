#include <Servo.h>

#define ANGULO_180 180
#define ANGULO_90 90
#define ANGULO_45 45
#define ANGULO_0 0

#define joystick1x A0
#define joystick1y A1
#define joystick2x A2
#define joystick2y A3
#define joystick3x A4
#define joystick3y A5

Servo motorBase;
Servo motorOmbro;
Servo motorCotovelo;
Servo motorAntebraco;
Servo motorPunho;
Servo motorGarra;

int servoSpeed = 10;

int currentPosBase = ANGULO_90;
int currentPosOmbro = ANGULO_90;
int currentPosCotovelo = ANGULO_45;
int currentPosAntebraco = ANGULO_0;
int currentPosPunho = ANGULO_90;
int currentPosGarra = ANGULO_0;

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
  motorGarra.write(ANGULO_0);
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
  posX3 = map(posX3, 0, 1023, -90, 90);
  posY3 = map(posY3, 0, 1023, -90, 90);

  // Atualiza as posições independentemente do joystick
  moveServo(motorBase, posX);
  moveServo(motorOmbro, posX2);
  moveServo(motorCotovelo, posY);
  moveServo(motorPunho, posY2);
  moveServo(motorAntebraco, posX3);
  moveServo(motorGarra, posY3);

  delay(100);
}

void moveServo(Servo servo, int targetPos) {
  int currentPos = servo.read();
  if (currentPos < targetPos) {
    for (int i = currentPos; i <= targetPos; i++) {
      servo.write(i);
      delay(servoSpeed);
    }
  } else if (currentPos > targetPos) {
    for (int i = currentPos; i >= targetPos; i--) {
      servo.write(i);
      delay(servoSpeed);
    }
  }
}
