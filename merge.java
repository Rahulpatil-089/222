import java.util.Scanner;
class MergeSort
{
    void merge(int arr[], int p, int q, int r)
    {
        int n1 = q-p+1;  //q=end of 1st arr, p=start of 1st arr
        int n2 = r-q;    //r=whole arr
        int l[] = new int[n1];
        int m[] = new int[n2];

        for(int i=0; i<n1; i++)
        {
            l[i] = arr[p+i];
        }
        for(int j=0; j<n2; j++)
        {
            m[j] = arr[q+1+j];
        }
        int i, j, k;
        i=0;
        j=0;
        k=p;

        while(i<n1 && j<n2)
        {
            if(l[i] <= m[j])
            {
                arr[k] = l[i];
                i++;
            }
            else
            {
                arr[k] = m[j];
                j++;
            }
            k++;
        }
        while(i<n1)
        {
            arr[k] = l[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            arr[k] = m[j];
            j++;
            k++;
        }
    }
    void mergesort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int m = (l+r)/2;
            mergesort(arr, l, m);
            mergesort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
    static void printarray(int arr[])
    {
        int n = arr.length;
        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String args[])
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter the number of elements you want to store: ");
        n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("\nEnter the elements of the array: ");
        for(int i=0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("\nArray before sorting");
        printarray(arr);
        MergeSort o = new MergeSort();
        o.mergesort(arr, 0, arr.length-1);
        System.out.println("Sorted array: ");
        printarray(arr);
    }
}
