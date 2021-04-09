#include <iostream>
#include <string>
#include <string.h>

#include "ui.h"

using namespace std;

int main(int argc, char **argv) {
    UI ui;
    if(argc == 2) {
        if(strcoll( argv[1], "-l" ) == 0 || strcoll( argv[1], "--loop" ) == 0)
            ui.cli_repl(argc, argv);
    } else
        ui.get_args(argc, argv);
}