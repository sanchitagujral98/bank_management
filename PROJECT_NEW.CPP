
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int max (int a, int b)
{
   if (a>b) return(a) ; else return (b);
}

int min (int a, int b)
{
   if (a>b) return(b); else return (a);
}

class Date
{
 public:
    Date ();
    Date ( int mn, int day, int yr);  // constructor
    void display();                   // function to display date
    int GetMonth();
    void SetMonth(int mn);
    void set(int mn, int dy, int yr);

 private:
    int month, day, year;
    int DaysSoFar();
};

// constructor definition
 Date::Date ()
{
   month = day =1;
   year = 1980;
}

Date::Date (int mn, int dy, int yr)
{
   int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   month = max(1, mn);
   month = min(month,12);

   day = max(1,dy);
   day = min(day, length[month]);

   year = max(1, yr);
}
void Date::set(int mn, int dy, int yr)
{
   static int length[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   month = max(1, mn);
   month = min(month,12);

   day = max(1,dy);
   day = min(day, length[month]);

   year = max(1, yr);

}

void Date::display()
{
   static char *name[] = {"nothing", "January", "February", "March", "April",
	    "May", "June", "July", "August", "September", "October",
	    "November", "December" };
   cout<<"\n" << name[month] << " " << day << "," << year << '\n';
}

int Date::DaysSoFar()
{
   int total = 0;
   int length[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   for (int i=1; i < month; i++) total += length[i];
   total += day;
   return (total);
}

int Date::GetMonth()
{
   return month;
}

void Date::SetMonth(int mn)
{
   month = max(1, mn);
   month = min(month, 12);
  }
class Loan_mst     //types of loan offered by bank
{
	private:
		char loan_id[10],loan_desc[50],elgblty_cond[50],active;
		long min_amount,max_amount;

	public:
		Loan_mst()
		{
		active =' ';
		min_amount = 0;
		max_amount =0;
		}

		void getdata();
		int get_min_amount()
		{
		return min_amount;
		}
		int get_max_amount()
		{
		return max_amount;
		}
		void putdata()
		{
			cout<<"displaying types of loans\n";
			cout<<"_________________________\n";
			cout<<"Loan Id: "<<loan_id<<"\t\t";
			cout<<"Loan Description: "<<loan_desc<<"\n\n";
			cout<<"Eligibility Rules:"<<elgblty_cond<<"\t\t";
			cout<<"Minimum Amount: "<<min_amount<<"\n\n";
			cout<<"Maximum Amount: "<<max_amount<<"\t\t";
			cout<<"Active: "<<active<<"\n\n";
		}
		void write_file()
		{
			ofstream mf("Loan_mst.dat",ios::binary|ios::app);
			if(!mf)
			{
				cout<<"Stream not created";
				getch();																																																																																						;
				return;
			}
			mf.write((char *)this,sizeof(Loan_mst));
			mf.close();
		}
		void read_file(char * lid);
		void read_file();
};
		void Loan_mst::getdata()
		{
			cout<<"Create new loan type\n";
			cout<<"_____________________\n";
			cout<<"Enter new Loan id:";
			cin>>loan_id;
			cout<<"Enter loan description:\n";
			gets(loan_desc);
			cout<<"Enter Eligibility Rules:\n";
			gets(elgblty_cond);
			while(1)
			{
			cout<<"Enter Minimum Amount:";
			cin>>min_amount;
			if(min_amount>0 && min_amount<100000)
			break;
			cout<<"Minimum Amount should be > 0 and < 100000" ;
			}

			while(1)
			{
			cout<<"Enter Maximum Amount:";
			cin >>max_amount;
			if (max_amount >= min_amount)
				break;
			cout<<"Maximum Amount should be > Minimum Amount";
			}
			active ='Y';
		}
		void Loan_mst::read_file(char * lid)
		{
			ifstream mf("Loan_mst.dat", ios::binary|ios::in);
			if(!mf)
			{
				cout<<"Stream not created";
				getch();
				return;
			}

			mf.read((char *)this,sizeof(Loan_mst));
			while(mf)
			{
				if(strcpy(lid,loan_id)==0)
					return;
				mf.read((char *)this,sizeof(Loan_mst));

			}
			getch();
			mf.close();
		}

		void Loan_mst::read_file()
		{

			int sno =0;
			ifstream mf("Loan_mst.dat", ios::binary|ios::in);
			if(!mf)
			{
				cout<<"Stream not created";
				getch();
				return;
			}
			cout<<"Types of Loans Offered\n";
			cout<<"______________________\n";
			cout << "\nSno   Loan Id  Description   Minimum Amt  Maximum Amt"<<"\n";
			mf.read((char *)this,sizeof(Loan_mst));
			while(mf)
			{

				sno++;
				cout<<sno<<"\t"<<loan_id<<"\t"<<loan_desc<<"\t"<<min_amount<<"\t"<<max_amount<<"\n";
				mf.read((char *)this,sizeof(Loan_mst));
				//putdata();
			}
			getch();
			mf.close();
		}              // end of Loan_mst class
class Customer   //customers of the bank
{

	private:
		char cust_id[10],name[20],joint_name[20],addr[50], contact[12];
		long monthlyincome,annualincome;
	public:


		void getdata()
		{
			clrscr();
			char vcust_id[10];
			cout<<"\nNew customer account\n";
			cout<<"____________________\n";
			cout<<"\n Enter customer id:\n";
			gets(vcust_id);
			if (get_customer(vcust_id)==1)
			{
				cout<<"\n Customer id already exists\n";
				getch();
				return;
			}

			strcpy(cust_id,vcust_id);
			cout<<"\n Enter name:";
			gets(name);
			cout<<"\n Enter the name of joint account:";
			gets(joint_name);
			cout<<"\n Enter monthly income:";
			cin>>monthlyincome;
			cout<<"\n Enter the annual income:";
			cin>>annualincome;
			cout<<"\n Enter contact number:";
			cin>>contact;
			cout<<"\n Enter address:";
			gets(addr);

		}
		void putdata()
		{
			cout<<"\nDetails of the customer\n";
			cout<<"_______________________\n";
			cout<<"Customer id- "<<cust_id<<"\t\t";
			cout<<"Name - "<<name<<"\n\n";
			cout<<"Name of joint account -"<<joint_name<<"\n\n";
			cout<<"Monthly income - "<<monthlyincome<<"\t\t";
			cout<<"Annual income - "<<annualincome<<"\n\n";
			cout<<"Contact number - "<<contact<<"\n\n";
			cout<<"Postal address - "<<addr<<"\n\n";
			getch();
		}
		void write_file();
		void read_file();
		int get_customer(char c[]);
};
		void Customer::write_file()
		{
			ofstream mf;
			mf.open("Customer.dat",ios::binary|ios::app);
			if(!mf)
			{
				cout<<"Stream not created";
				getch();
				exit(0);

			}
			mf.write((char *)this,sizeof(Customer));
			mf.close();
		}
		void Customer::read_file()
		{
			ifstream mf;
			mf.open("Customer.dat",ios::binary|ios::in);
			if(!mf)
			{
				cout<<"Stream not created";
				return;

			}
			cout<<"\nCustomers Of the Bank\n";
			cout<<"_______________________\n";
			mf.read((char *)this ,sizeof(Customer));
			while(mf)
			{
				cout<<cust_id<<'\t'<<name <<'\n';
				mf.read((char *)this ,sizeof(Customer));
			}
			mf.close();
		}
		int Customer::get_customer(char *vcust_id)
		{
			int sno =0;
			ifstream mf("Customer.dat",ios::binary);
			if(!mf)
			{
				cout<<"stream not created";
				getch();
				return 0;

			}
			while(mf)
			{
				sno++;
				mf.read((char *)this,sizeof(Customer));
				if(strcmp(cust_id, vcust_id)==0)
				{
					putdata();
					mf.close();
					return 1;
				}

			}
			       cout<<"Customer id not found"<<'\n';
			       mf.close();
			       return 0 ;


			}

class LoanAccount
{

private:
	char acc_no[10];
	char cust_id[10];
	char loan_id[10];
	long loan_amount;
	int no_of_emi;
	Date start_dt;
	Date emi_pymnt_strt;
	double balance;
	float intrst;
	double emi;
public:
	void getdata();
	void get_LoanAccount_info(char vacc_no[10])
	{
		LoanAccount tla;
		if(tla.get_loanaccount(vacc_no))
			tla.putdata();

	}

	void putdata()
	{
	  Customer cust;
		clrscr();
		cout<<"Loan Account Information\n";
		cout<<"________________________\n";
		cout<< "Loan Account No :"<< acc_no<<'\n';
		cout<< "Customer ID :"<<cust_id<<"\t\t";
		cout<<"Loan Id: "<< loan_id<<'\n';
		cust.get_customer(cust_id);
		cout<< '\n'<<"Loan Amount :"<<loan_amount<<"     ";
		cout<<"No of EMI :"<<no_of_emi<<'\n';
		cout <<"Interst Rate:"<< intrst<<'\n';
		cout <<"Start Date:";

		start_dt.display();
		cout<< "Balance:"<<ceil(balance)<<'\n';
		cout <<"EMI:"<<ceil(emi)<<'\n';
		getch();
	}
		void write_file()
		{
			ofstream mf("Loan_Acc.dat",ios::binary|ios::app);
			if(!mf)
			{
				cout<<"stream not created";
				getch();
				return;

			}
			mf.write((char *)this,sizeof(LoanAccount));
			mf.close();
		}
		void read_file();
		int  get_loanaccount(char vacc_no[10]);
		int  update_loanaccount(char vacc_no[10],int pymnt_amt);
		void delete_data(char *vacc_no);

};
	void LoanAccount::delete_data(char *vacc_no)
	{
	ifstream oldfile;
	oldfile.open("Loan_Acc.dat",ios::binary|ios::in);
	if(!oldfile)
	{
	cout<<"file not created";
	getch();
	return;
	}
	ofstream newfile;
	newfile.open("Loan_AXX.dat",ios::binary|ios::out);
	int num;
	int flag=0;
	cout <<"Acc no:"<<vacc_no;
	oldfile.read((char*)this,sizeof(LoanAccount));
	while(oldfile)
	{       cout<<"this acc_no"<<acc_no<<'\t'<<strcmp(acc_no,vacc_no)<<'\n';
		if(strcmp(acc_no,vacc_no)!=0)
			newfile.write((char*)this,sizeof(LoanAccount));
		else
		 flag=1;
		oldfile.read((char*)this,sizeof(LoanAccount));
	}
	oldfile.close();
	newfile.close();
	remove("Loan_Acc.dat");
	rename("Loan_AXX.dat","Loan_Acc.dat");
	if(flag==1)
	cout<<"record deleted"<<'\n';
	else
	cout<<"record not found"<<'\n';
}

		int  LoanAccount::update_loanaccount(char vacc_no[10],int pymnt_amt)
		{
			int sno =0; int interest ;
			fstream mf("Loan_Acc.dat",ios::binary|ios::in|ios::out);
			if(!mf)
			{
				cout<<"Stream not created";
				return 0;

			}
			mf.read((char *)this,sizeof(LoanAccount));
			while(mf)
			{
				sno++;


				if(strcmp(acc_no, vacc_no)==0)
				{       cout<<"\n Before Payment\n";
					putdata();

					balance -=(pymnt_amt-emi);
					cout<<"\n After APyment\n";
					putdata();
					mf.seekp(mf.tellg()-sizeof(LoanAccount),ios::beg);
					mf.write((char*)this,sizeof(LoanAccount));
					getch();
					return 1;
				}
			mf.read((char *)this,sizeof(LoanAccount));
			}
			if(mf)
			{
			       cout<<"Loan Account no not found"<<'\n';
			       getch();
			       return 0 ;
			}

				mf.close();
				getch();
				return 1;
			}
	int  LoanAccount::get_loanaccount(char vacc_no[10])
	{
		int sno =0;
		ifstream mf("Loan_Acc.dat",ios::binary);
		if(!mf)
		{
			cout<<"stream not created";
			getch();
			return 0;
		}
		mf.read((char *)this,sizeof(LoanAccount));
		while(mf)
		{
			sno++;
			//mf.read((char *)this,sizeof(LoanAccount));
			if(strcmp(acc_no, vacc_no)==0)
			{
				putdata();
			 //	getch();
				return 1;
			}
			mf.read((char *)this,sizeof(LoanAccount));
		}
		if(mf)
		{
		       cout<<"Loan Account no not found"<<'\n';
		       getch();
		       return 0 ;
		}

			mf.close();
			return 1;
	}

void LoanAccount::getdata()
	{       Loan_mst ln;
		clrscr();

		cout<<"Enter Loan Account No :";
		cin>> acc_no;
		cout<<"Enter Customer id: ";
		cin >> cust_id;
		ln.read_file();
		cout <<"Enter loan_id:" ;
		cin>>loan_id;
		ln.read_file(loan_id);
		cout <<"Enter loan amount between "<<ln.get_min_amount()<<" and "<<ln.get_max_amount()<<":";
		cin>> loan_amount;
		cout << "Enter no of EMI :" ;
		cin>> no_of_emi;
		while(1)
		{
		cout << "Enter interest percentage :";
		cin>>  intrst;
		if (intrst>0 && intrst <0.50)
			break;
		cout<<"Interst should be > 0 (0 %) and less than 0.5(50 %)\n";
		}
		cout<< "Start date(mm/dd/yy):";

		int m, d, y;
		scanf("%2d/%2d/%2d",&m,&d,&y);
		start_dt.set(m,d,y);
		start_dt.display();
		balance = loan_amount;
//		float a = pow(1+intrst,2);
  //		cout <<"a:"<<a;
		emi = (intrst*pow(1+intrst,no_of_emi))*loan_amount/ (pow(1+intrst,no_of_emi) -1);
		cout <<"EMI :"<<ceil(emi);
		getch();
	}
  void LoanAccount::read_file()
  {
	 int sno =0;
	 ifstream mf("Loan_Acc.dat",ios::binary);
	 if(!mf)
	 {
		cout<<"stream not created";
		return;
	 }
	 cout<<"\nAll Loan Account Information\n";
	 cout<<"______________________________\n";
	 mf.read((char *)this,sizeof(LoanAccount));
	 while(mf)
	 {
		sno++;
		//mf.read((char *)this,sizeof(LoanAccount));
		cout<<"Record no :"<<sno;
		putdata();
		mf.read((char *)this,sizeof(LoanAccount));
	 }
		mf.close();
  }

class PaymentInfo
{
	private:
	char acc_no[10];
	char cust_id[10];
	char pymnt_id[10];
	Date *pymnt_dt;
	int pymnt_amt;
	public:
	void read_file();
	void getdata()
	{
	int dd, mm,yy;
	clrscr();
	cout<<"Enter customer Id :";
	cin>>cust_id;
	cout <<"Enter Loan account id:";
	cin>> acc_no;
	cout<<"Enter Payment Date:";
	scanf("%2d/%2d/%4d",&dd,&mm,&yy);
	pymnt_dt= new Date(dd,mm,yy);
	pymnt_dt->display();
	cout <<"Enter Payment Amount:";
	cin >> pymnt_amt;
	}
	void display()
	{
	cout << "Customer Id:" << cust_id<<'\n';
	cout << "Loan account id:"<<acc_no<<'\n';
	cout << "Payment date:";
	pymnt_dt-> display();
	cout<< "Payment Amount:"<< pymnt_amt;
	}
	void write_file()
	{
		ofstream mf("Payment.dat",ios::app);
		if(!mf)
		{
			cout<<"Stream not created";
			return ;
		}
		mf.write((char *)this,sizeof(PaymentInfo));
		mf.close();
		LoanAccount la;
		la.update_loanaccount(acc_no,pymnt_amt);
	}

};
	 void PaymentInfo::read_file()
	 {
		int sno =0;
		ifstream mf("Payment.dat");
		if(!mf)
		{
			cout<<"stream not created";
			exit(0);
		}

		while(mf)
		{
			sno++;
			mf.read((char *)this,sizeof(PaymentInfo));
			cout<<"Record no :"<<sno;
			PaymentInfo::display();
		}
			mf.close();
	 }

void intro()
{
	clrscr();
	gotoxy(30,9);
	cout<<"LOAN MANAGEMENT";
	gotoxy(33,11);
	cout<<"SYSTEM";
	gotoxy(35,13);
	cout<<"\n\nMADE BY : SANCHITA GUJRAL";
	cout<<"\n\nSCHOOL :  ST.FRANCIS DE SALES SCHOOL";
	getch();
}

void main()
{
	clrscr();
	intro();
	clrscr();
	cout <<"\n\n\n\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	cout<<"\n\n\n\n\t\t WELCOME TO LOAN BANKING SYSTEM \t\n";
	cout <<"\n\n\n\n $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
	getch();
	int choice;
	while(1)
	{
	clrscr();
	cout << "############## Main Menu #############"<<'\n';
	cout <<"1. Create New Customer account"<<'\n';
	cout <<"2. Create a new Loan Account "<<'\n';
	cout<<"3. Create a new Loan Type "<<'\n';
	cout<<"4. Update Payments "<<'\n';
	cout<<"5. Delete Loan Account "<<'\n';
	cout<<"6. Display Customer Information"<<'\n';
	cout <<"7. Display Loan Account Information"<<'\n';
	cout<<"8. Display Loan Types"<<'\n';
	cout<<"9. Display all Customers"<<'\n';
	cout<<"10.Display all Loan Accounts"<<'\n';
	cout<<"0. Quit"<<'\n';
	cout<<" Enter choice :"<<'\n';
	cin>>choice;
	switch(choice)
	{
	case 1: Customer c;
		c.getdata();
		c.write_file();
		break;

	case 2:LoanAccount la;
		la.getdata();
		la.write_file();
		la.putdata();
		break;

	case 3: Loan_mst lm;
		lm.getdata();
		lm.write_file();
		break;

	case 4: PaymentInfo Pi;
		Pi.getdata();
		Pi.write_file();

		break;

	case 5:char vacc_no[10],vcust_id[10];
	       cout<<'\n'<<"Enter Customer id :";
	       cin>>vcust_id;
	       Customer cust1;
	       cust1.get_customer(vcust_id);
	       cout<<'\n'<<"Enter Loan Account number :";
	       cin>> vacc_no;
	       LoanAccount lac;
	       lac.delete_data(vacc_no);
	       getch();
	       break;

	case 6: clrscr();
		char vcust_no[10];
		cout<<'\n'<< "Enter Customer id :";
		cin >>vcust_no;
		Customer cust;
		cust.get_customer(vcust_no);
		getch();
		break;

	case 7: clrscr();
		char vacc_no1[10];
		cout<< '\n'<< "Enter Loan Account no :";
		cin >> vacc_no1;
		LoanAccount gla;
		gla.get_loanaccount(vacc_no1);
		getch();
		break;

	case 8:  clrscr();
		 Loan_mst lmst;
		 lmst.read_file();
		 getch();
		 break;

	case 9: clrscr();
		Customer c1;
		c.read_file();
		getch();
		break;

	case 10:clrscr();
		LoanAccount l;
		l.read_file();
		getch();
		break;

	case 0: return;
	}
	}

}

