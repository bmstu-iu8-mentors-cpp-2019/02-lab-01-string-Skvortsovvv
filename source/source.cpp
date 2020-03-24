// Copyright 2020 Skvortsov Vladimir <your_email>
#include <string.hpp>
#include <cstring>
std::ostream& operator<<(std::ostream& out, const String& str) {
    for (size_t i = 0; i < str.Size(); i++) {
        out << str.ptr[i];
    }
    return out;
}

String operator+(const String& a, const String& b) {
    char* ps = new char[a.Size() + b.Size() + 1];
    ps[a.Size() + b.Size()] = '\0';
    for (size_t i = 0; i < a.Size(); i++) {
        ps[i] = a.ptr[i];
    }
    for (size_t i = a.Size(), j = 0; i < a.Size() + b.Size(); i++, j++) {
        ps[i] = b.ptr[j];
    }
    String* str = new String(ps);
    delete[]ps;
    return *str;
}

String operator*(const String& a, unsigned int b) {
    char* ps = new char[a.Size() * b + 1];
    ps[a.Size() * b] = '\0';
    for (size_t i = 0, j = 0; i < (a.Size() * b); i++, j++) {
        if (j == a.Size()) j = 0;
        ps[i] = a.ptr[j];
    }
    String* str = new String(ps);
    delete[]ps;
    return *str;
}

bool operator!=(const String& a, const String& b) {
    size_t count = 0;
    if (a.Size() != b.Size()) return true;
    else
    {
        for (size_t i = 0; i < a.Size(); i++) {
            if (a.ptr[i] == b.ptr[i]) count++;
        }
        if (count == a.Size()){
           return false;
        } else {
           return true;
        }
    }
}

bool operator>(const String& a, const String& b) {
    if (a.Size() > b.Size()){
       return true;
    } else {
       return false;
    }
}

String::~String() {
    delete[]ptr;;
}
String::String() {
    ptr = nullptr;
}
String::String(const String& str) {
    size_t len = str.Size();
    ptr = new char[len + 1];
    ptr[len] = '\0';
    delete[]ptr;
    for (size_t i = 0; i < len; i++) {
        ptr[i] = str.ptr[i];
    }
}
String::String(const char* data) {
    int len = strlen(data);
    ptr = new char[len + 1];
    ptr[len] = '\0';
    for (size_t i = 0; ptr[i] != '\0'; i++) {
        ptr[i] = data[i];
    }
}
String& String::operator=(const String& str) {
    size_t len = str.Size();
    delete[]ptr;
    char* ps = new char[len + 1];
    ps[len] = '\0';
    for (size_t i = 0; i < len; i++) {
        ps[i] = str.ptr[i];
    }
    ptr = ps;
    return *this;
}
String& String::operator+=(const String& str) {
    char* newstr = new char[this->Size() + str.Size() + 1];
    newstr[this->Size() + str.Size()] = '\0';
    for (size_t i = 0; i < this->Size(); i++) {
        newstr[i] = ptr[i];
    }
    for (size_t i = this->Size(), j = 0;
         i < this->Size() + str.Size(); i++, j++) {
        newstr[i] = str.ptr[j];
    }
    delete[]ptr;
    ptr = newstr;
    return *this;
}
String& String::operator*=(unsigned int m) {
    char* ps = new char[this->Size() * m + 1];
    ps[this->Size() * m] = '\0';
    for (size_t i = 0, j = 0; i < this->Size() * m; i++, j++) {
        if (j == this->Size()) j = 0;
        ps[i] = ptr[j];
    }
    delete[]ptr;
    ptr = ps;
    return *this;
}

bool String::operator==(String& str) {
    size_t count = 0;
    if (this->Size() == str.Size()) {
        for (size_t i = 0; i < this->Size(); i++) {
            if (ptr[i] == str.ptr[i]) count++;
        }
        if (count == this->Size()) return true;
        else
        {
           return false;
        }
    } else {
       return false;
    }
}

size_t String::Find(const String& str) const {
    size_t count = 0, size = this->Size(), j = 0;
    int key = -1;
    if (size < str.Size()) return -1;
    else
    {
        for (size_t i = 0; i < size; i++) {
            if (ptr[i] != str.ptr[j]) {
                count = j = 0;
                key = -1;
            } else {
                count++;
                j++;
                if (key == -1) key = i;
            }
            if (count == str.Size()) return key;
        }
    }
    return -1;
}

void String::Replace(char oldSymbol, char newSymbol) {
    for (size_t i = 0; i < this->Size(); i++) {
        if (ptr[i] == oldSymbol) ptr[i] = newSymbol;
    }
}
size_t String::Size() const {
    size_t count = 0;
    for (size_t i = 0; ptr[i] != '\0'; i++) {
        count++;
    }
    return count;
}
bool String::Empty() {
    if (this->Size() == 0) return true;
    else
    {
        return false;
    }
}

char String::operator[](size_t index) const {
    return ptr[index];
}
char& String::operator[](size_t index) {
    return ptr[index];
}
void String::RTrim(char symbol) {
    int count = 0;
    for (int i = this->Size(); i > -1; i--) {
        if (ptr[i] == symbol) count++;
        else
        {
           i = -1;
        }
    }
    char* ps = new char[this->Size() - count + 1];
    ps[this->Size() - count] = '\0';
    for (size_t i = 0; i < this->Size() - count; i++) {
        ps[i] = ptr[i];
    }
    delete[]ptr;
    ptr = ps;
}
void String::LTrim(char symbol) {
    size_t count = 0;
    for (size_t i = 0; i < this->Size(); i++) {
        if (ptr[i] == symbol) count++;
        else
        {
           i = this->Size();
        }
    }
    char* ps = new char[this->Size() - count + 1];
    ps[this->Size() - count] = '\0';
    for (size_t i = 0, j = count; i < this->Size() - count; i++, j++) {
        ps[i] = ptr[j];
    }
    delete[]ptr;
    ptr = ps;
}
void String::Swap(String& oth) {
    char* ps1 = new char[oth.Size() + 1];
    char* ps2 = new char[this->Size() + 1];
    ps1[oth.Size()] = '\0';
    ps2[this->Size()] = '\0';
    for (size_t i = 0; i < oth.Size(); i++) {
        ps1[i] = oth.ptr[i];
    }
    for (size_t i = 0; i < this->Size(); i++) {
        ps2[i] = ptr[i];
    }
    delete[]ptr;
    delete[]oth.ptr;
    ptr = ps1;
    oth.ptr = ps2;
}

bool String::operator==(const char* str) const {
    if (this->Size() == strlen(str)) {
        size_t count = 0;
        for (size_t i = 0; i < this->Size(); i++) {
            if (ptr[i] == str[i]) {
                count++;
            }
        }
        if (count == this->Size()) return true;
    } else {
        return false;
    }
}
