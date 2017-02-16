/*
 * PA1.cpp
 *
 *  Created on: Feb 2, 2017
 *      Author: Miranda-Ferguson
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main(){

	int magic[15][15]; //initiates an array with 15^2 values to prevent large inputs
	int x;
	int sum;
	int even = 0;




	cout << "INPUT>>Enter the size of an odd magic square: " << endl;
	cin >> x; //takes user input to determine magic square
	even = x%2;



	// ensure that the number is between 3 and 15 and is odd
	while(x < 3 || x > 15 || even <= 0){
		cout << "INPUT>>Please enter a valid value: " << endl;
		cin >> x;
		even = x%2;
	}


	//initialize all array values to 0
	for (int r=0; r < x ; r++){
		for (int c = 0; c < x ; c++){
			magic[r][c] = 0;
		}
	}



	//magic square constant M=x(x^2+1)/2
	int temp = x*x;
	temp++;
	temp = temp*x;
	temp = temp/2;
	sum = temp; //all rows, cols., and diags. need to equal this


	//all nums in magic square must be 1 < num < x^2
	cout << "OUTPUT>>Magic square constant: " << sum << endl << endl;


	//odd order magic squares

	//algorithm
	//1) number 1 goes in middle bottom row
	//2) move one col. to right and one row down
	//3) if row is below bottom row, keep same col. and place num in top row
	//4)if col. is more than right col., keep row and place num in first col.
	//5) if square is filled, move one row down with col. to left
	//6) if both row and col. are out of bounds, place below last num



	int row = x-1; //last row of square
	int col = x/2; //middle box
	magic[row][col] = 1;  //assign 1 to the middle col. of last row (algorithm)


	    //numbers that can be assigned range from 2 to x^2
		for (int i = 2; i <= x*x; i++) {

		   //if the generated location is unassigned
		   if (magic[(row + 1) % x][(col + 1) % x] == 0) {

		      row = (row + 1) % x; //one row down from last location
		      col = (col + 1) % x; //one col. right from last location

		    }

		   //if position is otherwise taken
		    else {

		      row = (row - 1 + x) % x;

		     }

		  //assign number to array
		  magic[row][col] = i;

		 }



	//print array
	cout << "OUTPUT>>Magic Square #1" << " :";
	cout << endl;

	//move through array rows
	for (int r=0; r < x ; r++){

		//move through array cols.
		for (int c = 0; c < x ; c++){

			//print array integer
			cout << magic[r][c] << " ";
		}

	cout << endl;

	}


	//rows
	cout << "OUTPUT>>Checking the sums of every row: ";

	int tempRowSum = 0;

		for(int r = 0; r < x; r ++){

			for(int c = 0; c < x; c++){

				tempRowSum += magic[r][c];

			}

		cout << tempRowSum << " ";
		tempRowSum = 0;

	}



	//cols.
	cout << endl;
	cout << "OUTPUT>>Checking the sums of every column: ";

	int tempColSum = 0;

		for(int c = 0; c < x; c ++){

			for(int r = 0; r < x; r++){

				tempColSum += magic[r][c];

			}

		cout << tempColSum << " ";
		tempColSum = 0;

	}



	//diags.
	cout << endl;
	cout << "OUTPUT>>Checking the sums of every diagonal: ";

	int tempDiagSum = 0;

	for(int r = 0; r < x; r ++){

		tempDiagSum += magic[r][r];

	}

	cout << tempDiagSum << " ";

	int diagSum = 0;

	for(int r = 0; r < x; r ++){

		int c = x-r-1;

		if(c > -1){

			diagSum += magic[r][c];

		}
	}

	cout << diagSum;
	cout << endl << endl;


	//magic square requirements are still met if the square is shifted
	//i.e. certain numbers must stay together, but rows/cols. can be moved

	//reversing rows
	int tempVal = 0;
	int count = x-1;

	for(int r = 0; r < x; r++){
		for(int c = 0; c < x/2; c++){
			tempVal = magic[r][c];
			magic[r][c] = magic[r][count];
			magic[r][count] = tempVal;
			count--;
		}
		count = x-1;
	}

	//print array
		cout << "OUTPUT>>Magic Square #2" << " :";
		cout << endl;

		//move through array rows
		for (int r=0; r < x ; r++){

			//move through array cols.
			for (int c = 0; c < x ; c++){

				//print array integer
				cout << magic[r][c] << " ";
			}

		cout << endl;

		}


		//rows
		cout << "OUTPUT>>Checking the sums of every row: ";

		tempRowSum = 0;

			for(int r = 0; r < x; r ++){

				for(int c = 0; c < x; c++){

					tempRowSum += magic[r][c];

				}

			cout << tempRowSum << " ";
			tempRowSum = 0;

		}



		//cols.
		cout << endl;
		cout << "OUTPUT>>Checking the sums of every column: ";

		tempColSum = 0;

			for(int c = 0; c < x; c ++){

				for(int r = 0; r < x; r++){

					tempColSum += magic[r][c];

				}

			cout << tempColSum << " ";
			tempColSum = 0;

		}



		//diags.
		cout << endl;
		cout << "OUTPUT>>Checking the sums of every diagonal: ";

		tempDiagSum = 0;

		for(int r = 0; r < x; r ++){

			tempDiagSum += magic[r][r];

		}

		cout << tempDiagSum << " ";

		diagSum = 0;

		for(int r = 0; r < x; r ++){

			int c = x-r-1;

			if(c > -1){

				diagSum += magic[r][c];

			}
		}

		cout << diagSum;
		cout << endl << endl;


	//switch cols. to rows and rows to cols.

		tempVal = 0;

		int magic2[x][x];
		for(int r = 0; r < x; r++){
			for(int c = 0; c < x; c++){
				magic2[r][c] = 0;
			}
		}

		 for(int r = 0; r < x; r++){
		        for(int c = x-1; c >= 0; c--){
		            magic2[r][c] = magic[c][r];
		        }
		    }

		 for(int r = 0; r < x; r++){
		 			for(int c = 0; c < x; c++){
		 				magic[r][c] = magic2[r][c];
		 			}
		 		}



		//print array
			cout << "OUTPUT>>Magic Square #3" << " :";
			cout << endl;

			//move through array rows
			for (int r=0; r < x ; r++){

				//move through array cols.
				for (int c = 0; c < x ; c++){

					//print array integer
					cout << magic[r][c] << " ";
				}

			cout << endl;

			}


			//rows
			cout << "OUTPUT>>Checking the sums of every row: ";

			tempRowSum = 0;

				for(int r = 0; r < x; r ++){

					for(int c = 0; c < x; c++){

						tempRowSum += magic[r][c];

					}

				cout << tempRowSum << " ";
				tempRowSum = 0;

			}



			//cols.
			cout << endl;
			cout << "OUTPUT>>Checking the sums of every column: ";

			tempColSum = 0;

				for(int c = 0; c < x; c ++){

					for(int r = 0; r < x; r++){

						tempColSum += magic[r][c];

					}

				cout << tempColSum << " ";
				tempColSum = 0;

			}



			//diags.
			cout << endl;
			cout << "OUTPUT>>Checking the sums of every diagonal: ";

			tempDiagSum = 0;

			for(int r = 0; r < x; r ++){

				tempDiagSum += magic[r][r];

			}

			cout << tempDiagSum << " ";

			diagSum = 0;

			for(int r = 0; r < x; r ++){

				int c = x-r-1;

				if(c > -1){

					diagSum += magic[r][c];

				}
			}

			cout << diagSum;
			cout << endl << endl;



	//switch oppposite values again

	tempVal = 0;
	count = x-1;

	for(int r = 0; r < x; r++){

		for(int c = 0; c < x/2; c++){

			tempVal = magic[r][c];
			magic[r][c] = magic[r][count];
			magic[r][count] = tempVal;
			count--;

		}

		count = x-1;

	}





			//print array
				cout << "OUTPUT>>Magic Square #4" << " :";
				cout << endl;

				//move through array rows
				for (int r=0; r < x ; r++){

					//move through array cols.
					for (int c = 0; c < x ; c++){

						//print array integer
						cout << magic[r][c] << " ";
					}

				cout << endl;

				}


				//rows
				cout << "OUTPUT>>Checking the sums of every row: ";

				tempRowSum = 0;

					for(int r = 0; r < x; r ++){

						for(int c = 0; c < x; c++){

							tempRowSum += magic[r][c];

						}

					cout << tempRowSum << " ";
					tempRowSum = 0;

				}



				//cols.
				cout << endl;
				cout << "OUTPUT>>Checking the sums of every column: ";

				tempColSum = 0;

					for(int c = 0; c < x; c ++){

						for(int r = 0; r < x; r++){

							tempColSum += magic[r][c];

						}

					cout << tempColSum << " ";
					tempColSum = 0;

				}



				//diags.
				cout << endl;
				cout << "OUTPUT>>Checking the sums of every diagonal: ";

				tempDiagSum = 0;

				for(int r = 0; r < x; r ++){

					tempDiagSum += magic[r][r];

				}

				cout << tempDiagSum << " ";

				diagSum = 0;

				for(int r = 0; r < x; r ++){

					int c = x-r-1;

					if(c > -1){

						diagSum += magic[r][c];

					}
				}

				cout << diagSum;
				cout << endl << endl;



}
