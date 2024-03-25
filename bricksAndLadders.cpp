#include <bits/stdc++.h>
using namespace std;

int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int i;
    priority_queue<int> pq;
    for(i = 0; i < heights.size()-1; i++)
    {
        int diff = heights[i+1] - heights[i];
        if(diff <= 0)
            continue;
        if(diff <= bricks)
        {
            bricks = bricks - diff;
            pq.push(diff);
        }
        else if(ladders > 0)
        {
            if(!pq.empty() && diff < pq.top())
            {
                bricks = bricks + pq.top();
                pq.pop();
                pq.push(diff);
                bricks=bricks - diff;
            }
            ladders--;
        }
        else
            break;
    }
    return i;
}

int main() {
    vector<int> heights{4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10, ladders = 2;
    cout << furthestBuilding(heights, bricks, ladders) << endl;
    return 0;
}