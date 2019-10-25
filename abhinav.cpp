#include<iostream>
#include<queue>
#include<algorithm>
#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<fstream>
#include<windows.h>
#include<ctime>
# define fine 200

using namespace std;

vector<string> library_books_;
vector<string > rg_mem;
vector<pair<string  , int> > ar;
class bank
{
	int balance;
	public:
		bank()
		{
			this->balance = 20000;
		}
		void getdetails(int fines)
		{
			//ccolor(26);
			cout<<"\nENTER THE BANK ACCOUNT NUMBER AND PIN";
			string acc,pin;
			cin>>acc>>pin;
			cout<<"\nAVAILABLE BANK BALANCE ="<<this->balance;
			balance = balance - fines;
			 cout<<"\nBANK BALANCE AFTER PAYING FINE = "<<balance<<endl;
		}
};


int find_month(string st)
{
	ar.push_back(make_pair( "Jan",1));
	ar.push_back(make_pair("Feb",2));
	ar.push_back( make_pair("Mar",3));
	ar.push_back( make_pair("Apr",4));
	ar.push_back( make_pair("May",5));
	ar.push_back( make_pair("Jun",6));
	ar.push_back( make_pair("Jul",7));
	ar.push_back( make_pair("Aug",8));
	ar.push_back( make_pair("Sep",9));
	ar.push_back( make_pair("Oct",10));
	ar.push_back( make_pair("Nov",11));
	ar.push_back( make_pair("Dec",12));
vector < pair<string,int > >::iterator it;
for(int i=0;i<ar.size();i++)
{
	if(ar[i].first == st)
	 return ar[i].second;
}
return 1;
}
int rdn(int d, int m, int y) { 
    if (m < 3)
        y--, m += 12;
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}
void return_borrow()
{ int fines;   
 time_t now = time(0);
   char* dt = ctime(&now);
 string sting(dt);
   stringstream ss(sting);
   string day;
   string  month ;
   int day_in_no;
   string time;
   int yr;
   ss >>  day >> month >> day_in_no >> time>> yr;
  int dd,mm,yy;
  yy=yr;
  dd=day_in_no ;
	mm=find_month(month );
	cout<<"\n\nenter the date - dd,mm,yy";
	int dd_,mm_,yy_;
	cin>>dd_>>mm_>>yy_;
	int difference = rdn(dd_,mm_,yy_) - rdn(dd,mm,yy);
	cout<<"\nthe difference = "<<difference;
	if(difference > 15)
	{
	    int xxx=difference-15;
	   fines = (xxx)*(xxx+1)/2; 
	}
	else fines = 0;
	cout<<"\n\nYOU NEED TO PAY THE FINE OF RUPEES "<<fines;
	bank obj ;

	obj.getdetails(fines);
}
class registration
{
	public:
	int age;
	string name , email;
	char* current_time_date;
};
class add_as_member
{
	public:
	int age;
	string name , email;
	char* current_time_date;
};



void cls(){
	system("cls");
}
void register_to_lib()
{
	cls();
	cout<<"\nENTER YOUR NAME , AGE AND EMAIL-ID TO REGISTER TO LIBRARY !";
	int ages;
	// current date/time based on current system
   time_t now = time(0);
   // convert now to string form
   char* dt = ctime(&now);
	string names , mail;
	cin>>names>>ages>>mail;
	
  fstream myfile;			//WRITING INTO A FILE USING OFSTREAM OBJECT
  myfile.open ("registered_members_in_library.txt",ios::app);
  myfile << names << " " << ages <<" " << mail<<" "<<dt<<"\n";
  myfile.close();
  		cout<<"\n\n\n\n\t\t\t\tYOU\n";
		cout<<"\t\t\t\tHAVE\n";
			cout<<"\t\t\t\tREGISTERED\n";
				cout<<"\t\t\t\tSUCCESSFULLY\n";
		
}
void add_member()
{
	cls();
	cout<<"\nENTER YOUR NAME , AGE AND EMAIL-ID TO BECOME A MEMBER TO LIBRARY !";
	int ages;
	string names , mail;
	cin>>names>>ages>>mail;
   time_t now = time(0);
   char* dt = ctime(&now);
   fstream myfile;			//WRITING INTO A FILE USING OFSTREAM OBJECT
  myfile.open ("members_in_library.txt",ios::app);
  myfile << names << " " << ages <<" " << mail<<" "<<dt<<"\n";
  myfile.close();  
cls();
	cout<<"\n\n\n\n\t\t\t\tYOU\n";	cout<<"\t\t\t\tHAVE\n";	cout<<"\t\t\tBEEN ADDED AS A MEMEBER\n";	cout<<"\t\t\t\tSUCCESSFULLY\n";
}
void remove_member()
{
	cls();
	cout<<"\nENTER YOUR NAME , AGE AND EMAIL-ID,time and date of registration TO GIVE UP AS A MEMBER TO LIBRARY !";
		int ages;
	string names , mail;
	char* dt;
	cin>>names>>ages>>mail>>dt;

	cls();
	cout<<"\n\n\n\n\t\t\t\tYOU\n";
		cout<<"\t\t\t\tHAVE\n";
			cout<<"\t\t\t\tdeleted\n";
				cout<<"\t\t\t\tSUCCESSFULLY\n";
	
}


