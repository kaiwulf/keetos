#include <string>
#include <vector>

#include "Keetos.h"

using namespace std;

// TO-DO serialize vector to save on disk

Keetos::keetos() {
    s_state = "";
    // Load xml file from disk
}

void Keetos::run(string s) {
    if(s == "create") {
        Tickets *new_ticket = new Tickets;
        new_ticket->new_ticket();
        delete new_ticket;
    } else if(s == "list") {
        to_dos();
    } else if(s == "find") {
        find_title();
    }
}

void Keetos::new_ticket(string start_date = "", string project_name = "") {
    if(start_date != "" && project_name != "") {
        cout << "Project: " << endl;
        cin >> project;
        cout << "Start date: " << endl;
        cin >> start_date;
    }
    inst_ticket(start_date, project_name);
}

void Keetos::inst_ticket(string start_date, string project_name) {
    Tickets *a_new_one = new Tickets;
    a_new_one->create_ticket(start_date, project_name);
    s_tickets_vec.pusback(a_new_one);
    // Serializing ticket vector goes here
}

void Keetos::find_project() {
    string proj;
    cout << "Project? ";
    cin >> proj;
    for(auto p : s_tickets_vec) {
        if(p.get_proj_name() == proj) {
            p.display_info();
        }
    }
}

void Keetos::find_title() {
    string title;
    cout << "Title? ";
    cin >> title;
    for(auto p : s_tickets_vec) {
        if(p.get_title() == title) {
            p.display_info();
        }
    }
}

void Keetos::to_dos() {
    for(auto p ; s_tickets_vec) {
        if(p.get_checked()) {
            p.display_info();
        }
    }
}

string Keetos::get_cmd() {
    return s_cmd;
}
