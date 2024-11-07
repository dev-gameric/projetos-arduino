#include <Servo.h>

Servo servoGarra;
Servo servoPunho;
Servo servoAntebraco;
Servo servoCotovelo;
Servo servoOmbro;
Servo servoBase;

int velocidade = 15; 
int anguloInicial = 90;
int anguloFinal = 10;
int passo = 1;

void setup() {
  servoGarra.attach(3);      
  servoPunho.attach(5);      
  servoAntebraco.attach(6);  
  servoCotovelo.attach(9);   
  servoOmbro.attach(10);      
  servoBase.attach(11);       
}

void loop() {
  moverServo(servoGarra, anguloInicial, anguloFinal);
  moverServo(servoPunho, anguloInicial, anguloFinal);
  moverServo(servoAntebraco, anguloInicial, anguloFinal);
  moverServo(servoCotovelo, 135, 90);
  moverServo(servoOmbro, 135, 90);    
  moverServo(servoBase, 0, 180);

  delay(1000); 
}

void moverServo(Servo servo, int anguloInicial, int anguloFinal) {
  for (int angulo = anguloInicial; angulo >= anguloFinal; angulo -= passo) {
    servo.write(angulo);
    delay(velocidade);
  }
  for (int angulo = anguloFinal; angulo <= anguloInicial; angulo += passo) {
    servo.write(angulo);
    delay(velocidade);
  }
}
