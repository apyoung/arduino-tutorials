/*
 * Tutorial 1: Reading Temperature
 * 
 * Read the temperature in celcius over serial.
 *
 * To see this sketch in action open up the serial
 * monitor. Clamp your fingers over the LM35
 * sensor. The temperature will rise and then fall
 * as you remove your fingers.
 *
 * The circuit:
 * - LM35 to 5v, GND, and Vo to analog 0
 */

// the output pin of the LM35 temperature sensor
int lm35Pin = A0;

void setup()
{
    // set up serial at 9600 baud   
    Serial.begin(9600);
}

void loop()
{ 
    int analogValue;
    float temperatureInCelsius;
    float temperatureInFahrenheit;

    // read our temperature sensor
    analogValue = analogRead(lm35Pin);

    // convert the 10bit analog value to celcius
    temperatureInCelsius = float(analogValue) / 1023;
    temperatureInCelsius = temperatureInCelsius * 500;

    // convert Celsius temperature to Fahrenheit
    temperatureInFahrenheit = (temperatureInCelsius * 9 / 5) + 32;

    // print the temperatures over serial
    Serial.print("Temperature: ");
    Serial.print(temperatureInCelsius);
    Serial.print("C ");
    Serial.print(temperatureInFahrenheit);
    Serial.println("F");
    
    // wait before reading the temperature again
    // 1000 milliseconds = 1 second
    delay(1000);
}
