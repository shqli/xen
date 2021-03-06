#ifndef _XEN_P2M_COMMON_H
#define _XEN_P2M_COMMON_H

#include <xen/mm.h>

/* Remove a page from a domain's p2m table */
int __must_check
guest_physmap_remove_page(struct domain *d, gfn_t gfn, mfn_t mfn,
                          unsigned int page_order);

/* Map MMIO regions in the p2m: start_gfn and nr describe the range in
 *  * the guest physical address space to map, starting from the machine
 *   * frame number mfn. */
int map_mmio_regions(struct domain *d,
                     gfn_t start_gfn,
                     unsigned long nr,
                     mfn_t mfn);
int unmap_mmio_regions(struct domain *d,
                       gfn_t start_gfn,
                       unsigned long nr,
                       mfn_t mfn);

/*
 * Populate-on-Demand
 */

/*
 * Call when decreasing memory reservation to handle PoD entries properly.
 * Returns the number of pages that were successfully processed.
 */
unsigned long
p2m_pod_decrease_reservation(struct domain *d, gfn_t gfn,
                             unsigned int order);

typedef enum p2m_type p2m_type_t;

int __must_check check_get_page_from_gfn(struct domain *d, gfn_t gfn,
                                         bool readonly, p2m_type_t *p2mt_p,
                                         struct page_info **page_p);


#endif /* _XEN_P2M_COMMON_H */
