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
	while(running) {
		window.update_display(points_list);
		for(int i = 0; i < points_list.size(); i++) {
			if(!points_list[i].m_active) continue;
			points_list[i].move();
			points_list[i].check_collision(points_list);
		}
		std::cout << points_list.size() << std::endl;
	}

	input_thread.join();
	return 0;
}
