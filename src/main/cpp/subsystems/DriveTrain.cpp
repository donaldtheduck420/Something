/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include "commands/Tankdrive.h"
//#import "iostream"

DriveTrain::DriveTrain() : Subsystem("DriveTrain"), left(new TalonSRX(2)), right(new TalonSRX(3)){}

void DriveTrain::tankDrive(double leftInput, double rightInput) {
  leftPower=leftInput;
  rightPower=rightInput;
  left->Set(ControlMode::PercentOutput, -leftInput);
  right->Set(ControlMode::PercentOutput, rightInput);


  //std::cout<<"leftPower"<<"rightPower"<<std::endl;

}




void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new Tankdrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
