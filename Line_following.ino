/*
 * Code Modified By: Mohamad Hafiz Bin Ahmad
 * Email: hafiz_apik99@yahoo.com
 * Youtube: https://www.youtube.com/channel/UC15t8HwKsRL2lTeP8uZlUjQ
*/
#include <SoftwareSerial.h>
#include <CytronMotorDriver.h> // https://github.com/CytronTechnologies/CytronMotorDriver   

// tetapan pin line sensor
int d1 = 7;
int d2 = 8;
int d3 = 9;
int d4 = 10;
int d5 = 11;

// tetapan motor driver
CytronMD motor1(PWM_PWM, 3, 4);   // PWM 1A = Pin 3, PWM 1B = Pin 4. Kalau motor pusing terbalik, tukarkan PWM 1A = Pin 4, PWM 1B = Pin 3
CytronMD motor2(PWM_PWM, 5, 6); // PWM 2A = Pin 5, PWM 2B = Pin 6. Kalau motor pusing terbalik, tukarkan PWM 2A = Pin 6,PWM 2B = Pin 5

  
void setup() 
{
  Serial.begin(9600);
 pinMode(d1, INPUT);
 pinMode(d2, INPUT);
 pinMode(d3, INPUT);
 pinMode(d4, INPUT);
 pinMode(d5, INPUT);

   //selepas on suis, tggu 3 saat
  delay (3000);
  
}
  
void loop() 
{

  // baca nilai dr sensor
  int D1 = digitalRead(d1);
  int D2 = digitalRead(d2);
  int D3 = digitalRead(d3);
  int D4 = digitalRead(d4);
  int D5 = digitalRead(d5);
   
   if (D1==0 && D2==0 && D3==1 && D4==0 && D5==0) 
   {
     Serial.println("Depan");
     motor1.setSpeed(255);   
     motor2.setSpeed(255);   
   }
   else if (D1==0 && D2==1 && D3==0 && D4==0 && D5==0) 
   {
     Serial.println("belok kiri sikit");
     motor1.setSpeed(255);   
     motor2.setSpeed(128);   
   }
      else if (D1==0 && D2==1 && D3==1 && D4==0 && D5==0) 
   {
     Serial.println("belok kiri sikit");
     motor1.setSpeed(255);   
     motor2.setSpeed(128);   
   }

   else if (D1==1 && D2==0 && D3==0 && D4==0 && D5==0) 
   {
     Serial.println("belok kiri banyak");
     motor1.setSpeed(255);   
     motor2.setSpeed(0);     
   }
   else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==0) 
   {
     Serial.println("belok kanan sikit");
     motor1.setSpeed(128);   
     motor2.setSpeed(255);    
   }
      else if (D1==0 && D2==0 && D3==1 && D4==1 && D5==0) 
   {
     Serial.println("belok kanan sikit");
     motor1.setSpeed(128);   
     motor2.setSpeed(255);    
   }
         else if (D1==0 && D2==0 && D3==0 && D4==1 && D5==1) 
   {
     Serial.println("belok kanan ");
     motor1.setSpeed(128);   
     motor2.setSpeed(255);    
   }
   else if (D1==0 && D2==0 && D3==0 && D4==0 && D5==1) 
   {
     Serial.println("belok kanan banyak");
     motor1.setSpeed(0);   
     motor2.setSpeed(255);     
   }
   else if (D1==1 && D2==1 && D3==1 && D4==1 && D5==1) 
   {
    //robot berhenti di persimpangan
     motor1.setSpeed(0);   
     motor2.setSpeed(0);     
   }
   else 
   {
    }
}
