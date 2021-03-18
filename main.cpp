#include <iostream>
#include <string>

#include "ui.h"

using namespace std;

int main(int argc, char **argv) {
    UI ui;
    if(argv[1] == "?")
        ui.cli_repl(argc, argv);
    else
        ui.get_args(argc, argv);
}