#include <unistd.h>
#include <sys/wait.h>

int real_waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options, void*);

int main() {
    char command[255];
    for (;;) {
        write(1, "> ", 2);
        int count = read(0, command, 255);
        command[count - 1] = '\0'; // Replace newline with null terminator
        pid_t fork_result = fork();
        if (fork_result == 0) {
            execve(command, 0, 0);
            break;
        } else {
            // wait
            siginfo_t info;
            real_waitid(P_ALL, 0, &info, WEXITED, 0);
        }
    }
}