#include <iostream>
#include <cmath>
using namespace std;

float func(float x, float y){
    float a = -1.5, b = -2.7, c = 0.6;
    return a * y + b * (x-1) * (x-1);
}

float eiler(float a, float b, float c){
    float right = 2, x = 0, y = c, h = 0.5;
    cout << "--------Eiler-----------"<<endl;
    int i = 1;
    while(x < right){
        y = y + h*func(x, y);
        x += h;
        cout << "y" << i << " = " << y << "      for x = " << x << endl;
        i++;
    }
    return y;
}

float kEiler(float a, float b, float c){
    float right = 2, x = 0, y = c, h = 0.5;
    cout << "--------Koshi-Eiler-----------"<<endl;
    int i = 1;
    while(x < right){
        y = h/2 * (func(x, y) + func(x+h, y+h*func(x, y)));
        x += h;
        cout << "y" << i << " = " << y << "      for x = " << x << endl;
        i++;
    }
    return y;
}




int main(){
    float a = -1.5, b = -2.7, c = 0.6; // менять тут и в func(первая функция)
    eiler(a, b, c);
    kEiler(a, b, c);
    
}
