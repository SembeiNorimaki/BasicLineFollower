const int PIN_SENSORS[5] = {3, 4, 5, 6, 7};

int sensorValues[5];

void readSensors()
{
    for (int i=0; i<5; i++)
    {
        sensorValues[i] = digitalRead(PIN_SENSORS[i]);
    }
}

void sendSensors()
{
    for (int i=0; i<5; i++)
    {
        Serial.print(sensorValues[i]);
    }
    Serial.println("");
}

void setup()
{
    for (int i=0; i<5; i++)
    {
        pinMode(PIN_SENSORS[i], INPUT);
    }
    Serial.begin(9600);
}

void loop()
{
    readSensors();
    sendSensors();
    delay(500);    
}