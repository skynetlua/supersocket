

#ifndef SuperSocket_h
#define SuperSocket_h

#include <stddef.h>



class SuperSocket
{
	SuperSocket();
	~SuperSocket();

	static SuperSocket* _instance;

	void init();
	void start();
public:
	static SuperSocket* getInstance();

};

#endif /* SuperSocket_h */
