#define hashRandomBytes 128
#define maxAlign 8
#define hchanSize 96
#define maxCPUProfStack 64
#define debugLogBytes 16384
#define debugLogStringLimit 2048
#define debugLogUnknown 1
#define debugLogBoolTrue 2
#define debugLogBoolFalse 3
#define debugLogInt 4
#define debugLogUint 5
#define debugLogHex 6
#define debugLogPtr 7
#define debugLogString 8
#define debugLogConstString 9
#define debugLogStringOverflow 10
#define debugLogPC 11
#define debugLogTraceback 12
#define debugLogHeaderSize 2
#define debugLogSyncSize 18
#define boundsIndex 0
#define boundsSliceAlen 1
#define boundsSliceAcap 2
#define boundsSliceB 3
#define boundsSlice3Alen 4
#define boundsSlice3Acap 5
#define boundsSlice3B 6
#define boundsSlice3C 7
#define boundsConvert 8
#define fastlogNumBits 5
#define fieldKindEol 0
#define fieldKindPtr 1
#define fieldKindIface 2
#define fieldKindEface 3
#define tagEOF 0
#define tagObject 1
#define tagOtherRoot 2
#define tagType 3
#define tagGoroutine 4
#define tagStackFrame 5
#define tagParams 6
#define tagFinalizer 7
#define tagItab 8
#define tagOSThread 9
#define tagMemStats 10
#define tagQueuedFinalizer 11
#define tagData 12
#define tagBSS 13
#define tagDefer 14
#define tagPanic 15
#define tagMemProf 16
#define tagAllocSample 17
#define bufSize 4096
#define typeCacheBuckets 256
#define typeCacheAssoc 4
#define timeHistSubBucketBits 4
#define timeHistNumSubBuckets 16
#define timeHistNumSuperBuckets 45
#define timeHistTotalBuckets 721
#define fInf 9218868437227405312
#define fNegInf 18442240474082181120
#define itabInitSize 512
#define addrBits 48
#define cntBits 19
#define sparcLinuxAddrBits 52
#define sparcLinuxCntBits 15
#define ia64AddrBits 55
#define ia64CntBits 12
#define aixAddrBits 57
#define aixCntBits 10
#define mutex_unlocked 0
#define mutex_locked 1
#define mutex_sleeping 2
#define active_spin 4
#define active_spin_cnt 30
#define passive_spin 1
#define lockRankDummy 0
#define lockRankSysmon 1
#define lockRankScavenge 2
#define lockRankForcegc 3
#define lockRankSweepWaiters 4
#define lockRankAssistQueue 5
#define lockRankCpuprof 6
#define lockRankSweep 7
#define lockRankPollDesc 8
#define lockRankSched 9
#define lockRankDeadlock 10
#define lockRankAllg 11
#define lockRankAllp 12
#define lockRankTimers 13
#define lockRankItab 14
#define lockRankReflectOffs 15
#define lockRankHchan 16
#define lockRankTraceBuf 17
#define lockRankFin 18
#define lockRankNotifyList 19
#define lockRankTraceStrings 20
#define lockRankMspanSpecial 21
#define lockRankProf 22
#define lockRankGcBitsArenas 23
#define lockRankRoot 24
#define lockRankTrace 25
#define lockRankTraceStackTab 26
#define lockRankNetpollInit 27
#define lockRankRwmutexW 28
#define lockRankRwmutexR 29
#define lockRankSpanSetSpine 30
#define lockRankGscan 31
#define lockRankStackpool 32
#define lockRankStackLarge 33
#define lockRankDefer 34
#define lockRankSudog 35
#define lockRankWbufSpans 36
#define lockRankMheap 37
#define lockRankMheapSpecial 38
#define lockRankGlobalAlloc 39
#define lockRankPageAllocScav 40
#define lockRankGFree 41
#define lockRankHchanLeaf 42
#define lockRankPanic 43
#define lockRankNewmHandoff 44
#define lockRankDebugPtrmask 45
#define lockRankFaketimeState 46
#define lockRankTicks 47
#define lockRankRaceFini 48
#define lockRankPollCache 49
#define lockRankDebug 50
#define lockRankLeafRank 1000
#define maxTinySize 16
#define tinySizeClass 2
#define maxSmallSize 32768
#define pageShift 13
#define pageSize 8192
#define pageMask 8191
#define maxObjsPerSpan 1024
#define heapAddrBits 48
#define maxAlloc 281474976710656
#define heapArenaBytes 67108864
#define logHeapArenaBytes 26
#define heapArenaBitmapBytes 2097152
#define pagesPerArena 8192
#define arenaL1Bits 0
#define arenaL2Bits 22
#define arenaL1Shift 22
#define arenaBits 22
#define arenaBaseOffset 18446603336221196288
#define arenaBaseOffsetUintptr 18446603336221196288
#define minLegalPointer 4096
#define persistentChunkSize 262144
#define bucketCntBits 3
#define bucketCnt 8
#define loadFactorNum 13
#define loadFactorDen 2
#define maxKeySize 128
#define maxElemSize 128
#define dataOffset 8
#define emptyRest 0
#define emptyOne 1
#define evacuatedX 2
#define evacuatedY 3
#define evacuatedEmpty 4
#define minTopHash 5
#define iterator 1
#define oldIterator 2
#define hashWriting 4
#define sameSizeGrow 8
#define noCheck 18446744073709551615
#define maxZero 1024
#define bitPointer 1
#define bitScan 16
#define heapBitsShift 1
#define wordsPerBitmapByte 4
#define bitScanAll 240
#define bitPointerAll 15
#define clobberdeadPtr 16045725885737590445
#define heapStatsDep 0
#define sysStatsDep 1
#define numStatsDeps 2
#define metricKindBad 0
#define metricKindUint64 1
#define metricKindFloat64 2
#define metricKindFloat64Histogram 3
#define sweepMinHeapDistance 1048576
#define gcMarkWorkerNotWorker 0
#define gcMarkWorkerDedicatedMode 1
#define gcMarkWorkerFractionalMode 2
#define gcMarkWorkerIdleMode 3
#define gcBackgroundMode 0
#define gcForceMode 1
#define gcForceBlockMode 2
#define gcTriggerHeap 0
#define gcTriggerTime 1
#define gcTriggerCycle 2
#define fixedRootFinalizers 0
#define fixedRootFreeGStacks 1
#define fixedRootCount 2
#define rootBlockBytes 262144
#define maxObletBytes 131072
#define drainCheckThreshold 100000
#define pagesPerSpanRoot 512
#define gcDrainUntilPreempt 1
#define gcDrainFlushBgCredit 2
#define gcDrainIdle 4
#define gcDrainFractional 8
#define gcCreditSlack 2000
#define gcAssistTimeSlack 5000
#define gcOverAssistWork 65536
#define defaultHeapMinimum 4194304
#define scannableStackSizeSlack 8192
#define scavengePercent 1
#define retainExtraPercent 10
#define maxPagesPerPhysPage 64
#define scavengeReservationShards 64
#define numSweepClasses 272
#define sweepClassDone 4294967295
#define sweepDrainedMask 2147483648
#define workbufAlloc 32768
#define minPhysPageSize 4096
#define maxPhysPageSize 524288
#define maxPhysHugePageSize 4194304
#define pagesPerReclaimerChunk 512
#define mSpanDead 0
#define mSpanManual 2
#define numSpanClasses 136
#define tinySpanClass 5
#define spanAllocHeap 0
#define spanAllocStack 1
#define spanAllocPtrScalarBits 2
#define spanAllocWorkBuf 3
#define gcBitsChunkBytes 65536
#define gcBitsHeaderBytes 16
#define pallocChunkPages 512
#define pallocChunkBytes 4194304
#define logPallocChunkPages 9
#define logPallocChunkBytes 22
#define summaryLevelBits 3
#define summaryL0Bits 14
#define pallocChunksL2Bits 13
#define pallocChunksL1Shift 13
#define pallocSumBytes 8
#define maxPackedValue 2097152
#define logMaxPackedValue 21
#define freeChunkSum 2251800887427584
#define summaryLevels 5
#define pageAlloc32Bit 0
#define pageAlloc64Bit 1
#define pallocChunksL1Bits 13
#define pageCachePages 64
#define memProfile 1
#define blockProfile 2
#define mutexProfile 3
#define prunedProfile 4
#define buckHashSize 179999
#define maxStack 32
#define mProfCycleWrap 100663296
#define spanSetBlockEntries 512
#define spanSetInitSpineCap 256
#define wbBufEntries 256
#define wbBufEntryPointers 2
#define pollNoError 0
#define pollErrClosing 1
#define pollErrTimeout 2
#define pollErrNotPollable 3
#define pdReady 1
#define pdWait 2
#define pollBlockSize 4096
#define pollClosing 1
#define pollEventErr 2
#define pollExpiredReadDeadline 4
#define pollExpiredWriteDeadline 8
#define freezeStopWait 2147483647
#define forcePreemptNS 10000000
#define profReaderSleeping 4294967296
#define profWriteExtra 8589934592
#define profBufBlocking 0
#define profBufNonBlocking 1
#define osRelaxMinNS 0
#define tracebackCrash 1
#define tracebackAll 2
#define tracebackShift 2
#define gTrackingPeriod 8
#define tlsSlots 6
#define tlsSize 48
#define waitReasonZero 0
#define waitReasonGCAssistMarking 1
#define waitReasonIOWait 2
#define waitReasonChanReceiveNilChan 3
#define waitReasonChanSendNilChan 4
#define waitReasonDumpingHeap 5
#define waitReasonGarbageCollection 6
#define waitReasonGarbageCollectionScan 7
#define waitReasonPanicWait 8
#define waitReasonSelect 9
#define waitReasonSelectNoCases 10
#define waitReasonGCAssistWait 11
#define waitReasonGCSweepWait 12
#define waitReasonGCScavengeWait 13
#define waitReasonChanReceive 14
#define waitReasonChanSend 15
#define waitReasonFinalizerWait 16
#define waitReasonForceGCIdle 17
#define waitReasonSemacquire 18
#define waitReasonSleep 19
#define waitReasonSyncCondWait 20
#define waitReasonTimerGoroutineIdle 21
#define waitReasonTraceReaderBlocked 22
#define waitReasonWaitForGCCycle 23
#define waitReasonGCWorkerIdle 24
#define waitReasonPreempted 25
#define waitReasonDebugCall 26
#define rwmutexMaxReaders 1073741824
#define selectSend 1
#define selectRecv 2
#define selectDefault 3
#define semTabSize 251
#define semaBlockProfile 1
#define semaMutexProfile 2
#define sigPreempt 23
#define sigIdle 0
#define sigReceiving 1
#define sigSending 2
#define smallSizeDiv 8
#define smallSizeMax 1024
#define largeSizeDiv 128
#define tmpStringBufSize 32
#define maxUint 18446744073709551615
#define maxInt 9223372036854775807
#define uintptrMask 18446744073709551615
#define timerNoStatus 0
#define timerWaiting 1
#define timerRunning 2
#define timerDeleted 3
#define timerRemoving 4
#define timerRemoved 5
#define timerModifying 6
#define timerModifiedEarlier 7
#define timerModifiedLater 8
#define timerMoving 9
#define maxWhen 9223372036854775807
#define traceEvNone 0
#define traceEvBatch 1
#define traceEvFrequency 2
#define traceEvStack 3
#define traceEvGomaxprocs 4
#define traceEvProcStart 5
#define traceEvProcStop 6
#define traceEvGCStart 7
#define traceEvGCDone 8
#define traceEvGCSTWStart 9
#define traceEvGCSTWDone 10
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
#define traceEvHeapGoal 34
#define traceEvTimerGoroutine 35
#define traceEvFutileWakeup 36
#define traceEvString 37
#define traceEvGoStartLocal 38
#define traceEvGoUnblockLocal 39
#define traceEvGoSysExitLocal 40
#define traceEvGoStartLabel 41
#define traceEvGoBlockGC 42
#define traceEvGCMarkAssistStart 43
#define traceEvGCMarkAssistDone 44
#define traceEvUserTaskCreate 45
#define traceEvUserTaskEnd 46
#define traceEvUserRegion 47
#define traceEvUserLog 48
#define traceEvCount 49
#define traceTickDiv 64
#define traceStackSize 128
#define traceBytesPerNumber 10
#define traceArgCountShift 6
#define traceFutileWakeup 128
#define tflagRegularMemory 8
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

