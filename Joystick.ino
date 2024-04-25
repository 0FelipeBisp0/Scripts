int eixo_X= A0;
int eixo_Y = A1; 
int botao = 2;
int b1 = 8;
int b2 = 9;
void setup(){
  pinMode (botao, INPUT_PULLUP); 
  Serial.begin (9600); 
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);

}
void loop(){

    if((analogRead(eixo_X)) == 0){ 
        Serial.println("PARA CIMA"); 
    digitalWrite(b1, HIGH);
    }
    if((analogRead(eixo_X)) == 1023){ 
              Serial.println("PARA BAIXO"); 
                  digitalWrite(b1, LOW);

    }
    if((analogRead(eixo_Y)) == 0){ 
                  Serial.println("DIREITA"); 
                      digitalWrite(b2, HIGH);

    }
    if((analogRead(eixo_Y)) == 1023){ 
                          Serial.println("ESQUERDA"); 
                              digitalWrite(b2, LOW);

    }
    if(digitalRead(botao) == LOW){ 
        Serial.println("BOTAO PRESSIONADO"); 
        digitalWrite(b1, HIGH);
    	digitalWrite(b2, HIGH);

    }  
  }