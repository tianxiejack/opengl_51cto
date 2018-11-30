#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "freetype.hpp"

FreeTypeFont*	_font;
FreeTypeFont*	_font43;

int _width = 800;
int _height = 600;

#define M_PI (3.14159265358979323846)

typedef struct float3
{
    float   x,y,z;
    float   w;
}float3_t;

float3_t  _circle[360*3];

void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,_width,_height);

#if 1
       //! 指定以下的操作针对投影矩阵
       glMatrixMode(GL_PROJECTION);
       //! 将投影举证清空成单位矩阵
       glLoadIdentity();
       glOrtho(0,_width,_height,0,-100,100);

       float   cx  =   100;
       float   cy  =   100;
       float   cz  =   0;
       float   r   =   80;

       glColor3f(1,1,1);

       for (int i = 0 ;i < 360 ; ++ i)
       {
           _circle[i * 3 + 0].x    =  cx;
           _circle[i * 3 + 0].y    =  cy;
           _circle[i * 3 + 0].z    =  cz;

           _circle[i * 3 + 1].x    =  (float)cos((double)i * M_PI/180) * r + cx;
           _circle[i * 3 + 1].y    =  (float)sin((double)i * M_PI/180) * r + cy;
           _circle[i * 3 + 1].z    =  cz;

           _circle[i * 3 + 2].x    =  (float)cos((double)(i + 1) * M_PI/180) * r + cx;
           _circle[i * 3 + 2].y    =  (float)sin((double)(i + 1) * M_PI/180) * r + cy;
           _circle[i * 3 + 2].z    =  cz;
       }
       glEnableClientState(GL_VERTEX_ARRAY);
       glVertexPointer(3,GL_FLOAT,sizeof(float3_t),_circle);
       glDrawArrays(GL_TRIANGLES,0,360 * 3);
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
