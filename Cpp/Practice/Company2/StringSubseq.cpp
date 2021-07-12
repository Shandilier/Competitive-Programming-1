#include <bits/stdc++.h>
#define MAX 10000
#define CHAR_SIZE 26
using namespace std;
 
// Precompute the position of each character from
// each position of String S
void precompute(int mat[MAX][CHAR_SIZE], char str[],
                                           int len)
{
    for (int i = 0; i < CHAR_SIZE; ++i)
        mat[len][i] = len;
 
    // Computing position of each character from
    // each position of String S
    for (int i = len-1; i >= 0; --i)
    {
        for (int j = 0; j < CHAR_SIZE; ++j)
            mat[i][j] = mat[i+1][j];
 
        mat[i][str[i]-'a'] = i;
    }
}
 
// Print "Yes" if T is subsequence of S, else "No"
bool query(int mat[MAX][CHAR_SIZE], const char *str, 
                                          int len)
{
    int pos = 0;
 
    // Traversing the string T
    for (int i = 0; i < strlen(str); ++i)
    {
        // If next position is greater than 
        // length of S set flag to false.
        if (mat[pos][str[i] - 'a'] >= len)
            return false;
 
        // Setting position of next character
        else
            pos = mat[pos][str[i] - 'a'] + 1;
    }
    return true;
}
// Driven Program
int main()
{
    char S[]= "geeksforgeeks";
    int len = strlen(S);
 
    int mat[MAX][CHAR_SIZE];
    precompute(mat, S, len);
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<26;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
 
    query(mat, "gg", len)?  cout << "Yes\n" :
                            cout << "No\n";
    query(mat, "gro", len)? cout << "Yes\n" :
                            cout << "No\n";
    query(mat, "gfg", len)? cout << "Yes\n" :
                            cout << "No\n";
    query(mat, "orf", len)? cout << "Yes\n" :
                            cout << "No\n";
    return 0;
}