#include "main.h"

// Joy Values
#define joyAxis1 joystickGetAnalog(1, 1)
#define joyAxis2 joystickGetAnalog(1, 2)
#define joyAxis3 joystickGetAnalog(1, 3)
#define joyAxis4 joystickGetAnalog(1, 4)
// Btn Values
#define bBtn7L joystickGetDigital(1, 7, JOY_LEFT)
#define bBtn7R joystickGetDigital(1, 7, JOY_RIGHT)
#define bBtn7U joystickGetDigital(1, 7, JOY_UP)
#define bBtn7D joystickGetDigital(1, 7, JOY_DOWN)
#define bBtn8L joystickGetDigital(1, 8, JOY_LEFT)
#define bBtn8R joystickGetDigital(1, 8, JOY_RIGHT)
#define bBtn8U joystickGetDigital(1, 8, JOY_UP)
#define bBtn8D joystickGetDigital(1, 8, JOY_DOWN)
#define bBtn5U joystickGetDigital(1, 5, JOY_UP)
#define bBtn5D joystickGetDigital(1, 5, JOY_DOWN)
#define bBtn6U joystickGetDigital(1, 6, JOY_UP)
#define bBtn6D joystickGetDigital(1, 6, JOY_DOWN)

inline void driveControl(int speed, int turn) //Arcade
{
    if(abs(joyAxis4) > 15 || abs(joyAxis3) > 15)
	{
	motorSet(DRIVE_LMUL, -speed + turn);
	motorSet(DRIVE_LSIN, -speed + turn);
    motorSet(DRIVE_RMUL, speed + turn);
	motorSet(DRIVE_RSIN, speed + turn);
	}

	else
	{
	motorSet(DRIVE_LMUL, 0);
	motorSet(DRIVE_LSIN, 0);
    motorSet(DRIVE_RMUL, 0);
	motorSet(DRIVE_RSIN, 0);
	}
	}

int inOutput;
inline void inControl(bool bBtnUp, bool bBtnDown)
{
	
    if(bBtnUp)      
	{
		inOutput = 127;  
	}
	else if (bBtnDown) 
	{
		inOutput = -127;
	}
	else
	{
        inOutput = 0;
	}
	in(inOutput);
}
/*
int cataOutput;
inline void cataLaunch(bool bBtnUp, bool bBtnDown, bool bBtnDownWait)
{
	if (bBtnUp)
	{
		cataOutput = 127;
	}
	else if (bBtnDown)
	{
		cataOutput = -127;
	
	}
	else if (bBtnDownWait)
	{
		if (digitalRead(CATA_SWITCH))
		{
			cataOutput = 0;
		}
		cataOutput = -127;
	}
	else if (digitalRead(CATA_SWITCH))
	{
		cataOutput = 0;
	}
	else
	{
        cataOutput = 0;
	}
	cata(cataOutput);
}
*/

int liftOutput;	
int iArmDes = 325; //Starting point of lift --------------REWORK
inline void liftControl(bool bBtnUp, bool bBtnDown)
{
    if(bBtnUp || bBtnDown)
    {
        liftOutput = bBtnUp ? 127 : (bBtnDown ? -127 : 0);
        iArmDes = analogRead(LIFT_POT);
    }
    else
    {
        liftOutput = iArmPID(iArmDes);
    }

    lift(liftOutput);
}



void operatorControl() {
	encoderReset(LEFT_ENCODER);
	encoderReset(RIGHT_ENCODER);
	while (true) 
	{
     delay(20);
	 lcdClear(uart1); 
	 lcdPrint(uart1, 1, "Batt: %1.3f V", (double)powerLevelMain() / 1000);
	 lcdPrint(uart1, 2, "Batt: %1.3f V", (double)analogRead(POWER_EXP) / 280);
	//lcdPrint(uart1, 1, "MANI - %d", analogRead(CATA_POT));
	driveControl(joyAxis3, joyAxis4);
	inControl(bBtn5U, bBtn5D);
	liftControl(bBtn6D, bBtn6U);
	//cataLaunch(bBtn8U, bBtn8D, bBtn8R);
	
    if (bBtn8D) //wind up/go down
	{
        taskCreate(cataWind, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	}
	if (bBtn8U) //launch/go up
	{
		taskCreate(cataLaunch, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	}
	
	printf("%d\n", analogRead(CATA_POT));
	}
}
