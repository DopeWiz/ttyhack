#include <iostream>
#include <unistd.h>
using namespace std;

FILE *f_open(char *f_name);

int main(int argc, char *argv[])
{
    char *f_name = argv[1];
    FILE *fp;
    char u_name[20], pswd[20];
    if(argc!=2)
    {
        cout << "Usage: ttyhack <file/stream name>" << endl;
        return(0);
    }
    fp = f_open(f_name);
    cout<<"Asking for uname.\n";
    fprintf(fp, "login:\n");
    fscanf(fp, "%s", &u_name);
    cout<<u_name<<endl;
    // usleep(2000);
    sleep(2);
    fp = f_open(f_name);
    cout<<"Asking for password.\n";
    fprintf(fp, "%s password:", u_name);
    fscanf(fp, "%s", &pswd);
    cout << "fname:\t" << f_name<<"\nuname:\t"<<u_name<<"\npass:\t"<<pswd;
    cout << endl;
    return(0);
}

FILE* f_open(char *f_name)
{
    FILE *fp;
    if(!(fp = fopen(f_name,"w+")))
    {
        cout << "Failed to load file \"" << f_name << "\"!"<<endl;
        exit(1);
    }
    return(fp);
}
