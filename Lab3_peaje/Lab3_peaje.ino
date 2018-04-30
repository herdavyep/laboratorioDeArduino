#include <Servo.h>      //Incluimos la libreria Servo
#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 24, 26, 28, 30, 32);
Servo servoMotor;

const int EchoPin = 5;
const int TriggerPin = 6;
const int LedPin = 23;
const int LedPin1 = 25;
int pul=0;
const int pinpul = 2;
int estado= 0;
bool carro = false;

void setup() {
   Serial.begin(9600);
   pinMode(LedPin, OUTPUT);
   pinMode(LedPin1, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   lcd.begin(16,2);
  pinMode(pinpul, INPUT);
  servoMotor.attach(8);
}
 
void loop() {
   // Desplazamos a la posición 0º
         servoMotor.write(0);
      
   int cm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(cm);
   delay(1000);
   if(estado == 0){
     digitalWrite(LedPin1,LOW);
     digitalWrite(LedPin,HIGH);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Bienvenido");
     lcd.setCursor(12,0);
     lcd.print("D=");
     lcd.print(cm);
     lcd.setCursor(0,1);
     lcd.print("Por favor siga");
   }
   if(cm <= 10){
   carro = true;
   estado = 1;
   }
   
   if(carro){
     digitalWrite(LedPin1,LOW);
     digitalWrite(LedPin,HIGH);
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Por Favor PARE"); 
     lcd.setCursor(0,1);
     lcd.print("Cancele 5000 COP");
     //estado=1;
         pul = digitalRead(pinpul);
     while(pul == LOW){
       pul = digitalRead(pinpul);
     }
     
    
      if(pul == HIGH){
        
      digitalWrite(LedPin,HIGH);
       lcd.clear(); 
       lcd.setCursor(0,1);
     lcd.print("PAGADO");
     delay(5000);
     lcd.clear();
     digitalWrite(LedPin,LOW);
     lcd.setCursor(0,0);  
     lcd.print("Hasta pronto");
      lcd.setCursor(0,1);  
     lcd.print("Buen Viaje");
     carro = false;
    digitalWrite(LedPin1,HIGH);
          // Desplazamos a la posición 90º
           servoMotor.write(90);
          // Esperamos 1 segundo
         delay(5000);
         digitalWrite(LedPin1,LOW);
         estado=0;
        
        
      }
      
}
}
 
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}
