#include "todo.h"

static void	display_list(t_todo *todo)
{
	t_task	*current;

	if (!todo->head)
	{	
		printf("\nNo Pending Tasks: Phew!\n");
		return ;
	}
	current = todo->head;
	while (current)
	{
		if (current->done == 1)
			printf("✅ %s \n", current->title);
		else
			printf("• %s - Urgency : %d\n", current->title, current->priority);
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
	printf("\nEnter task priority(1 to 4): ");
	fgets(temp_priority, 3, stdin);
	new_task->priority = atoi(temp_priority);
	while (!(new_task->priority >= 1 && new_task->priority <= 4))
	{
		printf("\nEnter a valid response (1 to 4) : ");
		fgets(temp_priority, 3, stdin);
		new_task->priority = atoi(temp_priority);
	}
	strprune(temp_title);
	strcpy(new_task->title, temp_title);
	new_task->done = 0;
	new_task->id = todo->count + 1; // adding id
	new_task->next = todo->head; // coping todo->head null to new next
	todo->head = new_task; // then making new next is the todo head
	todo->count++;
	display_list(todo);
}

void	del_task(t_todo *todo)
{
	t_task	*current;
	t_task	*previous;
	char	temp_del[100];
	int		del_id;

	current = todo->head;
	previous = NULL;

	printf("\nEnter ID to Delete Task");
	fgets(temp_del,100,stdin);
	del_id = atoi(temp_del);
	while (current)
	{
		if (current->id == del_id)
		{
			previous = current;
			current->next->next = current->next;
		}

	}
}

void	mark_done(t_todo *todo)
{
	t_task	*current;
	char	temp_mark_id[100];
	int		mark_id;

	printf("\nEnter ID to Mark Done : ");
	fgets(temp_mark_id,100,stdin);
	mark_id = atoi(temp_mark_id);
	current = todo->head;
	while(current)
	{
		if(current->id == mark_id)
		{
			current->done = 1;
			display_list(todo);
			return ;
		}
		current = current->next;
	}
	printf("Incorrect ID ! \n");
	display_list(todo);
}
