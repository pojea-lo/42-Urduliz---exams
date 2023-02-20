#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int		error(char *str);
int		ft_cd(char **argv, int i);
int		ft_exe(char **argv, char **envp, int i);

int		fd_aux;

int		main(int argc, char **argv, char **envp) {

	int		i = 0;
	int		j = 0;

	if (argc < 2)
		return error("error: fatal\n");

	fd_aux = dup(0);

	while (argv[i] && argv[++i]) {
		argv = argv + i;
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (!strcmp(*argv, "cd"))
			j = ft_cd(argv, i);
		else
			j = ft_exe(argv, envp, i);
	}

	return (dup2(0, fd_aux) == -1 && error("error: fatal\n") | j);//duda de si hace falta
}

int		error(char *str) {

	while (*str)
		write (2, str++, 1);

	return 1;
}

int		ft_cd(char **argv, int i) {

	if (i != 2)
		return error("error: cd: bad arguments\n");
	if (chdir(argv[1]))
		return (error("error: cd: cannot change directory to ") & error(argv[1]) & error ("\n"));

	return 0;
}

int		ft_exe(char **argv, char **envp, int i) {

	int		fd[2];
	int		res;
	int		pid;
	int		pip = (argv[i] && !strcmp(argv[i], "|"));

	if (pip && pipe(fd) == -1)
		return error("error: fatal\n");
	pid = fork();
	if (pid == -1)
		return error("error: fatal\n");
	else if (!pid) {
		argv[i] = 0;//duda de si hace falta
		if (dup2(fd_aux, STDIN_FILENO) == -1 && close(fd_aux) == -1)
			return error("error: fatal\n");
		if (pip && (close(fd[0]) == -1 && dup2(fd[1], STDOUT_FILENO) == -1 && close(fd[1]) == -1))
			return error("error: fatal\n");
		execve(*argv, argv, envp);
		return (error("error: cannot execute ") & error(*argv) & error ("\n"));
	}
	else {
		if (pip && (close(fd[1]) == -1 && waitpid(pid, &res, 0) == -1 && dup2(fd[0], fd_aux) == -1 && close(fd[0]) == -1))
			return error("error: fatal\n");
		else if (!pip && (waitpid(pid, &res, 0) == -1))
			return error("error: fatal\n");
	}

	return WIFEXITED(res) && WEXITSTATUS(res);//duda de si hace falta
}
