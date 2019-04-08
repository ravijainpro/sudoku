#include <iostream>
using namespace std;
int main() {
    int *i=new int;
    *i=5;
    cout << "\nBEFORE DELETE i= " << *i << " ADDRESS = " << i << "\n";
    delete i;
    i=NULL;
    cout << "\nAFTER DELETE i= " << *i << " ADDRESS = " << i << "\n";
    return 0;
}