#include <list>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


void *thread_func(void *arg, void *arg2){

    int v;
    v++;
   
    printf("v is %d\n", v);

    pthread_exit(0);

}

int main(){
    /* n is the amount of numbers that will be sorted
    u is the upper limit for determining the numbers
    p is the number of segments that the numbers will be divided into */
    int n, u, p;
    cin >> n >> u >> p;
    cout << "inputs were:" << endl;
    cout << n << endl << u << endl << p << endl;
    cout << "end of inputs" << endl;

    /*generate random numbers determined by N and U */
    int counter = 0;
    int random;
    vector<int> arr;
    while(counter < n){
        random = rand() % u;
        arr.push_back(random);
        counter++;
    }

    cout << "generated numbers:" << endl;
    for (auto v : arr){
        cout << v << endl;
    }    

    //somehow determine boundaries for each segment to pass based on n/p and replace NULL with each corresponding front and rear
    int elements_each = n/p;//number of elements in each segment
    int iterator1 = 0;
    int iterator2 = elements_each;
    pthread_t p1, p2;
    int counter2 = 0;
    while(counter2 < p){
        pthread_create(&p1, NULL, thread_func, arr[iterator1:iterator2]/*what it should be*/);
        iterator1 += elements_each; 
        iterator2 += elements_each; //possibly -1 to avoid out of bounds error
        pthread_create(&p2, NULL, thread_func, arr[iterator1:iterator2]);
        iterator1 += elements_each;
        iterator2 += elements_each;
        // 0,1,2,3,4 ||5,6,7,8,9 || 10 11 12 13 14
        counter2++; 
    }

    return 0;
}

/* qsort() example
#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, 5, sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {   
      printf("%d ", values[n]);
   }
  
   return(0);
}
*/

/*Concurrent Thread Example

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int j = 0;

void *thread_func(void *arg){

    
    j++;
   
    printf("j is %d\n", j);

    pthread_exit(0);

}

int main(int argc, char *argv[]){

      pthread_t p1, p2, p3, p4;             // Need to add 2 more segment p3, p4

      pthread_create(&p1, NULL, thread_func, NULL);
      pthread_create(&p2, NULL, thread_func, NULL);
      pthread_create(&p3, NULL, thread_func, NULL);
      pthread_create(&p4, NULL, thread_func, NULL);


      pthread_join(p1, NULL);
      pthread_join(p2, NULL);
      pthread_join(p3, NULL);
      pthread_join(p4, NULL);



}
*/

/*
// C++ program to generate the vector
// with random values
#include <bits/stdc++.h>
using namespace std;
  
// Driver Code
int main()
{
    // Size of vector
    int size = 5;
  
    // Initialize the vector with
    // initial values as 0
    vector<int> V(size, 0);
  
    // use srand() for different outputs
    srand(time(0));
  
    // Generate value using generate
    // function
    generate(V.begin(), V.end(), rand);
  
    cout << "The elements of vector are:\n";
  
    // Print the values in the vector
    for (int i = 0; i < size; i++) {
        cout << V[i] << " ";
    }
  
    return 0;
}
*/
