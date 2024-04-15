#include <Adafruit_SSD1306.h>

// Parameter definition
/////////////////////////////////////////////////////////////////////////
#define encoderPinA 2 // CLK Output A
#define encoderPinB 4 // DT Output B
#define Switch 5 // Switch connection
#define nombreDePixelsEnLargeur 128 // Parameters for the OLED screen
#define nombreDePixelsEnHauteur 64
#define brocheResetOLED -1
#define adresseI2CecranOLED 0x3C

volatile unsigned int encoderValue = 0;
long lastEncoderValue = 0;

long lastDebounceTime = 0;
long debounceDelay = 120;
bool button_pressed = false; 


Adafruit_SSD1306 ecranOLED(nombreDePixelsEnLargeur, nombreDePixelsEnHauteur, &Wire, brocheResetOLED);

String menuItems[] = {"Potentiometer", "Flex Sensor", "Graphite Sensor"}; // Definition of menu items
int selectedItem = 0; // Menu items are defined from 0 to 2
/////////////////////////////////////////////////////////////////////////

void setup() {
  pinMode(encoderPinA, INPUT); // Use internal pull-up resistors for the encoder
  digitalWrite(encoderPinA, HIGH); // Turn on pullup resistor
  pinMode(encoderPinB, INPUT);
  digitalWrite(encoderPinB, HIGH); // Turn on pullup resistor

  attachInterrupt(0, updateEncoder, RISING); // Whenever the encoderPinB changes state, an interruption occurs.
  //attachInterrupt(digitalPinToInterrupt(Switch), switchButton, RISING); // Whenever the switch button is pressed, an interruption is raised
  if (!ecranOLED.begin(SSD1306_SWITCHCAPVCC, adresseI2CecranOLED))
    while (1); // Program stops (infinite loop) if something goes wrong here
  ecranOLED.clearDisplay();
  ecranOLED.setTextColor(SSD1306_WHITE);
  Serial.begin(9600);
}

void loop() {
  displayMenu();
  //handleMenuItemSelection(selectedItem);
  encoderValue = abs(encoderValue % 3); 
  Serial.println(encoderValue); // To debug
  if (encoderValue != lastEncoderValue) { // If we turn the encoder, then the selectedItem variable is increased
    selectedItem++;
    if (selectedItem == 3) {
      selectedItem = 0; // If we reach the last element from the menu, the selectedItem is reset to the first element
    }
  } 
  lastEncoderValue = encoderValue; // The last value from the encoder is updated
  Serial.println("Selected:" + String(selectedItem)); // To debug
  delay(150); // We add a delay between loops for stability, while still having a responsive display
}

void displayMenu() {
  ecranOLED.clearDisplay();
  for (int i = 0; i < sizeof(menuItems) / sizeof(menuItems[0]); i++) {
    if (i == selectedItem) {
      ecranOLED.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Highlight selected item
    } else {
      ecranOLED.setTextColor(SSD1306_WHITE); // Regular color for other items
    }
    ecranOLED.setCursor(0, i * 10); // Adjust position for each item
    ecranOLED.print(menuItems[i]); // Print each element
  }
  ecranOLED.display();
}


void handleMenuItemSelection(int selectedItem) {
  // Implement actions for each menu item
  switch (selectedItem) {
    case 1:
      if (button_pressed) { // For each case, if the switch button was pressed, we enter each menu respectively
      
      }
    case 2:
      if (button_pressed) {
        
      }
    case 3:
      if (button_pressed) {
        
      }
    default:
      break;
  }
}

void updateEncoder() {
  if (digitalRead(encoderPinB) == HIGH) {
    encoderValue++;
  }
  else {
    encoderValue--;
  }
}

void switchButton() {
  // Debouncing logic for the switch button
  long currentTime = millis();
  lastDebounceTime = currentTime;
  while (currentTime - lastDebounceTime < debounceDelay) {
    currentTime = millis(); // The function waits for the debounce delay to pass, and then we read the value of the switch again
  }
  if (Switch == HIGH) { // If, after the debounce delay, the Switch is still high, we have effectively pressed the button
    button_pressed = true; // We choose the selected option
  }
}

