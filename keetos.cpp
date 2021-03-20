#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "keetos.h"

using namespace std;

// TO-DO serialize vector to save on disk

Keetos::Keetos(bool read) {
    s_keetos_file = "keetos.bin";

    if(read)
        xml_serialize_read();
    else
        xml_serialize_write();
}

void Keetos::xml_serialize_read() {
    fstream fee;

    fee.open(s_keetos_file, ios::out);
    if(!fee) {
        // load info to vector
    } else
        fee.close();
}

void Keetos::xml_serialize_write() {

}


void Keetos::run(string s) {
    if(s == "create") {
        Keetos::new_ticket("", "");
    } else if(s == "list") {
        to_dos();
    } else if(s == "find") {
        Keetos::find_title();
    } else if(s == "project") {
        Keetos::find_project();
    } else if(s == "finish") {
        Keetos::finish_ticket("", "");
    } else if(s == "delete") {
        Keetos::delete_ticket("", "");
    }
}

void Keetos::new_ticket(string start_date = "", string project_name = "") {
    if(start_date != "" && project_name != "") {
        cout << "Project: " << endl;
        cin >> project_name;
        cout << "Start date: " << endl;
        cin >> start_date;
    }
    inst_ticket(start_date, project_name);
    for(auto p : s_ticket_vec) {
        cout 
    }
}

void Keetos::inst_ticket(string start_date, string project_name) {
    Ticket a_new_one;
    a_new_one.create_ticket(start_date, project_name);
    s_tickets_vec.push_back(a_new_one);
    // Serializing ticket vector goes here
}

void Keetos::delete_ticket(string project_name = "", string title = "") {
    int i = 0;

    auto elem_to_remove = s_tickets_vec.begin();
    for(auto p : s_tickets_vec) {
        if(p.get_proj_name() == project_name || p.get_title() == title) {
                s_tickets_vec.erase(elem_to_remove + i); i+=1;
        }
    }
    // TO-DO reserialize updated vector and save to disk
}

void Keetos::finish_ticket(string project_name = "", string title = "") {
    for(auto p : s_tickets_vec) {
        if(p.get_proj_name() == project_name || p.get_title() == title) {
                p.set_checked(false);
        }
    }
    // TO-DO reserialize updated vector and save to disk
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
    for(auto p : s_tickets_vec) {
        if(p.get_checked()) {
            p.display_info();
        }
    }
}

string Keetos::get_cmd() {
    return s_cmd;
}
