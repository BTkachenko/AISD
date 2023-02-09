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
    for(int i = 0 ; i < n;i++)
    {
        result[i] = rand()%(2*n-1);
        cout<<result[i]<<" ";
    }

    return 0;
}
