#include <GL/glut.h>

float angle = 0;

 void display()

 {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //glutSolidSphere(0.02,30,30);
    glutSolidTeapot(0.3);

    glPushMatrix();//���u
        glTranslatef(0.45,0.15,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.45,-0.05,0);
        glutSolidTeapot(0.3);
        glPushMatrix();//��y
            glTranslatef(0.45,0.15,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.45,-0.05,0);
            glutSolidTeapot(0.3);
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();

    angle++;

 }

 int main(int argc, char *argv[])//main()�D�禡 �i����

 {

    glutInit(&argc,argv);//��Ѽưe��glutInit��l��

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��

    glutCreateWindow("week05");//�}GLUT����



    glutDisplayFunc(display);//��ܥΪ��禡

    glutIdleFunc(display);



    glutMainLoop();

 }

