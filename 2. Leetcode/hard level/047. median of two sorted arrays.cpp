// link to question - https://leetcode.com/problems/median-of-two-sorted-arrays/

// solved after watching tushar roy's video explanation on youtube

class Solution {
public:        
    double go(int start, int end, vector<int>& a, vector<int>& b) {
        int partitionA, partitionB;
        int maxLeftA = INT_MIN, maxLeftB = INT_MIN;
        int minRightA = INT_MAX, minRightB = INT_MAX;
        
        while(start <= end) {
            partitionA = (start + end) / 2;
            partitionB = (a.size() + b.size() + 1) / 2 - partitionA;
            
            if(partitionA) maxLeftA = a[partitionA - 1];
            if(partitionB) maxLeftB = b[partitionB - 1];
            if(partitionA != a.size()) minRightA = a[partitionA];
            if(partitionB != b.size()) minRightB = b[partitionB];
            
            if(maxLeftA <= minRightB and maxLeftB <= minRightA) {
                if((a.size() + b.size()) & 1) 
                    return (double)max(maxLeftA, maxLeftB);
                else 
                    return (double)(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2;
            }
            
            if(maxLeftA > minRightB) 
                end = partitionA - 1;
            else 
                start = partitionA + 1;
            
            maxLeftA = INT_MIN, maxLeftB = INT_MIN;
            minRightA = INT_MAX, minRightB = INT_MAX;
        }
        return 0.0;
    }
    
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        
        if(m < n) return go(0, m, a, b);        
        else return go(0, n, b, a);
    }
};