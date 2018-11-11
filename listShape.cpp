#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include<math.h>

using namespace std;

# define PI           3.14159265358979323846  /* pi */

double power(double b, int t);

class Shape {
public:
	friend  class ListShapes;
	virtual double Area() = 0;
	virtual void   Draw() = 0;
};

class ListShapes{
	int count;
	int size;
	Shape** shapes;
public:
	int getCount(){
		return count;
	}

	ListShapes(int n = 4){
		count = 0;
		shapes = new Shape*[n];
		size = n;
	}

	~ListShapes(){
		if (shapes != NULL)
			delete[] shapes;
		shapes = NULL;
	}

	Shape* getShape(int index){
		return shapes[index];
	}

	int  getIndex(Shape* sh) {
		for (int i = 0; i < count; i++) {
			if (shapes[i] == sh) {
				return i;
			}
		}
		return -1;
	}

	void expandList(ListShapes& sh, int s) {
		ListShapes tempsh(s);
		for (int i = 0; i < sh.count; i++)
			tempsh.shapes[i] = sh.shapes[i];
		
		tempsh.count = sh.count;
		sh.~ListShapes();
		sh = tempsh;
	}

	void addShape(Shape* sh) {
		if (count == size)
			expandList(this, 2 * size);
		insert(sh, count);
	}

	void insert(Shape* sh, int index){
		if (index <= -1)
		{
			cout << "Index should be non-negative." << endl;
			return;
		}
		if (index>count)
			index = count;
		for (int i = count - 1; i >= index; i--)
			shapes[i + 1] = shapes[i];
		shapes[index] = sh;
		count++;
	}

	int RemoveShape(Shape* sh) {
		int index = getIndex(sh);
		if (index <= -1)
		{
			cout << "There isn't such Shape to remove." << endl;
			return -1;
		}
		for (int i = index + 1; i < count; i++)
			shapes[i - 1] = shapes[i];
		shapes[count - 1] = nullptr;
		count--;
		cout << "Sucessfully removed." << endl;
		return 0;
	}

	void SortShapes() {
		for (int i = 1; i < count; i++) {
			for (int j = 0; j < count - i; j++) {
				if ((this)->shapes[j]->Area() > this->shapes[j + 1]->Area()) {
					Shape* temp = this->shapes[j];
					this->shapes[j] = this->shapes[j + 1];
					this->shapes[j + 1] = temp;
				}
			}
		}
	}

	void printShapesByArea() {
		for (int i = 0; i < count; i++) {
			cout << this->shapes[i]->Area() << endl;
		}
	}

	void printShapesByDraw() {
		for (int i = 0; i < count; i++) {
			this->shapes[i]->Draw();
		}
	}
};
class Circle :public Shape {
private:
	double radius;
	double area;
public:
	Circle(double r = 1) :radius(r) ,area(Area()){};
	double Area() {
		area = PI*power(radius, 2);
		return area;
	}
	void   Draw() {
		cout << "Circle with radius: " << radius << endl;
	}
	double getRadius() {
		return radius;
	}
	void setRaduis(int r) {
		radius = r;
	}
};

class Rectangle :public Shape {
private:
	int width;
	int length;
	double area;
public:
	Rectangle(int l = 3, int w = 4) :length(l), width(w) ,area(Area()){};
	double Area() {
		area = width*length;
		return area;
	}
	void   Draw() {
		cout << "Rectangle with length: " << length << ",width: " << width << endl;
	}
	int getWidth() {
		return width;
	}
	void setWidth(int w) {
		width = w;
	}
	int getLength() {
		return length;
	}
	void setLength(int l) {
		length = l;
	}
};

class Triangle :public Shape {
private:
	int height;
	int base;
	double area;
public:
	Triangle(int h = 3, int b = 4) :height(h), base(b) ,area(Area()){};
	double Area() {
		area = 0.5*height*base;
		return area;
	}
	void   Draw() {
		cout << "Triangle with height: " << height << ",base: " << base << endl;
	}
	int getHeight() {
		return height;
	}
	void setHeight(int h) {
		height = h;
	}
	int getBase() {
		return base;
	}
	void setBase(int b) {
		base = b;
	}
};

double power(double a, int t) {
	double mypower = 1;
	while (t != 0) {
		mypower *= a;
		t--;
	}
	return mypower;
}
int main() {
	return 0;
}