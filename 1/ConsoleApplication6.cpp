#include <iostream>

using namespace std;

class String {
private:
    char* str;

public:
    String() : str(nullptr) {}
    String(const char* s) : str(nullptr) {
        if (s) {
            int len = 0;
            while (s[len]) {
                len++;
            }
            str = new char[len + 1];
            for (int i = 0; i <= len; i++) {
                str[i] = s[i];
            }
        }
    }
    String(const String& other) : String(other.str) {}
    void replace(const char* s) {
        delete[] str;
        str = nullptr;
        if (s) {
            int len = 0;
            while (s[len]) {
                len++;
            }
            str = new char[len + 1];
            for (int i = 0; i <= len; i++) {
                str[i] = s[i];
            }
        }
    }
    String substring(int start, int end) {
        if (!str || start < 0 || end < start) {
            return String();
        }
        int len = end - start + 1;
        char* sub = new char[len + 1];
        for (int i = 0; i < len; i++) {
            sub[i] = str[start + i];
        }
        sub[len] = '\0';

        return String(sub);
    }
    void print() {
        if (str) {
            cout << str;
        }
    }
    int countWords(const char* word) {
        if (!str || !word) 
            return 0;
        int count = 0;
        int wordLen = 0;
        while (word[wordLen]) {
            wordLen++;
        }
        int i = 0;
        while (str[i]) {
            int j = 0;
            while (j < wordLen && str[i + j] && str[i + j] == word[j]) {
                j++;
            }
            if (j == wordLen && (!str[i + j] || str[i + j] == ' ')) {
                count++;
            }
            i++;
        }
        return count;
    }
    ~String() {
        delete[] str;
    }
};
int main() {
    String str1;
    String str2("Hello");
    String str3 = str2;
    str1.print();
    cout << endl;
    str2.print();
    cout << endl;
    str3.print();
    cout << endl;
    str1.replace("World");
    str1.print();
    cout << endl;
    String subStr = str1.substring(0, 1);
    subStr.print();
    cout << endl;
    int wordCount = str1.countWords("World");
    cout << "Result: " << wordCount << endl;
}
