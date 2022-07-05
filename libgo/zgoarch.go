package goarch

const GOARCH = "amd64"

const (
  _ArchFamily = AMD64
  _BigEndian = false
  _DefaultPhysPageSize = 4096
  _Int64Align = 8
  _MinFrameSize = 0
  _PCQuantum = 1
  _StackAlign = 8
)

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
	NIOS2
	PPC
	PPC64
	RISCV
	RISCV64
	S390
	S390X
	SH
	SPARC
	SPARC64
	WASM
)

const Is386 = 0
const IsAlpha = 0
const IsAmd64 = 1
const IsAmd64p32 = 0
const IsArm = 0
const IsArmbe = 0
const IsArm64 = 0
const IsArm64be = 0
const IsIa64 = 0
const IsM68k = 0
const IsMips = 0
const IsMipsle = 0
const IsMips64 = 0
const IsMips64le = 0
const IsMips64p32 = 0
const IsMips64p32le = 0
const IsNios2 = 0
const IsPpc = 0
const IsPpc64 = 0
const IsPpc64le = 0
const IsRiscv = 0
const IsRiscv64 = 0
const IsS390 = 0
const IsS390x = 0
const IsSh = 0
const IsShbe = 0
const IsSparc = 0
const IsSparc64 = 0
const IsWasm = 0
