#include "BankSession.h"
#include <cstdio>

BankSession::BankSession() {
	printf("BankSession()\n");
}

BankSession::~BankSession() {
	printf("~BankSession()\n");
}

void BankSession::SetData(const char* data, size_t len) {
	printf("Setdata()\n");
}

void BankSession::Process() {
	printf("Process()\n");
}

