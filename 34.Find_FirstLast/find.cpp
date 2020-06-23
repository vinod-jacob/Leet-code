#include<iostream>
#include<vector>

using namespace std;

    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target)
        {
            if (nums.empty()) return {-1,-1};
            int L=0, R= nums.size()-1;
            int s1 = -1;
            while (L<=R)
            {
                int m = (L+R)/2;
                if (nums[m] == target)
                {
                    s1 = m;
                    break;
                }
                else if (nums[m] < target)
                {
                    L = m+1;
                }
                else if (nums[m] > target)
                {
                    R = m-1;
                }
            }
            if (s1 == -1)
            {
                return {-1,-1};
            }

            int posl = s1, posr = s1;
            R = s1-1 >= 0 ? nums[s1-1] == target ? s1-1 
                : -1 
                : -1;
            L = s1+1 < nums.size() ? nums[s1+1] == target ? s1+1 
                : nums.size()
                : nums.size();
            int l = 0, r = nums.size()-1;

            int temp = 0;
            while (R >= 0 && l <= R)
            {
                int m = (l+R)/2;
                if (nums[m] == target)
                {
                    if (m-1 >= 0 && nums[m-1] == target)
                    {
                        R = m-1;
                        posl = R;
                        l = temp;
                    }
                    else
                    {
                        R = -1;
                        posl = m;
                    }
                }
                else if(nums[m] < target)
                {
                    l = m+1;
                    temp = l;
                }
            }

            temp = nums.size()-1;
            while (L <= nums.size() -1 && r >= L)
            {
                int m = (L+r)/2;
                if (nums[m] == target)
                {
                    if(m+1 < nums.size() && nums[m+1] == target)
                    {
                        L = m+1;
                        posr = L;
                        r = temp;
                    }
                    else
                    {
                        L = nums.size();
                        posr = m;
                    }
                }
                else if (nums[m] > target)
                {
                    r = m-1;
                    temp = r;
                }
            }
            return{posl, posr};
        }
    };

/* class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.empty()) return {-1,-1};
        int L=0, R= nums.size()-1;
        int ret = -1;
        while (L<=R)
        {
            int m = (L+R)/2;
            if (nums[m] == target)
            {
                ret = m;
                break;
            }
            else if (nums[m] < target)
            {
                L = m+1;
            }
            else if (nums[m] > target)
            {
                R = m-1;
            }
        }
        if (ret != -1)
        {
            int l = ret,r = ret;
            while (l >= 0 && nums[l] == target)
            {
                l--;
            }
            while (r < nums.size() && nums[r] == target)
            {
                r++;
            }
            return {l+1,r-1};
        }
        else
        {
            return {-1,-1};
        }
    }
}; */

int main()
{
    vector<int> nums = {1,2,3,4,5,7,7,7,7,7,8,9,9};
    int target = 7;
    Solution S1;
    vector<int> res = S1.searchRange(nums, target);
    cout << "result = [" << res[0] << " ," << res[1] << " ]" <<endl;
}