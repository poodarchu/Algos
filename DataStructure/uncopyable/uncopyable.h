#ifndef _UNCOPYABLE_H_INCLUDED
#define _UNCOPYABLE_H_INCLUDED

//avoid copying
class Uncopyable {
public:
	Uncopyable() {}
	~Uncopyable() {}

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

#endif