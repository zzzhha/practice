#include"sort.h"
using namespace std;

//Ӧ���Ѷ���
//����֮��
//����һ���������� nums ��һ������Ŀ��ֵ target��
// �����ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�

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

//��������
//���������ͷ��� head ���뽫�䰴 ���� ���в����� ���������� 

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

//�ϲ�������������

//���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2��
// ������������ m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�4
//ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�
// Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ�
// �� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n 

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


//�ϲ�������������
//��������������ϲ�Ϊһ���µ� ���� �������ء�
// ��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ� 


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



//У���Ѷ���
//Ѱ�����������������λ��
//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

//�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log(m + n)) ��
//�˽ⷨʱ�临�Ӷ�ΪO(n+m)
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


//�����ظ�Ԫ��
//����һ���������� nums ��һ������ k ��
// �ж��������Ƿ�������� ��ͬ������ i �� j ��
// ���� nums[i] == nums[j] �� abs(i - j) <= k ��
// ������ڣ����� true �����򣬷��� false 

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