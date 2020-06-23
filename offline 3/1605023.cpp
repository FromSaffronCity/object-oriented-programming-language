#include<iostream>
#include<cmath>

using namespace std;

typedef enum {UNDEFINED, POINT2D, RECTANGLE, CIRCLE, POINT3D, SPHERE, SQUARE} STYPE;

// class Shape - it is an abstract class

class Shape
{
	STYPE type; // private - no problem

public:

	Shape();
	Shape(STYPE argtype);

	virtual void print(); // Other Functions
	virtual double area();
	virtual bool contains(const Shape *s); // NOTICE

	//Intentionally made non-virtual
	bool operator==(const Shape &rhs);  // NOTICE

	virtual ~Shape(){ }
};

Shape::Shape() // no matter what, the constructor of abstract base class will be called
{
	type = UNDEFINED;
}

Shape::Shape(STYPE argtype)
{
	type = argtype;
}

void Shape::print() // No need to type 'virtual' here
{
	cout << "\nType: " << type <<endl;

	// NOTICE : Enumeration constant have integer values and those integer values will be printed
	// Here : UNDEFINED = 0, POINT2D = 1, RECTANGLE = 2, CIRCLE = 3, POINT3D = 4, SPHERE = 5, SQUARE = 6
}

double Shape::area()
{
	cout << "You see this, because appropriate area() function is missing in the derived class"<<endl;

	return 0;
}

bool Shape::contains(const Shape *s)
{
	cout << "You see this, because appropriate contains() function is undefined"<<endl;

	return false; // return 0;
}

bool Shape::operator==(const Shape &rhs) // o1 == o2; => o1.operator==(o2);
{
	if(type==rhs.type) return true; // it works as in the same class
	else return false;
}


// class Point2D : public Shape

class Point2D : public Shape
{
	double x,y;

public:

	Point2D();
	Point2D(STYPE argtype, double argx, double argy);

	void print(); // overridden functions
	double area();
	bool contains(Shape *rhs); // NOTICE - problem with const keyword, so removed

	bool contains(const Point2D *s); // other functions // NOTICE
	bool operator==(const Point2D &rhs);

	void setX(double xVal) { x = xVal; } // Setter added
	void setY(double yVal) { y = yVal; }

	double getX() const { return x; }
	double getY() const { return y; }

	double distance(const Point2D *point); // New function introduced

    ~Point2D(){ }
};

Point2D::Point2D() // calls Base's default constructor at first
{
	x = y = 0;
}

Point2D::Point2D(STYPE argtype, double argx, double argy) : Shape(argtype) // calls parametered construcotr of base
{
	x = argx;
	y = argy;
}

void Point2D::print()
{
	Shape::print();

	cout << "Point : (" << x << "," << y << ")"<< endl;
}

double Point2D::area()
{
	return 0; // point does not have any area
}

bool Point2D::contains(Shape *s)
{
	Point2D *pointType = dynamic_cast<Point2D*>(s); // NOTICE - dynamic casting

	if(pointType!=NULL)
	{
		//Supported

		return contains(pointType); // argument sent to bool Point2D::contains(const Point2D *rhs);
	}

	//By default, use base

	return Shape::contains(s); // contains functon of Shape class called
}

bool Point2D::contains(const Point2D *rhs)
{
	if(x == rhs->x && y == rhs->y) return true; // possible as same class
	else return false;
}

bool Point2D::operator==(const Point2D &rhs)
{
	if( !Shape::operator==(rhs) ) return false; // Check this line

	if( x == rhs.x && y == rhs.y ) return true; // possible as same class
	else return false;
}

double Point2D::distance(const Point2D *point)
{
    return sqrt(( x - point->getX() )*( x - point->getX())  + ( y - point->getY() )*( y - point->getY() ));
}


// class Rectangle : public Shape

class Rectangle : public Shape
{
	Point2D topRight;
	Point2D bottomLeft;

public:

	Rectangle();
	Rectangle(STYPE argtype, Point2D tr, Point2D bl);

	void print();
	double area();

