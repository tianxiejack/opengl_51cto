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
    float   r,g,b;
};

Vertex  _circle[360];

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


       float   cx  =   100;
       float   cy  =   100;
       float   cz  =   0;
       float   r   =   80;
       //         x = cos(@) * r + centerx
       //         y = sin(@) * r + centery

       for (int i = 0 ;i < 360 ; ++ i)
       {
           _circle[i].x    =   cos(double(i) * M_PI / 180) * r + cx;
           _circle[i].y    =   sin(double(i) * M_PI / 180) * r + cy;
           _circle[i].z    =   cz;
           _circle[i].r    =   1;
           _circle[i].g    =   1;
           _circle[i].b    =   1;
       }


       glColor3f(1,0,1);
       glEnableClientState(GL_VERTEX_ARRAY);
       glEnableClientState(GL_COLOR_ARRAY);
       glVertexPointer(3,GL_FLOAT,sizeof(Vertex),_circle);
       glColorPointer(3,GL_FLOAT,sizeof(Vertex),&_circle[0].r);
       glDrawArrays(GL_LINE_LOOP,0, sizeof(_circle)/ sizeof(_circle[0]));


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
