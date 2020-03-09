//
//  main.cpp
//  hw1
//
//  Created by Benjamin Kuschner on 1/4/20.
//

#include <iostream>
#include "multiply.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    std::string factor1 = "3141592653589793238462643383279502884197169399375105820974944592";
    std::string factor2 = "2718281828459045235360287471352662497757247093699959574966967627";
    std::string a = "1234";
    std::string b = "5678";
    
    
    std::cout << plus(a, b) << std::endl;
    return 0;
}
