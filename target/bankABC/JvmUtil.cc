#include <cstdio>
#include <jni.h>
#include <string.h>

#include <iostream>
#include "JvmUtil.h"

using namespace std;

JvmUtil::JvmUtil() {
	opt[0].optionString = const_cast<char*>("-Djava.class.path=DB.jar");
	memset(&jvm_args, 0, sizeof(jvm_args));
        jvm_args.version = JNI_VERSION_1_8;
        jvm_args.nOptions = 1;
        jvm_args.options = opt;
	
	JNI_CreateJavaVM(&jvm, reinterpret_cast<void**>(&jenv), &jvm_args);
        cout << "JVM load succeeded: Version" << endl;
        jint ver = jenv->GetVersion();
        cout << ((ver>>16)&0x0f) << "."<<(ver&0x0f) << endl;
}

JvmUtil::~JvmUtil() {
	jvm->DestroyJavaVM();
	cout << "after destory Java VM" << endl;
}

void JvmUtil::CallJavaMethod(string& data) {
	cout << data << endl;
	string msg = "localhost#6379#"+data;
	jstring msg_ = jenv->NewStringUTF(msg.c_str());
	
	jclass cls = jenv->FindClass("Main");
	if(!cls) {
    		cerr << "ERROR: class not found !";
	}
	else {
    		cout << "Class Main found" << endl;
    		jmethodID mid = jenv->GetStaticMethodID(cls, "main_method", "(Ljava/lang/String;)V");
    		if(!mid)
        		cerr << "ERROR: method void main_method not found !" << endl;
    		else {
        		//jenv->CallVoidMethod(cls, mid, msg_);
			jenv->CallObjectMethod(cls, mid, msg_);
   		}
	}
}
