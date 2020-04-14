
#include "SuperSocket.h"
#include "mrsocket.h"
#include "mrtool.h"

SuperSocket* SuperSocket::_instance = NULL;

SuperSocket::SuperSocket()
{
	mr_socket_init();
}

SuperSocket::~SuperSocket() 
{

}

SuperSocket* SuperSocket::getInstance()
{
	if (_instance == NULL) {
		_instance = new SuperSocket();
	}
	return _instance;
}

void SuperSocket::init()
{
	
}

void SuperSocket::start()
{

}
