#include "drlog.h"
#include <iostream>
using namespace std;

int main() {
    drlog::logger lg("[{TYPE}]: {MESSAGE} || {FILE}:{LINE} || {FUNCTION} || "
                     "{PRETTY_FUNCTION}");
    lg.info("This is an info!", DR_INFO);
    lg.note("This is a note!", DR_INFO);
    lg.warn("This is a warn!", DR_INFO);
    lg.error("This is an error!", DR_INFO);
    lg.log("This is a log!", DR_INFO);
    lg.debug("This is a debug!", DR_INFO);
    return 0;
}