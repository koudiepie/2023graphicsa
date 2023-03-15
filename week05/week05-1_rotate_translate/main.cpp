#include <GL/glut.h>
float angle = 0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);//上色
    glPushMatrix();
        glTranslatef(0.8,0,0);
        glRotatef(angle,0,0,1);//改Z軸旋轉
        glutSolidTeapot(0.3);
    glPopMatrix();
    glColor3f(0,1,1);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glTranslatef(0.8,0,0);
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
