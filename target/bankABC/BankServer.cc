#include "BankServer.h"
#include "BankSession.h"

#include <muduo/base/Logging.h>
#include <muduo/base/LogStream.h>
#include <boost/bind.hpp>

#include <cstdio>
#include <string.h>

BankServer::BankServer(JvmUtil& jvmUtil,
		       muduo::net::EventLoop* loop,
		       const muduo::net::InetAddress& listenAddr)
	: jvmUtil_(jvmUtil),
	  loop_(loop),
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
	}
}

void BankServer::onMessage(const muduo::net::TcpConnectionPtr& conn,
			   muduo::net::Buffer* buf,
			   muduo::Timestamp time) 
{
	while(buf->readableBytes() >= kHeaderLen) {
		muduo::string t = buf->retrieveAllAsString();
		std::string msg(t.c_str());
		BankSession bs(jvmUtil_);
		bs.Process(msg);
		LOG_INFO << buf->retrieveAllAsString();
		break;
	}
}
