

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Tue Nov 18 13:53:26 2014
 */
/* Compiler settings for C:\Users\aljim\AppData\Local\Temp\winrtInterface.idl-d7a4ac8f:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __winrtInterface_h_h__
#define __winrtInterface_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(__cplusplus)
#if defined(__MIDL_USE_C_ENUM)
#define MIDL_ENUM enum
#else
#define MIDL_ENUM enum class
#endif
#endif


/* Forward Declarations */ 

#ifndef ____x_ABI_CwinrtInterface_CIProtocol_FWD_DEFINED__
#define ____x_ABI_CwinrtInterface_CIProtocol_FWD_DEFINED__
typedef interface __x_ABI_CwinrtInterface_CIProtocol __x_ABI_CwinrtInterface_CIProtocol;

#ifdef __cplusplus
namespace ABI {
    namespace winrtInterface {
        interface IProtocol;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CwinrtInterface_CIProtocol_FWD_DEFINED__ */


#ifndef ____x_ABI_CwinrtInterface_CIProtocolAnalytics_FWD_DEFINED__
#define ____x_ABI_CwinrtInterface_CIProtocolAnalytics_FWD_DEFINED__
typedef interface __x_ABI_CwinrtInterface_CIProtocolAnalytics __x_ABI_CwinrtInterface_CIProtocolAnalytics;

#ifdef __cplusplus
namespace ABI {
    namespace winrtInterface {
        interface IProtocolAnalytics;
    } /* end namespace */
} /* end namespace */

#endif /* __cplusplus */

#endif 	/* ____x_ABI_CwinrtInterface_CIProtocolAnalytics_FWD_DEFINED__ */


/* header files for imported files */
#include "inspectable.h"
#include "Windows.Foundation.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_winrtInterface_0000_0000 */
/* [local] */ 

#ifdef __cplusplus
} /*extern "C"*/ 
#endif
#include <windows.foundation.collections.h>
#ifdef __cplusplus
extern "C" {
#endif


/* interface __MIDL_itf_winrtInterface_0000_0000 */
/* [local] */ 



extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0000_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0208 */




/* interface __MIDL_itf_winrtInterface_0000_0208 */




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0208_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0208_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0001 */
/* [local] */ 

#ifndef DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if defined(__cplusplus) && !defined(RO_NO_TEMPLATE_NAME)
} /*extern "C"*/ 
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("60310303-49c5-52e6-abc6-a9b36eccc716"))
IKeyValuePair<HSTRING,HSTRING> : IKeyValuePair_impl<HSTRING,HSTRING> {
static const wchar_t* z_get_rc_name_impl() {
return L"Windows.Foundation.Collections.IKeyValuePair`2<String, String>"; }
};
typedef IKeyValuePair<HSTRING,HSTRING> __FIKeyValuePair_2_HSTRING_HSTRING_t;
#define ____FIKeyValuePair_2_HSTRING_HSTRING_FWD_DEFINED__
#define __FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIKeyValuePair_2_HSTRING_HSTRING_t

/* ABI */ } /* Windows */ } /* Foundation */ } /* Collections */ }
extern "C" {
#endif //__cplusplus
#endif /* DEF___FIKeyValuePair_2_HSTRING_HSTRING_USE */


/* interface __MIDL_itf_winrtInterface_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0001_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0209 */




/* interface __MIDL_itf_winrtInterface_0000_0209 */




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0209_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0209_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0002 */
/* [local] */ 

#ifndef DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if defined(__cplusplus) && !defined(RO_NO_TEMPLATE_NAME)
} /*extern "C"*/ 
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("05eb86f1-7140-5517-b88d-cbaebe57e6b1"))
IIterator<__FIKeyValuePair_2_HSTRING_HSTRING*> : IIterator_impl<__FIKeyValuePair_2_HSTRING_HSTRING*> {
static const wchar_t* z_get_rc_name_impl() {
return L"Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IKeyValuePair`2<String, String>>"; }
};
typedef IIterator<__FIKeyValuePair_2_HSTRING_HSTRING*> __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t;
#define ____FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_FWD_DEFINED__
#define __FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_t

