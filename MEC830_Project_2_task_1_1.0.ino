#define EnableA 5
  #define EnableB 6
  #define motorAIN 7
  #define motorBIN 8
  #define motorSTBY 3



const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output


void setup() {

  pinMode(X_pin, INPUT);
  pinMode(Y_pin, INPUT); //joystick stuff
   
  pinMode(motorSTBY, OUTPUT);
  pinMode(EnableA, OUTPUT); //A is for right wheels
  pinMode(EnableB, OUTPUT); //B is for left wheels
  pinMode(motorAIN, OUTPUT);
  pinMode(motorBIN, OUTPUT);

 
  Serial.begin(9600);
  delay(1000);

}

void loop() {

if(analogRead(X_pin)>600){
    right();
  }
  
  if(analogRead(X_pin)<450){
    left();
  }
  
  if(analogRead(Y_pin)>600){
   back();
  }  
    
  if(analogRead(Y_pin)<450){
   forward();
  }

Serial.println(X_pin);
Serial.println(Y_pin);

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
