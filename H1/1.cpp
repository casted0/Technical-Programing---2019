#include <iostream>
using namespace std;

// v = 331.3 + 0.61T (v = meters/seconds) (T = temperature in Celsius)
// MAX temperature registered =  24º
// MIN temperature registered = -90º

int main(){

    int min;
    int max;

    do{
        cout << "Input a max temperature (max = 24º, min = -90º): ";
        cin >> max;
    }while((max > 25) || (max < -90));

    do{
        cout << "Input a min temperature (max = 24º, min = -90º): ";
        cin >> min;
    }while((min > 25) || (min < -90));

    for(int i = min; i <= max; i++){
        cout << "Velocity: " << (331.3 + 0.61*i) << "(m/s), Temperature: " << i << "(Cº)" << endl;
    }

    return 0;

}