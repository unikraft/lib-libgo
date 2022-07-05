package syscall
type EpollEvent struct {
	Events uint32
	Fd int32
	Pad [4]byte
}