	bool contains(const Shape *s); //implemented only for containment of Point2D
	bool contains(const Point2D *rhs); // added

	bool operator==(const Rectangle &rhs); // Check this out

	const Point2D* getTR() const { return &topRight; } // getter added - NOTICE
	const Point2D* getBL() const { return &bottomLeft; } // Check this out - very important

	~Rectangle(){ }
};

Rectangle::Rectangle()
{
    Point2D origin(POINT2D, 0, 0);
    topRight = bottomLeft = origin; // Check this line
}

Rectangle::Rectangle(STYPE argtype, Point2D tr, Point2D bl) : Shape(argtype)
{
    topRight = tr;
    bottomLeft = bl;
}

void Rectangle::print()
{
    Shape::print();

    cout<<"Top Right Point : "; // Check here
    topRight.print();
    cout<<"Bottom Left Point :"; // Check here
    bottomLeft.print();
}

double Rectangle::area()
{
    return ( topRight.getX() - bottomLeft.getX() )*( topRight.getY() - bottomLeft.getY() );
}

bool Rectangle::contains(const Shape *s)
{
	const Point2D *pointType = dynamic_cast<const Point2D*>(s);

	if(pointType!=NULL)
	{
		//Supported
		return contains(pointType); // argument sent to bool Rectangle::contains(const Point2D *rhs);
	}

	//By default use the base function

	return Shape::contains(s);
}

bool Rectangle::contains(const Point2D *rhs)
{
    return ( ( (rhs->getX()) >= bottomLeft.getX() && (rhs->getX())<=topRight.getX() ) && ( (rhs->getY())>=bottomLeft.getY() && (rhs->getY())<=topRight.getY() ));
}

bool Rectangle::operator==(const Rectangle &rhs)
{
	if( !Shape::operator==(rhs) ) return false; // Check this line

	return ( topRight == rhs.topRight && bottomLeft == rhs.bottomLeft ); // possible as in the same class
}


// class Circle : public Shape

class Circle : public Shape
{
	Point2D center;
	double radius;

public:

	Circle();
	Circle(STYPE argtype, Point2D c, double r);

	double area();
	void print();

	bool contains(const Shape *s); // NOTICE
	bool contains(const Point2D *rhs);
	bool contains(const Circle *rhs);
	bool contains(const Rectangle *rhs); // Problem with const keyword, so removed
	bool operator==(const Circle &rhs);

	~Circle(){ }
};

Circle::Circle()
{
    Point2D point(POINT2D, 0, 0);
    center = point;
    radius = 0;
}

Circle::Circle(STYPE argtype, Point2D c, double r) : Shape(argtype)
{
    center = c;
    radius = r;
}

void Circle::print()
{
    Shape::print();

    cout<<"Center : "; // Check here
    center.print();
    cout<<"Radius = "<<radius<<endl;
}

double Circle::area()
{
    return 3.1416*radius*radius;
}

bool Circle::contains(const Shape *s)
{
	const Point2D *pointType = dynamic_cast<const Point2D*>(s);

	if(pointType!=NULL)
	{
		//Supported

		return contains(pointType); // argument sent to bool Circle::contains(const Point2D *rhs);
	}

	const Circle *circleType = dynamic_cast<const Circle*>(s);

	if(circleType!=NULL)
	{
		//Supported

		return contains(circleType); // argument sent to bool Circle::contains(const Circle *rhs);
	}

	const Rectangle *rectangleType = dynamic_cast<const Rectangle*>(s);

	if(rectangleType!=NULL)
	{
		//Supported BUT PROBLEM HERE : as rectangleType is a const pointer and argument here is not a const.

		return contains(rectangleType); // argument sent to bool Circle::contains(const Rectangle *rhs);
	}

	//By default use the base function

	return Shape::contains(s);
}

bool Circle::contains(const Point2D *rhs)
{
    return ( radius >= center.distance(rhs));
}

bool Circle::contains(const Circle *rhs)
{
    return ( radius >= ( rhs->radius + center.distance( &( rhs->center ) ) ) ); // NOTICE this line -_-
}

