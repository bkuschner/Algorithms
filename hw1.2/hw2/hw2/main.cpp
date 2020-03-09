//
//  main.cpp
//  hw2
//
//  Created by Benjamin Kuschner on 3/8/20.
//  Copyright © 2020 Benjamin Kuschner. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

long long count_sort(std::vector<int>& input) {
    if(input.size() < 2) return 0;
    
    std::vector<int> left_array = std::vector<int>();
    std::vector<int> right_array = std::vector<int>();
    for(int i = 0; i < input.size() / 2; ++i) {
        left_array.push_back(input.at(i));
    }
    for(int i = input.size() / 2; i < input.size(); ++i) {
        right_array.push_back(input.at(i));
    }
    long long left_inversions = count_sort(left_array);
    long long right_inversions = count_sort(right_array);
    std::vector<int> sorted_array = std::vector<int>();
    int left_index = 0;
    int right_index = 0;
    long long split_inversions = 0;
    
    while(left_index < left_array.size() && right_index < right_array.size()) {
        if(left_array.at(left_index) <= right_array.at(right_index)) {
            sorted_array.push_back(left_array.at(left_index));
            left_index++;
        }
        else {
            sorted_array.push_back(right_array.at(right_index));
            right_index++;
            split_inversions += (left_array.size() - left_index);
        }
    }
    while(left_index < left_array.size() || right_index < right_array.size()) {
        if(left_index < left_array.size()) {
            sorted_array.push_back(left_array.at(left_index));
            left_index++;
        }
        if(right_index < right_array.size()) {
            sorted_array.push_back(right_array.at(right_index));
            right_index++;
        }
    }
    input = sorted_array;
    return left_inversions + right_inversions + split_inversions;    
}

int main(int argc, const char * argv[]) {
    //std::vector<int> test_input {1,3,5,2,4,6};
    //std::cout << count_sort(test_input) << std::endl;
    
    std::ifstream myfile;
    myfile.open("/Users/benjaminkuschner/Programming/Algorithms/hw1.2/hw2/hw2/IntegerArray.txt");
    std::string next_number;
    std::vector<int> input = std::vector<int>();
    while(std::getline(myfile, next_number)) {
        input.push_back(std::stoi(next_number));
    }
    myfile.close();
    std::cout << count_sort(input) << std::endl;
    return 0;
}
