#include <xem/XEM.hpp>

#include <xemtest/XEMTEST.hpp>

#include <iostream>
#include <chrono>

void Stall() {
	// Stall for 15 seconds
	auto lastTime = std::chrono::steady_clock::now();
	auto accumulator = std::chrono::nanoseconds(0);

	while (std::chrono::seconds(15) > accumulator) {
		auto currentTime = std::chrono::steady_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentTime - lastTime);
		lastTime = currentTime;
		accumulator += elapsedTime;
	}
}

int main() {
	std::cout << "---------- Running XEM Tests" << std::endl;
	bool lastTestPassed = true;

	std::cout << "Running xem::VecTest()" << std::endl;
	lastTestPassed = lastTestPassed && xem::VecTest();

	if (lastTestPassed) {
		std::cout << "xem::VecTest() passed!" << std::endl;
	}
	else {
		std::cerr << "xem::VecTest() didn't pass!" << "\n";
		Stall();
		return 1;
	}

	return 0;
}