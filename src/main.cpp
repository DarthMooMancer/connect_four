#include <iostream>
#include <thread>
#include <vector>
#include "input.hpp"
#include "window.hpp"
#include "elements.hpp"

int main() {
	std::vector<Point> points_list = {};
	Input input;
	Window window;
	Player one('o', true);
	Player two('x', false);

	bool running = true;
	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(one), std::ref(two), std::ref(points_list));
	char symbol = ' ';
	bool d = true;
	bool result = false;
	while(running) {
		window.update_display(points_list);
		for(int i = 0; i < points_list.size(); i++) {
			points_list[i].move();
			points_list[i].check_collision(points_list);
		}
		for(int i = 0; i < ROW - 1; i++) {
			for(int j = 0; j < COL - 1; j++) {
				if(window.m_board[i][j] == ' ') continue;
				symbol = window.m_board[i][j];
				d = true;
				if(d) {
					for(int k = 1; k <= 3; k++) {
						if(window.m_board[i][j + k] != symbol) d = false;
					}
					if(d) {
						result = true;
					}
				}
			}
		}
		// if(window.check_chain()) {
		// 	std::cout << "Chain is active" << std::endl;
		// }
		std::cout << result << std::endl;
	}

	input_thread.join();
	return 0;
}
