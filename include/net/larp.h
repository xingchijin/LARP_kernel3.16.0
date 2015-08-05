
#include <net/arp.h>
#define TLV_LST 1
#define TLV_ATT 2

/* LARP functions & data structures*/
struct larp_label{
  char valid;
  char entropy;
  int label;
}
struct larp_data{
  u32  metric;
  int lst_len;
  struct larp_label *l_stack;
  //int ident;
};

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
  unsigned char     ar_label_h7;

  unsigned char     ar_label_mid;

  unsigned char     ar_label_5:4,
    ar_entropy:1,
    mbz:3;

#elif defined(__LITTLE_ENDIAN_BITFIELD)
  unsigned char     ar_label_h7;

  unsigned char      ar_label_mid;
  unsigned char      mbz:3,
    ar_entropy:1,
    ar_label_5:4;
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


