#include<iostream>
#define INFINITY 999
#define MAX  6
using namespace std;

class tree
{
	private:
		int G[MAX][MAX], ST[MAX][MAX];
		int v,e;
   public:
        tree();
        void display();
        void display_ST();
		void MST();
};

tree::tree()  //default constructor
{
	int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if(i==j)
			    G[i][j]=0;  //diagonal element zero
			else
				G[i][j]=INFINITY; //non connected edges
			ST[i][j]=0;
		}
	}
}

void tree::display()  //display adjacency matrix of graph
{
    int i,j;
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			cout<<G[i][j]<<"\t";
		}
		cout<<"\n";
	}

}

void tree::display_ST()   //display adjacency matrix of spanning tree
{
    int i,j;
    for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			cout<<ST[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

void tree::MST()
{
   int i,j,v0,v1,wt,count;
   int process[MAX]={0},via[MAX]={0},distance[MAX]={0};
   int sv,mindist,u,v2,Totalcost_Graph=0, Totalcost_MST=0;
   //accepting the values
   cout<<"\nEnter the no. Of vertices : ";
   cin>>v;

   cout<<"\nEnter the no. Of edges : ";
   cin>>e;

   cout<<"\nEnter the "<<e<<" edges : ";

   cout<<"\nSource\tDest\tWeight\n";

    for(i=0;i<e;i++)
       {
        cin>>v0>>v2>>wt; // enter start vertex and end vertex and cost
        Totalcost_Graph+=wt; //adding total cost of graph

        G[v0][v2]=wt;
        G[v2][v0]=wt;
        }
    cout<<"\n";
	cout<<"\nAdjacency Matrix of graph:\n\n";
    display();  //display graph

	cout<<"\nPlease Enter the Starting vertex : ";
    cin>>sv;

    process[sv]=1;  //starting vertex =1

    for(i=0;i<v;i++){
        distance[i]=G[sv][i];   //copying contents of original graph in dist array
        via[i]=sv; //modify via array
    }

    count=0;
    while(count<v-1) //traverse until vertex-1
    {
        mindist=999;

        for(i=0;i<v;i++)
        {
        if((distance[i]<mindist)&&(process[i]!=1))
            {
               mindist=distance[i]; //copying distance which is satisfying the condition in mindist
               v1=i;
            }
        }
        u=via[v1];

       if(u!=v1)    //to avoid self loop
       {
    	process[v1]=1;
    	ST[u][v1]=mindist;
    	ST[v1][u]=mindist;
    	Totalcost_MST+=mindist;  //adding total cost of minimum spanning tree

        for(j=0;j<v;j++)
        {
            if((G[v1][j]<distance[j]) && (process[j]!=1))
            {
               distance[j]=G[v1][j];
               via[j]=v1;
            }
        }
        count++;    //incrementing count
       }//while
    }

   cout<<"\nSpanning tree matrix is\n\n";

	display_ST();   //displaying spanning tree

	cout<<"\n\nThe Edges added in the minimum spanning tree";
	cout<<"\n\nSource\tDest\tWeight\n";
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
		{
			if((j>=i)&&ST[i][j]!=0)
				cout<<i<<"\t"<<j<<"\t"<<ST[i][j]<<"\n";
		}
	//	cout<<"\n";
	}


	cout<<"\nTotalcost_Graph is = "<<Totalcost_Graph; //displaying
	cout<<"\nTotalcost_MST is = "<<Totalcost_MST;
}

int main()
{
   tree t;

   t.MST();

   return 0;
}
