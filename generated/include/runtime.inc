#define hashRandomBytes 128
#define maxAlign 8
#define hchanSize 96
#define numBuckets 1024
#define logSize 131072
#define assoc 4
#define maxCPUProfStack 64
#define bucketCntBits 3
#define bucketCnt 8
#define maxKeySize 128
#define maxValueSize 128
#define dataOffset 8
#define empty 0
#define evacuatedEmpty 1
#define evacuatedX 2
#define evacuatedY 3
#define minTopHash 4
#define iterator 1
#define oldIterator 2
#define hashWriting 4
#define sameSizeGrow 8
#define noCheck 18446744073709551615
#define maxZero 1024
#define addrBits 48
#define cntBits 19
#define mutex_unlocked 0
#define mutex_locked 1
#define mutex_sleeping 2
#define active_spin 4
#define active_spin_cnt 30
#define passive_spin 1
#define memProfile 1
#define blockProfile 2
#define mutexProfile 3
#define buckHashSize 179999
#define maxStack 32
#define pdReady 1
#define pdWait 2
#define pollBlockSize 4096
#define freezeStopWait 2147483647
#define forcePreemptNS 10000000
#define tracebackCrash 1
#define tracebackAll 2
#define tracebackShift 2
#define caseRecv 1
#define caseSend 2
#define caseDefault 3
#define $sinkconst0 0
#define selectSend 1
#define selectRecv 2
#define selectDefault 3
#define semTabSize 251
#define semaBlockProfile 1
#define semaMutexProfile 2
#define sigIdle 0
#define sigReceiving 1
#define sigSending 2
#define smallSizeDiv 8
#define smallSizeMax 1024
#define largeSizeDiv 128
#define tmpStringBufSize 32
#define maxUint 18446744073709551615
#define maxInt 9223372036854775807
#define gcMarkWorkerDedicatedMode 0
#define gcMarkWorkerFractionalMode 1
#define gcMarkWorkerIdleMode 2
#define traceEvNone 0
#define traceEvBatch 1
#define traceEvFrequency 2
#define traceEvStack 3
#define traceEvGomaxprocs 4
#define traceEvProcStart 5
#define traceEvProcStop 6
#define traceEvGCStart 7
#define traceEvGCDone 8
#define traceEvGCScanStart 9
#define traceEvGCScanDone 10
#define traceEvGCSweepStart 11
#define traceEvGCSweepDone 12
#define traceEvGoCreate 13
#define traceEvGoStart 14
#define traceEvGoEnd 15
#define traceEvGoStop 16
#define traceEvGoSched 17
#define traceEvGoPreempt 18
#define traceEvGoSleep 19
#define traceEvGoBlock 20
#define traceEvGoUnblock 21
#define traceEvGoBlockSend 22
#define traceEvGoBlockRecv 23
#define traceEvGoBlockSelect 24
#define traceEvGoBlockSync 25
#define traceEvGoBlockCond 26
#define traceEvGoBlockNet 27
#define traceEvGoSysCall 28
#define traceEvGoSysExit 29
#define traceEvGoSysBlock 30
#define traceEvGoWaiting 31
#define traceEvGoInSyscall 32
#define traceEvHeapAlloc 33
#define traceEvNextGC 34
#define traceEvTimerGoroutine 35
#define traceEvFutileWakeup 36
#define traceEvString 37
#define traceEvGoStartLocal 38
#define traceEvGoUnblockLocal 39
#define traceEvGoSysExitLocal 40
#define traceEvGoStartLabel 41
#define traceEvGoBlockGC 42
#define traceEvCount 43
#define traceTickDiv 64
#define traceStackSize 128
#define traceBytesPerNumber 10
#define traceArgCountShift 6
#define traceFutileWakeup 128
#define kindBool 1
#define kindInt 2
#define kindInt8 3
#define kindInt16 4
#define kindInt32 5
#define kindInt64 6
#define kindUint 7
#define kindUint8 8
#define kindUint16 9
#define kindUint32 10
#define kindUint64 11
#define kindUintptr 12
#define kindFloat32 13
#define kindFloat64 14
#define kindComplex64 15
#define kindComplex128 16
#define kindArray 17
#define kindChan 18
#define kindFunc 19
#define kindInterface 20
#define kindMap 21
#define kindPtr 22
#define kindSlice 23
#define kindString 24
#define kindStruct 25
#define kindUnsafePointer 26
#define kindDirectIface 32
#define kindGCProg 64
#define kindNoPointers 128
#define kindMask 31
#define runeError 65533
#define runeSelf 128
#define maxRune 1114111
#define surrogateMin 55296
#define surrogateMax 57343
#define t1 0
#define tx 128
#define t2 192
#define t3 224
#define t4 240
#define t5 248
#define maskx 63
#define mask2 31
#define mask3 15
#define mask4 7
#define rune1Max 127
#define rune2Max 2047
#define rune3Max 65535
#define locb 128
#define hicb 191

