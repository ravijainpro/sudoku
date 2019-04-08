#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stack>
#include <bits/stdc++.h>
#define UNDEFINED 0
using namespace std;
int arr[9];
int **play=new int*[9];
stack<int> s;
void genrate_rand_array() {
    int i=0;
    while(i<9) {
        srand(time(NULL));
        int r=rand()%9+1,k;
        for(k=0; k<i; k++) {if(arr[k]==r) {break;}}
        if(k==i) {arr[i]=r; std::cout<<arr[i]<<" "<<flush; i++;}
    }
    std::cout << flush << "\n";
}

void fill_up() {
    srand(time(NULL));
    int i1=rand()%2+1,i2;
    if(i1==2) {i2=0;}
    else {i2=1; while(i2!=0 && i2!=2 ) {i2=rand()%3;}}
    cout.flush();
    {   for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            play[i][j]=arr[i*3+j];
        if(i==0) {
            play[i1][j+3]=arr[i*3+j];
            if(i1==1) {play[2][j+6]=arr[i*3+j];}
            if(i1==2) {play[1][j+6]=arr[i*3+j];}
            }
        if(i==1) {
            play[i2][j+3]=arr[i*3+j];
            if(i2==0) {play[2][j+6]=arr[i*3+j];}
            if(i2==2) {play[0][j+6]=arr[i*3+j];}
            }
        if(i==2) {
            play[3-i1-i2][j+3]=arr[i*3+j];
            if((3-i1-i2)==0) {play[1][j+6]=arr[i*3+j];}
            if((3-i1-i2)==1) {play[0][j+6]=arr[i*3+j];}
            }
        }}
    }
{   for(int j=0; j<3; j++) {
        for(int i=0; i<3; i++) {
           if(j==0) {
            play[i+3][i1]=play[i][j];
            if(i1==1) {play[i+6][2]=play[i][j];}
            if(i1==2) {play[i+6][1]=play[i][j];}
            }
        if(j==1) {
            play[i+3][i2]=play[i][j];
            if(i2==0) {play[i+6][2]=play[i][j];}
            if(i2==2) {play[i+6][0]=play[i][j];}
            }
        if(j==2) {
            play[i+3][3-i1-i2]=play[i][j];
            if((3-i1-i2)==0) {play[i+6][1]=play[i][j];}
            if((3-i1-i2)==1) {play[i+6][0]=play[i][j];}
            }
        }}
    }
    {   for(int i=3; i<9; i++) {
        for(int j=0; j<3; j++) {
        if(i==3) {
            play[i1+3][j+3]=play[i][j];
            if(i1==1) {play[5][j+6]=play[i][j];}
            if(i1==2) {play[4][j+6]=play[i][j];}
            }
        if(i==4) {
            play[i2+3][j+3]=play[i][j];
            if(i2==0) {play[5][j+6]=play[i][j];}
            if(i2==2) {play[3][j+6]=play[i][j];}
            }
        if(i==5) {
            play[6-i1-i2][j+3]=play[i][j];;
            if((3-i1-i2)==0) {play[4][j+6]=play[i][j];}
            if((3-i1-i2)==1) {play[3][j+6]=play[i][j];}
            }
        if(i==6) {
            play[i1+6][j+3]=play[i][j];
            if(i1==1) {play[8][j+6]=play[i][j];}
            if(i1==2) {play[7][j+6]=play[i][j];}
            }
        if(i==7) {
            play[i2+6][j+3]=play[i][j];
            if(i2==0) {play[8][j+6]=play[i][j];}
            if(i2==2) {play[6][j+6]=play[i][j];}
            }
        if(i==8) {
            play[9-i1-i2][j+3]=play[i][j];;
            if((3-i1-i2)==0) {play[7][j+6]=play[i][j];}
            if((3-i1-i2)==1) {play[6][j+6]=play[i][j];}
            }
        }}
    }
    
}

void in_file() {
ofstream o;
o.open("sodoku_data.out",ios::out|ios::app);
if(!o) {cout << flush << "Unable to open the file(s)\n"; exit(1);}
int x,y;
//===============DIFFERENT WAY TO PRINT THE STUFF IN FILE===============
/* for(x=0; x<3; x++) {
o << "| "  << flush;
for(y=0; y<3; y++) {o << play[x][y] << " " << flush;}
o << "| " << flush;
for(y=3; y<6; y++) {o << play[x][y] << " " << flush;}
o << "| " << flush;
for(y=6; y<9; y++) {o << play[x][y] << " " << flush;}
o <<
 "|" <<  endl << flush;
}
o << "-------------------------\n" << flush;

for(x=3; x<6; x++) {
o << "| " << flush;
for(y=0; y<3; y++) {o << play[x][y] << " " << flush;}
o << "| " << flush;
for(y=3; y<6; y++) {o << play[x][y] << " " << flush;}
o << "| " << flush;
for(y=6; y<9; y++) {o << play[x][y] << " " << flush;}
o << "|" <<  endl << flush;
}
o << "-------------------------\n" << flush;

for(x=6; x<9; x++) {
o << "| " << flush;
for(y=0; y<3; y++) {o << play[x][y] << " " << flush;}
o << "| " << flush;
for(y=3; y<6; y++) {o << play[x][y] << " " << flush;}
o << "| " << flush;
for(y=6; y<9; y++) {o << play[x][y] << " " << flush;}
o << "|" <<  endl << flush;
}
 */
for(x=0; x<9; x++) {
    for(y=0; y<9; y++) {
        o << play[x][y] << " " << flush;
    }
    o << "\n" << flush;
}
o << "\n\n" << flush;
o.close();
o.flush();
cout.flush();
}

