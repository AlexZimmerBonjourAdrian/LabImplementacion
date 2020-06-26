#include<iostream>
#include "../interfaces/ICollection.cpp"

#ifndef DTMESA_H
#define DTMESA_H

using namespace std;

class DtMesa : public ICollectible{
	private:
		int id;
		
	public:
		DtMesa(int);
		int getId();
		~DtMesa();
};


#endif
