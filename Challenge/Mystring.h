#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);
    
private:
    char *str;  // pointer to a char[] that holds a C-style string
public:
    Mystring();                                 // No-args constructor
    Mystring(const char *s);                    // Overloaded constructor
    Mystring(const Mystring &source);           // Copy constructor
    Mystring( Mystring &&source);               // Move constructor
    ~Mystring();                                // Destructor

    Mystring &operator=(const Mystring &rhs);   // Copy assignment
    Mystring &operator=(Mystring &&rhs);        // Move assignment
    
    void display() const;
    
    int get_length() const;                     // getters
    const char *get_str() const;
    
//    bool operator==(const Mystring &rhs) const;
//    bool operator!=(const Mystring &rhs) const;
//    bool operator<(const Mystring &rhs) const;
//    bool operator>(const Mystring &rhs) const;
//    Mystring operator-() const;
//    Mystring operator+(const Mystring &rhs) const;
//    Mystring &operator+=(const Mystring &rhs);
//    Mystring operator*(size_t rhs) const;
//    Mystring &operator*=(size_t rhs);
//    Mystring &operator++();
//    Mystring operator++(int);
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &lhs);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
    friend Mystring operator*(const Mystring &lhs, int n);
    friend Mystring &operator*=(Mystring &lhs, int n);
    friend Mystring &operator++(Mystring &rhs);
    friend Mystring operator++(Mystring &lhs, int);
};

#endif // _MYSTRING_H_