#include <stdio.h>
#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除背景
    glPushMatrix();//備份矩陣
        //glTranslatef(X, Y, 0);
        //glutSolidTeapot( 0.3 );
    glPopMatrix();//還原矩陣

	glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    float X=(x-500)/500.0;
    float Y=-(y-500)/500.0;
    if(state==GLUT_DOWN){
        printf("    glVertex2f(%.3f, %.3f ;\n",X,Y);
    }
}
int main(int argc, char *argv[])

{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1000,1000);
	glutCreateWindow("week03");

	glutDisplayFunc(display);
	glutMouseFunc(mouse);

	glutMainLoop();

}
