# Terminal Todo List

A small terminal-based todo app written in C.

You can add tasks, mark tasks as done, delete tasks, and keep your list saved between runs.

## How to Run

Open a terminal in the folder that contains the `todo` file.

Run the app:

```sh
./todo
```

If the terminal says permission is denied, run this once:

```sh
chmod +x todo
./todo
```

## What You Can Do

- Add a new task with a priority from `1` to `4`
- View pending and completed tasks
- Mark a task as done using its task ID
- Delete a task using its task ID
- Quit the program and save your list automatically
- Reopen the program and continue from the saved list

## Menu Options

When the app starts, choose one of these options:

```text
1. Add Task
2. Mark Done
3. Delete
4. Quit
```

## Saving

Tasks are saved automatically when you quit with option `4`.

The app saves data in:

```text
todo.text
```

If `todo.text` does not exist yet, the app creates it when saving.

## Notes

- Task IDs are shown beside pending tasks.
- Use the task ID when marking a task as done or deleting it.
- Do not edit `todo.text` manually unless you know the save format.
