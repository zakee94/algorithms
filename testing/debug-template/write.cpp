#include <iostream>
#include <fstream>

using namespace std;
#define MAX 10

int main() {
	int arr[MAX] = {1,2,3,4,5,6,7,8,9,10};
    int i;

    ofstream outFile;
    outFile.open("input.txt");

    for (i = 0; i < MAX; i++)
        outFile << arr[i] << "\n";

    outFile.close();

	return 0;
}
