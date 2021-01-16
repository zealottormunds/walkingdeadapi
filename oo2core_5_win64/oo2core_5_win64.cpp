#include <windows.h>
#include <stdio.h>

#include "oo2core_5_win64.h"
#include "WD_Main.h"

using namespace moddingApi;

HINSTANCE mHinst = 0, mHinstDLL = 0;
extern "C" UINT_PTR mProcs[64] = {0};
LPCSTR mImportNames[] = {"OodleHuffman_CountHistoArrayU8", "OodleHuffman_DecodeArrayU8", "OodleHuffman_EncodeArrayU8", "OodleLZDecoder_Create", "OodleLZDecoder_DecodeSome", "OodleLZDecoder_Destroy", "OodleLZDecoder_MakeValidCircularWindowSize", "OodleLZDecoder_MemorySizeNeeded", "OodleLZDecoder_Reset", "OodleLZ_CheckSeekTableCRCs", "OodleLZ_Compress", "OodleLZ_CompressContext_Alloc", "OodleLZ_CompressContext_Free", "OodleLZ_CompressContext_Reset", "OodleLZ_CompressOptions_GetDefault", "OodleLZ_CompressOptions_Validate", "OodleLZ_CompressWithContext", "OodleLZ_CompressionLevel_GetName", "OodleLZ_Compressor_GetName", "OodleLZ_CreateSeekTable", "OodleLZ_Decompress", "OodleLZ_FillSeekTable", "OodleLZ_FindSeekEntry", "OodleLZ_FreeSeekTable", "OodleLZ_GetChunkCompressor", "OodleLZ_GetCompressedBufferSizeNeeded", "OodleLZ_GetCompressedStepForRawStep", "OodleLZ_GetDecodeBufferSize", "OodleLZ_GetInPlaceDecodeBufferSize", "OodleLZ_GetNumSeekChunks", "OodleLZ_GetSeekEntryPackedPos", "OodleLZ_GetSeekTableMemorySizeNeeded", "OodleLZ_GetZipLikeCompressionSettings", "OodleLZ_MakeSeekChunkLen", "OodleLZ_ThreadPhased_BlockDecoderMemorySizeNeeded", "OodleNetwork1TCP_Decode", "OodleNetwork1TCP_Encode", "OodleNetwork1TCP_State_InitAsCopy", "OodleNetwork1TCP_State_Reset", "OodleNetwork1TCP_State_Size", "OodleNetwork1TCP_Train", "OodleNetwork1UDP_Decode", "OodleNetwork1UDP_Encode", "OodleNetwork1UDP_StateCompacted_MaxSize", "OodleNetwork1UDP_State_Compact", "OodleNetwork1UDP_State_Size", "OodleNetwork1UDP_State_Uncompact", "OodleNetwork1UDP_Train", "OodleNetwork1_CompressedBufferSizeNeeded", "OodleNetwork1_SelectDictionaryFromPackets", "OodleNetwork1_SelectDictionaryFromPackets_Trials", "OodleNetwork1_Shared_SetWindow", "OodleNetwork1_Shared_Size", "OodlePlugin_DisplayAssertion_Default", "OodlePlugin_Free_Default", "OodlePlugin_MallocAligned_Default", "OodlePlugin_Printf_Default", "OodlePlugins_SetAllocators", "OodlePlugins_SetAssertion", "OodlePlugins_SetPrintf", "Oodle_CheckVersion", "Oodle_GetConfigValues", "Oodle_LogHeader", "Oodle_SetConfigValues"};

uintptr_t oo2core_5_win64::moduleBase;
uintptr_t oo2core_5_win64::handleBase;

BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved, HMODULE hModule )
{
	mHinst = hinstDLL;
	if ( fdwReason == DLL_PROCESS_ATTACH )
	{
		mHinstDLL = LoadLibrary( "ori_oo2core_5_win64.dll" );
		if (!mHinstDLL)
		{
			return (FALSE);
		}
		for (int i = 0; i < 64; i++)
		{
			mProcs[i] = (UINT_PTR)GetProcAddress(mHinstDLL, mImportNames[i]);
		}

		oo2core_5_win64::handleBase = (uintptr_t)hModule;
		oo2core_5_win64::moduleBase = (uintptr_t)GetModuleHandle(NULL) + 0xC00;

		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)WD_Main::Start, hModule, 0, nullptr));
	}
	else if ( fdwReason == DLL_PROCESS_DETACH )
	{
		FreeLibrary( mHinstDLL );
	}
	return ( TRUE );
}

