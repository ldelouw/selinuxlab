#include <stdio.h>    //printf(3)
#include <stdlib.h>   //exit(3)
#include <unistd.h>   //fork(3), chdir(3), sysconf(3)
#include <signal.h>   //signal(3)
#include <sys/stat.h> //umask(3)
#include <syslog.h>   //syslog(3), openlog(3), closelog(3)
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>
#define MAXHOSTNAME 256
using namespace std;

int main()
{
    int ttl=999999;
    int delay=5;

    pid_t pid = fork();

    if (pid == 0)
    {
        // child process
        openlog("testapp",LOG_PID,LOG_DAEMON);

        while( 1 )
        {
            syslog(LOG_NOTICE,"daemon ttl %d",ttl);
            sleep(delay);
            ttl-=delay;
        }
        syslog(LOG_NOTICE,"daemon ttl expired");
        closelog();
        return(EXIT_SUCCESS);
    }
    if (pid > 0)
    {
        string filename = "/var/run/testapp.pid";
        ofstream o(filename.c_str());
        o << pid << endl;

        ifstream meminfo;
	    meminfo.open("/proc/meminfo");
        meminfo.close();

        CURL *curl;
        CURLcode res;

        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, "lukas-vrabec.com");
            res = curl_easy_perform(curl);
            /* always cleanup */
            curl_easy_cleanup(curl);
        }

        syslog(LOG_NOTICE,"testapp parent process");
        return(EXIT_SUCCESS);
    }
}
