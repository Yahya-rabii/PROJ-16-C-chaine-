#include "Header.h"
#include <iostream>

using namespace std;

Chaine::Chaine()
{

    this->m_size = 0;
    this->m_str = nullptr;

}

Chaine::Chaine(const char* ch)
{   
    this->m_size = strlen(ch); 
    this->m_str = new char[this->m_size+1];  
    strcpy_s(this->m_str,this->m_size+1,ch );

}

Chaine::Chaine(const Chaine &ch)
{
    this->m_size = ch.m_size;
    this->m_str = new char[ch.m_size+1];
    strcpy_s(this->m_str, ch.m_size+1 , ch.m_str);

}

Chaine::~Chaine()
{

    delete [] this->m_str;
    this->m_str = nullptr;

}

void Chaine::afficher() const
{
    cout << "chaine -> " ;

    for (int i = 0; i < this->m_size; i++)
    {

        cout << this->m_str[i] ;
    
    }

    cout << endl;

    cout << "the size of the char : " << this->m_size << endl;
}

bool Chaine::equals(const Chaine &d) const
{

    if (strcmp(this->m_str, d.m_str) == 0) {

        return true;

    }
    
    else
    {
        return false;
    }
    
}

Chaine Chaine::concat(const Chaine&d)
{
    
    Chaine cp;
    int t = 0;
    
    cp.m_size = this->m_size + d.m_size ;
    
    cp.m_str = new char[cp.m_size +1 ];

    for (int i = 0; i < this->m_size; i++)
    {

        cp.m_str[i] = this->m_str[i];
        t++;
    }

    

    for (int i = t; i <= cp.m_size; i++)
    {

        cp.m_str[i] = d.m_str[i-t];

    }

    return cp;
}

Chaine Chaine::operator=(const Chaine& a)
{
    if (this != &a) {

        delete[] this->m_str;
        this->m_str = nullptr;
        this->m_str = new char[strlen(a.m_str) +1 ];
        this->m_size = a.m_size;
        strcpy_s(this->m_str, a.m_size + 1, a.m_str);

    }
    return *this;
}

bool Chaine::operator==(const Chaine& a) const
{

    if (strcmp(this->m_str, a.m_str) == 0) {

        return true;

    }

    else
    {
        return false;
    }

}
