
#include<string>
#include<iostream>

using namespace std;


class Obj {
    public:

    void removePre(string& s) {
        size_t char_count = 0;
        size_t i = 0;
        while (i < s.size()) {
            char c = s[i];
            if (c == '*' && char_count > 0) 
                char_count--;
            else if ('a' <= c && c <= 'z') 
                char_count++;
            else if (c == '#')
                char_count <<= 1;
            if (char_count <= 0) {
                s.erase(0,i+1);
                i = 0;
            }
            else
                i++;
        }
    }
};

int main() {
    Obj a = Obj();
    string s = "f#*#o#";
    // for (int i = 0; i < s.size(); i++) {
    //     cout << "i: " << i << "   s: " << s << "  s.size: " << s.size() << endl;
    //     s.erase(0,8);
    //     i = 0;
    //     cout << "i: " << i << "   s: " << s << "  s.size: " << s.size() << endl;
    //     cout << endl;
    // }
    cout << s << endl;
    a.removePre(s);
    cout << s << endl;


    return 0;
}