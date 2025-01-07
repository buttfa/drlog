#include "drlog.h"
#include <iostream>
using namespace std;

int main() {
    drlog::logger lg1("[{TYPE}]: {MESSAGE} || {FILE}:{LINE} || {FUNCTION} || "
                      "{PRETTY_FUNCTION}");
    lg1.info("This is an info!", DR_INFO);
    lg1.note("This is a note!", DR_INFO);
    lg1.warn("This is a warn!", DR_INFO);
    lg1.error("This is an error!", DR_INFO);
    lg1.log("This is a log!", DR_INFO);
    lg1.debug("This is a debug!", DR_INFO);

    cout << "*******************************************" << endl;

    drlog::logger lg2 = drlog::logger();
    DR_DEBUG(lg2.info("This is an info!"));
    DR_DEBUG(lg2.note("This is a note!"));
    DR_DEBUG(lg2.warn("This is a warn!"));
    DR_DEBUG(lg2.error("This is an error!"));
    DR_DEBUG(lg2.log("This is a log!"));
    DR_DEBUG(lg2.debug("This is a debug!"));
    return 0;
}