/* ABI */ } /* Windows */ } /* Foundation */ } /* Collections */ }
extern "C" {
#endif //__cplusplus
#endif /* DEF___FIIterator_1___FIKeyValuePair_2_HSTRING_HSTRING_USE */


/* interface __MIDL_itf_winrtInterface_0000_0002 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0002_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0210 */




/* interface __MIDL_itf_winrtInterface_0000_0210 */




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0210_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0210_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0003 */
/* [local] */ 

#ifndef DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#define DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE
#if defined(__cplusplus) && !defined(RO_NO_TEMPLATE_NAME)
} /*extern "C"*/ 
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("e9bdaaf0-cbf6-5c72-be90-29cbf3a1319b"))
IIterable<__FIKeyValuePair_2_HSTRING_HSTRING*> : IIterable_impl<__FIKeyValuePair_2_HSTRING_HSTRING*> {
static const wchar_t* z_get_rc_name_impl() {
return L"Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Collections.IKeyValuePair`2<String, String>>"; }
};
typedef IIterable<__FIKeyValuePair_2_HSTRING_HSTRING*> __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t;
#define ____FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_FWD_DEFINED__
#define __FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_t

/* ABI */ } /* Windows */ } /* Foundation */ } /* Collections */ }
extern "C" {
#endif //__cplusplus
#endif /* DEF___FIIterable_1___FIKeyValuePair_2_HSTRING_HSTRING_USE */


/* interface __MIDL_itf_winrtInterface_0000_0003 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0003_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0003_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0211 */




/* interface __MIDL_itf_winrtInterface_0000_0211 */




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0211_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0211_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0004 */
/* [local] */ 

#ifndef DEF___FIMapView_2_HSTRING_HSTRING_USE
#define DEF___FIMapView_2_HSTRING_HSTRING_USE
#if defined(__cplusplus) && !defined(RO_NO_TEMPLATE_NAME)
} /*extern "C"*/ 
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("ac7f26f2-feb7-5b2a-8ac4-345bc62caede"))
IMapView<HSTRING,HSTRING> : IMapView_impl<HSTRING,HSTRING> {
static const wchar_t* z_get_rc_name_impl() {
return L"Windows.Foundation.Collections.IMapView`2<String, String>"; }
};
typedef IMapView<HSTRING,HSTRING> __FIMapView_2_HSTRING_HSTRING_t;
#define ____FIMapView_2_HSTRING_HSTRING_FWD_DEFINED__
#define __FIMapView_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIMapView_2_HSTRING_HSTRING_t

