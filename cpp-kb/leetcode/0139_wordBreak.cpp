#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/word-break/?envType=problem-list-v2&envId=rab78cw1

class Solution {
public:
    enum TEST {RELEASE, DEBUG1};
    // bool isEmpty(const string& s) {
    //     for(auto it = s.begin(); it != s.end(); ++it)
    //     {
    //         if (*it != ' ')
    //             return false;
    //     }
    //     return true;
    // }

    bool starts_with(const string& s, size_t pos,  const string& sub_s) {
        size_t i = pos, j = 0;
        for(; i < s.size() && j < sub_s.size(); ++i, ++j) {
            if(s[i] != sub_s[j])
                return false;
        }
        if(j == sub_s.size())
            return true;
        return false;
    }

    bool wordBreak2(const string& s, vector<string>& wordDict, size_t n, std::map<string, bool>& cache ) {
        if(n >= s.size()){
            return true;
        }
        for(auto it = wordDict.begin(); it != wordDict.end();++it )
        {
            auto idx = to_string(n) + "-" + *it;
            if(auto cit = cache.find(idx); cit != cache.end())
                return cit->second;
            if(starts_with(s, n, *it) && wordBreak2(s, wordDict, n + it->size(), cache))
            {
                cache[idx] = true;
                return true;
            }
            cache[idx] = false;
        }
        return false;
    }

    
    bool wordBreak3(const string& s, vector<string>& wordDict, size_t n, vector<pair<bool, bool>>& cache ) {
        if(n >= s.size()){
            return true;
        }
        if(cache[n].first)
            return cache[n].second;
        for(auto it = wordDict.begin(); it != wordDict.end();++it )
        {
            if(starts_with(s, n, *it) && wordBreak3(s, wordDict, n + it->size(), cache))
            {
                cache[n] = {true, true};
                return true;
            }
        }
        cache[n] = {true, false};
        return false;
    }

    bool wordBreak(TEST t, string s, vector<string>& wordDict) {

        vector<string> wordDict2;
        for(auto it = wordDict.begin(); it != wordDict.end(); ++it)
        {
            auto pos = s.find(*it);
            if(pos == s.npos)
                continue;
            wordDict2.push_back(*it);
        }
        if(t == DEBUG1)
        {
            vector<pair<bool, bool>> cache(s.size(), {false, false});
            return wordBreak3(s, wordDict2, 0, cache);
        }
        else
        {
           std::map<string, bool> cache;
           return wordBreak2(s, wordDict2, 0, cache);
        }
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        vector<string> wordDict2;
        for(auto it = wordDict.begin(); it != wordDict.end(); ++it)
        {
            auto pos = s.find(*it);
            if(pos == s.npos)
                continue;
            wordDict2.push_back(*it);
        }
        std::map<string, bool> cache;
        return wordBreak2(s, wordDict2, 0, cache);
    }

    // fastest from leetcode
    bool wordBreak_leet(string s, vector<string>& wordDict) {
        vector<int> dp(s.length()+1,false);
        unordered_set<string> S;
        int maxi=0;
        int mini=1e9;
        for(auto &i:wordDict){
            S.insert(i);
            int p=i.length();
            maxi=max(maxi,p);
            mini=min(mini,p);
        }

        dp[0]=true;
        for(int i=mini;i<=s.length();i++){
            for(int j=max(0,i-maxi);j<=i-mini;j++){
                if(dp[j]&& S.find(s.substr(j,i-j))!=S.end()){
                    dp[i]=true;
                }
            }
        }

        return dp[s.length()];
    }

    // Iterative - TLE
    bool wordBreak_leet2(string s, vector<string>& wordDict) {
        if (s.length() == 0) return true;

        for (auto word : wordDict) {
            string cand = s.substr(0, word.length());
            // LOGGVVV(s, word, cand);
            if (cand == word) {
                string newS = s.substr(word.length(), s.length() - word.length());
                if (wordBreak_leet2(newS, wordDict)) return true;
            }
        }
        return false;
    }
};


