/*
Useful functions for using motor enconders. Input in centimeters is APPROXIMATE!
*/
const int rotation = 1440;
const float wheelCircumference = 31.902;

//Converts cenimeters to encoder units
int centimetersToUnits(int centimeters)
{
	float rotationPerCm = rotation / wheelCircumference;
	return rotationPerCm * centimeters;
}

//Converts encoder units to cenimeters
int unitsToCentimeters(long units)
{
	float cmPerRotation = wheelCircumference / rotation;	// .02 "cm per units"
	return cmPerRotation * units;
}

//Runs 1 motor for a certain number of encoder units at a certin power
void runMotor(tMotor chosenMotor, int power, int units)
{
	nMotorEncoder[chosenMotor] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[chosenMotor] = power;
	while(abs(nMotorEncoder[chosenMotor]) < units)
	{
	}
	motor[chosenMotor] = 0;
	nMotorEncoder[chosenMotor] = 0;
	wait1Msec(100);
}

//Runs 1 motor for a certain distance in CM at a certin power
void runMotorByCm(tMotor chosenMotor, int power, int cm)
{
	runMotor(chosenMotor, power, centimetersToUnits(cm));
}

//Runs 2 motors for a certain number of encoder units at a certin power
void runTwoMotors(tMotor motor1, tMotor motor2, int power, int units)
{
	nMotorEncoder[motor1] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power;
	motor[motor2] = power;
	while(abs(nMotorEncoder[motor1]) < units)
	{

	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	nMotorEncoder[motor1] = 0;
	wait1Msec(100);
}

//Runs 2 motors for a certain distance in CM at a certin power
void runTwoMotorsByCm(tMotor motor1, tMotor motor2, int power, int cm)
{
	runTwoMotors(motor1, motor2, power, centimetersToUnits(cm));	
}

//Runs 4 motors for certain number of encoder units at a certin power
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotors(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int units)
{
	nMotorEncoder[motor1] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power;
	motor[motor2] = power;
	motor[motor3] = power;
	motor[motor4] = power;
	while(abs(nMotorEncoder[motor1]) < units)
	{


	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor4] = 0;
	nMotorEncoder[motor1] = 0;
	wait1Msec(100);
}



//Runs 4 motors for a certain distance in CM at a certin power
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsByCm(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int cm)
{
	runFourMotors(motor1, motor2, motor3, motor4, power, centimetersToUnits(cm));
}

//Runs 4 motors for a certain number of encoder units at two diffrent powers
//power1 is applied to motors 1 and 3. power2 is applied to motors 2 and 4.
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsWithDifferentPower(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power1, int power2, int units)
{
	nMotorEncoder[motor1] = 0;
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power1;
	motor[motor2] = power2;
	motor[motor3] = power1;
	motor[motor4] = power2;
	while(abs(nMotorEncoder[motor1]) < units)
	{


	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor4] = 0;
	nMotorEncoder[motor1] = 0;
	wait1Msec(100);
}

//Runs 4 motors for a certain distance in CM at two diffrent powers
//power1 is applied to motors 1 and 3. power2 is applied to motors 2 and 4.
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsWithDifferentPowerByCM(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power1, int power2, int cm)
{
	runFourMotorsWithDifferentPower(motor1, motor2, motor3, motor4, power1, power2, centimetersToUnits(cm));
}

//Runs 4 motors for a certain number of encoder units at a certain powers
//The encoders are not rest afterwards
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsNoReset(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int units)
{
	int startVal = nMotorEncoder[motor1];
	if(units < 0)
	{
		units = -units;
	}
	motor[motor1] = power;
	motor[motor2] = power;
	motor[motor3] = power;
	motor[motor4] = power;
	while(abs(nMotorEncoder[motor1] - startVal) < units)
	{


	}
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor4] = 0;
	wait1Msec(100);
}

//Runs 4 motors for a certain distance in CM at a certain powers
//The encoders are not rest afterwards
//Only motors 1 and 2 have encoders but it drives them all
void runFourMotorsByCmNoReset(tMotor motor1, tMotor motor2, tMotor motor3, tMotor motor4, int power, int cm)
{
	runFourMotorsNoReset(motor1, motor2, motor3, motor4, power, centimetersToUnits(cm));
}
