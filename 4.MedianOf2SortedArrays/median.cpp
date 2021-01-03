#include<iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> mergedArray;
        mergeArrays(nums1, nums2, mergedArray);
        return getMedian(mergedArray, nums1.size(), nums2.size());
    }
    void mergeArrays(vector<int> &nums1, vector<int> &nums2, vector<int> &ma)
    {
        vector<int>::iterator it1, it2;
        it1 = nums1.begin();
        it2 = nums2.begin();

        while(it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 <= *it2)
            {
                ma.push_back(*it1);
                it1++;
            }
            else
            {
                ma.push_back(*it2);
                it2++;
            }
        }

        while (it2 != nums2.end())
        {
            ma.push_back(*it2);
            it2++;
        }

        while (it1 != nums1.end())
        {
            ma.push_back(*it1);
            it1++;
        }
    }

    double getMedian(vector<int>& ma, int s1, int s2)
    {
        int s = s1 + s2;
        return s%2 == 0 ? (ma[(s-1)/2] + ma[((s-1)/2)+1])/2.00 : ma[s/2];
    }

};



int main()
{
    Solution S1;
    vector<int> nums1 = {1,3,5,6,7,8};
    vector<int> nums2 = {2};
    cout << S1.findMedianSortedArrays(nums1, nums2) << endl;
}