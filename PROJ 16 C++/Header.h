#pragma once

class Chaine

{

private:

	char* m_str;
	int   m_size;

public:

	Chaine(); 
	Chaine(const char* ch);
	Chaine(const Chaine& ch);
	~Chaine();

	void afficher()const ;
	bool equals(const Chaine& ch)const;
	Chaine concat(const Chaine& ch);

	Chaine operator = (const Chaine& a); 
	bool   operator == (const Chaine& a)const;

};