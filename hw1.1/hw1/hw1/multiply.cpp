//
//  multiply.cpp
//  
//
//  Created by Benjamin Kuschner on 1/4/20.
//

#include "multiply.h"
#include <math.h>
#include <algorithm>
#include <string>

std::string ZERO = "0";
/*
 * adds two non-negative integers, represented as strings
 * @param a: non-negative integer to be added
 * @param b: non-negative integer to be added
 * @return: sum of a and b
 */
std::string plus (std::string a, std::string b) {
    std::string sum = "";
    int carryover, digit1, digit2;
    carryover = 0;
    int i = 1;
    while (i < a.length() && i < b.length()) {
        digit1 = (int) (a.at(a.length() - i) - '0'); //subtract 0 to convert from ascii
        digit2 = (int) (b.at(b.length() - i) - '0');
        digit1 += carryover;
        carryover = 0;
        digit1 += digit2;
        if(digit1 > 9) {
            carryover = 1;
            digit1 %= 10;
        }
        sum.push_back('0' + digit1);
        ++i;
    }
    std::reverse(sum.begin(), sum.end());
    return sum;
}
/* non-negative integer multiplication with Karatsuba's method
 * @param factor1: string containing the non-negative integer to be multiplied
 * @param factor2: string containing the non-negative integer to be multiplied
 * @return: product of factor1 and factor2
 */
std::string multiply (std::string factor1, std::string factor2) {
    if (factor1.length() < 2 && factor2.length() < 2)
        return std::to_string((std::stoi(factor1) * std::stoi(factor2)));
    while(factor1.length() > factor2.length()) {
        factor2 = factor2.insert(0, ZERO);
    }
    while(factor2.length() > factor1.length()) {
        factor1 = factor1.insert(0, ZERO);
    }
    //factor1 and factor2 are now the same length

    std::string a, b, c, d, a_plus_b, c_plus_d;
    a = factor1.substr(0, factor1.length() / 2);
    b = factor1.substr(factor1.length() / 2);
    c = factor2.substr(0, factor2.length() / 2);
    d = factor2.substr(factor2.length() / 2);
    a_plus_b = std::to_string(std::stoi(a) + std::stoi(b));
    c_plus_d = std::to_string(std::stoi(c) + std::stoi(d));
    
    std::string part1 = multiply(a, c);
    std::string part2 = multiply(b, d);
    std::string part3 = multiply(a_plus_b, c_plus_d);
    part3 = std::to_string(std::stoi(part3) - std::stoi(part1) - std::stoi(part2));
    
    //insert 0s to give the effect of multiplying part1 by 10^n
    while(part2.length() < factor1.length()) {
        part2 = part2.insert(0, ZERO);
    }
    part1.append(part2);
    //multiply part3 by 10^(n/2) then add
    for(int i = 0; i < (factor1.length() / 2); ++i) {
        part3.append(ZERO);
    }
    part1.append(part3);
    return part1;
}
