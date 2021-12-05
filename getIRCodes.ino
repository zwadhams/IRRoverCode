#include <IRremote.h>
#include <IRremoteInt.h>

#define IRPIN 7 //pin that the ir reciever is connected to

IRrecv irrecv(IRPIN);
decode_results result;


//starts up the ir reciever and prints status message
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");

}

//decodes the recieved signal and prints out the value returned
//this is used to map the remote for rover movement
void loop() {
  if (irrecv.decode(&result)) 
  {
    Serial.println(result.value);
    irrecv.resume(); 
  }
}
