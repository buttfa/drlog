#include <iostream>

#include "drlog/drlog.h"

using namespace std;

int main() {
    cout << "*****************************************************" << endl;
    drlog::logger lg1 = drlog::logger();
    lg1.info("This is an info!");
    lg1.note("This is a note!");
    lg1.warn("This is a warn!");
    lg1.error("This is an error!");
    lg1.log("This is a log!");
    lg1.debug("This is a debug!");

    cout << "*****************************************************" << endl;

    drlog::logger lg2("[{TYPE}]: {MESSAGE} || {FILE}:{LINE} || {FUNCTION} || "
                      "{PRETTY_FUNCTION}");
    lg2.info("This is an info!", DR_INFO);
    lg2.note("This is a note!", DR_INFO);
    lg2.warn("This is a warn!", DR_INFO);
    lg2.error("This is an error!", DR_INFO);
    lg2.log("This is a log!", DR_INFO);
    lg2.debug("This is a debug!", DR_INFO);

    return 0;
}