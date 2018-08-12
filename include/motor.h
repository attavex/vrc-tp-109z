#include "API.h"


/* ------------------------------Motor Numbers--------------------------------- */
#define DRIVE_RB 
#define DRIVE_RF 
#define R_LIFT   
#define holder
#define holder 
#define INTAKE 
#define holder
#define L_LIFT 
#define DRIVE_LF 
#define DRIVE_LB 



/* ------------------------------Analog Sensors--------------------------------- */
#define CATA_POT 1
#define LIFT_POT 2
#define GYRO_PORT 3
Gyro GYRO;

// Bat Voltage (Power Exp)
#define POWER_EXP 4


/*-----------------------------Digital Sensors---------------------------------- */
#define RIGHT_QUAD_TOP_PORT 1
#define RIGHT_QUAD_BOTTOM_PORT 2
#define LEFT_QUAD_TOP_PORT 3
#define LEFT_QUAD_BOTTOM_PORT 4

Encoder RIGHT_ENCODER;
Encoder LEFT_ENCODER;


// PID //
typedef struct {
    float current;
    float kP;
    float kI;
    float kD;
    float target;
    float integral;
    float error;
    float derivative;
    float lastError;
} pid;

//Lift
int iArmPID(int iDes);
//Drive
int iDrivePID(int iDes);

// ~~~DEFINE ALL FUNCTIONS~~~ //
void driveSpeed(int iSpeed);
void in(int iSpeed);
void lift(int iSpeed);
void pidDrive(void * parameter);
void pidRotate(void * parameter);
void lcdAuton_Pages(int selectVal);
void lcdAuton();
int driveGet();