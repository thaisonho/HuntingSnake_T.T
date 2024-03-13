#pragma once
#include "ConsoleWindow.h"
#include "Snake.h"
#include <iostream>

using namespace std;

void setTextColor(int color); // change text color inside box

void draw_rec(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width); // draw rectangle box

void draw_matchBoard(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, int &SCORE, int &LEVEL); // draw matchboard

void draw_infoBoard(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, int txtColor, int bg_color, int line_color); // draw info board

void draw_underline(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, string text, int value, int txtColor, int bg_color, int line_color); // draw box with text inside

void draw_obstacle(Point obs[], int obs_nums); // draw obstacle from obstacle initialized

//void draw_game(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obstacle[], int obs_nums); 

