/*
Luke Mason, Alex Hollier, Kyle, Simon
Project for Data Structures
*/

#include <iostream>
using namespace std;

void CountSort(int array[], int size) {
	int min;
	int max;
	int range;
	int countIndex;
	int sortIndex;

	min = findmin(array[],size);
	max = findmax(array[],size);
	range = max-min;
	int countArray[range];
	for (int i = 0; i < range; i++) {
		countArray[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		countIndex = array[i];
		countArray[countIndex]++;
	}

	for (int i = 1; i < range; i++) {
		countArray[i] += countArray[i-1];
	}

	int sorted[size];
	for (int i = 0; i < size; i++) {
		countIndex = array[i];
		sortIndex = countArray[countIndex];
		sorted[sortIndex] = countIndex;
		countArray[countIndex]--;
	}
}

int findmin(int array[], int size) {
	int min = array[0];
	for (int i = 0;, i < size; i++) {
      if (array[i] < min) {
      	min = array[i];
      }
	}
	return min;
}

int findmax(int array[], int size) {
	int max = array[0];
	for (int i = 0;, i < size; i++) {
      if (array[i] > max) {
      	max = array[i];
      }
	}
	return max;
}