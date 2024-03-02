#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
//        std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source)
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;
    
    if (this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
//    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return strcmp(str, rhs.str) == 0;
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return strcmp(str, rhs.str) != 0;
}

bool Mystring::operator<(const Mystring &rhs) const {
    return strcmp(str, rhs.str) < 0;
}

bool Mystring::operator>(const Mystring &rhs) const {
    return strcmp(str, rhs.str) > 0;
}

Mystring Mystring::operator-() const {
    auto s = new char[get_length() + 1];
    
    for (size_t i = 0; i < get_length(); i++) {
        s[i] = tolower(str[i]);
    }
    
    s[get_length()] = '\0';
    Mystring result(s);
    delete [] s;
    return result;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    auto s = new char[get_length() + rhs.get_length() + 1];
    strcpy(s, str);
    strcat(s, rhs.str);
    Mystring result(s);
    delete [] s;
    return result;
}

Mystring &Mystring::operator+=(const Mystring &rhs) {
    Mystring concatenated = *this + rhs;
    char *destination = new char[concatenated.get_length() + 1];
    strcpy(destination, concatenated.str);
    delete [] str;
    str = destination;
    return *this;
}

Mystring Mystring::operator*(size_t rhs) const {
    auto s = new char[get_length() * rhs + 1];
    strcpy(s, str);
    
    for (int i = 1; i < rhs; i++) {
        strcat(s, str);
    }
    
    Mystring result(s);
    delete [] s;
    return result;
}

Mystring &Mystring::operator*=(size_t rhs) {
    Mystring repeated = *this * rhs;
    char *destination = new char[repeated.get_length() + 1];
    strcpy(destination, repeated.str);
    delete [] str;
    str = destination;
    return *this;
}

Mystring &Mystring::operator++() {
    for (size_t i = 0; i < get_length(); i++) {
        str[i] = toupper(str[i]);
    }
    
    return *this;
}

Mystring Mystring::operator++(int) {
    Mystring temp (*this);
    operator++();
    return temp;
}
