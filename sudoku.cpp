#include <bits/stdc++.h>
using namespace std;


#define ll long long
//declaring a vector of maps that store numbers filled in a every row

vector<map<ll,ll> > rows{};
//declaring a vector of maps that store numbers filled in a every column

vector<map<ll,ll> > cols{};

//declaring a vector of maps that store numbers filled in a every sub matrix of size 3*3
vector<map<ll,ll> > squares{};

//recursive function for solving sudoku
bool sudoku(vector<vector<char> > &A){
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){

            //we check if the cell is filled or not
            if(A[i][j] == '.'){
                for(int h = 1;h<10;h++){
                    int x1 = 3*(i/3) + j/3;
                    if(rows[i][h] != 1 && (cols[j][h] != 1 && squares[x1][h] != 1)){
                        rows[i][h] = 1;
                        cols[j][h] = 1;
                        squares[x1][h] = 1;
                        A[i][j] = (h +'0');
                        if(sudoku(A)) return true;
                        else{
                            A[i][j] = '.';
                            rows[i][h] = 0;
                            cols[j][h] = 0;
                            squares[x1][h] = 0;
                        }
                    }

                }
                //we do not found any number satisfying the present position based on the filling of previous places. So, we backtrack.
                return false;
            }
        }
    }
    //we completed the traversal and every place is filled as per the rules.
    return true;
}
int main() {
    //declaring a vector of vector of characters to store the sudoku.
    vector<vector<char> > vec(9,vector<char>(9));

    //taking input from the user
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cin>>vec[i][j];
        }
    }

    //cleaning unwanted memory and resizing the global vectors declared above
    rows.clear(); rows.resize(9);
    cols.clear(); cols.resize(9);
    squares.clear(); squares.resize(9);

    //filling the corresponding rows,columns and sub matrices with the given filled values
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(vec[i][j] != '.'){
                //index of the sub matrix starting from top left going along row-wise
                int x = 3*(i/3) + j/3;
                rows[i][vec[i][j] - '0'] = 1;
                cols[j][vec[i][j] - '0'] = 1;
                squares[x][vec[i][j] - '0'] = 1;
            }
        }
    }

    //calling the recursive function sudoku

    bool ans = sudoku(vec);


    //printing the completed sudoku
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }

}
