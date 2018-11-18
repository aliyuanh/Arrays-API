#include <iostream>
#include <string>
#include <cassert>
//passing an array to a function does not pass the value of the array, it passes the actual array 
using namespace std;
int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

int main() {
	string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
	assert(lookup(h, 7, "eleni") == 5);
	assert(lookup(h, 7, "ed") == 2);
	assert(lookup(h, 2, "ed") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "greg", "gavin", "fiona", "kevin" };
	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "greg?" && g[3] == "kevin?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "fiona?" && g[3] == "gavin?");

	string e[4] = { "ed", "xavier", "", "eleni" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
	assert(countRuns(d, 5) == 2);

	string f[3] = { "fiona", "ed", "john" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "john" && f[2] == "fiona");

	assert(divide(h, 7, "fiona") == 3);

	cout << "All tests succeeded" << endl;
}
//works
int appendToAll(string a[], int n, string value) {
	//if n is negative, always return 0. 
	if (n < 0) {
		return -1;
	}
	//adds value to every string in array a
	for (int i = 0; i < n; i++) {
		a[i] += value;
	}
	return n;
}
//workz
int lookup(const string a[], int n, string target) {
	//if n is negative, always return 0. 

	if (n < 0) {
		return -1;
	}
	//iterates through the loop until it finds a string equal to target
	for (int i = 0; i < n; i++){
		if (a[i].compare(target)==0) {
			//returns the index of target inside array a
			return i;
		}
	}
	return -1;
}
//workz 
int positionOfMax(const string a[], int n) {
	int posMax = 0;
	//if there is no position to be found or n is negative, return -1 
	if (n <= 0) {
		return -1;
	}
	for (int i = 0; i < n; i++) {
		//if the string at i is greater than the string at posMax, the new maximum is i
		if (a[i].compare(a[posMax]) > 0) {
			posMax = i;
		}
	}
	return posMax;
}
//works DANK
int rotateLeft(string a[], int n, int pos) {
	//you cannot rotate an array of negative size. 
	if (n <= 0) {
		return -1;
	}
	//you cannot rotate from a point past the size of the array
	if (pos >= n) {
		return -1;
	}
	//you cannot rotate from a position that is before the start of the array. 
	if (pos < 0) {
		return -1;
	}
	//saves the array at index pos. 
	string first = a[pos];
	for (int i = pos; i < n - 1; i++) {
		//shifts everything over to the left by 1 except at the last index
		a[i] = a[i + 1];
	}
	//sets the string at the last index to the saved string first
	a[n - 1] = first;
	return pos;
}
//FIXED
int countRuns(const string a[], int n) {
	//	//you cannot count in an array of negative size. 
	if (n < 0) {
		return -1;
	}
	//if there is only one thing in the array, by definition, it must have 1 run of 1 element
	if (n == 1) {
		return 1;
	}
	//if the array is empty, there are no runs but n is not invalid
	if (n == 0) {
		return 0;
	}
	int numRuns = 1;
	//iterates through the array, checking if the element at index i is equal to at index i+1
	for (int i = 0; i < n-1; i++) {
		//if they are not equal, a new run has started so numRuns increments
		if (!(a[i] == a[i+1])) {
			numRuns++;
		}
	}
	return numRuns;
}
//works!
int flip(string a[], int n) {
	//you cannot flip an array of negative size 
	if (n < 0) {
		return -1;
	}
	//if there is only one element, it doesn't need to be switched
	if (n >= 2) {
		//iterates through the array n/2 times to avoid swapping again and ending with the original array 
		for (int i = 0; i < (n / 2); i++) {
			//swaps from both ends
			string temp = a[i];
			a[i] = a[n - i-1];
			a[n - i-1] = temp;		}
	}
	return n;
}
//works! 
int differ(const string a1[], int n1, const string a2[], int n2) {
	int min = 0;
	//if either arrays have a negative length, then they cannot be compared
	if (n1 < 0 || n2 < 0) {
		return -1;
	}
	//if the arrays are of a different size (n1>n2), then the latest place they can differ 
	//is at the lowest size. Min refers to the smaller size between both arrays. 
	if (n1 > n2) {
		min = n2;
	}
	else {
		min = n1;
	}
	//if both arrays are of length 0, they differ beginning at 0. 
	if (n1 == 0 && n2 == 0) {
		return 0;
	}
	//when they start to diverge, return that index. 
	for (int i = 0; i < min; i++) {
		if (a1[i] != a2[i]) {
			return i;
		}
	}
	//if they never diverge, then return the smaller size
	if (n1 > n2) {
		return n2;
	}
	return n1;
}
//worlks :)
int subsequence(const string a1[], int n1, const string a2[], int n2) {
	//n2 must be smaller than n1 because it is the sequence we're trying to find in a1
	//n1 must not be less than 0 because you cannot find a sequence in nothingness. 
	if (n2 > n1 || n1<0) {
		return -1;
	}
	//you can find the subsequence of nothingness at 0. 
	if (n2 == 0) {
		return 0;
	}
	bool matches = false;
	int start = -1;
	for (int i = 0; i < n1; i++) {
		//of any of a2 matches something in a1, it goes through a2
		if (a1[i] == a2[0]) {
			matches = true;
			start = i;
			for (int j = 0; j < n2; j++) {
				//if the subsequence breaks, then it no longer matches. 
				if (a1[i + j] != a2[j]) {
					matches = false;
					start = -1;
				}
			}
			//only if they matched for the entirety of a2 does it return the start of the subsequence. 
			if (matches == true) {
				return start;
			}
		}
	}
	//if there was no match, this will return -1. 
	return start;
}
//worksssssss
int lookupAny(const string a1[], int n1, const string a2[], int n2) {
	//goes through both arrays, and if anything matches, it returns the index in a1
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (a1[i] == a2[j]) {
				return i;
			}
		}
	}
	//if there is no match, then it returns -1. 
	//This also works for if n1 or n2 are less than 0, as it will never enter the for loops
	return -1;
}
//workie boi 
int divide(string a[], int n, string divider) {
	//you cannot divide an array of a length less than 0 
	if (n < 0) {
		return -1;
	}
	//alphabetizes the array a[]
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			//swaps elements of the array if they aren't in alphabetical order
			if (a[i] < a[k]) {
				string temp = a[i];
				a[i] = a[k];
				a[k] = temp;
			}
		}
	}
	//finds the index of the first !(string < divider)
	for (int i = 0; i < n; i++) {
		if (!(a[i] < divider)) {
			return i;
		}
	}
	//returns the size of the array if there is no spot where there is no element <divider
	//i.e. it returns the "index" of where the divider would be in the array--right after everything already there
	return n;
}

