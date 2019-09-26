package sys
const DefaultGoroot = "/usr/local"
const TheVersion = "go1.8.3 gccgo-7 (Debian 7.4.0-6) 7.4.0"
const GOARCH = "amd64"
const GOOS = "linux"
const GccgoToolDir = "/usr/local/libexec/gcc//7"

type ArchFamilyType int

const (
	UNKNOWN ArchFamilyType = iota
	I386
	ALPHA
	AMD64
	ARM
	ARM64
	IA64
	M68K
	MIPS
	MIPS64
	PPC
	PPC64
	S390
	S390X
	SPARC
	SPARC64
)

const Goarch386 = 0
const GoarchAlpha = 0
const GoarchAmd64 = 1
const GoarchAmd64p32 = 0
const GoarchArm = 0
const GoarchArmbe = 0
const GoarchArm64 = 0
const GoarchArm64be = 0
const GoarchIa64 = 0
const GoarchM68k = 0
const GoarchMips = 0
const GoarchMipsle = 0
const GoarchMips64 = 0
const GoarchMips64le = 0
const GoarchMips64p32 = 0
const GoarchMips64p32le = 0
const GoarchPpc = 0
const GoarchPpc64 = 0
const GoarchPpc64le = 0
const GoarchS390 = 0
const GoarchS390x = 0
const GoarchSparc = 0
const GoarchSparc64 = 0

const (
	ArchFamily = AMD64
	BigEndian = 0
	CacheLineSize = 64
	PhysPageSize = 4096
	PCQuantum = 1
	Int64Align = 8
	HugePageSize = 1 << 21
	MinFrameSize = 0
)

const GoosAndroid = 0
const GoosDarwin = 0
const GoosDragonfly = 0
const GoosFreebsd = 0
const GoosIrix = 0
const GoosLinux = 1
const GoosNetbsd = 0
const GoosOpenbsd = 0
const GoosPlan9 = 0
const GoosRtems = 0
const GoosSolaris = 0
const GoosWindows = 0

type Uintreg uintptr
