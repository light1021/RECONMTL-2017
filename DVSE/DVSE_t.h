#ifndef DVSE_T_H__
#define DVSE_T_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include "sgx_edger8r.h" /* for sgx_ocall etc. */


#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif


int ecall_init_enclave(char* storage_folder, char* address, int port);
int ecall_update_epg();
int ecall_get_epg_page(int number, size_t strsize, void* page);
int ecall_prepare_movie(size_t movie_id);
int ecall_get_movie_chunk(size_t chunk_offset, size_t chunk_size, void* chunk);
int ecall_get_movie_file_size(size_t movie_id, size_t* size);
int ecall_try_coupon(char* coupon);
int ecall_get_balance(int* balance);
int ecall_write_log(size_t logsize, char* logstr);

sgx_status_t SGX_CDECL ocall_file_open(void** retval, char* file_name, char* format);
sgx_status_t SGX_CDECL ocall_file_close(int* retval, void* handle);
sgx_status_t SGX_CDECL ocall_file_read(int* retval, void* handle, size_t offset, size_t datasize, unsigned char* data);
sgx_status_t SGX_CDECL ocall_file_write(int* retval, void* handle, size_t datasize, unsigned char* data);
sgx_status_t SGX_CDECL ocall_file_size(size_t* retval, void* file_handle);
sgx_status_t SGX_CDECL ocall_socket_connect(void** retval, char* url, unsigned int port);
sgx_status_t SGX_CDECL ocall_socket_shutdown(void* socket);
sgx_status_t SGX_CDECL ocall_get_the_current_time(int* retval, unsigned char thetime[16]);
sgx_status_t SGX_CDECL u_sgxssl_ftime(void* timeptr, uint32_t timeb_len);
sgx_status_t SGX_CDECL sgx_oc_cpuidex(int cpuinfo[4], int leaf, int subleaf);
sgx_status_t SGX_CDECL sgx_thread_wait_untrusted_event_ocall(int* retval, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_untrusted_event_ocall(int* retval, const void* waiter);
sgx_status_t SGX_CDECL sgx_thread_setwait_untrusted_events_ocall(int* retval, const void* waiter, const void* self);
sgx_status_t SGX_CDECL sgx_thread_set_multiple_untrusted_events_ocall(int* retval, const void** waiters, size_t total);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
