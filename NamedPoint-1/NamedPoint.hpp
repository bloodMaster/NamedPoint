//
//  NamedPoint.hpp
//
//  Task :
//  Write a NamedPoint class with three members: two floating point values for
//  the coordinates on an X-Y plane, and a name represented as a 'char *'.
//  Assume that this class will be used for some sort of war-game or simulation
//  program that treats the world as flat and that these named points will be
//  used to represent things like cities, battlefields, etc.
//
//  Created by Merkava on 2/25/16.
//  Copyright © 2016 *. All rights reserved.
//

#ifndef NAMED_POINTER_HPP
#define NAMED_POINTER_HPP

#include <iostream>
#include <cmath>

namespace merkava {
    class Named_Point;
    class Point;
};

namespace merkava {
    
class Point
{
public:
    // default ctor
    Point()
    : m_x()
    , m_y()
    {}
    
    // ctor
    Point(double x, double y)
    : m_x(x)
    , m_y(y)
    {}
    // copy ctor
    Point(const Point& p)
    : m_x(p.m_x)
    , m_y(p.m_y)
    {
    }
    
public:
    static void swap(Point& r, Point& l)
    {
        using std::swap;
        swap(r.m_x, l.m_x);
        swap(r.m_y, l.m_y);
    }
    
public:
    // overload add operator for Point type
    Point operator + (const Point& b) const
    {
        return Point(m_x + b.m_x, m_y + b.m_y);
    }
    // overload sub operator for Point type
    Point operator - (const Point& b) const
    {
        return Point(m_x - b.m_x, m_y - b.m_y);
    }
    // overload = operator
    Point& operator = (Point p)
    {
        swap(*this, p);
        return *this;
    }
    // overload operator ==
    bool operator == (const Point& p)
    {
        static const double epsilion = 0.00001;
        return is_equal(m_x, p.m_x, epsilion) &&
               is_equal(m_y, p.m_y, epsilion);
    }
    
public:
    
    bool is_equal(double x, double y, const double epsilon)
    {
        return std::abs(x - y) <= epsilon * std::abs(x);
    }
    // get x
    double get_x() const
    {
        return m_x;
    }
    // set x
    void set_x(double x)
    {
        m_x = x;
    }
    // get y
    double get_y() const
    {
        return m_y;
    }
    // set y
    void set_y(double y)
    {
        m_y = y;
    }
    // return x as string
    std::string x_to_string() const
    {
        return std::to_string(m_x);
    }
    // return y as string
    std::string y_to_string() const
    {
        return std::to_string(m_y);
    }
    // compute distinc of given pointer from current
    double dist(const Point& pointer) const
    {
        double x = m_x - pointer.m_x;
        double y = m_y - pointer.m_y;
        return std::sqrt(x*x + y*y);
    }
    // move the existing point.
    void move(double a, double b)
    {
        m_x += a;
        m_y += b;
    }
    // print x and y in "(x,y)" format
    void print(std::ostream &o) const
    {
        o << "(" << m_x << "," << m_y << ")";
    }
    
private:
    double m_x;
    double m_y;
};
    
// overload operator << for Point type
std::ostream& operator<<(std::ostream &strm, const Point& p);
    
class Named_Point
{
public:
    // default ctor
    Named_Point()
        : m_coordinate()
        , m_name(new char[1])
    {
        strcpy(m_name, "\0");
    }
    // ctor
    Named_Point(const char* name, double x, double y)
        : m_coordinate(x, y)
        , m_name(0)
    {
        try {
            if ( 0 == name ) {
                return;
            }
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        } catch ( ... ) {
            delete[] m_name;
            m_name = 0;
        }
    }
    // copy ctor
    Named_Point(const Named_Point& point)
        : m_coordinate(point.m_coordinate)
        , m_name(0)
    {
        try {
            if ( 0 == point.m_name ) {
                return;
            }
            m_name = new char[strlen(point.m_name) + 1];
            strcpy(m_name, point.m_name);
        } catch ( ... ) {
            delete[] m_name;
            m_name = 0;
        }
    }
    // dtor
    ~Named_Point()
    {
        delete[] m_name;
        m_name = 0;
    }
    
public:
    // overload == operator
    bool operator == (const Named_Point&);
    // overload = operator
    Named_Point& operator = (Named_Point);

public:
    // set name
    void set_name(const char*);
    // get name
    std::string get_name() const;
    // set coordinate
    void set_coordinate(const Point&);
    // get coordinate
    Point get_coordinate() const;

public:
    // print Name_Point class for the following format
    // {name, (coordinatex) }
    void print(std::ostream& ost) const
    {
        ost << "{" <<  (m_name == 0 ? "no name": m_name) << ", " << m_coordinate << "}" << std::endl;
    }
    
private:
    Point m_coordinate;
    char* m_name;
};
    
// overload operator << for Named_Point type
std::ostream& operator<<(std::ostream &strm, const Named_Point& p);
    
} // end merkava namespace

#endif /* NAMED_POINTER_HPP */