#include <iostream>
#include <iomanip>
#include <cmath>
#include <List>

using namespace std;
int main()
{
  int n=5;
  list < double > table[3];

  for (int i=1; i<n+1; i++)
   { table[0].push_back(i);  table[1].push_back(sqrt(i)); table[2].push_back(log(i)); }

  list<double>::iterator it;
  cout << "\ntable[0] contains:" << setprecision(2);
	for ( it=table[0].begin(); it != table[0].end(); it++ )
	  cout << " " << setw(5) << *it;
  cout << "\ntable[1] contains:";
	for ( it=table[1].begin(); it != table[1].end(); it++ )
	  cout << " " << setw(5) << *it;
  cout << "\ntable[2] contains:";
	for ( it=table[2].begin(); it != table[2].end(); it++ )
	  cout << " " << setw(5) << *it;
  return 0;
}

