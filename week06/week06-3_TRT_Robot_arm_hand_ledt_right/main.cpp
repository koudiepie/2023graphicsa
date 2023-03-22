#include <GL/glut.h>

float angle = 0;

void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
 void display()

 {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();//右手臂
        glTranslatef(0.25,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.25,0,0);
        drawHand();
        glPushMatrix();//右手肘
            glTranslatef(0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.25,0,0);
            drawHand();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();//左手臂
        glTranslatef(-0.25,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.25,0,0);
        drawHand();
        glPushMatrix();//左手肘
            glTranslatef(-0.25,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);
            drawHand();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();

    angle++;

 }

 int main(int argc, char *argv[])//main()主函式 進階版

 {

    glutInit(&argc,argv);//把參數送給glutInit初始化

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能

    glutCreateWindow("week06");//開GLUT視窗



    glutDisplayFunc(display);//顯示用的函式

    glutIdleFunc(display);



    glutMainLoop();

 }

