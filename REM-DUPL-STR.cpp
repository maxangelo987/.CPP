#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

void removeDupWord(string str)
{
	// Used to split string around spaces.
	istringstream ss(str);

	// To store individual visited words
	unordered_set<string> hsh;

	// Traverse through all words
	do
	{
		string word;
		ss >> word;

		// If current word is not seen before.
		while (hsh.find(word) == hsh.end()) {
			cout << word << " ";
			hsh.insert(word);
		}

	} while (ss);
}

// Driver function
int main()
{
	string str = "hello hello hi";
	removeDupWord(str);
	return 0;
}
