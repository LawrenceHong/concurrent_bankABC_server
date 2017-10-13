#include "BankServer.h"
#include "JvmUtil.h"
#include <muduo/base/Logging.h>
#include <muduo/net/EventLoop.h>

int main() {
	muduo::net::EventLoop loop;
	muduo::net::InetAddress listenAddr(2017);
	JvmUtil jvmUtil;
	BankServer server(jvmUtil, &loop, listenAddr);
	server.start();
	loop.loop();
}
