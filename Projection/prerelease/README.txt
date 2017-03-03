How to generate a prerelease projection:

1) Run GenerateResponseFiles.cmd <sdk_ver>
2) Make a union of the response files called all.rsp if you want a projection with everything. This is what we release. Note that
   the extension SDK rsp files do not have the UAP.rsp entries. They need these to work. Just copy paste UAP.rsp. The extension
   SDKs have duplicates. Remove those.
3) Run PrereleaseProjection.cmd <response_file> <output_folder> to create the projection