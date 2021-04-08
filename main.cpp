#include <iostream>
#include <string>
#include <string.h>

#include "ui.h"

using namespace std;

int main(int argc, char **argv) {
    UI ui;
    // if(strcoll( argv[1], "-l" ) == 0 || strcoll( argv[1], "--loop" ) == 0  )
    // if(argv[1] == "-l" || argv[1] == "--loop")
    //     ui.cli_repl(argc, argv);
    // else
        ui.get_args(argc, argv);
}