int main()
{
    cout << "begin"<< endl;
    vector<string> wordDict;
    Solution sol;

    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    //assert(false == sol.wordBreak_leet2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict));
    // auto f1 = [&]() {
    //     auto res = sol.wordBreak_leet2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict);
    //     cout << res << " ";
    // };
    // cout << duration(f1) << endl;
    auto f2 = [&]() {
        auto res = sol.wordBreak(Solution::DEBUG1, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", wordDict);
        cout << res << " ";
    };
    cout << duration(f2) << endl;

    wordDict = {"cats","dog","sand","and","cat"};
    assert(false == sol.wordBreak("catsandog", wordDict));

    wordDict = {"cc","ac"};
    assert(true == sol.wordBreak("ccaccc", wordDict));

    wordDict = {"leet","code"};
    assert(true == sol.wordBreak("leetcode", wordDict));

    wordDict = {"apple","pen"};
    assert(true == sol.wordBreak("applepenapple", wordDict));

    

    wordDict = {"car","ca","rs"};
    assert(true == sol.wordBreak("cars", wordDict));
    
    wordDict = {"kfomka","hecagbngambii","anobmnikj","c","nnkmfelneemfgcl","ah","bgomgohl","lcbjbg","ebjfoiddndih","hjknoamjbfhckb","eioldlijmmla","nbekmcnakif","fgahmihodolmhbi","gnjfe","hk","b","jbfgm","ecojceoaejkkoed","cemodhmbcmgl","j","gdcnjj","kolaijoicbc","liibjjcini","lmbenj","eklingemgdjncaa","m","hkh","fblb","fk","nnfkfanaga","eldjml","iejn","gbmjfdooeeko","jafogijka","ngnfggojmhclkjd","bfagnfclg","imkeobcdidiifbm","ogeo","gicjog","cjnibenelm","ogoloc","edciifkaff","kbeeg","nebn","jdd","aeojhclmdn","dilbhl","dkk","bgmck","ohgkefkadonafg","labem","fheoglj","gkcanacfjfhogjc","eglkcddd","lelelihakeh","hhjijfiodfi","enehbibnhfjd","gkm","ggj","ag","hhhjogk","lllicdhihn","goakjjnk","lhbn","fhheedadamlnedh","bin","cl","ggjljjjf","fdcdaobhlhgj","nijlf","i","gaemagobjfc","dg","g","jhlelodgeekj","hcimohlni","fdoiohikhacgb","k","doiaigclm","bdfaoncbhfkdbjd","f","jaikbciac","cjgadmfoodmba","molokllh","gfkngeebnggo","lahd","n","ehfngoc","lejfcee","kofhmoh","cgda","de","kljnicikjeh","edomdbibhif","jehdkgmmofihdi","hifcjkloebel","gcghgbemjege","kobhhefbbb","aaikgaolhllhlm","akg","kmmikgkhnn","dnamfhaf","mjhj","ifadcgmgjaa","acnjehgkflgkd","bjj","maihjn","ojakklhl","ign","jhd","kndkhbebgh","amljjfeahcdlfdg","fnboolobch","gcclgcoaojc","kfokbbkllmcd","fec","dljma","noa","cfjie","fohhemkka","bfaldajf","nbk","kmbnjoalnhki","ccieabbnlhbjmj","nmacelialookal","hdlefnbmgklo","bfbblofk","doohocnadd","klmed","e","hkkcmbljlojkghm","jjiadlgf","ogadjhambjikce","bglghjndlk","gackokkbhj","oofohdogb","leiolllnjj","edekdnibja","gjhglilocif","ccfnfjalchc","gl","ihee","cfgccdmecem","mdmcdgjelhgk","laboglchdhbk","ajmiim","cebhalkngloae","hgohednmkahdi","ddiecjnkmgbbei","ajaengmcdlbk","kgg","ndchkjdn","heklaamafiomea","ehg","imelcifnhkae","hcgadilb","elndjcodnhcc","nkjd","gjnfkogkjeobo","eolega","lm","jddfkfbbbhia","cddmfeckheeo","bfnmaalmjdb","fbcg","ko","mojfj","kk","bbljjnnikdhg","l","calbc","mkekn","ejlhdk","hkebdiebecf","emhelbbda","mlba","ckjmih","odfacclfl","lgfjjbgookmnoe","begnkogf","gakojeblk","bfflcmdko","cfdclljcg","ho","fo","acmi","oemknmffgcio","mlkhk","kfhkndmdojhidg","ckfcibmnikn","dgoecamdliaeeoa","ocealkbbec","kbmmihb","ncikad","hi","nccjbnldneijc","hgiccigeehmdl","dlfmjhmioa","kmff","gfhkd","okiamg","ekdbamm","fc","neg","cfmo","ccgahikbbl","khhoc","elbg","cbghbacjbfm","jkagbmfgemjfg","ijceidhhajmja","imibemhdg","ja","idkfd","ndogdkjjkf","fhic","ooajkki","fdnjhh","ba","jdlnidngkfffbmi","jddjfnnjoidcnm","kghljjikbacd","idllbbn","d","mgkajbnjedeiee","fbllleanknmoomb","lom","kofjmmjm","mcdlbglonin","gcnboanh","fggii","fdkbmic","bbiln","cdjcjhonjgiagkb","kooenbeoongcle","cecnlfbaanckdkj","fejlmog","fanekdneoaammb","maojbcegdamn","bcmanmjdeabdo","amloj","adgoej","jh","fhf","cogdljlgek","o","joeiajlioggj","oncal","lbgg","elainnbffk","hbdi","femcanllndoh","ke","hmib","nagfahhljh","ibifdlfeechcbal","knec","oegfcghlgalcnno","abiefmjldmln","mlfglgni","jkofhjeb","ifjbneblfldjel","nahhcimkjhjgb","cdgkbn","nnklfbeecgedie","gmllmjbodhgllc","hogollongjo","fmoinacebll","fkngbganmh","jgdblmhlmfij","fkkdjknahamcfb","aieakdokibj","hddlcdiailhd","iajhmg","jenocgo","embdib","dghbmljjogka","bahcggjgmlf","fb","jldkcfom","mfi","kdkke","odhbl","jin","kcjmkggcmnami","kofig","bid","ohnohi","fcbojdgoaoa","dj","ifkbmbod","dhdedohlghk","nmkeakohicfdjf","ahbifnnoaldgbj","egldeibiinoac","iehfhjjjmil","bmeimi","ombngooicknel","lfdkngobmik","ifjcjkfnmgjcnmi","fmf","aoeaa","an","ffgddcjblehhggo","hijfdcchdilcl","hacbaamkhblnkk","najefebghcbkjfl","hcnnlogjfmmjcma","njgcogemlnohl","ihejh","ej","ofn","ggcklj","omah","hg","obk","giig","cklna","lihaiollfnem","ionlnlhjckf","cfdlijnmgjoebl","dloehimen","acggkacahfhkdne","iecd","gn","odgbnalk","ahfhcd","dghlag","bchfe","dldblmnbifnmlo","cffhbijal","dbddifnojfibha","mhh","cjjol","fed","bhcnf","ciiibbedklnnk","ikniooicmm","ejf","ammeennkcdgbjco","jmhmd","cek","bjbhcmda","kfjmhbf","chjmmnea","ifccifn","naedmco","iohchafbega","kjejfhbco","anlhhhhg"};
    assert(true == sol.wordBreak("fohhemkkaecojceoaejkkoedkofhmohkcjmkggcmnami", wordDict));

    cout << "end" << endl;
    return 0;
}