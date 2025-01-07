#include "drlog.h"
#include <iostream>
using namespace std;

int main() {
    drlog::logger lg = drlog::logger();
    lg.info("This is an info!");
    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");
    lg.log("This is a log!");
    lg.debug("This is a debug!");

    return 0;
}