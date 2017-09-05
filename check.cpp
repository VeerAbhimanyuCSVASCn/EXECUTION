#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;


int a[8][8];

int players[2]={12,12};

void removee(int i)
{
    if(i==2)
        --players[0];
    else
        --players[1];

}

void inital()
{
    for(int i=0;i<3;i++)
    {   for(int j=0;j<8;j++)
        {if((i+j)%2==0)a[i][j]=1;}}
        for(int i=5;i<8;i++)
        {for(int j=0;j<8;j++){if((i+j)%2==0)a[i][j]=2;}}

}

void display()
{
    for(int i=0;i<8;i++)
    {cout<<"\n";
        for(int j=0;j<8;j++)
        {
            cout<<a[i][j]<<"  ";
        }
    }
}
int command(int d,int b,int c)
{
    if(a[d][b]==0)
    {
        return 0;
    }
    if((a[d][b]%2)!=(c%2))
    {
        return 0;
    }
return 1;
}
void check(int bha, int *abhi)
{
    if(bha==0 && *abhi%2==0)
        *abhi=4;
    if(bha==8 && *abhi%2==1)
        *abhi=3;

}




int execute(int &x, int &y, int i ,int p)
{
    int s=0;
    switch(p)
    {
    case 1:
        {
            if(a[x-1][y-1]==0)
            {
                check(x-1,&i);
                a[x-1][y-1]=i;
                a[x][y]=0; x=x-1;y=y-1;
                return 0;
            }

            if(a[x-1][y-1]!=0)
            {

                check(x-2,&i);
                a[x-2][y-2]=i;
                a[x-1][y-1]=0;
                a[x][y]=0;x=x-2;y=y-2;++s;removee(i);
            }
        return s;
        }

      case 2:
        {
            if(a[x-1][y+1]==0)
            {
                check(x-1,&i);
                a[x-1][y+1]=i;
                a[x][y]=0; x=x-1;y=y+1;
                return 0;
            }

            if(a[x-1][y+1]!=0)
            {
                check(x-2,&i);
                a[x-2][y+2]=i;
                a[x-1][y+1]=0;
                a[x][y]=0;x=x-2;y=y+2;
            ++s;removee(i);
            }
        return s;
        }

   case 3:
        {
            if(a[x+1][y-1]==0)
            {
                check(x+1,&i);
                a[x+1][y-1]=i;
                a[x][y]=0; x=x+1;y=y-1;
                return 0;
            }

            if(a[x+1][y-1]!=0)
            {   check(x+2,&i);
                a[x+2][y-2]=i;
                a[x+1][y-1]=0;
                a[x][y]=0;  x=x+2;y=y-2;
                ++s;removee(i);

            }
            return s;
        }
 case 4:
        {
            if(a[x+1][y+1]==0)
            {   check(x+1,&i);
                a[x+1][y+1]=i;
                a[x][y]=0;  x=x+1;y=y+1;
                return 0;
            }

            if(a[x+1][y+1]!=0)
            {
                check(x+2,&i);
                a[x+2][y+2]=i;
                a[x+1][y+1]=0;
                a[x][y]=0;  x=x+2;y=y+2;
                ++s;removee(i);
            }
            return s;
        }
}


return 1;
}



int checker(int x, int y, int i,int &p,int&q,int&r,int&s)
{
    p=1;q=2;r=3;s=4;

      if(a[x][y]==1)
    {
      p=0;
      q=0;
    }

    if(a[x][y]==2)
    {
        r=0;
        s=0;
    }

    if((x==0)||(y==0)||(a[x-1][y-1]==i) || ((a[x-1][y-1]!=0) && (a[x-2][y-2]!=0))  || (  (a[x-1][y-1]!=0) && ((x-2)<0||(y-2)<0 )  )  ||(a[x-1][y-1]==0) )
        {p=0;}

        if((x==0)||(y==7)||(a[x-1][y+1]==i) || ((a[x-1][y+1]!=0) && (a[x-2][y+2]!=0))  || ((a[x-1][y+1]!=0) && ((x-2)<0||(y+2)<0 ) )  ||(a[x-1][y+1]==0) )
            {q=0;}

        if((x==7)||(y==0)||(a[x+1][y-1]==i) || ((a[x+1][y-1]!=0) && (a[x+2][y-2]!=0))  || ((a[x+1][y-1]!=0) && ((x+2)<0||(y-2)<0 ) )   ||(a[x+1][y-1]==0))
        {r=0;}

        if((x==7)||(y==7)||(a[x+1][y+1]==i) || ((a[x+1][y+1]!=0) && (a[x+2][y+2]!=0))  || ((a[x+1][y+1]!=0) && ((x+2)<0||(y+2)<0 ) )   ||(a[x+1][y+1]==0))
        {s=0;}


        if((p||q||r||s)==0)
            return 0;

        return 1;

}







