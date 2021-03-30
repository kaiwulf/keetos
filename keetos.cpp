#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>

#include "keetos.h"

using namespace std;

// TO-DO serialize vector to save on disk

Keetos::Keetos() {

}

Keetos::Keetos(bool read) {
    k_keetos_file = "keetos.bin";
    k_read = read;
    
    if(k_read) xml_serialize_read();
}

Keetos::~Keetos() {
    init_serialize();
    xml_serialize_write();
}

void Keetos::init_serialize() {
        k_header = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
        k_checked = "checked";
        k_body = "body";
        k_start = "start_date";
        k_end = "end_date";
        k_title = "title";
        k_project = "project_name";
        k_body = "body";

        push_vec_elems();
}

pair<string, string> Keetos::parse_xml_line(string xml) {
    // string xml = "<this>is a xml</this>";
    string delimiters = "";
    string center = "";
    pair<string, string> xml_pair;
    int i = 0;

    while(i < xml.length()) {
        if(xml[i] == '<') {
            i+=1;
            char s = xml[i];
            while(s != '>') {
                delimiters.push_back(s);
                i+=1;
                s = xml[i];
            }
        }
        if(xml [i] == '>') {
            i+=1;
            char s = xml[i];
            while(s != '<') {
                center.push_back(s);
                i+=1;
                s = xml[i];
                if(xml[i] == '<')
                    goto end;
            }
        }
        i+=1;
        end: break;
    }

    xml_pair.first = delimiters;
    xml_pair.second = center;

    return xml_pair;
}

void Keetos::xml_serialize_read() {
    fstream xml_in;
    string xml_line;
    map<string, string> that;
    cout << "opening file" << endl;
    xml_in.open(k_keetos_file, ios::in);
    pair<string, string> parse;


    while(std::getline(xml_in, xml_line)) {
        if(xml_line[1] == '?') continue;
        parse = parse_xml_line(xml_line);
        that.insert(parse_xml_line(xml_line));
    }

    
    Ticket ticket();
    ticket.set_checked(that["checked"]);
    ticket.set_end_date(that["end_date"]);
    ticket.set_proj_name(that["project_name"]);
    ticket.set_start_date(that["start_date"]);
    ticket.set_title(that["title"]);
    k_tickets_vec.push_back(ticket);
    

    string xml_serialized = "";
    for(auto p: that) {
        xml_serialized += (xmlize_line(p.first, p.second) + '\n');
    }
    cout << "XML serialized" << xml_serialized << endl;
}

void Keetos::push_vec_elems() {
    k_xml_vec.push_back(k_header);
    k_xml_vec.push_back(k_checked);
    k_xml_vec.push_back(k_body);
    k_xml_vec.push_back(k_start);
    k_xml_vec.push_back(k_end);
    k_xml_vec.push_back(k_title);
    k_xml_vec.push_back(k_project);
}

string Keetos::xmlize_line(string bracketed, string center){
    string xml = "<" + bracketed + ">" + center + "</" + bracketed + ">";
    return xml;
}

void Keetos::xml_serialize_write() {
    fstream xml_out;
    xml_out.open(k_keetos_file, ios::out);
    xml_out << k_header << endl;
    for(auto p : k_tickets_vec) {
        xml_out << xmlize_line(k_title, p.get_title()) << endl;
        string x= p.get_checked() == 0 ? "0" : "1";
        xml_out << xmlize_line(k_checked, x) << endl;
        xml_out << xmlize_line(k_start, p.get_start_date()) << endl;
        xml_out << xmlize_line(k_end, p.get_end_date()) << endl;
        xml_out << xmlize_line(k_project, p.get_proj_name()) << endl;
        xml_out << xmlize_line(k_body, p.get_body()) << endl;
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
    if(start_date == "" && project_name == "") {
        cout << "Project: " << endl;
        getline(cin, project_name);
        cout << "Start date: " << endl;
        getline(cin, start_date);
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