class avl
{
        public:
                int data,h;
                avl* left;
                avl* right;
                string author;
                string isbn;
                avl* rightrotate(avl* node)
                {
                        avl* temp=node->left;
                        node->left=temp->right;
                        temp->right=node;
                        node->h=max(height(node->left),height(node->right))+1;
                        temp->h=max(height(temp->left),height(temp->right))+1;
                        return temp;
                }
                avl* leftrotate(avl* node)
                {
                        avl* temp=node->right;
                        node->right=temp->left;
                        temp->left=node;
                        node->h=max(height(node->left),height(node->right))+1;
                        temp->h=max(height(temp->left),height(temp->right))+1;
                        return temp;
                }
                int max(int a,int b)
                {
                        if(a>=b)
                                return a;
                        else
                                return b;
                }
                int height(avl* node)
                {
                        if(node==NULL)
                                return -1;
                        else
                                return node->h;
                }
                int getbalance(avl* node)
                {
                    if(node==NULL)
                        return 0;
                    return (height(node->left)-height(node->right));
                }
                avl* minvalue(avl* node)
                {
                    avl* current=node;
                    while(current->left!=NULL)
                        current=current->left;
                    return current;
                }
                avl* deletion(avl* node, int x)
                {
                    if(node==NULL)
                        return node;
                    if(x<node->data)
                        node->left=deletion(node->left,x);
                    else if(x>node->data)
                        node->right=deletion(node->right,x);
                    else
                    {
                        if(node->left==NULL || node->right==NULL)
                        {
                            avl* temp=node->left?node->left:node->right;
                            if(temp==NULL)
                            {
                                temp=node;
                                node=NULL;
                            }
                            else
                            {
                                *node=*temp;
                                free(temp);
                            }
                        }
                        else
                        {
                            avl* temp=minvalue(node->right);
                            node->data=temp->data;
                            node->right=deletion(node->right,temp->data);
                        }
                    }
                    if(node==NULL)
                        return node;
                    node->h=max(height(node->left),height(node->right))+1;
                    int bal=getbalance(node);
                    if(bal>1 && getbalance(node->left)>=0)
                        return rightrotate(node);
                    if(bal>1 && getbalance(node->left)<0)
                    {
                        node->left=leftrotate(node->left);
                        return rightrotate(node);
                    }
                    if(bal<-1 && getbalance(node->right)<=0)
                        return leftrotate(node);
                    if(bal<-1 && getbalance(node->right)>0)
                    {
                        node->right=rightrotate(node->right);
                        return leftrotate(node);
                    }
                    return node;
                }
                avl* insert(avl* node,int x,string author ,string isbn)
                {
                        if(node==NULL)
                        {
                                node=new avl();
                                node->data=x;
                                node->left=NULL;
                                node->right=NULL;
                                node->h=0;
                                node->author = author;
                                node->isbn = isbn;
                                return node;
                        }
                        if(author<node->author)
                                node->left=insert(node->left,x,author , isbn);
                        else
                                node->right=insert(node->right,x, author , isbn);

                        node->h=max(height(node->left),height(node->right))+1;
                        int bal;
                        bal=height(node->left)-height(node->right);
                        if(bal>1 && author<node->author)
                                return rightrotate(node);
                        else if(bal>1 && author>node->author)
                        {
                                node->left=leftrotate(node->left);
                                return rightrotate(node);
                        }
                        else if(bal<-1 && author>node->author)
                                return leftrotate(node);
                        else if(bal<-1 && author<node->author)
                        {
                                node->right=rightrotate(node->right);
                                return leftrotate(node);
                        }


                        return node;
                }
                void inorder(avl* node)
                {
                        if(node!=NULL)
                        {
                                inorder(node->left);
                                cout<<node->data<<" "<<node->author<<" "<<node->isbn<<"\n\n";
                                inorder(node->right);
                        }
                }
               
               
};

void take_a_book(avl*);
///extra design Function
void cls();
void ccolor(int clr);
void pwellcome();
void loadingbar();

void ccolor(int clr){

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, clr);

}


