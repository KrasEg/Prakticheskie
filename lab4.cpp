#include <iostream> 
#include <string>
using namespace std;
string text;
void showStr(string txt) {
    setlocale(LC_ALL, "Russian");
    cout << txt<<'\n';
}
void deleteSpace(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ' && txt[i + 1] == ' ')
            while (txt[i + 1] == ' ')
                txt.erase((i + 1), 1);
    }
    text = txt;
}
void deletePunctMarks(string txt) {
    for (int i = 0; i <= txt.size(); i++) {
        if (txt[i] >32 && txt[i]<48 || txt[i]==63)
            if (txt[i] == '.' && txt[i + 1] == '.' && txt[i + 2] == '.' && txt[i + 3] == ' ')
                i += 3;
            else {
                while (txt[i+1] > 32 && txt[i+1] < 48 || txt[i+1]==63)
                    txt.erase((i + 1), 1);
            }
    }
    text = txt;
}
void Register(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            i += 2;
        txt[i] = tolower(txt[i]);
    }
    text = txt;
}
void toUpFirst(string txt) {
    txt[0] = toupper(txt[0]);
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            txt[i + 1] = toupper(txt[i + 1]);
    }
    showStr(txt);
}
void search(string txt) {
    string key;
    bool check;
    int count = 0;
    cin >> key;
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == key[0]) {
            check = true;
            for (int j = 1; j < key.size(); j++) {
                if (txt[i + j] != key[j]) {
                    check = false;
                }
            }
            if (check == true)
                count++;
        }
    }
    if (count == 0) {
        cout << "Соответствий не найдено";
    }
    else {
        cout << "Найдено " << count << " соответствий";
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    getline(cin,text);
    deleteSpace(text);
    deletePunctMarks(text);
    Register(text);
    showStr(text);
    int a = 0;
    cout << "Слова в обратном порядке: ";
    for (int i = text.length(); i >= 0; i--) {
        if (text[i] == ' ' || i==-1) {
            for (int k = i + 1; k <= (i + a-1); k++) {
                cout << text[k];
            }
            cout << ' ';
            a = 0;
        }
        a++;
    }
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == ' ') break;
        cout << text[i];
    }
    cout << "\nВсе слова с заглавной буквы: ";
    toUpFirst(text);
    cout << "Введите подстроку, которую вы хотите найти \n";
    search(text);
}
