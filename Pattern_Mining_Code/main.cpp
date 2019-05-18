#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>


using namespace std;
unordered_map<int,vector<int>> mymap;
unordered_map<int,vector<int>>::const_iterator got;
unordered_map<string,int> mymapp;
unordered_map<int,string> intmap;
unordered_map<::string,int>::const_iterator gott;

#define structure map<vector<int>, int>
#define structure2 map<int,vector<int>>
#define FOR_MAP(ii,T) for(structure::iterator (ii)=(T).begin();(ii)!=(T).end();(ii)++)
#define FOR_next_MAP(jj,ii,T) for(structure::iterator (jj)=(ii);(jj)!=(T).end();(jj)++)
#define VI vector<int>
#define FOR_MAP2(mm,M) for(structure2::iterator (mm)=(M).begin();(mm)!=(M).end();(mm)++)
#define FOR_next_MAP2(nn,mm,T) for(structure2::iterator (nn)=(mm);(nn)!=(T).end();(nn)++)

structure2 M;
structure C;
structure L;


void C1();
void L1();
void generate_C();
void generate_L();
void output(structure, string);
void scan_D();
void prune();
bool check_compatibility(VI ,VI );
void set_count();
vector<int> intersection(vector<int> &v1, vector<int> &v2);


ofstream outf;
int MIN_SUP=10;
int k=2;
int main(int argc, char const *argv[])
{
    string filen, outfil;

    MIN_SUP = atoi(argv[1]);
    k = atoi(argv[2]);
    filen = argv[3];
    outfil = argv[4];
    /*string ipath;
    string opath;


    cout<<"minimum support=\t";
	cin>>MIN_SUP;
	cout<<"\n K value=\t";
	cin>>k;
	cout<<"\n  input_transaction_file_path=\t";
	cin.ignore();
    getline(cin,ipath);
	cout<<"\n output_file_path=\t";
	cin.ignore();
    getline(cin,opath);*/


   	ifstream infile(filen); //change this line
   	ofstream outfile("input2.txt");


    string line;

    int k=1;
    while (getline(infile, line))
    {
        istringstream iss(line);
        string token;

        while (iss >> token)
        {
            unordered_map<::string,int>::const_iterator gott = mymapp.find (token);

           if ( gott == mymapp.end() )
            {

                     outfile << k; outfile << " ";
                     mymapp.insert(make_pair(token,k));
                     intmap.insert(make_pair(k,token));
                     //cout<< token<<" "<<k<<endl;
                     k++;

            }

            else
            {
                    auto str=mymapp.find(token);
                    mymapp.insert(make_pair(token,str->second));
                    intmap.insert(make_pair(str->second,token));
                    outfile << str->second; outfile << " ";
                    //cout<<token<<" "<<str->second<<" ";


            }


          }

         outfile << -1; outfile << " ";
       }


    C.clear();
	L.clear();
    M.clear();
	bool mv=true;
	int index=2;
	while(true)
	{
		if (mv)
		{
			C1();
			//cout<<"C1\n";
			//output(C);

			L1();
			//cout<<"L1\n";

			output(L, outfil);


			mv=!mv;
		}else
		{

			generate_C();

			if(C.size()==0)
				break;
			//cout<<"\nC"<<index<<"\n";
			//output(C);

                 prune();

			if (C.size()==0)
			{
				break;
			}
			//cout<<"\nC"<<index<<" after prune \n";
			//output(C);

			set_count();

			//cout<<"\nC"<<index<<"after scaning dataset \n";
            //output(C);
			generate_L();
			if (L.size()==0)
			{
				break;
			}
			cout<<"\nL"<<index<<"\n";
			output(L, outfil);
			index++;
		}
	}
	return 0;
}