void print_registered()
{
	fstream file;
		file.open("registered_members_in_library.txt");
		file.seekg(0);
			string dis;
			dis.clear();
		cout<<"\ndisplaying : \n\n\n";
		while(getline(file,dis))
		{
			cout<<dis<<" \n";
		}

file.close();
}
void print_added_as_member()
{
	fstream file;
		file.open("members_in_library.txt");
		file.seekg(0);
			string dis,copy;
			dis.clear();
		cout<<"\ndisplaying : \n\n\n";
		while(getline(file,dis))
		{
			stringstream ajai(dis);
			ajai>>copy;
			rg_mem.push_back(copy); 
			cout<<dis<<" \n";
			ajai.clear();
			dis.clear();
		}

file.close();
}
bool avlsearch(avl* root,string autho)
{
	if(root==NULL ) return false;
	if(root->author ==autho) return true;
	else if(autho > root->author)
	{
		return avlsearch(root->right,autho);
	}
	else if(autho < root->author)
	{
		return avlsearch(root->left,autho);
	}
	 else return false;
}
void search(avl* root)
{
	cls();
	cout<<"\nENTER THE BOOK NAME TO SEARCH!";
	string name_of;
	cin>>name_of;
	bool answer = avlsearch(root,name_of);
/*	if(find(library_books_.begin(),library_books_.end(),name_of) !=library_books_.end())
	cout<<"\n\nTHE SEARCHED BOOK IS FOUND !";
	else
	{
		cout<<"\nTHE SEARCHED BOOK IS  NOT FOUND !";
	}
*/
if(answer)
{
	cout<<"\n\nTHE SEARCHED BOOK IS FOUND !";
}
	else
	{
		cout<<"\nTHE SEARCHED BOOK IS  NOT FOUND !";
	}
 } 
int main()
{
	avl* root=NULL;
    int ch,n,d;
	fstream stream;
	stream.open("library_books.txt");
	char chars;
int x;
string sample1,sample2;
std::string str;	
  while (std::getline(stream, str)) {
    stringstream ss(str);
    ss>>x;
    ss>>sample1;
    library_books_.push_back(sample1);
    ss>>sample2;
    root=root->insert(root,x,sample1,sample2);
    str.clear();
    sample1.clear();
    sample2.clear();
    stream.clear();
}
stream.close();
	ccolor(230);
	main_menu : 
	cout<<"\n\n\n\n\n\n================================LIBRARY MANAGEMENT SYSTEM===========================================================\n\n\n";
	cout<<"\t\t\t\t\t\t1.REGISTER-TO-ENTER-INTO-LIBRARY\n";
	cout<<"\t\t\t\t\t\t2.ADD AS A MEMBER\n";
	cout<<"\t\t\t\t\t\t3.MAIN MENU\n";
	cout<<"\t\t\t\t\t\t4.EXIT\n";
	cout<<"\t\t\t\t\t\t5.SEARCH A BOOK IN LIBRARY . ENTER THE BOOK NAME !\n";
	cout<<"\t\t\t\t\t\t6.TAKE A BOOK FROM LIBRARY\n";
	cout<<"\t\t\t\t\t\t7.RETURN THE BORROWED BOOK FROM LIBRARY \n";
	cout<<"\t\t\t\t\t\t8.AVAILABLE BOOKS IN LIBRARY !\n";
	cout<<"\t\t\t\t\t\t9.LIST OF REGISTERED MEMBERS !\n";
	cout<<"\t\t\t\t\t\t10.LIST OF MEMBERS OF THE LIBRARY !\n";
	
	cout<<"\n\nENTER THE OPTION !\n";
	
		string dis;
		while(1)
	{
	int x,flag=0;
	cin>>x;
	switch(x)
	{
		case 1 : register_to_lib();
				
					break;
		case 2 : add_member();break;
		case 4 : exit(0);break;
		case 5 : search(root);break;
		case 6 : take_a_book(root);break;
		case 7 : return_borrow();break;
		case 8 : 
				cls();
				
				root->inorder(root);break;
	
	
		case 9: 
		cls();
		print_registered();
		 break;
		 
		case 10: 
		cls();
		print_added_as_member();
		break;
	
	
		case 3 : 
		flag=1;goto main_menu;break;
		
	}
	
	if(flag!=1)
	{
	
	cout<<"\n\n\nBACK TO MAIN MENU : PRESS 1";
	int press;
	cin>>press;
	cls();
	if(press)  goto main_menu;
}
}
        return 0;
}


void take_a_book(avl* root)
{
cls();
cout<<"\nENTER YOUR NAME";
string aj,puthagam;
cin>>aj;


if(find(rg_mem.begin(),rg_mem.end(),aj)!=rg_mem.end())	
{
	cout<<"\nPERMISSION GRANTED SINCE YOU ARE A MEMBER!";
	search(root);
}
else
{
	cout<<"\nYOU ARE NOT A MEMBER OF THE LIBRARY !";
}

}


