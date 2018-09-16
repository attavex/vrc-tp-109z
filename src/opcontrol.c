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
    motorSet(DRIVE_LMUL, -speed - turn);
	motorSet(DRIVE_LSIN, -speed + turn);
    motorSet(DRIVE_RMUL, -speed + turn);
	motorSet(DRIVE_RSIN, -speed - turn);
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

int liftOutput;	
int iArmDes = 325; //Starting point of lift
inline void liftControl(bool bBtnUp, bool bBtnDown)
{
    if(bBtnUp || bBtnDown)
    {
        liftOutput = bBtnUp ? 127 : (bBtnDown ? -127 : 0);
        iArmDes = analogRead(LIFT_POT);
    } /*
	else if(analogRead(LIFT_POT) < 3500) 
	{
		liftOutput = -15;
	} */
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
	//lcdPrint(uart1, 1, "MANI - %d", analogRead(MANI_POT));
	//lcdPrint(uart1, 2, "LIFT - %d", analogRead(LIFT_POT));
	driveControl(joyAxis3, joyAxis4);
	inControl(bBtn5U, bBtn5D);
	liftControl(bBtn6U, bBtn6D);
	//printf("%d %d %d\n", analogRead(), analogRead(LIFT_POT), analogRead());
	}
}