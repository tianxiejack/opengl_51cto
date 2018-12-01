#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "freetype.hpp"

FreeTypeFont*	_font;
FreeTypeFont*	_font43;

int _width = 800;
int _height = 600;

struct  Vertex
{
    float   x,y,z;
};

Vertex  _line[360];

void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,_width,_height);

#if 1

#define M_PI (3.14159265358979323846)
       //! 指定以下的操作针对投影矩阵
       glMatrixMode(GL_PROJECTION);
       //! 将投影举证清空成单位矩阵
       glLoadIdentity();
       glOrtho(0,_width,_height,0,-100,100);


       Vertex  vertex[]    =
       {
           {50,0,0},
           {100,50,0},

           {80,100,0},
           {60,100,0},
           {10,50,0},
       };
       glEnableClientState(GL_VERTEX_ARRAY);
       glVertexPointer(3,GL_FLOAT,sizeof(Vertex),vertex);
       glDrawArrays(GL_TRIANGLE_FAN,0, sizeof(vertex)/sizeof(vertex[0]));



#endif


	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE); // 修改了参数为GLUT_DOUBLE
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(_width, _height);
    glutCreateWindow("123456789");    // 改了窗口标题

    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