struct _type;

struct TypeAssertionError {
	struct _type* _interface;
	struct _type* concrete;
	struct _type* asserted;
	String missingMethod;
};

struct errorCString {
	uintptr_t cstr;
};

struct errorAddressString {
	String msg;
	uintptr_t addr;
};








struct typeCacheBucket {
	struct _type* t[4];
};

struct gobitvector {
	uintptr_t n;
	Slice bytedata;
};

struct timeHistogram {
	uint64_t counts[720];
	uint64_t underflow;
};

struct interfacetype;

struct itab {
	struct interfacetype* inter;
	void* methods[2];
};

struct itabTableType {
	uintptr_t size;
	uintptr_t count;
	struct itab* entries[512];
};

struct persistentAlloc {
	struct notInHeap* base;
	uintptr_t off;
};

struct linearAlloc {
	uintptr_t next;
	uintptr_t mapped;
	uintptr_t end;
	_Bool mapMemory;
};

struct mapextra;

struct hmap {
	int64_t count;
	uint8_t flags;
	uint8_t B;
	uint16_t noverflow;
	uint32_t hash0;
	void* buckets;
	void* oldbuckets;
	uintptr_t nevacuate;
	struct mapextra* extra;
};

struct bmap;

struct mapextra {
	Slice* overflow;
	Slice* oldoverflow;
	struct bmap* nextOverflow;
};

