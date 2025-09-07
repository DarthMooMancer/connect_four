#include "window.hpp"
#include <iostream>
#include <chrono>
#include <thread>


void Window::update_display(std::vector<Point> &points_list) {
	for(std::array<char, COL> &row : m_board) { row.fill('.'); }
	for(int i = 0; i < points_list.size(); i++) {
		m_board[points_list[i].m_row][points_list[i].m_col] = points_list[i].m_symbol;
	}

	std::cout << "\033[H" << std::flush;
	for(std::array<char, COL> &row : m_board) {
		for(char &col : row) {
			std::cout << col << " ";
		}
		std::cout << "\r\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 1000 / fps; 200ms = 5fps
}

bool Window::check_chain() {
	char symbol = ' ';
	bool d = true;
	bool result = false;
	for(int i = 0; i < ROW - 1; i++) {
		for(int j = 0; j < COL - 1; j++) {
			if(m_board[i][j] == ' ') continue;
			symbol = m_board[i][j];
			d = true;
			if(d) {
				for(int k = 1; k <= 3; k++) {
					if(m_board[i][j + k] != symbol) d = false;
				}
				if(d) {
					result = true;
				}
			}
		}
	}
	return result;
}
