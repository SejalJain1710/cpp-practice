#include <bits/stdc++.h>
using namespace std;

#define T pair<int, pair<int, int>>

class queueTime_compare {
	public:
	bool operator() (T p1, T p2) {
		return p1.second.first > p2.second.first;
    }
};

class executionTime_compare {
	public:
	bool operator() (T p1, T p2) {
		return p1.second.second > p2.second.second;
    }
};

vector<int> enqueueTasks(vector<T> tasks) {
    int time_elapsed = 0;
    priority_queue<T, vector<T>, queueTime_compare> queueTime;
    priority_queue<T, vector<T>, executionTime_compare> executionTime;

    vector<int> result;

    for (auto task: tasks) {
        queueTime.push(task);
    }
    while (!queueTime.empty() and queueTime.top().second.first <= time_elapsed) {
        T task = queueTime.top();
        queueTime.pop();
        executionTime.push(task);
    }

    while (!executionTime.empty()) {
        T task = executionTime.top();
        executionTime.pop();
        result.push_back(task.first);
        time_elapsed += task.second.second;
        while (!queueTime.empty() and queueTime.top().second.first <= time_elapsed) {
            T newtask = queueTime.top();
            queueTime.pop();
            executionTime.push(newtask);
        }
    }
    return result;
}

int main() {
    vector<T> tasks{ {0, {0, 7}}, {1, {0, 2}}, {2, {3, 3}}, {3, {5, 9}} };
    vector<int> result = enqueueTasks(tasks);
    for (auto task_id: result)
        cout << task_id << " ";
    cout << endl;
    return 0;
}
