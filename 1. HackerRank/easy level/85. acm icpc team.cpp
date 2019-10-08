// link to question - https://www.hackerrank.com/challenges/acm-icpc-team/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> t) {

  int m = t.size(), n = t[0].size(), max = 0, c , d = 0;
  vector<int> a,z;
  for (int i = 0; i < m - 1; i++) {
    for (int j = i + 1; j < m; j++) {
        c=0;
      for (int k = 0; k < n; k++) {
        if (t[i][k]-'0' | t[j][k]-'0')
          c++;
      }
        z.push_back(c);
      if (max <= c)
        max = c;
    }
  }
  for(int i=0;i<z.size();i++){
      if(z[i]==max)
      d++;
  }

  a.push_back(max);
  a.push_back(d);
  return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i]<<endl;
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
