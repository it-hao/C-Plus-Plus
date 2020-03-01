// C++ program to implement gravity/bead sort 
#include <iostream>
#include <cstring>
using namespace std; 
  
#define BEAD(i, j) beads[i * max + j] 
  
  
/*
3	:1	1	1 				3:	1	1	1	1	1
5	:1	1	1	1	1   ==> 5:	1	1	1
1	:1 						1:	1
*/
void beadSort(int *a, int len) 
{ 
    // Find the maximum element 
    int max = a[0]; 
    for (int i = 1; i < len; i++) 
        if (a[i] > max) 
           max = a[i]; 
  
    // allocating memory 
    unsigned char beads[max*len]; 
    memset(beads, 0, sizeof(beads)); 
  
    // mark the beads 
    for (int i = 0; i < len; i++) 
        for (int j = 0; j < a[i]; j++) 
            BEAD(i, j) = 1; 
  
    for (int j = 0; j < max; j++) 
    { 
        // count how many beads are on each col 
        int sum = 0; 
        for (int i = 0; i < len; i++) 
        { 
            sum += BEAD(i, j); 
            BEAD(i, j) = 0; 
        } 
  
        // Move beads up 
        for (int i = len - sum; i < len; i++) 
            BEAD(i, j) = 1; 
    } 
  
    // Put sorted values in array using beads 
    for (int i = 0; i < len; i++) 
    { 
        int j; 
        for (j = 0; j < max && BEAD(i, j); j++); 
  
        a[i] = j; 
    } 
} 

void show(int *a, int len)
{
    int i;
    for (i = 0; i < len; i++)
        cout << a[i] << "\n";
}

// driver function to test the algorithm 
int main() 
{ 
	int len;
    cout << "\nEnter the number of elements : ";

    cin >> len;

    int arr[len];

    cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < len; ++i)
    {
        cout << "\n";
        cin >> arr[i];
    }
    
    beadSort(arr, len); 
  
    cout << "Sorted array\n";
    show(arr, len); 
  
    return 0; 
} 
