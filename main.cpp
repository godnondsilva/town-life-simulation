#include <GL/glut.h>
#include <math.h>
#include <cstring>

// constants.h includes all the constants
#include "constants.h"
// functions.h includes all the function declarations
#include "functions.h"
// utility.h includes all the utility functions
#include "utility.h"
// objects.h includes all objects in the background
#include "objects.h"

// Rendering objects
// Render dawn
void renderDawn() {
    renderGrass(0.10, 0.27, 0.11);
    renderSceneTitle(0.38, -0.035, dawn);
    renderSky(0, 0.17, 0.37);
    renderPlanet(1.00, 0.63, 0.18);
    renderHorizon(0.2, 0.2, 0.2, 0.1);
    renderClouds(0.5, 0.5, 0.5, 0.4);
    renderBuildings(0.71, 0.84, 1);
    renderRoads();
    renderCarOneModel(1);
    renderCarTwoModel(1);
}
// Render morning
void renderMorning() {
    renderGrass(0.204, 0.51, 0.204);
    renderSceneTitle(0.368, -0.035, morning);
    renderSky(0.13, 0.36, 0.84);
    renderPlanet(0.9, 0.9, 0.0);
    renderHorizon(0.0, 0.0, 0.0, 0.5);
    renderClouds(0.5, 0.5, 0.5, 0.4);
    renderBuildings(0.71, 0.84, 1);
    renderRoads();
    renderCarOneModel(0);
    renderCarTwoModel(0);
}
// Render evening
void renderEvening() {
    renderGrass(0.10, 0.27, 0.11);
    renderSceneTitle(0.372, -0.035, evening);
    renderSky(1.00, 0.63, 0.18);
    renderPlanet(1.00, 0.88, 0.74);
    renderHorizon(0.0, 0.0, 0.0, 0.5);
    renderClouds(0.5, 0.5, 0.5, 0.4);
    renderBuildings(0.71, 0.84, 1);
    renderRoads();
    renderCarOneModel(0);
    renderCarTwoModel(0);
}
// Render night
void renderNight() {
    renderGrass(0.01, 0.16, 0.00);
    renderSceneTitle(0.38, -0.035, night);
    renderSky(0.0, 0.0, 0.0);
    renderPlanet(0.79, 0.79, 0.79);
    renderHorizon(0.2, 0.2, 0.2, 0.1);
    renderClouds(0.5, 0.5, 0.5, 0.4);
    renderBuildings(1, 0.94, 0.28);
    renderRoads();
    renderCarOneModel(1);
    renderCarTwoModel(1);
}

void renderObjects() {
    if(sceneMode==0) {
        // Morning Dusk
        if(pos<=600) {
            renderDawn();
        }
        // Morning
        if(pos>600 && pos<=1200) {
            renderMorning();
        }
        // Evening
        if(pos>1200 && pos<=1800) {
            renderEvening();
        }
        // Night
        if(pos>1800 && pos<2400) {
            renderNight();
        }
    }
    if(sceneMode==1) {
        if(pos<2400) {
            renderDawn();
        }
    }
    if(sceneMode==2) {
        if(pos<2400) {
            renderMorning();
        }
    }
    if(sceneMode==3) {
        if(pos<2400) {
            renderEvening();
        }
    }
    if(sceneMode==4) {
        if(pos<2400) {
            renderNight();
        }
    }
}

// Function to lock the position of the screen (pausing function)
void lockPosition() {
    float newPos;
    float newPlanetX;
    float newPlanetY;
    float newVehiclePos;
    float newCloudOneSpeed;
    float newCloudTwoSpeed;
    float newCloudThreeSpeed;
    
    if(lock==1) {
        newPos = pos;
        newPlanetX = planetX;
        newPlanetY = planetY;
        newVehiclePos = vehiclePos;
        newCloudOneSpeed = cloudOneSpeed;
        newCloudTwoSpeed = cloudTwoSpeed;
        newCloudThreeSpeed = cloudThreeSpeed;
        lock=2;

    } 
    else if(lock==2) {
        pos = newPos;
        planetX = newPlanetX;
        planetY = newPlanetY;
        vehiclePos = newVehiclePos;
        cloudOneSpeed = newCloudOneSpeed;
        cloudTwoSpeed = newCloudTwoSpeed;
        cloudThreeSpeed = newCloudThreeSpeed;
    }
    else if(lock==0) {
        return;
    }
}

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(pause==1) {
        lockPosition();
    } else {
        pos+=0.25;
        
        // 1st cloud speed
        if(cloudOneSpeed <= 2.0)
            cloudOneSpeed += 0.000035;
        else
            cloudOneSpeed = CLOUD_ONE_DEFAULT_SPEED;
        // 2nd cloud speed
        if(cloudTwoSpeed <= 2.0)
            cloudTwoSpeed += 0.00015;
        else
            cloudTwoSpeed = CLOUD_TWO_DEFAULT_SPEED;
        // 3rd cloud speed
        if(cloudThreeSpeed <= 2.0)
            cloudThreeSpeed += 0.000005;
        else
            cloudThreeSpeed = CLOUD_THREE_DEFAULT_SPEED;

        // 1st phase - quarter of the screen
        if(pos==600) {
            pos=601.0;
        }
        // 2nd phase - half of the screen
        if(pos==1200) {
            pos=1201.0;
        }
        // 3rd phase - 3/4th of the screen
        if(pos==1800) {
            pos=1801.0;
        }
        // 4th phase - end of the screen
        if(pos==2400) {
            pos=0.0;
            planetX = PLANET_X_DEFAULT; // Reset sun horizontal position
            planetY = PLANET_Y_DEFAULT; // Reset sun vertical position
            vehiclePos = DEFAULT_VEHICLE_POS;
        }
        // Render background objects
        renderObjects();
        // Morning Dusk
        if(pos<=600) {
            planetY += 0.000025;
        }
        // Morning
        if(pos>600 && pos<=1200) {
            planetY += 0.000025;
        }
        // Evening
        if(pos>1200 && pos<=1800) {
            planetY -= 0.000025;
        }
        // Night
        if(pos>1800 && pos<2400) {
            planetY -= 0.000025;
        }
        // Entire screen
        if(pos>=0 && pos<=2400) {
            planetX += 0.0001;
            vehiclePos += carSpeed; 
        }
    }
    if(pause==1) {
        renderObjects();
        renderPauseScreen();
    }
    glutPostRedisplay();
    glFlush();
}


