#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define PB push_back

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi pset(1000);
int _size;
void initSet(int N) {
    for (int i=0 ; i<N ; i++) pset[i] = i;
    _size = N; }
int findSet(int i) {
    return pset[i] == i ? i : (pset[i] = findSet(pset[i])); }
bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j); }
int getSize() {
    return _size; }
void unionSet(int i, int j) {
    if (!isSameSet(i, j))
        pset[findSet(i)] = findSet(j), _size--; }

int N, M, a, b;
double x[1000], y[1000];
vector<pair<double, ii> > EdgeList;

int main() {
    while (scanf("%d", &N) == 1) {
        EdgeList.clear();
        for (int i=0 ; i<N ; i++) {
            scanf("%lf %lf", &x[i], &y[i]);
        }

        for (int i=0 ; i<N ; i++) for (int j=i+1 ; j<N ; j++) {
            double dist = hypot(x[i] - x[j], y[i] - y[j]);
            EdgeList.PB(make_pair(dist, ii(i, j)));
        }

        initSet(N);
        scanf("%d", &M);
        while (M--) {
            scanf("%d %d", &a, &b);
            unionSet(a-1, b-1);
        }
        double MST=0;
        sort(EdgeList.begin(), EdgeList.end());
        for (int i=0 ; i<EdgeList.size() && getSize() > 0 ; i++) {
            pair<double, ii> front = EdgeList[i];
            if (!isSameSet(front.second.first, front.second.second)) {
                MST += front.first;
                unionSet(front.second.first, front.second.second);
            }
        }

        printf("%.2lf\n", MST);
    }


    return 0;
}
