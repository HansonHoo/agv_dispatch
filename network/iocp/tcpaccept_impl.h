#ifndef TCPACCEPT_IMPL_H_
#define TCPACCEPT_IMPL_H_

#include "common_impl.h"
#include "iocp_impl.h"
#include "tcpsocket_impl.h"
#ifdef WIN32
namespace qyhnetwork
{
class TcpAccept : public std::enable_shared_from_this<TcpAccept>
{
public:
    TcpAccept();
    ~TcpAccept();
    bool initialize(EventLoopPtr& summer);
    bool openAccept(const std::string ip, unsigned short port, bool reuse = true);
    bool doAccept(const TcpSocketPtr& s, _OnAcceptHandler &&handler);
    bool onIOCPMessage(BOOL bSuccess);
    bool close();
private:
    std::string logSection();
private:
    //config
    EventLoopPtr _summer;


    std::string        _ip;
    unsigned short    _port = 0;

    //listen
    SOCKET            _server = INVALID_SOCKET;
    bool              _isIPV6 = false;

    //client
    SOCKET _socket = INVALID_SOCKET;
    char _recvBuf[200];
    DWORD _recvLen = 0;
    ExtendHandle _handle;
    _OnAcceptHandler _onAcceptHandler;
    TcpSocketPtr _client;

};
using TcpAcceptPtr = std::shared_ptr<TcpAccept>;

}

#endif
#endif