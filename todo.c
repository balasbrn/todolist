#include "todo.h"

static void	display_list(t_todo *todo)
{
	t_task	*current;

	current = todo->head;
	while (current)
	{
		printf("\n%s - Urgency : %d\n", current->title, current->priority);
		current = current->next;
	}
}

static void strprune(char *temp_title)
{
	int	i;
	
	i = 0;
	while (temp_title[i])
	{
		if (temp_title[i] == '\n')
		{
			temp_title[i] = '\0';
			break ;
		}
		i++;
	}
}

void	add_task(t_todo *todo)
{
	t_task	*new_task;
	char	temp_title[100];
	char	temp_priority[3];
	new_task = malloc(sizeof(t_task));
	if (!new_task)
		return ;
	printf("\nEnter a task: ");
	fgets(temp_title, 100, stdin);
	printf("\nEnter task priority(1 to 5): ");
	fgets(temp_priority, 3, stdin);
	strprune(temp_title);
	strcpy(new_task->title, temp_title);
	new_task->priority = atoi(temp_priority);
	new_task->done = 0;
	new_task->id = todo->count + 1; // adding id
	new_task->next = todo->head; // coping todo->head null to new next
	todo->head = new_task; // then making new next is the todo head
	todo->count++;
	display_list(todo);
}

void	del_task(t_todo *todo)
{

}

void	mark_done(t_todo *todo)
{

}
