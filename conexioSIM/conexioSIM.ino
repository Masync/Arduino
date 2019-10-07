// Librerias
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2); //Pines de comunicacion  ---> SIM TX(Pin 3) RX( Pin 2)

void setup() {
  // Velocidad --> Mensajeria de texto 115200 / Llamada 19200 / Serial 9600
  // Se debe manejar el mismo rango en Serial y en Myserial para dar conexion
  
  Serial.begin(115200);
  mySerial.begin(115200);
  Serial.println("-- iniciando Conexion --");
  delay(1000);

  //Comandos para la Tajeta SIM a bajo nivel
  mySerial.println("AT");
  updateSerial();

  mySerial.println("AT+CMGF=1");
  updateSerial();
  //Println para instrucciones y print para mensajes
  mySerial.println("AT+CMGS=\"+573162741054\"");
  updateSerial();
  mySerial.print("Amor este es un mensaje desde arduino <3 eres mi vida, besos");
  updateSerial();
  mySerial.write(26);
}

void loop() {
  // 
}
  void updateSerial(){
  delay(500);
  //Comunicacion serial
  while(Serial.available())
  {
    mySerial.write(Serial.read());
  }
  // Objeto creado para la comunicacion
   while(Serial.available())
  {
    Serial.write(mySerial.read());
  }
}
