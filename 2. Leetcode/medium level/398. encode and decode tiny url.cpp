// link to question - https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
public:
    
    map<string, string> e, d;
    int i = 0;
    string s = "http://tinyurl.com/";

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        e[longUrl] = s + to_string(i);
        d[s + to_string(i)] = longUrl;
        i++;
        return e[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return d[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));