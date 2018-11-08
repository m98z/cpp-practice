#include <iostream>
#include <vector>

using namespace std;


class Shape{
public:
    virtual double Area()=0;
    virtual void   Draw()=0;
};

class Circle:public Shape{
private:
    double radius;
public:
    double Area(){

    }
    void   Draw(){

    }
};

class Rectangle:public Shape{
private:
    int width;
    int length;
public:
    double Area(){

    }
    void   Draw(){
        
    }
};

class Trinangle:public Shape{
private: 
    int height;
    int base;
public:
    double Area(){

    }
    void   Draw(){
        
    }
};

int main(){
    return 0;
}