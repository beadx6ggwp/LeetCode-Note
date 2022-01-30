#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int no = 0, ne = k % len, t = len - 1;
        while (t > 0) {
            // run len-1 times
            swap(nums[no], nums[ne]);
            ne = (ne + k) % len;
            if (ne == no) {
                // renew
                no = (no + 1) % len;
                ne = (no + k) % len;
                t--;
            }
            t--;
        }
    }
};
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==0 || k==0){
            return;
        }
        
        int curr=0;
        int torot=nums[curr];
        int n=nums.size();
        int j=n;
        int start=0;
        while(j--){
            int t=nums[(curr+k)%n];
            nums[(curr+k)%n]=torot;
            curr=(curr+k)%n;
            torot=t;
            
            if(curr==start){
                if(++curr >= n) return;
                torot=nums[curr];
                start++;
            }
        }
    }
};
*/

void printVector(vector<int>& nums) {
    for (auto n : nums) cout << n << " ";
    cout << "\n";
}
int main() {
    vector<int> in0 = {1, 2};
    vector<int> in1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> in2 = {-1, -100, 3, 99};

    Solution().rotate(in0, 2);
    printVector(in0);

    Solution().rotate(in1, 3);
    printVector(in1);

    Solution().rotate(in2, 2);
    printVector(in2);
    return 0;
}
