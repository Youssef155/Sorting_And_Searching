#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id, grade;
    char name[20];
};

struct Student students[5];


int DisplayMenu();
void merge(struct Student arr[], int start, int mid, int end);
void mergeSort(struct Student arr[], int start, int end);
void display(struct Student arr[], int size);
int BinarySearch(struct Student arr[], int key, int start, int end);
void BubbleSort(struct Student arr[], int size);


int main()
{
    students[0].id = 3;
    students[0].grade = 45;
    strcpy(students[0].name, "Omar");

    students[1].id = 5;
    students[1].grade = 67;
    strcpy(students[1].name, "George");

    students[2].id = 2;
    students[2].grade = 87;
    strcpy(students[2].name, "Khalil");

    students[3].id = 1;
    students[3].grade = 74;
    strcpy(students[3].name, "Youssef");

    students[4].id = 4;
    students[4].grade = 29;
    strcpy(students[4].name, "nour");

    int ch;

    do
    {
        system("cls");
        ch = DisplayMenu();

        if(ch == 1)
        {
            mergeSort(students, 0, 4);
            printf("the list is sorted using merge");
            getch();
        }
        else if(ch == 2)
        {
            BubbleSort(students, 5);
            printf("the list is sorted using bubble");
            getch();
        }
        else if(ch == 3)
        {
            int id;
            printf("Enter id to search: ");
            scanf("%d", &id);
            int loc = BinarySearch(students, 0, 5, id);
            if(loc != -1)
            {
                printf("the location is: %d", loc);
                getch();
            }
            else
            {
                printf("the location is not found");
                getch();
            }
        }
        else if(ch == 4)
        {
            display(students, 5);
            getch();
        }
    }
    while(ch!=0);

    return 0;
}

int DisplayMenu()
{
    int ch;
    printf("1. Merge Sort.\n");
    printf("2. Bubble Sort.\n");
    printf("3. search by id.\n");
    printf("4. Display.\n");
    printf("Enter ur choice: ");
    scanf("%d", &ch);

    return ch;
}

void merge(struct Student arr[], int start, int mid, int end)
{

    int len1 = mid - start + 1;
    int len2 = end - mid;

    struct Student leftArr[len1], rightArr[len2];

    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[start + i];
    for (int j = 0; j < len2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while (i < len1 && j < len2)
    {
        if (leftArr[i].id <= rightArr[j].id)
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < len1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < len2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(struct Student arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

void BubbleSort(struct Student arr[], int size)
{
    int i, j;
    struct Student temp;
    int swapped = 1;
    i = 0;
    while(swapped)
    {
        swapped = 0;
        for(j=0; j<size-1-i; j++)
        {
            if(arr[j].id > arr[j+1].id)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        i++;
    }

}

int BinarySearch(struct Student arr[], int start, int end, int key)
{
    int mid, loc=-1;
    while(start <= end && loc == -1)
    {
        mid = (start + end)/2;
        if(arr[mid].id == key)
        {
            loc = mid;
        }
        else if(arr[mid].id>key)
            end = mid-1;
        else
            start = mid+1;
    }

    return loc;
}

void display(struct Student arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("student %d id: %d\n", i+1, arr[i].id);
        printf("student %d name: %s\n", i+1, arr[i].name);
        printf("student %d grade: %d\n\n", i+1, arr[i].grade);
    }
}
