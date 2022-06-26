//radius_x,radius_y,certre_position_x,centre_position_y
void renderCircle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy) {
    glBegin(GL_POLYGON);
    for(int i=0; i<180; i++) {
        float angle = 4.0f * 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

// Render background grass
void renderGrass(float grassR, float grassG, float grassB) { 
    glBegin(GL_QUADS);
        glColor3f(grassR, grassG, grassB);
        glVertex3f(-0.05f, 0.0f, 0.0f);
        glVertex3f(-0.05f, 0.15f, 0.0f);
        glVertex3f(0.85f, 0.15f, 0.0f);
        glVertex3f(0.85f, 0.00f, 0.0f);
    glEnd();
}

// Render clouds
void renderClouds(float cloudR, float cloudG, float cloudB, float cloudA) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    // Cloud 1
    glColor4f(cloudR, cloudG, cloudB, cloudA);
    renderCircle(0.03,0.03,cloudOneSpeed-0.01, 0.28);
    renderCircle(0.03,0.03,cloudOneSpeed-0.04, 0.28);
    renderCircle(0.03,0.03,cloudOneSpeed-0.07, 0.28);
    renderCircle(0.03,0.03,cloudOneSpeed-0.04, 0.30);
    
    // Cloud 2
    renderCircle(0.03,0.03,cloudTwoSpeed-0.71, 0.32);
    renderCircle(0.03,0.03,cloudTwoSpeed-0.74, 0.32);
    renderCircle(0.03,0.03,cloudTwoSpeed-0.77, 0.32);
    renderCircle(0.03,0.03,cloudTwoSpeed-0.74, 0.34);

    // Cloud 3
    renderCircle(0.03,0.03,cloudThreeSpeed-0.41, 0.36);
    renderCircle(0.03,0.03,cloudThreeSpeed-0.44, 0.36);
    renderCircle(0.03,0.03,cloudThreeSpeed-0.47, 0.36);
    renderCircle(0.03,0.03,cloudThreeSpeed-0.44, 0.38);

    glDisable(GL_BLEND);
}

// Render sky
void renderSky(float skyR, float skyG, float skyB) {
    glBegin(GL_QUADS);
        glColor3f(skyR, skyG, skyB);
        glVertex3f(-0.05f, 0.15f, 0.0f);
        glVertex3f(-0.05f, 0.40f, 0.0f);
        glVertex3f(0.85f, 0.40f, 0.0f);
        glVertex3f(0.85f, 0.15f, 0.0f);
    glEnd();
}

// Render planet
void renderPlanet(float r, float g, float b) {
    glColor3f(r, g, b);
    renderCircle(0.055, 0.05, sunX-0.05, sunY+0.3);
}

void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b) {
    // Rectangle order
    // 1> Bottom Left (x1, y1) 
    // 2> Top Left (x2, y2)
    // 3> Top Right (x3, y3)
    // 4> Bottom Right (x4, y4)
    // x> Colors (r, g, b)

    glColor3f (r, g, b);
    glBegin(GL_QUADS);
        glVertex3f(x1, y1, 0.0f);
        glVertex3f(x2, y2, 0.0f);
        glVertex3f(x3, y3, 0.0f);
        glVertex3f(x4, y4, 0.0f);
    glEnd();
}

