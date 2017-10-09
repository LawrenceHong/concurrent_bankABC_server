#include "BankServer.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

int main() {
	muduo::net::EventLoop loop;
	muduo::net::InetAddress listenAddr(2017);
	BankServer server(&loop, listenAddr);
	server.start();
	loop.loop();
}
