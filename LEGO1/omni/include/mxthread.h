#ifndef MXTHREAD_H
#define MXTHREAD_H

#include "compat.h"
#include "mxsemaphore.h"
#include "mxtypes.h"

#include <SDL3/SDL_thread.h>

class MxCore;

// VTABLE: LEGO1 0x100dc860
// SIZE 0x1c
class MxThread {
public:
	// Note: Comes before virtual destructor
	virtual MxResult Run();

	MxResult Start(MxS32 p_stack, MxS32 p_flag);

	void Terminate();
	void Sleep(MxS32 p_milliseconds);

	inline MxBool IsRunning() { return m_running; }

	// SYNTHETIC: LEGO1 0x100bf580
	// MxThread::`scalar deleting destructor'

protected:
	MxThread();

public:
	virtual ~MxThread();

private:
	static unsigned ThreadProc(void* p_thread);

	SDL_Thread* m_thread;
	MxBool m_running;
	MxSemaphore m_semaphore;

protected:
	MxCore* m_target; // 0x18
};

#endif // MXTHREAD_H
