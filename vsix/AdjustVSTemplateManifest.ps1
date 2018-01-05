param (
    [string]$vsix
)

# Insert a VSTemplateDir element into the generated project template manifest to rename category to "C++/WinRT"
write-host "Adjusting project template manifest"
$temp_vsix = ".\__temp_vsix"
Remove-Item $temp_vsix -ErrorAction SilentlyContinue -Force -Recurse
Add-Type -Assembly System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::ExtractToDirectory($vsix, $temp_vsix)
$vstemplatedir = New-Object System.Xml.XmlDocument
$vstemplatedir.Load(".\ProjectTemplates\VSTemplateDir.vstman")
$vstman = New-Object System.Xml.XmlDocument
$vstman_path = $temp_vsix + "\ProjectTemplates\templateManifest0.noloc.vstman";
$vstman.Load($vstman_path)
$child = $vstman.ImportNode($vstemplatedir.VSTemplateManifest.VSTemplateDir, $true)
$dontcare = $vstman.DocumentElement.AppendChild($child)
$vstman.Save($vstman_path)
Remove-Item $vsix -Force
[System.IO.Compression.ZipFile]::CreateFromDirectory($temp_vsix, $vsix, [System.IO.Compression.CompressionLevel]::Optimal, $false)
Remove-Item $temp_vsix -Force -Recurse
