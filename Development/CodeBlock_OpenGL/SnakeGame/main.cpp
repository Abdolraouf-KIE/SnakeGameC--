#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"

#define FPS 5


void display_callback();
void timer_callback(int);
void reshape_callback(int,int);
void keyboard_callback(int, int,int);
extern short sDirection;
void endGame();
extern bool gameOver;
extern int score;

void init()
{
    glClearColor(0,0,0,1.0);
    initGrid(COLUMNS,ROWS);

}

int main (int argc, char **argv)
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500,500);
    glutCreateWindow("SNAKE");

    glutReshapeFunc(reshape_callback);
    glutDisplayFunc(display_callback);
    glutTimerFunc(0,timer_callback,0); //this only runs once with a delay of 0 milisecs. To use for showing frames we recursivly call it.

    //glutKeyboardFunc();
    glutSpecialFunc(keyboard_callback);

    init();
    glutMainLoop();
    return 0;
}

void display_callback ()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    if (gameOver)
    {
        endGame();
    }
    drawSnake();
    drawFood();
    glutSwapBuffers();
}

void reshape_callback(int w,int h)
{
    glViewport(0, 0, (GLsizei)w , (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,ROWS,0.0,COLUMNS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void keyboard_callback(int key,int,int)
{
    switch(key)
    {
        case GLUT_KEY_RIGHT:
            if (sDirection!=LEFT)
                sDirection=RIGHT;
            break;
        case GLUT_KEY_LEFT:
            if (sDirection!=RIGHT)
                sDirection=LEFT;
            break;
        case GLUT_KEY_UP:
            if (sDirection!=DOWN)
                sDirection=UP;
            break;
        case GLUT_KEY_DOWN:
            if (sDirection!=UP)
                sDirection=DOWN;
            break;
    }
}

void endGame()
{
    //TODO: add a message box using gtkmm. gtkmm is opp and here was are using nested function calls so it is hard to do.
    HelloWorld helloworld;

    std::cout << "\n*****Score: " <<score << std::endl;
    //Shows the window and returns when it is closed.
    exit(0); //app->run(helloworld)
}
