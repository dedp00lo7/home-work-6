#include <iostream>
#include <fstream>

using namespace std;
//Задание 1

void Errorr()
{
    cout<<"Sorry, there are some errors!"<<endl;
}
void MemoryError()
{
    cout << "Error! Can not allocate memory!"<<endl;
}
void ArrWork(int* ptrArr,int n)
{
    ptrArr = new (std::nothrow) int[n];
    if (ptrArr != nullptr)
    {
        ptrArr[0]=1;
        cout<<ptrArr[0]<<endl;
        for (int i=1; i<n; ++i)
        {
            ptrArr[i]=ptrArr[i-1]*2;
            cout<<ptrArr[i]<<endl;
            
            
        }
        delete[] ptrArr;
        
    }
    else
    {
        MemoryError();
    }
}
// задание 2
void ArrMemoryWork(int** pptrArr,  size_t m)
{
    pptrArr = new int * [m];
    for ( int i=0; i<m; i++)
    {
        pptrArr[i]=new int [m];
        
    }
    for ( int i=0; i<m; ++i)
    {
        for ( int j=0; j<m; ++j)
        {
            pptrArr[i][j]=rand() %1000;
            cout<<pptrArr[i][j]<<endl;
        }
    }

}



int main()
{
    //задание 1
    int* ptrArr = nullptr;
    int n;
    cin>>n;
    if (n>0)
    {
        ArrWork(ptrArr, n);
    
    }
    else
    {
        Errorr();
    }
    //задание 2
   int** pptrArr = nullptr;
    const size_t m=4;
    ArrMemoryWork(pptrArr, m);
 
    //задание 3
    cout<<"Viberite imena Failov:"<<endl;
    string FileName1, FileName2;
    cin>>FileName1>>FileName2;
    ofstream fout(FileName1);
    for (int i=0; i<80; i++)
    {
        fout << rand() %423432 << endl;
    }
        
    fout.close();
    
    ofstream ffout(FileName2);
    for (int i=0; i<80; i++)
    {
        ffout << rand() %423432 << endl;
    }
        
    ffout.close();
//    задание 4
    cout<<"Viberite imya Faila:"<<endl;
    string FileName3;
    cin>>FileName3;
    
    ifstream fin(FileName1);
    if (fin.is_open())
        
    {
        string buf;
        while (!fin.eof())
        getline(fin, buf);
        ifstream fffin(FileName3);
        ofstream fffout(FileName3);
        fffout<<buf<<endl;
        fffin.close();
        fin.close();
    }
    ifstream ffin(FileName2);
    if (ffin.is_open())
        
    {
        string buf;
        while (!ffin.eof())
        getline(ffin, buf);
        ifstream fffin(FileName3);
        ofstream fffout(FileName3);
        fffout<<buf<<endl;
        fffin.close();
        ffin.close();
    }
    // задание 5
    
    
    string USTR;
    cin>>USTR;
    
    ofstream foutn("data.txt");
    
    
    foutn << "Privet kak dela Yan";
    ifstream finn("data.txt");
    
    string buff;
    string buf;
    while (!finn.eof())
    getline(finn, buf);
    buff=buf;
    
    finn.close();
    if (buff.find(USTR) != string::npos)
        {
            cout << "Yes we found User's word!"<<endl;
    }
    else
        {
            cout << "We can not find User's Word!"<<endl;
    
    }
   

    
    
    return 0;
}
