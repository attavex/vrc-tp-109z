#include "main.h"
TaskHandle driveTask, turnTask;





void testPIDRotate(int gyDes)
{
  turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
//anything here will run
  while(gyroGet(GYRO) < gyDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(turnTask);
}


void testPIDDrive(int dDes)
{
  driveTask = taskCreate(pidDrive, TASK_DEFAULT_STACK_SIZE, (void*)dDes, TASK_PRIORITY_DEFAULT);
 //anything here will run
  while(driveGet() < dDes)
  {
    delay(15);
  }
  delay(500);
  taskDelete(driveTask);
}


/**
 * Global Variable Reminders
 * Pos0 : Type of Autonomous - 1 = Cap/No Park - 2 = No Cap/Park - 3 = Cap/Park
 * Pos1 : Back/Front - 1 = Back - 2 = Front
 * Pos2 : Side - 1 = Blue - 2 = Red
**/

int dDes;
int gyDes;
void capNoParkMaster(int pos, int color) 
{
    if(pos == 1) //Back - Farthest from Flags
    {
      if(color == 1) // Blue - Back/Blue Auton
      {

      }
      else if(color == 2) // Red - Back/Red Auton
      {

      }
    }
    else if(pos == 2) //Front - Closest to Flags
    {
      if(color == 1) // Blue - Front/Blue Auton
      {
	    while(analogRead(CATA_POT) < 915) 
        {
        cata(127);
        }
        cata(90);
        wait(300);
        cata(0);
		wait(100);
 	 	gyDes = 170;
		gyroReset(GYRO);
  		turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  		while(gyroGet(GYRO) < gyDes)
  		{
    		delay(15);
 		}
  		delay(500);
  		taskDelete(turnTask);
		encoderReset(LEFT_ENCODER);
  		encoderReset(RIGHT_ENCODER);
		driveSpeed(-127);
   		while(driveGet() > -1550)
  		{
  			if(driveGet() < -1550) driveSpeed(0); 
  			delay(20);
  		}
		driveSpeed(0);
		lift(-127);
		while(analogRead(LIFT_POT) < 200)
		{
			if(analogRead(LIFT_POT) > 210) lift(127);
		}
		lift(127);
		while(analogRead(LIFT_POT) > 25)
		{
			if(analogRead(LIFT_POT) < 20) lift(0);
		}
		lift(0);
		encoderReset(LEFT_ENCODER);
  		encoderReset(RIGHT_ENCODER);
		driveSpeed(127);
   		while(driveGet() < 300)
  		{
  			if(driveGet() > 300) driveSpeed(0);
  			delay(20);
  		}
		gyDes = -62;
		gyroReset(GYRO);
  		turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  		while(gyroGet(GYRO) > gyDes)
  		{
    		delay(15);
 		}
  		delay(500);
  		taskDelete(turnTask);
		encoderReset(LEFT_ENCODER);
  		encoderReset(RIGHT_ENCODER);
		driveSpeed(127);
   		while(driveGet() < 250)
  		{
  			if(driveGet() > 250) driveSpeed(0);
  			delay(20);
  		}
		driveSpeed(0);
		lift(-127);
		while(analogRead(LIFT_POT) < 200)
		{
			if(analogRead(LIFT_POT) > 210) lift(127);
		}
		lift(127);
		while(analogRead(LIFT_POT) > 25)
		{
			if(analogRead(LIFT_POT) < 20) lift(0);
		}
		lift(0);
      }
      else if(color == 2) // Red - Front/Red Auton
      {
	    while(analogRead(CATA_POT) < 915) 
        {
        cata(127);
        }
        cata(90);
        wait(300);
        cata(0);
		wait(100);
 	 	gyDes = -170;
		gyroReset(GYRO);
  		turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  		while(gyroGet(GYRO) < gyDes)
  		{
    		delay(15);
 		}
  		delay(500);
  		taskDelete(turnTask);
		encoderReset(LEFT_ENCODER);
  		encoderReset(RIGHT_ENCODER);
		driveSpeed(-127);
   		while(driveGet() > -1550)
  		{
  			if(driveGet() < -1550) driveSpeed(0); 
  			delay(20);
  		}
		driveSpeed(0);
		lift(-127);
		while(analogRead(LIFT_POT) < 200)
		{
			if(analogRead(LIFT_POT) > 210) lift(127);
		}
		lift(127);
		while(analogRead(LIFT_POT) > 25)
		{
			if(analogRead(LIFT_POT) < 20) lift(0);
		}
		lift(0);
		encoderReset(LEFT_ENCODER);
  		encoderReset(RIGHT_ENCODER);
		driveSpeed(127);
   		while(driveGet() < 300)
  		{
  			if(driveGet() > 300) driveSpeed(0);
  			delay(20);
  		}
		gyDes = 62;
		gyroReset(GYRO);
  		turnTask = taskCreate(pidRotate, TASK_DEFAULT_STACK_SIZE, (void*)gyDes, TASK_PRIORITY_DEFAULT);
  		while(gyroGet(GYRO) > gyDes)
  		{
    		delay(15);
 		}
  		delay(500);
  		taskDelete(turnTask);
		encoderReset(LEFT_ENCODER);
  		encoderReset(RIGHT_ENCODER);
		driveSpeed(127);
   		while(driveGet() < 250)
  		{
  			if(driveGet() > 250) driveSpeed(0);
  			delay(20);
  		}
		driveSpeed(0);
		lift(-127);
		while(analogRead(LIFT_POT) < 200)
		{
			if(analogRead(LIFT_POT) > 210) lift(127);
		}
		lift(127);
		while(analogRead(LIFT_POT) > 25)
		{
			if(analogRead(LIFT_POT) < 20) lift(0);
		}
		lift(0);
      }
    }
}

void noCapParkMaster(int pos, int color)
{
    if(pos == 1) //Back - Farthest from Flags
    {
           if(color == 1) // Blue - Back/Blue Auton
      {

      }
      else if(color == 2) // Red - Back/Red Auton
      {

      }
    }
    else if(pos == 2) //Front - Closest to Flags
    {
      if(color == 1) // Blue - Front/Blue Auton
      {

      }
      else if(color == 2) // Red - Front/Red Auton
      {

      }
    }

}

void capParkMaster(int pos, int color)
{
  if (pos == 1) //Back - Farthest from Flags
  {
    if(color == 1) // Blue - Back/Blue Auton
    {

    }
    else if(color == 2) // Red - Back/Red Auton
    {

    }
  }
  else if (pos == 2) //Front - Closest to Flags
  {
    if(color == 1) // Blue - Front/Blue Auton
      {

      }
      else if(color == 2) // Red - Front/Red Auton
      {

      }
  }
}
/**
 * Global Variable Reminders
 * Pos0 : Type of Autonomous - 1 = Cap/No Park - 2 = No Cap/Park - 3 = Cap/Park
 * Pos1 : Back/Front - 1 = Back - 2 = Front
 * Pos2 : Side - 1 = Blue - 2 = Red
**/

void autonomous() 
{
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  gyroReset(GYRO);
  if(selectAuton[0] == 1) //Cap and NO Park Auton
  {
    if(selectAuton[1] == 1) //Back(Farthest from Flags)
    {
      if(selectAuton[2] == 1) //Blue Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capNoParkMaster(1,1);
      }
      else if(selectAuton[2] == 2) //Red Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capNoParkMaster(1,2);
      }
    }
    else if(selectAuton[1] == 2) //Front(Closest to Flags)
    {
     if(selectAuton[2] == 1) //Blue Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capNoParkMaster(2,1);
      }
      else if(selectAuton[2] == 2) //Red Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capNoParkMaster(2,2);
      }
    }
  }

  if(selectAuton[0] == 2) //NO Cap/Park
  {
     if(selectAuton[1] == 1) //Back(Farthest from Flags)
    {
     if(selectAuton[2] == 1) //Blue Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        noCapParkMaster(1,1);
      }
      else if(selectAuton[2] == 2) //Red Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        noCapParkMaster(1,2);
      }
    }
    else if(selectAuton[1] == 2) //Front(Closest to Flags)
    {
      if(selectAuton[2] == 1) //Blue Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        noCapParkMaster(2,1);
      }
      else if(selectAuton[2] == 2) //Red Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        noCapParkMaster(2,2);
      }
  }

  if(selectAuton[0] == 3) //Cap AND Park
  {
    if(selectAuton[1] == 1) //Back(Farthest from Flags)
    {
      if(selectAuton[2] == 1) //Blue Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capParkMaster(1,1);
      }
      else if(selectAuton[2] == 2) //Red Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capParkMaster(1,2);
      }
    }
    else if(selectAuton[1] == 2) //Front(Closest to Flags)
    {
     if(selectAuton[2] == 1) //Blue Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capParkMaster(2,1);
      }
      else if(selectAuton[2] == 2) //Red Side
      {
        encoderReset(LEFT_ENCODER);
        encoderReset(RIGHT_ENCODER);
        gyroReset(GYRO);
        capParkMaster(2,2);
      }
    }
  }
}
}