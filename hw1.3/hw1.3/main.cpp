//
//  main.cpp
//  hw1.3
//
//  Created by Benjamin Kuschner on 3/10/20.
//  Copyright © 2020 Benjamin Kuschner. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

/*
 * sorts the input array in place using quick sort
 * @param input: input vector to be sorted
 * @param pivot_strategy: how to determine the pivot element when sorting (see the coursera page)
 * @return number of comparisons with the pivot element
 */
int quick_sort(std::vector<int>::iterator start, std::vector<int>::iterator end, std::string pivot_strategy) {
    //base case for input arrays of length 0 or 1
    if(start + 1 >= end) return 0;
    
    int total_comparisons = (int) std::distance(start, end) - 1;
    
    //find the pivot value based on the givien pivot strategy
    std::vector<int>::iterator pivot;
    if(pivot_strategy == "first") {
        pivot = start;
    }
    else if(pivot_strategy == "last") {
        std::iter_swap(start, end - 1);
        pivot = start;
    }
    else if(pivot_strategy == "median_of_three") {
        int first = *start;
        int last = *(end - 1);
        int mid = *(start + (((std::distance(start, end) + 1) / 2) - 1));
        if(first <= mid && first <= last) {
            if(mid <= last){
                std::iter_swap(start + (((std::distance(start, end) + 1) / 2) - 1), start);
            }
            else {
                std::iter_swap(start, end - 1);
            }
        }
        else if(mid <= first && mid <= last) {
            if(first <= last) {
                pivot = start;
            }
            else {
                std::iter_swap(start, end - 1);
            }
        }
        else {
            if(first <= mid) {
                pivot = start;
            }
            else {
                std::iter_swap(start + (((std::distance(start, end) + 1) / 2) - 1), start);
            }
        }
        pivot = start;
    }
    else {
        std::cout << "invalid pivot strategy" << std::endl;
        return 0;
    }
    
    //partition around the pivot
    std::vector<int>::iterator partition = start + 1;
    for(std::vector<int>::iterator i = start + 1; i < end; ++i) {
        if(*i < *pivot) {
            std::iter_swap(partition, i);
            ++partition;
        }
    }
    //put the pivot in the partition place
    std::iter_swap(pivot, (partition - 1));
    
    //recursively sort the two partitions
    total_comparisons += quick_sort(start, partition - 1, pivot_strategy);
    total_comparisons += quick_sort(partition, end, pivot_strategy);
    return total_comparisons;
}

int main(int argc, const char * argv[]) {
    /*
    std::vector<int> test_input {3, 8, 2, 5, 1, 4, 7, 6};
    std::cout << "comparisons: " << quick_sort(test_input.begin(), test_input.end(), "last") << std::endl;
    for(auto element : test_input) {
        std::cout << element << std::endl;
    }
    */
    
    
    std::ifstream myfile;
    myfile.open("/Users/benjaminkuschner/Programming/Algorithms/hw1.3/hw1.3/QuickSort.txt");
    std::string next_number;
    std::vector<int> input = std::vector<int>();
    while(std::getline(myfile, next_number)) {
        input.push_back(std::stoi(next_number));
    }
    myfile.close();
    
    //std::cout << "first: " << quick_sort(input.begin(), input.end(), "first") << std::endl;
    //std::cout << "last: " << quick_sort(input.begin(), input.end(), "last") << std::endl;
    std::cout << "median_of_three: " << quick_sort(input.begin(), input.end(), "median_of_three") << std::endl;
    
    
    return 0;
}
