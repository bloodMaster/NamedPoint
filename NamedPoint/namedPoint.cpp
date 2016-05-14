#include "namedPoint.hpp"

// STD
#include <math.h>

Point::
Point(double x, double y)
	: m_x(x)
	, m_y(y)
{}

bool Point::
operator< (const Point& other) const
{
	return isLess(m_x, other.m_x) ||
		(isEqual(m_x, other.m_x) && isLess(m_y, other.m_y));
}

bool Point::
operator== (const Point& other) const
{
	return isEqual(m_x, other.m_x) && isEqual(m_y, other.m_y);
}

double Point::
getX() const
{
	return m_x;
}

double Point::
getY() const
{
	return m_y;
}

void Point::
setX(double x)
{
	m_x = x; 
}

void Point::
setY(double y)
{
	m_y = y;
}

void Point::
setCoords(double x, double y)
{
	m_x = x;
	m_y = y;
}

double Point::
distance(const Point& from, const Point& to)
{
	double xDistance = std::abs(from.m_x - to.m_x);
	double yDistance = std::abs(from.m_y - to.m_y);
	return std::sqrt(std::pow(xDistance, 2) + std::pow(yDistance, 2));
}

std::ostream& 
operator<<(std::ostream& out, const Point& point)
{
	out << "( " << point.m_x << ", " << point.m_y << " )";
	return out;
}

bool Point::
isLess(double x, double y) const
{
	return x + std::numeric_limits<double>::epsilon() < y;
}

bool Point::
isEqual(double x, double y) const
{
	return !isLess(x, y) && !isLess(x, y);
}

// NamedPoint

NamedPoint::
NamedPoint(const char* name, double x, double y)
	: Point(x, y) 
	, m_name(0)
{
	if (0 == name) {
		return;
	}
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}

NamedPoint::
NamedPoint(const NamedPoint& other)
	: Point(other)
	, m_name(0)
{
	if (0 == other.m_name) {
		return;
	}
	m_name = new char[strlen(other.m_name) + 1];
	strcpy(m_name, other.m_name);
}

NamedPoint::
~NamedPoint()
{
	delete m_name;
}

NamedPoint& NamedPoint::
operator= (const NamedPoint& other)
{
	if (this == &other) {
		return *this;
	}
	static_cast<Point&>(*this) = other;
	setName(other.m_name);
	return *this;
}

void NamedPoint::
setName(const char* name)
{
	if (0 == name) {
		if(0 != m_name) {
			delete m_name;
			m_name = 0;
		}
		return;
	}
	delete m_name;
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}

const char* NamedPoint::
getName() const
{
	return m_name;
}

std::ostream& operator<<(std::ostream& out, const NamedPoint& namedPoint)
{
	out << namedPoint.m_name << " at " << static_cast<const Point&>(namedPoint);
	return out;
}

int main()
{
	NamedPoint p("name", 5.2, 3.6);
	std::cout << p;
}