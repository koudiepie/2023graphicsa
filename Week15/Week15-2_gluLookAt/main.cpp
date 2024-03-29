#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void reshape(int w, int h){

    glViewport(0, 0, w, h);///視窗裡會看到的2D範圍

    float ar = w / (float) h;///長寬比
    glMatrixMode(GL_PROJECTION);///切換成投影矩陣
    glLoadIdentity();///矩陣清空，還原成單位矩陣
    gluPerspective(60, ar, 0.01, 1000);

    glMatrixMode(GL_MODELVIEW);///切換成MODEL VIEW矩陣
    glLoadIdentity();///還原成單位矩陣
    gluLookAt(0,0,1, 0,0,0, 0,1,0);

    glutPostRedisplay();
}
float eyeX = 0, eyeY = 0;
void motion(int x, int y){
    eyeX = (x-150.0)/150.0;
    eyeY = (150.0-y)/150.0;
    glMatrixMode(GL_MODELVIEW);///切換成MODEL VIEW矩陣
    glLoadIdentity();///還原成單位矩陣
    gluLookAt(eyeX, eyeY, 1, 0,0,0, 0,1,0);
    glutPostRedisplay();
}
int main(int argc, char** argv)

{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week15");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(motion);

    glutMainLoop();

}
