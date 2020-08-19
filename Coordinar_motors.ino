
#include <Stepper.h>

#define motor1StepPin 6
#define motor1DirPin 7
#define motor2StepPin 8
#define motor2DirPin 9

#define stepsPerRevolution 6400

const float PaperWidth = 0.0001;
const float InitialHeight = 0.041; //(r)
const float ReelHeight = 0.03;
int stepsDone = 0;


Stepper motor1(stepsPerRevolution, motor1StepPin, motor1DirPin);
Stepper motor2(stepsPerRevolution, motor2StepPin, motor2DirPin);

void setup() {
  // set the speed:
  motor1.setSpeed(60);
  motor2.setSpeed(60);
  
  // initialize the serial port:
  Serial.begin(9600);
  //moveSteppers(3200);  
}

void moveSteppers(int steps){
  for (int i = 0; i < steps; i++){
      motor1.step(1);
      motor2.step(1);
  }
}

void rotateCoordinated(int steps){
    for (int i = 0; i < steps; i += 15){
      int a = 15*((InitialHeight + ReelHeight - PaperWidth*(stepsDone/(6400*4)))/(InitialHeight + PaperWidth*(stepsDone/(6400*4))));
      motor1.step(10);
      motor2.step(a);
      stepsDone += 15;
   /* Serial.print("stepsDone: ");
      Serial.print(stepsDone);
      Serial.print(", 0: ");
      Serial.print(a);
      Serial.print(", i: ");
      Serial.print(i);
      Serial.println();*/
  }
}


void loop() {
  rotateCoordinated(5000);
}
