/*Your program will tell whether the number given by the user is the summation of any three numbers in the array. Also
print the three numbers whose sum is equal to the given number.*/

#include<iostream>
using namespace std;
int main() {
	int n; cout << "Enter a number: "; cin >> n;
	bool check = true;
	
	int arr[9] = {9,4,54,23,54,-23,0,54,58};
	for (int i = 0; i < 7; i++) {
		for (int j = i + 1; j < 8; j++)
		{
			for (int k = i+2; k < 9; k++) {
				if (arr[i] + arr[j] + arr[k] == n)
				{
					cout << "(" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
				}
			}
		}	
  }

	
	
  	return 0;
}
