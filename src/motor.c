#include "main.h"

int driveGet() 
{
    return((encoderGet(LEFT_ENCODER) + encoderGet(RIGHT_ENCODER)) / 2);
}

void driveSpeed(int iSpeed)
{
    motorSet(DRIVE_LMUL, -iSpeed);
	motorSet(DRIVE_LSIN, -iSpeed);
    motorSet(DRIVE_RMUL, iSpeed);
	motorSet(DRIVE_RSIN, iSpeed);
}

void driveControl(int speed, int turn)
{
    motorSet(DRIVE_LMUL, -speed - turn);
	motorSet(DRIVE_LSIN, -speed + turn);
    motorSet(DRIVE_RMUL, -speed + turn);
	motorSet(DRIVE_RSIN, -speed - turn);
}

void driveLeft(int iSpeed)
{
    motorSet(DRIVE_LMUL, -iSpeed);
	motorSet(DRIVE_LSIN, iSpeed);
}

void driveRight(int iSpeed)
{
    motorSet(DRIVE_RSIN, iSpeed);
	motorSet(DRIVE_RMUL, -iSpeed);
}

void in(int iSpeed)
{
    motorSet(INTAKE, iSpeed);
}
void lift(int iSpeed) 
{
    motorSet(LIFT, iSpeed);
}
void cata(int iSpeed)
{
    motorSet(CATA_R, iSpeed);
    motorSet(CATA_L, -iSpeed);
    motorSet(CATA_SIN, iSpeed);
}

void cataWind() 
{
    while(analogRead(CATA_POT) < 890) 
    {
       cata(127);
    }
    cata(0);
    taskDelete(NULL);
}

void cataLaunch() 
{
        while(analogRead(CATA_POT) < 890) 
        {
        cata(60);
        }
        cata(60);
        wait(300);
        cata(0);
        while(analogRead(CATA_POT) < 890) 
        {
        cata(127);
        }
        cata(0);
        taskDelete(NULL);
}


//PD//
//LIFT
pid sArmPID;
int
iArmPID( int iDes ) 
{
	sArmPID.kP         = 0.075;
  sArmPID.kD         = 0.1;
	sArmPID.current    = analogRead(LIFT_POT);
	sArmPID.error      = sArmPID.current - iDes;
	sArmPID.derivative = sArmPID.error - sArmPID.lastError;
  sArmPID.lastError  = sArmPID.error;
	return ( (sArmPID.error * sArmPID.kP) + (sArmPID.derivative * sArmPID.kD) );
}

//DRIVE
pid sDrivePID;
    int iDrivePID( int target ) 
{
    sDrivePID.kP = .2;
    sDrivePID.kD = 1;
    sDrivePID.current = (encoderGet(LEFT_ENCODER) + encoderGet(RIGHT_ENCODER)) / 2;
    sDrivePID.error = target - sDrivePID.current;
    sDrivePID.derivative = sDrivePID.error - sDrivePID.lastError;
    sDrivePID.lastError = sDrivePID.error;
    return ( (sDrivePID.error * sDrivePID.kP) + (sDrivePID.derivative *sDrivePID.kD) + (15 * (sDrivePID.error / abs(sDrivePID.error) ) ) );
    }

    pid sRotatePID;
    int iRotatePID( int target) 
    {
    sRotatePID.kP = 2.65;
    sRotatePID.kD = 2;
    sRotatePID.kI = 0; 
    sRotatePID.current = gyroGet(GYRO);
    sRotatePID.error = target - sRotatePID.current;
    sRotatePID.integral += sRotatePID.error;  
    sRotatePID.derivative = sRotatePID.error - sRotatePID.lastError;
    sRotatePID.lastError = sRotatePID.error;
    return ( (sRotatePID.error * sRotatePID.kP)+ (sRotatePID.derivative * sRotatePID.kD) + (sRotatePID.integral * sRotatePID.kI) + 15 *(sRotatePID.error/(abs(sRotatePID.error))));
    }

void pidDrive(void * parameter)
{
    while(true)
    {
    driveSpeed(iDrivePID((int)parameter));
    }
}

void pidRotate(void * parameter)
{
    while(true)
    {
    driveLeft(iRotatePID((int)parameter));
    driveRight(iRotatePID((int)parameter));
    }
}