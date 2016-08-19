const int xpin = A3;
const int ypin = A4;
const int zpin = A5;

const int led_pins[] = {5, 6, 9, 10, 11, 16};
const int pin_count  = 6; // could do sizeof(led_pins)/sizeof(int), but this won't change

const int threshold = 50;

int old_x, old_y, old_z = 0;
int new_x, new_y, new_z = 0;

void setup() {
  for(int i=0; i<pin_count; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  int new_x = analogRead(xpin);
  int new_y = analogRead(ypin);
  int new_z = analogRead(zpin);

  // if there was enough movement
  if(abs(old_x - new_x) >= threshold || 
     abs(old_y - new_y) >= threshold ||
     abs(old_z - new_z) >= threshold){

    // twinkle
    int pin = random(0,pin_count);
    int twinkle_count = random(2,5);
    int brightness = random(5,30);
    for(int i=0; i<twinkle_count; i++) {
     
      analogWrite(led_pins[pin], brightness);
      delay(random(50,100));
      digitalWrite(led_pins[pin], LOW);
      delay(random(50,100));
    }
  }

  old_x = new_x;
  old_y = new_y;
  old_z = new_z;
  
  delay(100);
}
