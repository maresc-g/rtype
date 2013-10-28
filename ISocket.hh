#include	<string>
#include	"ISocketClient.hh"

class ISocket
{
public:
	virtual ~ISocket(){}
	virtual int initialize(std::string const &) = 0;
	virtual int destroy() = 0;
	virtual int bindSocket(int const) = 0;
	virtual int listenSocket() = 0;
	virtual ISocketClient *connectToAddr(std::string const &, int const) = 0;
	virtual ISocketClient *acceptConnection() = 0;
};