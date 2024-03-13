#pragma once
#include "ConsoleWindow.h"
#include "GameMatch.h"

// ___________________________________________________________________MAP 2______________________________________________________________________
// initialize obstacle for map level 2
void create_obstacle_2(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int& obs_nums);
// play match level 2
void play_match2(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int& obs_nums);

// ___________________________________________________________________MAP 3______________________________________________________________________
// initialize obstacle for map level 3
void create_obstacle_3(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int& obs_nums);
// play match level 3
void play_match3(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int &obs_nums);

// ___________________________________________________________________MAP 4______________________________________________________________________
// initialize obstacle for map level 4
void create_obstacle_4(int x_pos, int y_pos, int width, int height, Point obs[], int& obs_nums, Point const_obs[], int& const_obs_nums);
// initialize movable obstacle for map level 4
void move_obs(int x_pos, int y_pos, int width, int height, Point obs[], int obs_nums, bool& up, Point const_obs[], int &const_obs_nums);
// play match level 4
void play_match4(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int &obs_nums, bool up, Point const_obs[], int &const_obs_nums);

// ___________________________________________________________________MAP 5______________________________________________________________________

//void create_obstacle_5(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, toado obs[], int& obs_nums);
void getConsoleSize(int& columns, int& rows);