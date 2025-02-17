#include "drlog.h"
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    drlog::logger lg;
    lg.set_print([](std::string msg) { printf("%s\n", msg.c_str()); });
    lg.info("This is an info!");
    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");
    lg.log("This is a log!");
    lg.debug("This is a debug!");

    cout << "***********************************" << endl;

    lg.recover_print();
    lg.info("This is an info!");
    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");
    lg.log("This is a log!");
    lg.debug("This is a debug!");

    return 0;
}