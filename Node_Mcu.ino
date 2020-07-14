#include <SoftwareSerial.h>


#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
#define FIREBASE_HOST "gardenio-34af8.firebaseio.com"
#define FIREBASE_AUTH "JVWRPjn3I4Qkr8D9PSoT7TXYOk6DSe6mJI3CtbJZ"
const char* ssid="SUPERONLINE_WiFi_2582";
const char* password = "CLELP9J4PR4P"; 
String myString;
String myString2;
String myString3;
String myString4;


void setup() {
  
  Serial.begin(9600);

  while (!Serial) continue;
  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);


}
 
void loop() {
   
  
  int sicveri;
 
  int su = analogRead(A0);
  int isik = digitalRead(D0);
  int sicaklik = digitalRead(D1);
  int nemdegeri = digitalRead(D7);

  delay(3000);
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["data1"] = isik;
  root["data2"] = su;
  root["data3"] = nemdegeri;
  root["data4"] = sicaklik;

   if (root == JsonObject::invalid()){  
    
      return;
  }
      

    if(Firebase.failed()){
    
    Serial.print("push");
    Serial.print(Firebase.error());
    return;
  }
 
  root.prettyPrintTo(Serial);
  Serial.print("Data 1 ");
  Serial.println("");
  int data1=root["data1"];
  myString = String(data1);
  Serial.println(myString); 
  Firebase.setString("Isik",myString);

  Serial.print("Data 2 ");
  Serial.println("");
  int data2=root["data2"];
  int data3= data2 ;
  myString2 = String(data3);
  Serial.println(myString2); 
  Firebase.setString("Su",myString2);
  

  Serial.print("Data 3 ");
  Serial.println("");
  int data5=root["data3"];
  myString3 = String(data5);
  Serial.println(myString3); 
  Firebase.setString("Nem",myString3);

  Serial.print("Data 4 ");
  Serial.println("");
  int data4=root["data4"];
  myString4 = 15;
  Serial.println(myString4); 
  Firebase.setString("Sicaklik",myString4); 

}
