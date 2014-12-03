/*
	Function for Holonomic drive
*/

int function Holonomic(tMotor frontLeft, tMotor frontRight, tMotor backLeft, tMotor backRight) {

	int x1 = Joystick.joy1_x1;
	int y1 = Joystick.joy1_y1;	

	frontLeft = y1 + x1;
	frontRight = -y1 + x1;
	backLeft = y1 - x1;
	backRight = -y1 - x1;

	return 0;
} 
