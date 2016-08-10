const int xpin = A3;
const int ypin = A4;
const int zpin = A5;

const int led_pins[] = {5, 6, 9, 10, 11, 16};
const int pin_count  = 6; // could do sizeof(led_pins)/sizeof(int), but this won't change

const int threshold = 50;

int old_x, old_y, old_z = 0;
int new_x, new_y, new_z = 0;

void setup() {
  Serial.begin(9600); // for debugging only

  for(int i=0; i<pin_count; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  int new_x = analogRead(xpin);
  int new_y = analogRead(ypin);
  int new_z = analogRead(zpin);
  
  // -- for debugging only
  Serial.print(new_x);
  Serial.print("\t");
  Serial.print(new_y);
  Serial.print("\t");
  Serial.print(new_z);
  Serial.println();
  // -- for debugging only

  // if there was enough movement
  if(abs(old_x - new_x) >= threshold || 
     abs(old_y - new_y) >= threshold ||
     abs(old_z - new_z) >= threshold){

    // twinkle
    for(int i=0; i<pin_count; i++) {
      digitalWrite(led_pins[i], HIGH);
      delay(random(100,500));
      digitalWrite(led_pins[i], LOW);
    }
  }

  old_x = new_x;
  old_y = new_y;
  old_z = new_z;
  
  delay(100);
}
