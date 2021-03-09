//#include <stdio.h>
//#include <stdlib.h>
//
//void merge(int arr[], int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	/* create temp arrays */
//	int L[n1], R[n2];
//
//	/* Copy data to temp arrays L[] and R[] */
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	/* Merge the temp arrays back into arr[l..r]*/
//	i = 0; // Initial index of first subarray
//	j = 0; // Initial index of second subarray
//	k = l; // Initial index of merged subarray
//	while (i < n1 && j < n2) {
//		if (L[i] <= R[j]) {
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	/* Copy the remaining elements of L[], if there
//	are any */
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	/* Copy the remaining elements of R[], if there
//	are any */
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
///* l is for left index and r is right index of the
//sub-array of arr to be sorted */
//void mergeSort(int arr[], int l, int r)
//{
//	if (l < r) {
//		// Same as (l+r)/2, but avoids overflow for
//		// large l and h
//		int m = l + (r - l) / 2;
//
//		// Sort first and second halves
//		mergeSort(arr, l, m);
//		mergeSort(arr, m + 1, r);
//
//		merge(arr, l, m, r);
//	}
//}
//
///* UTILITY FUNCTIONS */
///* Function to print an array */
//void printArray(int A[], int size)
//{
//	int i;
//	for (i = 0; i < size; i++)
//		printf("%d ", A[i]);
//	printf("\n");
//}
//
//
////----------------------stack implmentation----------------------
//int MAXSIZE = 20;
//int stack[20];
//int top = -1;
//
//
//
//int isempty() {
//
//   if(top == -1)
//      return 1;
//   else
//      return 0;
//}
//
//int isfull() {
//
//   if(top == MAXSIZE)
//      return 1;
//   else
//      return 0;
//}
//
//int peek() {
//   return stack[top];
//}
//
//int pop() {
//   int data;
//
//   if(!isempty()) {
//      data = stack[top];
//      top = top - 1;
//      return data;
//   } else {
//      printf("Could not retrieve data, Stack is empty.\n");
//   }
//}
//
//int push(int data) {
//
//   if(!isfull()) {
//      top = top + 1;
//      stack[top] = data;
//   } else {
//      printf("Could not insert data, Stack is full.\n");
//   }
//}
////--------------------------------end of stack-----------------------
//
//int main(){
//    int i,j,k,n,m,sum=0,x,y,h;
//    printf("Enter the size of disk\n");
//    scanf("%d",&m);
//    printf("Enter number of requests\n");
//    scanf("%d",&n);
//    printf("Enter the requests\n");
//    int arr[n+2];
//    for(i=0;i<n;i++){
//        scanf("%d",&arr[i]);
//    }
//    for(i=0 ; i<n ; i++){
//        if(arr[i] > m){
//            printf("Error, Unknown position %d \n" ,arr[i]);
//            return 0;
//        }
//    }
//    // vector <int> a(n),b;
//    printf("Enter the head position \n");
//    scanf("%d",&h);
//    int temp = h;
//    printf("\ntemp %d \n",temp);
//    arr[n] = h;
//    arr[n+1] = m;
//
//
//
//
//    mergeSort(arr, 0, n - 1);
//
//    printArray(arr,n+1);
//
//
//    for(i= 0 ; i< n+1 ; i++){
//        if( h == arr[i])
//            break;
//    }
//
//    k = i;
//    if( k < n/2){
//        for(i = k ; i < n ;i++){
//            push(arr[i]);
//        }
//        for(i=k-1;i>=0;i--){
//           push(arr[i]);
//        }
//    }
//    else{
//        for(i = k ; i >= 0 ; i--){
//            push(arr[i]);
//        }
//        for(i=k+1;i<n;i++){
//            push(arr[i]);
//        }
//    }
//    temp = stack [0];
//    printf("%d " , temp);
//
//    for(i=1 ; i< n ;i++){
//        printf(" -> %d" , stack[i]);
//        sum += abs(stack[i]-temp);
//        temp = stack[i];
//    }
//    printf("\n");
//    printf("Total head movements = %d \n ",sum);
//    printf("Average head movement = %f \n ", (float)sum);
//    return 0;
//}



#include<stdio.h>

#include<math.h>

int main()

{
    int queue[20],n,head,i,j,k,seek=0,max,diff,temp,queue1[20],queue2[20],temp1=0,temp2=0;
    float avg;
    printf("Enter the max range of disk\n");
    scanf("%d",&max);

    printf("Enter the initial head position\n");

    scanf("%d",&head);

    printf("Enter the size of queue request\n");

    scanf("%d",&n);

    printf("Enter the queue of disk positions to be read\n");

    for(i=1; i<=n; i++)

    {

        scanf("%d",&temp);

        if(temp >= head)
        {
            queue1[temp1]=temp;
            temp1++;

        }

        else
            {
            queue2[temp2]=temp;
            temp2++;
            }
    }

    for(i=0; i<temp1-1; i++)

    {
        for(j=i+1; j<temp1; j++)

        {

            if(queue1[i]>queue1[j])

            {

                temp=queue1[i];

                queue1[i]=queue1[j];

                queue1[j]=temp;

            }

        }

    }

    for(i=0; i<temp2-1; i++)

    {

        for(j=i+1; j<temp2; j++)

        {

            if(queue2[i]<queue2[j])

            {

                temp=queue2[i];

                queue2[i]=queue2[j];

                queue2[j]=temp;

            }

        }

    }

    for(i=1,j=0; j<temp1; i++,j++)

        queue[i]=queue1[j];

    queue[i]=max;

    for(i=temp1+2,j=0; j<temp2; i++,j++)

        queue[i]=queue2[j];

    queue[i]=0;

    queue[0]=head;

    for(j=0; j<=n+1; j++)

    {

        diff=abs(queue[j+1]-queue[j]);

        seek+=diff;

        printf("Disk head moves from %d to %d with seek %d\n",queue[j],queue[j+1],diff);

    }

    printf("Total seek time is %d\n",seek);

    avg=seek/(float)n;

    printf("Average seek time is %f\n",avg);

    return 0;

}
