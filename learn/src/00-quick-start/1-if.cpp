#include <iostream>

int main_if() {

	int val, curval = 0;
	std::cin >> val;
	curval = val;
	int cnt = 1;
	while (std::cin >> val) {
		if (val == curval) {
			cnt++;
		}
		else {
			std::cout << curval << " occurs " << cnt << " times" << std::endl;
			curval = val;
			cnt = 1;
		}
	}
	std::cout << curval << " occurs " << cnt << " times" << std::endl;

	return 0;
}