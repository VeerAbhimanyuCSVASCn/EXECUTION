#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

static int a[8][8];




int H(int r, int c, int i)
{   int k=0;
    int cc=c-1;
    while(a[r][cc]!=i && a[r][cc]!=0  &&  cc>=0)
    {        cc=cc-1;    }
    if(  (a[r][cc]==0 || cc==-1  ||  cc==c-1)  )
        {            goto ab;}

    for(int j=cc;j<=c;j++)
    {        a[r][j]=i;    }
    k=1;
    ab:
    cc=c+1;
    while(a[r][cc]!=i && a[r][cc]!=0  &&  cc<=8)
    {
        cc=cc+1;
    }
    if(a[r][cc]==0 || cc==9  ||cc==c+1)
      {
        goto cd;
      }
    for(int j=cc;j>=c;j--)
    {
        a[r][j]=i;
    }
    k=1;
    cd:
return k;
}
int V(int r, int c, int i)
{   int k=0;
    int rr=r-1;
    while(a[rr][c]!=i && a[rr][c]!=0  &&  rr>=0)
    {        rr=rr-1;    }
    if(  (a[rr][c]==0 || rr==-1  ||  rr==r-1)  )
        {            goto ab;}

    for(int j=rr;j<=r;j++)
    {        a[j][c]=i;    }
    k=1;
    ab:
    rr=r+1;
    while(a[rr][c]!=i && a[rr][c]!=0  &&  rr<=8)
    {
        rr=rr+1;
    }

    if(a[rr][c]==0 || rr==9  ||rr==r+1)
      {
        goto cd;
      }

    for(int j=rr;j>=r;j--)
    {
        a[j][c]=i;
    }
    k=1;

    cd:

return k;
}

int D(int r, int c, int i)
{   int k=0;
    int rr=r-1,cc=c-1;
    while(a[rr][cc]!=i && a[rr][cc]!=0  &&  rr>=0 && cc>=0)
    {        rr=rr-1;
                cc=cc-1;
    }

    if(  (a[rr][cc]==0 || rr==-1  ||  rr==r-1 || cc==c-1 || cc==-1 )  )
        {            goto ab; }



    for(int j=rr,k=cc;j<=r;j++,k++)
    {        a[j][k]=i;    }

    k=1;
    ab:
    rr=r+1;
    cc=c+1;
    while(a[rr][cc]!=i && a[rr][cc]!=0  &&  rr<=8 && cc<=8)
    {
        rr=rr+1;
        cc=cc+1;
    }

    if(a[rr][cc]==0 || rr==9  ||rr==r+1 ||  cc==9  ||  cc==c+1)
      {
        goto cd;
      }

     for(int j=rr,k=cc;j>=r;j--,k--)
    {        a[j][k]=i;    }


    k=1;

    cd:

return k;
}




int O(int r, int c, int i)
{   int k=0;
    int rr=r-1,cc=c+1;
    while(a[rr][cc]!=i && a[rr][cc]!=0  &&  rr>=0 && cc<=8)
    {        rr=rr-1;
                cc=cc+1;
    }

    if(  (a[rr][cc]==0 || rr==-1  ||  rr==r-1 || cc==c+1 || cc==-1 )  )
        {            goto ab; }



    for(int j=rr,k=cc;j<=r;j++,k--)
    {        a[j][k]=i;    }

    k=1;
    ab:
    rr=r+1;
    cc=c-1;
    while(a[rr][cc]!=i && a[rr][cc]!=0  &&  rr<=8 && cc>=0)
    {
        rr=rr+1;
        cc=cc-1;
    }

    if(a[rr][cc]==0 || rr==9  ||rr==r+1 ||  cc==9  ||  cc==c-1)
      {
        goto cd;
      }

     for(int j=rr,k=cc;j>=r;j--,k++)
    {        a[j][k]=i;    }


    k=1;

    cd:

return k;
}






void display()
{   cout<<endl<<endl;
    for(int i=0;i<8;i++)
    {cout<<endl;
        for(int j=0;j<8;j++)
        cout<<a[i][j]<<"  ";
    }
}







int plot(int r,int c,int i)
{
    if(a[r][c]==0)
    {
       int x=H(r,c,i);int y=V(r,c,i);int z=D(r,c,i);int xx=O(r,c,i);

    if(x||y||z||xx)

    {display();
        return 0;}
    }

        return 1;

}





int player(int i)
{   int b;
    ab:
    cin>>b;
    int k=plot(b/10,b%10,i);

    if(k==1)
      {
       cout<<"WRONG MOVE";
        goto ab;
      }
    return 0;
}






int main()
{
    a[3][3]=a[4][4]=1;
    a[3][4]=a[4][3]=2;
   for(int i=0;i<30;i++)
   {cout<<i;
    player(1);
    player(2);
    }

    return 0;
}
