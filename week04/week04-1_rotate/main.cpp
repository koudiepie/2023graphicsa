#include <GL/glut.h>
float angle = 0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
 }
 int main(int argc, char *argv[])//main()主函式 進階版
 {
    glutInit(&argc,argv);//把參數送給glutInit初始化
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//雙緩衝區+3D深度功能
    glutCreateWindow("week04");//開GLUT視窗

    glutDisplayFunc(display);//顯示用的函式
    glutIdleFunc(display);

    glutMainLoop();
 }
