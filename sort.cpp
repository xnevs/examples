#include <cstdlib>
#include <cstdio>
#include <algorithm>

#include <ctime>

using namespace std;

/*
                                                _   
                                               | |  
  _ __ ___   ___ _ __ __ _  ___  ___  ___  _ __| |_ 
 | '_ ` _ \ / _ \ '__/ _` |/ _ \/ __|/ _ \| '__| __|
 | | | | | |  __/ | | (_| |  __/\__ \ (_) | |  | |_ 
 |_| |_| |_|\___|_|  \__, |\___||___/\___/|_|   \__|
                      __/ |                         
                     |___/
*/
void mergesort(int a[], int i, int j, int b[]) {
	if(j-i < 2)
		return;
	
	int center = (i+j) / 2;

	mergesort(a, i, center, b);
	mergesort(a, center+1, j, b);

	int k0 = i, k1 = center + 1;
	for(int k=i; k<=j; k++)
		if(k0 <= center && (k1 > j || a[k0] <= a[k1]))
			b[k] = a[k0++];
		else
			b[k] = a[k1++];

	copy(b+i, b+j+1, a+i);
}
/* end mergesort */


/*
              _      _                   _   
             (_)    | |                 | |  
   __ _ _   _ _  ___| | _____  ___  _ __| |_ 
  / _` | | | | |/ __| |/ / __|/ _ \| '__| __|
 | (_| | |_| | | (__|   <\__ \ (_) | |  | |_ 
  \__, |\__,_|_|\___|_|\_\___/\___/|_|   \__|
     | |                                     
     |_|
*/
int partition(int a[], int i, int j, int pivot) {
	swap(a[pivot], a[j]); //pivot damo na zadnje mesto

	int crnt = i;
	for(int k=i; k<j; k++) //gremo čev vse razen zadnjega (pivota)
		if(a[k] < a[j])
			swap(a[k], a[crnt++]);

	swap(a[j], a[crnt]); //postavimo pivot na svoje mesto

	return crnt; //vrnemo indeks pivota
}
void quicksort(int a[], int i, int j) {
	if(j-i < 2)
		return;

	int pivot = i + (rand()%(j-i+1));

	pivot = partition(a, i, j, pivot);

	quicksort(a, i, pivot-1);
	quicksort(a, pivot+1, j);
}
/* end quicksort */


/*
  _                                     _   
 | |                                   | |  
 | |__   ___  __ _ _ __  ___  ___  _ __| |_ 
 | '_ \ / _ \/ _` | '_ \/ __|/ _ \| '__| __|
 | | | |  __/ (_| | |_) \__ \ (_) | |  | |_ 
 |_| |_|\___|\__,_| .__/|___/\___/|_|   \__|
                  | |                       
                  |_|
*/

void trickle_down(int a[], int n) {
	int crnt = 0;
	while( (2 * (crnt+1)) - 1 < n ) {
		int max_child = (2 * (crnt+1)) - 1;
		if( (2 * (crnt+1)) < n && a[(2 * (crnt+1))] > a[(2 * (crnt+1)) - 1]) 
			max_child = (2 * (crnt+1));

		if(a[max_child] > a[crnt]) {
			swap(a[max_child], a[crnt]);
			crnt = max_child;
		}
		else
			break;
	}
}
void heapsort(int a[], int n) {
	make_heap(a, a+n);

	int crnt = n-1;
	while(crnt>0) {
		swap(a[0], a[crnt]);
		trickle_down(a, crnt);
        crnt--;
	}
}
/* end heapsort */




void sort(int a[], int n) {
	int *b = new int[n];
	//mergesort (a, 0, n-1, b);
	//quicksort(a, 0, n-1);
	heapsort(a, n);
	delete []b;
}

int main() {
	int n = 10;
	int a[10] = {3,5,1,8,2,12,47,4,6, 11};

	sort(a, n);
	for(int i=0; i<10; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}
