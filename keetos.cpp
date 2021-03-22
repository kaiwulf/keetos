#include <string>
#include <vector>
#include <iostream>
#include <fstream>


#include "keetos.h"

using namespace std;

// TO-DO serialize vector to save on disk

Keetos::Keetos() {

}

Keetos::Keetos(bool read) {
    k_keetos_file = "keetos.bin";

    if(read)
        xml_serialize_read();
}

Keetos::~Keetos() {
    init_serialize();
    xml_serialize_write();
}

void Keetos::init_serialize() {
        k_header = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
        k_checked = "checked";
        k_body = "body";
        k_assigned = "assigned";
        k_start = "start_date";
        k_end = "end date";
        k_title = "title";
        k_project = "project_name";
        k_body = "body";
        k_assigned = "assigned";

        push_vec_elems();
}

void Keetos::xml_serialize_read() {
    fstream xml_in;

    xml_in.open(k_keetos_file, ios::out);
        // load info to vector
}

void Keetos::push_vec_elems() {
    k_xml_vec.push_back(k_header);
    k_xml_vec.push_back(k_checked);
    k_xml_vec.push_back(k_body);
    k_xml_vec.push_back(k_assigned);
    k_xml_vec.push_back(k_start);
    k_xml_vec.push_back(k_end);
    k_xml_vec.push_back(k_title);
    k_xml_vec.push_back(k_project);
    k_xml_vec.push_back(k_assigned);
}

void Keetos::xml_serialize_write() {
    fstream xml_out;
    xml_out.open(k_keetos_file, ios::out);
    xml_out << k_header << endl;
    for(auto p : k_tickets_vec) {
        xml_out << "<" << k_title << ">" << p.get_title() << "</" << k_title << ">" << endl;
        xml_out << "<" << k_checked << ">" << p.get_checked() << "</" << k_checked << ">" << endl;
        xml_out << "<" << k_assigned << ">" << p.get_assigned() << "</" << k_assigned << ">" << endl;
        xml_out << "<" << k_start << ">" << p.get_start_date() << "</" << k_start << ">" << endl;
        xml_out << "<" << k_end << ">" << p.get_end_date() << "</" << k_end << ">" << endl;
        xml_out << "<" << k_project << ">" << p.get_proj_name() << "</" << k_project << ">" << endl;
        xml_out << "<" << k_body << ">" << p.get_body() << "</" << k_body << ">" << endl;
    }

}


void Keetos::run(string s) {
    if(s == "create") {
        new_ticket();
    } else if(s == "list") {
        to_dos();
    } else if(s == "find") {
        find_title();
    } else if(s == "project") {
        find_project();
    } else if(s == "finish") {
        finish_ticket();
    } else if(s == "delete") {
        delete_ticket();
    }
}

void Keetos::new_ticket(string start_date, string project_name) {
    if(start_date != "" && project_name != "") {
        cout << "Project: " << endl;
        cin >> project_name;
        cout << "Start date: " << endl;
        cin >> start_date;
    }
    inst_ticket(start_date, project_name);
}

void Keetos::inst_ticket(string start_date, string project_name) {
    Ticket a_new_one;
    a_new_one.create_ticket(start_date, project_name);
    k_tickets_vec.push_back(a_new_one);
}

void Keetos::delete_ticket(string project_name, string title) {
    int i = 0;

    auto elem_to_remove = k_tickets_vec.begin();
    for(auto p : k_tickets_vec) {
        if(p.get_proj_name() == project_name || p.get_title() == title) {
                k_tickets_vec.erase(elem_to_remove + i); i+=1;
        }
    }
    // TO-DO reserialize updated vector and save to disk
}

void Keetos::finish_ticket(string project_name, string title) {
    for(auto p : k_tickets_vec) {
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
    for(auto p : k_tickets_vec) {
        if(p.get_proj_name() == proj) {
            p.display_info();
        }
    }
}

void Keetos::find_title() {
    string title;
    cout << "Title? ";
    cin >> title;
    for(auto p : k_tickets_vec) {
        if(p.get_title() == title) {
            p.display_info();
        }
    }
}

void Keetos::to_dos() {
    for(auto p : k_tickets_vec) {
        if(p.get_checked()) {
            p.display_info();
        }
    }
}

string Keetos::get_cmd() {
    return k_cmd;
}
