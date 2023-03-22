#include <GL/glut.h>

float angle = 0;

 void display()

 {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glutSolidSphere(0.02,30,30);
    glutSolidTeapot(0.3);

    glPushMatrix();//手臂
        glTranslatef(0.45,0.15,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.45,-0.05,0);
        glutSolidTeapot(0.3);
        glPushMatrix();//手肘
            glTranslatef(0.45,0.15,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.45,-0.05,0);
            glutSolidTeapot(0.3);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();

    angle++;

 }

 int main(int argc, char *argv[])//main()主函式 進階版

 {

    glutInit(&argc,argv);//把參數送給glutInit初始化

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能

    glutCreateWindow("week05");//開GLUT視窗



    glutDisplayFunc(display);//顯示用的函式

    glutIdleFunc(display);



    glutMainLoop();

 }

