#pragma config(Hubs,  S1, HTMotor,  HTServo,  HTMotor,  none)
#pragma config(Sensor, S1,     touch,          sensorI2CMuxController)
#pragma config(Sensor, S2,     ir,             sensorNone)
#pragma config(Sensor, S3,     light,          sensorLightActive)
#pragma config(Sensor, S4,     sonar,          sensorSONAR)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftWheel,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightWheel,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     flagRaiser,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     pullupRaise,   tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    deployArm,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C2_2,    dropBlockArm,         tServoStandard)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "move_turns_vars.h"
#include "movement.h"
#include "surfaces.h"
#include "JoystickDriver.c"


task winchButton()
{
    nSchedulePriority = kHighPriority;

    switch (nNxtButtonPressed)
    {
    case kLeftButton:   //raise your candies
        motor[pullupRaise] = 80;
        break;
    case kRightButton:  //STASH THEM
        motor[pullupRaise] = -90;
        break;
    case kEnterButton:  //stop pls
        motor[pullupRaise] = 0;
        break;
    case kExitButton:
        StopAllTasks();
        break;
    default:
        motor[pullupRaise] = 0;
        break;
    }
}

task main()
{
       nNxtButtonTask = winchButton;
       while (true) { }
}
