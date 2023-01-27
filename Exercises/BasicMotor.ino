// define pins
const int PIN_LEFT_MOTOR_DIR = 13;
const int PIN_LEFT_MOTOR_VEL = 11;
const int PIN_RIGHT_MOTOR_DIR = 12;
const int PIN_RIGHT_MOTOR_VEL = 3;

const int FORWARD = 1;
const int BACKWARD = 0;


void move_right_motor(int direction, int speed) {
    digitalWrite(PIN_RIGHT_MOTOR_DIR, direction);  
    analogWrite(PIN_RIGHT_MOTOR_VEL, speed); 
}

void move_left_motor(int direction, int speed) {
    digitalWrite(PIN_LEFT_MOTOR_DIR, direction);  
    analogWrite(PIN_LEFT_MOTOR_VEL, speed); 
}

void setup() {
    // set motor pins as outputs
    pinMode(PIN_LEFT_MOTOR_DIR, OUTPUT);
    pinMode(PIN_RIGHT_MOTOR_DIR, OUTPUT);
    
    // set initial speed to 0 and initial direction to forward
    // for both motors
    digitalWrite(PIN_LEFT_MOTOR_DIR, FORWARD);
    digitalWrite(PIN_RIGHT_MOTOR_DIR, FORWARD);  
    analogWrite(PIN_LEFT_MOTOR_VEL, 0);
    analogWrite(PIN_RIGHT_MOTOR_VEL, 0);       

    delay(5000);
}

void move_in_circles() {
    move_right_motor(FORWARD, 0);
    move_left_motor(FORWARD, 100);
    delay(5000);
    move_right_motor(FORWARD, 100);
    move_left_motor(FORWARD, 0);
    delay(5000);
}


void loop() {
    move_in_circles();  
}

/*
void loop2() {
    move_right_motor(FORWARD, 100);
    move_left_motor(FORWARD, 100);
    delay(3000);
    
    move_right_motor(FORWARD, 0);
    move_left_motor(FORWARD, 0);
    delay(500);
    
    move_right_motor(BACKWARD, 100);
    move_left_motor(BACKWARD, 100);
    delay(3000);
    
    move_right_motor(BACKWARD, 0);
    move_left_motor(BACKWARD, 0);
    delay(500);  
}

void loop() {

    digitalWrite(PIN_LEFT_MOTOR_DIR, FORWARD);
    digitalWrite(PIN_RIGHT_MOTOR_DIR, FORWARD);  
    analogWrite(PIN_LEFT_MOTOR_VEL, 100);
    analogWrite(PIN_RIGHT_MOTOR_VEL, 100);
    delay(3000);
    
    analogWrite(PIN_LEFT_MOTOR_VEL, 0);
    analogWrite(PIN_RIGHT_MOTOR_VEL, 0);
    delay(500);
    
    
    digitalWrite(PIN_LEFT_MOTOR_DIR, BACKWARD);
    digitalWrite(PIN_RIGHT_MOTOR_DIR, BACKWARD);  
    analogWrite(PIN_LEFT_MOTOR_VEL, 200);
    analogWrite(PIN_RIGHT_MOTOR_VEL, 200);
    delay(3000);  

    analogWrite(PIN_LEFT_MOTOR_VEL, 0);
    analogWrite(PIN_RIGHT_MOTOR_VEL, 0);
    delay(500);    
}
*/
