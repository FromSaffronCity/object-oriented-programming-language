#include<iostream>
#include<cmath>

using namespace std;

// Point 2D

class Point2D
{
	double x,y;

public:

	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(double argx, double argy);

	void setX(double argx);
	void setY(double argy);
	double getX() const;
	double getY() const;
	void print() const;

	Point2D operator+(const Point2D rhs);
	Point2D operator*(const double n);
	bool operator==(const Point2D rhs);
	bool operator!=(const Point2D rhs);

	~Point2D(){ x = 0; y = 0; } //destructor that sets all values to 0
};

Point2D::Point2D(double argx,double argy)
{
	x = argx;
	y = argy;
}

void Point2D::setX(double argx)
{
	x = argx;
}

void Point2D::setY(double argy)
{
	y = argy;
}

double Point2D::getX() const
{
	return x;
}

double Point2D::getY() const
{
	return y;
}

void Point2D::print() const
{
	cout << "(" << x << "," << y << ")"<<endl;
}

// added

Point2D Point2D::operator+(const Point2D rhs)
{
    return Point2D( x+rhs.getX() , y+rhs.getY() );
}

Point2D Point2D::operator*(const double n)
{
    return Point2D( x*n , y*n );
}

bool Point2D::operator==(const Point2D rhs)
{
    if( x==rhs.getX() && y==rhs.getY() )
        return true;
    else
        return false;
}

bool Point2D::operator!=(const Point2D rhs)
{
    if( x==rhs.getX() && y==rhs.getY() )
        return false;
    else
        return true;
}

// Circle

class Circle
{
	Point2D center;
	double radius;

public:

	Circle() { center.setX(0); center.setY(0); radius = 0; }
	Circle(Point2D c, double r);

	void setCenter(Point2D c);
	void setRadius(double r);
	Point2D getCenter() const;
	double getRadius() const;
    void print() const; //prints the circle in the stdout

    Circle operator+(const Point2D rhs);
    Circle operator*(const double n);
    Circle operator+(const Circle rhs);
    Circle operator-(const Circle rhs);
    bool operator==(Circle rhs);
    bool operator>(Circle rhs);
    bool operator>=(Circle rhs);
    bool operator<(Circle rhs);
    bool operator<=(Circle rhs);

    Circle operator++(int number); // Prefix Increment
    Circle operator++(); // Postfix Increment

	~Circle() { center.setX(0); center.setY(0); radius = 0; }
};

Circle::Circle(Point2D c, double r)
{
	center.setX(c.getX());
	center.setY(c.getY());
	radius = r;
}

void Circle::setCenter(Point2D c)
{
    center.setX(c.getX());
    center.setY(c.getY());
}

void Circle::setRadius(double r)
{
    radius = r;
}

Point2D Circle::getCenter() const
{
    return center;
}

double Circle::getRadius() const
{
    return radius;
}

void Circle::print() const
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius<<endl;
}

// Added

Circle Circle::operator+(const Point2D rhs)
{
    return Circle( Point2D( center.getX()+rhs.getX() , center.getY()+rhs.getY() ) , radius );
}

Circle Circle::operator*(const double n)
{
    return Circle( Point2D( center.getX()*n , center.getY()*n ) , radius*n );
}

Circle Circle::operator+(const Circle rhs)
{
    double a = radius/ (radius+rhs.getRadius()) ;
    return Circle( center*a+rhs.getCenter()*(1-a) , radius+rhs.getRadius() );
}

Circle Circle::operator-(const Circle rhs)
{
    double a = radius/ (radius+rhs.getRadius()) ;
    return Circle( center*a+rhs.getCenter()*(1-a) , abs( radius-rhs.getRadius() ) );
}

bool Circle::operator==(Circle rhs)
{
    if( radius == rhs.getRadius() )
        return true;
    else
        return false;
}

bool Circle::operator>(Circle rhs)
{
    if( radius > rhs.getRadius() )
        return true;
    else
        return false;
}

bool Circle::operator>=(Circle rhs)
{
    if( radius >= rhs.getRadius() )
        return true;
    else
        return false;
}

bool Circle::operator<(Circle rhs)
{
    if( radius < rhs.getRadius() )
        return true;
    else
        return false;
}

bool Circle::operator<=(Circle rhs)
{
    if( radius <= rhs.getRadius() )
        return true;
    else
        return false;
}

Circle Circle::operator++(int number) // Postfix Increment
{
    return Circle( center , radius++ ); // Postfix increment of radius.So retunred circle will have radius

    //number is passed only to make compiler distinguish between postfix and prefix increment
}

Circle Circle::operator++() // Prefix Increment
{
    return Circle( center , ++radius ); // Prefix increment of raidus.Hence returned circle will also have radius+1
}

// Rectangle

class Rectangle
{
	Point2D topRightPoint,bottomLeftPoint;

	// rectangles are assumed to be parallel with X-Y axes

public:

    Rectangle() { topRightPoint.setX(0); topRightPoint.setY(0); bottomLeftPoint.setX(0); bottomLeftPoint.setY(0); }
    Rectangle(Point2D pointOne, Point2D pointTwo);

	void setTRPoint(Point2D point);
	void setBLPoint(Point2D point);
	Point2D getTRPoint() const;
	Point2D getBLPoint() const;

    Rectangle operator+(const Point2D rhs);
    Rectangle operator*(const double n);

