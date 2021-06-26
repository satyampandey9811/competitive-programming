// link to question - https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution {
public:
    // important question
    vector<pair<int, int>> a;
    vector<int> ans;
    int n;
    
    void merge(int start, int mid, int end) {
        vector<pair<int, int>> res(end - start + 1);
        int i = start, j = mid + 1;
        int c = 0, k = 0;
        
        while(i <= mid and j <= end) {
            if(a[i].first <= a[j].first) {
                if(i < mid) ans[a[i+1].second] += c;
                res[k++] = a[i++];
            }
            else {
                ans[a[i].second]++;
                c++;
                res[k++] = a[j++];
            }
        }
        while(i <= mid) {
            if(i < mid) ans[a[i+1].second] += c;
            res[k++] = a[i++];
        }
        while(j <= end) res[k++] = a[j++];
        
        for(int x = start; x <= end; x++) a[x] = res[x-start];
    }
    
    void mergeSort(int i, int j) {
        if(i >= j) return;
        int mid = (i + j) / 2;
        mergeSort(i, mid);
        mergeSort(mid + 1, j);
        merge(i, mid, j);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        a.resize(n);
        ans.resize(n);
        
        for(int i = 0; i < n; i++) {
            a[i].first = nums[i];
            a[i].second = i;
        }
        mergeSort(0, n - 1);
        
        return ans;
    }
};