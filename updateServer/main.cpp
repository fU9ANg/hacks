
/**
 * @ingroup framework
 * @{
 */

#include <stdio.h>
#include "ThreadPool.h"
#include "AtomicT.h"
#include "PoolT.h"
#include "Buf.h"

#include "ProcessManager.h"

// it's rock
int main (int argc, char* argv[])
{
    ProcessManager* process = NULL;

    if ((process = new ProcessManager ()) == NULL)
    {
        cout << "ERROR: ProcessManager is NULL" << endl;
        abort ();
    }

    process->process_logic (argc, argv);

    delete process;
    return 0;
}
///@}
