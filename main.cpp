#include <wiringPi.h>
#include <iostream>
#include <iomanip>
#include <unistd.h>

#define TRIGGER_PIN 4    // GPIO 4
#define ECHO_PIN    17   // GPIO 17
#define TIMEOUT     25000 // Maximum time to wait for echo (in microseconds)

double measureDistance() {
    // Send trigger pulse
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    // Wait for echo start
    while (digitalRead(ECHO_PIN) == LOW);
    long startTime = micros();
    
    // Wait for echo end
    while (digitalRead(ECHO_PIN) == HIGH && micros() - startTime < TIMEOUT);
    long endTime = micros();
    
    // Calculate distance
    double duration = (endTime - startTime);
    double distance = (duration * 0.0343) / 2; // Speed of sound = 343 m/s
    
    return distance;
}

int main() {
    // Initialize WiringPi
    if (wiringPiSetupGpio() == -1) {
        std::cerr << "Failed to initialize WiringPi" << std::endl;
        return 1;
    }
    
    // Setup pins
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    
    while (true) {
        double distance = measureDistance();
        std::cout << std::fixed << std::setprecision(1) 
                  << distance << " cm" << std::endl;
        sleep(1);
    }
    
    return 0;
}
