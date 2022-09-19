int upperBound(const int *arr, int right, int key)
{
    int left = 0, mid;
    while (left < right) {
        if (arr[mid = (left + right) / 2] > key) right = mid;
        else left = mid + 1;
    }
    return right;
}

int lowerBound(const int *arr, int right, int key)
{
    int left = 0, mid;
    while (left < right) {
        if (arr[mid = (left + right) / 2] < key) left = mid + 1;
        else right = mid;
    }
    return left;
}
