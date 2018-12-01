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

char*   _pixel;

void SamplerSmooth()
{
    _pixel  =   new char[100 * 200 * 4];
    for (int i = 0 ; i < 100 * 200 * 4 ; ++ i)
    {
        _pixel[i]   =   rand()%255;
    }
}

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

        glColor3f(1,0,1);

        Vertex  rect[]  =
        {
            {10,    10,     0,  1,  0,  0},
            {110,   10,     0,  0,  1,  0},
            {10,    110,    0,  0,  0,  1},
            {110,   110,    0,  1,  0,  1},
        };
        glColor3f(1,0,1);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glVertexPointer(3,GL_FLOAT,sizeof(Vertex),rect);
        glColorPointer(3,GL_FLOAT,sizeof(Vertex),&rect[0].r);
        glDrawArrays(GL_TRIANGLE_STRIP,0,4);


        Vertex  rect1[]  =
        {
            {10,    10,     0,  1,  0,  0},
            {110,   10,     0,  0,  1,  0},
            {10,    110,    0,  0,  0,  1},
            {110,   110,    0,  1,  0,  1},
        };

        for (int i = 0 ;i < 4 ; ++ i )
        {
            rect1[i].x += 100;
        }

        glVertexPointer(3,GL_FLOAT,sizeof(Vertex),rect1);
        glColorPointer(3,GL_FLOAT,sizeof(Vertex),&rect1[0].r);
        glColor3f(0,0,1);
        glDrawArrays(GL_TRIANGLE_STRIP,0,4);

       glRasterPos2i(100,300);
       glDrawPixels(100,200,GL_RGBA,GL_UNSIGNED_BYTE,_pixel);





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

    SamplerSmooth();

    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
