// Drawing functions
void drawRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, float r, float g, float b) {
    // Rectangle order
    // Bottom Left (x1, y1) 
    // Top Left (x2, y2)
    // Top Right (x3, y3)
    // Bottom Right (x4, y4)
    // Colors (r, g, b)

    glColor3f (r, g, b);
    glBegin(GL_QUADS);
        glVertex3f(x1, y1, 0.0f);
        glVertex3f(x2, y2, 0.0f);
        glVertex3f(x3, y3, 0.0f);
        glVertex3f(x4, y4, 0.0f);
    glEnd();
}

void drawAlphaRectangle(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4, float r, float g, float b, float a) {
    // Rectangle order
    // Bottom Left (x1, y1) 
    // Top Left (x2, y2)
    // Top Right (x3, y3)
    // Bottom Right (x4, y4)
    // Colors (r, g, b)
    // Opacity (a)

    glColor4f(r, g, b, a);
    glBegin(GL_POLYGON);
        glVertex3f(x1, y1, 0.0f);
        glVertex3f(x2, y2, 0.0f);
        glVertex3f(x3, y3, 0.0f);
        glVertex3f(x4, y4, 0.0f);
    glEnd();
}

void drawCircle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    // Circle order
    // Radius X (rx)
    // Radius Y (ry)
    // Center X (cx)
    // Center Y (xy)

    glBegin(GL_POLYGON);
    for(int i=0; i<180; i++) {
        float angle = 4.0f * 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

// Rendering functions
// Render background grass
void renderGrass(float grassR, float grassG, float grassB) { 
    drawRectangle(-0.05f, -0.05f, -0.05f, 0.02f, 0.85f, 0.02f, 0.85f,-0.05f, grassR, grassG, grassB);
}

// Render clouds
void renderClouds(float cloudR, float cloudG, float cloudB, float cloudA) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    // Cloud 1
    glColor4f(cloudR, cloudG, cloudB, cloudA);
    drawCircle(0.025,0.025,cloudOneSpeed-0.01, 0.28);
    drawCircle(0.025,0.025,cloudOneSpeed-0.04, 0.28);
    drawCircle(0.025,0.025,cloudOneSpeed-0.07, 0.28);
    drawCircle(0.025,0.025,cloudOneSpeed-0.04, 0.30);
    
    
    // Cloud 2
    drawCircle(0.025,0.025,cloudTwoSpeed-0.71, 0.32);
    drawCircle(0.025,0.025,cloudTwoSpeed-0.74, 0.32);
    drawCircle(0.025,0.025,cloudTwoSpeed-0.77, 0.32);
    drawCircle(0.025,0.025,cloudTwoSpeed-0.74, 0.34);

    // Cloud 3
    drawCircle(0.025,0.025,cloudThreeSpeed-0.41, 0.36);
    drawCircle(0.025,0.025,cloudThreeSpeed-0.44, 0.36);
    drawCircle(0.025,0.025,cloudThreeSpeed-0.47, 0.36);
    drawCircle(0.025,0.025,cloudThreeSpeed-0.44, 0.38);

    // Cloud 4
    drawCircle(0.025,0.025,cloudOneSpeed+0.12, 0.36);
    drawCircle(0.025,0.025,cloudOneSpeed+0.15, 0.36);
    drawCircle(0.025,0.025,cloudOneSpeed+0.18, 0.36);
    drawCircle(0.025,0.025,cloudOneSpeed+0.15, 0.38);

    // Cloud 5
    drawCircle(0.025,0.025,cloudTwoSpeed+0.42, 0.26);
    drawCircle(0.025,0.025,cloudTwoSpeed+0.45, 0.26);
    drawCircle(0.025,0.025,cloudTwoSpeed+0.48, 0.26);
    drawCircle(0.025,0.025,cloudTwoSpeed+0.45, 0.28);

    // Cloud 6
    drawCircle(0.025,0.025,cloudOneSpeed+0.62, 0.33);
    drawCircle(0.025,0.025,cloudOneSpeed+0.65, 0.33);
    drawCircle(0.025,0.025,cloudOneSpeed+0.68, 0.33);
    drawCircle(0.025,0.025,cloudOneSpeed+0.65, 0.35);

    glDisable(GL_BLEND);
}

// Render sky
void renderSky(float skyR, float skyG, float skyB) {
    drawRectangle(-0.05f, 0.09f, -0.05f, 0.40f, 0.85f, 0.40f, 0.85f, 0.09f, skyR, skyG, skyB);
}

// Render planet
void renderPlanet(float planetR, float planetG, float planetB) {
    glColor3f(planetR, planetG, planetB);
    drawCircle(0.0255, 0.02, planetX-0.05, planetY+0.3);
}

