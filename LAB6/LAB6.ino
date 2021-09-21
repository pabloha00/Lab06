/***************************Definición de Variables*************************/

#define A1 PA_7 //Camiamos de nombre los pines
#define A2 PA_6
#define A3 PA_5
#define A4 PB_4
#define A5 PE_5
#define A6 PE_4
#define A7 PB_1
#define A8 PB_0

#define B1 PA_2
#define B2 PD_7
#define B3 PD_6
#define B4 PC_7
#define B5 PC_6
#define B6 PC_5
#define B7 PC_4
#define B8 PB_3

int AA; //Antirrebote para los jugadores
int BB;
int EN; //Enable para comenzar el juego
int ZZ; //Contador de jugadores
int YY;

/***************************Prototipo de Funciones*************************/

void CONT1(void); //Función de ambos jugadores
void CONT2(void);
void SEMAFORO(void);  //Función del semáforo

/***************************Setup*************************/

void setup() {
  pinMode(PUSH1, INPUT_PULLUP); //Pullups a los push
  pinMode(PUSH2, INPUT_PULLUP);
  
  pinMode(A1, OUTPUT); //Output a las luces de los jugadores
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);
  pinMode(A7, OUTPUT);
  pinMode(A8, OUTPUT);
  
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(B5, OUTPUT);
  pinMode(B6, OUTPUT);
  pinMode(B7, OUTPUT);
  pinMode(B8, OUTPUT);
  
  pinMode(BLUE_LED, OUTPUT);  //Output a los pines que controlan el led RGB
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  
  AA=0; //Antirrebote enable y contador en 0
  BB=0;
  EN=0;
  YY=0;
  ZZ=0;
}
  /***************************Main Loop*************************/

void loop() {
  if (EN==0){ //Si el enable no ha sido activado comenzará la función del semáforo
    SEMAFORO();
  }
  else if  (EN==1){ //Si el enable ya fue activado se ejecutan los contadores
  CONT1();
  CONT2();    
  }
}

/***************************Funciones*************************/

void CONT1(void){
  if (digitalRead(PUSH1)==LOW){ //Antirrebote del jugador 1
    AA=1;
  }
  else if (digitalRead(PUSH1)==HIGH && AA==1){  //Si deja de presionar el botón
    AA=0; //Se regresa el antirrebote a 0
    ZZ++; //Se suma 1 al contador
    switch(ZZ){
      case 1:
      digitalWrite(A1,HIGH);  //Se enciende el primer led
      digitalWrite(A2,LOW);
      digitalWrite(A3,LOW);
      digitalWrite(A4,LOW);
      digitalWrite(A5,LOW);
      digitalWrite(A6,LOW);
      digitalWrite(A7,LOW);
      digitalWrite(A8,LOW);
      break;
      case 2:
      digitalWrite(A1,LOW);   //Se apaga el pin 1 y se enciende el 2
      digitalWrite(A2,HIGH);
      break;
      case 3:
      digitalWrite(A2,LOW);   //Así susesivamente hasta que el contador llegue a 9
      digitalWrite(A3,HIGH);
      break;
      case 4:
      digitalWrite(A3,LOW);
      digitalWrite(A4,HIGH);
      break;
      case 5:
      digitalWrite(A4,LOW);
      digitalWrite(A5,HIGH);
      break;
      case 6:
      digitalWrite(A5,LOW);
      digitalWrite(A6,HIGH);
      break;
      case 7:
      digitalWrite(A6,LOW);
      digitalWrite(A7,HIGH);
      break;
      case 8:
      digitalWrite(A7,LOW);
      digitalWrite(A8,HIGH);
      break;
      case 9:
      digitalWrite(A8,LOW); //Se apaga el ultimo pin
      digitalWrite(GREEN_LED,LOW);  //Se apaga la luz verde
      while(1){ //Está en un loop infinito  
        digitalWrite(RED_LED,HIGH);   //Se enciende una luz morada
        digitalWrite(BLUE_LED,HIGH);
        delay(500);
        digitalWrite(RED_LED,LOW);    //Se apaga la luz morada
        digitalWrite(BLUE_LED,LOW);
        delay(500);
        }
      break;
    }
  }
}

void CONT2(void){
  if (digitalRead(PUSH2)==LOW){ //Antirrebote del jugador 2
    BB=1;
  }
  else if (digitalRead(PUSH2)==HIGH && BB==1){  //Si se deja de presionar el push 2:
    BB=0;   //Antirrebote regresa a 0
    YY++;   //Se le suma uno al contador
    switch(YY){
      case 1:
      digitalWrite(B1,HIGH);  //Se enciende el pin 1
      digitalWrite(B2,LOW);
      digitalWrite(B3,LOW);
      digitalWrite(B4,LOW);
      digitalWrite(B5,LOW);
      digitalWrite(B6,LOW);
      digitalWrite(B7,LOW);
      digitalWrite(B8,LOW);
      break;
      case 2:
      digitalWrite(B1,LOW);
      digitalWrite(B2,HIGH);  //Se apaga el pin 1 y se enciende el 2
      break;
      case 3:
      digitalWrite(B2,LOW);   //Así susesivamente hasta que el contador llegue a 9
      digitalWrite(B3,HIGH);
      break;
      case 4:
      digitalWrite(B3,LOW);
      digitalWrite(B4,HIGH);
      break;
      case 5:
      digitalWrite(B4,LOW);
      digitalWrite(B5,HIGH);
      break;
      case 6:
      digitalWrite(B5,LOW);
      digitalWrite(B6,HIGH);
      break;
      case 7:
      digitalWrite(B6,LOW);
      digitalWrite(B7,HIGH);
      break;
      case 8:
      digitalWrite(B7,LOW);
      digitalWrite(B8,HIGH);
      break;
      case 9:
      digitalWrite(B8,LOW); //Se apaga el ultimo pin
      while(1){ //Está en un loop infinito
        digitalWrite(GREEN_LED,HIGH); //Se enciende una luz celeste
        digitalWrite(BLUE_LED,HIGH);
        delay(500);
        digitalWrite(GREEN_LED,LOW);  //Se apaga la luz celeste
        digitalWrite(BLUE_LED,LOW);
        delay(500);
        }
    }
  }
}

void SEMAFORO(void){
  if (digitalRead(PUSH1)==LOW && digitalRead(PUSH2)==LOW){  //Si se presionan ambos push a la vez:
    digitalWrite(RED_LED, HIGH);  //Se pondrá en rojo
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(1000);  //Esperará 1 segundo
    digitalWrite(RED_LED, HIGH);  //Se pondrá en amarillo
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(1000);  //1s
    digitalWrite(RED_LED, LOW); //Se pone en rojo el led RGB
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    EN=1; //Se activa el enable
  }
}
