#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#include "ui.h"
#include "keetos.h"

using namespace std;
namespace fs = std::filesystem;

UI::UI()  {

}

void UI::cli_repl(int argc, char **argv) {

}

void UI::get_args(int argc, char **argv) {

    if(argc > 1 && argc < 4) {
        ui_usr_args.assign(argv + 1, argv + argc);
        arg_parse();
    } else if(argc == 1) {
        bool file = find_xml()
        Keetos state(false);
        cout << "This is KEETOS." << endl << "'create' a ticket" << endl
             << "'list' TO-DOs" << endl
             << "'find' a specific ticket" << endl
             << "'project' - retrieve ticket(s) related to a project" << endl
             << "'finish' a ticket" << endl
             << "'delete' a ticket" << endl;
        cin  >> ui_get;
    
        state.run(ui_get);
    
    } else {
        help();
    }
}

void UI:find_xml() {
    fs::path kfile{ "keetos.bin" };
    if (fs::exists(kfile))
        return true;
    else
        return false;
}

void UI::arg_parse() {
    bool read = find_xml();
    Keetos state(read);
    state.new_ticket(ui_usr_args[0] /* project name */, ui_usr_args[1] /* start date */);
}

// Ticket UI::new_ticket(string start_date, string project) {
//     Ticket a_new_one(start_date, project);
//     return a_new_one;
// }

void UI::help() {
    cout << "Usage:" << endl
        << "keetos [<project name> <start_date>]" << endl
        << "or" << endl
        << "keetos [?] (for repl)" << endl;
}