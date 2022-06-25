#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "sysinfo.h"
#include "proc.h"

uint64 
sys_sysinfo(void)
{
  uint64 addr;
  if(argaddr(0, &addr) < 0)
    return -1;
  struct sysinfo info;
  info.freemem = freemem();
  info.nproc = usedproc();
  struct proc *p = myproc();
  if(copyout(p->pagetable, addr, (char *)&info, sizeof(info)) < 0)
      return -1;
  return 0;
}