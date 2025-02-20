//Code to control and RGB Led via arduino from a breadboard


//pin 7 for red, pin 6 for green, pin 5 for blue RGB LED
//red button = pin 4, green button = pin 3, blue button = pin 2


//!! For some reason this was just not working, we tried digitalWrite with highs and lows, then i switched to analogWrite logic and it is not displaying any colors at all

//Initially I was able to have red color work, but it would only display the red. Then randomly it decided to output a spectrum of colors vs 1, then now it is just not showing any colors 


//declaring the variables for the button and pin color controlling
const int redButton = 4, greenButton = 3, blueButton = 2;
const int redPin = 7, greenPin = 6, bluePin = 5;

void setup() {
  pinMode(redButton, INPUT_PULLUP);
  pinMode(greenButton, INPUT_PULLUP);
  pinMode(blueButton, INPUT_PULLUP);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int red = 0, green = 0, blue = 0; // Setting the colors to be off

  // Check which buttons are pressed and set colors accordingly
  if (digitalRead(redButton) == LOW) {
    red = 255;  // This is when the red button is pressed 
  }
  
  if (digitalRead(greenButton) == LOW) {
    green = 255; // This is when the Green button is pressed
  }

  if (digitalRead(blueButton) == LOW) {
    blue = 255;  // This is when the Blue button is pressed
  }

  // Calling the color mix function i created 
  colorMix(red, green, blue);
}

// Function to handle color mixing and set the LED color
void colorMix(int red, int green, int blue) {
  // Handle the basic color mixing 
  if (red == 255 && green == 255 && blue == 0) {
    // Color combo Red + Green = Yellow
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  else if (green == 255 && blue == 255 && red == 0) {
    // Color combo  Green + Blue = Cyan
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  else if (red == 255 && blue == 255 && green == 0) {
    // Color combo for Red + Blue = Magenta
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else if (red == 255 && green == 255 && blue == 255) {
    // Color combo  Red + Green + Blue = White
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  else {
    //set back to the default colors 
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
  }
}






