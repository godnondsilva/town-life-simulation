#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <stdio.h>

// constants.h includes all the contants
#include "constants.h"
// functions.h includes all the function declarations
#include "functions.h"
// objects.h includes all objects in the background
#include "objects.h"

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
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
        sunX = SUN_X_DEFAULT; // Reset sun horizontal position
        sunY = SUN_Y_DEFAULT; // Reset sun vertical position
        vehiclePos = DEFAULT_VEHICLE_POS;
    }

    // Morning Dusk
    if(pos<=600) {
        renderGrass(0.10, 0.27, 0.11);
        renderSky(0.24, 0.00, 0.36);
        renderPlanet(0.94, 0.98, 0.32);
        renderClouds(0.5, 0.5, 0.5, 0.4);
        renderBuildings(0.0, 0.0, 0.0);
        sunY += 0.000025;
    }
    // Morning
    if(pos>600 && pos<=1200) {
        renderGrass(0.204, 0.51, 0.204);
        renderSky(0.13, 0.36, 0.84);
        renderPlanet(0.9, 0.9, 0.0);
        renderClouds(0.5, 0.5, 0.5, 0.4);
        renderBuildings(0.2, 0.2, 0.2);
        sunY += 0.0000125;
    }
    // Evening
    if(pos>1200 && pos<=1800) {
        renderGrass(0.204, 0.51, 0.204);
        renderSky(1.00, 0.63, 0.18);
        renderPlanet(1.00, 0.88, 0.74);
        renderClouds(0.5, 0.5, 0.5, 0.4);
        renderBuildings(1.0, 1.0, 1.0);
        sunY -= 0.0000125;
    }
    // Night
    if(pos>1800 && pos<2400) {
        renderGrass(0.01, 0.16, 0.00);
        renderSky(0.0, 0.0, 0.0);
        renderPlanet(0.79, 0.79, 0.79);
        renderClouds(0.5, 0.5, 0.5, 0.4);
        renderBuildings(1.0, 1.0, 1.0);
        sunY -= 0.000025;
    }
    // Entire screen
    if(pos>=0 && pos<=2400) {
        sunX += 0.0001;
        vehiclePos += carSpeed;
    }
    
    renderRoads();

    renderCarOneModel();
    renderCarTwoModel();
    renderBusModel();

    glutPostRedisplay();
    glFlush();
}


void displayString(int x, int y, char* string, int fontType) {
    int len,i;
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++)
    {
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
    displayString(200, 800, collegeName, 1);
    displayString(200, 700, projectTitle, 1);
    displayString(200, 700, commands0, 4);
    glFlush();
}


void displayHandle() {
    // Title screen view
    if(view==0) {
        glClearColor (1.0, 1.0, 1.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, 720, 0.0, 1200);
        renderTitleScreen();
    }
    // Scenary screen view
    if(view==1) {
        glClearColor (1.0, 1.0, 1.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-0.05, 0.85, -0.05, 0.40, 0.0, 10.0);
        renderScene();
    }  
}

void keyHandle(unsigned char key, int x, int y) {
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
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 720);
    glutInitWindowPosition (100, 100);
    glutCreateWindow("Scenario");
    glutKeyboardFunc(keyHandle);
    glutDisplayFunc(displayHandle);
    glutMainLoop();
    return 0;
}