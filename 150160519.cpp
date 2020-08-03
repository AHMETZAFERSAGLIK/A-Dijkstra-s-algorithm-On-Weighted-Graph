



#include <iostream>
#include <limits.h>
#include <fstream>
#define MAX 300

#include <vector> 
using namespace std;

class DISTANCE
{	
public:

	int adjencency[MAX][MAX];
	int joseph_time[MAX];
	int joseph_road[MAX];
	int joseph_sayac;
	int lucy_time[MAX];
	int lucy_road[MAX];
	int lucy_sayac;
	int distance[MAX];  
    bool spt_bool[MAX]; 
    int parent[MAX]; 
  	vector<int> path;
	int time[MAX];
	int sayac;
	

void dijkstra(int graph[MAX][MAX], int src,int dst){
	
    for (int i = 0; i < MAX; i++) 
    { 
        parent[src] = -1; 
        distance[i] = INT_MAX; 
        spt_bool[i] = false; 
    } 
    distance[src] = 0; 
    for (int count = 0; count < MAX - 1; count++) 
    { 
    
    	int min = INT_MAX, min_index; 
  
    for (int v = 0; v < MAX; v++) {
	
        if (spt_bool[v] == false && distance[v] <= min) 
            min = distance[v], min_index = v; 
   
								}
								     
    
        int u = min_index;
		 
        spt_bool[u] = true; 
        for (int v = 0; v < MAX; v++) {
            if (!spt_bool[v] && graph[u][v] && 
                distance[u] + graph[u][v] < distance[v]) 
            { 
                parent[v] = u; 
                distance[v] = distance[u] + graph[u][v]; 
			
            }  
}
	}
	path.erase (path.begin(),path.begin()+sayac); 
	sayac=0;
	
	rtrn_nodes(src,parent, dst);
	int buff=src;
	time[-1]=0;
	for(int i=0;i<sayac;i++)
	{
	time[i]=graph[buff][path[i]]+time[i-1];
	buff=path[i]; 

	}
	
  
}
void rtrn_nodes(int src, int parent[], int j){
	 if (parent[j] == - 1) 
        return ; 
    rtrn_nodes(src,parent, parent[j]); 
    path.push_back(j);
    sayac++;
    
}


                      
};

 


