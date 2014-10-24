const int rotation = 1440;
const float wheelCircumference = 31.902;

//Converts the Cenimerters we put in, to encoder units
int centimetersToUnits(int centimeters)
{
	float rotationPerCm = rotation/wheelCircumference;
	return rotationPerCm*centimeters;
}
//Converts Encoder units to CM
int unitsToCentimeters(long units)
{
	float cmPerRotation = wheelCircumference/rotation;	// .02 "cm per units"
	return cmPerRotation * units;
}
//Runs 1 motor for certain encoder units at a certin speed
void runMotorWithEncoder(tMotor chosenMotor,int power,int units)
{
	nMotorEncoder[chosenMotor] = 0;
	if(units<0)
	{
		units=(-units);
	}
	motor[chosenMotor]=power;
	while(abs(nMotorEncoder[chosenMotor])<units)
	{
	}
	motor[chosenMotor]=0;
	nMotorEncoder[chosenMotor] = 0;
	wait1Msec(100);
}
//Runs 1 motor for certain CM at a certin speed (using the runWithEncoder)
void runMotorWithEncoderByCm(tMotor chosenMotor,int power,int cm)
{
	runMotorWithEncoder( chosenMotor, power, centimetersToUnits(cm) );
}
//Runs 2 motors for certain encoder units at a certin speed
void runTwoMotorsWithEncoder(tMotor Motor1,tMotor Motor2,int power,int units)
{
	nMotorEncoder[Motor1] = 0;
	if(units<0)
	{
		units=(-units);
	}
	motor[Motor1]=power;
	motor[Motor2]=power;
	while(abs(nMotorEncoder[Motor1])<units)
	{

	}
	motor[Motor1]=0;
	motor[Motor2]=0;
	nMotorEncoder[Motor1] = 0;
	wait1Msec(100);
}
//Runs 4 motors for certain encoder units at a certin speed
// only motors 1 and 2 have encoders but it drives them all
void runFourMotorsWithEncoder(tMotor Motor1,tMotor Motor2,tMotor Motor3,tMotor Motor4,int power,int units)
{
	nMotorEncoder[Motor1] = 0;
	if(units<0)
	{
		units=(-units);
	}
	motor[Motor1]=power;
	motor[Motor2]=power;
	motor[Motor3]=power;
	motor[Motor4]=power;
	while(abs(nMotorEncoder[Motor1])<units)
	{


	}
	motor[Motor1]=0;
	motor[Motor2]=0;
	motor[Motor3]=0;
	motor[Motor4]=0;
	nMotorEncoder[Motor1] = 0;
	wait1Msec(100);
}
void runFourMotorsWithEncoderByCmNoReset(tMotor Motor1,tMotor Motor2,tMotor Motor3,tMotor Motor4,int power,int units)
{
	int startVal = nMotorEncoder[Motor1];
	if(units<0)
	{
		units=(-units);
	}
	motor[Motor1]=power;
	motor[Motor2]=power;
	motor[Motor3]=power;
	motor[Motor4]=power;
	while(abs(nMotorEncoder[Motor1]-startVal)<centimetersToUnits(units))
	{


	}
	motor[Motor1]=0;
	motor[Motor2]=0;
	motor[Motor3]=0;
	motor[Motor4]=0;
	wait1Msec(100);
}
//Runs 2 motors for certain CM at a certin speed

void fourMotorcm(tMotor Motor1,tMotor Motor2,tMotor Motor3,tMotor Motor4,int power,int cm)
{
	runFourMotorsWithEncoder(Motor1,Motor2,Motor3,Motor4,power,centimetersToUnits(cm));
}

void RunFourMotorsWithEncoderWithDifferentPower(tMotor Motor1,tMotor Motor2,tMotor Motor3,tMotor Motor4,int power1,int power2, int units)
{
	nMotorEncoder[Motor1] = 0;
	if(units<0)
	{
		units=(-units);
	}
	motor[Motor1]=power1;
	motor[Motor2]=power2;
	motor[Motor3]=power1;
	motor[Motor4]=power2;
	while(abs(nMotorEncoder[Motor1])<units)
	{


	}
	motor[Motor1]=0;
	motor[Motor2]=0;
	motor[Motor3]=0;
	motor[Motor4]=0;
	nMotorEncoder[Motor1] = 0;
	wait1Msec(100);
}


