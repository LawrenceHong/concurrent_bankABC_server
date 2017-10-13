#ifndef BANK_SESSION_H
#define BANK_SESSION_H

#include <cstdlib>
#include <string>
#include "JvmUtil.h"

class BankSession {
public:
	BankSession(JvmUtil& jvmUtil);
	void Process(std::string& data);
private:
	void CallJava(std::string& data);
	JvmUtil& jvmUtil_;
};
#endif
