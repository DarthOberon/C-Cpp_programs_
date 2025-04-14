# include <iostream>
# include<cmath>
using namespace std;

int main()
{
    double number;

    cout <<"Enter the base: "<<endl;
    cin >> number;

    cout << "\nResults:\n";
    cout << number << " ^2 = " <<pow(number,2) << endl;
    cout << number << " ^3 = " <<pow(number,3) << endl;
    cout << number << " ^4 = " <<pow(number,4) << endl;
}