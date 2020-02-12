
#include <Servo.h>   //servo library
Servo servo;     
int trigPin = 2;    
int echoPin = 3;   
int servoPin = 9;

long duration, dist, average;   
long aver[3]; 


void setup() {       
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close dustbin cap on power on
    delay(1000);
    servo.detach();
} 

void measure() {  
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=2;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(50);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    //average distance by 3 measurements

if ( dist<40 ) {
 //if hand on the distance 10...50 cm
 servo.attach(servoPin);
  delay(1);
 servo.write(90);  
 delay(5000);       //wait 5 seconds
 servo.write(0);    
 delay(1000);
 servo.detach();      
}
}



/*******************************************************
*   Content by TECHH-ENGINE
*   

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    FOLLOW US ON INSTAGRAM www.instagram.com/techhengine 
*    
*    email us for queries at techh.engine@gmail.com

********************************************************/
