//
//  main.cpp
//  
//
//  Created by Merkava on 2/25/16.
//  Copyright © 2016 *. All rights reserved.
//

#include <iostream>
#include <vector>

#include "NamedPoint.hpp"

int main(int argc, const char * argv[])
{
    merkava::Named_Point p;
    std::cout << p << std::endl;
    std::string s = p.get_name();
    std::cout << s << std::endl;
    return 0;
}