int main(int argc, char** argv)
{
	DISTANCE matrix;
	DISTANCE matrix2;
		    
			int j_hotel;
			int j_dest;
			int l_hotel;
			int l_dest;
		
			
		
			string File_Name;
		
			if (argc != 2)
			{
				cerr << "ERROR! NO paramether. " << endl;
				//system("PAUSE");
				return 0;
			}
		
			File_Name = argv[1];
			
			ifstream input_file(File_Name.c_str());
		
			if (!input_file.is_open())	// File opening control
			{
				printf("ERROR!! File cant open.\n");
			
				return 0;
			}
			int num1;
			int num2;
			int num3;
			
			input_file >> num1;
			
			for (int i = 0; i < num1; i++)
			{
			 for (int j = 0; j < num1; j++)  
			{matrix.adjencency[i][j] = 0;
			matrix2.adjencency[i][j] = 0;
		
		}}
			input_file >> j_hotel;
			input_file >> j_dest;
			input_file >> l_hotel;
			input_file >> l_dest;
			
			// I am reading file
			while (!input_file.eof())						
			{
				input_file >> num2;
				input_file >> num3;
				input_file >> matrix.adjencency[num2][num3];
				
			}
			
			int josephwait[30];
			int lucywait[30];
			
			//matrix object has paths with crossings
		    matrix.dijkstra(matrix.adjencency,j_hotel,j_dest);
		    
		    for(int i=0; i<matrix.sayac;i++)
		    {
			matrix.joseph_time[i]=matrix.time[i];
			matrix.joseph_road[i]=matrix.path[i];
			matrix.joseph_sayac=matrix.sayac;
			
				
			}
			int buff=matrix.time[matrix.sayac-1];
			
		
			matrix.dijkstra(matrix.adjencency,j_dest,j_hotel);
		    	
		    for(int i=0; i<matrix.sayac;i++)
		    {
			int k=i+matrix.joseph_sayac;
			matrix.joseph_time[k]=matrix.time[i]+buff;
			for(int num1=0;num1<30;num1++){
					matrix.joseph_time[k]=	matrix.joseph_time[k]+1;
					josephwait[num1]=matrix.joseph_time[k];
			}
			matrix.joseph_road[k]=matrix.path[i];
			
			
				}
				matrix.joseph_sayac=matrix.joseph_sayac + matrix.sayac;
				
				
				
			
			matrix.dijkstra(matrix.adjencency,l_hotel,l_dest);
		    
		    for(int i=0; i<matrix.sayac;i++)
		    {
			matrix.lucy_time[i]=matrix.time[i];
			matrix.lucy_road[i]=matrix.path[i];
			matrix.lucy_sayac=matrix.sayac;
				
			}
			int buff1=matrix.time[matrix.sayac-1];
			
		
			matrix.dijkstra(matrix.adjencency,l_dest,l_hotel);
		   
		    for(int i=0; i<matrix.sayac;i++)
		    {
			int l=i+matrix.lucy_sayac;
			matrix.lucy_time[l]=matrix.time[i]+buff1;
			for(int num1=0;num1<30;num1++){
				matrix.lucy_time[l]=matrix.lucy_time[l]+1;
				lucywait[num1]=matrix.lucy_time[l];
			}
			matrix.lucy_road[l]=matrix.path[i];
			
			
			
				}matrix.lucy_sayac=matrix.lucy_sayac + matrix.sayac;	
				
				
				
			for(int i=0;i<matrix.joseph_sayac;i++)
			{   
				for(int j=0;j<matrix.lucy_sayac;j++)
				{
					//this if looking for crossings when they are waiting(+30)
					if((josephwait[i]==lucywait[j])){
						cout<<"Crossing During Waiting"<<endl;
						
						for (int l = 0; l < num1; l++)
							{
								for (int m = 0; m < num1; m++)  
								{
									matrix2.adjencency[l][m]=matrix.adjencency[l][m];
								}
							}			
							for(int x = matrix.joseph_road[i]; x<num1; x++)
							{
								for(int y = 0;y<num1;y++)
								{          
									matrix2.adjencency[5][y] =100;
								}
							}
							for(int x = 0; x<num1; x++)
							{
								for(int y = matrix.joseph_road[i];y<num1;y++)
								{          
									matrix2.adjencency[x][5] =100;
								}
							}
							cout<<"joseph starts: "<<j_hotel<<endl;
							cout<<"NODE: "<<j_hotel<<"     TIME:"<<0<<endl;
								    matrix2.dijkstra(matrix2.adjencency,j_hotel,j_dest);
								    
								    for(int i=0; i<matrix2.sayac;i++)
								    {
									matrix2.joseph_time[i]=matrix2.time[i];
									matrix2.joseph_road[i]=matrix2.path[i];
									matrix2.joseph_sayac=matrix2.sayac;
									
									cout<<"NODE: "<<matrix2.path[i]<<"     TIME:"<<matrix2.time[i]<<endl;	
									}
									int buff=matrix2.time[matrix2.sayac-1];
									
									cout<<"    --return--"<<endl;
									cout<<"NODE: "<<matrix2.path[matrix2.path.size()-1]<<"     TIME:"<<30+buff<<endl;
									matrix2.dijkstra(matrix.adjencency,j_dest,j_hotel);
								    	
								    for(int i=0; i<matrix2.sayac;i++)
								    {
									int k=i+matrix2.joseph_sayac;
									matrix2.joseph_time[k]=matrix2.time[i]+30+buff;
									matrix2.joseph_road[k]=matrix2.path[i];
									
									cout<<"NODE: "<<matrix2.path[i]<<"     TIME:"<<matrix2.time[i]+30+buff<<endl;	
										}
										matrix2.joseph_sayac=matrix2.joseph_sayac + matrix2.sayac;
										cout<<endl;
										cout<<"duration: "<<matrix2.time[matrix2.path.size()-1]+30+buff<<endl;
										cout<<endl;
										if((matrix2.time[matrix2.path.size()-1]+30+buff)>100){
											cout<<"No SOLUTION"<<endl;
											cout<<endl;
										}
									cout<<"lucie starts: "<<l_hotel<<endl;	
									cout<<"NODE: "<<l_hotel<<"     TIME:"<<0<<endl;
									matrix.dijkstra(matrix.adjencency,l_hotel,l_dest);
								    
								    for(int i=0; i<matrix.sayac;i++)
								    {
									matrix.lucy_time[i]=matrix.time[i];
									matrix.lucy_road[i]=matrix.path[i];
									matrix.lucy_sayac=matrix.sayac;
									cout<<"NODE: "<<matrix.path[i]<<"     TIME:"<<matrix.time[i]<<endl;	
									}
									int buff1=matrix.time[matrix.sayac-1];
									
									cout<<"    --return--"<<endl;
									
									cout<<"NODE: "<<matrix.path[matrix.path.size()-1]<<"     TIME:"<<30+buff1<<endl;
									matrix.dijkstra(matrix.adjencency,l_dest,l_hotel);
								   
								    for(int i=0; i<matrix.sayac;i++)
								    {
									int l=i+matrix.lucy_sayac;
									matrix.lucy_time[l]=matrix.time[i]+30+buff1;
									matrix.lucy_road[l]=matrix.path[i];
									
									cout<<"NODE: "<<matrix.path[i]<<"     TIME:"<<matrix.time[i]+30+buff1<<endl;	
										}matrix.lucy_sayac=matrix.lucy_sayac + matrix.sayac;	
											cout<<endl;
											cout<<"duration: "<<matrix.time[matrix.path.size()-1]+30+buff1<<endl;
											cout<<endl;
												if((matrix.time[matrix.path.size()-1]+30+buff1)>100){
											cout<<"No SOLUTION"<<endl;
											cout<<endl;
										}			
													
														return 0;
					}
					//This if is looking crossing during the trip and if there is we are making that row and column 100;
					if((matrix.joseph_time[i]==matrix.lucy_time[j]&&matrix.joseph_road[i]==matrix.lucy_road[j])  ){
							
							
							for (int l = 0; l < num1; l++)
							{
								for (int m = 0; m < num1; m++)  
								{
									matrix2.adjencency[l][m]=matrix.adjencency[l][m];
								}
							}			
							for(int x = matrix.joseph_road[i]; x<num1; x++)
							{
								for(int y = 0;y<num1;y++)
								{          
									matrix2.adjencency[matrix.joseph_road[i]][y] =100;
								}
							}
							//matrix2 object is using for compare
							for(int x = 0; x<num1; x++)
							{
								for(int y = matrix.joseph_road[i];y<num1;y++)
								{          
									matrix2.adjencency[x][matrix.joseph_road[i]] =100;
								}
							}

	 

											cout<<"joseph starts: "<<j_hotel<<endl;
											cout<<"NODE: "<<j_hotel<<"     TIME:"<<0<<endl;
										    matrix.dijkstra(matrix.adjencency,j_hotel,j_dest);
										    
										    for(int i=0; i<matrix.sayac;i++)
										    {
											matrix.joseph_time[i]=matrix.time[i];
											matrix.joseph_road[i]=matrix.path[i];
											matrix.joseph_sayac=matrix.sayac;
											
											cout<<"NODE: "<<matrix.path[i]<<"     TIME:"<<matrix.time[i]<<endl;	
											}
											int buff=matrix.time[matrix.sayac-1];
											
											cout<<"    --return--"<<endl;
											cout<<"NODE: "<<matrix.path[matrix.path.size()-1]<<"     TIME:"<<30+buff<<endl;
											matrix.dijkstra(matrix.adjencency,j_dest,j_hotel);
										    	
										    for(int i=0; i<matrix.sayac;i++)
										    {
											int k=i+matrix.joseph_sayac;
											matrix.joseph_time[k]=matrix.time[i]+30+buff;
											matrix.joseph_road[k]=matrix.path[i];
											
											cout<<"NODE: "<<matrix.path[i]<<"     TIME:"<<matrix.time[i]+30+buff<<endl;	
												}
												matrix.joseph_sayac=matrix.joseph_sayac + matrix.sayac;
												
												cout<<endl;
												cout<<"duration: "<<matrix.time[matrix.path.size()-1]+30+buff<<endl;
												cout<<endl;
												
													if((matrix.time[matrix.path.size()-1]+30+buff)>100){
															cout<<"No SOLUTION"<<endl;
															cout<<endl;
										}
												
											cout<<"lucie starts: "<<l_hotel<<endl;
											cout<<"NODE: "<<l_hotel<<"     TIME:"<<0<<endl;	
											matrix2.dijkstra(matrix2.adjencency,l_hotel,l_dest);
										    
										    for(int i=0; i<matrix2.sayac;i++)
										    {
											matrix2.lucy_time[i]=matrix2.time[i];
											matrix2.lucy_road[i]=matrix2.path[i];
											matrix2.lucy_sayac=matrix2.sayac;
											cout<<"NODE: "<<matrix2.path[i]<<"     TIME:"<<matrix2.time[i]<<endl;	
											}
											int buff1=matrix2.time[matrix2.sayac-1];
											
											cout<<"    --return--"<<endl;
											cout<<"NODE: "<<matrix2.path[matrix2.path.size()-1]<<"     TIME:"<<30+buff1<<endl;
											matrix2.dijkstra(matrix2.adjencency,l_dest,l_hotel);
										   
										    for(int i=0; i<matrix2.sayac;i++)
										    {
											int l=i+matrix2.lucy_sayac;
											matrix2.lucy_time[l]=matrix2.time[i]+30+buff1;
											matrix2.lucy_road[l]=matrix2.path[i];
											
											cout<<"NODE: "<<matrix2.path[i]<<"     TIME:"<<matrix2.time[i]+30+buff1<<endl;	
												}matrix2.lucy_sayac=matrix2.lucy_sayac + matrix2.sayac;	
													
													cout<<endl;
													cout<<"duration: "<<matrix2.time[matrix2.path.size()-1]+30+buff1<<endl;
													cout<<endl;
													
														if((matrix2.time[matrix2.path.size()-1]+30+buff)>100){
																cout<<"No SOLUTION"<<endl;
																cout<<endl;
																												}			
															
																return 0;
																
								
							
					
						}
					}
				
				}
				
				
			
		    
		   
		


	return 0;
}
