
/*
 *  This is a part of example of opengl
 *  File: example1.c
 *  A simple glut framework.
 *
 *  Written 2011,2012 by fU9ANg
 *  E-mail: bb.newlife@gmail.com
 */

#ifdef  __APPLE__
#   include <glut/glut.h>
#else
#   ifdef  _WIN32
#   include <windows.h>
#   include "gl/gl.h"
#   include "gl/glu.h"
#   include "gl/glut.h"
#   endif
#   include <GL/gl.h>
#   include <GL/glu.h>
#   include <GL/glut.h>
#endif

/*
=====================
  DrawScene
=====================
*/
void
DrawScene (void)
{
    // Clear background color
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity ();

    // Set Our Camera
    gluLookAt (0,0,10,  0,0,0,  0,1,0);

    // Draw a triangle
    glBegin (GL_TRIANGLES);
        glVertex3f ( 0, 1, 0);
        glVertex3f (-1, 0, 0);
        glVertex3f ( 1, 0, 0);
    glEnd ();

    glutSwapBuffers ();
}

/*
=====================
  InitOpenGL
=====================
*/
void
InitOpenGL (void)
{
    glClearColor (0.0f, 1.0f, 1.0f, 1.0f);
    glColor3f (1.0f, 0.0f, 0.0f);
}

/*
=====================
  SizeOpenGL
=====================
*/
void
SizeOpenGL (int width, int height)
{
    if (height == 0)
    {
        height  = 1;
    }

    glViewport (0, 0, width, height);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();

    gluPerspective (45.0f, (GLfloat)width / (GLfloat)height, 1, 1000.0f);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

/*
=====================
  main (let's go)
=====================
*/
int
main (int argc, char **argv)
{
    glutInit (&argc, argv);
    // glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow ("Example1 -- OpenGL");
    glutDisplayFunc (DrawScene);
    glutReshapeFunc (SizeOpenGL);
    
    InitOpenGL ();

    glutMainLoop ();

    return (0);
}
