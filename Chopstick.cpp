#include <iostream>
#include <conio.h>
using namespace std;
int A[2] = {1, 1};
int B[2] = {1, 1};
int count, x=0, S1, S2;
char Move, inputhand, affecthand;

void turnA()
{
    if (Move == 'A')
    {
        if (inputhand == 'L')
        {
            if (affecthand == 'L')
            {
                B[0] = A[0] + B[0];
            }
            if (affecthand == 'R')
            {
                B[1] = A[0] + B[1];
            }
        }
        if (inputhand == 'R')
        {
            if (affecthand == 'L')
            {
                B[0] = A[1] + B[0];
            }
            if (affecthand == 'R')
            {
                B[1] = A[1] + B[1];
            }
        }
    }
    if (Move == 'S')
    {
        A[0] = S1;
        A[1] = S2;
    }
}
void Roll()
{
    if (A[0] >= 5)
        A[0] = 0;
    if (A[1] >= 5)
        A[1] = 0;
    if (B[0] >= 5)
        B[0] = 0;
    if (B[1] >= 5)
        B[1] = 0;
}
void Player1()
{
    cout << "Enter move for Player 1 -";
    cin >> Move;
    if (Move == 'A')
    {
        cout << "Enter the move combination -";
        cin >> inputhand >> affecthand;
    }
    else if (Move == 'S')
    {
        cout << "Enter the move combination -";
        cin >> inputhand;
        cin>>S1>>S2;
    }
    turnA();
    Roll();
}

void turnB()
{
    if (Move == 'A')
    {
        if(inputhand=='L')
        {
            if(affecthand=='L')
            {
                A[0]=B[0] + A[0];
            }
            if(affecthand=='R')
            {
                A[1]=B[0] + A[1];
            }
        }
        if(inputhand=='R')
        {
            if(affecthand=='L')
            {
                A[0]= B[1] + A[0];
            }
            if(affecthand=='R')
            {
                A[1]= B[1] + A[1];
            }
        }
    }
    if(Move== 'S')
    {
        B[0]=S1;
        B[1]=S2;
    }
}
void Player2()
{
    cout << "Enter move for Player 2 -";
    cin >> Move;
    if (Move == 'A')
    {
        cout << "Enter the move combination -";
        cin >> inputhand >> affecthand;
    }
    else if (Move == 'S')
    {
        cout << "Enter the move combination -";
        cin >> inputhand;
        cin>>S1>>S2;
    }
    turnB();
    Roll();
}
void Check()
{
    if(A[0]==0 && A[1]==0)
    {
        count=1;
        x=1;
    }
     else if(B[0]==0 && B[1]==0)
    {
        count=2;
        x=1;
    }
}
int main()
{
    while(x==0)
	{
        cout << "Current Status:\n";
        cout << "Player1-" << A[0] << " " << A[1] << "\n";
        cout << "Player2-" << B[0] << " " << B[1] << "\n"<<endl;
        Check();
        if(A[0]==0 && A[1]==0)
        break;
        else if(B[0]==0 && B[1]==0)
        break;
        Player1();
        cout << "Current Status:\n";
        cout << "Player1-" << A[0] << " " << A[1] << "\n";
        cout << "Player2-" << B[0] << " " << B[1] << "\n"<<endl;
        Check();
        if(A[0]==0 && A[1]==0)
        break;
        else if(B[0]==0 && B[1]==0)
        break;
        Player2();

    }
    if(count==1)
    cout<<"Player 2 wins \n";
    if(count==2)
    cout<<"Player 1 wins \n";
    return 0;
}
