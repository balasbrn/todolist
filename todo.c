#include "todo.h"

void	save_tasks(t_todo *todo)
{
	FILE	*file;
	t_task	*current;

	current = todo->head;
	file = fopen("todo.text", "w");
	if(!file)
		return ;
	while (current)
	{
		fprintf(file, "%d|%d|%d|%s\n", current->id,current->done, current->priority, current->title);
		current = current->next;
	}
	fclose(file);
}

void	load_tasks(t_todo *todo)
{
	FILE	*file;
	t_task	*new_task;
	t_task	*current;
	char	line[256];

	file = fopen("todo.text", "r");
	if (!file)
		return ;
	while (fgets(line, sizeof(line), file))
	{
		new_task = malloc(sizeof(t_task));
		if (!new_task)
			break ;
		if (sscanf(line, "%d|%d|%d|%99[^\n]", &new_task->id,
				&new_task->done, &new_task->priority, new_task->title) != 4)
		{
			free(new_task);
			continue ;
		}
		new_task->next = NULL;
		if (!todo->head)
			todo->head = new_task;
		else
		{
			current = todo->head;
			while (current->next)
				current = current->next;
			current->next = new_task;
		}
		if (new_task->id > todo->count)
			todo->count = new_task->id;
	}
	fclose(file);
}

void	display_list(t_todo *todo)
{
	t_task	*current;
	int		priority;

	if (!todo->head)
	{	
		printf("\nNo Pending Tasks: Phew!\n");
		return ;
	}
	priority = 1;
	while (priority <= 4)
	{
		current = todo->head;
		while (current)
		{
			if (current->priority == priority && current->done == 0)
				printf("[%d] • %s\n", current->id, current->title);
			current = current->next;
		}
		priority++;
	}
	current = todo->head;
	while (current)
	{
		if (current->done == 1)
			printf("[%d] • %s  ✅\n", current->id, current->title);
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
}

void	del_task(t_todo *todo)
{
	t_task	*current;
	t_task	*previous;
	char	temp_del[100];
	int		del_id;

	current = todo->head;
	previous = NULL;

	printf("\nEnter ID to Delete Task : ");
	fgets(temp_del,100,stdin);
	del_id = atoi(temp_del);
	while (current)
	{
		if (current->id == del_id)
		{
			if (previous == NULL)
				todo->head = current->next;
			else
				previous->next = current->next;
			free(current);
			todo->count--;
			display_list(todo);
			return ;
		}
		previous = current;
		current = current->next;
	}
	printf("Incorrect ID!\n");
	display_list(todo);
}

void	mark_done(t_todo *todo)
{
	t_task	*current;
	char	temp_mark_id[100];
	int		mark_id;

	printf("\nEnter ID [?] to Mark Done : ");
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