// Render roads
void renderRoads() {
    // Road background
    drawRectangle(-0.05f,0.02f, -0.05f,0.08f, 0.90f,0.08f, 0.90f,0.02f, 0.4, 0.4, 0.4);
    // Road stripes
    for(float i=-0.03f; i<0.80; i+=0.08) {
        drawRectangle(i,0.053f, i,0.057f, i+0.04,0.057f, i+0.04,0.053f, 0.7, 0.7, 0.7);
    }

    // Road edges top
    drawRectangle(-0.05f,0.08f, -0.05f,0.09f, 0.90f,0.09f, 0.90f,0.08f, 0.2, 0.2, 0.2);
    // Road edges top stripes
    for(float i=0.01; i<0.80; i+=0.08) {
        drawRectangle(i,0.08f, i,0.09f, i+0.04,0.09f, i+0.04,0.08f, 0.8, 0.8, 0.8);
    }

    // Road edges bottom
    drawRectangle(-0.06f,0.02f, -0.05f,0.03f, 0.90f,0.03f, 0.90f,0.02f, 0.2, 0.2, 0.2);
    // Road edges bottom stripes
    for(float i=0.01; i<0.80; i+=0.08) {
        drawRectangle(i,0.02f, i,0.03f, i+0.04,0.03f, i+0.04,0.02f, 0.8, 0.8, 0.8);
    }
}

void renderCarOneModel(int isLightOn) {
    // upper body
    drawRectangle(vehiclePos-0.24,0.085, vehiclePos-0.21,0.11, vehiclePos-0.12,0.11, vehiclePos-0.1,0.085, 0.56, 0.06, 0.11);
    // lower body
    drawRectangle(vehiclePos-0.24,0.065, vehiclePos-0.24,0.085, vehiclePos-0.06,0.085, vehiclePos-0.06,0.065, 0.56, 0.06, 0.11);

    if(isLightOn) {
        drawRectangle(vehiclePos-0.06,0.075, vehiclePos-0.06,0.080, vehiclePos+0.01,0.065, vehiclePos-0.03,0.065, 0.9, 0.9, 0.0);
        glColor3f(0.9, 0.9, 0.0);
        drawCircle(0.05,0.007,vehiclePos-0.0, 0.06);
    }    

    // Windows
    // Window 1
    drawRectangle(vehiclePos-0.23,0.085, vehiclePos-0.21,0.105, vehiclePos-0.195,0.105, vehiclePos-0.195,0.085, 0.71, 0.84, 1);
    // Window 2
    drawRectangle(vehiclePos-0.19,0.085, vehiclePos-0.19,0.105, vehiclePos-0.15,0.105, vehiclePos-0.15,0.085, 0.71, 0.84, 1);
    // Window 3
    drawRectangle(vehiclePos-0.145,0.085, vehiclePos-0.145,0.105, vehiclePos-0.125,0.105, vehiclePos-0.11,0.085, 0.71, 0.84, 1);

    // Tires
    glColor3f(0.0,0.0,0);
    drawCircle(0.016,0.015,vehiclePos-0.2, 0.06); // Front tire
    drawCircle(0.016,0.015,vehiclePos-0.1, 0.06); // Back tire

    // Inner tires
    glColor3f(0.8, 0.8, 0.8);
    drawCircle(0.008,0.007,vehiclePos-0.2, 0.06); // Inner Front tire
    drawCircle(0.008,0.007,vehiclePos-0.1, 0.06); // Inner Back tire
}

void renderCarTwoModel(int isLightOn) {
    // upper body
    drawRectangle(vehiclePos-0.82,0.11, vehiclePos-0.78,0.08, vehiclePos-0.92,0.08, vehiclePos-0.88,0.11, 0, 0.56, 0.67);
    // lower body
    drawRectangle(vehiclePos-0.93,0.065, vehiclePos-0.93,0.085, vehiclePos-0.77,0.085, vehiclePos-0.77,0.065, 0, 0.56, 0.67);
    
    if(isLightOn) {
        drawRectangle(vehiclePos-0.77,0.075, vehiclePos-0.77,0.080, vehiclePos-0.70,0.065, vehiclePos-0.74,0.065, 0.9, 0.9, 0.0);
        glColor3f(0.9, 0.9, 0.0);
        drawCircle(0.05,0.007,vehiclePos-0.70, 0.06);
    }    

    // Windows
    // Window 1
    drawRectangle(vehiclePos-0.805,0.085, vehiclePos-0.83,0.105, vehiclePos-0.845,0.105, vehiclePos-0.845,0.085, 0.71, 0.84, 1);
    // Window 2
    drawRectangle(vehiclePos-0.855,0.085, vehiclePos-0.855,0.105, vehiclePos-0.87,0.105, vehiclePos-0.895,0.085, 0.71, 0.84, 1);

    // Tires
    glColor3f(0.0,0.0,0);
    drawCircle(0.016,0.015,vehiclePos-0.80, 0.06); // Front tire
    drawCircle(0.016,0.015,vehiclePos-0.90, 0.06); // Back tire

    // Inner tires
    glColor3f(0.8, 0.8, 0.8);
    drawCircle(0.008,0.007,vehiclePos-0.80, 0.06); // Inner Front tire
    drawCircle(0.008,0.007,vehiclePos-0.90, 0.06); // Inner Back tire
}

