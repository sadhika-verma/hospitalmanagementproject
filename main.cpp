#include <iostream>
#include<fstream>



using namespace std;

class doc_information                                        //class for doctor's info
{
    char doc_name[20];
    char specialization[30];
public:
    ofstream fout;                                      //to make accessibility easier
    ifstream fin;
    void doc_input();
    void doc_display();
    void truncate();
}docdata,docobj;
void doc_information::doc_input()
{

    fout.open("Binaryfile.dat",ios::binary|ios::app);
    {
        while(fout.is_open())
        {
            cout<<"Enter doctor's name:"<<endl;
            cin>>doc_name;
            cin.ignore();
            cout<<"Enter doctor specialization"<<endl;
            gets(specialization);
            fout.write((char*)&docdata,sizeof(docdata));      //writes data into binary file
            fout.close();
        }
    }
}
void doc_information::truncate()
{
    fout.open("Binaryfile.dat",ios::trunc);
    fout.close();
    cout<<"DOCTOR'S Data DELETED."<<endl;
}
void doc_information::doc_display()
{
    fin.open("Binaryfile.dat",ios::binary);
    while(fin.read((char*)&docdata,sizeof(docdata)))
    {
    cout<<"Doctor's name:";
    puts(doc_name);
    cout<<endl;
    cout<<"Doctor specialization:";
    puts(specialization);
    cout<<endl;                                     //displays doctors information
    fin.close();
    }
}

class pat_info                                                    //class for patient's info
{
private:
    char name[30];
    char problem[30];
    int age;
    char gender[30];
    char bldgrp[10];
public:
    ofstream foutt;
    ifstream finn;                       //to make accessibility easier
    void pat_input();
    void pat_display();
    void truncate();
}patdata,patobj;
void pat_info::pat_input()
{
    foutt.open("Binaryfile1.dat",ios::binary|ios::app);
    {
        while(foutt.is_open())
        {
            cout<<"Please insert a space and proceed with every input, thank you"<<endl;
            cout<<"Enter name of the patient:"<<endl;
            cin.ignore();
            gets(name);
            cout<<"Enter the patient's problem:"<<endl;
            cin.ignore();
            gets(problem);
            cout<<"Enter patient's age:"<<endl;
            cin>>age;
            cin.ignore();
            cout<<"Enter patient's gender:"<<endl;
            gets(gender);
            cin.ignore();
            cout<<"Enter patient's blood group"<<endl;
            gets(bldgrp);
            foutt.write((char*)&patdata,sizeof(patdata));        //writes patient data into another binary file
            foutt.close();
        }

    }
}
void pat_info::pat_display()
{

    finn.open("Binaryfile1.dat",ios::binary);
    while(finn.read((char*)&patdata,sizeof(patdata)))        //displays patient info
    {
        cout<<"\nPATIENT NAME: ";
        puts(name);

        cout<<"\nPROBLEM: ";
        puts(problem);

        cout<<"\nAGE: "<<age;

        cout<<"\nGENDER: ";
        puts(gender);

        cout<<"\nBLOOD GROUP: ";
        puts(bldgrp);

        finn.close();
    }

}
void pat_info::truncate()
{
    ofstream foutt;
    foutt.open("Binaryfile1.dat",ios::trunc);
    foutt.close();
    cout<<"PATIENTS Data Deleted"<<endl;
}
class appointments                                   //class for appointments
{
private:
    char docname[30];
    int date;
    char day[10];
    int time;
public:
    void app_input();
    void app_display();
};
void appointments::app_input()
{
    cout<<"Enter doctor's name:"<<endl;
    cin>>docname;
    cout<<"Enter Date, Day, Time:"<<endl;
    cin>>date>>day>>time;
    if(time<10.00)                           //to check if time is in working hours of doctor
    {
        cout<<"Doctors not available before 10am"<<endl;
    }
    else if(time>20.00)
    {
        cout<<"Doctors not available after 8pm"<<endl;
    }
}
void appointments::app_display()
{
    cout<<"Appointment Confirmed! Details are given below"<<endl;
    cout<<"DOCTOR'S NAME: "<<docname<<endl;
    cout<<"TIMING :"<<date<<" "<<day<<" "<<time<<" "<<endl;
}

struct billing              //structure for billing
{
    char desc[50];
    int amt;
};

class ambulance                //for ambulance service
{
private:
    char address[50];
    int no;
    int c;
    int v;
public:
    void amb_input();
    void amb_display();
    void check();
};
void ambulance::amb_input()
{
    cout<<"Enter address (without spaces)"<<endl;
    cin>>address;
    cout<<"Send ambulance number: \n1.\n2.\n3.\nEnter your choice."<<endl;
    cin>>no;
}
void ambulance::check()
{
        if(c==1)                //condition
        {
            if(no==v)             //checking if same ambulance went
            {
                cout<<"The ambulance has already gone"<<endl;
            }
            else
            {
                cout<<"Sent ambulance "<<no<<endl;
                v=no;                //assigning value to comparing variable
            }
        }
        else
        {
            cout<<"Sent Ambulance "<<no<<endl;
            v=no;
             c=1;                      //assigning value to show that it ran once
        }
}
void ambulance::amb_display()
{
    cout<<"Address :"<<address<<endl;
    check();

}

