#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

# define PI           3.14159265358979323846  /* pi */

int power(int b,int t);

class Shape{
protected:
    double area;
public:
    virtual double Area()=0;
    virtual void   Draw()=0;
};

class Circle:public Shape{
private:
    double radius;
public:
    Circle(double r = 1):radius(r){};
    double Area(){
        area=PI*power(radius,2);
        return area;
    }
    void   Draw(){
        cout<<"Circle with radius: "<<radius<<endl;
    }
    int getRadius(){
        return radius;
    }
    void setRaduis(int r){
        radius=r;
    }
};

class Rectangle:public Shape{
private:
    int width;
    int length;
public:
    Rectangle(int l= 3,int w =4):length(l),width(w){};
    double Area(){
        area=width*length;
        return area;
    }
    void   Draw(){
        cout<<"Rectangle with length: "<<length<<",width: "<<width<<endl;
    }
    int getWidth(){
        return width;
    }
    void setWidth(int w){
        width=w;
    }
    int getLength(){
        return length;
    }
    void setLength(int l){
        length=l;
    }
};

class Triangle:public Shape{
private: 
    int height;
    int base;
public:
    Triangle(int h= 3,int b =4):height(h),base(b){};
    double Area(){
        area=0.5*height*base;
        return area;
    }
    void   Draw(){
         cout<<"Triangle with height: "<<height<<",base: "<<base<<endl;
    }
    int getHeight(){
        return height;
    }
    void setHeight(int h){
        height=h;
    }
    int getBase(){
        return base;
    }
    void setBase(int b){
        base=b;
    }
};

int power(int a,int t){
    int mypower = 1;
    while(t!=0){
        mypower*=a;
        t--;
    }
    return mypower;
}
int main(){
    return 0;
}