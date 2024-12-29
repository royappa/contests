
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class CostlySorting {

    int N;
    int i, j;

    vector<int> order;
    /*
     * Only uses the costs to figure out the number of elements.
     * After that, does bubble sort.
    */

    public:

    vector<int> initialize(vector<string> costs){
        N = costs.size();

        for(i = 0; i<N; i++){
            order.push_back(i+1);
        }
        i = 1; j = 1;
        //First query asks: is item 2 less than item 1
        //global variable i will hold the number of sorted items
        //j will hold the index of the item currently being bubbled
        //up towards the front of the order
        vector<int> r;
        r.push_back(2);
        r.push_back(1);
        return r;
    }

    vector<int> query(bool result)
    {
        if(result){//order[j] < order[j-1]
            int tmp = order[j];
            order[j] = order[j-1];
            order[j-1] = tmp;
            if(j == 1){
                //reached the beginning, bubble up the next thing
                i++;
                j = i;
            }else{
                //moved item forward 1 step, decrement j
                j--;
            }
        }else{//order[j] > order[j-1]
            i++;
            j = i;
        }
        if(i == N){
            //all done
            return order;
        }else{
            //need to make another query
            vector<int> r;
            r.push_back(order[j]);
            r.push_back(order[j-1]);
            return r;
        }
    }
};


main()
{
	exit(0);
}