struct sudog;

struct waitq {
	struct sudog* first;
	struct sudog* last;
};

struct cpuprofEntry {
	uintptr_t count;
	int64_t depth;
	uintptr_t stack[64];
};

struct TypeAssertionError {
	String interfaceString;
	String concreteString;
	String assertedString;
	String missingMethod;
};

struct errorCString {
	uintptr_t cstr;
};

struct bmap {
	uint8_t tophash[8];
};

struct hiter {
	void* key;
	void* value;
	void* t;
	void* h;
	void* buckets;
	struct bmap* bptr;
	Slice* overflow[2];
	uintptr_t startBucket;
	uint8_t offset;
	_Bool wrapped;
	uint8_t B;
	uint8_t i;
	uintptr_t bucket;
	uintptr_t checkBucket;
};

struct mlink;

struct mcachelist {
	struct mlink* list;
	uint32_t nlist;
};

struct mspan;

struct mcache {
	int32_t next_sample;
	uintptr_t local_cachealloc;
	void* tiny;
	uintptr_t tinysize;
	struct mspan* alloc[67];
	struct mcachelist free[67];
	uintptr_t local_nlookup;
	uintptr_t local_largefree;
	uintptr_t local_nlargefree;
	uintptr_t local_nsmallfree[67];
};

struct mtypes {
	uint8_t compression;
	uintptr_t data;
};

struct special {
	struct special* next;
	uint16_t offset;
	uint8_t kind;
};

struct mlink {
	struct mlink* next;
};

struct bucket {
	struct bucket* next;
	struct bucket* allnext;
	int64_t typ;
	uintptr_t hash;
	uintptr_t size;
	uintptr_t nstk;
};

struct memRecord {
	uintptr_t allocs;
	uintptr_t frees;
	uintptr_t alloc_bytes;
	uintptr_t free_bytes;
	uintptr_t prev_allocs;
	uintptr_t prev_frees;
	uintptr_t prev_alloc_bytes;
	uintptr_t prev_free_bytes;
	uintptr_t recent_allocs;
	uintptr_t recent_frees;
	uintptr_t recent_alloc_bytes;
	uintptr_t recent_free_bytes;
};

struct blockRecord {
	int64_t count;
	int64_t cycles;
};

struct StackRecord {
	uintptr_t Stack0[32];
};

struct MemProfileRecord {
	int64_t AllocBytes;
	int64_t FreeBytes;
	int64_t AllocObjects;
	int64_t FreeObjects;
	uintptr_t Stack0[32];
};

