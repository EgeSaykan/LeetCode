
#include<string>
#include<iostream>

using namespace std;


int main() {

    int min = (-1<<0x1f)-1;
    cout << min << endl;
    cout << (min<<1) << endl;
    cout << (min<<2) << endl;

    return 0;
}