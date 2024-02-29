#include <iostream>
#include <locale>
#include <codecvt>
#include <string>

using namespace std;

int main() {

    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    setlocale(LC_ALL, "RUS");
    system("chcp 1251");

    wstring text;
    int shift;

    wcout << L"Введите текст для шифрования: ";
    wcin.ignore();
    getline(wcin, text);

    wcout << L"Введите сдвиг для шифрования: ";
    wcin >> shift;
    wcin.ignore();

    for (wchar_t& c : text) {
        if (iswalpha(c)) {
            wchar_t offset = iswupper(c) ? L'А' : L'а';
            c = (c - offset + shift) % 32 + offset;
        }
    }

    wcout << L"Зашифрованный текст: " << text << endl;

    return 0;
}