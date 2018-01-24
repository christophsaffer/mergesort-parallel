#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <algorithm>
#include <sstream>

#include "mergesort.hpp"

void output(int * a, int N){
	for(int i=0; i < N; ++i){
		std::cout << a[i] << " ";
	}
	std::cout << '\n';
}

int main(int argc, char const *argv[]) {

	int N = 10;
	std::istringstream inbuf2(argv[1]);
	inbuf2 >> N;

	std::vector<int> a(N);
	std::iota(a.begin(), a.end(), 0);
	std::shuffle(a.begin(), a.end(), std::mt19937{std::random_device{}()});

	//output(a.data(), N);

  	auto time_start = std::chrono::system_clock::now();

	a = mergesort(a);

	auto time_end = std::chrono::system_clock::now();
  	float const elapsed_seconds =
  	std::chrono::duration<float>(time_end - time_start).count();
  	std::cout << "TIME: " << elapsed_seconds << std::endl;
  	
  	//output(a.data(), N);

  	std::cout << "TIME: " << elapsed_seconds << std::endl;

	return 0;
}