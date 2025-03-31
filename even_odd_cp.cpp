#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter any Integer:";

    cin >> n;

    cout << "The number you entered is:" << n;

    if(n%2 == 0)
    {
        cout << "The number is Even";
    }
    else{
        cout << "The number is Odd";
    }
    return 0;
    
}

