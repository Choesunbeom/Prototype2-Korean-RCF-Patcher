#ifndef P2_RCF_PATCHER_H
#define P2_RCF_PATCHER_H
#include <stdint.h>
typedef void (*p2_progress_cb)(void *context, double progress, const char *message);
typedef struct {
    uint32_t original_entries;
    uint32_t zip_candidates;
    uint32_t matched_entries;
    uint32_t replaced_entries;
    uint32_t unsupported_entries;
    uint64_t output_size;
    char message[512];
} P2PatchResult;
int p2_patch_rcf(const char *rcf_file, const char *zip_file,
                 const char *output_file, p2_progress_cb callback,
                 void *context, P2PatchResult *result);
#endif
