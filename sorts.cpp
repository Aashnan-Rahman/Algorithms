#include<bits/stdc++.h>

using namespace std;

int A[10000]={9,2,10,6,5,3,7,1,8,4},N = 10,i;

//void merge(int arr[], int l, int m, int r)
//{
//    int k;
//    int n1 = m - l + 1;
//    int n2 =  r - m;
//    int L[n1], R[n2];
//
//    for(int i = 0; i < n1; i++)
//        L[i] = arr[l + i];
//    for(int j = 0; j < n2; j++)
//        R[j] = arr[m + 1+ j];
//
//    int i = 0;
//    int j = 0;
//    k = l;
//
//    while (i < n1 && j < n2)
//    {
//        if (L[i] <= R[j])
//        {
//            arr[k] = L[i];
//            i++;
//        }
//        else
//        {
//            arr[k] = R[j];
//            j++;
//        }
//        k++;
//    }
//
//    while (i < n1)
//    {
//        arr[k] = L[i];
//        i++;
//        k++;
//    }
//
//    while (j < n2)
//    {
//        arr[k] = R[j];
//        j++;
//        k++;
//    }
//}

void input()
{
	cin>>N;
	for(i=0;i<N;i++)
        cin>>A[i];
}

void print()
{
	for(i=0;i<N;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

void bubble_sort()
{
	//input();
	for(int x=0;x<N-1;x++)
	{
		for(int y=0;y<N-1-x;y++)
		{
			if(A[y]>A[y+1])
				swap(A[y],A[y+1]);
            print();
		}
        cout<<endl;
        print();
	}
}

void selection_sort()
{
	int max_ ;
	for(int x=0;x<N;x++)
	{
	    max_ = 0;
		for(int y=0;y<N-x;y++)
		{
			if(A[y]>A[max_]) max_ = y;
		}
		//cout<<A[N-x-1]<<" "<<A[max_]<<endl;
		swap(A[N-x-1],A[max_]);
		print();
	}
}

void insertion_sort()
{
	int max_ ;
	for(int x=1;x<N;x++)
	{
		for(int y=x;y>0 && A[y-1]>A[y];y--)
		{
			swap(A[y],A[y-1]);
			print();
		}
		cout<<endl;
		print();
	}
}


void merge__(int lo,int mid,int hi)
{
    print();

    mid = lo + (hi-lo)/2;

    int x = lo ,y = mid+1, aux[10000]={};

    for(int k = lo; k <= hi ; k++)
       {
         aux[k] = A[k];
         cout<<aux[k]<<' ';
       }
    cout<<endl;


    for(int k = lo; k <= hi ; k++)
    {
        if(x > mid)
            A[k] = aux[y++];
        else if(y > hi)
            A[k] = aux[x++];
        else if(aux[y] < aux[x])
            A[k] = aux[y++];
        else A[k] = aux[x++];

        print();

    }
    print();
}


void rec_merge_sort(int A[],int lo,int hi)
{
    if(hi<=lo) return;

    int mid = lo + (hi - lo)/2;
    rec_merge_sort(A,lo,mid);
    print();
    rec_merge_sort(A,mid+1,hi);
    print();
    cout<<endl;
    merge__(lo,mid,hi);
    print();
}

int main()
{
    clock_t time_req = clock();
    cout<<time_req<<" "<<endl;
    //bubble_sort();
    //selection_sort();
    //insertion_sort();
    rec_merge_sort(A,0,N-1);
    //non_rec_merge_sort(0,N-1);
    time_req = clock() - time_req ;
	cout<<time_req<<" "<<(float)time_req/CLOCKS_PER_SEC<<endl;
	return 0;
}

//
//10
//9 2 10 6 5 3 7 1 8 4
