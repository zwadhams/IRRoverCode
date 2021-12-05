#include <IRremote.h>
#include <IRremoteInt.h>

#define IRPIN 7

IRrecv irrecv(IRPIN);
decode_results result;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&result)) 
  {
    Serial.println(result.value);
    irrecv.resume(); 
  }
}
