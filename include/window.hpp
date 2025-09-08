#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <array>
#include <vector>
#include "globals.hpp"
#include "elements.hpp"

struct Window {
	std::array<std::array<char, COL>, ROW> m_board = {};
	void update_display(std::vector<Point> &points_list);
};

#endif
