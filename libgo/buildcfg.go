package buildcfg
import "runtime"
func defaultGOROOTValue() string { return `/usr` }
const defaultGO386 = `sse2`
const defaultGOAMD64 = `v1`
const defaultGOARM = `5`
const defaultGOMIPS = `hardfloat`
const defaultGOMIPS64 = `hardfloat`
const defaultGOPPC64 = `power8`
const defaultGOEXPERIMENT = `fieldtrack`
const defaultGO_EXTLINK_ENABLED = ``
const defaultGO_LDSO = ``
const version = `go1.18 gccgo (GCC) 12.1.0`
const defaultGOOS = runtime.GOOS
const defaultGOARCH = runtime.GOARCH
