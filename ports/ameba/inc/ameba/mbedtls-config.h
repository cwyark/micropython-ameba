#define CONFIG_PROJECT_CUSTOM   0
#define CONFIG_SSL_RSA          1
#define MBEDTLS_ENTROPY_C  
#define MBEDTLS_NO_PLATFORM_ENTROPY
#define MBEDTLS_CTR_DRBG_C
#define MBEDTLS_PLATFORM_MEMORY

#include "mbedtls/config.h"

#if (defined CONFIG_PLATFORM_8195A) || (defined CONFIG_PLATFORM_8711B)
#include "section_config.h"
#include "rom_ssl_ram_map.h"
#define RTL_HW_CRYPTO
#elif defined(CONFIG_HARDWARE_8188F)
#define SUPPORT_HW_SW_CRYPTO
#endif

#if defined (CONFIG_SSL_ROM) //define in ROM makefile
#define SUPPORT_HW_SW_CRYPTO
#include "mbedtls/ssl_rom_lib.h"
#include "mbedtls/config_rom.h"
#elif CONFIG_PROJECT_CUSTOM
#include "platform_stdlib.h"
#include "ssl_config.h"
#elif CONFIG_SSL_RSA
#include "platform_stdlib.h"
#include "mbedtls/config_rsa.h"
#else
#include "platform_stdlib.h"
#include "mbedtls/config_all.h"
#endif /* CONFIG_SSL_ROM */