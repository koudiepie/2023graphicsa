#include <GL/glut.h>
float angle = 0;
 void display()
 {
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(0.6,0,0);
        glRotatef(angle,0,1,0);
        glColor3f(2,1,0);
        glutSolidTeapot(0.3);

    glPopMatrix();
     glPushMatrix();
        glRotatef(angle,0,1,0);
        glTranslatef(0.6,0,0);
        glColor3f(0,1,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle++;
 }
 int main(int argc, char *argv[])//main()�D�禡 �i����
 {
    glutInit(&argc,argv);//��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��
    glutCreateWindow("week04");//�}GLUT����

    glutDisplayFunc(display);//��ܥΪ��禡
    glutIdleFunc(display);

    glutMainLoop();
 }