/* ABI */ } /* Windows */ } /* Foundation */ } /* Collections */ }
extern "C" {
#endif //__cplusplus
#endif /* DEF___FIMapView_2_HSTRING_HSTRING_USE */


/* interface __MIDL_itf_winrtInterface_0000_0004 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0004_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0004_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0212 */




/* interface __MIDL_itf_winrtInterface_0000_0212 */




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0212_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0212_v0_0_s_ifspec;

/* interface __MIDL_itf_winrtInterface_0000_0005 */
/* [local] */ 

#ifndef DEF___FIMap_2_HSTRING_HSTRING_USE
#define DEF___FIMap_2_HSTRING_HSTRING_USE
#if defined(__cplusplus) && !defined(RO_NO_TEMPLATE_NAME)
} /*extern "C"*/ 
namespace ABI { namespace Windows { namespace Foundation { namespace Collections {
template <>
struct __declspec(uuid("f6d1f700-49c2-52ae-8154-826f9908773c"))
IMap<HSTRING,HSTRING> : IMap_impl<HSTRING,HSTRING> {
static const wchar_t* z_get_rc_name_impl() {
return L"Windows.Foundation.Collections.IMap`2<String, String>"; }
};
typedef IMap<HSTRING,HSTRING> __FIMap_2_HSTRING_HSTRING_t;
#define ____FIMap_2_HSTRING_HSTRING_FWD_DEFINED__
#define __FIMap_2_HSTRING_HSTRING ABI::Windows::Foundation::Collections::__FIMap_2_HSTRING_HSTRING_t

/* ABI */ } /* Windows */ } /* Foundation */ } /* Collections */ }
extern "C" {
#endif //__cplusplus
#endif /* DEF___FIMap_2_HSTRING_HSTRING_USE */

#if !defined(____x_ABI_CwinrtInterface_CIProtocol_INTERFACE_DEFINED__)
extern const __declspec(selectany) WCHAR InterfaceName_winrtInterface_IProtocol[] = L"winrtInterface.IProtocol";
#endif /* !defined(____x_ABI_CwinrtInterface_CIProtocol_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_winrtInterface_0000_0005 */
/* [local] */ 





extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0005_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0005_v0_0_s_ifspec;

#ifndef ____x_ABI_CwinrtInterface_CIProtocol_INTERFACE_DEFINED__
#define ____x_ABI_CwinrtInterface_CIProtocol_INTERFACE_DEFINED__

/* interface __x_ABI_CwinrtInterface_CIProtocol */
/* [uuid][object] */ 



/* interface ABI::winrtInterface::IProtocol */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CwinrtInterface_CIProtocol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace winrtInterface {
            
            MIDL_INTERFACE("64b0eac7-f5e7-4787-90a2-940f5297570a")
            IProtocol : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE getPluginVersion( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE getSDKVersion( 
                    /* [out][retval] */ HSTRING *value) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE setDebugMode( 
                    /* [in] */ boolean bDebug) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IProtocol = __uuidof(IProtocol);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CwinrtInterface_CIProtocolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CwinrtInterface_CIProtocol * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CwinrtInterface_CIProtocol * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *getPluginVersion )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [out][retval] */ HSTRING *value);
        
        HRESULT ( STDMETHODCALLTYPE *getSDKVersion )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [out][retval] */ HSTRING *value);
        
        HRESULT ( STDMETHODCALLTYPE *setDebugMode )( 
            __x_ABI_CwinrtInterface_CIProtocol * This,
            /* [in] */ boolean bDebug);
        
        END_INTERFACE
    } __x_ABI_CwinrtInterface_CIProtocolVtbl;

    interface __x_ABI_CwinrtInterface_CIProtocol
    {
        CONST_VTBL struct __x_ABI_CwinrtInterface_CIProtocolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CwinrtInterface_CIProtocol_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CwinrtInterface_CIProtocol_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CwinrtInterface_CIProtocol_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CwinrtInterface_CIProtocol_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CwinrtInterface_CIProtocol_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CwinrtInterface_CIProtocol_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CwinrtInterface_CIProtocol_getPluginVersion(This,value)	\
    ( (This)->lpVtbl -> getPluginVersion(This,value) ) 

#define __x_ABI_CwinrtInterface_CIProtocol_getSDKVersion(This,value)	\
    ( (This)->lpVtbl -> getSDKVersion(This,value) ) 

#define __x_ABI_CwinrtInterface_CIProtocol_setDebugMode(This,bDebug)	\
    ( (This)->lpVtbl -> setDebugMode(This,bDebug) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CwinrtInterface_CIProtocol_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_winrtInterface_0000_0006 */
/* [local] */ 


#if !defined(____x_ABI_CwinrtInterface_CIProtocolAnalytics_INTERFACE_DEFINED__)
extern const __declspec(selectany) WCHAR InterfaceName_winrtInterface_IProtocolAnalytics[] = L"winrtInterface.IProtocolAnalytics";
#endif /* !defined(____x_ABI_CwinrtInterface_CIProtocolAnalytics_INTERFACE_DEFINED__) */


/* interface __MIDL_itf_winrtInterface_0000_0006 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0006_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_winrtInterface_0000_0006_v0_0_s_ifspec;

#ifndef ____x_ABI_CwinrtInterface_CIProtocolAnalytics_INTERFACE_DEFINED__
#define ____x_ABI_CwinrtInterface_CIProtocolAnalytics_INTERFACE_DEFINED__

/* interface __x_ABI_CwinrtInterface_CIProtocolAnalytics */
/* [uuid][object] */ 



/* interface ABI::winrtInterface::IProtocolAnalytics */
/* [uuid][object] */ 


EXTERN_C const IID IID___x_ABI_CwinrtInterface_CIProtocolAnalytics;

#if defined(__cplusplus) && !defined(CINTERFACE)
    } /* end extern "C" */
    namespace ABI {
        namespace winrtInterface {
            
            MIDL_INTERFACE("666997f8-53a1-4c9c-b7c7-e7b3f248e9f5")
            IProtocolAnalytics : public IInspectable
            {
            public:
                virtual HRESULT STDMETHODCALLTYPE startSession( 
                    /* [in] */ HSTRING appKey) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE stopSession( void) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE setSessionContinueMillis( 
                    /* [in] */ int millis) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE logError( 
                    /* [in] */ HSTRING errorId,
                    /* [in] */ HSTRING message) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE logEvent( 
                    /* [in] */ HSTRING eventId,
                    /* [in] */ __FIMap_2_HSTRING_HSTRING *paramMap) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE logTimedEventBegin( 
                    /* [in] */ HSTRING eventId) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE logTimedEventEnd( 
                    /* [in] */ HSTRING eventId) = 0;
                
                virtual HRESULT STDMETHODCALLTYPE setCaptureUncaughtException( 
                    /* [in] */ boolean enabled) = 0;
                
            };

            extern const __declspec(selectany) IID & IID_IProtocolAnalytics = __uuidof(IProtocolAnalytics);

            
        }  /* end namespace */
    }  /* end namespace */
    extern "C" { 
    
#else 	/* C style interface */

    typedef struct __x_ABI_CwinrtInterface_CIProtocolAnalyticsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIids )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [out] */ ULONG *iidCount,
            /* [size_is][size_is][out] */ IID **iids);
        
        HRESULT ( STDMETHODCALLTYPE *GetRuntimeClassName )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [out] */ HSTRING *className);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrustLevel )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [out] */ TrustLevel *trustLevel);
        
        HRESULT ( STDMETHODCALLTYPE *startSession )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ HSTRING appKey);
        
        HRESULT ( STDMETHODCALLTYPE *stopSession )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This);
        
        HRESULT ( STDMETHODCALLTYPE *setSessionContinueMillis )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ int millis);
        
        HRESULT ( STDMETHODCALLTYPE *logError )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ HSTRING errorId,
            /* [in] */ HSTRING message);
        
        HRESULT ( STDMETHODCALLTYPE *logEvent )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ HSTRING eventId,
            /* [in] */ __FIMap_2_HSTRING_HSTRING *paramMap);
        
        HRESULT ( STDMETHODCALLTYPE *logTimedEventBegin )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ HSTRING eventId);
        
        HRESULT ( STDMETHODCALLTYPE *logTimedEventEnd )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ HSTRING eventId);
        
        HRESULT ( STDMETHODCALLTYPE *setCaptureUncaughtException )( 
            __x_ABI_CwinrtInterface_CIProtocolAnalytics * This,
            /* [in] */ boolean enabled);
        
        END_INTERFACE
    } __x_ABI_CwinrtInterface_CIProtocolAnalyticsVtbl;

    interface __x_ABI_CwinrtInterface_CIProtocolAnalytics
    {
        CONST_VTBL struct __x_ABI_CwinrtInterface_CIProtocolAnalyticsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_GetIids(This,iidCount,iids)	\
    ( (This)->lpVtbl -> GetIids(This,iidCount,iids) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_GetRuntimeClassName(This,className)	\
    ( (This)->lpVtbl -> GetRuntimeClassName(This,className) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_GetTrustLevel(This,trustLevel)	\
    ( (This)->lpVtbl -> GetTrustLevel(This,trustLevel) ) 


#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_startSession(This,appKey)	\
    ( (This)->lpVtbl -> startSession(This,appKey) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_stopSession(This)	\
    ( (This)->lpVtbl -> stopSession(This) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_setSessionContinueMillis(This,millis)	\
    ( (This)->lpVtbl -> setSessionContinueMillis(This,millis) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_logError(This,errorId,message)	\
    ( (This)->lpVtbl -> logError(This,errorId,message) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_logEvent(This,eventId,paramMap)	\
    ( (This)->lpVtbl -> logEvent(This,eventId,paramMap) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_logTimedEventBegin(This,eventId)	\
    ( (This)->lpVtbl -> logTimedEventBegin(This,eventId) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_logTimedEventEnd(This,eventId)	\
    ( (This)->lpVtbl -> logTimedEventEnd(This,eventId) ) 

#define __x_ABI_CwinrtInterface_CIProtocolAnalytics_setCaptureUncaughtException(This,enabled)	\
    ( (This)->lpVtbl -> setCaptureUncaughtException(This,enabled) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ____x_ABI_CwinrtInterface_CIProtocolAnalytics_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  HSTRING_UserSize(     unsigned long *, unsigned long            , HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserMarshal(  unsigned long *, unsigned char *, HSTRING * ); 
unsigned char * __RPC_USER  HSTRING_UserUnmarshal(unsigned long *, unsigned char *, HSTRING * ); 
void                      __RPC_USER  HSTRING_UserFree(     unsigned long *, HSTRING * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


