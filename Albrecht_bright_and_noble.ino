const int bPin = 3;
const int rPin = 5;
const int gPin = 6;

//define the brightness
int rVal;
int gVal;
int bVal;
int rInUse;
int gInUse;
int bInUse;

// Define an array for selection of the 3 colours
int UseTable[7][3] = {{0, 0, 1},
                      {0, 1, 0},
                      {1, 0, 0},
                      {0, 1, 1},
                      {1, 0, 1},
                      {1, 1, 0},
                      {1, 1, 1}
                    };

// create a dice for the table above
int dice1;

int onRand;
int offRand;

void setup() {
  // set random seed using a floating analog pin
  randomSeed(analogRead(A0));

  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  
  //Fade trhough the colors
  for (int i = 0; i < 255; i++) {
    analogWrite(rPin, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(rPin, i);
    delay(5);
  }
  digitalWrite(rPin, 0);
  for (int i = 0; i < 255; i++) {
    analogWrite(gPin, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(gPin, i);
    delay(5);
  }
  digitalWrite(gPin, 0);
  for (int i = 0; i < 255; i++) {
    analogWrite(bPin, i);
    delay(5);
  }
  for (int i = 255; i > 0; i--) {
    analogWrite(bPin, i);
    delay(5);
  }
  digitalWrite(bPin, 0);
  //END Fade trhough the colors
}

void loop() {
  // roll the dice to select to channels
  dice1 = random(0, 7);

  // look up the values
  rInUse = UseTable[dice1][0];
  gInUse = UseTable[dice1][1];
  bInUse = UseTable[dice1][2];

  // get random color values
  rVal = random(0, 150) * rInUse;
  gVal = random(0, 150) * gInUse;
  bVal = random(0, 150) * bInUse;

  onRand = random(500, 2000);
  
  //on
  analogWrite(rPin, rVal);
  analogWrite(gPin, gVal);
  analogWrite(bPin, bVal);
  delay(onRand);
  //off
  digitalWrite(rPin, 0);
  digitalWrite(gPin, 0);
  digitalWrite(bPin, 0);
  

}
