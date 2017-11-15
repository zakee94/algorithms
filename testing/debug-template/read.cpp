#include <iostream>
#include <fstream>

using namespace std;
#define MAX 10

int main() {
	int arr[MAX], i, n = 0;
	ifstream inFile;

	inFile.open("test-cases.txt");

	if (inFile.is_open())
		while (inFile >> arr[n])
			n++;
	else
		cout << "Error opening file !\n";
	inFile.close();

	return 0;
}
