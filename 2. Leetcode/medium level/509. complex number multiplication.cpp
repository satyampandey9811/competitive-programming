// link to question - https://leetcode.com/problems/complex-number-multiplication/

class Solution {
public:
    int getReal(string a) {
        int val = 0, i = 0;
        if(a[i] == '-') i++;
        while(a[i] != '+') {
            val *= 10;
            val += a[i] - '0';
            i++;
        }
        if(a[0] == '-') val *= -1;
        return val;
    }
    
    int getImag(string a) {
        int val = 0, i = 0;
        while(a[i] != '+') i++;
        i++;
        int j = i;
        if(a[i] == '-') i++;
        while(a[i] != 'i') {
            val *= 10;
            val += a[i] - '0';
            i++;
        }
        if(a[j] == '-') val *= -1;
        return val;
    }
    
    string complexNumberMultiply(string a, string b) {
        int m = a.size(), n = b.size();
        int reala, realb, imaga = 0, imagb = 0;
        
        reala = getReal(a);
        realb = getReal(b);
        imaga = getImag(a);
        imagb = getImag(b);
        
        int realans = reala * realb + (imaga * imagb) * (-1);
        int imagans = reala * imagb + realb * imaga;
        
        string ans;
        ans += to_string(realans);
        ans += '+';
        ans += to_string(imagans);
        ans += 'i';
        
        return ans;
    }
};