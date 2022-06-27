// Title screen configuration
char projectTitle[] = "Town Life Simulation";
char collegeName[] = "St Joseph Engineering College, Mangalore";
char commands0[] = "Press S to Start";

#define PLANET_X_DEFAULT -0.005
#define PLANET_Y_DEFAULT -0.05;
#define DEFAULT_VEHICLE_POS -0.005;
#define CLOUD_ONE_DEFAULT_SPEED -0.005;
#define CLOUD_TWO_DEFAULT_SPEED -0.005;
#define CLOUD_THREE_DEFAULT_SPEED -0.005;
#define DEFAULT_CAR_SPEED 0.0002;

// Sun default positions
float planetX = PLANET_X_DEFAULT;
float planetY = PLANET_Y_DEFAULT;

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
// 2 - Pause screen
int view=1;

// Directions
// A - Move slower
// D - Move faster
float carSpeed = DEFAULT_CAR_SPEED;