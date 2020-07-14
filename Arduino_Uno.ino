
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#define led 3 //3.Pinde LED olduğunu tanımlıyoruz
int buzzerpin = 9;
int nemdegeri;
void setup() {
    Serial.begin(9600);
    
    pinMode(led,OUTPUT); //LED'in çıkış elemanı olduğunu belirtiyoruz
    pinMode(buzzerpin,OUTPUT);
}

void loop() {
  delay(1000);
 int su= analogRead(A2);
 int isik = digitalRead (2);
 Serial.println(isik);
Serial.println(su);
 /*
  Serial.println(nem);
  if(s.available()>0)
  {
   s.write(nem);
   nemdegeri = s.read();
  Serial.println(nemdegeri);
  delay(100);
  }
 */   
  
  if(isik > 0 ){ 
    digitalWrite(led,HIGH); 
  } 
   
  if(isik < 1){ 
  
    digitalWrite(led,LOW); 
  }

  if ( su > 100)
  {
    digitalWrite(buzzerpin,HIGH);
    delay(100);
    digitalWrite(buzzerpin,LOW);
    delay(20);

    
  }

   if ( su < 100)
  {
    digitalWrite(buzzerpin,LOW);
    
  }
  

  delay(1000);
}
