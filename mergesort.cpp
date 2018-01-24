#include "mergesort.hpp"

#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> list_l, std::vector<int> list_r){
	
	std::vector<int> sorted;
	int k = 0;
	for(int i=0; i < list_l.size(); ++i){
		for(int j=k; j < list_r.size(); ++j){
			if (list_l[i] < list_r[j]){
				sorted.push_back(list_l[i]);
				j = list_r.size();
				if (i == list_l.size()-1) {
					sorted.insert(sorted.end(), list_r.begin() + k, list_r.end());
				}
			} else {
				sorted.push_back(list_r[j]);
				k = j+1;
				if (j == list_r.size()-1) {
					sorted.insert(sorted.end(), list_l.begin() + i, list_l.end());
				}
			}
		}
	}

	return sorted;
}

std::vector<int> mergesort(std::vector<int> a){

	if (a.size() > 2){
		std::vector<int> l(a.begin(), a.begin() + (a.size()/2));
		std::vector<int> r(a.begin() + (a.size()/2), a.end());
		#pragma omp parallel
		{
			#pragma omp sections
			{
				#pragma omp section 
				l = mergesort(l);
				#pragma omp section
				r = mergesort(r);
			}
		}
		return merge(l, r);
	} else {
		if (a.size() == 1) {
			return a;
		} else {
			if (a[0] < a[1]){
				return a;
			} else {
				std::swap(a[0], a[1]);
				return a;
			}

		}
	}

}