#include <SoftwareSerial.h>

SoftwareSerial bluetooth(11, 12); // RX, TX

int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int vel1 = 9;
int vel2 = 10;
int  v;
void setup() {
  Serial.begin(9600); // Inicializa a comunicação serial para o monitor serial
  bluetooth.begin(9600); // Inicializa a comunicação serial para o módulo Bluetooth
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(vel1, OUTPUT);
  pinMode(vel2, OUTPUT);
  v = 80;

}

void loop() {

  // Verifica se há dados disponíveis no módulo Bluetooth
  if (bluetooth.available() > 0) {
    char command = bluetooth.read(); // Lê o comando enviado pelo aplicativo Bluetooth
    if (command == 'X'){
      v = 80;
    }
    if (command == 'Y'){
      v = 150;
    }
      Serial.println(v);

    // Imprime o valor recebido no monitor serial
    Serial.println("Comando recebido: " + String(command));

    // Executa a ação com base no comando recebido
    switch (command) {
      case 'F':
        frente();
        break;
      case 'G':
        tras();
        break;
      case 'L':
        esq();
        break;
      case 'R':
        dir();
        break;
      case 'S':
        para();
        break;
      case 'E':
        curvaD();
        break;
      case 'Q':
        curvaE();
        break;
    }
  }
}

void tras() {
  Serial.println("tras");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(vel1, v);
  analogWrite(vel2, v);
}

void frente() {
  Serial.println("frente");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, v);
  analogWrite(vel2, v);
}

void esq() {
  Serial.println("esquerda");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(vel1, 60);
  analogWrite(vel2, 60);
}

void dir() {
  Serial.println("direita");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, 60);
  analogWrite(vel2, 60);
}

void para() {
  Serial.println("parando");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, 0);
  analogWrite(vel2, 0);
}

void curvaE() {
  Serial.println("curvaE");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, 75);
  analogWrite(vel2, 130);
}

void curvaD() {
  Serial.println("curvaD");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(vel1, 130);
  analogWrite(vel2, 75);
}

