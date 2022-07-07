// Simulation default definitions
#define PLANET_X_DEFAULT -0.005
#define PLANET_Y_DEFAULT -0.05;
#define DEFAULT_VEHICLE_POS -0.005;
#define CLOUD_ONE_DEFAULT_SPEED -0.005;
#define CLOUD_TWO_DEFAULT_SPEED -0.005;
#define CLOUD_THREE_DEFAULT_SPEED -0.005;
#define DEFAULT_CAR_SPEED 0.0002;

// Title screen configuration
char projectTitle[] = "Town Life Simulation";
char controlTitle[] = "Controls";
char commandDecrease[] = "Press A to decrease vehicle speed";
char commandIncrease[] = "Press D to increase vehicle speed";
char commandPause[] = "Press P to pause/resume simulation";
char commandReset[] = "Press R to reset simulation";
char comandSceneModes[] = "Press 1/2/3/4/5 to change scene modes";
char commandQuit[] = "Press Q to return to title screen";
char commandStart[] = "Press S to Start Simulation";

// Pause screen configuration
char pauseTitle[] = "Simulation paused";
char pauseText[] = "Press P to resume";

// Scene title configuration
char dawn[] = "Dawn";
char morning[] = "Morning";
char evening[] = "Evening";
char night[] = "Night";

// Sun default positions
float planetX = PLANET_X_DEFAULT;
float planetY = PLANET_Y_DEFAULT;

// Vehicle default position
float vehiclePos = DEFAULT_VEHICLE_POS;

// Cloud defaults
float cloudOneSpeed = CLOUD_ONE_DEFAULT_SPEED;
float cloudTwoSpeed = CLOUD_TWO_DEFAULT_SPEED;
float cloudThreeSpeed = CLOUD_THREE_DEFAULT_SPEED;

// Variable pos is used to get the current position in the screen
// 0-600 - Dusk
// 600-1200 - Morning
// 1200-1800 - Evening
// 1800-2400 - Night
float pos = 0;

// View mode
// 0 = Title screen
// 1 - Scenary screen
int view=0;

// Directions
// A - Move slower
// D - Move faster
float carSpeed = DEFAULT_CAR_SPEED;

// Pause mode
// 0 - Not paused
// 1 - Paused
int pause=0;

// Lock mode
// 0 - Value set to default (changing values)
// 1 - Value not locked (first time)
// 2 - Value locked (second time)
int lock=1;

// Scene modes
// 0 - Default mode
// 1 - Dawn
// 2 - Morning
// 3 - Evening
// 4 - Night
int sceneMode=0;