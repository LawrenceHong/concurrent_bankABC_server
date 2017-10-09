#ifndef BANK_SESSION_H
#define BANK_SESSION_H

#include<cstdlib>

class BankSession {
public:
	BankSession();
	~BankSession();
	void SetData(const char* data, size_t len);
	void Process();
private:
};
#endif