extern "C" void OodleHuffman_CountHistoArrayU8_wrapper();
extern "C" void OodleHuffman_DecodeArrayU8_wrapper();
extern "C" void OodleHuffman_EncodeArrayU8_wrapper();
extern "C" void OodleLZDecoder_Create_wrapper();
extern "C" void OodleLZDecoder_DecodeSome_wrapper();
extern "C" void OodleLZDecoder_Destroy_wrapper();
extern "C" void OodleLZDecoder_MakeValidCircularWindowSize_wrapper();
extern "C" void OodleLZDecoder_MemorySizeNeeded_wrapper();
extern "C" void OodleLZDecoder_Reset_wrapper();
extern "C" void OodleLZ_CheckSeekTableCRCs_wrapper();
extern "C" void OodleLZ_Compress_wrapper();
extern "C" void OodleLZ_CompressContext_Alloc_wrapper();
extern "C" void OodleLZ_CompressContext_Free_wrapper();
extern "C" void OodleLZ_CompressContext_Reset_wrapper();
extern "C" void OodleLZ_CompressOptions_GetDefault_wrapper();
extern "C" void OodleLZ_CompressOptions_Validate_wrapper();
extern "C" void OodleLZ_CompressWithContext_wrapper();
extern "C" void OodleLZ_CompressionLevel_GetName_wrapper();
extern "C" void OodleLZ_Compressor_GetName_wrapper();
extern "C" void OodleLZ_CreateSeekTable_wrapper();
extern "C" void OodleLZ_Decompress_wrapper();
extern "C" void OodleLZ_FillSeekTable_wrapper();
extern "C" void OodleLZ_FindSeekEntry_wrapper();
extern "C" void OodleLZ_FreeSeekTable_wrapper();
extern "C" void OodleLZ_GetChunkCompressor_wrapper();
extern "C" void OodleLZ_GetCompressedBufferSizeNeeded_wrapper();
extern "C" void OodleLZ_GetCompressedStepForRawStep_wrapper();
extern "C" void OodleLZ_GetDecodeBufferSize_wrapper();
extern "C" void OodleLZ_GetInPlaceDecodeBufferSize_wrapper();
extern "C" void OodleLZ_GetNumSeekChunks_wrapper();
extern "C" void OodleLZ_GetSeekEntryPackedPos_wrapper();
extern "C" void OodleLZ_GetSeekTableMemorySizeNeeded_wrapper();
extern "C" void OodleLZ_GetZipLikeCompressionSettings_wrapper();
extern "C" void OodleLZ_MakeSeekChunkLen_wrapper();
extern "C" void OodleLZ_ThreadPhased_BlockDecoderMemorySizeNeeded_wrapper();
extern "C" void OodleNetwork1TCP_Decode_wrapper();
extern "C" void OodleNetwork1TCP_Encode_wrapper();
extern "C" void OodleNetwork1TCP_State_InitAsCopy_wrapper();
extern "C" void OodleNetwork1TCP_State_Reset_wrapper();
extern "C" void OodleNetwork1TCP_State_Size_wrapper();
extern "C" void OodleNetwork1TCP_Train_wrapper();
extern "C" void OodleNetwork1UDP_Decode_wrapper();
extern "C" void OodleNetwork1UDP_Encode_wrapper();
extern "C" void OodleNetwork1UDP_StateCompacted_MaxSize_wrapper();
extern "C" void OodleNetwork1UDP_State_Compact_wrapper();
extern "C" void OodleNetwork1UDP_State_Size_wrapper();
extern "C" void OodleNetwork1UDP_State_Uncompact_wrapper();
extern "C" void OodleNetwork1UDP_Train_wrapper();
extern "C" void OodleNetwork1_CompressedBufferSizeNeeded_wrapper();
extern "C" void OodleNetwork1_SelectDictionaryFromPackets_wrapper();
extern "C" void OodleNetwork1_SelectDictionaryFromPackets_Trials_wrapper();
extern "C" void OodleNetwork1_Shared_SetWindow_wrapper();
extern "C" void OodleNetwork1_Shared_Size_wrapper();
extern "C" void OodlePlugin_DisplayAssertion_Default_wrapper();
extern "C" void OodlePlugin_Free_Default_wrapper();
extern "C" void OodlePlugin_MallocAligned_Default_wrapper();
extern "C" void OodlePlugin_Printf_Default_wrapper();
extern "C" void OodlePlugins_SetAllocators_wrapper();
extern "C" void OodlePlugins_SetAssertion_wrapper();
extern "C" void OodlePlugins_SetPrintf_wrapper();
extern "C" void Oodle_CheckVersion_wrapper();
extern "C" void Oodle_GetConfigValues_wrapper();
extern "C" void Oodle_LogHeader_wrapper();
extern "C" void Oodle_SetConfigValues_wrapper();
