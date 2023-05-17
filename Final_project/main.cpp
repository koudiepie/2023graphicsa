#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {0, 1, 1, 1};
int ID=3;//0�Y1��2�W���u3�U���u
void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    ///if(key=='0') show[0] = !show[0];
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}

FILE * fout = NULL;
FILE * fin = NULL;
float teapotX=0, teapotY=0;
float angle=0, angle2=0, angle3=0;
void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);
        if(body==NULL){
            body = glmReadOBJ("model/body.obj");
            head = glmReadOBJ("model/head.obj");
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");

            //glmUnitize(body);
        }
        if(ID==0) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID==1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1]) glmDraw(body, GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(-1.186666, +0.380000, 0);
            glRotatef(angle, 0, 0, 1);
            glTranslatef(1.186666, -0.380000, 0);
            if(ID==2) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);

            glPushMatrix();
                //glTranslatef(teapotX, teapotY, 0);
                glTranslatef(-1.953333, +0.120001, 0);
                glRotatef(angle, 0, 0, 1);
                glTranslatef(1.953333, -0.120001, 0);
                if(ID==3) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
            glPopMatrix();

        glPopMatrix();

    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();

}
int oldX = 0, oldY = 0;
void motion(int x, int y){
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    angle = x;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        teapotX = (x-150)/150.0;
        teapotY = (150-y)/150.0;
        if(fout==NULL) fout = fopen("file4.txt","w");
        fprintf(fout, "%f %f\n", teapotX, teapotY);
    }
    display();
}
//void keyboard(unsigned char key,int x, int y)
//{
//    if(fin==NULL){
//        fclose(fout);
//        fin = fopen("file4.txt","r");
//    }
//    fscanf(fin, "%f %f", &teapotX, &teapotY);
//    display();
//}
int main(int argc, char *argv[])//main()�D�禡 �i����

{

    glutInit(&argc,argv);//��Ѽưe��glutInit��l��

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);//���w�İ�+3D�`�ץ\��

    glutCreateWindow("week12");//�}GLUT����



    glutDisplayFunc(display);//��ܥΪ��禡

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);



    glutMainLoop();

}
