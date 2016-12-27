/* qsorts:  sort v[left]...v[right] into increasing order */
void qsorts(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)	/* do nothing if array contains */
        return ;		/* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsorts(v, left, last-1, comp);
    qsorts(v, last+1, right, comp);
}
