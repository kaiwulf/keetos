#ifndef __KEETOS_
#define __KEETOS_

// KEEp Track Of Stuff (KEETOS)

#include <string>
#include <vector>

using namespace std;

class Keetos {
    public:
        keetos();
        void new_ticket(string start_date, string project);
        void find_project();
        void find_title();
        void run(string s);
        void to_dos();
        string get_cmd();
    private:
        void inst_ticket(string start_date, string project_name)
        string s_cmd;
        vector<Ticket> s_tickets_vec;
        // Tickets *s_ticket;
}

#endif