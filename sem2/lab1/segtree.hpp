#include <vector>
using namespace std;

#include <vector>
using namespace std;

class SegmentTree {
public:
    vector<int> tree, arr;
    int n, searching;

    SegmentTree(vector<int>& array) {
        n = (int)array.size();
        arr = array;
        searching = 0;
        tree.resize(4 * n, 0);
        buildTree(arr, 0, 0, n);
    }

    int findCount(int left, int right) {
        return findCount(0, left, right + 1, 0, n);
    }

    void rebuildTree(int num) {
        searching = num;
        buildTree(arr, 0, 0, n);
    }

    void rebuildTree(vector<int>& array) {
        arr = array;
        buildTree(arr, 0, 0, n);
    }

private:
    void buildTree(vector<int>& arr, int v, int left, int right) {
        if (left == right - 1) {
            tree[v] = arr[left] == searching ? 1 : 0;
        }
        else {
            int mid = (left + right) / 2;
            buildTree(arr, v * 2 + 1, left, mid);
            buildTree(arr, v * 2 + 2, mid, right);
            tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
        }
    }

    int findCount(int v, int left, int right, int lBorder, int rBorder) {
        if (right <= lBorder || left >= rBorder)
            return 0;

        if (lBorder >= left && rBorder <= right)
            return tree[v];

        int mid = (lBorder + rBorder) / 2;
        return findCount(2 * v + 1, left, right, lBorder, mid) + findCount(2 * v + 2, left, right, mid, rBorder);
    }
};