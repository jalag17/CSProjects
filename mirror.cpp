#include <iostream>
#include <stdlib.h>
void insertionSort(int data[], int size);
void printArr(int data[], int size);
void mirrors(int data[], int size);

int main() {
  // Prompt user for random integers and insert into array
  int size = 0;
  int data[100];
  std::cout << "Enter integers right after the other without pressing enter on the terminal:\n";
  int number;
  while (std::cin.peek() != '\n') {
    std::cin >> number;
    data[size] = number;
    size++;
  }

// insertion sort
  insertionSort(data, size);

  // find mirror elements
  mirrors(data, size);
}
void mirrors(int data[], int size) {
  // Check each negative number to see if it has a matching positive number
  int front_ptr = 0; // Set to front of array
  int back_ptr = size - 1; // Set to back of array
  while (front_ptr != back_ptr) {
    // If negative number has mirror element, print it
    if (abs(data[front_ptr]) == data[back_ptr]) {
      std::cout <<" Mirror element pair: " << "(" << data[front_ptr] << "," << data[back_ptr] << "),";
    }
    // Increment front_ptr if the absolute value of it is greater than the data
    // the back_ptr is pointing too
    // Ex: if data[front_ptr] = -5 and data[back_ptr] = 4, then we'll want to
    // increment the front_ptr to try and find -4
    if (abs(data[front_ptr]) > data[back_ptr]) {
      do {
        front_ptr++;
      } while(data[front_ptr] == data[front_ptr-1] && front_ptr < back_ptr); // Skip duplicates
    }
    // Else, decrement the back_ptr using opposite logic from above
    else {
      do {
        back_ptr--;
      } while(data[back_ptr] == data[back_ptr+1] && back_ptr > front_ptr); // Skip duplicates
    }
  }
}
void insertionSort(int data[], int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = data[i];//take value
      j = i;
      while(j > 0 && data[j-1]>key) {
         data[j] = data[j-1];
         j--;
      }
      data[j] = key;   //insert in right place
   }
}


void printArr(int data[], int size) {
  for (int i = 0; i < size; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}
