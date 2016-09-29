// C++ for the Windows Runtime v1.0.private
// Copyright (c) 2016 Microsoft Corporation

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Transcoding {

struct IMediaTranscoder;
struct IMediaTranscoder2;
struct IPrepareTranscodeResult;
struct MediaTranscoder;
struct PrepareTranscodeResult;

}

namespace Windows::Media::Transcoding {

struct IMediaTranscoder;
struct IMediaTranscoder2;
struct IPrepareTranscodeResult;
struct MediaTranscoder;
struct PrepareTranscodeResult;

}

namespace Windows::Media::Transcoding {

enum class MediaVideoProcessingAlgorithm
{
    Default = 0,
    MrfCrf444 = 1,
};

enum class TranscodeFailureReason
{
    None = 0,
    Unknown = 1,
    InvalidProfile = 2,
    CodecNotFound = 3,
};

}

}
