#include <iostream>
#include <string>
using namespace std;

// Create BankAccount class, constructor, and private/public Variables
class BankAccount
{
private:

	string accountHolderName;
	double accountNumber;
	double balance = 0;


public:

	//required public functions
	void deposit(double amount)
	{
		balance = balance + amount;
		cout << "Good on ya, new balance is: $" << balance << "\n";
	}

	void withdraw(double amount)
	{
		//error catcher, denies request if it is greater than balance 
		while (amount > balance)
		{
			cout << "Look here brokey, lets enter a realistic amount that won't put you under: ";
			cin >> amount;
			amount = amount;
		}
		
		balance = balance - amount;
		cout << "Bye bye Money, new balance is: $" << balance << "\n";
	}

	void getBalance()
	{
		cout << "Lookin spiffy, Current balance: $" << balance << "\n";
	}
	

	//Constructor, (forces first time users to enter name and balance)
	BankAccount(string x, double y)
	{
		cout << "[ WELCOME TO THE BACK ALLEY BANK! ]\n";
		cout << "Make an account with us or you shall be tarnished, whats ya name? ";
		cin >> x;
		accountHolderName = x;

		cout << "\nHmm... quite the name " << x << "!\n";
		cout << "Now deposit ya money: ";

		//Error catcher while loop ensures a numerical value is entered
		while (!(cin >> y))
		{
			cout << "Woah buddy thats not a number! try again: ";
			cin.clear();
			cin.ignore(123,'\n');
		}
		balance = y;

		cout << "SUCCESS!, welcome aboard my friend, greatness awaits you, off you go now! <-.->/ \n";
	};
};
	


int main()
{
	// Temporary variables set for class to run
	string tempstr;
	int tempint = 0;
	int inputAmount;

	BankAccount test(tempstr, tempint);

	int input = 0;

	//while loop allows menu to keep running until exit input 4 is selected.
	while (input != 4)
	{
		
		cout << "\n[...Back again? what can I help ya with pal?]\n";
		cout << "1. (I got the bag) Deposit Money\n";
		cout << "2. (I'm broke)  Withdraw Money \n";
		cout << "3. (How's it lookin?) Check Balance\n";
		cout << "4. Exit\n";
		cout << "\nChoose your answer: ";
		cin >> input;

		//if statement to determine input and course of action selected
		if (input == 1)
		{
			cout << "How much r ya depositing? ";
			cin >> inputAmount;
			
			// Error Catcher if number is less or equal to 0
			while (inputAmount <= 0)
			{
				cout << "\nYou bumbling idiot! answer properly with a value above 0: ";
				cin >> inputAmount;
			};

			test.deposit(inputAmount);
		}
		else if (input == 2)
		{
			cout << "RAHH, going through tough times huh? How much you taking out? ";
			cin >> inputAmount;
			test.withdraw(inputAmount);

		}
		else if (input == 3)
		{
			test.getBalance();
		}
		else;
		
	}

	//Exit message
	cout << "\nHope ya come back in one piece my friend, GODSPEED! <-_->/ \n";
	return 0;

	
}


