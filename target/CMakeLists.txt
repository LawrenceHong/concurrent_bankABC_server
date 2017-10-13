include_directories(${JNI_INCLUDE_DIRS})
link_directories(${JNI_LIBRARIES})
add_executable(bank_abc bankABC/BankServer.cc bankABC/BankSession.cc bankABC/JvmUtil.cc bankABC/main.cc)
target_link_libraries(bank_abc muduo_net jvm)