struct bmap {
	uint8_t tophash[8];
};

struct maptype;

struct hiter {
	void* key;
	void* elem;
	struct maptype* t;
	struct hmap* h;
	void* buckets;
	struct bmap* bptr;
	Slice* overflow;
	Slice* oldoverflow;
	uintptr_t startBucket;
	uint8_t offset;
	_Bool wrapped;
	uint8_t B;
	uint8_t i;
	uintptr_t bucket;
	uintptr_t checkBucket;
};

struct evacDst {
	struct bmap* b;
	int64_t i;
	void* k;
	void* e;
};

struct heapBits {
	uint8_t* bitp;
	uint32_t shift;
	uint32_t arena;
	uint8_t* last;
};

struct markBits {
	uint8_t* bytep;
	uint8_t mask;
	uintptr_t index;
};

struct mspan;

struct mcache {
	uintptr_t nextSample;
	uintptr_t scanAlloc;
	uintptr_t tiny;
	uintptr_t tinyoffset;
	uintptr_t tinyAllocs;
	struct mspan* alloc[136];
	uint32_t flushGen;
};

struct gclink {
	uint64_t next;
};

struct metricData {
	uint64_t deps[1];
	FuncVal* compute;
};

struct sysStatsAggregate {
	uint64_t stacksSys;
	uint64_t mSpanSys;
	uint64_t mSpanInUse;
	uint64_t mCacheSys;
	uint64_t mCacheInUse;
	uint64_t buckHashSys;
	uint64_t gcMiscSys;
	uint64_t otherSys;
	uint64_t heapGoal;
	uint64_t gcCyclesDone;
	uint64_t gcCyclesForced;
};

