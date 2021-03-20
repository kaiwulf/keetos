#ifndef __KEETOS_
#define __KEETOS_

// KEEp Track Of Stuff (KEETOS)

#include <string>
#include <vector>

#include "ticket.h"

using namespace std;

class Keetos {
    public:
        Keetos();
        void new_ticket(string start_date, string project);
        void find_project();
        void find_title();
        void finish_ticket(string project_name, string title);
        void delete_ticket(string project_name, string title);
        void run(string s);
        void to_dos();
        void xml_serialize_read();
        void xml_serialize_write();
        string get_cmd();
    private:
        void inst_ticket(string start_date, string project_name);
        string s_cmd;
        string s_keetos_file;
        vector<Ticket> s_tickets_vec;

        // for XML parsing
        string s_header = "<?xml version="1.0" encoding="UTF-8"?>";
        string s_checked = "checked";
        string s_body = "body";
        string s_assign = "assign";
        string s_start = "start date";
        string s_end = "end date";
        string s_title = "title";
        string s_project = "project name";
        string s_body = "body";
        string s_assigned = "assigned";
        vector<string> s_xml_vec;
};

#endif