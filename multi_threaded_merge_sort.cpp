#include <list>
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
//struct object that will store information on thread
struct info {
    int roof;
    int floor;
    vector<int> arr;
    int iterator = 0; 

    void *sort_func(){
            //printf("\nIt worked!"); //a tester line
            sort(arr.begin(), arr.end());//attempt to sort vector
            return NULL;
    };
};

void *to_sort_func(void *arg){ 
    // THIS INITIALIZES arg as V but causes errors due because of above ^^^
    struct info *V = (struct info *)arg;//lets us use V inside function
    V->sort_func();

    return NULL;
}

int main(){
    /* n is the amount of numbers that will be sorted
    u is the upper limit for determining the numbers
    p is the number of segments that the numbers will be divided into */
    //
    //command used to compile -> g++ -pthread -o multi_threaded_merge_sort_test  multi_threaded_merge_sort.cpp
    //
    //when inputting put a space inbetween numbers all in one line EX: 5 25 5
    //
    int n, u, p;
    cout << "Please input 3 numbers: ";
    cin >> n >> u >> p;
    cout << "inputs were:" << endl;
    cout << n << endl << u << endl << p << endl;
    cout << "end of inputs" << endl;

    //generate random numbers determined by N and U and add to vector
    int counter = 0;
    int random;
    vector<int> holder;
    while(counter < n){
        random = rand() % u;
        holder.push_back(random);
        counter++;
    }

    //create object 
    struct info V;
    V.roof = n/p;
    V.floor = 0;
    V.arr = holder;

    cout << "generated numbers:" << endl;
    for (auto v : V.arr){
        cout << v << " ";
    }    

    pthread_t tid;

    for(int i = 0; i<p; i++){
        pthread_create(&tid, NULL, to_sort_func, (void*)&V);//passing V which is the struct
    }
    
    cout << "\n Sorted \n";
    for (auto x : V.arr)
        cout << x << " ";
   
    cout << "\n";

    return 0;
}