void renderHorizon(float horizonR, float horizonG, float horizonB, float horizonA) {
    // Horizon
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

    drawAlphaRectangle(-0.05, 0.05, -0.05, 0.21, 0.00, 0.21, 0.00, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.00, 0.05, 0.00, 0.18, 0.05, 0.18, 0.05, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.05, 0.05, 0.05, 0.24, 0.10, 0.24, 0.10, 0.05, horizonR, horizonG, horizonB, horizonA);

    drawAlphaRectangle(0.10, 0.05, 0.10, 0.21, 0.15, 0.21, 0.15, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.15, 0.05, 0.15, 0.24, 0.20, 0.24, 0.20, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.20, 0.05, 0.20, 0.33, 0.25, 0.33, 0.25, 0.05, horizonR, horizonG, horizonB, horizonA);

    drawAlphaRectangle(0.25, 0.05, 0.25, 0.3, 0.30, 0.3, 0.30, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.30, 0.05, 0.30, 0.27, 0.35, 0.27, 0.35, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.35, 0.05, 0.35, 0.33, 0.40, 0.33, 0.40, 0.05, horizonR, horizonG, horizonB, horizonA);

    drawAlphaRectangle(0.40, 0.05, 0.40, 0.3, 0.45, 0.3, 0.45, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.45, 0.05, 0.45, 0.33, 0.50, 0.33, 0.50, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.50, 0.05, 0.50, 0.3, 0.55, 0.3, 0.55, 0.05, horizonR, horizonG, horizonB, horizonA);

    drawAlphaRectangle(0.55, 0.05, 0.55, 0.3, 0.60, 0.3, 0.60, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.60, 0.05, 0.60, 0.24, 0.65, 0.24, 0.65, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.65, 0.05, 0.65, 0.33, 0.70, 0.33, 0.70, 0.05, horizonR, horizonG, horizonB, horizonA);
    
    drawAlphaRectangle(0.70, 0.05, 0.70, 0.24, 0.75, 0.24, 0.75, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.75, 0.05, 0.75, 0.16, 0.80, 0.16, 0.80, 0.05, horizonR, horizonG, horizonB, horizonA);
    drawAlphaRectangle(0.80, 0.05, 0.80, 0.21, 0.85, 0.21, 0.85, 0.05, horizonR, horizonG, horizonB, horizonA);

    glDisable(GL_BLEND);
}

