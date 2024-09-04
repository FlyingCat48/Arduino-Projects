

#define BLYNK_TEMPLATE_ID "TMPL3sIOHguwJ"
#define BLYNK_TEMPLATE_NAME "WIFiTEST01"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#include "BlynkEdgent.h"


const int IR_pin = A0;
int int_val =0;



BLYNK_WRITE(V0)
{
  if(param.asInt()==1){
    digitalWrite(2, HIGH);
  }
  else{
    digitalWrite(2, LOW);
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);  
  Blynk.virtualWrite(V1,int_val);
}

void setup()
{
  pinMode(2, OUTPUT); 
  pinMode(IR_pin,INPUT);
  
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  int_val = analogRead(A0);
  Serial.println(int_val);
  BlynkEdgent.run();
}
