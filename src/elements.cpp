#include "elements.hpp"
#include "globals.hpp"
#include <array>
#include <vector>

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
}

void Point::move() {
	if(m_row < ROW - 1) m_row++;
	else m_collided = true;
}

void Point::check_collision(std::vector<Point> &points_list) {;
	for(int i = 0; i < points_list.size(); i++) {
		if(points_list[i].m_id == m_id) continue;
		if(points_list[i].m_row != m_row) continue;
		if(points_list[i].m_col != m_col) continue;
		m_row = points_list[i].m_row - 1;
		m_collided = true;
	}
}

void Player::input_tile(int col, std::vector<Point> &points) {
	if(points.size() == 0) points.push_back(Point({ 0, col, 0 }));
	else points.push_back(Point({ 0, col, points.back().m_id + 1 }));
	points.back().m_symbol = m_symbol;
}

bool Player::check_chain(std::array<std::array<char, COL>, ROW> &m_board, std::vector<Point> &points_list) {
	for(int i = ROW - 1; i >= 0; i--) {
		for(int j = COL - 1; j >= 0; j--) {
			if(m_board[i][j] != m_symbol) continue;
			if(m_board[i - 1][j] != m_symbol) continue;
			if(m_board[i - 2][j] != m_symbol) continue;
			if(m_board[i - 3][j] != m_symbol) continue;
			return true;
		}
	}
	for(int i = ROW - 1; i >= 0; i--) {
		for(int j = COL - 1; j >= 0; j--) {
			if(m_board[i][j] != m_symbol) continue;
			if(m_board[i][j - 1] != m_symbol) continue;
			if(m_board[i][j - 2] != m_symbol) continue;
			if(m_board[i][j - 3] != m_symbol) continue;
			return true;
		}
	}
	for(int i = ROW - 1; i >= 0; i--) {
		for(int j = COL - 1; j >= 0; j--) {
			if(m_board[i][j] != m_symbol) continue;
			if(m_board[i - 1][j + 1] != m_symbol) continue;
			if(m_board[i - 2][j + 2] != m_symbol) continue;
			if(m_board[i - 3][j + 3] != m_symbol) continue;
			if(m_board[i][j + 1] == '.') continue;
			if(m_board[i - 1][j + 2] == '.') continue;
			if(m_board[i - 2][j + 3] == '.') continue;
			return true;
		}
	}
	for(int i = ROW - 1; i >= 0; i--) {
		for(int j = COL - 1; j >= 0; j--) {
			if(m_board[i][j] != m_symbol) continue;
			if(m_board[i - 1][j - 1] != m_symbol) continue;
			if(m_board[i - 2][j - 2] != m_symbol) continue;
			if(m_board[i - 3][j - 3] != m_symbol) continue;
			if(m_board[i][j - 1] == '.') continue;
			if(m_board[i - 1][j - 2] == '.') continue;
			if(m_board[i - 2][j - 3] == '.') continue;
			return true;
		}
	}
	return false;
}
