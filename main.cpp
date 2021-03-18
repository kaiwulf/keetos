#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv) {
    UI ui;
    if(argv[1] == "?")
        ui.cli_repl(argc, argv);
    else
        ui.get_args(argc, argv);
}