void C1()
{
	ifstream fin; VI d; int linenumber=1;
	fin.open("input2.txt"); VI B;
	int g;VI v;int n;

	   while(fin>>g)
       {
            v.clear();



         if(g==-1){ linenumber++;continue;}

          v.push_back(g);

         if(C.count(v)>0)
		  {
		    C[v]++;
unordered_map<int,vector<int>>::const_iterator got = mymap.find(g);
			   if(got!=mymap.end())
			   {
			       auto str=mymap.find(g);
                   B=str->second;
			       B.push_back(linenumber);
                   mymap[g]=B;
			   }

		B.clear();
       }
		else
			{C[v]=1;
			unordered_map<int,vector<int>>::const_iterator got = mymap.find(g);

			if(got==mymap.end())
			 {d.push_back(linenumber);
			mymap.insert(std::make_pair(g,d));

			 }
			}

        d.clear();
    }
	fin.close();


	/*int i=1;
	VI d; int linenumber=1;

	while(i<=r)
    {  fin.open("input2.txt");

        d.clear(); linenumber=1;

	    while(fin>>n)
        {

		if (n==-1)
		{
			linenumber++;
			continue;
		}


            if(n==i)
		    {
		     d.push_back(linenumber);


        }


        }

       M.insert(std::make_pair(i,d));

       i++;
       fin.close();


	}*/

//fin.close();
/*VI q;
FOR_MAP2(mm,M)
{
cout<<endl;
q=mm->second;
cout<<mm->first;
for(int k=0;k<q.size();k++)
{
cout<<" "<<q[k];

}

}*/
}
void output(structure T, string s)
{
    outf.open (s, ios_base::app);
	//ofstream ff(opath);

	//outf<<"\n";
	VI v;
	FOR_MAP(ii,T)
	{
		v.clear();
		v=ii->first;

		  if(v.size()>=k)
        {


		for (int i = 0; i < v.size(); ++i)
		  {

            auto str=intmap.find(v[i]);
		    outf<<str->second<<" ";
             string s=str->second;
             //ff << s; ff << " ";
		  }

		  outf<<"("<<ii->second<<")";
		 outf<<"\n";
        int m=ii->second;
        // ff << "(";   ff << m; ff << ")"; ff << endl;

        }
	}

	outf.close();
}

void L1()
{

	FOR_MAP(ii,C)
	{
		if (ii->second >= MIN_SUP)
		{
			L[ii->first]=ii->second;
		}
	}

}

void generate_C()
{
	//clean(C);
	C.clear();

	FOR_MAP(ii,L)
	{
		FOR_next_MAP(jj,ii,L)
		{
			if(jj==ii)
				continue;
			VI a,b;
			a.clear();
			b.clear();
			a=ii->first;
			b=jj->first;
			bool compatible=true;
			for (int i = 0; i < a.size()-1; ++i)
	        {
		     if (a[i]!=b[i])
		      {
			  compatible=false;
			  break;
		      }
	       }

			if(compatible)
			{
				a.push_back(b.back());
				//sort(a.begin(), a.end());
				C[a]=0;
			}
		}

	}


}



void prune()
{
	VI a,b,v;

	FOR_MAP(ii,C)
	{
		a.clear();
		b.clear();
        v.clear();
        v=ii->first;
        if(v.size()>2)
		{
		    a=ii->first;
		for(int i = 0;i<a.size();i++)
		{
			b.clear();
			for (int j = 0; j < a.size(); ++j)
			{
				if(j==i)
					continue;
				b.push_back(a[j]);
			}
			if(L.find(b)==L.end())
				{
					ii->second=-1;
					break;
				}

		}
	 }

	}

	structure temp;
	temp.clear();
	FOR_MAP(ii,C)
	{
		if (ii->second != -1)
		{
			temp[ii->first]=ii->second;
		}
	}

	C.clear();
	C=temp;
	temp.clear();

}



void set_count()
{   VI B,Y,v;
	FOR_MAP(ii,C)
	{

	    v=ii->first;

		for(int i=0;i<v.size();i++)
             {
                  unordered_map<int,vector<int>>::const_iterator got = mymap.find(v[i]);

                   if(got!=mymap.end())
                    {
                        auto str=mymap.find(v[i]);

                        if(i==0)
                      {
                        B=str->second;
                        auto v3 = intersection(B, B);
                         Y.clear();
                        for(int L : v3)
                        Y.push_back(L);
                         B.clear();
                         //break;
                        }

                     else
                        {
                        B=str->second;
                        auto v3 = intersection(B, Y);
                         Y.clear();
                        for(int L : v3)
                        Y.push_back(L);
                        B.clear();
                        //break;
                     }
                 }



			}


        v.clear();
		if (Y.size()>=MIN_SUP)
		{
			ii->second=Y.size();
		}
	}
}

vector<int> intersection(vector<int> &v1, vector<int> &v2)
{

    vector<int> v3;

    //sort(v1.begin(), v1.end());
    //sort(v2.begin(), v2.end());

    set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));



return v3;
}





void generate_L()
{
	L.clear();

	FOR_MAP(ii,C)
	{
		if(ii->second >= MIN_SUP)
		{
			L[ii->first]=ii->second;
		}
	}
}