struct mstats {
	uint64_t alloc;
	uint64_t total_alloc;
	uint64_t sys;
	uint64_t nlookup;
	uint64_t nmalloc;
	uint64_t nfree;
	uint64_t heap_alloc;
	uint64_t heap_sys;
	uint64_t heap_idle;
	uint64_t heap_inuse;
	uint64_t heap_released;
	uint64_t heap_objects;
	uint64_t stacks_inuse;
	uint64_t stacks_sys;
	uint64_t mspan_inuse;
	uint64_t mspan_sys;
	uint64_t mcache_inuse;
	uint64_t mcache_sys;
	uint64_t buckhash_sys;
	uint64_t gc_sys;
	uint64_t other_sys;
	uint64_t next_gc;
	uint64_t last_gc;
	uint64_t pause_total_ns;
	uint64_t pause_ns[256];
	uint64_t pause_end[256];
	uint32_t numgc;
	uint32_t numforcedgc;
	double gc_cpu_fraction;
	_Bool enablegc;
	_Bool debuggc;
	struct {
	uint32_t size;
	uint64_t nmalloc;
	uint64_t nfree;
	} by_size[67];
	uint64_t tinyallocs;
	uint64_t gc_trigger;
	uint64_t heap_live;
	uint64_t heap_scan;
	uint64_t heap_marked;
};

struct MemStats {
	uint64_t Alloc;
	uint64_t TotalAlloc;
	uint64_t Sys;
	uint64_t Lookups;
	uint64_t Mallocs;
	uint64_t Frees;
	uint64_t HeapAlloc;
	uint64_t HeapSys;
	uint64_t HeapIdle;
	uint64_t HeapInuse;
	uint64_t HeapReleased;
	uint64_t HeapObjects;
	uint64_t StackInuse;
	uint64_t StackSys;
	uint64_t MSpanInuse;
	uint64_t MSpanSys;
	uint64_t MCacheInuse;
	uint64_t MCacheSys;
	uint64_t BuckHashSys;
	uint64_t GCSys;
	uint64_t OtherSys;
	uint64_t NextGC;
	uint64_t LastGC;
	uint64_t PauseTotalNs;
	uint64_t PauseNs[256];
	uint64_t PauseEnd[256];
	uint32_t NumGC;
	uint32_t NumForcedGC;
	double GCCPUFraction;
	_Bool EnableGC;
	_Bool DebugGC;
	struct {
	uint32_t Size;
	uint64_t Mallocs;
	uint64_t Frees;
	} BySize[61];
};

struct mOS {
	uint8_t unused;
};

struct randomOrder {
	uint32_t count;
	Slice coprimes;
};

struct randomEnum {
	uint32_t i;
	uint32_t count;
	uint32_t pos;
	uint32_t inc;
};

struct dbgVar {
	String name;
	int32_t* value;
};

struct debugVars {
	int32_t allocfreetrace;
	int32_t cgocheck;
	int32_t efence;
	int32_t gccheckmark;
	int32_t gcpacertrace;
	int32_t gcshrinkstackoff;
	int32_t gcstackbarrieroff;
	int32_t gcstackbarrierall;
	int32_t gcrescanstacks;
	int32_t gcstoptheworld;
	int32_t gctrace;
	int32_t invalidptr;
	int32_t sbrk;
	int32_t scavenge;
	int32_t scheddetail;
	int32_t schedtrace;
	int32_t wbshadow;
};

struct mutex {
	uintptr_t key;
};

struct note {
	uintptr_t key;
};

struct funcval {
	uintptr_t fn;
};

struct iface {
	void* tab;
	void* data;
};

struct eface {
	void* _type;
	void* data;
};

struct g;

struct hchan;

struct sudog {
	struct g* g;
	uint32_t* selectdone;
	struct sudog* next;
	struct sudog* prev;
	void* elem;
	int64_t acquiretime;
	int64_t releasetime;
	uint32_t ticket;
	struct sudog* waitlink;
	struct hchan* c;
};

struct gcstats {
	uint64_t nhandoff;
	uint64_t nhandoffcnt;
	uint64_t nprocyield;
	uint64_t nosyield;
	uint64_t nsleep;
};

struct _panic;

struct _defer;

