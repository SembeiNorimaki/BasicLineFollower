const int POT_PIN = 3;
const int MOTOR_SPEED_PIN = 4;


int ReadPotentiometer()
{
    return analogRead(POT_PIN);
}

void SetMotorSpeed(int speed)
{
    analogWrite(MOTOR_SPEED_PIN, speed);
}

void setup()
{
    
}

void loop()
{
    int potValue = analogRead(POT_PIN);
    potValue = map(potValue, 0, 1023, 0, 255);
    SetMotorSpeed(potValue);
    delay(100);
}
