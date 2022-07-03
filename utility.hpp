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