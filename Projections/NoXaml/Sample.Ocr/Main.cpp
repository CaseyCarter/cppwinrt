#include "pch.h"

using namespace winrt;

static hstring MessagePath()
{
    // StorageFile.GetFileFromPathAsync doesn't appear to honor the "current directory"
    // so we have to get that ourselves...

    wchar_t buffer[1024] {};
    GetCurrentDirectory(_countof(buffer), buffer);

    check_hresult(PathCchAppendEx(buffer, _countof(buffer), L"message.png", PATHCCH_ALLOW_LONG_PATHS));

    return buffer;
}

static std::future<hstring> Sample()
{
    using namespace Windows::Storage;
    using namespace Windows::Storage::Streams;
    using namespace Windows::Graphics::Imaging;
    using namespace Windows::Media::Ocr;

    StorageFile file = await StorageFile::GetFileFromPathAsync(MessagePath());
    IRandomAccessStream stream = await file.OpenAsync(FileAccessMode::Read);

    BitmapDecoder decoder = await BitmapDecoder::CreateAsync(stream);
    SoftwareBitmap bitmap = await decoder.GetSoftwareBitmapAsync();

    OcrEngine engine = OcrEngine::TryCreateFromUserProfileLanguages();
    OcrResult result = await engine.RecognizeAsync(bitmap);

    return result.Text();
}

int main()
{
    Initialize();

    printf("%ls\n", Sample().get().c_str());
}