// Render roads
void renderRoads() {
    glBegin(GL_QUADS);
        //black font Road here
        glColor3f (0.4, 0.4, 0.4);
        glVertex3f(-0.05f, -0.05f, 0.0f);
        glVertex3f(-0.05f, 0.03f, 0.0f);
        glVertex3f(0.90f, 0.03f, 0.0f);
        glVertex3f(0.90f, -0.05f, 0.0f);

        // road divider 1
        glColor3f (1.0, 1.0, 1.0);
        glVertex3f(-0.05f, -0.01f, 0.0f);
        glVertex3f(-0.05f, 0.0f, 0.0f);
        glVertex3f(-0.02f, 0.0f, 0.0f);
        glVertex3f(-0.02f, -0.01f, 0.0f);
        // road divider 2
        glVertex3f(0.03f, 0.0f, 0.0f);
        glVertex3f(0.03f, -0.01f, 0.0f);
        glVertex3f(0.08f, -0.01f, 0.0f);
        glVertex3f(0.08f, 0.0f, 0.0f);

        // road divider 3
        glVertex3f(0.13f, 0.0f, 0.0f);
        glVertex3f(0.13f, -0.01f, 0.0f);
        glVertex3f(0.18f, -0.01f, 0.0f);
        glVertex3f(0.18f, 0.0f, 0.0f);

        // road divider 3
        glVertex3f(0.23f, 0.0f, 0.0f);
        glVertex3f(0.23f, -0.01f, 0.0f);
        glVertex3f(0.28f, -0.01f, 0.0f);
        glVertex3f(0.28f, 0.0f, 0.0f);

        // road divider 4
        glVertex3f(0.33f, 0.0f, 0.0f);
        glVertex3f(0.33f, -0.01f, 0.0f);
        glVertex3f(0.38f, -0.01f, 0.0f);
        glVertex3f(0.38f, 0.0f, 0.0f);
        // road divider 5
        glVertex3f(0.43f, 0.0f, 0.0f);
        glVertex3f(0.43f, -0.01f, 0.0f);
        glVertex3f(0.48f, -0.01f, 0.0f);
        glVertex3f(0.48f, 0.0f, 0.0f);

        // road divider 3
        glVertex3f(0.53f, 0.0f, 0.0f);
        glVertex3f(0.53f, -0.01f, 0.0f);
        glVertex3f(0.58f, -0.01f, 0.0f);
        glVertex3f(0.58f, 0.0f, 0.0f);

        // road divider 3
        glVertex3f(0.63f, 0.0f, 0.0f);
        glVertex3f(0.63f, -0.01f, 0.0f);
        glVertex3f(0.68f, -0.01f, 0.0f);
        glVertex3f(0.68f, 0.0f, 0.0f);

        // road divider 3
        glVertex3f(0.73f, 0.0f, 0.0f);
        glVertex3f(0.73f, -0.01f, 0.0f);
        glVertex3f(0.78f, -0.01f, 0.0f);
        glVertex3f(0.78f, 0.0f, 0.0f);

        // road divider 3
        glVertex3f(0.83f, 0.0f, 0.0f);
        glVertex3f(0.83f, -0.01f, 0.0f);
        glVertex3f(0.88f, -0.01f, 0.0f);
        glVertex3f(0.88f, 0.00f, 0.0f);
    glEnd();

    // Road edges top
    drawRectangle(-0.05f,0.03f, -0.05f,0.04f, 0.90f,0.04f, 0.90f,0.03f, 0.2, 0.2, 0.2);
    // Road edges top stripes
    drawRectangle(-0.04f,0.03f, -0.04f,0.04f, -0.02f,0.04f, -0.02f,0.03f, 1.0, 1.0, 1.0);

    // Road edges bottom
    drawRectangle(-0.06f,-0.05f, -0.05f,-0.04f, 0.90f,-0.04f, 0.90f,-0.05f, 0.2, 0.2, 0.2);
}

