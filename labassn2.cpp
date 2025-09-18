#include <iostream>
#include <string>
using namespace std;

//Q1:binary search
int binarySearch(int arr[], int n, int x) {
    int low =0,high=n -1;
    while (low<=high) {
        int mid =(low+ high) / 2;
        if (arr[mid]==x) 
		return mid;
        else if (arr[mid]< x) 
		low=mid + 1;
        else 
		high=mid - 1;
    }
    return -1;
}

//Q2:bubble sort
void bubbleSort(int arr[],int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] >arr[j+1]) {
                int temp=arr[j];
                arr[j] =arr[j+1];
                arr[j+1] =temp;
            }
        }
    }
}

///Q3
int missingNumberLinear(int arr[], int n) {
    int sum=0,expected = n*(n+1)/2;
    
	for(int i=0; i<n-1 ;i++) 
	   sum += arr[i];
    
	return expected - sum;
}

int missingNumberBinary(int arr[], int n) {
    int low=0,high=n-2;
    
	while(low<=high) {
        
		int mid=(low+high)/2;
        if(arr[mid] != mid+1) {
            if(mid==0 || arr[mid-1]==mid) 
			  return mid+1;
            high = mid-1;
        } else 
		  low=mid+1;
    }
    return n;
}

//Q4
string concatStrings(string a, string b) { return a+b; }

string reverseString(string s) {
    string rev="";
    for(int i=s.length()-1;i>=0;i--) rev+=s[i];
    return rev;
}

string deleteVowels(string s) {
    
	string res="";
    
	for(int i=0;i<s.length();i++) {
        char c=s[i];
        
		if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
             c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            res=res+c;
    }
    return res;
}

void sortStrings(string arr[], int n) {
    for(int i=0;i<n-1;i++) {
        
		for(int j=i+1; j<n; j++) {
            if(arr[i]>arr[j]) {
                string temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

char upperToLower(char c) {
    if(c>='A' && c<='Z') 
	 return c+32;
    return c;
}

//Q5:matrices
void storeDiagonal(int mat[3][3], int diag[3], int n) {
    for(int i=0; i<n; i++) 
	  {
	  	diag[i]=mat[i][i];
	  }
}

//Q6
struct Triplet { int row,col,val; };

void toTriplet(int mat[3][3], Triplet trip[], int &k) {
    k=0;
    for(int i=0; i< 3; i++) {
        for(int j=0;j<3; j++) {
            if(mat[i][j]!=0) {
                trip[k].row=i;
                trip[k].col=j;
                trip[k].val= mat[i][j];
                k++;
            }
        }
    }
}

void printTriplet(Triplet trip[], int k) {
    for(int i=0;i<k;i++)
    {
    	        cout<<trip[i].row<<" "<<trip[i].col<<" "<<trip[i].val<<endl;

	}
}

void transpose(Triplet trip[], Triplet result[],int k) {
    for(int i=0;i<k ; i++) {
        result[i].row= trip[i].col;
        result[i].col=trip[i].row;
        result[i].val=trip[i].val;
    }
}

//Q7
int countInversions(int arr[], int n) {
    int cnt=0;
    for(int i=0;i<n;i++)
        {
        	for(int j=i+1;j<n;j++)
            {
            	if(arr[i]>arr[j]) 
				 cnt++;
			}
		}
    return cnt;
}

//Q8
int distinctElements(int arr[], int n) {
    int count=0;
   
    for(int i=0;i< n; i++) {
        bool seen=false;
        for(int j=0;j<i;j++) {
            if(arr[i]==arr[j]) 
			{ seen=true; 
			break; 
			}
        }
        if(!seen) 
		 count++;
    }
    return count;
}


int main() {
    // Q1
    int arr1[]={1,2,3,4,5};
    cout<<"Q1 : "<<binarySearch(arr1,5,4)<<endl;

    // Q2
    int arr2[]={64,34,25,12,22,11,90}; 
	int n2=7;
    bubbleSort(arr2,n2);
    cout<<"Q2 Bubble Sort:";
	 for(int i=0;i<n2;i++) {
	 	cout<<arr2[i]<<" "; 
		 cout<<endl;
	 }

    //Q3
    int arr3[]={1,2,3,5};
    cout<<"Q3a: "<<missingNumberLinear(arr3,5)<<endl;
    cout<<"Q3b : "<<missingNumberBinary(arr3,5)<<endl;

    //q4
    cout<<"Q4a  "<<concatStrings("Hello","World")<<endl;
    cout<<"Q4b Reverse: "<<reverseString("Python")<<endl;
    cout<<"Q4c  "<<deleteVowels("Beautiful")<<endl;
    string strs[]={"banana","apple","cherry"};
    sortStrings(strs,3);
    cout<<"4d Sorted Strings: "; for(int i=0;i<3;i++) cout<<strs[i]<<" "; cout<<endl;
    cout<<"Q4e  "<<upperToLower('A')<<endl;

    //Q 5
    int mat[3][3]={{1,0,0},{0,2,0},{0,0,3}}, diag[3];
    storeDiagonal(mat,diag,3);
    cout<<"Q5  "; 
	for(int i=0;i<3;i++) {
		cout<<diag[i]<<" "<<endl;
	}

    // Q6
    int mat2[3][3]={{1,0,0},{0,0,2},{0,3,0}};
    Triplet trip[10],trans[10]; 
	int k;
    toTriplet(mat2,trip,k);
    cout<<"Q6 Triplet form:"<<endl; 
	printTriplet(trip,k);
    transpose(trip,trans,k);
    cout<<"Q6 Transpose:"<<endl; 
	printTriplet(trans,k);

    // Q7
    int arr7[]={2,4,1,3,5};
    cout<<"Q7 "<<countInversions(arr7,5)<<endl;

    // Q8
    int arr8[]={1,2,2,3,4,4,5};
    cout<<"Q8  "<<distinctElements(arr8,7)<<endl;

    return 0;
}

