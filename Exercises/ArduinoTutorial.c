Declare a variable

int integerValue;


Loops

For loops:

    for (int i=0; i<5; i=i+1)
    {
        // some code
    }

    // int i = 0   Declare an integer i and assign a value of 0
    // i < 5       Repeat while i < 5
    // i = i + 1   At each iteration increase i by i. Also writen as i++

While loops:

    int i = 0;
    while (i < 5)
    {
        // some code

        i = i + 1;
    }

Conditionals:

    if (i == 3)
    {
        // code to execute if i is 3
    }
    else if (i == 2)
    {
        // code to execute if i is 2
    }
    else
    {
        // code to execute in any other case
    }

Read a digital pin:

    value = digitalRead(pinNumber);
    
Write a digital value:

    digitalWrite(pinNumber, value);
    
Write an analog value:

    analogWrite(pinNumber, value);

Read an analog value:
    
    value = analogRead(pinNumber);

Initialize a Serial connection

    Serial.begin(baudRate);
    
Send a value via Serial port

    Serial.print(value);    // send only the value
    Serial.println(value);  // send the value and a newLine
    
Arithmetic Operators

    +   Addition
    -   Substraction
    *   Multipliction
    /   Division
    %   Modulo (remainder)
    =   Assignment
    ++  Increment
    --  Decrement

Comparison Operators
    
    ==  Equal to
    !=  Not equal to
    <   Lower than
    <=  Lower or equal than
    >   Greater than
    >=  Greater or equal than
    
Boolean Operators:

    !   Logical not
    &&  Logical and
    ||  Logical or