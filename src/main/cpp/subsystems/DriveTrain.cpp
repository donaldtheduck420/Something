/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "commands/driveForward.h"
//#import "iostream"



DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(2)), right(new TalonSRX(3)){
  left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute);
  left->SetSelectedSensorPosition(0,0,10);
  left->SetInverted(false);
  right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Absolute);
  right->SetSelectedSensorPosition(0,0,10);
  right->SetInverted(false);
}

void DriveTrain::tankDrive(double leftInput, double rightInput) {
  leftPower=leftInput;
  rightPower=rightInput;
  left->Set(ControlMode::PercentOutput, -leftInput);
  right->Set(ControlMode::PercentOutput, rightInput);


  //std::cout<<"leftPower"<<"rightPower"<<std::endl;

}

double DriveTrain::getPosition(){
  return (left->GetSelectedSensorPosition() + right->GetSelectedSensorPosition()) / 2;
}

void DriveTrain::resetEncoders(){
  left->SetSelectedSensorPosition(0,0,10);
  right->SetSelectedSensorPosition(0,0,10);
}



void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
 // SetDefaultCommand(new driveForward(double distance));
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
