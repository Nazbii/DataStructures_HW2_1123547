#Nazbii
#1123547
#24.11.28

# Function to schedule tasks for maximum profit
def schedule_tasks(tasks):
    # Sort tasks based on profit (highest profit first)
    tasks.sort(key=lambda x: -x[0])

    # Find the latest deadline to determine the number of available slots
    max_deadline = max(task[1] for task in tasks)
    
    # Create a list to track scheduled tasks (-1 means slot is empty)
    slots = [-1] * (max_deadline + 1)
    
    total_profit = 0
    scheduled_tasks = []

    # Go through each task to schedule it
    for profit, deadline in tasks:
        # Try to find an available slot for this task
        for i in range(deadline, 0, -1):
            if slots[i] == -1:  # Slot is empty
                slots[i] = profit  # Schedule the task here
                total_profit += profit
                scheduled_tasks.append(profit)
                break

    return total_profit, scheduled_tasks

# Read input
n = int(input())  # Number of tasks
tasks = []

for _ in range(n):
    # Read profit and deadline for each task
    profit, deadline = map(int, input().split())
    tasks.append((profit, deadline))

# Call the function and print the results
max_profit, scheduled_tasks = schedule_tasks(tasks)
print("Maximum Profit:", max_profit)
print("Scheduled Tasks:", scheduled_tasks)
