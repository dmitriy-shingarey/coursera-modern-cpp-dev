# Programming Assignment: Task Tracker

Implement a _TeamTasks_ class that allows you to store statistics on the task statuses of the development team:

```objectivec
// Enumerative type for the task status
enum class TaskStatus {
  NEW, // new
  IN_PROGRESS, // in progress
  TESTING, // in testing
  DONE // completed
};

// declare type-synonym for map<TaskStatus, int>,
// allowing to store the number of tasks of each status
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Get statistics on the task statuses of a particular developer
  GetPersonTasksInfo(const string& person) const;
  
  // Add a new task (with NEW status) for a particular developer
  void AddNewTask(const string& person);
  
  //Update the statuses of the given number of tasks of a particular developer,
  // see below for details.
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count);
};

```

The _PerformPersonTasks_ method should implement the following algorithm:

1. Consider all unperformed tasks of the developer person.
2. Arrange them by their statuses: first all tasks with status NEW, then all tasks with status IN_PROGRESS and finally all tasks with status TESTING.
3. Consider the first task_count of tasks and put each of them into the following status in accordance with the natural order: NEW → IN_PROGRESS → TESTING → DONE.
4. Let's return a tuple of two elements: information about the statuses of updated tasks (including those that are in DONE status) and information about the statuses of the remaining unaccomplished tasks.

It is guaranteed that *task_count* is a positive number. If *task_count* exceeds the current number of unfulfilled tasks of the developer, it is sufficient to assume that *task_count* is equal to the number of unfulfilled tasks: in this case you do not need to update the status of any task twice.

Besides, it is guaranteed that the _GetPersonTasksInfo_ method will not be called for a developer who has no tasks.

## Example of how the PerformPersonTasks method works

Suppose that a particular developer has 10 tasks with the following statuses:

* NEW - 3
* IN_PROGRESS - 2
* TESTING - 4
* DONE - 1

The _PerformPersonTasks_ command is received with the parameter *task_count = 4*, which means that the status updates for 3 tasks from *NEW* to *IN_PROGRESS* and for 1 task from *IN_PROGRESS* to *TESTING*. Thus, the new task statuses will be as follows:

* IN_PROGRESS - 3 updated, 1 old
* TESTING - 1 updated, 4 old
* DONE - 1 old

In this case you need to return a tuple of 2 dictionaries:

* updated tasks: IN_PROGRESS - 3, TESTING - 1.
* Tasks not updated, excluding completed tasks: IN_PROGRESS - 1, TESTING - 4.

__Task dictionaries must not contain unnecessary elements, i.e. statuses that have zero tasks.

### Note

Updating a dictionary at the same time as iterating over it might lead to unpredictable consequences. If such a need arises, it is recommended to first in a separate temporary
