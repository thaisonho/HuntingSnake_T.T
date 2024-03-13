#pragma once
#include <windows.h>
#include <iostream>
#include <conio.h>
#include "Snake.h"
#include "graphics.h"
// macro for console background color & text color
#define BG_COLOR 1
#define TXT_COLOR 7

struct axis //store terminal's axis
{
	int x;
	int y;
};

axis getTermSize(); // get terminal size

void text_color(int background_color, int text_color);

void GotoXY(int x, int y);

void LoadConsole();
void DisableResizeWindow();
void DisableCtrButton(bool Close, bool Min, bool Max);
void ShowScrollbar(BOOL Show);
void SetConsolePosition(int x, int y);
void LockConsolePosition();
void MaximizeConsoleWindow();
void ShowConsoleCursor(bool show); // show/unshow the cursor of the terminal

void mainMenu(); // main menu of the program