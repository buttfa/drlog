#include <iostream>

#include "drlog/drlog.h"

int main() {
    drlog::logger lg("[{TYPE}]: {MESSAGE}");

    lg.info("This is an info!");

    lg.note("This is a note!");
    lg.warn("This is a warn!");
    lg.error("This is an error!");

    lg.log("This is a log!");
    lg.debug("This is a debug!");

    return 0;
}