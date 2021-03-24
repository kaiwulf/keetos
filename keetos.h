#ifndef __KEETOk_
#define __KEETOk_

// KEEp Track Of Stuff (KEETOS)

#include <string>
#include <vector>

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
        void inst_ticket(string start_date, string project_name);
        void init_serialize();
        void push_vec_elems();
        void xml_serialize_read();
        void xml_serialize_write();
        string xmlize_line(string bracketed, string center);

        // working variables
        string k_cmd;
        string k_keetos_file;
        vector<Ticket> k_tickets_vec;

        // for XML parsing
        string k_header;
        string k_checked;
        string k_assigned;
        string k_start;
        string k_end;
        string k_title;
        string k_project;
        string k_body;
        vector<string> k_xml_vec;
};

#endif