struct m;

struct tracebackg;

struct g {
	struct _panic* _panic;
	struct _defer* _defer;
	struct m* m;
	uintptr_t syscallsp;
	uintptr_t syscallpc;
	void* param;
	uint32_t atomicstatus;
	int64_t goid;
	int64_t waitsince;
	String waitreason;
	uint64_t schedlink;
	_Bool preempt;
	_Bool paniconfault;
	_Bool preemptscan;
	_Bool gcscandone;
	_Bool gcscanvalid;
	_Bool throwsplit;
	int8_t raceignore;
	_Bool sysblocktraced;
	int64_t sysexitticks;
	uint64_t traceseq;
	uint64_t tracelastp;
	struct m* lockedm;
	uint32_t sig;
	Slice writebuf;
	uintptr_t sigcode0;
	uintptr_t sigcode1;
	uintptr_t sigpc;
	uintptr_t gopc;
	uintptr_t startpc;
	struct sudog* waiting;
	int32_t gcRescan;
	int64_t gcAssistBytes;
	void* exception;
	_Bool isforeign;
	void* gcstack;
	uintptr_t gcstacksize;
	void* gcnextsegment;
	void* gcnextsp;
	void* gcinitialsp;
	void* gcregs[122];
	void* entry;
	_Bool fromgogo;
	_Bool issystem;
	_Bool isbackground;
	struct tracebackg* traceback;
	void* context[122];
	void* stackcontext[10];
};

struct p {
	struct mutex lock;
	int32_t id;
	uint32_t status;
	uint64_t link;
	uint32_t schedtick;
	uint32_t syscalltick;
	uint64_t m;
	struct mcache* mcache;
	Slice deferpool;
	struct _defer* deferpoolbuf[32];
	uint64_t goidcache;
	uint64_t goidcacheend;
	uint32_t runqhead;
	uint32_t runqtail;
	uint64_t runq[256];
	uint64_t runnext;
	struct g* gfree;
	int32_t gfreecnt;
	Slice sudogcache;
	struct sudog* sudogbuf[128];
	uint64_t tracebuf;
	int64_t gcAssistTime;
	uint64_t gcBgMarkWorker;
	int64_t gcMarkWorkerMode;
	uint32_t runSafePointFn;
	uint8_t pad[64];
};

struct schedt {
	uint64_t goidgen;
	uint64_t lastpoll;
	struct mutex lock;
	uint64_t midle;
	int32_t nmidle;
	int32_t nmidlelocked;
	int32_t mcount;
	int32_t maxmcount;
	uint32_t ngsys;
	uint64_t pidle;
	uint32_t npidle;
	uint32_t nmspinning;
	uint64_t runqhead;
	uint64_t runqtail;
	int32_t runqsize;
	struct mutex gflock;
	struct g* gfree;
	int32_t ngfree;
	struct mutex sudoglock;
	struct sudog* sudogcache;
	struct mutex deferlock;
	struct _defer* deferpool;
	uint32_t gcwaiting;
	int32_t stopwait;
	struct note stopnote;
	uint32_t sysmonwait;
	struct note sysmonnote;
	FuncVal* safePointFn;
	int32_t safePointWait;
	struct note safePointNote;
	int32_t profilehz;
	int64_t procresizetime;
	int64_t totaltime;
};

struct lfnode {
	uint64_t next;
	uintptr_t pushcnt;
};

struct forcegcstate {
	struct mutex lock;
	struct g* g;
	uint32_t idle;
};

struct _defer {
	struct _defer* link;
	_Bool* frame;
	struct _panic* _panic;
	uintptr_t pfn;
	void* arg;
	uintptr_t retaddr;
	_Bool makefunccanrecover;
	_Bool special;
};

struct _panic {
	struct _panic* link;
	Eface arg;
	_Bool recovered;
	_Bool isforeign;
};

struct sigset {
	uint64_t __val[16];
};