bool Circle::contains(const Rectangle *rhs)
{
    Point2D pointTR(POINT2D, rhs->getTR()->getX(), rhs->getTR()->getY()); // top right point
    Point2D pointBL(POINT2D, rhs->getBL()->getX(), rhs->getBL()->getY()); // bottom left point
    Point2D pointBR(POINT2D, rhs->getTR()->getX(), rhs->getBL()->getY()); // bottom right point
    Point2D pointTL(POINT2D, rhs->getBL()->getX(), rhs->getTR()->getY()); // top left point

    // NOTICE
    return !((radius < center.distance(&pointBL)) || (radius < center.distance(&pointTL)) || (radius < center.distance(&pointBR)) ||  (radius < center.distance(&pointTR)) );
}

bool Circle::operator==(const Circle &rhs)
{
	if( !Shape::operator==(rhs) ) return false; // Check this line

	if( center == rhs.center && radius == rhs.radius ) return true; // possible as same class
	else return false;
}


// class Point3D : public Point2D

class Point3D : public Point2D
{
    double z;

public:

    Point3D();
    Point3D(STYPE argtype, double argx, double argy, double argz); // NOTICE

    void print(); // Overridden Function

    // double area();
    // NOTICE : Not needed, base version is sufficient - area() of Point2D is called here

	bool contains(const Shape *s); // Overridden
	bool contains(const Point3D *rhs);  // NOTICE

	bool operator==(const Point3D &rhs); // NOTICE : Added Function

	double getZ() const { return z; } // Added getter

	double distance(const Point3D &rhs); // Introduced Function

	~Point3D(){ }
};

Point3D::Point3D() // Default constructor of Shape then Point2D will be called
{
    z = 0;
}

Point3D::Point3D(STYPE argtype, double argx, double argy, double argz) : Point2D(argtype,argx,argy)
{
    z = argz;
}

void Point3D::print()
{
	Shape::print(); // NOTICE

    cout << "Point : (" << getX() << "," << getY() << "," << z << ")"<<endl;
}

bool Point3D::contains(const Shape *s)
{
	const Point3D *pointType = dynamic_cast<const Point3D*>(s);

	if(pointType!=NULL)
	{
		//Supported

		return contains(pointType); // argument sent to bool Point3D::contains(const Point3D *rhs);
	}

	//By default use the base function

	return Shape::contains(s);
}

bool Point3D::contains(const Point3D *rhs)
{
    return ( *this == *rhs );
}

bool Point3D::operator==(const Point3D &rhs)
{
    if( !Shape::operator==(rhs) ) return false; // Check this line

    // NOTICE the following line - it worked for getZ() const; , but not for getZ();

    return ( (z == rhs.getZ()) && (getX() == rhs.getX()) && (getY() == rhs.getY()) );
}

double Point3D::distance(const Point3D &rhs)
{
    // NOTICE the following line
    // getX(), getY() are inherited in Point3D. so need not to use Point2D:: here

    return sqrt( ( z - rhs.z )*( z - rhs.z ) + ( getX() - rhs.getX() )*( getX() - rhs.getX() ) + ( getY() - rhs.getY())*( getY() - rhs.getY()) );

    // Possible as both in same class
}




// class Shape3D : public Shape - Shape3D is an abstract class

class Shape3D : public Shape
{

public:

	Shape3D();
	Shape3D(STYPE argtype);

	virtual double volume(); // NOTICE : Virtual Function

	// no print() function here
	// area() and print() functions inherited from Shape class

	~Shape3D(){ }
};

Shape3D::Shape3D() // default constructor of base - Shape() is called here
{

}

Shape3D::Shape3D(STYPE argtype) : Shape(argtype) // parametered constructor of base - Shape(STYPE argtype) is called here
{

}

double Shape3D::volume()
{
	cout << "You see this, because appropriate area() function is missing in the derived class";

	return 0;
}


// class Sphere : public Shape3D - NOTICE this entire class

