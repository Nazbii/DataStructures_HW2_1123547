// Nazbii
// 1123547
// 24.11.27

#include <bits/stdc++.h>
using namespace std;

struct Task
{
    string name;
    int priority;

    Task(string task_name, int task_priority)
    {
        name = task_name;
        priority = task_priority;
    }

    bool operator<(const Task &other) const
    {
        return priority < other.priority;
    }
};

int main()
{
    int N; // Number of operations
    cout << "Input number of priorities: ";
    cin >> N;

    // Max heap (priority queue)
    priority_queue<Task> pq;

    vector<string> output; // To store output of all GET operations

    // Process each operation
    for (int i = 0; i < N; ++i)
    {
        string operation;
        cin >> operation;

        if (operation == "ADD")
        {
            string task_name;
            int priority;
            cin >> task_name >> priority;
            pq.push(Task(task_name, priority)); // Add task to max heap
        }
        else if (operation == "GET")
        {
            if (!pq.empty())
            {
                Task top_task = pq.top();        // Get the highest priority task
                output.push_back(top_task.name); // Store the task name in output
                pq.pop();                        // Remove the task from the heap
            }
            else
            {
                output.push_back("No tasks available"); // If no tasks available
            }
        }
    }

    cout << "///////////////" << endl;

    // Output all GET operations
    for (const string &result : output)
    {
        cout << result << endl;
    }

    // Print remaining tasks in descending order of priority
    cout << "Remaining tasks: ";
    vector<pair<string, int>> remaining_tasks;

    while (!pq.empty())
    {
        Task task = pq.top();
        remaining_tasks.push_back({task.name, task.priority});
        pq.pop();
    }

    // Output remaining tasks
    cout << "[";
    for (size_t i = 0; i < remaining_tasks.size(); ++i)
    {
        if (i > 0)
            cout << ", ";
        cout << "('" << remaining_tasks[i].first << "', " << remaining_tasks[i].second << ")";
    }
    cout << "]" << endl;

    return 0;
}
