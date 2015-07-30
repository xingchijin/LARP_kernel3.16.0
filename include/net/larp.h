
#include <net/arp.h>


struct larp_hw_hdr
{
  __be16          ar_hrd;         /* format of hardware address   */
  unsigned char   ar_hln;         /* length of hardware address   */
  unsigned char   mbz;           /* dummy   */

#if 0
  unsigned char           ar_sha[ETH_ALEN];
#endif

}__packed;

struct larp_label_hdr
{
#if defined(__BIG_ENDIAN_BITFIELD)
  unsigned char     ar_lvalid:1,
    ar_label_h7:7;

  unsigned char     ar_label_mid;

  unsigned char     ar_label_5:5,
    ar_entropy:1,
    mbz:2;

#elif defined(__LITTLE_ENDIAN_BITFIELD)
  unsigned char     ar_label_h7:7,
    ar_lvalid:1;

  unsigned char      ar_label_mid;
  unsigned char      mbz:2,
    ar_entropy:1,
    ar_label_5:5;
#endif
#if 0
  __be32 ar_metric;
  __be32 ar_ident;
#endif

}__packed;


#define MPLS_LABEL_HDR_SIZE (sizeof(struct larp_hw_hdr) + sizeof(struct larp_label_hdr) + ETH_ALEN)

/* Utility functions */

static inline int larp_hdr_len(struct net_device *dev)
{
  /* ARP header, plus 2 device addresses, plus 2 IP addresses. */
  //return sizeof(struct arphdr) + (sizeof(u32) + MPLS_LABEL_HDR_SIZE)* 2 ;
  return sizeof(struct arphdr) + (sizeof(u32) + dev->addr_len)* 2 ;
}


