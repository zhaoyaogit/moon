#include "../cfg/environment.h"
#include "moon_thread_pool.h"
#include "moon_config_struct.h"
#include "moon_malloc.h"
#ifdef MS_WINDOWS
#include <Windows.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif

	extern Moon_Server_Config* p_global_server_config;//��������ȫ�ֱ���

	/************************************************************************/
	/* �����̳߳�                                                           */
	/*    ����:size   �̳߳ش�С											*/
	/*	  ����ֵ�������ɹ������߳������ַ������ʧ�ܷ���NULL    			*/
	/************************************************************************/
	Array_List* moon_create_thread_pool(int size,
#ifdef MS_WINDOWS
		LPTHREAD_START_ROUTINE pFunc,
#endif
		void* param
		)
	{
		HANDLE handle = NULL;
		int i = 0;
		DWORD threadId = 0;
		Array_List* pThreads = array_list_init();
		if (pThreads == NULL)
		{
			return NULL;
		}
		for ( i = 0 ; i < size ;i++)
		{
#ifdef MS_WINDOWS
			handle = CreateThread(NULL,0,pFunc,(LPVOID)param,CREATE_SUSPENDED,&threadId);
			if (handle != NULL)
			{
				Moon_Thread* pThread = (Moon_Thread*)moon_malloc(sizeof(Moon_Thread));
				pThread->m_handle = handle;
				pThread->m_dThreadId = threadId;
				if (array_list_insert(pThreads,pThread,0) == -1)
				{
					return NULL;
				}
			}
#endif
		}
		return pThreads;
	}

#ifdef __cplusplus
}
#endif