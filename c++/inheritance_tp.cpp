
#include <iostream>
#include <array>
using namespace std;


class shape {       
   // Access specifier
  public:             
    float width;
    float height;

    // Constructor with parameters
    shape(float x, float y) { 
      width = x;
      height = y;
    }
};

class triangle:public shape{
    public:
     float area(float w, float h);
     triangle(float x, float y): shape(x, y){
         
     }
};

class rectangle:public shape{
    public:
     float area(float w, float h);
     rectangle(float x, float y) : shape(x, y){

     }

     

};

float rectangle::area(float w, float h) {
    return w*h;
}

float triangle::area(float w, float h) {
    return w*h/2;
}

int main(){
    triangle T(5,4);
    rectangle R(5,4);
    float area_T = T.area(T.width, T.height);
    cout << "area of the triangle: " << area_T<<endl;

    float area_R = R.area(R.width, R.height);
    cout << "area of the rectangle: " << area_R<<endl;

    return 0;
}