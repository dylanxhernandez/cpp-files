/*

 A basic function to check if a number is odd or even

*/

#include <iostream>
using namespace std;

int main() {
  int n;

  cout << "Enter an integer: ";
  cin >> n;
   
  /*

  This function uses a ternary operator, however a basic if else can also be used here:
  if ( n % 2 == 0)
    cout << n << " is even.";
  else
    cout << n << " is odd.";

  /*
 
  (n % 2 == 0) ? cout << n << " is even." :  cout << n << " is odd.";
    
  return 0;
}
