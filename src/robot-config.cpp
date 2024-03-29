#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeft = motor(PORT1, ratio18_1, true);
motor frontRight = motor(PORT2, ratio18_1, false);
motor backLeft = motor(PORT3, ratio18_1, true);
motor backRight = motor(PORT4, ratio18_1, false);
motor roller = motor(PORT6, ratio18_1, false);
motor expansion = motor(PORT7, ratio18_1, false);
motor plauncherR = motor(PORT15, ratio18_1, false);
motor plauncherL = motor(PORT16, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}