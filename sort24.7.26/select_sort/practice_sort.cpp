#include"sort.h"
using namespace std;

//应试难度题
//两数之和
//给定一个整数数组 nums 和一个整数目标值 target，
// 请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>ind(n);
        for (int i = 0; i < n; i++)
        {
            ind[i] = i;
        }
        sort(ind.begin(), ind.end(), [&](int i, int j)-> bool {
            return nums[i]< nums[j];
            });
        int p1 = 0, p2 = n - 1;
        while (nums[ind[p1]] + nums[ind[p2]] != target)
        {
            if (nums[ind[p1]] + nums[ind[p2]] < target)
            {
             p1+=1;
            }
             else
             {
                 p2-=1;
             }
        }
         vector<int>ret(2);
         ret[0] = ind[p1], ret[1] = ind[p2];
         if (ret[0] > ret[1])
         {
             swap(ret[0], ret[1]);
         }
    return ret;
    }
};

//排序链表
//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return head;
        int l = head->val, r = head->val;
        ListNode* p = head,*h1=nullptr,*h2=nullptr,*q;
        while (p)
        {
            l = min(p->val, l);
            r = max(p->val, r);
            p = p->next;
        }
        if (l == r)return head;
        int z = floor((l + r) / 2.0);
        p = head;
        while (p) {
            q = p->next;
            if (p->val <= z)
            {
                p->next = h1;
                h1 = p;
            }
            else
            {
                p->next = h2;
                h2 = p;
            }
            p = q;
        }
        h1=sortList(h1);
        h2=sortList(h2);
        p = h1;
        while (p->next)p = p->next;
        p->next = h2;
        return h1;
    }
};

//合并两个有序数组

//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，
// 另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。4
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
// 为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
// 后 n 个元素为 0 ，应忽略。nums2 的长度为 n 

class Solution {
public:
    void my_merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* arr = new int[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = nums1[i];
        }
        int k = 0, n1 = 0, n2 = 0;
        while (n1 < m || n2 < n)
        {
            if (n2==n||(n1<m&&arr[n1] <= nums2[n2]))
                nums1[k++] = arr[n1++];
            else
                nums1[k++] = nums2[n2++];
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, k = m + n - 1;
        while(p1!=-1||p2!=-1){
            if (p2 == -1 || (p1 != -1 && nums1[p1] >= nums2[p2]))
                nums1[k--] = nums1[p1--];
            else
                nums1[k--] = nums2[p2--];
        }
        return;
    }
};


//合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。
// 新链表是通过拼接给定的两个链表的所有节点组成的。 


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ret, * p = &ret;
        while (list1 || list2) {
            if (list2==NULL || (list1!=NULL && list1->val <= list2->val))
            {
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            }
            else
            {
                p->next = list2;
                list2 = list2->next;
                p=p->next;
            }
        }
        return ret.next;
    }
};



//校招难度题
//寻找两个正序数组的中位数
//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

//算法的时间复杂度应该为 O(log(m + n)) 。
//此解法时间复杂度为O(n+m)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),  m = nums2.size();
        vector<int>temp(n + m);
        int p1 = 0, p2 = 0, k = 0;
        while (p1 < n || p2 < m) {
            if (p2 == m || (p1 < n && nums1[p1] < nums2[p2]))
            {
                temp[k++] = nums1[p1++];
            }
            else
            {
                temp[k++] = nums2[p2++];
            }
        }
        double a = temp[(n + m) / 2], b = temp[(n + m) / 2];
        if ((n + m) % 2 == 0)
        {
            b = temp[(n + m) / 2 - 1];
        }
        return (a + b) / 2.0;
    }
};


//存在重复元素
//给你一个整数数组 nums 和一个整数 k ，
// 判断数组中是否存在两个 不同的索引 i 和 j ，
// 满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
// 如果存在，返回 true ；否则，返回 false 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ind(n);
        for (int i = 0; i < n; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j)->bool {
            if (nums[i] != nums[j]) return nums[i] < nums[j];
            return i < j;
            });
        for (int i = 0, I = n - 1; i < I; i++) {
            if (nums[ind[i]] - nums[ind[i+1]])continue;
            if (ind[i+1] - ind[i] <= k)return true;
        }
        return false;
    }
};