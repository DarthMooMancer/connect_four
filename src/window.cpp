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
