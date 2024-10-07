/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void allCombinations(int score,int TDtwo,int TDone,int TD,int FG,int S){
    if (score==0){
        printf("%d TD +2 pt, %d TD + FG, %d TD, %d FG, %d Safety\n",TDtwo,TDone, TD, FG,S);
        return;
    }
    //base case
    if (score<0){
        return;
    }
    allCombinations(score-8,TDtwo+1,TDone, TD, FG,S);
    allCombinations(score-7,TDtwo,TDone+1, TD, FG,S);
    allCombinations(score-6,TDtwo,TDone, TD+1, FG,S);
    allCombinations(score-3,TDtwo,TDone, TD, FG+1,S);
    allCombinations(score-2,TDtwo,TDone, TD, FG,S+1);
    
}

int main()
{
    int NFLScore;
    int continueLoop=1;
    while (continueLoop==1){
        printf("Enter the NFL Score:\n");
        scanf("%d",& NFLScore);
        allCombinations(NFLScore,0,0,0,0,0);
        printf("Enter 1 to continue or 0 to STOP\n");
        scanf("%d",& continueLoop);
    }
   
    return 0;
}