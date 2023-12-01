#include <iostream>
#include <cmath>
using namespace std;

float func(float x, float y){
    float a = -1.5, b = -2.7, c = 0.6;
    return a * y + b * (x-1) * (x-1);
//    return x * x + y;
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

float rungeKutta(float a, float b, float c){
    float right = 2, x = 0, y = c, h = 0.5;
    float k0, k1, k2, k3;
    cout << "--------Runge-Kutta-----------"<<endl;
    int i = 1;
    while(x < right){//             ;)
        k0 = func(x, y);
        k1 = func(x+(h/2), y+((h*k0)/2));
        k2 = func(x+(h/2), y+((h*k1)/2));
        k3 = func(x+h, y+h*k2);
        y += h/6 * (k0 + 2*k1 + 2*k2 + k3);
        x += h;
        cout << "k0 = " << k0 << ";   "<< "k1 = " << k1 << ";   "<< "k2 = " << k2 << ";   "<< "k3 = " << k3 << ";   "<< endl;
        cout << "y" << i << " = " << y << "      for x = " << x << endl << endl;
        i++;
        
    }
    return y;
}


int main(){
    float a = -1.5, b = -2.7, c = 0.6; // менять тут и в func(первая функция)
    eiler(a, b, c);
    kEiler(a, b, c);
    rungeKutta(a, b, c);
    
}
