#include<iostream>
#include<math.h>
using namespace std;
int main(){
    long double rounds;
    long int players;
    cout<<"Enter the number of players"<<endl;
    cin>>players;
    while(1){
    if(players<2){
        cout<<"Please enter atleast 2 players"<<endl;
    }
    else{
        break;
    }
    }
   while(1) 
   {cout<<"Enter the number of rounds to be played"<<endl;
    cin>>rounds;
    if(rounds<2){
        cout<<"Please enter >2 rounds"<<endl;
      
    }
   else {
    break;
   }
   }
    long double prev[players];
    long double curr[players];
    long double beta ;
    cout<<"Enter the value of hyperparameter beta"<<endl;
    cin>>beta;
    for (int i = 0; i <players; i++)
    {
        prev[i]=0;
    }
   for(int j =1;j<=rounds;j++){

    cout<<"Enter the values for round "<<j<<endl;
 
    for(int i=0;i<players;i++){
        cin>>curr[i];
}
    for (int  i = 0; i < players; i++)
    {
        
        curr[i]= ((1-beta)*curr[i] + prev[i]*(beta))/((1-pow(beta,j+1)));
        prev[i] +=curr[i];
    }
   }
   long double max=-1;
   long long int index=-1;
    for(int i=0;i<players;i++){
        if(curr[i]>max){
            max= curr[i];
            index = i;
        }
    }
    for(int i=0;i<players;i++){
        cout<<curr[i]<<" ";
    }
    cout<<endl;
    cout<<"Player "<<index+1<<" wins"<<endl;
   
    
    return 0;
}