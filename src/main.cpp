#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "freetype.hpp"

FreeTypeFont*	_font;
FreeTypeFont*	_font43;

int _width = 800;
int _height = 600;


struct Vertex
{
    unsigned char r,g,b,a;
    float x, y, z;
};

Vertex cubeVertices[] =
{
    { 255,0,0,255, -1.0f,-1.0f, 1.0f },
    { 255,0,0,255, 1.0f,-1.0f, 1.0f },
    { 255,0,0,255, 1.0f, 1.0f, 1.0f },
    { 255,0,0,255, -1.0f, 1.0f, 1.0f },

    { 0,255,0,255, -1.0f,-1.0f,-1.0f },
    { 0,255,0,255, -1.0f, 1.0f,-1.0f },
    { 0,255,0,255, 1.0f, 1.0f,-1.0f },
    { 0,255,0,255, 1.0f,-1.0f,-1.0f },

    { 0,0,255,255, -1.0f, 1.0f,-1.0f },
    { 0,0,255,255, -1.0f, 1.0f, 1.0f },
    { 0,0,255,255, 1.0f, 1.0f, 1.0f },
    { 0,0,255,255, 1.0f, 1.0f,-1.0f },

    { 0,255,255,255, -1.0f,-1.0f,-1.0f },
    { 0,255,255,255, 1.0f,-1.0f,-1.0f },
    { 0,255,255,255, 1.0f,-1.0f, 1.0f },
    { 0,255,255,255, -1.0f,-1.0f, 1.0f },

    { 255,0,255,255, 1.0f,-1.0f,-1.0f },
    { 255,0,255,255, 1.0f, 1.0f,-1.0f },
    { 255,0,255,255, 1.0f, 1.0f, 1.0f },
    { 255,0,255,255, 1.0f,-1.0f, 1.0f },

    { 255,255,255,255, -1.0f,-1.0f,-1.0f },
    { 255,255,255,255, -1.0f,-1.0f, 1.0f },
    { 255,255,255,255, -1.0f, 1.0f, 1.0f },
    { 255,255,255,255, -1.0f, 1.0f,-1.0f }
};



void myDisplay(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0,0,_width,_height);
#if 1
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,double(_width)/double(_height),0.1,1000);

	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
	glTranslatef(0,0,-3);
	 	
	//glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3,GL_FLOAT,         sizeof(Vertex),     &cubeVertices[0].x);
	glColorPointer(4,GL_UNSIGNED_BYTE,  sizeof(Vertex),     cubeVertices);

	glDrawArrays( GL_QUADS, 0, 24 );
#endif
	_font->begin(_width,_height);
	_font->drawText(10,100,0,Rgba(125,255,255),L"abc123这边就是可以",0,0,0);
	_font->end();

	glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE); // 修改了参数为GLUT_DOUBLE
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(_width, _height);
    glutCreateWindow("123456789");    // 改了窗口标题

    _font   =   new FreeTypeFont();
    _font->create("simsun.ttc",16,512,512);

    _font43 =   new FreeTypeFont();
    _font43->create("simsun.ttc",40,512,512);




    glutDisplayFunc(&myDisplay);
    glutMainLoop();
    return 0;
}
