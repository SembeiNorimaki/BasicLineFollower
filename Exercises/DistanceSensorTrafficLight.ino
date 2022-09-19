/*
    Exercice:
    Distance Sensor + Traffic Light
*/

// Pin definitions
const int PIN_TF_RED = 3;
const int PIN_TF_YELLOW = 4;
const int PIN_TF_GREEN = 5;

// Color definitions
enum color {RED, YELLOW, RED_YELLOW, GREEN, OFF};


int distanceRed = 5;
int distanceYellow = 10;


void turnLight(color color)
{
    /*
        Turns the Traffic light lights to the desired color
        Colors available:
        RED, YELLOW, RED_YELLOW, GREEN, OFF
    */
    if (color == RED)
    {
        digitalWrite(PIN_TF_RED, HIGH);
        digitalWrite(PIN_TF_YELLOW, LOW);
        digitalWrite(PIN_TF_GREEN, LOW);
    }
    else if (color == YELLOW)
    {
        digitalWrite(PIN_TF_RED, LOW);
        digitalWrite(PIN_TF_YELLOW, HIGH);
        digitalWrite(PIN_TF_GREEN, LOW);
    }
    else if (color == GREEN)
    {
        digitalWrite(PIN_TF_RED, LOW);
        digitalWrite(PIN_TF_YELLOW, LOW);
        digitalWrite(PIN_TF_GREEN, HIGH);
    }
    else if (color == RED_YELLOW)
    {
        digitalWrite(PIN_TF_RED, HIGH);
        digitalWrite(PIN_TF_YELLOW, HIGH);
        digitalWrite(PIN_TF_GREEN, LOW);
    }
    else if (color == OFF)
    {
        digitalWrite(PIN_TF_RED, LOW);
        digitalWrite(PIN_TF_YELLOW, LOW);
        digitalWrite(PIN_TF_GREEN, LOW);
    }    
}

float readDistanceCm()
{
    return (3.5);
}

void setup()
{
    // Define Traffic Light pins as outputs
    pinMode(PIN_TF_RED, OUTPUT);
    pinMode(PIN_TF_YELLOW, OUTPUT);
    pinMode(PIN_TF_GREEN, OUTPUT);
}

void loop()
{
    distance = readDistanceCm();
    if (distance <= distanceRed)
    {
        turnLight(RED);
    }
    else if (distance <= distanceYellow)
    {
        turnLight(YELLOW);
    }
    else
    {
        turnLight(GREEN);
    }
}