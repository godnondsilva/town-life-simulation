// Rendering functions
// Render scene title
void renderSceneTitleBox() {
    drawAlphaRectangle(0.35, -0.04, 0.35, -0.02, 0.45, -0.02, 0.45, -0.04, 0.6, 0.6, 0.6, 0.4);
}
// Render pause menu dialog box
void renderPauseDialogBox() {
    drawRectangle(0.25, 0.15, 0.25, 0.3, 0.55, 0.3, 0.55, 0.15, 1.0, 1.0, 1.0);
}

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

    // Enable car lights during dawn/night
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
    // Front tire
    drawCircle(0.016,0.015,vehiclePos-0.2, 0.06);
    // Back tire
    drawCircle(0.016,0.015,vehiclePos-0.1, 0.06); 

    // Inner tires
    glColor3f(0.8, 0.8, 0.8);
    // Inner Front tire
    drawCircle(0.008,0.007,vehiclePos-0.2, 0.06);
    // Inner Back tire
    drawCircle(0.008,0.007,vehiclePos-0.1, 0.06);
}

void renderCarTwoModel(int isLightOn) {
    // upper body
    drawRectangle(vehiclePos-0.82,0.11, vehiclePos-0.78,0.08, vehiclePos-0.92,0.08, vehiclePos-0.88,0.11, 0, 0.56, 0.67);
    // lower body
    drawRectangle(vehiclePos-0.93,0.065, vehiclePos-0.93,0.085, vehiclePos-0.77,0.085, vehiclePos-0.77,0.065, 0, 0.56, 0.67);
    
    // Enable car lights during dawn/night
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
    // Front tire
    drawCircle(0.016,0.015,vehiclePos-0.80, 0.06);
    // Back tire
    drawCircle(0.016,0.015,vehiclePos-0.90, 0.06);

    // Inner tires
    glColor3f(0.8, 0.8, 0.8);
    // Inner Front tire
    drawCircle(0.008,0.007,vehiclePos-0.80, 0.06);
    // Inner Back tire
    drawCircle(0.008,0.007,vehiclePos-0.90, 0.06);
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

// Render buildings
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

// Render title screen buildings
void renderTitleScreenObjects(float windowR, float windowG, float windowB) {
    // Sun
    glColor3f(1.00, 0.63, 0.18);
    drawCircle(0.0255, 0.02, 0.745, 0.325);

    // Cloud
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.5, 0.5, 0.5, 0.4);
    drawCircle(0.025, 0.025, 0.66, 0.28);
    drawCircle(0.025, 0.025, 0.69, 0.28);
    drawCircle(0.025, 0.025, 0.72, 0.28);
    drawCircle(0.025, 0.025, 0.69, 0.30);
    glDisable(GL_BLEND);

    // 1st building
    // Building background
    drawRectangle(-0.03f, -0.05f, -0.03f, 0.19f, 0.05f, 0.19f, 0.05f, -0.05f, 1, 0.35, 0.69);
    // Inner building shade
    drawRectangle(-0.02f, -0.05f, -0.02f, 0.18f, 0.04f, 0.18f, 0.04f, -0.05f, 0.77, 0.27, 0.53);
    // Building sideline
    drawRectangle(-0.05f, -0.05f, -0.05f, 0.17f, -0.03f, 0.19f, -0.03f, -0.05f, 0.49, 0, 0.26);
    // Building windows
    for(float i=-0.02; i<0.16; i+=0.02) {
        drawRectangle(-0.01f, i, -0.01f, i+0.01, 0.0055f, i+0.01, 0.0055f, i, windowR, windowG, windowB);
    }
    for(float i=-0.02; i<0.16; i+=0.02) {
        drawRectangle(0.0155f, i, 0.0155f, i+0.01, 0.03f, i+0.01, 0.03f, i, windowR, windowG, windowB);
    }

    // 2nd building
    // Building background
    drawRectangle(0.07f, -0.05f, 0.07f, 0.13f, 0.15f, 0.13f, 0.15f, -0.05f, 0.4, 0.4, 0.4);
    // Inner building shade
    drawRectangle(0.08f, -0.05f, 0.08f, 0.12f, 0.14f, 0.12f, 0.14f, -0.05f, 0.26, 0.26, 0.26);
    // Building sideline
    drawRectangle(0.05f, -0.05f, 0.05f, 0.11f, 0.07f, 0.13f, 0.07f, -0.05f, 0.14, 0.14, 0.14);
    // Building windows
    for(float i=-0.02; i<0.11; i+=0.02) {
        drawRectangle(0.09f, i, 0.09f, i+0.01, 0.1055f, i+0.01, 0.1055f, i, windowR, windowG, windowB);
    }
    for(float i=-0.02; i<0.11; i+=0.02) {
        drawRectangle(0.1155f, i, 0.1155f, i+0.01, 0.13f, i+0.01, 0.13f, i, windowR, windowG, windowB);
    }

    // 3rd building
    // Building background
    drawRectangle(0.17f, -0.05f, 0.17f, 0.09f, 0.25f, 0.09f, 0.25f, -0.05f, 1, 0.56, 0.33);
    // Inner building shade
    drawRectangle(0.18f, -0.05f, 0.18f, 0.08f, 0.24f, 0.08f, 0.24f, -0.05f, 0.7, 0.37, 0.2);
    // Building sideline
    drawRectangle(0.15f, -0.05f, 0.15f, 0.07f, 0.17f, 0.09f, 0.17f, -0.05f, 0.48, 0.16, 0);
    //Building windows
    for(float i=-0.02; i<0.07; i+=0.02) {
        drawRectangle(0.19f, i, 0.19f, i+0.01, 0.2055f, i+0.01, 0.2055f, i, windowR, windowG, windowB);
    }
    for(float i=-0.02; i<0.07; i+=0.02) {
        drawRectangle(0.2155f, i, 0.2155f, i+0.01, 0.23f, i+0.01, 0.23f, i, windowR, windowG, windowB);
    }

    // 4th building
    // Building background
    drawRectangle(0.55f, -0.05f, 0.55f, 0.09f, 0.63f, 0.09f, 0.63f, -0.05f, 1.00, 0.13, 0.13);
    // Inner building shade
    drawRectangle(0.56f, -0.05f, 0.56f, 0.08f, 0.62f, 0.08f, 0.62f, -0.05f, 0.72, 0.00, 0.00);
    // Building sideline
    drawRectangle(0.63f, -0.05f, 0.63f, 0.09f, 0.65f, 0.07f, 0.65f, -0.05f, 0.52, 0.00, 0.00);
    // Building windows
    for(float i=-0.02; i<0.07; i+=0.02) {
        drawRectangle(0.57f, i, 0.57f, i+0.01, 0.5855f, i+0.01, 0.5855f, i, windowR, windowG, windowB);
    }
    for(float i=-0.02; i<0.07; i+=0.02) {
        drawRectangle(0.5955f, i, 0.5955f, i+0.01, 0.61f, i+0.01, 0.61f, i, windowR, windowG, windowB);
    }

    // 5th building
    // Building background
    drawRectangle(0.65f, -0.05f, 0.65f, 0.13f, 0.73f, 0.13f, 0.73f, -0.05f, 0.56, 0.29, 1);
    // Inner building shade
    drawRectangle(0.66f, -0.05f, 0.66f, 0.12f, 0.72f, 0.12f, 0.72f, -0.05f, 0.38, 0.15, 0.74);
    // Building sideline
    drawRectangle(0.73f, -0.05f, 0.73f, 0.13f, 0.75f, 0.11f, 0.75f, -0.05f, 0.12, 0, 0.32);
    // Building windows
    for(float i=-0.02; i<0.11; i+=0.02) {
        drawRectangle(0.67f, i, 0.67f, i+0.01, 0.6855f, i+0.01, 0.6855f, i, windowR, windowG, windowB);
    }
    for(float i=-0.02; i<0.11; i+=0.02) {
        drawRectangle(0.6955f, i, 0.6955f, i+0.01, 0.71f, i+0.01, 0.71f, i, windowR, windowG, windowB);
    }

    // 6th building
    // Building background
    drawRectangle(0.75f, -0.05f, 0.75f, 0.19f, 0.83f, 0.19f, 0.83f, -0.05f, 0.2, 0.5, 0.0);
    // Inner building shade
    drawRectangle(0.76f, -0.05f, 0.76f, 0.18f, 0.82f, 0.18f, 0.82f, -0.05f, 0.2, 0.4, 0.0);
    // Building sideline
    drawRectangle(0.83f, -0.05f, 0.83f, 0.19f, 0.85f, 0.17f, 0.85f, -0.05f, 0.2, 0.2, 0.0);
    // Building windows
    for(float i=-0.02; i<0.16; i+=0.02) {
        drawRectangle(0.77f, i, 0.77f, i+0.01, 0.7855f, i+0.01, 0.7855f, i, windowR, windowG, windowB);
    }
    for(float i=-0.02; i<0.16; i+=0.02) {
        drawRectangle(0.7955f, i, 0.7955f, i+0.01, 0.81f, i+0.01, 0.81f, i, windowR, windowG, windowB);
    }
}