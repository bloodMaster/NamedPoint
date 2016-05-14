//
//  NamedPoint.cpp
//  Name
//
//  Created by Merkava  on 2/25/16.
//  Copyright © 2016 *. All rights reserved.
//

#include "NamedPoint.hpp"

namespace merkava
{
    
std::ostream& operator<<(std::ostream &strm, const Point& p)
{
    p.print(strm);
    return strm;
}
    
std::ostream& operator<<(std::ostream &strm, const Named_Point& p)
{
    p.print(strm);
    return strm;
}
    
bool Named_Point::operator == (const Named_Point& p)
{
    return m_coordinate == p.m_coordinate &&
           !strcmp(m_name, p.m_name);
}
    
Named_Point& Named_Point::operator = (Named_Point p)
{
    delete[] m_name;
    m_name = new char[strlen(p.m_name) + 1];
    strcpy(m_name, p.m_name);
    Point::swap(m_coordinate, p.m_coordinate);
    return *this;
}

void Named_Point::set_name(const char* name)
{
    if ( 0 == name ) {
        delete[] m_name;
        m_name = 0;
        return;
    }
    delete[] m_name;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
}
    
std::string Named_Point::get_name() const
{
    return std::string(m_name);
}
    
void Named_Point::set_coordinate(const Point& p)
{
    m_coordinate = p;
}
    
Point Named_Point::get_coordinate() const
{
    return m_coordinate;
}

};// end namespac merkava