void renderCarOneModel() {
    //upper body
    glBegin(GL_QUADS); 
        glColor3f(1.0,0.0,0);
        glVertex3f(vehiclePos+0.01,0.06,0);
        glVertex3f(vehiclePos+0.01,0.02,0);
        glVertex3f(vehiclePos+0.10,0.02,0);
        glVertex3f(vehiclePos+0.10,0.06,0);
    glEnd();
    // lower body
    glBegin(GL_QUADS); 
        glColor3f(1.0,0.0,0);
        glVertex3f(vehiclePos-0.05,-0.015,0);
        glVertex3f(vehiclePos-0.05,0.025,0);
        glVertex3f(vehiclePos+0.16,0.025,0);
        glVertex3f(vehiclePos+0.16,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
        glVertex3f(vehiclePos+0.01,0.02,0);
        glVertex3f(vehiclePos+0.01,0.06,0);
        glVertex3f(vehiclePos-0.01,0.02,0);

        glVertex3f(vehiclePos+0.10,0.02,0);
        glVertex3f(vehiclePos+0.10,0.06,0);
        glVertex3f(vehiclePos+0.125,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
        //window 1
        glColor3f(0.0,0.0,0);
        glVertex3f(vehiclePos+0.01,0.03,0);
        glVertex3f(vehiclePos+0.025,0.05,0);
        glVertex3f(vehiclePos+0.05,0.05,0);
        glVertex3f(vehiclePos+0.05,0.03,0);
        //windows 2
        glVertex3f(vehiclePos+0.06,0.03,0);
        glVertex3f(vehiclePos+0.06,0.05,0);
        glVertex3f(vehiclePos+0.08,0.05,0);
        glVertex3f(vehiclePos+0.095,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    renderCircle(0.02,0.02,vehiclePos+0.0, -0.01); // Front tyre
    renderCircle(0.02,0.02,vehiclePos+0.10, -0.01); // Back tyre
}

void renderCarTwoModel() {
    glBegin(GL_QUADS); //upper body
        glColor3f(0.255,0.102,0.255);
        glVertex3f(vehiclePos-0.31,0.06,0);
        glVertex3f(vehiclePos-0.31,0.02,0);
        glVertex3f(vehiclePos-0.40,0.02,0);
        glVertex3f(vehiclePos-0.40,0.06,0);
    glEnd();
    glBegin(GL_QUADS); // lower body
        glVertex3f(vehiclePos-0.46,-0.015,0);
        glVertex3f(vehiclePos-0.46,0.025,0);
        glVertex3f(vehiclePos-0.25,0.025,0);
        glVertex3f(vehiclePos-0.25,-0.015,0);
    glEnd();
    //first car body in back side
    glBegin(GL_TRIANGLES);
        glVertex3f(vehiclePos-0.31,0.02,0);
        glVertex3f(vehiclePos-0.31,0.06,0);
        glVertex3f(vehiclePos-0.29,0.02,0);

        glVertex3f(vehiclePos-0.40,0.02,0);
        glVertex3f(vehiclePos-0.40,0.06,0);
        glVertex3f(vehiclePos-0.425,0.02,0);
    glEnd();

    glBegin(GL_QUADS);
        //window 1
        glColor3f(0.0,0.0,0);
        glVertex3f(vehiclePos-0.31,0.03,0);
        glVertex3f(vehiclePos-0.325,0.05,0);
        glVertex3f(vehiclePos-0.35,0.05,0);
        glVertex3f(vehiclePos-0.35,0.03,0);
        //windows 2
        glVertex3f(vehiclePos-0.36,0.03,0);
        glVertex3f(vehiclePos-0.36,0.05,0);
        glVertex3f(vehiclePos-0.38,0.05,0);
        glVertex3f(vehiclePos-0.395,0.03,0);
    glEnd();

    glColor3f(0.0,0.0,0);
    renderCircle(0.02,0.02,vehiclePos-0.30, -0.01); //tier 1
    renderCircle(0.02,0.02,vehiclePos-0.40, -0.01); //tier 2
}

void renderBusModel() {
    glBegin(GL_QUADS); //lower body
        glColor3f(0.0 ,0.0, 1.0);
        glVertex3f(vehiclePos-0.55,-0.02,0);
        glVertex3f(vehiclePos-0.55,0.05,0);
        glVertex3f(vehiclePos-0.75,0.05,0);
        glVertex3f(vehiclePos-0.75,-0.02,0);
        //upper body

        glVertex3f(vehiclePos-0.75,0.08,0);
        glVertex3f(vehiclePos-0.75,0.05,0);
        glVertex3f(vehiclePos-0.55,0.05,0);
        glVertex3f(vehiclePos-0.55,0.08,0);


        //windows 1
        glColor3f(1.0,1.0,1);
        glVertex3f(vehiclePos-0.56,0.02,0);
        glVertex3f(vehiclePos-0.56,0.07,0);
        glVertex3f(vehiclePos-0.59,0.07,0);
        glVertex3f(vehiclePos-0.59,0.02,0);
        //windows 2
        glColor3f(1.0,1.0,1);
        glVertex3f(vehiclePos-0.60,0.02,0);
        glVertex3f(vehiclePos-0.60,0.07,0);
        glVertex3f(vehiclePos-0.63,0.07,0);
        glVertex3f(vehiclePos-0.63,0.02,0);

        //windows 3
        glColor3f(1.0,1.0,1);
        glVertex3f(vehiclePos-0.64,0.02,0);
        glVertex3f(vehiclePos-0.64,0.07,0);
        glVertex3f(vehiclePos-0.67,0.07,0);
        glVertex3f(vehiclePos-0.67,0.02,0);
        //windows 4
        glColor3f(1.0,1.0,1);
        glVertex3f(vehiclePos-0.68,0.02,0);
        glVertex3f(vehiclePos-0.68,0.07,0);
        glVertex3f(vehiclePos-0.71,0.07,0);
        glVertex3f(vehiclePos-0.71,0.02,0);
        //windows 5
        glColor3f(1.0,1.0,1);
        glVertex3f(vehiclePos-0.72,0.02,0);
        glVertex3f(vehiclePos-0.72,0.07,0);
        glVertex3f(vehiclePos-0.735,0.07,0);
        glVertex3f(vehiclePos-0.735,0.02,0);
    glEnd();


    // tier1
    glColor3f(0.0,0.0,0);
    renderCircle(0.0225,0.0225,vehiclePos-0.60, -0.01); //tier 1
    renderCircle(0.0225,0.0225,vehiclePos-0.70, -0.01); //tier 2
}

// Render windows
void renderBuildings(float windowR, float windowG, float windowB) {
    /////////////////////////////////

    //shohid miner ground
    glBegin(GL_QUADS);
        glColor3f (1.0, 0.5, .0);
        glVertex3f(0.45f, 0.05f, 0.0f);
        glVertex3f(0.45f, 0.30f, 0.0f);
        glVertex3f(0.55f, 0.30f, 0.0f);
        glVertex3f(0.55f, 0.05f, 0.0f);

        glColor3f (0.6, 0.2, .0);
        glVertex3f(0.55f, 0.05f, 0.0f);
        glVertex3f(0.55f, 0.30f, 0.0f);
        glVertex3f(0.57f, 0.32f, 0.0f);
        glVertex3f(0.57f, 0.07f, 0.0f);

        glColor3f (0.2, 0.2, 1.0);
        glVertex3f(0.45f, 0.30f, 0.0f);
        glVertex3f(0.47f, 0.32f, 0.0f);
        glVertex3f(0.57f, 0.32f, 0.0f);
        glVertex3f(0.55f, 0.30f, 0.0f);
    glEnd();

    ////////////////////////////////
    glEnd();

}