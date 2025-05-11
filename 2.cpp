#include<iostream>
using namespace std;

void right_M(char arr[], int &index,int arr2[],int &ind)   // to move right 
{
	cout << "enter how much you want to move robert " << endl;

	int m;
	cin >> m;          // how much to move right 

	if (index + m < 9 and arr[index+m] == '-')     //validaton to check the code is within the limmit 
	{
		arr[index + m] = arr[index];

		arr[index] = '-';

		index += m;

		cout << "the robot moved right by " << m << "cells " << endl;

		arr2[ind] = index;    // updating the movve storing array 

		ind++;
	}
	else
		cout << "out of boundry attempt robot is at same position" <<  endl;      // in case when righ movement does not executes
	
}
void left_M(char arr[], int &index,int arr2[],int &ind)      // left movement function
{
	cout << "enter how much you want to move robert" << endl;

	int m;          // no of movemnet 

	cin >> m;

	if (index - m >= 0 and arr[index-m]=='-')      // limitation conditins 
	{
		arr[index - m] = arr[index];

		arr[index] = '-';

		index -= m;

		cout << "the robot moved left by " << m << "cells " << endl;

		arr2[ind] = index;   //updating the index storing array 

		ind++;
	}
	else
	cout << "out of boundry attempt robot is at  same position" <<  endl;

	
}
void display(char arr[], int &index,int &index2)// just to display the index in which both robots are right now 
{

	cout << "The robot one is at the index " << index << " and the robot 2 is at the index " << index2;
}

void reboot(char arr[], int &index,int arr2[],int &ind ,int &index2,int arr3[],int &ind2)// reboot to the positon where started 
{
	index = 0;

	index2 = 1;                    // every thing is reinilitized to the back 

	arr[0] = 'R';

	arr[1] = 'r';

	for (int i = 2; i < 9; i++)
	{
		arr[i] = '-';
	}
	ind = 1;

	ind2 = 1;

	arr2[ind++] = index;
	                               // index storing arrays of the robers are also rebboted 
	arr3[ind2++] = index2;

}
void show_grid(char arr[])       // just to show the grid  
{
	cout << "------------------" << endl;

	for (int i = 0; i < 9; i++)
	{
		
		cout << arr[i] << "|";
	
	}
	cout << "\n------------------" << endl;

}
void cancel(char arr[], int& index, int arr2[], int& ind ,int & movemet_cancle)     // cancel the last n movement of the robots 
{
	int robotcancel_choice;

	cout << "enter the commonds you want to cancel ";

	cin >> robotcancel_choice;

	if (robotcancel_choice >= ind  or robotcancel_choice <=0)
	{
		cout << "no command is canceled out of range ";

		return;
	}
	if (movemet_cancle == 1)     // if robot is 1 one than this will work 
	{
		int nindex = arr2[ind - robotcancel_choice - 1];

		arr[index] = '-';

		arr[nindex] = 'R';

		ind = ind - robotcancel_choice;

		index = nindex;

		cout << "\nthe last " << robotcancel_choice << "commands are canceled ";
	}
	if (movemet_cancle == 2)  // if the robot is second one ths will work 
	{
		int nindex = arr2[ind - robotcancel_choice - 1];

		arr[index] = '-';

		arr[nindex] = 'r';

		ind = ind - robotcancel_choice;

		index = nindex;

		cout << "\nthe last " << robotcancel_choice << "commands are canceled ";
	}

	
}

int main()
{
	char arr[10] = { 'R','r','-' ,'-' ,'-' ,'-' ,'-' ,'-' ,'-','\0'};      // at the start of the program the array is initilazed with the values so that the wll be updated
	                                                                     /// from here 

	int index = 0;

	int index2 = 1;

	int arr2[100] = { 0 };

	int arr3[100] = { 1 };

	int ind = 1,ind2=1;
	int a;
	
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "                           WELCOME TO ROBERTS MOVEMENT GAME                        "<< endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	while (true)
	{
		cout << "\ncontroller menu" << endl;

		cout << "1 right " << endl;

		cout << "2 left " << endl;

		cout << "3 display " << endl;

		cout << "4 reboot " << endl;

		cout << "5 show aray" << endl;

		cout << "6 cancel " << endl;

		cout << "7 exit " << endl;

		cout << "Enter your choice " << endl;

		cin >> a;
		if (a == 1)                                                // if one move rihght 
		{
			cout << "which robot you want to move " << endl;

			int robot_option_R;

			cin >> robot_option_R;
			 
			if (robot_option_R == 1)               // R 1       
			{
				right_M(arr, index, arr2, ind);
			}

			else if (robot_option_R == 2)        // R2
			{
				right_M(arr, index2, arr3, ind2);
			}
		}


		if (a == 2)          // move left 
		{
			cout << "which robot you want to move " << endl;
			int robot_option_l;

			cin >> robot_option_l;

			if (robot_option_l == 1)            //robot 1
			{
				left_M(arr, index, arr2, ind);
			}

			else if (robot_option_l == 2)       // robot 2
			{
				left_M(arr, index2, arr3, ind2);
			}
		}

		if (a == 3)
		{
			
		 display(arr, index,index2);
		}

		if (a == 4)
		{
			reboot(arr, index, arr2, ind,index2,arr3,ind2);
		}

		if (a == 5)
		{
			show_grid(arr);
		}

		if (a == 6)
		{
			cout << "which robert commands you want to cancel  " << endl;
			int movemet_cancle;

			cin >> movemet_cancle;

			if (movemet_cancle == 1)// cancel commands of robit 1
			{
				cancel(arr, index, arr2, ind, movemet_cancle);
			}
			else if(movemet_cancle ==2)           // cancel comands fo robot 2
				cancel(arr, index2, arr3, ind2, movemet_cancle);
		}
		if (a == 7)
		{
			cout << "EXIt ! successfully";

			break;
		}


	}
	return 0;
}
