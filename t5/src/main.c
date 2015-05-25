#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FILE* fp;
int write_data(void* apData, size_t aSize, size_t anmenb)
{
    int lCount = fwrite(apData, aSize, anmenb, (FILE*)fp);
    return lCount;
}

int main()
{
    const char* path = "/tmp/curl-test";
    const char* mode = "w";
    fp = fopen(path, mode);
    curl_global_init(CURL_GLOBAL_ALL);
    CURLcode res;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

}