class Sphere : public Shape3D
{
	Point3D center;
	double radius;

public:

	Sphere(); // NOTICE
	Sphere(STYPE argtype, Point3D c, double r); // NOTICE

	void print(); // NOTICE
	double area();
	double volume();

	bool contains(const Shape *s); //implemented for checking containment of Point3D, Sphere inside sphere
	bool contains(const Point3D *rhs); // NOTICE
	bool contains(const Sphere *rhs); // NOTICE

	~Sphere(){ }
};

Sphere::Sphere() // Shape() then Shape3D() will be called here
{
    Point3D point(POINT3D, 0, 0, 0);
    center = point;
    radius = 0;
}

Sphere::Sphere(STYPE argtype, Point3D c, double r) : Shape3D(argtype) // NOTICE : parametered constructor of Shape3D (not Shape) called here
{
    center = c;
    radius = r;
}

void Sphere::print()
{
    Shape::print();

    cout<<"Center : "; // Check here
    center.print();

    cout<<"Radius = "<<radius<<endl;
}

double Sphere::area()
{
    return 4*3.1416*radius*radius;
}

double Sphere::volume()
{
    return ((double)4/3)*3.1416*radius*radius*radius; // NOTICE

    // (4/3)*3.1416*radius*radius*radius did not work because (4/3) = 1 , integer division
}

bool Sphere::contains(const Shape *s)
{
	const Point3D *pointType = dynamic_cast<const Point3D*>(s);

	if(pointType!=NULL)
	{
		//Supported

		return contains(pointType); // argument sent to bool Sphere::contains(const Point3D *rhs);
	}

	const Sphere *sphereType = dynamic_cast<const Sphere*>(s);

	if(sphereType!=NULL)
	{
		//Supported

		return contains(sphereType); // argument sent to bool Sphere::contains(const Sphere *rhs);
	}

	//By default use the base function

	return Shape::contains(s);
}

bool Sphere::contains(const Point3D *rhs)
{
    return ( radius >= center.distance(*rhs) );

    // NOTICE this line - sending *rhs (not rhs) in double Point3D::distance(const Point3D &rhs)
}

bool Sphere::contains(const Sphere *rhs)
{
    return ( radius >= ( rhs->radius + center.distance( rhs->center ) ) );

    // NOTICE : Possible as in the same class
    // sending reference (not pointer) to distance() function
}


// int main(void)

