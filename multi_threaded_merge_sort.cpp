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

// We have to use sort() function so I include the sort() function here
/*
#include <iostream>
#include <algorithm> 
#include <vector>
#include <execution>

using namespace std;

int main()
{
    std::vector<int> Vec{5,3,6,2,7,4,1,8,2,9};
    std::sort(std::execution::par, Vec.begin(),Vec.end());
    for(auto elm:Vec)
    {
        cout << elm << “ ”; 
    }
    return 0;

}

*/
