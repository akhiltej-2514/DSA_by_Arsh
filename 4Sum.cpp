class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
    
        vector<vector<int> > res;
    
        if (num.empty()|| num.size()<4)
            return res;
        
           sort(num.begin(),num.end());
    
        for (int i = 0; i < num.size(); i++) {
        
            for (int j = i + 1; j < num.size(); j++) {
            
               long long target_2 = target - (long long)num[j]-(long long)num[i];
            
                long long  front = j + 1;
                long long  back = num.size() - 1;
            
                while(front < back) {
                    if (num[front] + num[back] < target_2) front++;
                    else if (num[front] + num[back] > target_2) back--;
                    else {
                        vector<int> temp;
                        temp.push_back(num[i]);                                               
                        temp.push_back(num[j]); 
                        temp.push_back(num[front]);
                        temp.push_back(num[back]);
                        res.push_back(temp);
                        while (front < back && num[front] == num[front+1]) ++front;
                        while (front < back && num[back] == num[back-1]) --back;
                        front++;
                        back--;
                    }
                }
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
                
            }
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
        
        }
        return res;
    
    }
};