#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;


void randomstart(){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
             
               grid[i][j]=rand()%2;
             
        }
    }
}
void manualstart(){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
             cout<<"Enter "<<i+1<<"th row and "<<j+1<<"th column element:";
               cin>>grid[i][j];
             
        }
    }
}

int calneigh(vector<vector<int>>& newgrid,int i,int j){
    int neighbours=0;
    if(i>0 && newgrid[i-1][j]==1)neighbours++;
            if(j>0 && newgrid[i][j-1]==1)neighbours++;
            if(i<newgrid.size()-1 && newgrid[i+1][j]==1)neighbours++;
            if(j<newgrid[0].size()-1 && newgrid[i][j+1]==1)neighbours++;

            if(i>0 && j>0 && newgrid[i-1][j-1]==1)neighbours++;
            if(i>0 &&  j<newgrid[0].size()-1 && newgrid[i-1][j+1]==1)neighbours++;
            if(i<newgrid.size()-1 && j>0 && newgrid[i+1][j-1]==1)neighbours++;
            if(i<newgrid.size()-1 && j<newgrid[0].size()-1 && newgrid[i+1][j+1]==1)neighbours++;

            return neighbours;
}



bool nextgen(vector<vector<int>> newgrid){
       for(int i=0;i<newgrid.size();i++){
        for(int j=0;j<newgrid[0].size();j++){
            
            int neighbours =0;
            neighbours = calneigh(newgrid,i,j);

            if(neighbours<2){
                newgrid[i][j]=0;
              
            }
            if(neighbours==2) 
            if(neighbours==3){
                newgrid[i][j]=1;
                
            }
            if(neighbours>3)
                {
                    newgrid[i][j]=0;
                    
                }
        }
    }
    bool stable=true;
    for(int i=0;i<newgrid.size();i++){
        for(int j=0;j<newgrid[0].size();j++){
            if(grid[i][j] != newgrid[i][j]){
                stable=false;
            }else {
                stable=true;
            }
            grid[i][j] = newgrid[i][j];
        }
    }
    return stable;

}



int main(){
    int rows=0;
    int cols =0;
    cout<<"Enter the number of rows for the grid:"<<endl;
    cin>>rows;
    cout<<"Enter the number of cols for the grid:"<<endl;
    cin>>cols;

    grid.resize(rows);
   
    for(int i=0;i<rows;i++){
        grid[i].resize(cols);
    }
    cout<<"Press R for random start or M for manual input:"<<endl;
    char ch;
    cin>>ch;

    if(ch=='R')
    randomstart();
    else if(ch=='M')
    manualstart();
    else {
        cout<<"Wrong input"<<endl;
        return 0;
    }

    while( nextgen(grid)!=true);
       

    cout<<endl;


     for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" "; 
        }cout<<endl;
    }
    cout<<"stable!!"<<endl;
   
return 0;
}
