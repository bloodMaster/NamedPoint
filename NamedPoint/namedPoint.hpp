#ifndef NAMED_POINT_HPP
#define NAMED_POINT_HPP

#include <iostream>

class Point
{
public:
	Point(double x = 0.0, double y = 0.0);

public:
	bool operator<(const Point& other) const;
	bool operator == (const Point& other) const;

public:
	double getX() const;
	double getY() const;

public:
	void setX(double x);
	void setY(double y);
	void setCoords(double x, double y);

public:
	static double distance(const Point& from, const Point& to);

public:
	friend std::ostream& operator<<(std::ostream&, const Point&);

private:
	bool isLess(double x, double y) const;
	bool isEqual(double x, double y) const;

private:
	double m_x;
	double m_y;
};

class NamedPoint : public Point
{
public:
	NamedPoint(const char* name, double x = 0.0, double y = 0.0);
	NamedPoint(const NamedPoint& other);
	~NamedPoint();

public:
	NamedPoint& operator=(const NamedPoint& other);

public:
	void setName(const char* name); 
	const char* getName() const;

public:
	friend std::ostream& operator<<(std::ostream&, const NamedPoint&);

private:
	char* m_name;
};

#endif