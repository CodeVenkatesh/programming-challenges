#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*

given an amount of words, make a "box" out the words
ex/

how many words? 1
word? hello

h e l l o
e       l
l       l
l       e
o l l e h

*/

class box
{
public:
    string word, word_space;
    vector<string> combinations;
    
    void init();
    void perline();
    void output();
};

void box::init()
{
    cout << "word? ";
    cin >> word;
    cout << endl;
    
    for(int i = 0; i < word.size(); i++)
    {
        word_space += word.at(i);
        word_space += '  ';
    }
    
    word_space.pop_back();
}

void box::perline()
{
    int space_val = word_space.size() - 2;
    string space;
    for(int i = 0; i < space_val; i++) space += ' ';
    
    combinations.push_back(word_space);
    
    for(int i = 1; i < word.size() - 1; i++)
    {
        string s = word.at(i) + space + word.at(word.size() - i - 1);
        combinations.push_back(s);
    }
    
    reverse(word_space.begin(), word_space.end());
    combinations.push_back(word_space);    
}

void box::output()
{
    for(vector<string>::iterator it = combinations.begin(); 
                                 it != combinations.end();
                                 it++)
        cout << *it << endl;
    
    cout << endl;
}


int main()
{
    box b;
    
    cout << "how many words? ";
    int wordnum;
    cin >> wordnum;
    
    for(int i = 0; i < wordnum; i++)
    {
        b.init();
        b.perline();
        b.output();
        
        b.word.clear();
        b.word_space.clear();
        b.combinations.clear();
    }
}
