#include<iostream>
#include<ctime>
using namespace std;

void Swap(int &a1, int &a2){
	int tmp = a1;
	a1 = a2;
	a2 = tmp;
}
//直接插入排序
//稳定，O(N^2),最好的情况是O(N)
void InsertSort(int *arr, int size) {
	for (int i = 0; i < size - 1; ++i) {
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0) {
			if (arr[end] > tmp) {
				arr[end + 1] = arr[end];
				end -= 1;
			}
			else break;
		}
		arr[end + 1] = tmp;
	}
}

//希尔排序
//稳定，O(N*logN)
void ShellSort(int *arr, int size) {
	int gap = size;
	while (gap > 1) {
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; ++i) {
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0) {
				if (arr[end] > tmp) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else break;
			}
			arr[end + gap] = tmp;
		}
	}
}

//冒泡排序
//稳定，O(N^2),O(N)
void BubbleSort(int *arr, int size) {
	int end = size - 1;
	while (end > 0) {
		bool flag = false;
		for (int i = 0; i < end; ++i) {
			if (arr[i] > arr[i + 1]) {
				//Swap(arr[i], arr[i + 1]);
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
			}
		}
		if (!flag)break;
	}
}

//简单选择排序
//不稳定，O(N^2),O(N^2)
void SelectSort1(int *arr, int size) {
	int left = 0, right = size - 1;
	while (left < right) {
		int maxI = left, minI = right;
		for (int i = left; i <= right; ++i) {
			if (arr[i] > arr[maxI])maxI = i;
			if (arr[i] < arr[minI])minI = i;
		}
		Swap(arr[left], arr[minI]);
		if (left == maxI)maxI = minI;
		Swap(arr[maxI], arr[right]);
		left++;
		right--;
	}
}
void SelectSort2(int *arr, int size) {
	for (int i = 0; i < size-1; ++i) {
		int minI = i;
		for (int j = i+1; j < size; ++j) {
			if (arr[minI] > arr[j])minI = j;
		}
		Swap(arr[i], arr[minI]);
	}
}

//快速排序
//不稳定，O(N*logN)
int  PartOneSort(int *arr, int left, int right) {
	int keyi = left;
	while (left < right) {
		while (left < right&&arr[right] >= arr[keyi])--right;
		while (left < right&&arr[left] <= arr[keyi])++left;
		if (left < right)Swap(arr[left], arr[right]);
	}
	int meeti = left;
	Swap(arr[meeti], arr[keyi]);
	return meeti;
}
void QuickSort(int *arr, int begin, int end) {
	if (begin >= end)return;
	int meeti = PartOneSort(arr, begin, end);
	if (meeti - 1 > begin)QuickSort(arr, begin, meeti - 1);
	if (meeti + 1 < end)QuickSort(arr, meeti + 1, end);
}

//归并排序
//稳定，O(N*logN)
void _Merge1(int *arr, int begin, int end, int *tmp) {
	if (begin >= end)return;
	int beginLeft = begin;
	int endLeft = (begin + end) >> 1;
	_Merge1(arr, beginLeft, endLeft, tmp);
	int beginRight = endLeft+1;
	int endRight = end;
	_Merge1(arr, beginRight, endRight, tmp);
	int i = begin;
	while ((beginLeft <= endLeft) && (beginRight <= endRight)) {
		if (arr[beginLeft] <= arr[beginRight]) tmp[i++] = arr[beginLeft++];
		else tmp[i++] = arr[beginRight++];
	}
	while (beginLeft <= endLeft) {
		tmp[i++] = arr[beginLeft++];
	}
	while (beginRight <= endRight) {
		tmp[i++] = arr[beginRight++];
	}
	for (int j = begin; j <= end; j++) {
		arr[j] = tmp[j];
	}
}
void Merge1(int *arr, int size) {
	int *tmp = new int[size];
	if (tmp == nullptr)return;
	_Merge1(arr, 0, size - 1, tmp);
	delete tmp;
}

