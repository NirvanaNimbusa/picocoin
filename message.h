#ifndef __PICOCOIN_MESSAGE_H__
#define __PICOCOIN_MESSAGE_H__

#include <stdint.h>
#include <stdbool.h>
#include "core.h"

#define P2P_HDR_SZ	(4 + 12 + 4 + 4)

struct p2p_message_hdr {
	unsigned char	netmagic[4];
	char		command[12];
	uint32_t	data_len;
	unsigned char	hash[4];
};

struct p2p_message {
	struct p2p_message_hdr	hdr;
	void			*data;
};

struct msg_version {
	uint32_t	nVersion;
	uint64_t	nServices;
	int64_t		nTime;
	struct bp_address addrTo;
	struct bp_address addrFrom;
	uint64_t	nonce;
	char		strSubVer[80];
	uint32_t	nStartingHeight;
};

extern bool deser_msg_version(struct msg_version *mv, struct buffer *buf);
extern GString *ser_msg_version(const struct msg_version *mv);
static inline void msg_version_free(struct msg_version *mv) {}

struct msg_addr {
	GPtrArray	*addrs;
};

extern bool deser_msg_addr(unsigned int protover, struct msg_addr *ma, struct buffer *buf);
extern GString *ser_msg_addr(unsigned int protover, const struct msg_addr *ma);
extern void msg_addr_free(struct msg_addr *ma);

#endif /* __PICOCOIN_MESSAGE_H__ */