	~Rectangle() { topRightPoint.setX(0); topRightPoint.setY(0); bottomLeftPoint.setX(0); bottomLeftPoint.setY(0); }
};

Rectangle::Rectangle(Point2D pointOne, Point2D pointTwo)
{
    topRightPoint.setX(pointOne.getX());
    topRightPoint.setY(pointOne.getY());
    bottomLeftPoint.setX(pointTwo.getX());
    bottomLeftPoint.setY(pointTwo.getY());
}

void Rectangle::setTRPoint(Point2D point)
{
    topRightPoint.setX(point.getX());
    topRightPoint.setY(point.getY());
}

void Rectangle::setBLPoint(Point2D point)
{
    bottomLeftPoint.setX(point.getX());
    bottomLeftPoint.setY(point.getY());
}

Point2D Rectangle::getTRPoint() const
{
    return topRightPoint;
}

Point2D Rectangle::getBLPoint() const
{
    return bottomLeftPoint;
}

// Added

Rectangle Rectangle::operator+(const Point2D rhs)
{
    return Rectangle( Point2D( topRightPoint.getX()+rhs.getX() , topRightPoint.getY()+rhs.getY() ) , Point2D( bottomLeftPoint.getX()+rhs.getX() , bottomLeftPoint.getY()+rhs.getY() ) );
}

Rectangle Rectangle::operator*(const double n)
{
    return Rectangle( Point2D( topRightPoint.getX()*n , topRightPoint.getY()*n ) , Point2D( bottomLeftPoint.getX()*n , bottomLeftPoint.getY()*n ) );
}

// main

int main(void)
{
    // Functionality of newly introduced functions are showed here

    // Point2D

    Point2D pointOne(1,2),pointTwo(4,7),pointThree(4,7);
    double value = 2.3;

    cout<< "Coordinates of Output Point : ";
    (pointOne+pointTwo).print();

    cout<< "Coordinates of Output Point : ";
    (pointOne*value).print();

    if(pointOne == pointTwo)
        cout<<"\nThey are same point"<<endl;
    else
        cout<<"\nThey are two different points"<<endl;

    if(pointThree == pointTwo)
        cout<<"\nThey are same point"<<endl;
    else
        cout<<"\nThey are two different points"<<endl;

    if(pointOne != pointThree)
        cout<<"\nThey are two different points"<<endl;
    else
        cout<<"\nThey are same point"<<endl;

    // Circle

    Circle circleOne(pointOne,1.2),circleTwo(pointTwo,4.7),circleThree(pointThree,2.3);

    cout<<"\ncircleOne + pointOne => "<<endl;
    (circleOne+pointOne).print();

    cout<<"\ncircleOne*value => "<<endl;
    (circleOne*value).print();

    cout<<"\ncircleOne + circleTwo => "<<endl;
    (circleOne+circleTwo).print();

    cout<<"\ncircleOne - circleThree => "<<endl;
    (circleOne-circleThree).print();

    if( circleOne == circleOne )
        cout<<"\nThey occupy same area"<<endl;
    else
        cout<<"\nThey occupy two different areas"<<endl;

    if( circleOne == circleTwo )
        cout<<"\nThey occupy same area"<<endl;
    else
        cout<<"\nThey occupy two different areas"<<endl;

    if( circleOne > circleTwo )
        cout<<"\ncircleOne > circleTwo"<<endl;
    else
        cout<<"\ncircleOne <= circleTwo"<<endl;

    if( circleTwo >= circleThree )
        cout<<"\ncircleTwo >= circleThree"<<endl;
    else
        cout<<"\ncircleTwo < circleThree"<<endl;

    if( circleOne < circleThree )
        cout<<"\ncircleOne < circleThree"<<endl;
    else
        cout<<"\ncircleOne >= circleThree"<<endl;

    if( circleTwo <= circleTwo )
        cout<<"\ncircleTwo <= circleTwo"<<endl;
    else
        cout<<"\ncircleTwo > circleTwo"<<endl;

    cout<<"\nNew circleTwo : "<<endl;
    (++circleTwo).print();

    cout<<"\nOld circleOne : "<<endl;
    (circleOne++).print();

    cout<<"\nNew circleOne : "<<endl;
    (circleOne).print();

    Circle circleA = ++circleThree;
    Circle circleB = circleOne++;

    cout<<"\nNew circleThree : "<<endl;
    circleThree.print();

    cout<<"\nNew circleOne : "<<endl;
    circleOne.print();

    cout<<"\ncircleA : "<<endl;
    circleA.print();

    cout<<"\ncircleB : "<<endl;
    circleB.print();

    // Rectangle

    Rectangle rectangle(pointTwo,pointOne);

    cout<< "\nTop Right Point of rectangle : ";
    rectangle.getTRPoint().print();
    cout<< "Bottom Left Point of rectangle : ";
    rectangle.getBLPoint().print();

    cout<< "\nTop Right Point of new rectangle : ";
    (rectangle + pointThree).getTRPoint().print();
    cout<< "Bottom Left Point of new rectangle : ";
    (rectangle + pointThree).getBLPoint().print();

    cout<< "\nTop Right Point of new rectangle : ";
    (rectangle*value).getTRPoint().print();
    cout<< "Bottom Left Point of new rectangle : ";
    (rectangle*value).getBLPoint().print();

	return 0;
}
