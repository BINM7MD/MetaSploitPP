#include <iostream>
#include <Windows.h>
#include "MetaSploit.h"
int main()
{
    MetaSploit MetaSploit;
    std::cout << "Welcome To MetaSploit Shell Code Executor\n";
    /*
    * Remote Process
    *   
    MetaSploit.Remote = TRUE;
    MetaSploit.Process_ID = xxxx;
    MetaSploit.Run( );
    */
    /*
    * Local Execute 
    */
    MetaSploit.Run();
}
