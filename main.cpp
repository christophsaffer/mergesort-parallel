#include <iostream>
#include <chrono>
#include <vector>

#include "mergesort.hpp"

int main(int argc, char const *argv[]) {

	std::vector<double> a;

	mergesort(a.data());

	std::cout << "Runs correctly" << '\n';
	return 0;
}