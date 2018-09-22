#include "API.h"


/* ------------------------------Motor Numbers--------------------------------- */
#define INTAKE 1
#define DRIVE_RMUL 2
#define LIFT 3
#define DRIVE_RSIN 4
#define CATA_SIN 5
#define CATA_R 6
#define CATA_L 7
#define DRIVE_LSIN 8
#define DRIVE_LMUL 9



/* ------------------------------Analog Sensors--------------------------------- */
#define LIFT_POT 1
#define GYRO_PORT 2
Gyro GYRO;

// Bat Voltage (Power Exp)
#define POWER_EXP 4


/*-----------------------------Digital Sensors---------------------------------- */
#define RIGHT_QUAD_TOP_PORT 1
#define RIGHT_QUAD_BOTTOM_PORT 2
#define LEFT_QUAD_TOP_PORT 3
#define LEFT_QUAD_BOTTOM_PORT 4
#define CATA_SWITCH 5

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
void cata(int iSpeed);
void cataWind();
void cataLaunch();
void pidDrive(void * parameter);
void pidRotate(void * parameter);
void lcdAuton_Pages(int selectVal);
void lcdAuton();
int driveGet();