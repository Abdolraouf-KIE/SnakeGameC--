#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define COLUMNS 40
#define ROWS 40

void initGrid(int, int);
void drawGrid();
void unit(int, int);
void drawSnake();

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <time.h>
#include <iostream>

void MessageBox();

#define RIGHT   1
#define LEFT    -1
#define UP      2
#define DOWN    -2
#define MAX_LENGTH 60

class HelloWorld : public Gtk::Window
{

public:
  HelloWorld();
  virtual ~HelloWorld();

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

void drawFood();

#endif // GAME_H_INCLUDED
