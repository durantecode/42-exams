#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// #include <stdio.h>

#define READ_END 0
#define WRITE_END 1

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_cd(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return (-1);
	}
	if (chdir(argv[1]) < 0)
	{
		write(2, "error: cd: cannot change directory to ", 38);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
		return (-1);
	}
	return (0);
}
int		is_pipe(char *argv[])
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (argv[i])
	{
		if (strncmp(argv[i], "|", 2) == 0)
		{
			ret = 1;
			argv[i] = NULL;
			break ;
		}
		if (strncmp(argv[i], ";", 2) == 0)
		{
			ret = 0;
			argv[i] = NULL;
			break ;
		}
		i++;
	}
	return (ret);
}

void	command(int argc, char **argv, char **envp, int prev_cmd, int *fd_prev)
{
	int		exit_status;
	int		i;
	int		next_cmd;
	int		fd_next[2];
	pid_t	pid;

	if (argc <= 1)
		return ;
	next_cmd = is_pipe(argv);
	if (argv[0])
	{
		if (next_cmd && pipe(fd_next) < 0)
		{
			write(2, "error: fatal\n", 13);
			exit(1);
		}
		if (strncmp(argv[0], "cd", 3) == 0)
			ft_cd(argv);
		else if ((pid = fork()) < 0)
		{
			write(2, "error: fatal\n", 13);
			exit(1);
		}
		else if (pid == 0)
		{
			if (prev_cmd && dup2(fd_prev[READ_END], STDIN_FILENO) < 0)
				exit(-1);
			if (next_cmd && dup2(fd_next[WRITE_END], STDOUT_FILENO) < 0)
				exit(-1);
			if (execve(argv[0], argv, envp) < 0)
			{
				write(2, "error: cannot execute ", 22);
				write(2, argv[0], ft_strlen(argv[0]));
				write(2, "\n", 1);
				exit(1);
			}
		}
		else
		{
			if (waitpid(pid, &exit_status, 0) < 0)
			{
				write(2, "error: fatal\n", 13);
				exit(1);
			}
			if (exit_status / 256 == 255)
			{
				write(2, "error: fatal\n", 13);
				exit(1);
			}
			if (prev_cmd)
				close(fd_prev[0]);
			if (next_cmd)
				close(fd_next[1]);
		}
	}
	i = 0;
	while (argv[i])
		i++;
	command(argc - i - 1, argv + i + 1, envp, next_cmd, fd_next);
}

int		main(int argc, char **argv, char **envp)
{
	int	prev_cmd;
	int	fd_prev[2];

	prev_cmd = 0;
	fd_prev[READ_END] = 0;
	fd_prev[WRITE_END] = 1;
	command(argc, argv + 1, envp, prev_cmd, fd_prev);
    // while (1);
	return (0);
}
