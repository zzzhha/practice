#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<vector>
//����֮��
//����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� 
// ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
//��ϣ��������
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> h;
        vector<int> ret(2);
        for (int i = 0, I = nums.size(); i < I; i++) {
            if (h.find(target - nums[i]) != h.end()) {
                ret[0] = h[target - nums[i]];
                ret[1] = i;
                break;
            }
            h[nums[i]] = i;
        }
        return ret;
    }
};
//�����㷨�������
class Solution {
public:
    int binary_search(vector<int>& nums, vector<int>& ind, int b, int x) {
        int head = b, tail = nums.size() - 1, mid;
        while (head <= tail)
        {
            mid = (head + tail) / 2;
            if (nums[ind[mid]] == x)return mid;
            if (nums[ind[mid]] < x) head = mid + 1;
            else
                tail = mid - 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int >ind(n, 0);
        for (int i = 0; i < n; i++)ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j)->bool {
            return nums[i] < nums[j];
            });
        vector<int>ret(2);
        for (int i = 0; i < n; i++) {
            int j = binary_search(nums, ind,i+1, target = nums[ind[i]]);
            if (j == -1)continue;
            ret[0] = ind[j];
            ret[1] = ind[i];
        }
        if (ret[0] > ret[1]) swap(ret[0], ret[1]);

        return ret;
    }
};