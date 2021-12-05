#include <IRremote.h>
#define irPin 7
 
IRrecv irrecv(irPin);
decode_results results;
 
//sets up pins that correlate to each motor (runs once)
void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn();
}

//switch statement for each case of movement (loops infinitely)
void loop() {
  
   if (irrecv.decode(&results)) {
      Serial.println(results.value);
      
      switch (results.value) {
        
         case 16718055:            // button 2 FORDWARD
            forward();
            break;
 
         case 16716015:            // button 4 LEFT
            left();
            break;
               
         case 16726215:            // button 5 STOP
            Stop();
            break;
 
         case 16734885:            // button 6 RIGHT
            right();
            break;
 
         case 16730805:            // button 8 BACK
            back();
            break;
 
         
         }      
   irrecv.resume(); 
   }
}
 
// below are each of the 5 functions used

//makes all motors turn forward
void forward()
{
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
}

//makes all motors turn backwards
void back()
{
              digitalWrite(8, LOW);
              digitalWrite(9, HIGH);
              digitalWrite(10, LOW);
              digitalWrite(11, HIGH);
}

//makes left motors turn forward and right motors turn backwards
void left()
{
            digitalWrite(8, LOW);
            digitalWrite(9, HIGH);
            digitalWrite(10, HIGH);
            digitalWrite(11, LOW);
}

//makes right motors turn forward and left motors turn backwards
void right()
{
              digitalWrite(8, HIGH);
              digitalWrite(9, LOW);
              digitalWrite(10, LOW);
              digitalWrite(11, HIGH);
} 

//stops all motor movement
void Stop()
{
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(11, LOW);
}
