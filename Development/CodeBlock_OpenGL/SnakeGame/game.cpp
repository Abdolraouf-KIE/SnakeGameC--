#include <GL/gl.h>
#include <GL/glut.h>
#include "game.h"



int gridX,gridY;
int posX[MAX_LENGTH]={20,20,20,20,20}, posY[MAX_LENGTH]={20,19,18,17,16}; //starting the snake with size 4 and max length of 60
int foodX=10, foodY=10;
short sDirection=RIGHT;
bool gameOver=false;
bool newFood=true;
int score=0;
int snake_length=5;

HelloWorld::HelloWorld()
: m_button("Hello World")   // creates a new button with label "Hello World".
{
  // Sets the border width of the window.
  set_border_width(10);

  // This packs the button into the Window (a container).
  add(m_button);

  // The final step is to display this newly created widget...
  m_button.show();
}

HelloWorld::~HelloWorld()
{
}

void initGrid(int x, int y)
{
    gridX=x;
    gridY=y;
}

void drawGrid()
{
    for(int x=0; x<gridX;x++)
    {
        for(int y=0; y<gridY; y++)
        {
            unit(x,y);
        }
    }
}

void unit(int x, int y)
{
    if(x==0||y==0||x==gridX-1||y==gridY-1)
    {
        glLineWidth(3.0);
        glColor3f(1.0,0.0,0.0);
    }else{
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);
    }
    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);
    glEnd();
}

void drawSnake()
{
    for (int i=snake_length-1; i>0;i--)
    {
        posX[i]=posX[i-1];
        posY[i]=posY[i-1];
    }
    switch(sDirection)
    {
        case RIGHT:
            posX[0]++;
            if (posX[0]==gridX-1)
                gameOver=true;
            break;
        case LEFT:
            posX[0]--;
            if (posX[0]==0)
                gameOver=true;
            break;
        case UP:
            posY[0]++;
            if (posY[0]==gridY-1)
                gameOver=true;
            break;
        case DOWN:
            posY[0]--;
            if (posY[0]==0)
                gameOver=true;
            break;
    }

    for(int i=1; i<snake_length;i++)
    {
        if (posX[i]==posX[0] && posY[i]==posY[0])
            gameOver=true;
    }

    for(int i=0;i<snake_length;i++)
    {
        if(i==0)
        {glColor3f(0,1,0);}
        else
        {glColor3f(1,0,0);}
        glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
    }

    if (posX[0]==foodX && posY[0]==foodY)
    {   newFood=true;
        snake_length++;
        score++;
    }
    if (posX[0]==0 || posX[0]==gridX-1 || posY[0]==0 || posY[0]==gridY-1)
        gameOver=true;
}

void MessageBox()
{

}

void randPos()
{
    srand(time(NULL));
    foodX=1 + rand()%(COLUMNS -2);
    foodY=1 + rand()%(ROWS -2);
}

void drawFood()
{
    if(newFood)
    {
        randPos();
        glColor3f(1,0,0);
        std::cout << "foodX: " <<foodX << std::endl;
        std::cout << "foodY: " <<foodY << std::endl;
        newFood=false;
    }
    glRectd(foodX,foodY,foodX+1,foodY+1);
}
