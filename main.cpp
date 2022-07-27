#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

string subject, nick;
string content[5];
string ansA[5], ansB[5], ansC[5], ansD[5];
string correct[5];
string answer;
int points=0;

int main()
{
    int  linenumber=1;
    string line;
    int questnum = 0;

    fstream file;
    file.open("quiz.txt",ios::in);

    if (file.good()==false)
    {
        cout<<"File does not exist";
        exit(0);
    }

    while(getline(file,line))
    {
        switch(linenumber)
        {
            case 1: subject=line;       break;
            case 2: nick=line;          break;
            case 3: content[questnum] = line;  break;
            case 4: ansA[questnum] = line;     break;
            case 5: ansB[questnum] = line;     break;
            case 6: ansC[questnum] = line;     break;
            case 7: ansD[questnum] = line;     break;
            case 8: correct[questnum] = line;  break;
        }

        if(linenumber==8){linenumber=2; questnum++;}
        linenumber++;
    }

    file.close();

    for (int i=0; i<=4; i++)
    {
        cout<<endl<<content[i]<<endl;
        cout<<"A. "<<ansA[i]<<endl;
        cout<<"B. "<<ansB[i]<<endl;
        cout<<"C. "<<ansC[i]<<endl;
        cout<<"D. "<<ansD[i]<<endl;

        cout<<"Your answer: ";
        cin>>answer;

        transform(answer.begin(),answer.end(), answer.begin(), ::tolower);

        if (answer==correct[i])
        {
            cout<<"The answer is correct. You earn one point"<<endl;
            points++;
        } else cout<<"Wrong. Zero points. The correct answer is: "<<correct[i]<<endl;
    }
    cout<<endl<<"End of quiz. Number of points: "<<points<<endl;

    return 0;
}
