#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include "globals.hpp"
#include <vector>

struct Point {
	Point() : m_row(0), m_col(0), m_id(0), m_collided(false) {}
	Point(int row, int col, int id) : m_row(row), m_col(col), m_id(id), m_collided(false) {}
	int m_row;
	int m_col;
	int m_id;
	char m_symbol;
	bool m_collided;
	void to_string();
	void assign(int row, int col);
	void move();
	void check_collision(std::vector<Point> &points_list);
};

struct Player {
	Player(char symbol, bool turn) : m_symbol(symbol), m_turn(turn) {}
	char m_symbol;
	bool m_turn;
	void input_tile(int col, std::vector<Point> &points);
	// bool check_chain(std::array<std::array<char, COL>, ROW> &m_board);
	bool check_chain(std::array<std::array<char, COL>, ROW> &m_board, std::vector<Point> &points_list);
};

#endif
