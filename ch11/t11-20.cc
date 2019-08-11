#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string &strip(string &word) {
    cout << "strip before: " << word << endl;
    for (auto &w : word)
        w = tolower(w);
    word.erase(remove_if(word.begin(), word.end(), [](unsigned char x) { return ispunct(x); }), word.end());
    cout << "strip after: " << word << endl;
    return word;
}

int main() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        auto ret = word_count.insert({strip(word), 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

    return 0;
}