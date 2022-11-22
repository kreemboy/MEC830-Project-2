#define EnableA 5
#define EnableB 6
#define motorAIN 7
#define motorBIN 8
#define motorSTBY 3


void setup() {

  pinMode(motorSTBY, OUTPUT);
  pinMode(EnableA, OUTPUT); //A is for right wheels
  pinMode(EnableB, OUTPUT); //B is for left wheels
  pinMode(motorAIN, OUTPUT);
  pinMode(motorBIN, OUTPUT);

  Serial.begin(9600);
  delay(1000);

}

void loop() {


}


void forward(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, HIGH);
  analogWrite (EnableA, 50);
  analogWrite (EnableB, 50);
  digitalWrite (motorBIN, HIGH);
}


void right(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, LOW);
  analogWrite (EnableA, 40);
  analogWrite (EnableB, 40);
  digitalWrite (motorBIN, HIGH);
   
}

void left(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, HIGH);
  analogWrite (EnableA, 40);
  analogWrite (EnableB, 40);
  digitalWrite (motorBIN, LOW);
}


void stop(){

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