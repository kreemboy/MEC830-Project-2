
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
  delay(1500);

}

void loop() {

//116cm for 3000ms of forward movement

  forward();
  delay(3569);
  Stop();
  delay(500);

  right();
  delay(840);
  Stop();
  delay(500);

  forward();
  delay(3569);
  Stop();
  delay(500);

  right();
  delay(840);
  Stop();
  delay(500);

  delay(3000);

  forward();
  delay(3569);
  Stop();
  delay(500);

  right();
  delay(840);
  Stop();
  delay(500);

  
  forward();
  delay(3569);
  Stop();
  delay(500);

  right();
  delay(840);
  Stop();
  delay(500);
  

/*  right();
  delay(840);

  Stop();
  delay(500);

  left();
  delay(800);
  //note that left turn overshoots and needs a shorter delay 
  
  Stop();
  delay(500);
*/

}

void forward(){

  digitalWrite (motorSTBY, HIGH);
  digitalWrite (motorAIN, HIGH);
  analogWrite (EnableA, 100);
  analogWrite (EnableB, 100);
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
