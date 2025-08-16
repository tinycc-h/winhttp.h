#ifndef WINHTTP_STUB_H
#define WINHTTP_STUB_H

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

// Minimal WinHTTP types
typedef void* HINTERNET;
typedef unsigned short INTERNET_PORT;

// Minimal WinHTTP constants
#define WINHTTP_ACCESS_TYPE_DEFAULT_PROXY 0
#define WINHTTP_NO_PROXY_NAME NULL
#define WINHTTP_NO_PROXY_BYPASS NULL
#define WINHTTP_NO_ADDITIONAL_HEADERS NULL
#define WINHTTP_NO_REFERER NULL
#define WINHTTP_DEFAULT_ACCEPT_TYPES NULL

// Minimal WinHTTP function declarations
HINTERNET __stdcall WinHttpOpen(
    LPCWSTR pszUserAgent,
    DWORD dwAccessType,
    LPCWSTR pszProxyName,
    LPCWSTR pszProxyBypass,
    DWORD dwFlags
);

HINTERNET __stdcall WinHttpConnect(
    HINTERNET hSession,
    LPCWSTR pswzServerName,
    INTERNET_PORT nServerPort,
    DWORD dwReserved
);

HINTERNET __stdcall WinHttpOpenRequest(
    HINTERNET hConnect,
    LPCWSTR pwszVerb,
    LPCWSTR pwszObjectName,
    LPCWSTR pwszVersion,
    LPCWSTR pwszReferrer,
    LPCWSTR *ppwszAcceptTypes,
    DWORD dwFlags
);

BOOL __stdcall WinHttpSendRequest(
    HINTERNET hRequest,
    LPCWSTR lpszHeaders,
    DWORD dwHeadersLength,
    LPVOID lpOptional,
    DWORD dwOptionalLength,
    DWORD dwTotalLength,
    DWORD_PTR dwContext
);

BOOL __stdcall WinHttpReceiveResponse(
    HINTERNET hRequest,
    LPVOID lpReserved
);

BOOL __stdcall WinHttpCloseHandle(
    HINTERNET hInternet
);

#ifdef __cplusplus
}
#endif

#endif // WINHTTP_STUB_H
