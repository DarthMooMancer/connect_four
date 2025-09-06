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
		Player *active = nullptr;
		Player *inactive = nullptr;
		if(one.m_turn) active = &one;
		else if(two.m_turn) active = &two;
		if(active == &one) inactive = &two;
		else if(active == &two) inactive = &one; 

		switch (_getch) {
			case 49:
				active->input_tile(0, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 50:
				active->input_tile(1, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 51:
				active->input_tile(2, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 52:
				active->input_tile(3, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 53:
				active->input_tile(4, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 54:
				active->input_tile(5, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 55:
				active->input_tile(6, points);
				active->m_turn = false;
				inactive->m_turn = true;
				break;
			case 113:
				running = false;
				break;
			default:
				_getch = 0;
		}
	}
}
