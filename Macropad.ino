#include <Keyboard.h>

static const uint8_t input_pins[] = {D6,D7,D8,D9};
static const uint8_t output_pins[] = {D15,D14,D13,D12};

void send_output(int);

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(input_pins[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(output_pins[i], OUTPUT);
  }
  Keyboard.begin();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  for (int y = 0; y < 4; y++) {
    digitalWrite(output_pins[y], LOW);
 
  for (int x = 0; x < 4; x++) { 
      if (digitalRead(input_pins[x]) == LOW) {
        int output = ((y * 4) + x + 1);
        digitalWrite(LED_BUILTIN, LOW);
        send_output(output);
  }
  }
  digitalWrite(output_pins[y], HIGH);
   }

}

void send_output(int input){
  switch(input) {                                                 
  case 1:  // PRESS ESC
   Keyboard.press(KEY_ESC);
   delay(100);
   Keyboard.releaseAll();
   break;
  case 2: // Open a Terminal
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
     delay(500);
   Keyboard.write('t');     
   Keyboard.releaseAll();                                                                                               
  break;
  case 3: // todoist
   run("Todoist"); 
   delay(10);
   break; 
  case 4: // Start Neovim
   run("neovim"); 
   break;
  case 5:  // cd
   Keyboard.print("cd ");
   delay(100);
   break;
  case 6: // cd into the Dev folder
   Keyboard.print("cd $HOME/Dev/");
   break;
  case 7: // cargo build
   Keyboard.print("cargo build "); 
   break;
  case 8: // clear terminal
   Keyboard.print("clear");
   delay(100);
   break;
  case 9: // CTRL + C
   Keyboard.press(KEY_LEFT_CTRL);
   delay(10);
   Keyboard.press('c');
   delay(100);
   Keyboard.releaseAll();
   break;
  case 10: // CTRL + D
  Keyboard.press(KEY_LEFT_CTRL);
   delay(10);
   Keyboard.press('d');
   delay(100);
   Keyboard.releaseAll();
   break;
  case 13: // SHIFT + TAB
   Keyboard.press(KEY_LEFT_SHIFT);
   delay(10);
   Keyboard.press(KEY_TAB);
   delay(100);
   Keyboard.releaseAll();
   break;
  case 14: // TAB 
   delay(10);
   Keyboard.press(KEY_TAB);
   delay(100);
   Keyboard.releaseAll();
   break; 
  case 15: // pleading emoji
    Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
     delay(10);
   Keyboard.press('u');                                                                                               
   Keyboard.releaseAll();
   delay(100);
   Keyboard.print("1f97a\n");
   break;
  case 16: // ENTER
   Keyboard.press(KEY_RETURN);
   delay(100);
   Keyboard.releaseAll();
   break;
  }
  }


void run(const char *program){
   Keyboard.press(KEY_LEFT_ALT);
   delay(500);
   Keyboard.press('d');
   delay(150);
   Keyboard.releaseAll();
   delay(10);
   Keyboard.print(program);
   Keyboard.press(KEY_RETURN);
   delay(100);
   Keyboard.releaseAll();
}
