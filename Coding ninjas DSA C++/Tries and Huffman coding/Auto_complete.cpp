/*
Auto complete
Send Feedback
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.
Input Format :
The first line of input contains an integer, that denotes the value of n.
The following line contains n space separated words.
The following line contains the word w, that has to be auto-completed.
Output Format :
Print all possible words in separate lines.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
7
do dont no not note notes den
no
Sample Output 2 :
no
not
note
notes
Sample Input 2 :
7
do dont no not note notes den
de
Sample Output 2 :
den
Sample Input 3 :
7
do dont no not note notes den
nom
Sample Output 3 :
(Empty) There is no word which starts with "nom"

*/

/*___________________________________________________solution_____________________________________________________________________*/
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }
    void removeWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // Small calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // Word not found
            return;
        }

        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    void removeWord(string word) { removeWord(root, word); }

    bool searchhelper(TrieNode *root, string word)
    {

        // base

        if (word.size() == 0)
        {
            return true;
        }

        bool ans = false;
        TrieNode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            ans = true;
        }
        else
        {
            return false;
        }

        // Write your code here
        return ans && searchhelper(child, word.substr(1));
    }

    bool search(string word)
    {
        // Write your code here
        return searchhelper(root, word);
    }

    void autocomplete(TrieNode *root, string s)
    {
        if (root->isTerminal == true)
            cout << s << endl;

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                char c = i + 'a';
                autocomplete(root->children[i], s + c);
            }
        }
        return;
    }
    void autoComplete(vector<string> input, string pattern)
    {
        // build a trie
        for (int i = 0; i < input.size(); i++)
            insertWord(input[i]);
        // search in a trie
        if (search(pattern) == false)
            return;

        string s = pattern;

        while (pattern.size() != 0)
        {
            root = root->children[pattern[0] - 'a'];
            pattern = pattern.substr(1);
        }

        autocomplete(root, s);
    }
};