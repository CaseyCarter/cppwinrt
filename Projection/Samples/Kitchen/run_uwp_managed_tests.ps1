# Note, to run the UWP tests from the command line, the uwp_managed_tests_TemporaryKey.pfx 
# must be added to the local machine's Trusted Root Certificate Authorities store.
# Details on Stack Overflow: 
#   * http://stackoverflow.com/questions/33771590/running-universal-windows-unit-tests-from-the-command-line

$tstpkg = get-childitem .\uwp_managed_tests\AppPackages\Kitchen_uwp_managed_tests_*\Kitchen_uwp_managed_tests_*.appx  | 
	Sort-Object -Property Name -Descending | 
	Select-Object -First 1

vstest.console.exe $tstpkg.FullName /inisolation