struct scase {
	void* elem;
	struct hchan* c;
	uintptr_t pc;
	uint16_t kind;
	uint16_t index;
	_Bool* receivedp;
	int64_t releasetime;
};

struct runtimeSelect {
	int64_t dir;
	void* typ;
	struct hchan* ch;
	void* val;
};

struct semaRoot {
	struct mutex lock;
	struct sudog* head;
	struct sudog* tail;
	uint32_t nwait;
};

struct notifyList {
	uint32_t wait;
	uint32_t notify;
	struct mutex lock;
	struct sudog* head;
	struct sudog* tail;
};

struct sigTabT {
	int32_t flags;
	String name;
};

struct _siginfo_t;

struct sigctxt {
	struct _siginfo_t* info;
	void* ctxt;
};

struct divMagic {
	uint8_t shift;
	uint8_t shift2;
	uint16_t mul;
	uint16_t baseMask;
};

struct slice {
	void* array;
	int64_t len;
	int64_t cap;
};

struct stringStruct {
	void* str;
	int64_t len;
};

struct stringStructDWARF {
	uint8_t* str;
	int64_t len;
};

struct Frames {
	Slice callers;
	uintptr_t last;
	int64_t lastCount;
};

struct Func;

struct Frame {
	uintptr_t PC;
	struct Func* Func;
	String Function;
	String File;
	int64_t Line;
	uintptr_t Entry;
};

struct Func {
	String name;
	uintptr_t entry;
};

struct timer {
	int64_t i;
	int64_t when;
	int64_t period;
	FuncVal* f;
	Eface arg;
	uintptr_t seq;
};

struct traceFrame {
	uint64_t funcID;
	uint64_t fileID;
	uint64_t line;
};

struct traceAlloc {
	uint64_t head;
	uintptr_t off;
};

struct traceAllocBlock {
	uint64_t next;
	uint8_t data[65528];
};

struct location {
	uintptr_t pc;
	String filename;
	String function;
	int64_t lineno;
};

struct method {
	String* name;
	String* pkgPath;
	void* mtyp;
	void* typ;
	void* tfn;
};

struct uncommontype {
	String* name;
	String* pkgPath;
	Slice methods;
};

struct imethod {
	String* name;
	String* pkgPath;
	void* typ;
};

struct structfield {
	String* name;
	String* pkgPath;
	void* typ;
	String* tag;
	uintptr_t offset;
};

struct timeval {
	int64_t tv_sec;
	int64_t tv_usec;
};

struct timespec {
	int64_t tv_sec;
	int64_t tv_nsec;
};

struct epollevent {
	uint32_t events;
	uint8_t data[8];
};

struct semt {
	int8_t __size[32];
	int64_t Godump_0_align[0];
};

struct hchan {
	uint64_t qcount;
	uint64_t dataqsiz;
	void* buf;
	uint16_t elemsize;
	uint32_t closed;
	void* elemtype;
	uint64_t sendx;
	uint64_t recvx;
	struct waitq recvq;
	struct waitq sendq;
	struct mutex lock;
};

struct cpuProfile {
	_Bool on;
	struct note wait;
	uintptr_t count;
	uintptr_t evicts;
	uintptr_t lost;
	struct {
	struct cpuprofEntry entry[4];
	} hash[1024];
	uintptr_t log[65536][2];
	int64_t nlog;
	int32_t toggle;
	uint32_t handoff;
	uint32_t wtoggle;
	_Bool wholding;
	_Bool flushing;
	_Bool eodSent;
};

struct mspan {
	struct mspan* next;
	struct mspan* prev;
	uintptr_t start;
	uintptr_t npages;
	struct mlink* freelist;
	uint32_t sweepgen;
	uint16_t ref;
	uint8_t sizeclass;
	_Bool incache;
	uint8_t state;
	uint8_t needzero;
	uintptr_t elemsize;
	int64_t unusedsince;
	uintptr_t npreleased;
	uintptr_t limit;
	struct mtypes types;
	struct mutex speciallock;
	struct special* specials;
	struct mlink* freebuf;
};

