#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 24, 26, 28, 30, 32);

float centigrados(){// Funcion para convertir a centigrados
  int dato;
  float c; // Declaracion de variables
  dato=analogRead(A0); // Lectura del puerto A0 y se iguala a la variable
  c = (500.0 * dato)/1023; // Formula de Conversion de analogo a digital
  return(c); // Retorna el valor Convertido
}

int led1= 23; //Declaracion de variables para los led
int led2= 25;
void setup() {
 
 
  lcd.begin(16,2);// se define la LCD
  lcd.setCursor(0,0);// Pposicion de los caracteres
  lcd.print("Temperatura");// imprime en la LCD para mantenerse estatico
  
  pinMode(led1,OUTPUT); // Declaracion de pines de salida
  pinMode(led2,OUTPUT);
}

void loop() {
  
  float grados = centigrados(); // Se declara vaiable y se iguala a la funcion
  lcd.setCursor(0,1);
  lcd.print(grados); // muestra el valor que entraga la funcion
  lcd.setCursor(5,1);
  lcd.print("C");  
  lcd.print((char)223); // para mostrar el simbolo de grados
  
  if (grados > 35){
   digitalWrite(led1,HIGH); 
   digitalWrite(led2,LOW); 
   lcd.setCursor(10,1);
  lcd.print("ALTA");
  }else{
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    lcd.setCursor(10,1);
    lcd.print("BAJA");
  }
  delay(300);
}
