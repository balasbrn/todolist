#include "todo.h"

void	print_welcome(void)
{
	printf("\n");
	printf("-------------------\n");
	printf(" 📝 TODO LIST : V1 \n");
	printf("-------------------\n");
}

void print_line(void)
{
	printf("-------------------\n");
}

static void print_menu(void)
{
	printf("1.Add Task  2.Mark Done  3.Delete  4.Quit\n");
	printf("\n");
	printf("Choose an option:  ");
}

int main (void)
{
	t_todo	todo;
	int		running;
	char	input_buffer[3];
	int		input_choice;
	
	todo.head = NULL;
	todo.count = 0;
	load_tasks(&todo);
	running = 1;

	while (running)
	{
		print_welcome();
		display_list(&todo);
		print_line();

		print_menu();
		fgets(input_buffer, 3, stdin);
		input_choice = atoi(input_buffer);
		if (input_choice == 4)
		{
			save_tasks(&todo);
			running = 0;
		}
		if (!(input_choice >= 1 && input_choice <= 4))
			printf("Invalid Input!\n");
		if (input_choice == 1)
			add_task(&todo);
		if (input_choice == 2)
			mark_done(&todo);
		if (input_choice == 3)
			del_task(&todo);
	}
	return (0);
}
