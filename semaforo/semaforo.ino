
#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 24, 26, 28, 30, 32);

int rojo1 = 38;
int amarillo1 = 40;
int verde1 = 42;
int semaforo1 = 1;

int rojo2 = 52;
int amarillo2 = 50; 
int verde2 = 48;

int pulsador1 = 2;
int estadoPulsador1 = 0;

int pulsador2 = 3;
int estadoPulsador2 = 0;

void setup() {
  
  Serial.begin(9600);
  lcd.begin(16,2);// se define la LCD
  lcd.setCursor(0,0);// Pposicion de los caracteres
  lcd.print("Deje Presionado");//
pinMode(rojo1 ,OUTPUT);
pinMode(amarillo1 ,OUTPUT);
pinMode(verde1 ,OUTPUT);

pinMode(rojo2 ,OUTPUT);
pinMode(amarillo2 ,OUTPUT);
pinMode(verde2 ,OUTPUT);

pinMode(pulsador1, INPUT);
pinMode(pulsador2, INPUT);
}

void delayPulsador(){
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(rojo2, HIGH);

  //verdee    
  estadoPulsador2 = digitalRead(pulsador2);    
  if(estadoPulsador2 == HIGH){
    digitalWrite(rojo1,HIGH);
    lcd.clear();
    lcd.print("Soltar Boton");
    lcd.setCursor(0,1);
    lcd.print("Puede Cruzar");
    
    digitalWrite(rojo2,LOW);
    digitalWrite(amarillo2, HIGH);
    delay(1000);
    digitalWrite(amarillo2, LOW);
    digitalWrite(verde2, HIGH);
    delay(5000);
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Deje Presionado");
  
  }else{
    digitalWrite(verde1, HIGH);
    delay(3000);
    digitalWrite(verde1, LOW);
    digitalWrite(amarillo1, HIGH);
    
    delay(1000);
  
  digitalWrite(amarillo1, LOW);
  digitalWrite(rojo1, HIGH);
  
  delay(1000);
  
  digitalWrite(rojo2, LOW);
  digitalWrite(amarillo2, HIGH);
  
  delay(1000);
  
  digitalWrite(amarillo2, LOW);
  }
  
  
  
  
  //verde
  estadoPulsador1 = digitalRead(pulsador1);    
  if(estadoPulsador1 == HIGH){
    digitalWrite(rojo2,HIGH);
    lcd.clear();
    lcd.print("Soltar Boton");
    lcd.setCursor(0,1);
    lcd.print("Puede Cruzar");

    digitalWrite(rojo1,LOW);
    digitalWrite(amarillo1, HIGH);
    delay(1000);
    digitalWrite(amarillo1, LOW);
    digitalWrite(verde1, HIGH);
    delay(5000);
        
     lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Deje Presionado");
 

  }else{
    digitalWrite(verde2, HIGH);
    delay(3000);
    digitalWrite(verde2, LOW);
    digitalWrite(amarillo2, HIGH);
  
  delay(1000);
  
  digitalWrite(amarillo2, LOW);
  digitalWrite(rojo1, LOW);
 
 digitalWrite(amarillo1, HIGH);
  digitalWrite(rojo2, HIGH);
  
  delay(1000);
  
  digitalWrite(amarillo1, LOW);
  }
  
   

}
