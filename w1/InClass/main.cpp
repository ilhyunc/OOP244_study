#include <iostream>

#include "main.h"
#include "Transaction.h"

using namespace std;

int main()
{
	Transaction tr;
	for (int i = 0; i < NO_TRANSACTION; i++)
	{
		enter(&tr);
		display(&tr);
	}
}