#include <sstream>
class Customer {
    string c_f_name;
    string c_l_name;
    string c_addr;
    string c_phone;
    vector <Animal *> c_pet_list;
    public: 
    Customer(string f_name, string l_name, string addr, string phone, 
             vector <Animal *> pet_list) {
        c_fname = f_name;
        c_l_name = l_name;
        c_addr = addr;
        c_phone = phone;
    }
    string getCustomerName() {
        int i;
        ostringstring c_details << c_fname << " " << c_lname << endl << c_addr << endl
           << c_phone;
        for (i=0;i<pet_list.size();i++)  {
            c_details << pet_list[i].getName() << " " << pet_list[i].getBreed();
        } 
        return(c_details);
    }

       

};
