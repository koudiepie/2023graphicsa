#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
void display()

{

	//glutSolidTeapot( 0.3 );
	if (pmodel==NULL) {
	pmodel = glmReadOBJ("Al.obj");
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90);
	}
	glmDraw(pmodel, GLM_MATERIAL);

	glutSwapBuffers();
}
int main(int argc, char *argv[])
{

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Week10");

	glutDisplayFunc(display);

	glutMainLoop();

}
