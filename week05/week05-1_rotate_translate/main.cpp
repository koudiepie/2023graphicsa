#include <GL/glut.h>
float angle = 0;
 void display()
 {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);//�W��
    glPushMatrix();
        glTranslatef(0.8,0,0);
        glRotatef(angle,0,0,1);//��Z�b����
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
 int main(int argc, char *argv[])//main()�D�禡 �i����
 {
    glutInit(&argc,argv);//��Ѽưe��glutInit��l��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��
    glutCreateWindow("week04");//�}GLUT����

    glutDisplayFunc(display);//��ܥΪ��禡
    glutIdleFunc(display);

    glutMainLoop();
 }
