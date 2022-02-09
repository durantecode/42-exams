#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READ_END 0
#define WRITE_END 1

#define ERR_FATAL "error: fatal\n"
#define ERR_CD "error: cd: bad arguments\n"
#define ERR_DIR "error: cd: cannot change directory to "
#define ERR_EXEC "error: cannot execute "

int ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int cd(char **argv)
{
    if (argv[2])
    {
        write(2, ERR_CD, ft_strlen(ERR_CD));
        return (-1); 
    }
    if (chdir(argv[1]) < 0)
    {
        write(2, ERR_DIR, ft_strlen(ERR_CD));
        write(2, argv[1], ft_strlen(argv[1]));
        write(2, "\n", 1);
        return (-1);
    }
    return (0);
}

int     is_pipe(char **argv)
{
    int i;
    int ret;

    i = 0;
    ret = 0;
    while(argv[i])
    {
        if (!strcmp(argv[i], "|"))
        {
            ret = 1;
            argv[i] = NULL;
            break ;
        }
        if (!strcmp(argv[i], ";"))
        {
            ret = 0;
            argv[i] = NULL;
            break ;
        }
        i++;
    }
    return (ret);
}

void    command(int argc, char **argv, char **envp, int prev_cmd, int *fd_prev)
{
    int i;
    int exit_status;
    int fd_next[2];
    int next_cmd;
    pid_t pid;

    if (argc <= 1)
        return ;
    next_cmd = is_pipe(argv);
    if (argv[0])
    {
        if (next_cmd && pipe(fd_next) < 0)
        {
            write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
            exit (1);
        }
        if (!strcmp(argv[0], "cd"))
            cd(argv);
        else if ((pid = fork()) < 0)
        {
            write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
            exit (1);
        }
        else if (!pid)
        {
            if (prev_cmd && dup2(fd_prev[READ_END], STDIN_FILENO) < 0)
            {
                write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
                exit (1);
            }
            if (next_cmd && dup2(fd_next[WRITE_END], STDOUT_FILENO) < 0)
            {
                write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
                exit (1);
            }
            if (execve(argv[0], argv, envp) < 0)
            {
                write(2, ERR_EXEC, ft_strlen(ERR_EXEC));
                write(2, argv[0], ft_strlen(argv[0]));
                write(2, "\n", 1);
                exit (1);
            }
            else
            {
                if (waitpid(pid, &exit_status, 0) < 0)
                {
                    write(2, ERR_FATAL, ft_strlen(ERR_FATAL));
                    exit (1);
                }
                if (prev_cmd)
                    close(fd_prev[READ_END]);
                if (next_cmd)
                    close(fd_next[WRITE_END]);
            }
        }
    }
    i = 0;
    while (argv[i])
        i++;
    command(argc - i - 1, argv + i + 1, envp, next_cmd, fd_next);
}

int main(int argc, char **argv, char **envp)
{
    int prev_cmd;
    int fd_prev[2];

    prev_cmd = 0;
    fd_prev[READ_END] = 0;
    fd_prev[WRITE_END] = 1;
    command(argc, argv + 1, envp, prev_cmd, fd_prev);
    return (0);
}