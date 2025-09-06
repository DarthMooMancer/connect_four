#include <iostream>
#include <ncurses.h>
#include "input.hpp"

void Input::get_input(bool &running, Player &one, Player &two, std::vector<Point> &points) {
	while(running) {
		initscr();
		cbreak();
		noecho();


		_getch = getch();
		endwin();
		switch (_getch) {
			case 49:
				one.input_tile(0, points);
				break;
			case 50:
				one.input_tile(1, points);
				break;
			case 51:
				one.input_tile(2, points);
				break;
			case 52:
				one.input_tile(3, points);
				break;
			case 53:
				one.input_tile(4, points);
				break;
			case 54:
				one.input_tile(5, points);
				break;
			case 55:
				one.input_tile(6, points);
				break;
			case 113:
				running = false;
				break;
			default:
				_getch = 0;
		}
	}
}