void input()                 //central function
{
    int ch; char k='y'; pat_info arr[3]; doc_information a[3];
    do                          //to run again
    {
    cout<<"\t---------------------------------------------------------"<<endl;
    cout<<"\t*\t\t:::HOME PAGE:::                         *"<<endl;
    cout<<"\t*\t1. Information                  \t\t*"<<endl;
    cout<<"\t*\t2. Current Room Booking         \t\t*"<<endl;
    cout<<"\t*\t3. Booking Appointments         \t\t*"<<endl;
    cout<<"\t*\t4. Billing                      \t\t*"<<endl;
    cout<<"\t*\t5. Ambulance Service            \t\t*"<<endl;
    cout<<"\t*\t6. Exit                         \t\t*"<<endl;
    cout<<"\t*\tEnter your choice..             \t\t*"<<endl;
    cout<<"\t---------------------------------------------------------"<<endl;
    cin>>ch;
switch(ch)
{
    case 1:
           int h;
           cout<<"1. Input Doctor's information"<<endl;
           cout<<"2. Input Patient's information"<<endl;
           cout<<"3. Display Doctors information"<<endl;
           cout<<"4. Display Patients information"<<endl;
           cout<<"5. Delete data of doctor?"<<endl;
           cout<<"6. Delete data of Patient?"<<endl;

           cout<<"Enter your choice.."<<endl;
           cin>>h;
           switch(h)
           {
             case 1:
                 {
                     for(int i=0;i<3;i++)
                     {
                     a[i].doc_input();
                     }
                 }
                     break;
             case 2:
                 {
                for(int j=0;j<3;j++)
                {
                    arr[j].pat_input();
                }
                }
                break;
             case 3:
                {
                    for(int i=0;i<3;i++)
                     {
                     a[i].doc_display();
                     }
                    break;
                }
             case 4:
                {
                    for(int j=0;j<3;j++)
                    {
                    arr[j].pat_display();
                    }
                    break;
                }
             case 5:
                docdata.truncate();
                break;
             case 6:
                patdata.truncate();
           }
           break;

    case 2:int roomno;
           cout<<"Enter room number to be allotted for patient:"<<endl;
           cin>>roomno;
           int v,p;
        if(p==1)
        {
            if(roomno==v)
            {
                cout<<"Room not available"<<endl;
                 cout<<"------------------------------------------------------------"<<endl;
            }

            else
            {
                cout<<"Room booked "<<roomno<<endl;
                v==roomno;
            }
        }
        else
        {
            cout<<"Room Booked "<<roomno<<endl;
            v=roomno;
            p=1;
        }
           break;

    case 3:appointments a;
           a.app_input();
           a.app_display();
           break;

    case 4:
        {
           int sum=0; char u='y'; int o; int money;
           do{                                    /*&i did this its simple to
                                                 understand its like a normal menu*/
           cout<<"     ---------------------------------------------------------"<<endl;
           cout<<"     *             Select Treatments Taken:                  *"<<endl;
           cout<<"     * 1. Surgery                                     12000  *"<<endl;
           cout<<"     * 2. Blood test                                  500    *"<<endl;
           cout<<"     * 3. Cancer Treatment                            100000 *"<<endl;
           cout<<"     * 4. Doctors guidance fee                        5000   *"<<endl;
           cout<<"     * 5. ICU stay                                    120000 *"<<endl;
           cout<<"     * 6. X ray                                       1200   *"<<endl;
           cout<<"     * 7. Fracture treatment                          30000  *"<<endl;
           cout<<"     * 8. Pregnancy                                   20000  *"<<endl;
           cout<<"     * 9. Mental Treatment                            40000  *"<<endl;
           cout<<"     * 10. Treatment not mentioned above(enter price)"<<endl;
           cout<<"   ---------------------------------------------------------"<<endl;
           cout<<"       Choose from above.."<<endl;
           cin>>o;
           switch(o)
           {
           case 1:
               sum=sum+12000;
            break;
            case 2:
                sum+=500;
            break;
            case 3:
                sum+=+1000000;
            break;
            case 4:
                sum+=5000;
            break;
            case 5:
                sum+=120000;
            break;
            case 6:
                sum+=1200;
            break;
            case 7:
                sum+=30000;
            break;
            case 8:
                sum+=20000;
            break;
            case 9:
                sum+=40000;
            break;
            case 10:
                {
                    cout<<"Enter treatment cost"<<endl;
                    cin>>money;
                    sum+=money;
                }
            break;
            default:
                {
                    cout<<"Error Input"<<endl;
                }
            break;
           }

           cout<<"Multiple Treatments? y/n"<<endl;
           cin>>u;
           }while(u=='y');
           cout<<"The Total Bill is:"<<sum<<endl;
           break;
}

    case 5:
        {
            ambulance d;
            d.amb_input();
            d.amb_display();
            break;
        }
    case 6:
        {
            break;
        }
    default:
    {
        cout<<"Please check error input and run again"<<endl;
        break;
    }
    }
    cout<<"Do you wish you RUN AGAIN? y/n"<<endl;
    cin>>k;
    }while(k=='y');
}

int main()
{

    input();
    return 0;
}
