class Str
{
private:
	char * buffer;
public:
	Str() {buffer = 0;}
	Str(const char*);
	Str(const Str&);
	~Str() {delete[] buffer;}

	void coppy(const char*);
	void clear() {delete[] buffer;}
	int Len() const;
	void vypis();
	Str operator+(const Str&);
	Str operator+(const char*);
	Str& operator=(const Str&);
	Str& operator=(const char*);
	Str& operator+=(const Str& s) {*this = *this + s; return *this;}
	Str& operator+=(const char* s) {*this = *this + s; return *this;}
	bool operator ==(const Str&);
	bool operator ==(const char*);
	bool operator <(const Str&) const;
	bool operator <(const char*) const;
	bool operator >(const Str& s) const {return !(*this < s);}
	bool operator >(const char* s) const {return !(*this < s);}
};