#include "elements.hpp"
#include "globals.hpp"
#include <vector>
#include <iostream>

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
}

void Point::move() {
	if(m_row < ROW - 1) {
		m_row++;
	}
}

void Point::to_string() {
	std::cout << "(" << m_row << ", " << m_col << ")";
}

void Point::check_collision(std::vector<Point> &points_list) {;
	for(int i = 0; i < points_list.size(); i++) {
		if(points_list[i].m_id == m_id) continue;
		if(points_list[i].m_row != m_row) continue;
		if(points_list[i].m_col != m_col) continue;
		m_row = points_list[i].m_row - 1;
	}
}

void Player::input_tile(int col, std::vector<Point> &points) {
	if(points.size() == 0) points.push_back(Point({ 0, col, 0 }));
	else points.push_back(Point({ 0, col, points.back().m_id + 1 }));
	points.back().m_symbol = m_symbol;
}
