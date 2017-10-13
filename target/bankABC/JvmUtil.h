#ifndef JVM_UTIL_H
#define JVM_UTIL_H

#include <cstdlib>
#include <string.h>
#include <jni.h>

class JvmUtil {
public:
	JvmUtil();
	~JvmUtil();
	void CallJavaMethod(std::string& data);
private:
	JavaVM* jvm = NULL;
        JNIEnv* jenv = NULL;
        JavaVMInitArgs jvm_args;
        JavaVMOption opt[1];
};
#endif
