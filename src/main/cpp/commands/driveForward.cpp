/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include "commands/driveForward.h"
#include "subsystems/DriveTrain.h"
#include "Robot.h"
#include "OI.h"


driveForward::driveForward(double distance) : Command("driveForward"), left(new TalonSRX(2)), right(new TalonSRX(3)){
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::drive());
  setpoint = distance;
  Requires(Robot::drive);
}

// Called just before this Command runs the first time
void driveForward::Initialize() {
  Robot::drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void driveForward::Execute() { // =0.5 is a default value to run if no arguement is given=
  double leftPow=0.5;
  double rightPow=0.5;
  Robot::drive->tankDrive(leftPow, rightPow);
  }

// Make this return true when this Command no longer needs to run execute()

bool driveForward::IsFinished() { 
  if(((left->GetSelectedSensorPosition() + right->GetSelectedSensorPosition()) / 2) >= setpoint) {
    return true;
  };
}

// Called once after isFinished returns true
void driveForward::End() 
{
    Robot::drive->tankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void driveForward::Interrupted() {

}
