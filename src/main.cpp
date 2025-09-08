#include <iostream>
#include <thread>
#include <vector>
#include "input.hpp"
#include "window.hpp"
#include "elements.hpp"

int main() {
	Input input;
	Window window;
	Player one('o', true);
	Player two('x', false);

	bool running = true;
	std::vector<Point> points_list = {};
	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(one), std::ref(two), std::ref(points_list));
	while(running) {
		window.update_display(points_list);
		for(int i = 0; i < points_list.size(); i++) {
			points_list[i].move();
			points_list[i].check_collision(points_list);
		}
		if(one.check_chain(window.m_board)) {
			std::cout << "Hello" << std::endl;
			running = false;
		}
	}

	input_thread.join();
	return 0;
}
