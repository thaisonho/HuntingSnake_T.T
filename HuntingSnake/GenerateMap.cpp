#include "GenerateMap.h"


// ___________________________________________________________________MAP 2______________________________________________________________________

// Initialize obstacle for level 2
// O map level2 co 2 thanh vat can nam ngang
void create_obstacle_2(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int& obs_nums) {
	int dist = 10; // dist la gia tri khoang cach tu hai bien trai va phai den vi tri dat thanh vat can ngang
	for (int i = x_pos + dist; i <= width - dist; i++) { // vat can cach bien trai va bien phai 1 khoang = dist

		// obs[i] chinh la toa do vat can {x;y}. Vi thanh vat can nam ngang va co dinh => tang x va giu nguyen y

		// Thanh vat can ben tren
		obs[obs_nums].x = i;
		obs[obs_nums].y = y_pos + 6;
		obs_nums++;

		// Thanh vat can phia duoi
		obs[obs_nums].x = i;
		obs[obs_nums].y = height - 4;
		obs_nums++;
	}
}

// Generate level 2
void play_match2(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int& obs_nums) {
	// prepare obstacle for level 2
	create_obstacle_2(x_pos, y_pos, height, width, obs, obs_nums);
	// draw match board
	//draw_matchBoard(x_pos, y_pos, height, width);
	// draw obstacle for level 2
	draw_obstacle(obs, obs_nums);
}

// ___________________________________________________________________MAP 3______________________________________________________________________

// Initialize obstacle for level 3
void create_obstacle_3(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int& obs_nums) {
	// Phan nay giu nguyen vat can cua level 2
	int dist = 10;
	for (int i = x_pos + dist; i <= width - dist; i++) {
		obs[obs_nums].x = i;
		obs[obs_nums].y = y_pos + 5;
		obs_nums++;

		obs[obs_nums].x = i;
		obs[obs_nums].y = height - 2;
		obs_nums++;
	}

	// Them hai thanh vat can nam dung ben trai va ben phai
	for (int j = y_pos + 8; j <= height - 5; j++) {

		// Vi vat can nam dung nen thay doi gia tri y va giu nguyen gia tri x cua tung toa do {x,y}

		// Phan vat can phai tren trai
		obs[obs_nums].x = x_pos + 2 * dist; // vat can dung cach 2 bien mot gia tri la 2*dist
		obs[obs_nums].y = j;
		obs_nums++;
		// Phan vat can phia ben phai
		obs[obs_nums].x = width - 2 * dist;
		obs[obs_nums].y = j;
		obs_nums++;
	}

}

// Generate level 3
void play_match3(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int obs_nums) {
	// prepare obstacle for level 3
	create_obstacle_3(x_pos, y_pos, height, width, obs, obs_nums);
	// draw matchboard
	//draw_matchBoard(x_pos, y_pos, height, width);
	// draw obstacle for level 2
	draw_obstacle(obs, obs_nums);
}



// ___________________________________________________________________MAP 4______________________________________________________________________

// Initialize obstacle for level 4
// O map level 4 se co 2 thanh vat can nam dung di chuyen lien tuc va mot thanh vat can nam ngang co dinh. Trong do mang obs[] la mang chua gia tri toa do
// cua 2 thanh nam dung di chuyen lien tuc va mang const_obs la mang chua gia tri toa do cua vat can nam ngang co dinh
void create_obstacle_4(int x_pos, int y_pos, int width, int height, Point obs[], int& obs_nums, Point const_obs[], int& const_obs_nums)
{
	int obs_length = 10; // Khai bao do dai 2 thanh vat can di chuyen la 10 don vi
	// Khoi tao gia tri toa do thanh vat can di chuyen tu tren xuong
	for (int i = y_pos + 1; i <= y_pos + obs_length; i++)
	{
		obs[obs_nums].x = x_pos + 20;
		obs[obs_nums].y = i;
		obs_nums++;
	}
	// Khoi tao gia tri toa do thanh vat can di chuyen tu duoi len
	for (int i = y_pos + height - obs_length; i <= y_pos + height - 1; i++)
	{
		obs[obs_nums].x = width - 20;
		obs[obs_nums].y = i;
		obs_nums++;
	}
	// Khoi tao gia tri toa do thanh vat can nam ngang co dinh
	for (int i = x_pos + width / 2 - 4; i <= x_pos + width / 2 + 4; i++) {
		const_obs[const_obs_nums].x = i;
		const_obs[const_obs_nums].y = 13;
		const_obs_nums++;
	}

}

// Make obstacle move
void move_obs(unsigned int x_pos, unsigned int y_pos, unsigned int width, unsigned int height, Point obs[], int obs_nums, bool& up, Point const_obs[], int const_obs_nums)
{
	draw_obstacle(const_obs, const_obs_nums); // Thanh thanh vat can co dinh nam ngang vao trong matchboard
	if (up)
	{
		// Co the hieu la lien tuc chay thay the khoang trang va duong ve vat can
		GotoXY(obs[obs_nums / 2 - 1].x, obs[obs_nums / 2 - 1].y);
		cout << " ";
		for (int i = 0; i < obs_nums / 2; i++)
		{
			obs[i].y--;
		}
		GotoXY(obs[0].x, obs[0].y);
		cout << char(219);

		GotoXY(obs[obs_nums / 2].x, obs[obs_nums / 2].y);
		cout << " ";
		for (int i = obs_nums / 2; i < obs_nums; i++)
		{
			obs[i].y++;
		}
		GotoXY(obs[obs_nums - 1].x, obs[obs_nums - 1].y);
		cout << char(219);

		if (obs[0].y == y_pos + 1)
		{
			up = false;
		}

	}
	else
	{
		GotoXY(obs[0].x, obs[0].y);
		cout << " ";

		for (int i = 0; i < obs_nums / 2; i++)
		{
			obs[i].y++;
		}

		GotoXY(obs[obs_nums / 2 - 1].x, obs[obs_nums / 2 - 1].y);
		cout << char(219);

		GotoXY(obs[obs_nums - 1].x, obs[obs_nums - 1].y);
		cout << " ";
		for (int i = obs_nums / 2; i < obs_nums; i++)
		{
			obs[i].y--;
		}
		GotoXY(obs[obs_nums / 2].x, obs[obs_nums / 2].y);
		cout << char(219);


		if (obs[obs_nums / 2 - 1].y == y_pos + height - 1)
		{
			up = true;
		}
	}
}

// Generate level 4
void play_match4(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, Point obs[], int obs_nums, bool up, Point const_obs[], int const_obs_nums) {
	// prepare obstacle for level 4
	create_obstacle_4(x_pos, y_pos, width, height, obs, obs_nums, const_obs, const_obs_nums);
	// draw match board
	//draw_matchBoard(x_pos, y_pos, height, width);
	// Move obstacle
	while (true) {
		move_obs(x_pos, y_pos, width, height, obs, obs_nums, up, const_obs, const_obs_nums);
		// Set movable obstacle speed
		Sleep(65);
	}
}

//void create_obstacle_5(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, toado obs[], int& obs_nums) {}

void getConsoleSize(int& columns, int& rows)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	//printf("columns: %d\n", columns);
	//printf("rows: %d\n", rows);
}

