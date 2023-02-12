/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// frontRight           motor         2               
// backLeft             motor         3               
// backRight            motor         4               
// roller               motor         6               
// expansion            motor         7               
// plauncherR           motor         15              
// plauncherL           motor         16              
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

//int lastx = 0;
//int lasty = 0;
//void brain_draw() {
  //while(true) {
    //if (Brain.Screen.pressing()) {
      //Brain.Screen.drawLine(lastx, lasty, Brain.Screen.xPosition(), Brain.Screen.yPosition());
    //}
    //lastx = Brain.Screen.xPosition();
    //lasty = Brain.Screen.yPosition();
    //wait(17, msec);
  //}
//}

void temp_display() {
  while(true){
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(frontLeft.temperature(percent));
    Controller1.Screen.setCursor(1, 11);
    Controller1.Screen.print(backLeft.temperature(percent));
    Controller1.Screen.setCursor(4, 1);
    Controller1.Screen.print(frontRight.temperature(percent));
    Controller1.Screen.setCursor(4, 11);
    Controller1.Screen.print(backRight.temperature(percent));
    Controller1.Screen.setCursor(2, 6);
    Controller1.Screen.print(roller.temperature(percent));
    wait(1000, msec);
  }
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  thread tempThread = thread(temp_display);
  // thread draw = thread(brain_draw);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void go(int x) {
  frontLeft.setVelocity(x, percent);
  frontRight.setVelocity(x, percent);
  backLeft.setVelocity(x, percent);
  backRight.setVelocity(x, percent);
}

void autonomous(void) {
  frontLeft.spin(forward);
  frontRight.spin(forward);
  backLeft.spin(forward);
  backRight.spin(forward);

  go(100);
  wait(1000, msec);
  go(0);
  wait(500, msec);
  go(-100);
  wait(2000, msec);
  go(0);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

//void expansion_code(){
//  expansion.spin(forward);
//  expansion.setVelocity(100, percent);
//  wait(1000, msec);
//  expansion.setVelocity(0, percent);
//}

void usercontrol(void) {
  frontLeft.spin(forward);
  frontRight.spin(forward);
  backLeft.spin(forward);
  backRight.spin(forward);
  roller.spin(forward);
  expansion.spin(forward);
  plauncherL.spin(forward);
  plauncherR.spin(forward);

  bool frontLeftFuse = true;
  bool frontRightFuse = true;
  bool backLeftFuse = true;
  bool backRightFuse = true;
  bool rollerFuse = true;
  bool expFuse = true;
  bool plauncherLFuse = true;
  bool plauncherRFuse = true;

  bool burn = false;


  while (true) {

    if (Controller1.ButtonA.pressing()) {
      frontLeft.setVelocity(-10, percent);
      frontRight.setVelocity(-10, percent);
      backLeft.setVelocity(80, percent);
      backRight.setVelocity(80, percent);
      burn = true;
    } else {
      burn = false;
    }

    if(burn == false) {
      frontRight.setVelocity((Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent) * 2), percent);
      backRight.setVelocity((Controller1.Axis3.position(percent) - Controller1.Axis1.position(percent) * 2), percent);
      frontLeft.setVelocity((Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent) * 2), percent);
      backLeft.setVelocity((Controller1.Axis3.position(percent) + Controller1.Axis1.position(percent) * 2), percent);
    }

    if (Controller1.ButtonR2.pressing()) {
      plauncherL.setVelocity(100, percent);
      plauncherR.setVelocity(100, percent);
    } else if (Controller1.ButtonL2.pressing()) {
      plauncherL.setVelocity(-100, percent);
      plauncherR.setVelocity(-100, percent);
    } else {
      plauncherL.setVelocity(0, percent);
      plauncherR.setVelocity(0, percent);
    }

    if (frontLeftFuse == true && frontLeft.temperature(percent) >= 80) {
      Controller1.rumble(rumbleLong);
      frontLeftFuse = false;
    } else if (frontRightFuse == true && frontLeft.temperature(percent) >= 80) {
      Controller1.rumble(rumbleLong);
      frontRightFuse = false;
    } else if (backLeftFuse == true && backLeft.temperature(percent) >= 80) {
      Controller1.rumble(rumbleLong);
      backLeftFuse = false;
    } else if (backRightFuse == true && backRight.temperature(percent) >= 80) {
      Controller1.rumble(rumbleLong);
      backLeftFuse = false;
    } else if (rollerFuse == true && roller.temperature(percent) >= 80) {
      Controller1.rumble(rumbleLong);
      rollerFuse = false;
    } else if (expFuse == true && expansion.temperature(percent) >= 80) {
      Controller1.rumble(rumbleLong);
      expFuse = false;
    } else if (plauncherLFuse == true && plauncherL.temperature(percent) >= 70) {
      Controller1.rumble(rumbleLong);
      plauncherLFuse = false;
    } else if (plauncherRFuse == true && plauncherR.temperature(percent) >= 70) {
      Controller1.rumble(rumbleLong);
      plauncherRFuse = false;
    }

    if (Controller1.ButtonL1.pressing()) {
      roller.setVelocity(-50, percent);
    } else if (Controller1.ButtonR1.pressing()) {
      roller.setVelocity(50, percent);
    } else {
      roller.setVelocity(0, percent);
    }

    if (Controller1.ButtonUp.pressing()) {
      expansion.setVelocity(100, percent);
    } else if (Controller1.ButtonDown.pressing()) {
      expansion.setVelocity(-100, percent);
    } else {
      expansion.setVelocity(0, percent);
    }

    wait(10, msec);
  }
}

// Main will set up the competition functions and callbacks.

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}