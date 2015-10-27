/*
 * =====================================================================================
 *
 *    Filename   :  hls_priv.h
 *    Description:
 *    Version    :  1.0
 *    Created    :  2015年10月27日 11时17分38秒
 *    Revision   :  none
 *    Compiler   :  gcc
 *    Author     :  peter-s (), peter_future@outlook.com
 *    Company    :  dt
 *
 * =====================================================================================
 */

#include "hls_macro.h"
#include "hls_buffer.h"
#include "hls_lock.h"
#include "hls_log.h"

typedef enum hls_state {
    HLS_MOD_UNINITED,
    HLS_MOD_INITED,
    HLS_MOD_RUNNING,
    HLS_MOD_STOPED
} hls_status_t;

typedef struct segment_item {
    char *uri;
} segment_item_t;

typedef struct segment_list {
    segment_item_t *item;
} segment_list_t;

typedef struct bandwidth_list {
    int cur_index;
    segment_list_t seg_list;
} bandwidth_list_t;

typedef struct hls_playlist {
    int is_variant;
    int cur_index;
    bandwidth_list_t bw_list;
} hls_playlist_t;

typedef struct hls_ctrl {
    hls_status_t state;
} hls_ctrl_t;

typedef struct hls_session {
    char *uri;
    int is_variant;
    int is_live;

    hls_buffer_t cache;

    hls_playlist_t play_list;
    hls_ctrl_t ctl;
} hls_session_t;
