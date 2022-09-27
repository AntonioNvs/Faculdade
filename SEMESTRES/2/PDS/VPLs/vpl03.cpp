#include <iostream>
#include <vector>
#include <map>  // Isto é uma dica. 
#include <string>

using namespace std;

vector<string> split(string sentence) {
    vector<string> words;
    string word = "";
    
    for(int i = 0; i < sentence.size(); i++) {
        if(sentence[i] == ' ' || sentence[i] == '\n') {
            words.push_back(word);
            word = "";
        } else
            word += sentence[i];
    }
    
    if(word != "")
        words.push_back(word);
        
    return words;
}

using namespace std;

int main() {
    string snt, sentence;
    
    while(getline(cin, snt)) {
        sentence += snt;
    }
        
    
    vector<string> words = split(sentence);
    map<string, int> hash;

    for(int i = 0; i < words.size(); i++)
        hash[words[i]]++;
        
    string common = "";
    int count = -1;
    
    for(auto par : hash)
        if(par.second > count) {
            common = par.first;
            count = par.second;
        }
    
    cout << common << endl;
        
  return 0;
}