project(HelloWorld)
cmake_minimum_required(VERSION 3.0)

add_executable(CA4 main.cpp customer.cpp account.cpp transaction.cpp bank.cpp)
add_executable(main_test main_test.cpp)