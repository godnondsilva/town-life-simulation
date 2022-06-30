// Handlers
void handleDisplay(); 
void handleKey(unsigned int, char, char);
void handleMenu(int);

// Render functions
void renderScene();
void renderObjects();
void renderGrass(float, float, float);
void renderClouds(float, float, float, float);
void renderPlanet(float, float, float);
void renderSky(float, float, float);
void renderBuildings(float, float, float);
void renderRoads();
void renderHorizon(float, float, float, float);
void renderCarOneModel(int);
void renderCarTwoModel(int);

// Render object functions
void renderDawn();
void renderMorning();
void renderEvening();
void renderNight();

// Render boxes and title screens
void renderSceneTitleBox();
void renderSceneTitle(float, float, char*);
void renderPauseDialogBox();
void renderPauseScreen();
void renderTitleScreen();

// Utility Functions
void displayString(float, float, char*, int);
void resetScene();
void lockPosition();

// Utility Drawing functions
void drawCircle(GLfloat, GLfloat, GLfloat, GLfloat);
void drawRectangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float, float, float);
void drawAlphaRectangle(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, float, float, float, float);   