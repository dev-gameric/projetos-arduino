// Configuração dos pinos e numerais do display
int Pinos[] = {2, 3, 4, 5, 6, 7, 8, 9};
byte numeral[10][7] = {
                      {1, 1, 1, 1, 1, 1, 0}, // 0
                      {0, 1, 1, 0, 0, 0, 0}, // 1
                      {1, 1, 0, 1, 1, 0, 1}, // 2
                      {1, 1, 1, 1, 0, 0, 1}, // 3
                      {0, 1, 1, 0, 0, 1, 1}, // 4
                      {1, 0, 1, 1, 0, 1, 1}, // 5
                      {1, 0, 1, 1, 1, 1, 1}, // 6
                      {1, 1, 1, 0, 0, 0, 0}, // 7
                      {1, 1, 1, 1, 1, 1, 1}, // 8
                      {1, 1, 1, 0, 0, 1, 1}  // 9
                    };

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(Pinos[i], OUTPUT); // Inicializa os pinos como saídas
  }
  Serial.begin(9600); // Inicializa a comunicação serial com o Master
}

void escreversegmento(byte cont) {
  byte pino = 2; // Começa no primeiro pino do Arduino
  for (byte contseg = 0; contseg < 7; contseg++) {
    digitalWrite(pino, numeral[cont][contseg]); // Escreve o número
    pino++; // Incrementa os pinos até o pino 8
  }
  digitalWrite(9, HIGH); // Ponto decimal (opcional)
}

void loop() {
  if (Serial.available()) {
    int displayValue = Serial.read(); // Recebe valor do Master
    escreversegmento(displayValue);   // Atualiza o display com o valor
  }
}
