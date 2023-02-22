#include <GL/glut.h>
void display()
{
    glColor3f(247/255.0,247/255.0,247/255.0);
    glBegin(GL_POLYGON);
        glVertex2f(1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f(1,-1);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3f(1,0,0); glVertex2f(0, 1);
        glColor3f(0,1,0); glVertex2f(-1,-1);
        glColor3f(0,0,1); glVertex2f(1,-1);
    glEnd();
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");
	glutDisplayFunc(display);
	glutMainLoop();
}
