class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>q;
        int ans=INT_MIN;
        int n=points.size();
        for(int i=0;i<n;i++){
            while((!q.empty()) && points[i][0]-q.top().second>k)q.pop();
            if(!q.empty())
                ans=max(ans,q.top().first+points[i][0]+points[i][1]);
            
            q.push({points[i][1]-points[i][0],points[i][0]});
        }
        return ans;   
    }
};


//yi + yj + xi - xj
//yi + yj + xj - xi


//intution: yi + yj + xi - xj = (yi - xi) + (yj + xj)
//so we need to find max(yi-xi) and max(yj+xj) in a window of size k
//we know we have xi+yi task is to find max(yi-xi) in a window of size k
// we used max heap to find max(yi-xi) in a window of size k



//queue will store {yi-xi,xi}
//we will pop all the elements from queue whose xi is out of window >k with x value that is at pair.second
//calculate ans=max(ans,q.top().first+points[i][0]+points[i][1]); if queue is not empty
//we will push {yi-xi,xi} in queue




// we can also use deque to find max(yi-xi) in a window of size k in O(n) time