How to generate a prerelease projection:

1) Run GenerateResponseFiles.cmd <sdk_ver>
2) Run PrereleaseProjection.cmd <response_file> <output_folder> to create the projection

To publish:
1) Run GenerateResponseFiles.cmd <sdk_ver>
2) Run IntegrateReferencesIntoOfficial <sdkver>
3) Move generated UWP*.rsp files to ..\SDKResponseFiles
5) Run the compiler against the new UWPPlusAllExtensions.my_sdkver.rsp
6) Update other scripts if moving the internal build to the new projection
7) Update internal projection with new scripts
8) Check in changes
9) Publish full headers to GitHub
