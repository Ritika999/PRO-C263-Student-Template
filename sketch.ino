
const byte trig_pin = 12;
const byte echo_pin = 14;

//CODE1:  Declare LED pins array


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig_pin , OUTPUT);
  pinMode(echo_pin , INPUT);
  //CODE2:  declare all led pins as 
  
  //CODE3:  Indicator function to test if all LEDs are working

}

void loop() {
  // put your main code here, to run repeatedly:

int distance = get_distance();
  delay(10); // this speeds up the simulation
}

void indicator_testing(){
  //  turning all leds on
 

  // CODE4:  all leds off
 

  
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
  long int distance = (duration * sound_speed) / 2;

  return distance;

}


void indicator(int distance){


  //CODE5: LEDs on/off according to distance

  


  if(distance <= 150){
    //  calculating buzzer interval, mapping with distance
    buzzer_interval = map(distance , 0 , 150 , 0 , 1000);
    buzzer();
    delay(buzzer_interval);
  }
}


void led_on(byte led_count){
  //  total led which are going to be on
  for (int i = 0; i < led_count; i++){
    digitalWrite(led_pins[i] , HIGH);
  }

  //  total leds which are going to be off
  for (int i = led_count; i < sizeof(led_pins); i++){
    digitalWrite(led_pins[i] , LOW);
  }
}

void buzzer(){
  for (int j = 0; j < 3; j++)
    { 
      digitalWrite(buzzerPin, HIGH);
      delay(2);
      digitalWrite(buzzerPin, LOW);
      delay(2);
    }
}
