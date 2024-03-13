#include "graphics.h"

void draw_rectangle(unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, int line_color, int bg_color, std::string text, int txtColor)
{
	// if cannot draw => return
	if (height < 1 || width < 1) return;


	text_color(bg_color, line_color);

	// if user want to draw a color-only rectangle and no border
	if (bg_color != 0 && line_color != 0
		&& bg_color == line_color) {
		for (int iy = y_pos; iy <= y_pos + height; ++iy) {
			for (int ix = x_pos; ix <= x_pos + width; ++ix) {
				GotoXY(ix, iy);
				std::cout << char(219);
			}
		}
	}

	// draw a rectangle with border and no filling color
	else {
		//draw 4 edges
		for (int ix = x_pos + 1; ix < x_pos + width; ++ix) {
			GotoXY(ix, y_pos);
			std::cout << char(205);
			GotoXY(ix, y_pos + height);
			std::cout << char(205);
		}
		GotoXY(x_pos, y_pos);
		for (int iy = y_pos + 1; iy < y_pos + height; ++iy) {
			GotoXY(x_pos, iy);
			std::cout << char(186);
			GotoXY(x_pos + width, iy);
			std::cout << char(186);
		}
		// draw 4 corners
		GotoXY(x_pos, y_pos);
		std::cout << char(201);
		GotoXY(x_pos + width, y_pos);
		std::cout << char(187);
		GotoXY(x_pos, y_pos + height);
		std::cout << char(200);
		GotoXY(x_pos + width, y_pos + height);
		std::cout << char(188);
	}

	// print text if any
	if (!text.empty()) {
		text_color(bg_color, txtColor);
		GotoXY(x_pos + (width - text.size()) / 2, y_pos + height / 2);
		std::cout << text;
	}
	text_color(0, 7); // set color to default

}

void setBackgroundColor(int bg_color, int txt_color)
{
	text_color(bg_color, bg_color); // set the color
	// print all the terminal with selected color
	for (int i = 0; i <= getTermSize().x; ++i) {
		for (int j = 0; j <= getTermSize().y; ++j) {
			std::cout << char(219);
		}
	}
	text_color(0, 7); //set to default
}

void highlightedBox(bool use, unsigned int x_pos, unsigned int y_pos, unsigned int height, unsigned int width, int bg_color, int line_color)
{
	if (use) { // if highlighted is needed
		text_color(bg_color, line_color); //set the selected color
		for (int ix = x_pos; ix <= x_pos + width; ++ix) {
			GotoXY(ix, y_pos);
			std::cout << char(219);
			GotoXY(ix, y_pos + height);
			std::cout << char(219);
		}
		GotoXY(x_pos, y_pos);
		for (int iy = y_pos; iy <= y_pos + height; ++iy) {
			GotoXY(x_pos, iy);
			std::cout << char(219);
			GotoXY(x_pos + width, iy);
			std::cout << char(219);
		}
		text_color(0, 7); // set color to default
	}

	else {
		// set back to normal state when navigate to other button
		draw_rectangle(x_pos, y_pos, height, width, 5, bg_color, "", 0);
	}
}