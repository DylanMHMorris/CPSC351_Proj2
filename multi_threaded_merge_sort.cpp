#include <list>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct info {
    int upper;
    int lower;
    vector<int> arr;
};

void *sort_func(void *arg){ // needs to be (info * arg) so we can access struct V being passed

    // THIS INITIALIZES arg as V but causes errors due because of above ^^^
    //struct info *V = arg; 

    printf("\nIt worked!");

    //int v;
    //v++;
    //printf("v is %d\n", v);
    return NULL;
}

int main(){
    /* n is the amount of numbers that will be sorted
    u is the upper limit for determining the numbers
    p is the number of segments that the numbers will be divided into */
    //when inputting put a space inbetween numbers EX: 5 25 5
    int n, u, p;
    cin >> n >> u >> p;
    cout << "inputs were:" << endl;
    cout << n << endl << u << endl << p << endl;
    cout << "end of inputs" << endl;

    /*generate random numbers determined by N and U */
    int counter = 0;
    int random;
    vector<int> holder;
    while(counter < n){
        random = rand() % u;
        holder.push_back(random);
        counter++;
    }

    struct info V;
    V.upper = n/p;
    V.lower = 0;
    V.arr = holder;

    cout << "generated numbers:" << endl;
    for (auto v : V.arr){
        cout << v << " ";
    }    

    pthread_t tid;

    for(int i = 0; i<p; i++){
        pthread_create(&tid, NULL, sort_func, (void *)&V);//passing V which is the struct
    }
    //somehow determine boundaries for each segment to pass based on n/p and replace NULL with each corresponding front and rear
//    int elements_each = n/p;//number of elements in each segment change to floor
 //   int iterator1 = 0;
 //   int iterator2 = elements_each;
 //   pthread_t p1;
 //   int counter2 = 0;
 //   while(counter2 < p){//concurrent
 //       pthread_create(&p1, NULL, thread_func, arr[iterator1:iterator2]/*what it should be*/);
 //       iterator1 += elements_each; 
  //      iterator2 += elements_each; //possibly -1 to avoid out of bounds error
        //pthread_create(&p2, NULL, thread_func, arr[iterator1:iterator2]);
        // 0,1,2,3,4 ||5,6,7,8,9 || 10 11 12 13 14
  //      counter2++; 
 //   }
    //while loop with join
    //while loop to merge

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
