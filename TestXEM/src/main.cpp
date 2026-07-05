#include <xem/XEM.hpp>

#include <iostream>

int main() {
	xem::Vec<3, float> v(1.0f);
	std::cout << "Length: " << v.Length();
}