// Render windows
void renderBuildings(float windowR, float windowG, float windowB) {
    // 1st building
    // Building background
    drawRectangle(0.12f, 0.05f, 0.12f, 0.19f, 0.2f, 0.19f, 0.2f, 0.05f, 1, 0.35, 0.69);
    // Inner building shade
    drawRectangle(0.13f, 0.05f, 0.13f, 0.18f, 0.19f, 0.18f, 0.19f, 0.05f, 0.77, 0.27, 0.53);
    // Building sideline
    drawRectangle(0.1f, 0.05f, 0.1f, 0.17f, 0.12f, 0.19f, 0.12f, 0.07f, 0.49, 0, 0.26);
    // Building windows
    for(float i=0.12; i<0.16; i+=0.02) {
        drawRectangle(0.14f, i, 0.14f, i+0.01, 0.155f, i+0.01, 0.155f, i, windowR, windowG, windowB);
    }
    for(float i=0.12; i<0.16; i+=0.02) {
        drawRectangle(0.165f, i, 0.165f, i+0.01, 0.18f, i+0.01, 0.18f, i, windowR, windowG, windowB);
    }

    // 2nd building
    // Building background
    drawRectangle(0.22f, 0.05f, 0.22f, 0.27f, 0.3f, 0.27f, 0.3f, 0.05f, 0.4, 0.4, 0.4);
    // Inner building shade
    drawRectangle(0.23f, 0.05f, 0.23f, 0.26f, 0.29f, 0.26f, 0.29f, 0.05f, 0.26, 0.26, 0.26);
    // Building sideline
    drawRectangle(0.2f, 0.05f, 0.2f, 0.25f, 0.22f, 0.27f, 0.22f, 0.07f, 0.14, 0.14, 0.14);
    // Building windows
    for(float i=0.12; i<0.24; i+=0.02) {
        drawRectangle(0.24f, i, 0.24f, i+0.01, 0.255f, i+0.01, 0.255f, i, windowR, windowG, windowB);
    }
    for(float i=0.12; i<0.24; i+=0.02) {
        drawRectangle(0.265f, i, 0.265f, i+0.01, 0.28f, i+0.01, 0.28f, i, windowR, windowG, windowB);
    }

    // 3rd building
    // Building background
    drawRectangle(0.32f, 0.05f, 0.32f, 0.33f, 0.4f, 0.33f, 0.4f, 0.05f, 1, 0.56, 0.33);
    // Inner building shade
    drawRectangle(0.33f, 0.05f, 0.33f, 0.32f, 0.39f, 0.32f, 0.39f, 0.05f, 0.7, 0.37, 0.2);
    // Building sideline
    drawRectangle(0.3f, 0.05f, 0.3f, 0.31f, 0.32f, 0.33f, 0.32f, 0.07f, 0.48, 0.16, 0);
    //Building windows
    for(float i=0.12; i<0.32; i+=0.02) {
        drawRectangle(0.34f, i, 0.34f, i+0.01, 0.355f, i+0.01, 0.355f, i, windowR, windowG, windowB);
    }
    for(float i=0.12; i<0.32; i+=0.02) {
        drawRectangle(0.365f, i, 0.365f, i+0.01, 0.38f, i+0.01, 0.38f, i, windowR, windowG, windowB);
    }

    // 4th building
    // Building background
    drawRectangle(0.4f, 0.05f, 0.4f, 0.25f, 0.48f, 0.25f, 0.48f, 0.05f, 1.00, 0.13, 0.13);
    // Inner building shade
    drawRectangle(0.41f, 0.05f, 0.41f, 0.24f, 0.47f, 0.24f, 0.47f, 0.05f, 0.72, 0.00, 0.00);
    // Building sideline
    drawRectangle(0.48f, 0.05f, 0.48f, 0.25f, 0.5f, 0.23f, 0.5f, 0.07f, 0.52, 0.00, 0.00);
    // Building windows
    for(float i=0.12; i<0.23; i+=0.02) {
        drawRectangle(0.42f, i, 0.42f, i+0.01, 0.435f, i+0.01, 0.435f, i, windowR, windowG, windowB);
    }
    for(float i=0.12; i<0.23; i+=0.02) {
        drawRectangle(0.445f, i, 0.445f, i+0.01, 0.46f, i+0.01, 0.46f, i, windowR, windowG, windowB);
    }

    // 5th building
    // Building background
    drawRectangle(0.5f, 0.05f, 0.5f, 0.29f, 0.58f, 0.29f, 0.58f, 0.05f, 0.56, 0.29, 1);
    // Inner building shade
    drawRectangle(0.51f, 0.05f, 0.51f, 0.28f, 0.57f, 0.28f, 0.57f, 0.05f, 0.38, 0.15, 0.74);
    // Building sideline
    drawRectangle(0.58f, 0.05f, 0.58f, 0.29f, 0.6f, 0.27f, 0.6f, 0.07f, 0.12, 0, 0.32);
    // Building windows
    for(float i=0.12; i<0.27; i+=0.02) {
        drawRectangle(0.52f, i, 0.52f, i+0.01, 0.535f, i+0.01, 0.535f, i, windowR, windowG, windowB);
    }
    for(float i=0.12; i<0.27; i+=0.02) {
        drawRectangle(0.545f, i, 0.545f, i+0.01, 0.56f, i+0.01, 0.56f, i, windowR, windowG, windowB);
    }

    // 6th building
    // Building background
    drawRectangle(0.6f, 0.05f, 0.6f, 0.23f, 0.68f, 0.23f, 0.68f, 0.05f, 0.2, 0.5, 0.0);
    // Inner building shade
    drawRectangle(0.61f, 0.05f, 0.61f, 0.22f, 0.67f, 0.22f, 0.67f, 0.05f, 0.2, 0.4, 0.0);
    // Building sideline
    drawRectangle(0.68f, 0.05f, 0.68f, 0.23f, 0.7f, 0.21f, 0.7f, 0.07f, 0.2, 0.2, 0.0);
    // Building windows
    for(float i=0.12; i<0.20; i+=0.02) {
        drawRectangle(0.62f, i, 0.62f, i+0.01, 0.635f, i+0.01, 0.635f, i, windowR, windowG, windowB);
    }
    for(float i=0.12; i<0.20; i+=0.02) {
        drawRectangle(0.645f, i, 0.645f, i+0.01, 0.66f, i+0.01, 0.66f, i, windowR, windowG, windowB);
    }
}