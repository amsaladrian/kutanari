void selection_sort(int data[]) {
    for (int i=0; i<n-1; i++) {
        pos = i;
        for (int j=i+1; j<n; j++) {
            if (data[j]<data[pos])
                pos = j; //ascending
        }
        if (pos != i)
            tukar (&data[pos], &data[i]);
    }
}
