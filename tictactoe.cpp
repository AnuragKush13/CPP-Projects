#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include<conio.h>
using namespace std;


bool isPlayer = true;
bool haveTime = false;

void playerMove(int(*)[3]);
void computerMove(int(*)[3]);
bool checkPattern(int(*[3]));

int seconds = 0;

void timer()
{   
	haveTime = true;
	while (seconds<=5) {
		
		// display the timer
	
        //system("CLS");
        //cout << setfill(' ') << setw(55) << "		 TIMER		 \n";
        //cout<<"\r";
        //cout << setfill(' ') <<"   "<< setw(55)  << seconds << " sec " ;

		// sleep system call to sleep
		// for 1 second
		sleep(1);

		// increment seconds
		seconds++;

		
			
		}
        
        seconds = 0;
        haveTime = false;
       
	}




void printMatrix(int matrix[3][3]){
    cout<<"\n";
    for(int i = 0 ; i <3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {   
            if(matrix[i][j] == -1)
            cout<<"  --  ";     
            else if(matrix[i][j] == 1)
            cout<<"  "<<"X"<<"  ";
            else
            cout<<"  "<<"O"<<"  ";
        }

        cout<<"    \n\n"<<endl;
    }
}



bool checkPattern(int m[3][3]){
    int a ;
    if(isPlayer)
    a = 0;
    else 
    a = 1;


    //horizontol pattern
    for(int i = 0; i <=2; i++)
    {   int score = 0;
        for(int j = 0; j <= 2; j++)
        {
            if(m[i][j] == a)
            score++;
        }
        if(score == 3)
        return true;
    }

    //vertical pattern
    for(int i = 0; i <=2; i++)
    {   int score = 0;
        for(int j = 0; j <= 2; j++)
        {
            if(m[j][i] == a)
            score++;
        }
        if(score == 3)
        return true;
    }

    //diagonal pattern
    if((m[0][0]== a && m[1][1] == a && m[2][2] == a) || (m[2][0]== a && m[1][1] == a && m[0][2] == a))
    {
        return true;
    }


    return false;


}

bool gameTie(int m[3][3]){
    int count = 0;
for(int i = 0; i <=2; i++)
    {
        for(int j = 0; j<=2;j++)
        {
            if(m[i][j] == 1 || m[i][j] == 0)
             {
                    count++;
             }
        }
    }

    if(count == 9)
    {return true;
    }

    return false;

}

void checkMove(int moveX, int moveY , int matrix[3][3]){
    if((moveX == 0 || moveX == 1 || moveX == 2)&&(moveY == 0 || moveY == 1 || moveY == 2))
    {
        if(matrix[moveX][moveY] == -1)
        { 
            if(isPlayer)
                    {
                        matrix[moveX][moveY] = 0;
                        //cout<<matrix[moveX][moveY]<<endl;
                        printMatrix(matrix);
                        if(checkPattern(matrix))
                        cout<<"\nKiddo won"<<endl;
                        else
                        {
                        if(!gameTie(matrix))
                            computerMove(matrix);
                        else
                            cout<<"Game tie , both of you are soo dumb!!";
                        }
                        }
            else
                    {    
                        matrix[moveX][moveY] = 1;
                       // cout<<matrix[moveX][moveY]<<endl;
                        printMatrix(matrix);
                        if(checkPattern(matrix))
                        cout<<"\nStupid Kiddo won"<<endl;
                        else
                    {
                        if(!gameTie(matrix))
                            playerMove(matrix);
                        else
                            cout<<"Game tie , both of you are soo dumb!!";
                        }
                    }
            
            
        }
        else
    {    
        if(isPlayer)
            cout<<"You lost kiddo wrong move"<<endl;
        else
            cout<<"Oh nooo wrong move!!!\nYou won kiddo, only by luck got it!!"<<endl;
    }
        
    }
    else
    {
        if(isPlayer)
            cout<<"You lost kiddo wrong move"<<endl;
        else
            cout<<"Oh nooo wrong move!!!\nYou won kiddo, only by luck got it!!"<<endl; 
    }
    
}

// move of the player
void playerMove(int matrix[3][3]){
   
    isPlayer = true;
    int moveX , moveY;
    cout<< "Enter your move kiddo"<<endl;
    cout<<"\nEnter row: ";
    cin >> moveX;
    cout<<"Enter column: ";

    cin>>moveY;
    system("CLS");
    checkMove(moveX,moveY,matrix);
    
    // else{
    //     cout<<"Time Over !! You lost kiddo!!";
    // }



}

//move of the 2nd player or computer
void computerMove(int matrix[3][3]){
    isPlayer = false;
    int moveX , moveY;
    cout<< "Stupid kiddo move "<<endl;
    cout<<"\nEnter row: ";
    cin >> moveX;
    // moveX = getch();
    cout<<"Enter column: ";

    cin>>moveY;
    //moveY = getch();
    system("CLS");
    checkMove(moveX,moveY,matrix);
    
}



int main()
{ bool restart;
   
do{
    system("CLS");
       restart = false;
    int x;
    int m[3][3] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

    
    cout<< "Kiddo : O\nStupid Kiddo : X"<<endl;
    
    printMatrix(m);
        playerMove(m);

    cout<<"Enter 0 to exit 1 to restart!\n";
    cin>>x;
    if(x== 1)
    restart = true;
    


}
while(restart);
    
    return 0;
}