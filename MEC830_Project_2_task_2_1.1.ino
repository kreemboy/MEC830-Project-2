#define EnableA 5
#define EnableB 6
#define motorAIN 7
#define motorBIN 8
#define motorSTBY 3

#define TrackL A2
#define TrackM A1
#define TrackR A0

void setup() {

  pinMode(motorSTBY, OUTPUT);
  pinMode(EnableA, OUTPUT); //A is for right wheels
  pinMode(EnableB, OUTPUT); //B is for left wheels
  pinMode(motorAIN, OUTPUT);
  pinMode(motorBIN, OUTPUT);

  pinMode(TrackL, INPUT);
  pinMode(TrackM, INPUT);
  pinMode(TrackR, INPUT);

  Serial.begin(9600);
  delay(1000);

}

void loop() {

  int TrackLValue = analogRead(TrackL);
  int TrackMValue = analogRead(TrackM);
  int TrackRValue = analogRead(TrackR);

  Serial.print("L sensor: ");
  Serial.println(TrackLValue);

  Serial.print("M sensor: ");
  Serial.println(TrackMValue);

  Serial.print("R sensor: ");
  Serial.println(TrackRValue);

    if(TrackLValue<100 && TrackMValue>100 && TrackMValue<970 && TrackRValue<100){
    //this is if only M sensor is on the black line -> MOVE FORWARD
      forward();
  }

  else if(TrackLValue<100 && TrackMValue<100 && TrackRValue>100 && TrackRValue<970 ){
    //this is if only R sensor is on the black line -> TURN RIGHT
      right();
  }

  else if(TrackLValue>100 && TrackRValue<970 && TrackMValue<100 && TrackRValue<100){
    //this is if only L sensor is on the black line -> TURN LEFT
      left();
  }


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