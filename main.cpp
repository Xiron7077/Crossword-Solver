#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool scan(const string& word, string dict[], int s)
{
    for(int i = 0; i < s; i++)
    {
        if(dict[i] == word)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string word, exist[5000], cord[5000][4];
    string fline, dict[5000];
    ifstream file("include/wordlist.txt");
    int rows, columns, count = 0, s = 0;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> columns;
    char *word_search = new char[rows * columns];
    cout<<"Enter the word search: "<<endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cin>>word_search[i * j];
            word_search[i * j] = tolower(word_search[i * j]);
        }
    }
    while(getline(file, fline))
    {
        dict[s] = fline;
        s++;
    }
    for(int i = 0; i < rows; i++)
    {
        for(int k = 0; k < columns; k++)
        {
            word = word_search[i * k];
            if(k < columns - 1)
            {
                for(int j = k + 1; j < columns; j++)
                {
                    word += (word_search[i * j]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(i);
                        cord[count][3] = to_string(j);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if( k > 0)
            {
                for(int j = k - 1; j >= 0; j--)
                {
                    word += (word_search[i * j]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(i);
                        cord[count][3] = to_string(j);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if( i < rows - 1)
            {
                for(int j = i + 1; j < rows; j++)
                {
                    word += (word_search[j * k]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(j);
                        cord[count][3] = to_string(k);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if(i > 0)
            {
                for(int j = i - 1; j >= 0; j--)
                {
                    word += (word_search[j * k]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(j);
                        cord[count][3] = to_string(k);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if(i < rows - 1 && k < columns - 1)
            {
                for(int j = i + 1, l = k + 1; j < rows & l < columns ; j++, l++)
                {
                    word += (word_search[j * l]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(j);
                        cord[count][3] = to_string(l);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if(i > 0 && k > 0)
            {
                for(int j = i - 1, l = k - 1; j >= 0 & l >= 0 ; j-- , l--)
                {
                    word += (word_search[j * l]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(j);
                        cord[count][3] = to_string(l);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if(i > 0 && k < columns - 1)
            {
                for(int j = i - 1, l = k + 1; j >= 0 & l < columns; j-- , l++)
                {
                    word += (word_search[j * l]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(j);
                        cord[count][3] = to_string(l);
                        count++;
                    }
                }
            }
            word = word_search[i * k];
            if(i < rows - 1 && k > 0)
            {
                for(int j = i + 1, l = k - 1; j < rows & l >= 0; j++ , l--)
                {
                    word += (word_search[j * l]);
                    if(scan(word, dict, s))
                    {
                        exist[count] = word;
                        cord[count][0] = to_string(i);
                        cord[count][1] = to_string(k);
                        cord[count][2] = to_string(j);
                        cord[count][3] = to_string(l);
                        count++;
                    }
                }
            }
            word = " ";
        }
    }
    cout<<"\nWords:\n\n";
    for(int x = 0; x < count; x++)
    {
        cout<<exist[x];
        for(int v = 0; v < 4; v ++)
        {
            if(v == 0 || v == 2) cout<<" (";
            if(v == 1 || v == 3) cout<<",";
            cout<<cord[x][v];
            if(v == 1 || v == 3) cout<<")";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}