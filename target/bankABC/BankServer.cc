#include "BankServer.h"
#include "BankSession.h"

#include <muduo/base/Logging.h>

#include <boost/bind.hpp>

#include <cstdio>

BankServer::BankServer(muduo::net::EventLoop* loop,
		       const muduo::net::InetAddress& listenAddr)
	: loop_(loop),
	  server_(loop, listenAddr, "BankServer")
{
	server_.setConnectionCallback(boost::bind(&BankServer::onConnection, this, _1));
	server_.setMessageCallback(boost::bind(&BankServer::onMessage, this, _1, _2, _3));
}

void BankServer::start() {
	server_.start();
}

void BankServer::onConnection(const muduo::net::TcpConnectionPtr& conn) {
	if (conn->connected()) {
		printf("BankServer::onConnection\n");
		//conn->setContext(BankSession());
	}
}

void BankServer::onMessage(const muduo::net::TcpConnectionPtr& conn,
			   muduo::net::Buffer* buf,
			   muduo::Timestamp time) 
{
	//printf("BankServer::onMessage\n");
	while(buf->readableBytes() >= kHeaderLen) {
		/*const void* data = buf->peek();
		const RequestHead* rh = static_cast<const RequestHead*>(data);
		uint16_t len = muduo::net::sockets::networkToHost16(rh->len);
		if(buf->readableBytes() >= len + kHeaderLen) {
			BankSession* bs = boost::any_cast<BankSession>(conn->getMutableContext());
			bs->SetData(buf->peek(), kHeaderLen+len);
			bs->Process();

			muduo::net::Buffer response;
			response.append(bs->GetJos().Data(), bs->GetJos->Length());
			bs->Clear();
			conn->send(&response);
			
			buf->retrieve(kHeaderLen+len);
		}
		else break;*/
		LOG_INFO << buf->retrieveAllAsString();
		break;
	}
}
