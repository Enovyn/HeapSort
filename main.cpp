#include <iostream>

void swap(int &a, int &b){
int h = b;
b = a;
a = h;
}

void Heapify(int a[], int f, int l, int root){
int largest, left = f + (root - f)*2 + 1, right = f + (root - f)*2 + 2;
    if(left <= l && a[left] > a[root]){
        largest = left;
    }else largest = root;
    if(right <= l && a[right] > a[largest]){
        largest = right;
    }
    if(largest!=root){
        swap(a[root], a[largest]);
        Heapify(a, f, l, largest);
    }
}


void BuildHeap(int a[], int f, int l){
int n = l - f + 1;
for(int i = f+(n-2)/2; i >= f; i--)
    Heapify(a, f, l, i);
}


void HeapSort(int a[], int f, int l){
BuildHeap(a, f, l);
    for(int i = l; i > f; i--){
        swap(a[f], a[i]);
        Heapify(a, f, i-1, f);
    }
}

int main(){
int nmbrs[] = {23, 5, 15, 7, 91, 14, 21, 2, 1, 9, 13, 5, 3, 81, 17};
int n = (sizeof(nmbrs)/sizeof(*nmbrs));

HeapSort(nmbrs, 0, n-1);

for(int i = 0; i < n; i++){
    printf("%d ", nmbrs[i]);
}

return 0;
}
