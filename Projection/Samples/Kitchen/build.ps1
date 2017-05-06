if ($env:VisualStudioVersion -eq $null)
{
	throw "VSVars not configured"
}

$repoRootDir = "..\..\.."
if (-not (test-path (join-path $repoRootDir cppwinrt\x86\release\cppwinrt.exe)))
{
	throw "X86 Release cppwinrt.exe not compiled"
}

if (-not (test-path (join-path $repoRootDir DevProjection)))
{
	throw "DevProjection not generated"
}

$nugetLocalFolder = Join-Path $env:LocalAppData cppwinrt.nuget
if (-not (test-path $nugetLocalFolder)) {
	mkdir $nugetLocalFolder | out-null
}

$nugetLatestUri = [System.Uri]"https://dist.nuget.org/win-x86-commandline/v4.1.0/nuget.exe"
$nugetFileName = Split-Path $nugetLatestUri.AbsolutePath -Leaf
$nugetFilePath = Join-Path $nugetLocalFolder $nugetFileName

if (test-path $nugetFilePath)
{
	Write-Output "$nugetFileName already downloaded"
}
else
{
	Write-Output "downloading $nugetFileName v4.1.0"
	Invoke-WebRequest $nugetLatestUri -OutFile $nugetFilePath
	unblock-file $nugetFilePath
}

& $nugetFilePath restore Kitchen.sln
msbuild.exe /p:Platform=x86