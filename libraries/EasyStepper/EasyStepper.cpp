#include "EasyStepper.h"
 
EasyStepper::EasyStepper(byte stepPin, byte directionPin, byte enablePin, bool directionPinsInverted, bool enablePinsInverted)
{
        // save the parameters
        this->stepPin = stepPin;
        this->directionPin = directionPin;
        this->enablePin = enablePin;
        this->directionPinsInverted = directionPinsInverted;
        this->enablePinsInverted = enablePinsInverted;
}
 
void EasyStepper::startup()
{
        // set the pin mode
        pinMode(this->stepPin, OUTPUT);
        pinMode(this->directionPin, OUTPUT);
        pinMode(this->enablePin, OUTPUT);
        // enable the stepper
        digitalWrite(enablePin, HIGH ^ this->enablePinsInverted);
        // initialize the done to true
        this->done = true;
}
 
void EasyStepper::shutdown()
{
        // disable the stepper
        digitalWrite(enablePin, LOW ^ this->enablePinsInverted);
}
 
void EasyStepper::debugMode(boolean enabled)
{
        this->debugModeFlag = enabled;
}
 
void EasyStepper::rotate(float speed, int steps)
{
        this->rotate(speed, steps, 0);
}
 
void EasyStepper::rotate(float speed, int steps, int acceleration)
{
        // ignore the zero value
        if (speed != 0 && steps != 0)
        {
                if (steps > 0)
                {
                        // CW
                        digitalWrite(directionPin, HIGH ^ this->directionPinsInverted);
                }
                else if (steps < 0)
                {
                        // CCW
                        digitalWrite(directionPin, LOW ^ this->directionPinsInverted);
                }
                // done flag
                this->done = false;
                // the steps to go
                this->stepsToGo = abs(steps);
                // the acceleration
                this->acceleration = abs(acceleration);
                if (this->stepsToGo <= 4)
                {
                        this->acceleration = 0;
                }
                // change the speed to stepTime, micro seconds per step
                this->stepTime = 1000.0 * 1000.0 / abs(speed);
                // start time
                this->startTime = this->stepTime * (this->acceleration + 1);
                // stage1
                this->stage1 = this->stepsToGo / 4;
                this->stage1StepTime = (float) this->acceleration * this->stepTime / this->stage1;
                // stage2
                this->stage2 = this->stepsToGo / 4 * 3;
                this->stage3StepTime = (float) this->acceleration * this->stepTime / (this->stepsToGo - this->stage2);
                // the steps gone
                this->stepsGone = 0;
                // current timestamp
                unsigned long time = micros();
                if (this->debugModeFlag)
                {
                        Serial.print("rotate: direction=");
                        Serial.print(steps > 0 ? "CW" : "CCW");
                        Serial.print(", stepsToGo=");
                        Serial.print(this->stepsToGo);
                        Serial.print(", acceleration=");
                        Serial.print(this->acceleration);
                        Serial.print(", startTime=");
                        Serial.print(this->startTime);
                        Serial.print(", stage1=");
                        Serial.print(this->stage1);
                        Serial.print(", stage1StepTime=");
                        Serial.print(this->stage1StepTime);
                        Serial.print(", stage2=");
                        Serial.print(this->stage2);
                        Serial.print(", stage3StepTime=");
                        Serial.print(this->stage3StepTime);
                        Serial.print(", stepTime=");
                        Serial.print(this->stepTime);
                        Serial.print(", currentTimestamp=");
                        Serial.println(time);
                }
                // call the step method to rotate the motor
                this->step();
        }
}
 
void EasyStepper::stop()
{
        this->stepsToGo = 0;
        this->done = true;
}
 
void EasyStepper::run()
{
        // the current timestamp
        unsigned long time = micros();
        if (!this->done && time >= this->nextTimestamp)
        {
                this->step();
        }
        if (this->debugModeFlag)
        {
                Serial.print("currentTimeStamp=");
                Serial.println(time);
        }
}
 
void EasyStepper::step()
{
        // are there some steps to rotate?
        if (this->stepsToGo > this->stepsGone)
        {
                // HIGH value
                digitalWrite(stepPin, HIGH);
                // delay
                delayMicroseconds(2);
                // LOW value
                digitalWrite(stepPin, LOW);
                // increase the stepsGone
                this->stepsGone++;
                // default: stage2
                float nextStepTime = this->stepTime;
                if (this->acceleration != 0)
                {
                        if (this->stepsGone < this->stage1)
                        {
                                // stage1: down to stepTime from startTime
                                nextStepTime = this->startTime - this->stage1StepTime * this->stepsGone;
                        }
                        else if (this->stepsGone >= this->stage2)
                        {
                                // stage3: up to startTime from stepTime
                                nextStepTime = this->stepTime + this->stage3StepTime * (this->stepsGone - this->stage2 + 1);
                        }
                }
                // current timestamp
                unsigned long time = micros();
                this->nextTimestamp = time + nextStepTime;
                if (this->debugModeFlag)
                {
                        Serial.print("step: stepsGone=");
                        Serial.print(this->stepsGone);
                        Serial.print(", currentTimestamp=");
                        Serial.print(time);
                        Serial.print(", nextTimestamp=");
                        Serial.print(this->nextTimestamp);
                        Serial.print(", nextStepTime=");
                        Serial.println(nextStepTime);
                }
        }
        else
        {
                this->done = true;
        }
}
 
boolean EasyStepper::isDone()
{
        return this->done;
}
