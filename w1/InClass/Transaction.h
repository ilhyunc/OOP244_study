
struct Transaction
{
	int acct; //  account numberr
	char type; //  credit 'c', debit 'b' 
	double amount;  // amount of money
};

void enter(Transaction* tr);
void display(const Transaction* tr);

// compact declaration solution
void add(double*, const Transaction*);