void display() {
 int x,y;
for(x=0; x<3; x++) {
cout << flush << "| ";
for(y=0; y<3; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "| ";
for(y=3; y<6; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "| ";
for(y=6; y<9; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush <<
 "|" <<  endl;
}
cout << flush << "-------------------------\n";

for(x=3; x<6; x++) {
cout << flush << "| ";
for(y=0; y<3; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "| ";
for(y=3; y<6; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "| ";
for(y=6; y<9; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "|" <<  endl;
}
cout << flush << "-------------------------\n";

for(x=6; x<9; x++) {
cout << flush << "| ";
for(y=0; y<3; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "| ";
for(y=3; y<6; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "| ";
for(y=6; y<9; y++) {if(play[x][y]!=0) {cout << flush << play[x][y] << " ";} else {cout << flush << "  ";}}
cout << flush << "|" <<  endl;
}
cout << flush << "\n";

}
//==========SOLVE PART===========
bool findEmpty(int &row,int &col);
bool isSolveable(int row,int col,int num);
bool solve() {
    int row,col;
    if(!findEmpty(row,col)) {return true; /*mark end of program.. coz nothing is empty now...SOLVED */}
    for(int num=1; num<=9; num++) {
        if(isSolveable(row,col,num)) {
            s.push(num);
            if(num<9) {continue;}
           // play[row][col]=num;
            if(solve() && s.size()==1) {return true; /* to mark end of that particular cell.. and not execute next line */}
            play[row][col]=UNDEFINED;
             while(s.size()!=0) {s.pop();}
    }
    }
        return false;
}
bool solve_sol() {
    int row,col;
    if(!findEmpty(row,col)) {return true; /*mark end of program.. coz nothing is empty now...SOLVED */}
    for(int num=1; num<=9; num++) {
        if(isSolveable(row,col,num)) {
            play[row][col]=num;
            if(solve_sol()) {return true; /* to mark end of that particular cell.. and not execute next line */}
            play[row][col]=UNDEFINED;
    }
    }
        return false;
}
bool findEmpty(int &row, int &col) {
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(play[row][col]==UNDEFINED) {return true;}
        }
    }
    return false;
}
bool usedInRow(int row,int num) {
    for(int col=0; col<9; col++) {
        if(play[row][col]==num) {return true;}
    }
    return false;
}
bool usedIncol(int col,int num) {
    for(int row=0; row<9; row++) {
        if(play[row][col]==num) {return true;}
    }
    return false;
}
bool usedInGrid(int row_start,int col_start,int num) {
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
           if(play[row_start+row][col_start+col]==num) {return true;}
        }
    }
    return false;
}
bool isSolveable(int row,int col,int num) {
    return !usedIncol(col,num) && !usedInRow(row,num) &&!usedInGrid(row-row%3,col-col%3,num);
}
//======================================================================================

int generate_rand_val() {
    srand(time(NULL));
    int k=rand()%9+1;
    return k;    
}

void remove() {
    for(int i=0; i<9; i++) {
    int count=4+rand()%3,check=0;
 cout << count << " " << flush;
    int to_remove[6];
    while(check<count) {
        int z=generate_rand_val(),k;
        for(k=0;k<check;k++) {if(z==to_remove[k]){break;}}
        if(k==check) {to_remove[check]=z; check++;}
    }
    for(int k=0; k<count; k++) {
        int rev=to_remove[k]; //1-9 output 
cout << rev << flush;
        int val=play[(i/3)*3+(rev-1)/3][(i%3)*3+(rev-1)%3];
        play[(i/3)*3+(rev-1)/3][(i%3)*3+(rev-1)%3]=0;
        if(!solve) {play[(i/3)*3+(rev-1)/3][(i%3)*3+(rev-1)%3]=val;
        }
    }  
cout << "\n" << flush;  
    }
}

int main() {
    for(int z=0; z<9; z++) {play[z]=new int[9];}

//=================THIS BLOCK OF CODE IS FOR SOLVING ANY SUDOKU============================
     /* ifstream i;
    i.open("sodoku_data.in",ios::in);
    if(!i) {cout << "Unable to open the file(s)\n"; exit(1);}
    for(int k=0; k<9; k++){ for(int l=0; l<9; l++) {int q; i>>q; play[k][l]=q;}}
    cout << "done\n";
    if(solve_sol()==true){in_file(); display();}
    else {cout << "FALIED\n";} */
//==========================================================================================
 
    /* I used Dynamic memory allocation coz heap memory is large and also i need stack to be free as it
    has has less memory and recursion is performed on stack memory... so backtracking will hang if stack gets full */
 /* BUGS:
    1> The Sudoku Generated has multiple solutions.. fix it
    ** To get rid of the above problem i must generate an algoritm that generates all possible solutions 
        for a given sudoku... so that i can check at every step wheather my program is going good...
    ** But tbis may increse time req. coz at every removal all possible solutions will be checked
    ** let's assume there are 6 voids in a grid...i.e., 6*9=54 voids total
        but if we keep checking for multiple solutions after every removal... backtracking(recursion) will consume 
        entire stack and this may lead to errors or may take lot of time
    ** but i think like upto some removals there is liberty to not check for multiple solutions..coz if we remove
        upto some 10 numbers there will not be possibility of multiple solution
    ** or do i need to change the fashion of removal... some different technique... nmaybe not random..some solvable pattern
 
  */
    genrate_rand_array();
    fill_up();
    in_file(); //
    remove();
    in_file();
    display();
   
    return 0;
}


