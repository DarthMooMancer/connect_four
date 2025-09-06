#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <vector>

struct Point {
	Point() : m_row(0), m_col(0), m_id(0), m_active(true) {}
	Point(int row, int col, int id) : m_row(row), m_col(col), m_id(id), m_active(true) {}
	int m_row;
	int m_col;
	int m_id;
	bool m_active;
	char m_symbol;
	void assign(int row, int col);
	void move();
	void check_collision(std::vector<Point> &points_list);
};

struct Player {
	Player(char symbol, bool turn) : m_symbol(symbol), m_turn(turn) {}
	char m_symbol;
	bool m_turn;
	std::vector<Point> m_points;
	void input_tile(int col, std::vector<Point> &points);
};

#endif
