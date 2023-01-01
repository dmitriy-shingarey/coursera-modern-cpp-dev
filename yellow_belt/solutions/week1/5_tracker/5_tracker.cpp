#include <map>
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const{
      return personal_info.at(person);
  }
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person){
      personal_info[person][TaskStatus::NEW] = personal_info[person][TaskStatus::NEW] + 1;
  }
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count){
          TasksInfo updated_tasks, untouched_tasks;

          updated_tasks[TaskStatus::NEW] = personal_info[person][TaskStatus::NEW];
          updated_tasks[TaskStatus::IN_PROGRESS] = personal_info[person][TaskStatus::IN_PROGRESS];
          updated_tasks[TaskStatus::TESTING] = personal_info[person][TaskStatus::TESTING];

          personal_info[person][TaskStatus::NEW] = personal_info[person][TaskStatus::NEW] - task_count; 
          personal_info[person][TaskStatus::IN_PROGRESS] = personal_info[person][TaskStatus::IN_PROGRESS] + task_count;
          if (personal_info[person][TaskStatus::NEW] < 0){
              personal_info[person][TaskStatus::IN_PROGRESS] = personal_info[person][TaskStatus::IN_PROGRESS]  - abs(personal_info[person][TaskStatus::NEW]);
              personal_info[person][TaskStatus::NEW] = 0;
              if (personal_info[person][TaskStatus::IN_PROGRESS] < 0){
                  personal_info[person][TaskStatus::TESTING] = personal_info[person][TaskStatus::TESTING]  - abs(personal_info[person][TaskStatus::IN_PROGRESS]);
                  personal_info[person][TaskStatus::IN_PROGRESS] = 0;
                  if (personal_info[person][TaskStatus::TESTING] < 0){
                      personal_info[person][TaskStatus::DONE] = personal_info[person][TaskStatus::DONE]  + abs(personal_info[person][TaskStatus::IN_PROGRESS]);
                      personal_info[person][TaskStatus::TESTING] = 0;
                  }
              }
          }
          untouched_tasks[TaskStatus::NEW] = personal_info[person][TaskStatus::NEW];
          untouched_tasks[TaskStatus::IN_PROGRESS] = personal_info[person][TaskStatus::IN_PROGRESS];
          untouched_tasks[TaskStatus::TESTING] = personal_info[person][TaskStatus::TESTING];

          updated_tasks[TaskStatus::NEW] = untouched_tasks[TaskStatus::NEW] - updated_tasks[TaskStatus::NEW];
          updated_tasks[TaskStatus::IN_PROGRESS] = untouched_tasks[TaskStatus::IN_PROGRESS] - updated_tasks[TaskStatus::IN_PROGRESS];
          updated_tasks[TaskStatus::TESTING] = untouched_tasks[TaskStatus::TESTING] - updated_tasks[TaskStatus::TESTING];     

          return {updated_tasks, untouched_tasks};
      }
      

 private:
    map<string, TasksInfo> personal_info;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}