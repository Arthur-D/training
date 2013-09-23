#include <iostream>
using namespace std;

int main ()
{
  cout << "Please input two numbers; one for width, followed by a separator, and one for height.\n";
  int width;
  int height;
  int c = 0;
  int d = 0;
  int f = 0;
  cin >> width >> height;
  for (; c!=width; c++) {
	  cout << "*";
  }
  cout << "\n";
  for (; d!=height-2; d++) {
	  cout << "*";
	  	  for (int e=0; e!=width-2; e++) {
		      cout << " ";
	      }
	  cout << "*\n";
  }
  for (; f!=width; f++) {
  cout << "*";
  }
  cout << "\nMommy, it's over!";
  return 0;
}
