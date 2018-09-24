#include "main.h"
/*
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

int dDes;
int gyDes;
void mogoAutonMaster20(int choice) 
{
    if(choice == 1)
    {
 
    }
    else if(choice == 2)
    {
  
}

void mogoAutonMaster5(int choice)
{
    if(choice == 1)
    {
     
    }
    else if(choice == 2)
    {
 
}

void blockingAutonMaster(int choice)
{
  if (choice == 1)
  {
  }
  else if (choice == 2)
  {
  }



void autonomous() 
{
  encoderReset(LEFT_ENCODER);
  encoderReset(RIGHT_ENCODER);
  gyroReset(GYRO);
  if(selectAuton[0] == 1) //20-point mogo 2 cone
  {
    if(selectAuton[2] == 1) //match loader side
    {
      encoderReset(LEFT_ENCODER);
      encoderReset(RIGHT_ENCODER);
      gyroReset(GYRO);
      mogoAutonMaster20(1);
    }
    else if(selectAuton[2] == 2) //other side
    {
      encoderReset(LEFT_ENCODER);
      encoderReset(RIGHT_ENCODER);
      gyroReset(GYRO);
      mogoAutonMaster20(2);
    }
  }

  if(selectAuton[0] == 2) //5-point mogo 2 cone
  {
     if(selectAuton[2] == 1) //Match loader side
    {
      encoderReset(LEFT_ENCODER);
      encoderReset(RIGHT_ENCODER);
      gyroReset(GYRO);
      mogoAutonMaster5(1);
    }
    else if(selectAuton[2] == 2) //other side
    {
      encoderReset(LEFT_ENCODER);
      encoderReset(RIGHT_ENCODER);
      gyroReset(GYRO);
      mogoAutonMaster5(2);
    }
  }

  if(selectAuton[0] == 3) //blocking
  {
       if(selectAuton[2] == 1) //Match loader side
    {
      encoderReset(LEFT_ENCODER);
      encoderReset(RIGHT_ENCODER);
      gyroReset(GYRO);
      blockingAutonMaster(1);
    }
    else if(selectAuton[2] == 2) //other side
    {
      encoderReset(LEFT_ENCODER);
      encoderReset(RIGHT_ENCODER);
      gyroReset(GYRO);
      blockingAutonMaster(2);
    }
  }
  
}
*/