#include <iostream>
#include <string>

using namespace std;

// Function to return the total palindromic subsequence
int Solve(string str, int i, int j) {
	if (i == j) // Base case: when the indices are the same, there is one palindrome
		return 1;

	if (i > j) // Base case: when the first index is greater than the second, there are no palindromes
		return 0;

	if (str[i] == str[j]) {
		// If the characters at indices i and j are the same, we can form palindromic subsequences
		// by including or excluding both characters, so we add 1 and make recursive calls.
		return 1 + Solve(str, i + 1, j) + Solve(str, i, j - 1);
	} else {
		// If the characters at indices i and j are different, we exclude one of them and make recursive calls.
		return Solve(str, i + 1, j) + Solve(str, i, j - 1) - Solve(str, i + 1, j - 1);
	}
}

// Driver program
int main() {
	string str = "abcb";
	cout << "Total palindromic subsequence are: " << Solve(str, 0, str.length() - 1) << endl;
	return 0;
}
