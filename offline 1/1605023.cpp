#include<iostream>
#include<cmath>

using namespace std;

class Point2D
{
	int x,y;

public:

	Point2D(){ x = 0; y = 0; } //default constructor initializes to (0,0)
	Point2D(int argx, int argy);

	void setX(int argx);
	void setY(int argy);
	int getX();
	int getY();
	void print();

	~Point2D(){ x = 0; y = 0; } //destructor that sets all values to 0
};

Point2D::Point2D(int argx,int argy) // We can pass a Point2D object to set X,Y (for setter getter also)
{
	x = argx;
	y = argy;
}

void Point2D::setX(int argx)
{
	x = argx;
}

void Point2D::setY(int argy)
{
	y = argy;
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}

void Point2D::print()
{
	cout << "(" << x << "," << y << ")"<<endl;
}


class Circle
{
	Point2D center;
	double radius;

public:

	Circle() { center.setX(0); center.setY(0); radius = 0; }
	Circle(Point2D c, double r);

	void setCenter(Point2D c);
	void setRadius(double r);
	Point2D getCenter();
	double getRadius();

	double area(); //returns area of the circle
    void print(); //prints the circle in the stdout

	int intersect(Circle rhs); //determine if this circle intersects with rhs
	int contains(Circle rhs); //determine if this circle contains circle rhs
	int contains(Point2D p); //determine if this circle contains point p
	double perimeter(); //returns perimeter of the circle

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

Point2D Circle::getCenter()
{
    return center;
}

double Circle::getRadius()
{
    return radius;
}

double Circle::area()
{
	return 3.1416*radius*radius;
}

void Circle::print()
{
	cout << "Center: ";
	center.print();
	cout << "Radius: " << radius<<endl;
}

int Circle::intersect(Circle rhs)
{
	double radiusLength = radius + rhs.getRadius();
	double centerLength = sqrt((double)(pow(center.getX()-rhs.getCenter().getX(),2)+pow(center.getY()-rhs.getCenter().getY(),2)));

	double distance = ( radius>=rhs.getRadius() ) ? rhs.getRadius()+centerLength : radius+centerLength;
	double maxRadius = ( radius>=rhs.getRadius() ) ? radius : rhs.getRadius();

	if( radiusLength < centerLength )
        return 0;
    else if ( radiusLength == centerLength )
        return 0; // As the two circles touch (not intersect) each other, then
    else
    {
        if( maxRadius >= distance )
            return 0; // As two circles either touch each other or have no contact between them, then
        else
            return 1; // Now they intersect each other
    }
}

int Circle::contains(Circle rhs)
{
	if( radius < rhs.getRadius() )
        return 0; // As this circle is comperatively small to contain the passed circle
    else if ( radius == rhs.getRadius() )
    {
        if( (center.getX() == rhs.getCenter().getX()) && (center.getY() == rhs.getCenter().getY()) )
            return 1;
        else
            return 0;
    }
    else
    {
        double centerLength = sqrt((double)(pow(center.getX()-rhs.getCenter().getX(),2)+pow(center.getY()-rhs.getCenter().getY(),2)));

        if( radius >= rhs.getRadius() + centerLength )
            return 1;
        else
            return 0;
    }
}

int Circle::contains(Point2D p)
{
    double distance = sqrt((double)(pow(center.getX()-p.getX(),2)+pow(center.getY()-p.getY(),2)));

    if( radius >= distance )
        return 1;
    else
        return 0;
}

double Circle::perimeter()
{
    return 2*3.1416*radius;
}

class Rectangle
{
	Point2D topRightPoint,bottomLeftPoint;

	// rectangles are assumed to be parallel with X-Y axes

public:

    Rectangle() { topRightPoint.setX(0); topRightPoint.setY(0); bottomLeftPoint.setX(0); bottomLeftPoint.setY(0); }
    Rectangle(Point2D pointOne, Point2D pointTwo);

	void setTRPoint(Point2D point);
	void setBLPoint(Point2D point);
	Point2D getTRPoint();
	Point2D getBLPoint();

