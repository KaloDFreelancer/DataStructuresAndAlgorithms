#include <iostream>
#include <set>
#include <queue>
#include <stack>

using namespace std;

struct Node {
    int x, y, dist;
    Node *parentNode;

    Node(int x, int y, int dist = 0) : x(x), y(y), dist(dist) {
        this->parentNode = nullptr;
    }

    virtual ~Node() {
        this->parentNode = nullptr;
    }

//    needed for std::set
    bool operator<(const Node &rhs) const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
};

int findMinDistBetweenTwoPoints(const Node& src, const Node& destination) {
    set<Node> visitedNodes;
    queue<Node> queue;
    queue.push(src);

    int rows[8] = {-2, -2, 2, 2, 1, 1, -1, -1};
    int cols[8] = {-1, 1, -1, 1, -2, 2, -2, 2};

    while (!queue.empty()) {
        Node point = queue.front();
        queue.pop();
//        skip if visited
        if (!visitedNodes.count(point)) {
            visitedNodes.insert(point);
//            if point == destination
            if (point.x == destination.x && point.y == destination.y) {
//                print path to this point
                stack<pair<int, int>> coordinatesStack;
                coordinatesStack.push(make_pair(point.x, point.y));
                Node *currentNode = point.parentNode;
                for (int i = 0; i < point.dist; ++i) {
                    coordinatesStack.push(make_pair(currentNode->x, currentNode->y));
                    currentNode = currentNode->parentNode;
                }
                //No need to "delete currentNode" because it's always null
//                print coordinates path
                while (!coordinatesStack.empty()) {
                    pair<int, int> coordinatePair = coordinatesStack.top();
                    coordinatesStack.pop();
                    cout << "[" << coordinatePair.first << ", " << coordinatePair.second << "]";
                    if (!coordinatesStack.empty()) {
                        cout << " -> ";
                    }
                }
                return point.dist;
            }
//            if point isn't the desired destination add all children points which are possible
            for (int i = 0; i < 8; ++i) {
                Node newPoint(point.x + rows[i], point.y + cols[i], point.dist + 1);
                //check if point is valid
                if ((newPoint.x >= 0 && newPoint.x < 8) && (newPoint.y >= 0 && newPoint.y < 8)) {
                    Node *parentNodePointer = new Node(point.x, point.y, point.dist);
                    parentNodePointer->parentNode = point.parentNode;
                    newPoint.parentNode = parentNodePointer;
                    queue.push(newPoint);
                }
            }

        }
    }

//    if there isn't a path
    return -1;
}

int main() {
    Node src(0, 7);
    Node destination(7, 0);

    int res = findMinDistBetweenTwoPoints(src, destination);
    if (res != -1) {
        cout << endl;
        cout << "Min distance: " << res;
    }
    return 0;
}
