/*
 * Elliptic_Curve.cpp
 *
 *  Created on: 03-Dec-2021
 *      Author: Ayub Shaikh
 */


#include<iostream>
#include<math.h>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
	int n,p;
	cout<<" ************************************************************************** \n\n";
	cout<<"-------Assignment-3 Submitted by Roll number: CS21M515 **** AYUB SHAIKH IIT Madras  \n\n";
	cout<<"ElGamal Elliptic Curve Cryptography by \nName - AYUB SHAIKH - CS21M515 \n\n";

	cout<<"\n *************************************************************** :\n";
	cout<<"Elliptic Curve General Form \t y^2 mod p = (x^3  + A*x + B) mod p \n";
	cout<<"\n *************************************************************** :\n";
	cout<<"Enter the value of P: \n";
	cin>>p;
	n = p;
	int LHS[2][n],RHS[2][n],a,b,i,j;

	cout<<"\nEnter the Value of a: \n";
	cin>>a;
	cout<<"\nEnter the Value of b: \n";
	cin>>b;
	cout<<"\n **************************************************************************************************:\n";
	cout<<"\nCurrent Elliptic Curve \t\t ---> y^2 mod "<<p<<" = (x^3  + "<<a<<"*x + "<<b<<") mod "<<p<<"\n\n";
	cout<<"\n **************************************************************************************************:\n";
	vector <int> arr_x;
	vector <int> arr_y;

// Equating LHS and RHS as per arbitrary index to generate range of values.
	for(int i = 0; i <	 n; i++)
	{
		LHS[0][i] = i;
		RHS[0][i] = i;
		LHS[1][i] = ((i*i*i) + a*i + b) % p;
		RHS[1][i] = (i*i) % p;
	}


// Generating Base Points
int in_c = 0;
	for(i = 0; i < n; i ++)
	{

		for(j = 0; j < n; j++)
		{
			if(LHS[1][i] == RHS[1][j])
			{
						in_c++;
					arr_x.push_back(LHS[0][i]);
					arr_y.push_back(RHS[0][j]);
			}
		}
	}

	cout<<endl<<"Generated Points are:"<<endl;

	for(i =0; i < in_c; i++)
	{
		cout<<i+1<<"\t( "<<arr_x[i]<<" , "<<arr_y[i]<<" )"<<endl;
	}
	cout<<"Base Point: ("<<arr_x[0]<<","<<arr_y[0]<<")"<<"\n";
	int k,d,Message , exit;
	cout<<"Enter the random number 'd' i.e. Private key of Sender  (d<n)\n";
	cin>>d;
	int Qx=d*arr_x[0];
	int Qy=d*arr_y[0];
	//Q is the public key of sender


	//Encryption
	 cout<<"*********************Encryption ******************\n";
    cout<<"Enter the random number 'k' (k<n)\n";
	cin>>k;

    cout<<"Enter the message to be sent:=>";
	cin>>Message;
	cout<<"The message to be sent is:\n"<<Message<<"\n";

	int c1x=k*arr_x[0];
	int c1y=k*arr_y[0];
	cout<<"Value of C1: ("<<c1x<<","<<c1y<<")"<<"\n";

	int c2x=k*Qx+Message;
	int c2y=k*Qy+Message;
	cout<<"Value of C2: ("<<c2x<<","<<c2y<<")"<<"\n";

	//Decryption
	cout<<"\n *************************************************** :";
	cout<<"\n *******Decryption Of message is******** :";
	cout<<"\n *************************************************** :\n";

	cout<<"Entering the Values of C1: ("<<c1x<<","<<c1y<<") to Decryption process"<<"\n";
	cout<<" Entering Value of C2: ("<<c2x<<","<<c2y<<") to Decryption process"<<"\n";




	cout<<"\n The Decryptioned message received is: ";
	int Mx=c2x-d*c1x;
	int My=c2y-d*c1y;
	cout<< Mx <<"\n";

	cout<<"Please Enter any text to exit:\n";
		cin>>exit;
}
