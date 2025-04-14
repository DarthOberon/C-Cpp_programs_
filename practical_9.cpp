# include <iostream>
using namespace std;

int main()
{
    double meter,feet;

    cout << "Enter number in meters: " << endl;
    cin >> meter;

    cout <<"Number endtered in meter is: " << meter << endl;
    
    // 1 meter = 3.28084 feet
    feet = meter * 3.28084;
    cout << "The value converted to feet is: "<< feet << endl;


}