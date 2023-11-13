#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int err(char *msg)
{
    while (*msg)
        write(2, msg++, 1);
    return (0);
}

int cd(char **argv, int i)
{
    if (i != 2)
        return (err("error: fatal\n"));
    else if (chdir(argv[1]) == -1)
        return (err("err"), err(argv[i]), err("\n")); 
    return (0);
}

int exec(char **argv, char **envp, int i)
{
    int status;
    int fd[2];
    int has_pipe = (argv[i] && !strcmp(argv[i], "|"));

    if (has_pipe && pipe(fd) == -1)
        return (err("err: fatal\n"));
    int pid = fork();
    if (!pid)
    {
        argv[i] = 0;
        if (has_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
            return (err("err1\n"));
        execve(*argv, argv, envp);
        return (err("err2\n"));
    }
    waitpid(pid, &status, 0);
    if (has_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
        return (err("err3\n"));
    return (WIFEXITED(status), WEXITSTATUS(status));
}

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    int status = 0;

    if (argc > 1)
    {
        while (argv[i] && argv[++i])
        {
            argv += i;
            i = 0;
            while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
                i++;
            if (!strcmp(*argv, "cd"))
                status = cd(argv, i);
            else if (i)
                status = exec(argv, envp, i);
        }
        
    }
    return (status);
}
