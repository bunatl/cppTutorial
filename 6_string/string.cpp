#include "string.h"
#include <string.h>
#include <stdio.h>

int Str::Len() const
{
	//printf("int Str::Len() const\n");
	return strlen(this->buffer) + 1;
}
Str::Str(const char* c)
{
	//printf("Str::Str(const char* c)\n");
	buffer = new char[strlen(c) + 1];
	strcpy(this->buffer,c);
}
Str::Str(const Str& s)
{
	//printf("Str::Str(const Str& s)\n");
	buffer = new char[s.Len()];
	strcpy(buffer,s.buffer);
}
void Str::vypis()
{	
	printf("%s \n",this->buffer);
}

Str Str::operator +(const Str & s)
{
	//printf("Str Str::operator +(const Str & s)\n");
	Str temp;
	temp.buffer = new char[this->Len() + s.Len()];
	strcpy(temp.buffer,this->buffer);
	strcat(temp.buffer,s.buffer);
	return temp;
}
Str Str::operator +(const char *c)
{
	//printf("Str Str::operator +(const char *c)\n");
	Str temp;
	temp.buffer = new char[this->Len() + strlen(c)];
	strcpy(temp.buffer,this->buffer);
	strcat(temp.buffer,c);
	return temp;
}

void Str::coppy(const char *s)
{
	//printf("void Str::coppy(const char *s)\n");
	if(!s || !*s)
		buffer = 0;
	else
	{
		buffer = new char[strlen(s) + 1];
		if(buffer) strcpy(buffer,s);
	}
}
Str& Str::operator =(const Str & s)
{
	//printf("Str& Str::operator =(const Str & s)\n");
	this->clear(); this->coppy(s.buffer);
	return *this;	
}
Str& Str::operator =(const char *c)
{
	//printf("Str& Str::operator =(const char *c)\n");
	this->clear(); this->coppy(c);
	return *this;
}

bool Str::operator ==(const Str& s)
{
	//printf("bool Str::operator ==(const Str& s)\n");
	if(strcmp(this->buffer,s.buffer))
		return false;
	else
		return true;
}
bool Str::operator ==(const char * c)
{
	if(strcmp(this->buffer,c))
		return false;
	else
		return true;
}

bool Str::operator <(const Str &s) const
{
	if(strcmp(this->buffer, s.buffer) < 0)
		return true;
	else
		return false;
}
bool Str::operator <(const char * c) const
{
	if(strcmp(this->buffer, c) < 0)
		return true;
	else
		return false;
}

int main(void)
{
	Str r1 = "Ahoj";
	Str r2 = "Kamo";
	Str r3;
	r3 = r1 + r2;
	r3.vypis();
	r3 = r3 + "haha";
	r3.vypis();
	r3 = "abraka dabra";
	r3.vypis();
	r3 += " dabrka abra";
	r3.vypis();
	r3 += r1;
	r3.vypis();
	r3 += r1 +r2;
	r3.vypis();
	if(r1 == "Halo")
		printf("OK\n");
	else
		printf("Ne OK\n");
	if(r1 < "Halo")
		printf("OK\n");
	else
		printf("ne OK\n");
	if(r1 < r2)
		printf("r1\n");
	if("Ahoj" < "Kamo")
		printf("Ahoj\n");
	return 0;
}
