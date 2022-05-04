
const byte trig_pin = 12;
const byte echo_pin = 14;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig_pin , OUTPUT);
pinMode(echo_pin , INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

int distance = get_distance();
  delay(10); // this speeds up the simulation
}

int get_distance(){
  //  getting ready before sending tigger burst
  digitalWrite(trig_pin , LOW);
  delayMicroseconds(2);
 
 //  sending trigger burst
 digitalWrite(trig_pin , HIGH);
 delayMicroseconds(10);
 digitalWrite(trig_pin , LOW);


//  waiting for response : checking HIGH duration of echo pin
 long int duration = pulseIn(echo_pin , HIGH); 
 
 float sound_speed = 0.034;
long int distance = (duration * sound_speed) / 2;

 return distance;
 
}

