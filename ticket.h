#ifndef __TICKETm
#define __TICKETm

#include <string>
#include <vector>

using namespace std;

class Ticket {
    public:
        void create_ticket(string start_date, string project_name);
        // getters
        string get_proj_name();
        string get_title();
        bool get_checked();
        string get_assigned();
        string get_start_date();
        string get_end_date();
        string get_body();

        void to_dos();
        void display_info();

        //setters
        void set_checked(bool checked);

        Ticket();

    private:
        bool t_checked;
        string t_body;
        string t_assigned;
        string t_end_date;
        string t_start_date;
        string t_title;
        string t_project_name;
};

#endif