struct metricValue {
	int64_t kind;
	uint64_t scalar;
	void* pointer;
};

struct metricFloat64Histogram {
	Slice counts;
	Slice buckets;
};

struct funcval;

struct functype;

struct ptrtype;

struct finalizer {
	struct funcval* fn;
	void* arg;
	struct functype* ft;
	struct ptrtype* ot;
};

struct mlink;

struct fixalloc {
	uintptr_t size;
	FuncVal* first;
	void* arg;
	struct mlink* list;
	uintptr_t chunk;
	uint32_t nchunk;
	uint32_t nalloc;
	uintptr_t inuse;
	uint64_t* stat;
	_Bool zero;
};

struct mlink {
	struct mlink* next;
};

struct gcTrigger {
	int64_t kind;
	int64_t now;
	uint32_t n;
};

struct gcRoot {
	void* decl;
	uintptr_t size;
	uintptr_t ptrdata;
	uint8_t* gcdata;
};

struct gcRootList {
	struct gcRootList* next;
	int64_t count;
	struct gcRoot roots[67108864];
};

struct piController {
	double kp;
	double ti;
	double tt;
	double min;
	double max;
	double errIntegral;
	_Bool errOverflow;
	_Bool inputOverflow;
};

struct sweepLocker {
	uint32_t sweepGen;
	_Bool valid;
};

struct sweepLocked {
	struct mspan* mspan;
};

struct workbuf;

struct gcWork {
	struct workbuf* wbuf1;
	struct workbuf* wbuf2;
	uint64_t bytesMarked;
	int64_t heapScanWork;
	_Bool flushedWork;
};

struct arenaHint {
	uintptr_t addr;
	_Bool down;
	struct arenaHint* next;
};

struct mSpanStateBox {
	uint8_t s;
};

struct mSpanList {
	struct mspan* first;
	struct mspan* last;
};

struct special {
	struct special* next;
	uint16_t offset;
	uint8_t kind;
};

struct specialfinalizer {
	struct special special;
	struct funcval* fn;
	struct functype* ft;
	struct ptrtype* ot;
};

struct bucket;

struct specialprofile {
	struct special special;
	struct bucket* b;
};

struct specialReachable {
	struct special special;
	_Bool done;
	_Bool reachable;
};

struct specialsIter {
	struct special** pprev;
	struct special* s;
};

struct gcBitsHeader {
	uintptr_t free;
	uintptr_t next;
};

struct gcBitsArena {
	uintptr_t free;
	struct gcBitsArena* next;
	uint8_t bits[65520];
};

struct pageCache {
	uintptr_t base;
	uint64_t cache;
	uint64_t scav;
};

