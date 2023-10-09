// created by Rishita Agarwal
#include <iostream>
#include<bits/stdc++.h>
#include <map>
using namespace std;
#define ll long long
const ll num=1e9;

int main(){
 int players;
 vector<int> v;
 cout<<"Enter the number of princes': ";
 cin>>players;

 vector <int> coins(players,100);
 while(players<2){
     cout<<"Atleast 2 players are required"<<endl;
     cout<<"Enter the number of princes' again: ";
     cin>>players;
 }

 int rounds;
 cout<<"Enter the number of rounds: ";
 cin>>rounds;
 int p=1;

 map <int, int> wins;
 while(rounds){
     map<int,int > count;
     vector <int> bids(players);
     cout<<"The amount bid by princes' in round "<<p<<" are- "<<endl;

     //the prince who bids in the end is eliminated as choices are less than the total number of princes
     for(int i=0;i<players;i++){
         cout<<"Prince "<<i+1<<" ";

         cin>>bids[i];
         count[bids[i]]++;
     }

     auto it= count.end();
     it--;
     int maxm=it->second;
     int z=it->first;
     it--;
     cout<<"The number of players with maximum bid are: "<<maxm<<endl;
     int sec=it->first;
     cout<<"The second highest amount is: "<<sec<<endl;
     for(int i=0;i<players;i++){
            if(bids[i]==z){
                    cout<<"Round is won by Prince "<<i+1<<endl;
                    coins[i]-=(sec/maxm);
                }
            }

     //Coins left with other princes'

     cout<<"The coins now with all princes' are-"<<endl;
     for(int k=0;k<players;k++){
        cout<<"Prince "<<k+1<<": "<<coins[k]<<endl;
     }
     vector <int> copy_coins=bids;
     sort(copy_coins.begin(),copy_coins.end());
     int maxx=copy_coins[players-1];

     for(int l=0;l<players;l++){
        if(bids[l]==maxx){
            wins[l+1]++; //i+1 is the prince number
        }
     }
     for(const auto& iter:wins){
        cout<<"prince "<<iter.first<<" with wins "<<iter.second<<endl;
     }
     rounds--;
     p++;
 }
 int maxn=0,k=0;
     for(auto it2:wins){
        maxn=max(maxn,it2.second);
        if(maxn==it2.second){
            k=it2.first;
        }
     }
     cout<<"The Prince who won the game finally is: "<<k<<endl;
}
