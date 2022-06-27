// Handlers
void displayHandle(); 
void keyHandle(unsigned int, char, char);

// Drawing functions
void drawCircle(GLfloat, GLfloat, GLfloat, GLfloat);
void drawRectangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float, float, float);
void drawAlphaRectangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float, float, float, float);   

// Render functions
void renderScene();
void renderGrass(float, float, float);
void renderClouds(float, float, float, float);
void renderPlanet(float, float, float);
void renderSky(float, float, float);
void renderBuildings(float, float, float, float);
void renderRoads(float, float, float);
void renderHorizon();
void renderCarOneModel();
void renderCarTwoModel();
void renderPauseScreen();
void renderTitleScreen();

// Utility Functions
void displayString(int, int, char*, int);
void resetScene();