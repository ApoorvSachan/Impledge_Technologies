#include <fstream>
#include <vector>
#include <time.h>
#include <queue>
#include <iomanip>
using namespace std;

// node of trie tree
struct node
{
  node *links[26];
  bool flag = 0;

  bool contain_char(char ch)
  {
    return links[ch - 'a'] != NULL;
  }

  void put_char(char ch)
  {
    links[ch - 'a'] = new node();
  }

  node *get_link(char ch)
  {
    return links[ch - 'a'];
  }

  void mark_wordEnd()
  {
    flag = 1;
  }

  bool is_end()
  {
    return flag;
  }
};

// implementing trie class
class trie
{
private:
  node *root;
  queue<pair<string, string>> q; // queue to store sufixes of word whose prefixes are present in input file along with word

public:
  trie()
  {
    root = new node();
  }

  // insert word in trie
  void insert(string word)
  {
    node *temp = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!temp->contain_char(word[i]))
        temp->put_char(word[i]);
      temp = temp->get_link(word[i]);
      if (temp->flag == 1)
        q.push({word, word.substr(i + 1)});
    }
    temp->mark_wordEnd();
  }

  // check if word is present in trie or not
  bool search_word(string word)
  {
    node *temp = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!temp->contain_char(word[i]))
        return false;
      temp = temp->get_link(word[i]);
    }
    return temp->flag;
  }

  // returns largest and second largest compounded word
  vector<string> compounded_word()
  {
    vector<string> ans(2);
    while (!q.empty())
    {
      string word = q.front().second;
      string complete_word = q.front().first;

      // if suffix is present in trie then the complete_word is compounded
      if (search_word(word))
      {
        // store largest compounded word in ans[0]
        if (ans[0].length() < complete_word.length())
        {
          ans[1] = ans[0];
          ans[0] = complete_word;
        }
        // store second largest compounded word in ans[1]
        else if (ans[1].length() < complete_word.length())
          ans[1] = complete_word;
      }

      // if suffix not present in trie then check for prefixes of the current suffix in trie and store new suffix
      else
      {
        node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
          if (!temp->contain_char(word[i]))
            break;
          temp = temp->get_link(word[i]);
          if (temp->flag == 1)
            q.push({complete_word, word.substr(i + 1)});
        }
      }
      q.pop();
    }
    return ans;
  }
};

int main()
{
  clock_t start, end; // to calculate time to process input file
  start = clock();
  fstream file, file1;
  file.open("input_02.txt", ios::in); // reading from file "input_02.txt"
  trie wordTree;
  string word;
  while (file >> word)
  {
    wordTree.insert(word);
  }
  file.close();
  file1.open("output.txt", ios::out); // storing result in file "output.text"
  vector<string> ans = wordTree.compounded_word();
  file1 << "Longest Compound Word : " << ans[0] << endl
        << "Second Longest Compound Word : " << ans[1] << endl;
  end = clock();
  file1 << "Time taken to process the input file : " << fixed << (double)(end - start) / (double)(CLOCKS_PER_SEC) << setprecision(5) << " seconds" << endl;
  file1.close();
  return 0;
}
