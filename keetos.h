#ifndef __KEETOk_
#define __KEETOk_

// KEEp Track Of Stuff (KEETOS)

#include <string>
#include <vector>
#include <utility>
#include <fstream>

#include "ticket.h"

using namespace std;

class Keetos {
    public:
        Keetos();
        Keetos(bool);
        ~Keetos();

        void new_ticket(string start_date = "", string project = "");
        void find_project();
        void find_title();
        void finish_ticket(string project_name = "", string title = "");
        void delete_ticket(string project_name = "", string title = "");
        void run(string s);
        void to_dos();
        string get_cmd();
    private:
        // private functions
        void inst_ticket(string start_date, string project_name);
        void init_serialize();
        void push_vec_elems();
        void xml_serialize_read();
        void xml_serialize_write();
        string xmlize_line(string bracketed, string center);
        pair<string, string> parse_xml_line(string xml);

        // private inline functions
        inline string bool_to_str(bool b) { string str = b == 0 ? "0" : "1"; return str; }
        inline bool str_to_bool(string s) { bool b00 = s == "0" ? 0 : 1; return b00; }

        // working variables
        string k_break;
        string k_cmd;
        string k_keetos_file;
        string k_str_break;
        vector<Ticket> k_tickets_vec;
        ofstream xml_out;
        ifstream xml_in;

        // for XML parsing
        string k_header;
        string k_checked;
        string k_start;
        string k_end;
        string k_title;
        string k_project;
        string k_body;
        bool k_read;
        vector<string> k_xml_vec;
        vector<string> k_vec_xml_tags;
};

#endif