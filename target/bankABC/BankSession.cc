#include "BankSession.h"
#include "JvmUtil.h"
#include <cstdio>
#include <jni.h>
#include <string.h>
#include <assert.h>

#include <iostream>

using namespace std;

BankSession::BankSession(JvmUtil& jvmUtil)
	:jvmUtil_(jvmUtil)
{
}

void BankSession::Process(string& data) {
	CallJava(data);
}

void BankSession::CallJava(string& data) {
	jvmUtil_.CallJavaMethod(data);	
}
