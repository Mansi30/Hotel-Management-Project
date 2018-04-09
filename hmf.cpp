#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
#define FILE_NAME "hm.dat"
int adults,chld,c,ch,s;
char name[100],check_in[30],check_out[30],email[50];
unsigned long long int phn;

class detail
{
	   public:
	   int  personal();
	   int place();
	   int writefile();
	   int readfile();
	   
};
 int detail :: personal()
 {
  	  cout<<"Enter Name : ";
 	  scanf(" %[^\n]s",name);
 	  cout<<"Check In date : ";
 	  cin>>check_in;
 	  cout<<"Check Out date : ";
 	  cin>>check_out;
 	  cout<<"Phone No. : ";
 	  cin>>phn;
 	  cout<<"Email Address : ";
 	  cin>>email;
 	  cout<<"Adults : ";
 	  cin>>adults;
 	  cout<<"Children : ";
 	  cin>>chld;
 	  return 0;
 }
 int detail :: place()
 {
 	   int ch;
 	   system("cls");
 	   cout<<"Which place do you want to book ?";
 	   cout<<"1. Mumbai\n2. Goa\nEnter your choice : ";
 	   cin>>ch;
 	   
 	   switch(ch)
 	   {
 	   	   case 1:
	   	   	system("cls");
 	   	   	cout<<"Hotels in Mumbai :-\n";
 	   	   	int c;
	 	cout<<"1. Hotel Taj, near Marine Lines, Mumbai.\nRs.14,598\n\n2. Hotel Jannat, near Raghuleela Mall, Navi Mumbai.\nRs.10,358\n\nEnter Your Choice : ";
	 	cin>>c;
	   	break;
 	   	   	
   	   	case 2:
		system("cls");
 	   	cout<<"Hotels in Goa :-\n";
        int s;
        cout<<"1. Hotel Nisarga, near Panjim road, Goa.\nRs.16,478\n\n2. Hotel Relax, near Mumbai-Goa Highway, Goa.\nRs.17,234\n\nEnter your choice : ";
        cin>>s;
        break;
 	   	   		
 	   	default:
 	   	cout<<"Invalid Input";
 	}
}
class display : public detail
{
	  public:
	 void show()
	 {
	   system("cls");
	  cout<<"\n************ Hotel Management *************\n\n";
	  cout<<"Name : "<<name<<endl;
	  cout<<"Check In :"<<check_in<<"\t\t"<<"Check Out :"<<check_out<<endl;
	  cout<<"Phone : "<<phn<<"\t\t"<<"Email Id :"<<email<<endl;
	  //cout<<"Adhar Card No :"<<adh_no<<endl;
	  cout<<"Adults :"<<adults<<"\t\tChildren :"<<chld<<endl;
	  if(ch==1)
	   {
	   	  if(c==1)
	     {
		   cout<<"Bookings Done For Hotel Taj, Mumbai.";
     	 }
     	
		else 
		{
			cout<<"Bookings Done For Hotel Jannat,Navi Mumbai.";
		}	  
       }
      else 
      {
    	if(s==1)
    	{
    		cout<<"Bookings Done For Hotel Nisarga,Goa.";
    	}
		else 
		{
			cout<<"Bookings Done For Hotel Relax,Goa.";
		}
	  }
}
};
int detail :: writefile()
{ 
 	if(!name)
    {
    	  cout<<"Record not found...";
    	  return (0);
    	  
	}
	else
	{
	       ofstream ofile;
	       ofile.open("abc.txt",ios::app);
           ofile<<"\n";
	       ofile<<"Name : "<<name<<endl;
	       ofile<<"Check In :"<<check_in<<"\t\t"<<"Check Out :"<<check_out<<endl;
	       ofile<<"Phone : "<<phn<<"\t\t"<<"Email Id :"<<email<<endl;
           ofile<<"Adults :"<<adults<<"\t\tChildren :"<<chld<<endl;
		   ofile.write((char*)this,sizeof (*this));
    
		ofile.close();
	     return (1);
	}
}
int detail :: readfile()
{
	  char str[100];
	  ifstream ifile;
	  ifile.open("abc.txt");
	  ifile.seekg(0,ios::beg);
	  ifile.read((char *)this,sizeof(*this));
	  
	  while(!ifile)
	  {
	  	  	display();
	  	    ifile.read((char *)this,sizeof(*this));
	  }
	  
      ifile.close();
}

int main()
{ 
    display d;
      int m;
      while(1)
    {
       
	 cout<<"\n\t\t\t\t--------------- WELCOME ---------------\n\n";
	   cout<<"\tMain Menu :\t\n1.Insert\t\n2.Display\t\n3.Exit\n";
	   cout<<"Enter your choice :";
	   cin>>m;
	   
	   switch(m)
	   {
	   	   system("cls");
	   	   case 1:
	   	{
		   
	   	   cout<<"\t\t\t\t+++++++++++ Namaste !!! ++++++++++++\n\n";
	   	  
	   	  d.personal();
	   	  d.place();
	   	  d.show();
	   	  d.writefile();
	   	  d.readfile();
	   	  break;
	   }
	   	   
	   	   case 2:
	   	{
				  
	   	   	cout<<"\n\t\t\t\t************** Find Me **************\n\n";
	   	   	{
	   	   		   std::ifstream file("abc.txt");
	   		 	   if(file.is_open())
	   		 	   std::cout<<file.rdbuf();
				   file.close();
				   break;	
			}
	}
			
			case 3:
			{ 
			      system("cls");
				  exit;
				  cout<<"\t\t\n\nThank You For Visiting !!!\t\t";
				  return (0);
			}
			
			defualt:
			
			
				cout<<"Invalid Input";
	        
	}
}
            return 0;
        
}

     	
	 
		   
 	   
 	   
		
 
