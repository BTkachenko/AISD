#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Wrong arguments!");
        return -1;
    }
    int n = atoi(argv[1]);
    srand(time(NULL));
    int result[n];
    cout<<n<< " ";
    int d =2;
    result[0] = rand()%(2*n-1)+n*d;
    
    cout<<result[0]<<" ";
    for(int i = 1 ; i < n;i++)
    {
        result[i] = (result[i-1])-d;
        cout<<result[i]<<" ";
    }

    return 0;
}