struct pallocData {
	uint64_t pallocBits[8];
	uint64_t scavenged[8];
};

struct bucket {
	struct bucket* next;
	struct bucket* allnext;
	int64_t typ;
	uintptr_t hash;
	uintptr_t size;
	uintptr_t nstk;
	int64_t skip;
};

struct memRecordCycle {
	uintptr_t allocs;
	uintptr_t frees;
	uintptr_t alloc_bytes;
	uintptr_t free_bytes;
};

struct blockRecord {
	double count;
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

struct BlockProfileRecord {
	int64_t Count;
	int64_t Cycles;
	struct StackRecord StackRecord;
};

struct offAddr {
	uintptr_t a;
};

struct addrRanges {
	Slice ranges;
	uintptr_t totalBytes;
	uint64_t* sysStat;
};

struct spanSetBlockAlloc {
	uint64_t stack;
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

struct heapStatsDelta {
	int64_t committed;
	int64_t released;
	int64_t inHeap;
	int64_t inStacks;
	int64_t inWorkBufs;
	int64_t inPtrScalarBits;
	uintptr_t tinyAllocCount;
	uintptr_t largeAlloc;
	uintptr_t largeAllocCount;
	uintptr_t smallAllocCount[68];
	uintptr_t largeFree;
	uintptr_t largeFreeCount;
	uintptr_t smallFreeCount[68];
	uint32_t _[0];
};

struct wbBuf {
	uintptr_t next;
	uintptr_t end;
	uintptr_t buf[512];
};

struct mOS {
	int32_t profileTimer;
	uint32_t profileTimerValid;
};

struct g;

struct suspendGState {
	struct g* g;
	_Bool dead;
	_Bool stopped;
};

struct sysmontick {
	uint32_t schedtick;
	int64_t schedwhen;
	uint32_t syscalltick;
	int64_t syscallwhen;
};

struct gQueue {
	uint64_t head;
	uint64_t tail;
};

struct gList {
	uint64_t head;
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

struct tracestat {
	_Bool active;
	int64_t id;
	uint64_t allocs;
	uint64_t bytes;
};

struct dbgVar {
	String name;
	int32_t* value;
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
	struct _type* _type;
	void* data;
};

struct hchan;

struct sudog {
	struct g* g;
	struct sudog* next;
	struct sudog* prev;
	void* elem;
	int64_t acquiretime;
	int64_t releasetime;
	uint32_t ticket;
	_Bool isSelect;
	_Bool success;
	struct sudog* parent;
	struct sudog* waitlink;
	struct sudog* waittail;
	struct hchan* c;
};

struct heldLockInfo {
	uintptr_t lockAddr;
	int64_t rank;
};

struct _panic;

struct _defer;

struct m;

struct timer;

struct g {
	struct _panic* _panic;
	struct _defer* _defer;
	struct m* m;
	uintptr_t syscallsp;
	uintptr_t syscallpc;
	void* param;
	uint32_t atomicstatus;
	int64_t goid;
	uint64_t schedlink;
	int64_t waitsince;
	uint8_t waitreason;
	_Bool preempt;
	_Bool preemptStop;
	_Bool asyncSafePoint;
	_Bool paniconfault;
	_Bool preemptscan;
	_Bool gcscandone;
	_Bool throwsplit;
	_Bool gcScannedSyscallStack;
	_Bool activeStackChans;
	uint8_t parkingOnChan;
	int8_t raceignore;
	_Bool sysblocktraced;
	_Bool tracking;
	uint8_t trackingSeq;
	int64_t runnableStamp;
	int64_t runnableTime;
	int64_t sysexitticks;
	uint64_t traceseq;
	uint64_t tracelastp;
	uint64_t lockedm;
	uint32_t sig;
	Slice writebuf;
	uintptr_t sigcode0;
	uintptr_t sigcode1;
	uintptr_t sigpc;
	uintptr_t gopc;
	Slice* ancestors;
	uintptr_t startpc;
	struct sudog* waiting;
	void* labels;
	struct timer* timer;
	uint32_t selectDone;
	int64_t gcAssistBytes;
	void* exception;
	_Bool isforeign;
	uintptr_t gcstack;
	uintptr_t gcstacksize;
	uintptr_t gcnextsegment;
	uintptr_t gcnextsp;
	void* gcinitialsp;
	uintptr_t gcnextsp2;
	void* gcinitialsp2;
	uintptr_t gcregs[122];
	FuncVal* entry;
	uintptr_t entryfn;
	uintptr_t entrysp;
	_Bool fromgogo;
	_Bool scanningself;
	uintptr_t scang;
	uintptr_t scangcw;
	_Bool isSystemGoroutine;
	_Bool isFinalizerGoroutine;
	_Bool deferring;
	_Bool goexiting;
	_Bool ranCgocallBackDone;
	uintptr_t traceback;
	uintptr_t context[122];
	uintptr_t stackcontext[10];
};

struct p {
	int32_t id;
	uint32_t status;
	uint64_t link;
	uint32_t schedtick;
	uint32_t syscalltick;
	struct sysmontick sysmontick;
	uint64_t m;
	struct mcache* mcache;
	struct pageCache pcache;
	uintptr_t raceprocctx;
	Slice deferpool;
	struct _defer* deferpoolbuf[32];
	uint64_t goidcache;
	uint64_t goidcacheend;
	uint32_t runqhead;
	uint32_t runqtail;
	uint64_t runq[256];
	uint64_t runnext;
	struct {
	struct gList gList;
	int32_t n;
	} gFree;
	Slice sudogcache;
	struct sudog* sudogbuf[128];
	struct {
	int64_t len;
	struct mspan* buf[128];
	} mspancache;
	uint64_t tracebuf;
	_Bool traceSweep;
	uintptr_t traceSwept;
	uintptr_t traceReclaimed;
	struct persistentAlloc palloc;
	uint32_t _;
	uint64_t timer0When;
	uint64_t timerModifiedEarliest;
	int64_t gcAssistTime;
	int64_t gcFractionalMarkTime;
	int64_t gcMarkWorkerMode;
	int64_t gcMarkWorkerStartTime;
	struct gcWork gcw;
	struct wbBuf wbBuf;
	uint32_t runSafePointFn;
	uint32_t statsSeq;
	struct mutex timersLock;
	Slice timers;
	uint32_t numTimers;
	uint32_t deletedTimers;
	int64_t scannableStackSizeDelta;
	_Bool preempt;
};

struct schedt {
	uint64_t goidgen;
	uint64_t lastpoll;
	uint64_t pollUntil;
	struct mutex lock;
	uint64_t midle;
	int32_t nmidle;
	int32_t nmidlelocked;
	int64_t mnext;
	int32_t maxmcount;
	int32_t nmsys;
	int64_t nmfreed;
	uint32_t ngsys;
	uint64_t pidle;
	uint32_t npidle;
	uint32_t nmspinning;
	struct gQueue runq;
	int32_t runqsize;
	struct {
	_Bool user;
	struct gQueue runnable;
	int32_t n;
	} disable;
	struct {
	struct mutex lock;
	struct gList list;
	int32_t n;
	} gFree;
	struct mutex sudoglock;
	struct sudog* sudogcache;
	struct mutex deferlock;
	struct _defer* deferpool;
	struct m* freem;
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
	struct mutex sysmonlock;
	uint32_t _;
	struct timeHistogram timeToRun;
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
	struct _panic* panicStack;
	struct _panic* _panic;
	uintptr_t pfn;
	void* arg;
	uintptr_t retaddr;
	_Bool makefunccanrecover;
	_Bool heap;
};

struct _panic {
	struct _panic* link;
	Eface arg;
	_Bool recovered;
	_Bool isforeign;
	_Bool aborted;
	_Bool goexit;
};

struct ancestorInfo {
	Slice pcs;
	int64_t goid;
	uintptr_t gopc;
};

struct sigset_go {
	uint64_t __val[16];
};

struct rwmutex {
	struct mutex rLock;
	uint64_t readers;
	uint32_t readerPass;
	struct mutex wLock;
	uint64_t writer;
	uint32_t readerCount;
	uint32_t readerWait;
};

struct scase {
	struct hchan* c;
	void* elem;
};

struct runtimeSelect {
	int64_t dir;
	void* typ;
	struct hchan* ch;
	void* val;
};

struct semaRoot {
	struct mutex lock;
	struct sudog* treap;
	uint32_t nwait;
};

struct notifyList {
	uint32_t wait;
	uint32_t notify;
	struct mutex lock;
	struct sudog* head;
	struct sudog* tail;
};

struct _siginfo_t;

struct sigctxt {
	struct _siginfo_t* info;
	void* ctxt;
};

struct sigTabT {
	int32_t flags;
	String name;
};

struct slice {
	void* array;
	int64_t len;
	int64_t cap;
};

struct notInHeapSlice {
	struct notInHeap* array;
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

struct bitvector {
	int32_t n;
	uint8_t* bytedata;
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
	uint64_t pp;
	int64_t when;
	int64_t period;
	FuncVal* f;
	Eface arg;
	uintptr_t seq;
	int64_t nextwhen;
	uint32_t status;
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

struct uncommontype;

struct _type {
	const uintptr_t size;
	const uintptr_t ptrdata;
	const uint32_t hash;
	const uint8_t tflag;
	const uint8_t align;
	const uint8_t fieldAlign;
	const uint8_t kind;
	const FuncVal* equal;
	const uint8_t* gcdata;
	const String* _string;
	const struct uncommontype* uncommontype;
	const struct _type* ptrToThis;
};

struct method {
	String* name;
	String* pkgPath;
	struct _type* mtyp;
	struct _type* typ;
	void* tfn;
};

struct uncommontype {
	const String* name;
	const String* pkgPath;
	const Slice methods;
};

struct imethod {
	String* name;
	String* pkgPath;
	struct _type* typ;
};

struct interfacetype {
	const struct _type typ;
	const Slice methods;
};

struct maptype {
	const struct _type typ;
	const struct _type* key;
	const struct _type* elem;
	const struct _type* bucket;
	const FuncVal* hasher;
	const uint8_t keysize;
	const uint8_t elemsize;
	const uint16_t bucketsize;
	const uint32_t flags;
};

struct arraytype {
	const struct _type typ;
	const struct _type* elem;
	const struct _type* slice;
	const uintptr_t len;
};

struct chantype {
	const struct _type typ;
	const struct _type* elem;
	const uintptr_t dir;
};

struct slicetype {
	const struct _type typ;
	const struct _type* elem;
};

struct functype {
	const struct _type typ;
	const _Bool dotdotdot;
	const Slice in;
	const Slice out;
};

struct ptrtype {
	const struct _type typ;
	const struct _type* elem;
};

struct structfield {
	String* name;
	String* pkgPath;
	struct _type* typ;
	String* tag;
	uintptr_t offsetAnon;
};

struct structtype {
	const struct _type typ;
	const Slice fields;
};

struct typeDescriptorList {
	int64_t count;
	uintptr_t types[1];
};

struct __IO_FILE;

































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






struct hchan {
	uint64_t qcount;
	uint64_t dataqsiz;
	void* buf;
	uint16_t elemsize;
	uint32_t closed;
	struct _type* elemtype;
	uint64_t sendx;
	uint64_t recvx;
	struct waitq recvq;
	struct waitq sendq;
	struct mutex lock;
};

struct profBuf;

struct cpuProfile {
	struct mutex lock;
	_Bool on;
	struct profBuf* log;
	uintptr_t extra[1000];
	int64_t numExtra;
	uint64_t lostExtra;
	uint64_t lostAtomic;
};

struct childInfo {
	uintptr_t argoff;
	uintptr_t arglen;
	struct bitvector args;
	uint8_t* sp;
	uintptr_t depth;
};

struct heapStatsAggregate {
	struct heapStatsDelta heapStatsDelta;
	uint64_t inObjects;
	uint64_t numObjects;
	uint64_t totalAllocated;
	uint64_t totalFreed;
	uint64_t totalAllocs;
	uint64_t totalFrees;
};

struct statAggregate {
	uint64_t ensured[1];
	struct heapStatsAggregate heapStats;
	struct sysStatsAggregate sysStats;
};

struct metricSample {
	String name;
	struct metricValue value;
};

struct finblock {
	struct finblock* alllink;
	struct finblock* next;
	uint32_t cnt;
	int32_t _;
	struct finalizer fin[127];
};

struct gcBgMarkWorkerNode {
	struct lfnode node;
	uint64_t gp;
	uint64_t m;
};

struct workbufhdr {
	struct lfnode node;
	int64_t nobj;
};

struct workbuf {
	struct workbufhdr workbufhdr;
	uintptr_t obj[253];
};

struct mspan {
	struct mspan* next;
	struct mspan* prev;
	struct mSpanList* list;
	uintptr_t startAddr;
	uintptr_t npages;
	uint64_t manualFreeList;
	uintptr_t freeindex;
	uintptr_t nelems;
	uint64_t allocCache;
	uint8_t* allocBits;
	uint8_t* gcmarkBits;
	uint32_t sweepgen;
	uint32_t divMul;
	uint16_t allocCount;
	uint8_t spanclass;
	struct mSpanStateBox state;
	uint8_t needzero;
	uintptr_t elemsize;
	uintptr_t limit;
	struct mutex speciallock;
	struct special* specials;
};

struct memRecord {
	struct memRecordCycle active;
	struct memRecordCycle future[3];
};

struct addrRange {
	struct offAddr base;
	struct offAddr limit;
};

struct spanSet {
	struct mutex spineLock;
	void* spine;
	uintptr_t spineLen;
	uintptr_t spineCap;
	uint64_t index;
};

struct spanSetBlock {
	struct lfnode lfnode;
	uint32_t popped;
	struct mspan* spans[512];
};

struct consistentHeapStats {
	struct heapStatsDelta stats[3];
	uint32_t gen;
	struct mutex noPLock;
};

struct pollCache {
	struct mutex lock;
	void* first;
};

struct profBuf {
	uint64_t r;
	uint64_t w;
	uint64_t overflow;
	uint64_t overflowTime;
	uint32_t eof;
	uintptr_t hdrsize;
	Slice data;
	Slice tags;
	uint64_t rNext;
	Slice overflowBuf;
	struct note wait;
};

struct m {
	struct g* g0;
	uint64_t procid;
	struct g* gsignal;
	struct sigset_go sigmask;
	FuncVal* mstartfn;
	struct g* curg;
	uint64_t caughtsig;
	uint64_t p;
	uint64_t nextp;
	uint64_t oldp;
	int64_t id;
	int32_t mallocing;
	int32_t throwing;
	String preemptoff;
	int32_t locks;
	int32_t dying;
	int32_t profilehz;
	_Bool spinning;
	_Bool blocked;
	_Bool newSigstack;
	int8_t printlock;
	_Bool incgo;
	uint32_t freeWait;
	uint64_t fastrand;
	_Bool needextram;
	uint8_t traceback;
	uint64_t ncgocall;
	int32_t ncgo;
	struct note park;
	struct m* alllink;
	uint64_t schedlink;
	uint64_t lockedg;
	struct location createstack[32];
	uint32_t lockedExt;
	uint32_t lockedInt;
	uint64_t nextwaitm;
	FuncVal* waitunlockf;
	void* waitlock;
	uint8_t waittraceev;
	int64_t waittraceskip;
	_Bool startingtrace;
	uint32_t syscalltick;
	struct m* freelink;
	uint32_t preemptGen;
	uint32_t signalPending;
	struct mOS mOS;
	int64_t locksHeldLen;
	struct heldLockInfo locksHeld[10];
	void* gsignalstack;
	uintptr_t gsignalstacksize;
	_Bool dropextram;
	_Bool exiting;
	struct note scannote;
};

struct traceBufHeader {
	uint64_t link;
	uint64_t lastTicks;
	int64_t pos;
	struct location stk[128];
};

struct traceBuf {
	struct traceBufHeader traceBufHeader;
	uint8_t arr[59368];
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

struct mcentral {
	uint8_t spanclass;
	struct spanSet partial[2];
	struct spanSet full[2];
};

struct mstats {
	uint64_t alloc;
	uint64_t total_alloc;
	uint64_t sys;
	uint64_t nlookup;
	uint64_t nmalloc;
	uint64_t nfree;
	uint64_t heap_sys;
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
	uint64_t gcWorkBufInUse;
	uint64_t gcProgPtrScalarBitsInUse;
	uint64_t gcMiscSys;
	uint64_t other_sys;
	uint64_t last_gc_unix;
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
	} by_size[68];
	uint32_t _[1];
	uint64_t last_gc_nanotime;
	uint64_t last_heap_inuse;
	struct consistentHeapStats heapStats;
	struct timeHistogram gcPauseDist;
};
#define _PageSize 8192
#define _PageMask 8191
#define _GoidCacheBatch 16
#define _Gidle 0
#define _Grunnable 1
#define _Grunning 2
#define _Gsyscall 3
#define _Gwaiting 4
#define _Gmoribund_unused 5
#define _Gdead 6
#define _Genqueue_unused 7
#define _Gcopystack 8
#define _Gpreempted 9
#define _Gexitingsyscall 10
#define _Gscan 4096
#define _Gscanrunnable 4097
#define _Gscanrunning 4098
#define _Gscansyscall 4099
#define _Gscanwaiting 4100
#define _Gscanpreempted 4105
#define _Pidle 0
#define _Prunning 1
#define _Psyscall 2
#define _Pgcstop 3
#define _Pdead 4
#define _PageShift 13
#define _MaxGcproc 32
#define _MaxSmallSize 32768
#define _SigNotify 1
#define _SigKill 2
#define _SigThrow 4
#define _SigPanic 8
#define _SigDefault 16
#define _SigGoExit 32
#define _SigSetStack 64
#define _SigUnblock 128
#define _SigIgn 256
#define _TraceRuntimeFrames 1
#define _TraceTrap 2
#define _TraceJumpStack 4
#define _TracebackMaxFrames 100
#define _NumStackOrders 4
#define _NumSizeClasses 68
