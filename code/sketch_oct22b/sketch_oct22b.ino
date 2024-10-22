cpp
Copy code
// Define pin numbers for analog inputs and motor outputs
const int input1Pin = A0; // Forward/Backward input
const int input2Pin = A1; // Left/Right input
const int motor1Pin = 9;  // Motor 1 output
const int motor2Pin = 10; // Motor 2 output
const int motor3Pin = 11; // Motor 3 output

// Variables to store input values
int forwardBackward = 0;
int leftRight = 0;

// Variables to store motor speeds
int motor1Speed = 0;
int motor2Speed = 0;
int motor3Speed = 0;

void setup() {
  // Set motor pins as output
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(motor3Pin, OUTPUT);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read analog inputs
  forwardBackward = analogRead(input1Pin); // Value between 0 and 1023
  leftRight = analogRead(input2Pin);       // Value between 0 and 1023

  // Map analog inputs to motor speeds (range -255 to 255 for motor PWM control)
  forwardBackward = map(forwardBackward, 0, 1023, -255, 255);
  leftRight = map(leftRight, 0, 1023, -255, 255);

  // Calculate motor speeds based on forward/backward and left/right inputs
  motor1Speed = forwardBackward;                // Motor 1 controls forward/backward
  motor2Speed = leftRight - forwardBackward;    // Motor 2 controls left/right and forward/backward combination
  motor3Speed = -(leftRight + forwardBackward); // Motor 3 controls left/right and forward/backward combination

  // Ensure motor speeds are within the valid range
  motor1Speed = constrain(motor1Speed, -255, 255);
  motor2Speed = constrain(motor2Speed, -255, 255);
  motor3Speed = constrain(motor3Speed, -255, 255);

  // Output motor speeds
  analogWrite(motor1Pin, abs(motor1Speed)); // Use abs() to ensure positive PWM values
  analogWrite(motor2Pin, abs(motor2Speed));
  analogWrite(motor3Pin, abs(motor3Speed));

  // Optionally reverse motors if negative speed
  if (motor1Speed < 0) {
    // Add logic for reversing motor direction if necessary
  }
  if (motor2Speed < 0) {
    // Add logic for reversing motor direction if necessary
  }
  if (motor3Speed < 0) {
    // Add logic for reversing motor direction if necessary
  }

  // Debugging output to Serial Monitor
  Serial.print("Input 1 (Forward/Backward): ");
  Serial.print(forwardBackward);
  Serial.print("\tInput 2 (Left/Right): ");
  Serial.print(leftRight);
  Serial.print("\tMotor 1: ");
  Serial.print(motor1Speed);
  Serial.print("\tMotor 2: ");
  Serial.print(motor2Speed);
  Serial.print("\tMotor 3: ");
  Serial.println(motor3Speed);

  delay(100); // Small delay to stabilize readings
}