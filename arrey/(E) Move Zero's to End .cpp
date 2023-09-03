vector<int> moveZeros(int n, vector<int> a) {
    int i = 0;
    int j = 0;
    while (i < n) {
        if (a[i] != 0) {
            i++;
            j++;
        } else {
            while (i < n && j <= i && a[i] == 0) {
                i++;
            }
            if (i < n) {  // Check if i is still within bounds
                swap(a[i], a[j]);
                j++;
            }
        }
    }
    return a;
}
