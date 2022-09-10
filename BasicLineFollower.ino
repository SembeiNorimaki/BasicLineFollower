//#include "Ardumoto.h"
#include <Streaming.h>

// DON'T CHANGE
const int BLACK = 0;
const int WHITE = 1;
const int CENTER = 0;
const int LEFT = -1;
const int RIGHT = 1;
const int BACKWARD = 0;
const int FORWARD = 1;


const int NUM_SENSORS = 7;
const int PREFERENCE_LEFT[NUM_SENSORS] = {0, 1, 2, 3, 4, 5, 6};
const int PREFERENCE_RIGHT[NUM_SENSORS] = {6, 5, 4, 3, 2, 1, 0};
const int PREFERENCE_CENTER[NUM_SENSORS] = {3, 2, 4, 1, 5, 0, 6};
 
// BLACK line over white background or WHITE line over black background
const int LINE_COLOR = BLACK;

// From left to right 
const int SENSOR_PINS[NUM_SENSORS] = {6, 7, 8, 9, 10, 11, 12};
const int MOTOR_LEFT_DIRECTION_PIN = 4;
const int MOTOR_LEFT_SPEED_PIN = 4;
const int MOTOR_RIGHT_DIRECTION_PIN = 4;
const int MOTOR_RIGHT_SPEED_PIN = 4;

// Sensor                          LOST   L3   L2   L1  CEN   R1   R2   R3  LOST
// Indexes                            0    1    2    3    4    5    6    7     8
int LEFT_SPEEDS[NUM_SENSORS+2]  = {-100,   0,  50,  80, 100, 100, 100, 100,  100};
int RIGHT_SPEEDS[NUM_SENSORS+2] = { 100, 100, 100, 100, 100,  80,  50,   0, -100};


uint8_t CurrentReadings;
uint8_t PreviousReadings;
int LastDetection = CENTER;

bool DEBUG = true;
int Preference;

//Ardumoto Motors;

void SetMotorSpeed(int idx)
{
    //Motors.setSpeed('A', LEFT_SPEEDS[idx]);
    //Motors.setSpeed('B', RIGHT_SPEEDS[idx]);

    if (LEFT_SPEEDS[idx] < 0) 
        digitalWrite(MOTOR_LEFT_DIRECTION_PIN, BACKWARD); 
    else
        digitalWrite(MOTOR_LEFT_DIRECTION_PIN, FORWARD);

    if (RIGHT_SPEEDS[idx] < 0) 
        digitalWrite(MOTOR_RIGHT_DIRECTION_PIN, BACKWARD);
    else
        digitalWrite(MOTOR_RIGHT_DIRECTION_PIN, FORWARD);

    analogWrite(MOTOR_LEFT_SPEED_PIN, abs(LEFT_SPEEDS[idx]));
    analogWrite(MOTOR_RIGHT_SPEED_PIN, abs(RIGHT_SPEEDS[idx]));
}

void ReadSensors()
{
    PreviousReadings = CurrentReadings;
    CurrentReadings = 0;
    for (int i=0; i<NUM_SENSORS; i++)
        bitWrite(CurrentReadings, i, digitalRead(SENSOR_PINS[i]) == LINE_COLOR);
}

void SendSensorReadings()
{
    for(int i=0; i<NUM_SENSORS; i++)
    {
       Serial << bitRead(CurrentReadings, i) << " ";
    }
    Serial << endl;
}


void SetupMode()
{
    Serial << "You are in setup mode" << endl;
    Serial << "Enter the following speeds separated by comma" << endl;
    Serial << "Lost, Sensor3, Sensor2, Sensor1, Center" << endl;
    Serial << "Current Configuration:" << endl;
    Serial << LEFT_SPEEDS[0] << LEFT_SPEEDS[1] << LEFT_SPEEDS[2] << \
              LEFT_SPEEDS[3] << LEFT_SPEEDS[4] << endl;
    Serial << endl << ">> ";
}

void setup()
{
    for (int i=0; i<NUM_SENSORS; i++)
        pinMode(SENSOR_PINS[i], INPUT);
    
    //Motors.begin();
    Serial.begin(115200);

    ReadSensors();
    if (CurrentReadings & 0b01001001 == 0b01001001)
        SetupMode(); 
    else if (CurrentReadings & 0b00000111) 
        Preference = (int)PREFERENCE_LEFT;
    else if (CurrentReadings & 0b01110000)
        Preference = (int)PREFERENCE_RIGHT;
}

void loop()
{
    ReadSensors();
    if (DEBUG && CurrentReadings != PreviousReadings)
        SendSensorReadings();
    
    int idx;
    for (int i=0; i<NUM_SENSORS; i++) 
    {
        if (Preference == LEFT)
            idx = PREFERENCE_LEFT[i];
        else if (Preference == RIGHT)
            idx = PREFERENCE_RIGHT[i];
        else
            idx = PREFERENCE_CENTER[i];

        if (bitRead(CurrentReadings, idx))
        {
            if (idx < 4)
                LastDetection = LEFT;
            else if (idx > 4)
                LastDetection = RIGHT;
            else
                LastDetection = CENTER;
            
            SetMotorSpeed(idx);
            return;
        }
    }

    // we haven't detected a line
    if (LastDetection == RIGHT) 
    {
        SetMotorSpeed(NUM_SENSORS-1);
    }
    else
    {
        SetMotorSpeed(0);
    }
}

void serialEvent() 
{
    while (Serial.available()) 
    {
        String rx = Serial.readString();
        rx.trim();
        //int a = rx.parseInt();
    }
}