void displayString(float x, float y, char* string, int fontType) {
    int len, i;
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
        if(fontType == 1)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
        if(fontType == 2)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
        if(fontType == 3)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
        if(fontType == 4)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string[i]);
    }
}


void renderTitleScreen() {
    glClear(GL_COLOR_BUFFER_BIT);
    displayString(0.1, 0.3, collegeName, 1);
    displayString(200, 700, projectTitle, 1);
    displayString(200, 700, commands0, 4);
    glFlush();
}

void renderPauseScreen() {
    renderPauseDialogBox();
    displayString(0.33, 0.25, pauseTitle, 1);
    displayString(0.34, 0.2, pauseCmd0, 2);
}

void renderSceneTitle(float x, float y, char* sceneTitle) {
    renderSceneTitleBox();
    displayString(x, y, sceneTitle, 1);
}

void resetScene() {
    pos = 0;
    planetX = PLANET_X_DEFAULT;
    planetY = PLANET_Y_DEFAULT;
    vehiclePos = DEFAULT_VEHICLE_POS;
    cloudOneSpeed = CLOUD_ONE_DEFAULT_SPEED;
    cloudTwoSpeed = CLOUD_TWO_DEFAULT_SPEED;
    cloudThreeSpeed = CLOUD_THREE_DEFAULT_SPEED;
}

void handleDisplay() {
    glClearColor (1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-0.05, 0.85, -0.05, 0.40);
    // Title screen view
    if(view==0) {
        renderTitleScreen();
    }
    // Scenary screen view
    if(view==1) {
        renderScene();
    }  
}

void pauseScene() {
    if(pause==1) {
        pause=0;
    }
    else {
        pause=1;
        lock=0;
    }
}

void handleKey(unsigned char key, int x, int y) {
    if(key=='s') {
        // Set mode to scenary mode
        view = 1;
        // Re-render the screen
        glutPostRedisplay();
    }
    if(key=='d') {
        carSpeed += 0.0002;
        if(carSpeed>=0.01) {
            carSpeed=0.01;
        }
    }
    if(key=='a') {
        carSpeed -= 0.0002;
        if(carSpeed<=0.0002) {
            carSpeed=0;
        }
    }
    if(key=='p') {
        pauseScene();
    }
    if(key=='r') {
        resetScene();
    }
    if(key=='q') {
        // Set mode to title screen mode
        view = 0;
        // Re-render the screen
        glutPostRedisplay();
    }
    // Number 1
    if(key==49) {
        sceneMode=0;
    }
    // Number 2
    if(key==50) {
        sceneMode=1;
    }
    // Number 3
    if(key==51) {
        sceneMode=2;
    }
    // Number 4
    if(key==52) {
        sceneMode=3;
    }
    // Number 5
    if(key==53) {
        sceneMode=4;
    }
}

void handleMenu(int option)
{
	if(option==1)
		pauseScene();
	if(option==2)
        // Set mode to title screen mode
		view=0;
        // Re-render the screen
        glutPostRedisplay();
	if(option==3)
		exit(0);
}

void handleModesMenu(int option) {
    resetScene();
    switch(option) {
        // Default scene
        case 0:
            sceneMode=0;
            break;
        // Dawn scene
        case 1:
            sceneMode=1;
            break;
        // Morning scene
        case 2:
            sceneMode=2;
            break;
        // Evening scene
        case 3:
            sceneMode=3;
            break;
        // Night scene
        case 4:
            sceneMode=4;
            break;
    }
}

void handleMainMenu(int option) {
    switch(option) {
        case 0:
            pauseScene();
            break;
        case 1:
            resetScene();
            break;
        case 2:
            // Set mode to title screen mode
            view = 0;
            // Re-render the screen
            glutPostRedisplay();
            break;
    }
}

void callMainMenu() {
    int modesMenu;
	modesMenu=glutCreateMenu(handleModesMenu);
	glutAddMenuEntry("Default",0);
	glutAddMenuEntry("Dawn",1);
	glutAddMenuEntry("Morning",2);
	glutAddMenuEntry("Evening",3);
    glutAddMenuEntry("Night",4);
	
	glutCreateMenu(handleMainMenu);
	glutAddMenuEntry("Pause/Resume", 0);
    glutAddSubMenu("Scene Modes", modesMenu);
    glutAddMenuEntry("Reset Scene", 1);
    glutAddMenuEntry("Exit", 2);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (100, 100);
    window = glutCreateWindow("Town Life Simulation");
    glutKeyboardFunc(handleKey);
    glutDisplayFunc(handleDisplay);
    callMainMenu();
    glutMainLoop();
    return 0;
}