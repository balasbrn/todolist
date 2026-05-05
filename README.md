# Terminal Todo List

Small C side project to practice linked lists, user input, and program structure in a simple terminal app.

## Current Progress

- Defined a `t_task` node with:
  - `id`
  - `title`
  - `done`
  - `priority`
  - `next`
- Defined a `t_todo` manager with:
  - `head`
  - `count`
- Built a basic `main` loop that:
  - prints a welcome header
  - prints a menu
  - reads user input with `fgets`
  - converts input with `atoi`
  - dispatches actions
- Implemented the first working feature:
  - add a task
  - assign priority
  - insert at the front of the linked list
  - print the list after insertion

## What I Learned

- `main.c` should coordinate the program, not contain all the logic.
- A linked list node stores both task data and a `next` pointer.
- A separate list manager struct makes the app easier to organize.
- `head` points to the first node in the list.
- `count` tracks how many tasks are currently stored.
- `.` is used on a struct variable, `->` is used on a pointer to a struct.
- `fgets` reads text, so user input should first go into a char buffer.
- `atoi` converts that text input into an integer choice or priority.
- `malloc(sizeof(t_task))` allocates memory for one full task node.
- `char title[100]` is easier for a first version than `char *title`.
- Arrays are copied with string functions, not assigned directly.
- `fgets` keeps the newline, so the title string needs pruning before copy.
- Front insertion works like this:
  - `new_task->next = todo->head`
  - `todo->head = new_task`
  - `todo->count++`

## Next Steps

- Validate task priority more strictly (`1` to `5`)
- Show empty-list message when there are no tasks
- Implement mark-done
- Implement delete-task
- Save tasks to a file
- Load tasks on startup
- Add colors for display
