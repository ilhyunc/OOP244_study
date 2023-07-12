#include <iostream>

class iPerson {
public:
    virtual void display(std::ostream&) const = 0;
};

iPerson* CreatePerson();