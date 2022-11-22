 #include <UltraDistSensor.h>
  #define EnableA 5
  #define EnableB 6
  #define motorAIN 7
  #define motorBIN 8
  #define motorSTBY 3
 
  UltraDistSensor mysensor;

const int SW_pin = 11; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
float distance;

void setup() {

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  
  pinMode(motorSTBY, OUTPUT);
  pinMode(EnableA, OUTPUT); //A is for right wheels
  pinMode(EnableB, OUTPUT); //B is for left wheels
  pinMode(motorAIN, OUTPUT);
  pinMode(motorBIN, OUTPUT);
  mysensor.attach(3,5); // trigger and echo pin, add after


}

void loop() {

distance = mysensor.distanceInCm();
delay(60);

if (distance < 15) {
   right ();

   delay(700);

   left ();

   delay(700);

   forward();

   delay(3000);

   left ();

   delay(700);

   right ();

   delay(700);
}

else 

delay(500);

forward ();

}

void forward(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, HIGH);
  analogWrite (EnableA, 80);
  analogWrite (EnableB, 80);
  digitalWrite (motorBIN, HIGH);
}


void right(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, LOW);
  analogWrite (EnableA, 60);
  analogWrite (EnableB, 60);
  digitalWrite (motorBIN, HIGH);
   
}

void left(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, HIGH);
  analogWrite (EnableA, 60);
  analogWrite (EnableB, 60);
  digitalWrite (motorBIN, LOW);
}


void Stop(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, LOW);
  analogWrite (EnableA, 0);
  analogWrite (EnableB, 0);
  digitalWrite (motorBIN, LOW);
   
}

void back(){
  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, LOW);
  analogWrite (EnableA, 70);
  analogWrite (EnableB, 70);
  digitalWrite (motorBIN, LOW);
 
}
