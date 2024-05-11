// Online C compiler to run C program online
#include <stdio.h>

int main() {
    
    int rows,cols;
    
    scanf("%d",&rows);
    scanf("%d",&cols);
    
    char grid[rows][cols];
    int visited[rows][cols];
    
    
    for(int i =0 ;i<rows; i++){
        for(int j=0; j<cols ; j++){
            visited[i][j]=0;
        }
    }   
    
    for(int i =0 ;i<rows; i++){
        for(int j=0; j<cols ; j++){
            scanf("%c",&grid[i][j]);
        }
    }
    
    //now visiting one by one
    for(int i=0; i<rows; i++){
        for(int j=0;j<cols; j++){
            
                
                if(grid[i][j]=='*'){
                    
                    int row_set = i;
                    
                    while(grid[i][j]!='o'&& i<rows){
                        i++;
                    }
                    
                    i-=1;
                    while(grid[i][j]!='*'){i--;}
                    grid[i][j] ='*';
                    i=row_set;
                    grid[i][j]='.';
                
                
                
            }
            
            
        }
    }

    return 0;
}