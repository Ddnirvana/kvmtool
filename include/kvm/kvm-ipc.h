#ifndef KVM__IPC_H_
#define KVM__IPC_H_

#include <linux/types.h>

enum {
	KVM_IPC_BALLOON	= 1,
	KVM_IPC_DEBUG	= 2,
	KVM_IPC_STAT	= 3,
	KVM_IPC_PAUSE	= 4,
	KVM_IPC_RESUME	= 5,
	KVM_IPC_STOP	= 6,
	KVM_IPC_PID	= 7,
};

int kvm_ipc__register_handler(u32 type, void (*cb)(int fd, u32 type, u32 len, u8 *msg));
int kvm_ipc__start(int sock);
int kvm_ipc__stop(void);

int kvm_ipc__send(int fd, u32 type);
int kvm_ipc__send_msg(int fd, u32 type, u32 len, u8 *msg);

#endif
