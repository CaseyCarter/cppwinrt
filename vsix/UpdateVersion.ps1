# Update the version number of the VSIX based on the current cppwinrt build version

$man = New-Object System.Xml.XmlDocument
$man.Load("source.extension.vsixmanifest")
$ver = Select-String "..\cppwinrt\source\version.h" -pattern '\"(.*)\"'
$man.PackageManifest.Metadata.Identity.Version = $ver.Matches[0].Groups[1].ToString()
$man.Save("source.extension.vsixmanifest")
