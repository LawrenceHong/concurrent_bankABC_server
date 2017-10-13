#ifndef BANK_SERVER_H
#define BANK_SERVER_H

#include <muduo/net/TcpServer.h>
#include "JvmUtil.h"

class BankServer : boost::noncopyable {
public:
	BankServer(JvmUtil& jvmUtil,
		   muduo::net::EventLoop* loop,
		   const muduo::net::InetAddress& listenAddr);
	void start();
private:
	void onConnection(const muduo::net::TcpConnectionPtr& conn);
	void onMessage(const muduo::net::TcpConnectionPtr& conn,
		       muduo::net::Buffer* buf,
		       muduo::Timestamp time);
	
	JvmUtil& jvmUtil_;
	muduo::net::EventLoop* loop_;
	muduo::net::TcpServer server_;
	const static size_t kHeaderLen = 4; //cmd(2)+len(2)
};
#endif
