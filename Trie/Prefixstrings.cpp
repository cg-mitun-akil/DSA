//https://leetcode.com/problems/sum-of-prefix-scores-of-strings/

struct TrieNode {
    struct TrieNode* children[26];
    vector<int>words;
};

map<string,vector<int>>m;

TrieNode* getNode(){
    TrieNode* x = new TrieNode;
    x->words.clear();
    for( int i = 0; i < 26; i++ )
        x->children[i] = NULL;
    return x;
}

void insert( TrieNode* root , string s , int key  )
{
    TrieNode* curr = root;
    for( int i = 0; i < s.length() ; i++ )
    {
        int index = s[i] - 'a';
        if( !curr->children[index] )
        {
            curr->children[index] = getNode();
        }
        ((curr->children[index])->words).push_back(key);

        curr = curr->children[index];
    }
}

vector<int>ans;

void solve( TrieNode* root )
{
    if( root == NULL )
        return;
    //cout<<root->words.size()<<endl;
    for( int i = 0; i < root->words.size(); i++ )
    {
        ans[ root->words[i] ]+= root->words.size();
    }
    for( int i = 0; i < 26; i++ )
    {
        if( root->children[i] )
            solve( root->children[i] );
    }
}



class Solution {
public:

    vector<int> sumPrefixScores(vector<string>& words) {
        m.clear();
        ans.assign( words.size() , 0 );
        TrieNode* root = getNode();
        for( int i = 0; i < words.size() ; i++ )
        {
            insert( root , words[i] , i );
            m[words[i]].push_back(i);
        }
        solve( root );
        return ans;
    }
};