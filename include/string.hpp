// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include <cstddef>
#include <iostream>

#include <cstring>

class String
{
    char* ptr;
public:
    ~String();
    String();
    String(const String& str);
    explicit String(const char* data);
    String& operator=(const String& str);
    String& operator+=(const String& str);
    String& operator+=(const char* str);
    String& operator*=(unsigned int m);
    bool operator==(const char* rhs) const;
    bool operator==(const String& str) const;
    friend bool operator==(const char* rhs, const String& str);
    size_t Find(const String& str) const;
    size_t Find(const char* str) const;
    void Replace(char oldSymbol, char newSymbol);
    size_t Size() const;
    bool Empty();
    char operator[](size_t index) const;
    char& operator[](size_t index);
    void RTrim(char symbol);
    void LTrim(char symbol);
    void Swap(String& oth);
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend String operator+(const String& a, const String& b);
    friend String operator*(const String& a, unsigned int b);
    friend bool operator!=(const String& a, const String& b);
    friend bool operator>(const String& a, const String& b);
};

#endif  // INCLUDE_STRING_HPP_
