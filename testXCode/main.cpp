//
//  main.cpp
//  testXCode
//
//  Created by Huan-Chi Lin on 2021/1/29.
//

#include <iostream>
#include "lll.hpp"
#include <vector>
#include <unordered_set>
#include <unordered_map>



using  namespace std;
bool containsDuplicate(vector<int>& nums)
{
    bool isDuplicate(false);
    
    if (nums.size() == 1)
        return isDuplicate;
    
    unordered_set<int> set;
    for (int i=0; i<nums.size(); i++)
    {
        if (set.find(nums[i]) == set.end())
        {
            set.insert(nums[i]);
        }
        else
            return true;
    }
    
    return isDuplicate;
};

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    vector<int> ans;
    for(int i = 0, j = 0;i < nums1.size() && j < nums2.size();){
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }
        else{
            i++;
        }
    }
    
    return ans;
};
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        int nSz1 = nums1.size();
        int nSz2 = nums2.size();
        
        std::unordered_map<int, int> hsMap;
        
        if (nSz1 <= nSz2)
        {
            for (int i(0); i<nSz1; i++)
            {
                hsMap[nums1[i]]++;
            }
        }
        else
        {
            for (int i(0); i<nSz2; i++)
            {
                hsMap[nums2[i]]++;
            }
        }
        
        std::vector<int> returnVt;
        
        if (nSz1 > nSz2)
        {
            for (int i(0); i<nSz1; i++)
            {
                if (hsMap[nums1[i]]-- >0)
                {
                    
                    returnVt.push_back(nums1[i]);
                }
            }
        }
        else
        {
            for (int i(0); i<nSz2; i++)
            {
                std::cout<<hsMap[nums2[i]]<<endl;
                if (hsMap[nums2[i]]-- >0)
                {
                    std::cout<<hsMap[nums2[i]]<<endl;
                    
                    returnVt.push_back(nums2[i]);
                }
            }
        }
       
        return returnVt;
    }

bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        int i(0), j(static_cast<int>(s.size() - 1));
        
        while (i < j)
        {
            if (!isalpha(s[i]))
            {
                i++;
                continue;
            }
            if (!isalpha(s[j]))
            {
                j--;
                continue;
            }
            
            if (tolower(s[i]) == tolower(s[j]))
            {
                i++; j--;
                std::cout<<"front "<< s[i-1]<<endl;
                std::cout<<"back "<< s[j+1]<<endl;

            }
            else
                return false;
        }
    return true;
    }

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

vector<int> vt;
    vector<int>& storeBT(TreeNode* root)
    {
        if (root == nullptr) {
            vt.push_back(0);
            return vt;
        }
        storeBT(root->left);
        vt.push_back(root->val);
        return storeBT(root->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        storeBT(root);

        int i(0), j(vt.size()-1);
        while (i<=j){
            if (vt.at(i++) != vt.at(j--))
                return false;
        }
         return true;
    }


int main(int argc, const char * argv[]) {
    // std::string s = "A man, a plan, a canal: Panama";
    // bool isTrue = isPalindrome(s);
    
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(2);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node2->left = node4;
    
    bool anss = isSymmetric(root);
    
    return 0;
}
