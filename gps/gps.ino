
// Librerias
#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Variables 
TinyGPS gps;
SoftwareSerial serialgps(3,4);  //pin 3(tx del gps)   pin 4(rx del gps)

int year;
byte month, day, hour, minute, second, hundredths;
unsigned long chars;
unsigned short sentences, failed_checksum;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  
  serialgps.begin(9600);

  Serial.println("");
  Serial.println("Conectando el GPS ...");
  Serial.println("--- Buscando señal ---");
  Serial.println("");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  while(serialgps.available())
  {
    int c = serialgps.read();
    if(gps.encode(c))
    {
      float latitud, longitud;
      gps.f_get_position(&latitud, &longitud);
      Serial.print("Latitud / Longitud");
      Serial.print(latitud,5);
      Serial.print(", ");
      Serial.print(longitud,5);

      gps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths);
        Serial.print("Feha:"); Serial.print(day, DEC);  Serial.print("/"); 
        Serial.print(month, DEC);  Serial.print("/");  Serial.print(year);
        Serial.print("Hora:"); Serial.print(hour, DEC);  Serial.print(":"); 
        Serial.print(minute, DEC); Serial.print(hour, DEC);  Serial.print(":"); 
        Serial.print(minute, DEC); Serial.print(":");  Serial.print(second, DEC);
        Serial.print(":"); Serial.println(hundredths, DEC);
        Serial.print("Altitud (Metros): "); Serial.println(gps.f_altitude());
          Serial.print("Rumbo (Grados): "); Serial.println(gps.f_course());
          Serial.print("Velocidad (kmph): "); Serial.println(gps.f_speed_kmph());
          Serial.print("Satelite (kmph): "); Serial.println(gps.satellites());
          Serial.println();
          gps.stats(&chars, &sentences, &failed_checksum);
       
        
          
        
      
    }
  }

}
