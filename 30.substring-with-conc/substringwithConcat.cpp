#include <iostream>
#include <vector>
#include <unordered_set>
#include <forward_list>
#include <map>
#include <unordered_map>
#include <set>

using namespace std;

class SolutionW {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        vector<string> allPermuteWords = findPermutation(words);

        unordered_set<string> uset;
        vector<string>::iterator it = allPermuteWords.begin();
        for (it; it != allPermuteWords.end(); it++)
        {
            uset.insert(*it);
        }

        int windowsize = allPermuteWords[0].length(); //all permut words are of the same size
        if (s.length() < windowsize) return res;
        else
        {
           int l = 0, r = windowsize-1;
           while(r < s.length())
           {
                string searchstr = s.substr(l,windowsize);
                unordered_set<string>::const_iterator got = uset.find(searchstr);
                if (got != uset.end())
                {
                    res.push_back(l);
                }
                l++; r++;
           } 
        }
        return res;
    }

    vector<string> findPermutation(vector<string> words)
    {
        vector<string> allPermuteStrings;
        string prefix = "";
        forward_list<string> words_list;
        int numWords = words.size();
        for(vector<string>::iterator it = words.begin(); it != words.end(); it++)
        {
            words_list.push_front(*it);
            cout << *it << " ";
        }
        permute(allPermuteStrings, prefix, numWords, words_list);
        return allPermuteStrings;
    }

    void permute(vector<string> &allPermuteStrings, string prefix, int numWords, forward_list<string> inputWords)
    {
        if (numWords != 0)
        {
            for (int i = 0; i < numWords; i++)
            {
                int j = 0;
                forward_list<string> temp = inputWords;
                auto it = temp.begin();
                auto it_t = temp.before_begin();
                while(j < i)
                {
                    it++; it_t++; j++;
                }
                string prefix_temp = prefix + *it; 
                temp.erase_after(it_t);
                permute(allPermuteStrings, prefix_temp, numWords -1, temp);

            }
        }
        else
        {
            allPermuteStrings.push_back(prefix);
        }
    }
};

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> res;
        if (!words.size()) return res;
        int windowsize = words[0].length() * words.size(); // total number of characters all the words together
        if (windowsize > s.length())
            return res;
        unordered_map<string, int> didwecheckthissubstrbefore;
        multiset<string> setofwords; //to make find ooperation faster, add it to a set O(n)

        for(auto it = words.begin(); it != words.end(); it++)
        {
            setofwords.insert(*it); 
        }

        for(int i = 0; i  <= s.length() - windowsize; i++)
        {
            string substr = s.substr(i, windowsize);
            string bkpsubstr = substr;
            if(didwecheckthissubstrbefore.find(substr) != didwecheckthissubstrbefore.end())
            {   
                // cout << "d didwecheckthissubstrbefore[substr] = " << didwecheckthissubstrbefore[substr] <<endl;
                //we've checked this substr before. Grab the results and add substr.length to it's output if it contained all words
                if(didwecheckthissubstrbefore[substr] != -1)
                {
                    res.push_back(i);
                }
                continue;
            }
            for(auto it = setofwords.rbegin(); it != setofwords.rend(); it++)
            {
                /*need to perform find operation in blocks of wordsize on the substr*/
                bool found = false;
                
                for(int k = 0; k < substr.length(); k = k + words[0].length())
                {
                    string subsub(substr,k,words[0].length()); //doing it word length by word length because ababababa and ab,ba,ba,ab will result in wrong hits
                    if(subsub == *it)
                    {
                        //found the word; remove it; break;
                        found = true; //this is the good way to break out of this search for a word
                        substr.replace(k, it->length(), it->length(), '0');
                        break;
                    }
                }
                if(!found) //searched the entire substring length. The bad way to break out of a search for a word
                {
                    //couldn't find a word in s; no need to search for rest of the words. This ones a failed substring. Add it to didwecheckthissubstrbefore with -1.
                    didwecheckthissubstrbefore.insert({bkpsubstr, -1});
                    break;
                }
            }
            if(substr == string(windowsize, '0')) //won't hit this condition if we didn't escape the loop after finishing all the words
            {
                didwecheckthissubstrbefore.insert({bkpsubstr, i});
                res.push_back(i);
            }
        }
        return res;
    }
};

int main()
{
    // string s = "foobarfoobar";
    // vector<string> words = {"foo","bar"};
    string s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababab";
    vector<string> words = {"ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba","ab","ba"};
    Solution S1;
    vector<int> result = S1.findSubstring(s, words);
    vector<int>::iterator it = result.begin();
    for(it; it != result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}