void _Merge2(int *arr, int beginLeft,int endLeft,int beginRight,int endRight,int *tmp) {
	int begin = beginLeft, end = endRight;
	int i = begin;
	while ((beginLeft <= endLeft) && (beginRight <= endRight)) {
		if (arr[beginLeft] <= arr[beginRight]) tmp[i++] = arr[beginLeft++];
		else tmp[i++] = arr[beginRight++];
	}
	while (beginLeft <= endLeft) {
		tmp[i++] = arr[beginLeft++];
	}
	while (beginRight <= endRight) {
		tmp[i++] = arr[beginRight++];
	}
	for (int j = begin; j <= end; j++) {
		arr[j] = tmp[j];
	}
}
void Merge2(int *arr, int size) {
	int *tmp = new int[size];
	if (tmp == nullptr)return;
	int gap = 1;
	while (gap < size) {
		int begin = 0, end = size - 1;
		while (begin <= end) {
			int beginLeft = begin, endLeft = beginLeft + gap - 1;
			int beginRight = endLeft + 1, endRight = beginRight + gap - 1;
			if (endLeft >= end)break;
			if (endRight > end)endRight = end;
			_Merge2(arr, beginLeft,endLeft,beginRight,endRight, tmp);
			begin += 2 * gap;
		}
		gap *= 2;
	}
	delete[] tmp;
}

//堆排序
//不稳定，O(N*logN)
void AdjustDown(int *arr, int size,int index) {
	int parent = index;
	int child = parent * 2 + 1;
	while (child < size) {
		if (child + 1 < size&&arr[child] < arr[child + 1])++child;
		if (arr[parent] < arr[child]) {
			Swap(arr[parent], arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else break;
	}
}
void HeapSort(int *arr, int size) {
	//建大堆
	for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(arr, size, i);
	}
	//排序
	int end = size-1;
	while (end > 0) {
		Swap(arr[0], arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}

//计数排序
//不稳定，O(N)
void CountSort1(int *arr, int size) {
	int min = arr[0], max = arr[0];
	for (int i = 0; i < size; ++i) {
		if (min > arr[i])min = arr[i];
		if (max < arr[i])max = arr[i];
	}
	int tmpSize = max - min + 1;
	int *tmp = new int[tmpSize] {0};
	for (int i = 0; i < size; ++i) {
		tmp[arr[i] - min]++;
	}
	int arrI = 0;
	for (int i = 0; i < tmpSize; ++i) {
		while (tmp[i] > 0) {
			arr[arrI++] = i + min;
			tmp[i]--;
		}
	}
	delete[] tmp;
}
//稳定
void CountSort2(int *arr, int size) {
	int min = arr[0], max = arr[0];
	for (int i = 0; i < size; ++i) {
		if (min > arr[i])min = arr[i];
		if (max < arr[i])max = arr[i];
	}
	int tmpSize = max - min + 1;
	int *tmp = new int[tmpSize] {0};
	for (int i = 0; i < size; ++i) {
		tmp[arr[i] - min]++;
	}
	for (int i = 0; i < tmpSize - 1; ++i) {
		tmp[i + 1] += tmp[i];
	}
	int countArrSize = size;
	int *countArr = new int[countArrSize];
	for (int i = size-1; i >=0; --i) {
		countArr[tmp[arr[i] - min]-- - 1] = arr[i];
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = countArr[i];
	}


	delete[] tmp;
	delete[] countArr;
}

void Test(){
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	int* a7 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; ++i){
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];

	}

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort1(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	BubbleSort(a6, N);
	int end6 = clock();

	int begin7 = clock();
	Merge1(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);//插入排序
	printf("ShellSort:%d\n", end2 - begin2);//希尔排序
	printf("SelectSort:%d\n", end3 - begin3);//选择排序
	printf("HeapSort:%d\n", end4 - begin4);//堆排序
	printf("QuickSort:%d\n", end5 - begin5);//快速排序
	printf("BubbleSort:%d\n", end6 - begin6);//冒泡排序
	printf("MergeSort:%d\n", end7 - begin7);//归并排序

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}
int main() {
	//int arr[] = { 1,2,1,4 };
	/*int arr[] = { 3,5,2,6,11,43,23,5,23,64,223,1221,43,32,13,4,2,4,1,4,2,5,21,3 };
	int size = sizeof(arr) / sizeof(arr[0]);*/
	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//BubbleSort(arr, size);
	//SelectSort1(arr, size);
	//SelectSort2(arr, size);
	//QuickSort(arr, 0, size - 1);
	//Merge1(arr, size);
	//Merge2(arr, size);
	//HeapSort(arr, size);
	//CountSort1(arr, size);
	//CountSort2(arr, size);
	Test();
	return 0;
}