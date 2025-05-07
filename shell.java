import java.util.Scanner;
class ShellSort
{
    static void printarray(int arr[])
    {
        int n = arr.length;
        for(int i=0; i<n; i++)
        {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    int sort(int arr[])
    {
        int n = arr.length;
        for(int gap = n/2; gap>0; gap /=2)
        {
            for(int i=gap; i<n; i++)
            {
                int temp = arr[i];
                int j;
                for(j=i; j>=gap && arr[j-gap]>temp; j-=gap)
                {
                    arr[j] = arr[j-gap];
                }
                arr[j] = temp;
            }
        }
        return 0;
    }
    public static void main(String args[])
    {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the no of elements you want to store: ");
        n = sc.nextInt();
        int[] arr = new int[n];
        System.out.println("Enter elements of the array: ");
        for(int i=0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }
        System.out.println("Array before sorting: ");
        printarray(arr);
        ShellSort o = new ShellSort();
        o.sort(arr);
        System.out.println("Array after sorting: ");
        printarray(arr);
    }
}