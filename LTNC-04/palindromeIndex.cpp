#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int palindromeIndex(std::string s)
{
  int res, i = 0, j = s.size() - 1;
  while (i <= j)
  {
    if (s[i] != s[j])
    {
      res = i;
      int left_index = i;
      int right_index = j;
      i++;
      while (i <= j)
      {
        if (s[i] != s[j])
        {
          res = -100;
          break;
        }
        i += 1;
        j -= 1;
      }
      if (res != -100) return res;
      
      i = left_index;
      j = right_index - 1;
      while (i <= j)
      {
        if (s[i] != s[j]) return -1;
        i++;
        j--;
      }
      return right_index;
    }
    i++;
    j--;
  }
  return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