int command2(int x,int y,int i,int l=0)
{


    int nn=0;
    int p=1,q=2,r=3,s=4;

     if(l==1)
    {
        checker(x,y,i,p,q,r,s);
        cout<<p<<endl<<q<<endl<<r<<endl<<s;
        goto ab;
    }


    if(a[x][y]==1)
    {
      p=0;
      q=0;
    }

    if(a[x][y]==2)
    {
        r=0;
        s=0;
    }




    if((x==0)||(y==0)||(a[x-1][y-1]==i) || ((a[x-1][y-1]!=0) && (a[x-2][y-2]!=0))  || (  (a[x-1][y-1]!=0) && ((x-2)<0||(y-2)<0 )  )    )
        {p=0;}

        if((x==0)||(y==7)||(a[x-1][y+1]==i) || ((a[x-1][y+1]!=0) && (a[x-2][y+2]!=0))  || ((a[x-1][y+1]!=0) && ((x-2)<0||(y+2)<0 ) )   )
            {q=0;}

        if((x==7)||(y==0)||(a[x+1][y-1]==i) || ((a[x+1][y-1]!=0) && (a[x+2][y-2]!=0))  || ((a[x+1][y-1]!=0) && ((x+2)<0||(y-2)<0 ) )   )
        {r=0;}

        if((x==7)||(y==7)||(a[x+1][y+1]==i) || ((a[x+1][y+1]!=0) && (a[x+2][y+2]!=0))  || ((a[x+1][y+1]!=0) && ((x+2)<0||(y+2)<0 ) )   )
        {s=0;}

        cout<<endl<<p<<endl<<q<<endl<<r<<endl<<s<<endl;
        if((p||q||r||s)==0) return 0;



ab:
    int j;
    cin>>j;
int we;



    switch(j)
    {
    case 1:
        if(p==0)
            goto ab;
         we=execute(x,y,a[x][y],1);


        if(we==1)
            {
                if(checker(x,y,i,p,q,r,s))
                {
                    cout<<endl<<p<<endl<<q<<endl<<r<<endl<<s;
                    goto ab;
                }
                else
                    return 1;
            }


        break;

    case 2:
        if(q==0)
            goto ab;
       we= execute(x,y,a[x][y],2);


     if(we==1)
            {
                if(checker(x,y,i,p,q,r,s))
                {
                    cout<<p<<endl<<q<<endl<<r<<endl<<s;
                    goto ab;
                }
                else
                    return 1;
            }


        break;

    case 3:
        if(r==0)
            goto ab;
        we=execute(x,y,a[x][y],3);


      if(we==1)
            {
                if(checker(x,y,i,p,q,r,s))
                {
                    cout<<p<<endl<<q<<endl<<r<<endl<<s;
                    goto ab;
                }
                else
                    return 1;
            }



        break;

    case 4:
        if(s==0)
            goto ab;
        we=execute(x,y,a[x][y],4);

      if(we==1)
            {
                if(checker(x,y,i,p,q,r,s))
                {
                    cout<<p<<endl<<q<<endl<<r<<endl<<s;
                    goto ab;
                }
                else
                    return 1;

            }


        break;

    case 5:
        return 0;


    return 1;
    }
}




int player(int i)
{   ab:
    int d;
    cin>>d;
    if(!(command(d/10,d%10,i)))
    {   cout<<" WRONG MOVE ";
        goto ab;
    }
    else
       if( !command2(d/10,d%10,i,0))
       {   cout<<"\n BACK TO RE-CHOOSE ";
           goto ab;
       }
    return 0;
}


int game(int i)
{   static int cp[12];
int    d=-1;
    int p=1,q=2,re=3,se=4;
    for(int r=0;r<8;r++)
    {   p=1;q=2;re=3;se=4;
        for(int s=0;s<8;s++)
        {
            if(a[r][s]==i)
            {
                if(checker(r,s,i,p,q,re,se))
                {   ++d;
                    cp[d]=(r*10+s);
                    cout<<endl<<cp[d];
                }
            }
        }
    }
    if(d==-1)
    return 0;
    red:
    int n;
    cin>>n;
    for(int r=0;r<=d;r++)
    {
        if(n==cp[r])
        {   command2(n/10,n%10,i,1);
            return 1;
        }
    }
    goto red;
    return 0;
}

int main()
{   inital();
while(players[0]&&players[1])
{
    cout<<endl<<players[0]<<endl<<players[1];
    bb:
    display();
    if(game(1))
        goto ab;
        player(1);
    ab:
        display();
        if(game(2))
        goto bb;
    player(2);
 }

 if(players[0]>players[1])
    cout<<players[0]<<"WON THE GAME ";
 else cout<<players[1]<<"WON THE GAME ";

return 0;
}