    double area(); //returns area of the rectangle
    int intersect(Rectangle rhs); //determine if this rectangle intersects with rhs
    int contains(Rectangle rhs); //determine if this rectangle contains rhs
    int inside(Circle c); //determine if this rectangle is completely inside the circle c
    double perimeter(); //returns perimeter of the circle

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

Point2D Rectangle::getTRPoint()
{
    return topRightPoint;
}

Point2D Rectangle::getBLPoint()
{
    return bottomLeftPoint;
}

double Rectangle::area()
{
    return (double) ( (topRightPoint.getX() - bottomLeftPoint.getX())*(topRightPoint.getY() - bottomLeftPoint.getY()) );
}

int Rectangle::intersect(Rectangle rhs)
{
    int rightX1 = topRightPoint.getX(), rightY1 = topRightPoint.getY();
    int leftX1 = bottomLeftPoint.getX(), leftY1 = bottomLeftPoint.getY();
    int rightX2 = rhs.getTRPoint().getX(), rightY2 = rhs.getTRPoint().getY();
    int leftX2 = rhs.getBLPoint().getX(), leftY2 = rhs.getBLPoint().getY();


    if(leftX1>rightX2 || rightX1<leftX2)
        return 0;
    if(leftY1>rightY2 || rightY1<leftY2)
        return 0;
    if(leftX1>leftX2 && rightX1<rightX2)
        if(leftY1>leftY2 && rightY1<rightY2)
            return 0; // passed rectangle contains this rectangle
    if((leftX1<=leftX2 && leftX2<=rightX1) && (leftX1<=rightX2 && rightX2<=rightX1))
        if((leftY1<=leftY2 && leftY2<=rightY1) && (leftY1<=rightY2 && rightY2<=rightY1))
            return 0; // passed rectangle is contained in this rectangle (or they perfectly overlap on each other)

    return 1;
}

int Rectangle::contains(Rectangle rhs)
{
    int rightX1 = topRightPoint.getX(), rightY1 = topRightPoint.getY();
    int leftX1 = bottomLeftPoint.getX(), leftY1 = bottomLeftPoint.getY();
    int rightX2 = rhs.getTRPoint().getX(), rightY2 = rhs.getTRPoint().getY();
    int leftX2 = rhs.getBLPoint().getX(), leftY2 = rhs.getBLPoint().getY();

    if((leftX1<=leftX2 && leftX2<=rightX1) && (leftX1<=rightX2 && rightX2<=rightX1))
        if((leftY1<=leftY2 && leftY2<=rightY1) && (leftY1<=rightY2 && rightY2<=rightY1))
            return 1; // passed rectangle is contained in this rectangle (or they perfectly overlap on each other)

    return 0;
}

int Rectangle::inside(Circle c)
{
    int rightX = topRightPoint.getX(), rightY = topRightPoint.getY();
    int leftX = bottomLeftPoint.getX(), leftY = bottomLeftPoint.getY();

    int centerX = c.getCenter().getX(), centerY = c.getCenter().getY();

    if(c.getRadius() < sqrt(pow(rightX-centerX,2) + pow(rightY-centerY,2)))
        return 0;
    if(c.getRadius() < sqrt(pow(rightX-centerX,2) + pow(leftY-centerY,2)))
        return 0;
    if(c.getRadius() < sqrt(pow(leftX-centerX,2) + pow(rightY-centerY,2)))
        return 0;
    if(c.getRadius() < sqrt(pow(leftX-centerX,2) + pow(leftY-centerY,2)))
        return 0;

    return 1;
}

double Rectangle::perimeter()
{
    int rightX = topRightPoint.getX(), rightY = topRightPoint.getY();
    int leftX = bottomLeftPoint.getX(), leftY = bottomLeftPoint.getY();

    return (double) ( 2*((rightX-leftX) + (rightY-leftY)) );
}


int main(void)
{
    // Circle

    Point2D center1(2,3),center2;

    cout<<"center1 = ";
    center1.print();
    cout<<"center2 = ";
    center2.print();

    center2.setX(4);
    center2.setY(7);

    cout<<"\ncenter2 = ";
    center2.print();

    Circle circle1,circle2(center2,2.45);

    cout<<"\ncircle1 - ";
    circle1.print();
    cout<<"circle2 - ";
    circle2.print();

    circle1.setCenter(center1);
    circle1.setRadius(1.51);

    cout<<"\ncircle1 - ";
    circle1.print();

    cout<<"\nArea of circle1 = "<<circle1.area()<<" unit"<<endl;
    cout<<"Area of circle2 = "<<circle2.area()<<" unit"<<endl;

    Point2D center3(1,2),center4(2,3);
    Circle circle3(center3,2),circle4(center4,2);

    cout<<"\ncircle3 - ";
    circle3.print();
    cout<<"circle4 - ";
    circle4.print();

    if(circle1.intersect(circle2))
        cout<<"\ncircle1 and circle2 intersect each other"<<endl;
    else
        cout<<"\ncircle1 and circle2 do not intersect each other"<<endl;
    if(circle3.intersect(circle4))
        cout<<"\ncircle3 and circle4 intersect each other"<<endl;
    else
        cout<<"\ncircle3 and circle4 do not intersect each other"<<endl;

	Point2D center5(4,5),center6(5,6);
    Circle circle5(center5,8),circle6(center6,2);

    cout<<"\ncircle5 - ";
    circle5.print();
    cout<<"circle6 - ";
    circle6.print();

    if(circle5.contains(circle6))
        cout<<"\ncircle5 contains circle6 in it"<<endl;
    else
        cout<<"\ncircle5 does not contain circle6 in it"<<endl;
    if(circle6.contains(circle5))
        cout<<"\ncircle6 contains circle5 in it"<<endl;
    else
        cout<<"\ncircle6 does not contain circle5 in it"<<endl;

    cout<<"\nPerimeter of circle1 = "<<circle1.perimeter()<<" unit"<<endl;

    if(circle5.contains(center6))
        cout<<"\nPoint center6 is inside the circle5"<<endl;
    else
        cout<<"\nPoint center6 is outside the circle5"<<endl;
    if(circle3.contains(center6))
        cout<<"\nPoint center6 is inside the circle3"<<endl;
    else
        cout<<"\nPoint center6 is outside the circle3"<<endl;


    // Rectangle

    Point2D pointTR1(4,3),pointBL1(0,0),pointTR2(7,8),pointBL2(2,3);

    Rectangle rectangle1,rectangle2(pointTR2,pointBL2);

    rectangle1.setTRPoint(pointTR1);
    rectangle1.setBLPoint(pointBL1);

    cout<<"\nArea of rectangle1 = "<<rectangle1.area()<<" unit"<<endl;
    cout<<"Area of rectangle2 = "<<rectangle2.area()<<" unit"<<endl;

	if(rectangle1.intersect(rectangle2))
        cout<<"\nrectangle1 intersects rectangle2"<<endl;
    else
        cout<<"\nrectangle1 does not intersect rectangle2"<<endl;

	Point2D pointTR3(4,5),pointBL3(3,2),pointTR4(10,11),pointBL4(0,0);

	Rectangle rectangle3(pointTR3,pointBL3),rectangle4(pointTR4,pointBL4);

	if(rectangle3.contains(rectangle4))
        cout<<"\nrectangle3 contains rectangle4 in it"<<endl;
    else
        cout<<"\nrectangle3 does not contain rectangle4 in it"<<endl;
    if(rectangle4.contains(rectangle3))
        cout<<"\nrectangle4 contains rectangle3 in it"<<endl;
    else
        cout<<"\nrectangle4 does not contain rectangle3 in it"<<endl;

    if(rectangle3.inside(circle5))
        cout<<"\nrectangle3 is completely inside the circle5"<<endl;
    else
        cout<<"\nrectangle3 is not completely inside the circle5"<<endl;
	if(rectangle4.inside(circle5))
        cout<<"\nrectangle4 is completely inside the circle5"<<endl;
    else
        cout<<"\nrectangle4 is not completely inside the circle5"<<endl;

    cout<<"\nPerimeter of rectangle4 = "<<rectangle4.perimeter()<<" unit"<<endl;

	return 0;
}
