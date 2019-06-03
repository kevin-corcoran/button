class Button {
public:
  /* Constructor - sets button pin number, default values for private class variables (is_pressed_) */
  Button(int button_pin) {
    is_pressed_ = false;
    button_pin_ = button_pin;
  }

  // add setup and loop
  void setup() {
    Serial.begin(9600);
    pinMode(button_pin_, INPUT);
  }

  void loop() {
    int input_val = digitalRead(button_pin_);
    if (input_val == 1) { // if button is pressed
      is_pressed_ = true; // change the state of this button
    } else {
      is_pressed_ = false;
    }
  }

  /* Getter for private variable is_pressed_ */
  bool isPressed() {
    return is_pressed_;
  }

private:
  bool is_pressed_; // state of this button
  int button_pin_; // pin button is attached to
};

/* initialize a Button object with pin number 2 */
Button button(2); // calls the constructor and assigns button_pin_ to 2

// set up led just like before
int led = 13;
int led_state = LOW;

void changeLedState() {
    if(led_state == LOW) {
      led_state = HIGH;
    } else if(led_state = HIGH) {
      led_state = LOW;
    }
    delay(500);
}

/* every arduino sketch needs a setup and loop */
void setup() {
  button.setup(); // opens serial port and sets pinMode of button_pin_ to INPUT
  pinMode(led, OUTPUT);
}

void loop() {
  button.loop();

  if (button.isPressed()) {
    changeLedState();
  }
  digitalWrite(led, led_state);
}


// int led = 13;
// int button = 2;
// int input_val;
// int led_state = LOW;
//
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(led, OUTPUT);
//   pinMode(button, INPUT);
// }
//
// void loop() {
//   // put your main code here, to run repeatedly:
//   input_val = digitalRead(button);   // read the input pin
//   Serial.print(input_val);
//   if(input_val == 1) { // when button is pressed
//     changeLedState();
//   }
//   digitalWrite(led, led_state);
// }
//
// void changeLedState() {
//     if(led_state == LOW) {
//       led_state = HIGH;
//     } else if(led_state = HIGH) {
//       led_state = LOW;
//     }
//     delay(500);
// }

// int led = 13;
// int button = 2;
// int input_val;
// int led_state = LOW;
//
// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(led, OUTPUT);
//   pinMode(button, INPUT);
// }
//
// void loop() {
//   // put your main code here, to run repeatedly:
//   input_val = digitalRead(button);   // read the input pin
//   Serial.print(input_val);
//   if(input_val == 1) { // when button is pressed
//     if(led_state == LOW) {
//       led_state = HIGH;
//     } else if(led_state = HIGH) {
//       led_state = LOW;
//     }
//     delay(500);
//   }
//   digitalWrite(led, led_state);
// }
