#include <list>
#include <iostream>

using namespace std;

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
    list<int> ini_list = {};
    while(counter < n){
        random = rand() % u;
        ini_list.push_back(random);
        counter++;
    }

    cout << "generated numbers:" << endl;
    for (auto v : ini_list){
        cout << v << endl;
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

      pthread_t p1, p2;             // Need to add 2 more segment p3, p4

      pthread_create(&p1, NULL, thread_func, NULL);
      pthread_create(&p2, NULL, thread_func, NULL);

      pthread_join(p1, NULL);
      pthread_join(p2, NULL);


}
*/
