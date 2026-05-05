#ifndef TODO_H
# define TODO_H

# include <stdio.h>
# include <stdlib.h>
typedef struct s_task
{
	int		id;
	char	title[100];
	int		done;
	int		priority;
	struct s_task	*next;
}	t_task;

typedef struct s_todo
{
	t_task	*head;
	int		count;
}	t_todo;

void	add_task(t_todo *todo);
//void	del_task(t_todo *todo);
//void	mark_done(t_todo *todo);

#endif