struct pollDesc {
	struct pollDesc* link;
	struct mutex lock;
	uintptr_t fd;
	_Bool closing;
	uintptr_t seq;
	uintptr_t rg;
	struct timer rt;
	int64_t rd;
	uintptr_t wg;
	struct timer wt;
	int64_t wd;
	uint32_t user;
};

struct pollCache {
	struct mutex lock;
	struct pollDesc* first;
};

struct m {
	struct g* g0;
	uint64_t procid;
	struct g* gsignal;
	struct sigset sigmask;
	uintptr_t mstartfn;
	struct g* curg;
	uint64_t caughtsig;
	uint64_t p;
	uint64_t nextp;
	int32_t id;
	int32_t mallocing;
	int32_t throwing;
	String preemptoff;
	int32_t locks;
	int32_t softfloat;
	int32_t dying;
	int32_t profilehz;
	int32_t helpgc;
	_Bool spinning;
	_Bool blocked;
	_Bool inwb;
	_Bool newSigstack;
	int8_t printlock;
	uint32_t fastrand;
	uint64_t ncgocall;
	int32_t ncgo;
	struct note park;
	struct m* alllink;
	uint64_t schedlink;
	struct mcache* mcache;
	struct g* lockedg;
	struct location createstack[32];
	uint32_t locked;
	uintptr_t nextwaitm;
	struct gcstats gcstats;
	_Bool needextram;
	uint8_t traceback;
	void* waitunlockf;
	void* waitlock;
	uint8_t waittraceev;
	int64_t waittraceskip;
	_Bool startingtrace;
	uint32_t syscalltick;
	struct mOS mos;
	void* gsignalstack;
	uintptr_t gsignalstacksize;
	_Bool dropextram;
	int32_t gcing;
};

struct hselect {
	uint16_t tcase;
	uint16_t ncase;
	uint16_t* pollorder;
	uint16_t* lockorder;
	struct scase scase[1];
};

struct traceBufHeader {
	uint64_t link;
	uint64_t lastTicks;
	int64_t pos;
	struct location stk[128];
};

struct traceStackTable {
	struct mutex lock;
	uint32_t seq;
	struct traceAlloc mem;
	uint64_t tab[8192];
};

struct traceStack {
	uint64_t link;
	uintptr_t hash;
	uint32_t id;
	int64_t n;
	struct location stk[0];
};

struct tracebackg {
	struct g* gp;
	struct location locbuf[100];
	int64_t c;
};
#define _Gidle 0
#define _Grunnable 1
#define _Grunning 2
#define _Gsyscall 3
#define _Gwaiting 4
#define _Gmoribund_unused 5
#define _Gdead 6
#define _Genqueue_unused 7
#define _Gcopystack 8
#define _Gscan 4096
#define _Gscanrunnable 4097
#define _Gscanrunning 4098
#define _Gscansyscall 4099
#define _Gscanwaiting 4100
#define _Pidle 0
#define _Prunning 1
#define _Psyscall 2
#define _Pgcstop 3
#define _Pdead 4
#define _PageShift 13
#define _MaxGomaxprocs 256
#define _MaxSmallSize 32768
#define _MaxMem 549755813887
#define _MaxGcproc 32
#define _LockExternal 1
#define _LockInternal 2
#define _SigNotify 1
#define _SigKill 2
#define _SigThrow 4
#define _SigPanic 8
#define _SigDefault 16
#define _SigHandling 32
#define _SigGoExit 64
#define _SigSetStack 128
#define _SigUnblock 256
#define _TraceRuntimeFrames 1
#define _TraceTrap 2
#define _TraceJumpStack 4
#define _TracebackMaxFrames 100
#define _MHeapMap_TotalBits 39
#define _NumSizeClasses 67