int main(void)
{
	//Create circles, rectanges, point2d,point3d,and sphere objects using base class pointers
	//then call the virtual methods to show that polymorphism works!


	int choice;

    Shape *objShape;
    Shape3D *objShape3D;

	cout << "Options :\n1. Point2D 2. Rectangle 3. Circle 4. Point3D 5. Sphere. 0. Exit"<<endl;

	while(1)
	{
        cout << "\nYour choice : ";
        cin >> choice;

		switch(choice)
		{
            case 1: // Demo of Point2D
            {
                objShape = new Point2D(POINT2D, 5, 10);
                // Shape *obj = new Point2D(POINT2D, 5, 10);

                Point2D pointOne(POINT2D, 5, 10),pointTwo(POINT2D, 1, 2);

				objShape->print(); // Virtual Test
				cout << "Area: " << objShape->area()<<endl;

                if(  pointOne.contains(objShape) ) cout<<"pointOne - Same point"<<endl; // Function Test
                else cout<<"pointOne - Different points"<<endl;
                if(  pointTwo.contains(objShape) ) cout<<"pointTwo - Same point"<<endl;
                else cout<<"pointTwo - Different points"<<endl;

                // if(  obj->contains(objShape) ) cout<<"obj - Same point"<<endl; - Problem occurs
                // else cout<<"obj - Different points"<<endl;

				delete objShape;
				// delete obj;

				break;
            }

			case 2: // Demo of Rectangle
            {
                Point2D rp1(POINT2D,5,5),rp2(POINT2D,20,20),rp3(POINT2D, 1, 1),rp4(POINT2D, 6, 6);

				objShape = new Rectangle(RECTANGLE, rp1, rp2);

				Rectangle rectOne(RECTANGLE, rp4, rp3),rectTwo(RECTANGLE, rp1, rp2),rectThree(RECTANGLE, rp3, rp4);
				Shape *obj1 = new Point2D(POINT2D, 5,5);
				Shape *obj2 = new Point2D(POINT2D, 20,20);
                Shape *rectObj = new Rectangle(RECTANGLE, rp4, rp3);

				objShape->print(); // Virtual Test
				cout << "\nArea: " << objShape->area()<<endl;

				if( rectObj->contains(obj1) ) cout<<"\nobj1 is in rectObj"<<endl;
				else cout<<"\nobj1 is not in rectObj"<<endl;
				if( rectObj->contains(obj2) ) cout<<"\nobj2 is in rectObj"<<endl;
				else cout<<"obj2 is not in rectObj"<<endl;

				if( rectOne == rectTwo ) cout<<"\nrectOne == rectTwo"<<endl; // Function Test
				else cout<<"\nrectOne != rectTwo"<<endl;
				if( rectOne == rectThree ) cout<<"rectOne == rectThree"<<endl;
				else cout<<"rectOne == rectThree"<<endl;

				if( rectOne.contains(obj1) ) cout<<"\nobj1 is in rectOne"<<endl;
				else cout<<"\nobj1 is not in rectOne"<<endl;
				if( rectOne.contains(obj2) ) cout<<"obj2 is in rectOne"<<endl;
				else cout<<"obj2 is not in rectOne"<<endl;

                delete objShape;
				delete obj1;
				delete obj2;
				delete rectObj;

				break;
            }

			case 3: // Demo of Circle
            {
                Point2D cp1(POINT2D,0,0),cp2(POINT2D, 5, 5);

				objShape = new Circle(CIRCLE,cp1,10);

				Circle circle1(CIRCLE, cp1, 10),circle2(CIRCLE, cp2, 2),circle3(CIRCLE, cp1, 10);

				Shape *objC1 = new Circle(CIRCLE, cp1,11);
				Shape *objC2 = new Circle(CIRCLE, cp2,2);
				Shape *objRect = new Rectangle(RECTANGLE, cp2, cp1);
				Shape *objP1 = new Point2D(POINT2D, 11, 11);
				Shape *objP2 = new Point2D(POINT2D, 1, 1);

				objShape->print(); // Virtual Test
				cout << "\nArea: " << objShape->area()<<endl;

				if( objC1->contains( objP1 ) ) cout<<"\nobjP1 in objC1"<<endl;
				else cout<<"\nobjP1 not in objC1"<<endl;
				if( objC1->contains( objP2 ) ) cout<<"objP2 in objC1"<<endl;
				else cout<<"objP2 not in objC1"<<endl;
				if( objC1->contains( objC1 ) ) cout<<"objC1 in objC1"<<endl;
				else cout<<"objC1 not in objC1"<<endl;
				if( objC1->contains( objC2 ) ) cout<<"objC2 in objC1"<<endl;
				else cout<<"objC2 not in objC1"<<endl;
				if( objC1->contains( objRect ) ) cout<<"objRect in objC1"<<endl;
				else cout<<"objRect not in objC1"<<endl;


				if( circle1 == circle2 ) cout<<"\nc1 and c3 - same circle"<<endl; // Function Test
				else cout<<"\nc1 and c2 - different circles"<<endl;
				if( circle1 == circle3 ) cout<<"c1 and c3 - same circle"<<endl;
				else cout<<"c1 and c2 - different circles"<<endl;


				if( circle1.contains( objP1 ) ) cout<<"\nobjP1 in circle1"<<endl;
				else cout<<"\nobjP1 not in circle1"<<endl;
				if( circle1.contains( objP2 ) ) cout<<"objP2 in circle1"<<endl;
				else cout<<"objP2 not in circle1"<<endl;
				if( circle1.contains( objC1 ) ) cout<<"objC1 in circle1"<<endl;
				else cout<<"objC1 not in circle1"<<endl;
				if( circle1.contains( objC2 ) ) cout<<"objC2 in circle1"<<endl;
				else cout<<"objC2 not in circle1"<<endl;
				if( circle1.contains( objRect ) ) cout<<"objRect in circle1"<<endl;
				else cout<<"objRect not in circle1"<<endl;

				delete objShape;
				delete objC1;
				delete objC2;
				delete objP1;
				delete objP2;
				delete objRect;

				break;
            }

			case 4: // Demo of Point3D
            {
                objShape = new Point3D(POINT3D,5,10,20);

				objShape->print(); // Virtual Test
				cout << "\nArea: " << objShape->area()<<endl;

				Point3D point3D(POINT3D, 5, 10, 20);
				Shape *dot3D1 = new Point3D(POINT3D, 1, 2, 3);
				Shape *dot3D2 = new Point3D(POINT3D, 5, 10, 20);

				if( point3D.contains( objShape ) ) cout<<"\npoint3D and objShape - same point"<<endl; // Function Test
				else cout<<"point3D and objShape - different points"<<endl;
				if( point3D.contains( dot3D1 ) ) cout<<"point3D and dot3D1 - same point"<<endl;
				else cout<<"point3D and dot3D1 - different points"<<endl;

				if( dot3D2->contains( objShape ) ) cout<<"\ndot3D2 and objShape - same point"<<endl; // Virtual Test
				else cout<<"dot3D2 and objShape - different points"<<endl;

				if( dot3D1->contains( objShape ) ) cout<<"dot3D1 and objShape - same point"<<endl;
				else cout<<"dot3D1 and objShape - different points"<<endl;

				delete objShape;
				delete dot3D1;
				delete dot3D2;

				break;
            }

			case 5: // Demo of Sphere
            {
                Point3D sp1(POINT3D,0,0,0),sp2(POINT3D, 3, 3, 3);

				objShape3D = new Sphere(SPHERE,sp1,10);
				Sphere sphereObj(SPHERE, sp1, 10);

				Shape *objectP1 = new Point3D(POINT3D,0,0,0);
				Shape *objectP2 = new Point3D(POINT3D,11,11,11);
				Shape *objectS1 = new Sphere(SPHERE, sp2, 4);
				Shape *objectS2 = new Sphere(SPHERE, sp1, 14);


				objShape3D->print(); // Virtual Test
				cout << "\nArea: " << objShape3D->area()<<endl;
				cout << "Volume: " << objShape3D->volume()<<endl;

				if( objShape3D->contains( objectP1 ) ) cout<<"\nP1 in objShape3D"<<endl;
				else cout<<"P1 not in objShape3D"<<endl;
				if( objShape3D->contains( objectP2 ) ) cout<<"P2 in objShape3D"<<endl;
				else cout<<"P2 not in objShape3D"<<endl;
				if( objShape3D->contains( objectS1 ) ) cout<<"S1 in objShape3D"<<endl;
				else cout<<"S1 not in objShape3D"<<endl;
				if( objShape3D->contains( objectS2 ) ) cout<<"S2 in objShape3D"<<endl;
				else cout<<"S2 not in objShape3D"<<endl;

				if( sphereObj.contains( objectP1 ) ) cout<<"\nP1 in sphereObj"<<endl; // Function test
				else cout<<"P1 not in sphereObj"<<endl;
				if( sphereObj.contains( objectP2 ) ) cout<<"P2 in sphereObj"<<endl;
				else cout<<"P2 not in sphereObj"<<endl;
				if( sphereObj.contains( objectS1 ) ) cout<<"S1 in sphereObj"<<endl;
				else cout<<"S1 not in sphereObj"<<endl;
				if( sphereObj.contains( objectS2 ) ) cout<<"S2 in sphereObj"<<endl;
				else cout<<"S2 not in sphereObj"<<endl;

                delete objShape3D;
                delete objectP1;
                delete objectP2;
                delete objectS1;
                delete objectS2;

				break;
            }
		}

		if(choice==0)break;
	}

	return 0;
}
