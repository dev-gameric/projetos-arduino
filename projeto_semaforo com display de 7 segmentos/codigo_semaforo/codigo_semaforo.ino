// Dando "nome" para as portas
int vermelho_1 = 10;
int amarelo_1 = 9;
int verde_1 = 8;

int vermelho_2 = 7;
int verde_2 = 6;

void setup() {
  // Indicando para o Arduino quais portas vamos usar
  pinMode(vermelho_1, OUTPUT);
  pinMode(amarelo_1, OUTPUT);
  pinMode(verde_1, OUTPUT);

  pinMode(vermelho_2, OUTPUT);
  pinMode(verde_2, OUTPUT);

  Serial.begin(9600); // Inicializa a comunicação serial com o Slave
}

void loop() {
   cruzamento();
}

void cruzamento() {
  int countdown = 9; // Começar contagem regressiva a partir de 9

  // Sinal 1 - Vermelho
  digitalWrite(amarelo_1, LOW);
  digitalWrite(vermelho_1, HIGH);
  digitalWrite(verde_1, LOW);
  delay(1000);

  // Sinal 2 - Verde
  digitalWrite(vermelho_2, LOW);
  digitalWrite(verde_2, HIGH);

  // Contagem regressiva de 9 a 0 no display
  for (int i = countdown; i >= 0; i--) {
    Serial.write(i);       // Enviar valor de contagem para o Arduino Slave
    delay(1000);           // Aguardar 1 segundo
  }

  // Sinal 2 - Vermelho
  digitalWrite(vermelho_2, HIGH);
  digitalWrite(verde_2, LOW);

  // Sinal 1 - verde
  digitalWrite(vermelho_1, LOW);
  digitalWrite(verde_1, HIGH);

  delay(5000); // Sinal 2 fechado / Sinal 1 aberto por 5s

  // Sinal 1 - Amarelo => Vermelho
  digitalWrite(verde_1, LOW);
  digitalWrite(amarelo_1, HIGH);
  delay(3000);

}
