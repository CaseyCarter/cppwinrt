// ------------------------------------------------------------------------------------
// Copyright(c) Microsoft Corporation.  All rights reserved.
// ------------------------------------------------------------------------------------

import * as Sdk from "Sdk.OSGTools";
import * as NativeFacade from "Sdk.OSGTools.NativeFacade";
import * as NativeSdk from "Sdk.Native";
import * as LegacySdk from "Sdk.Legacy";
import {Artifact, Cmd, Tool, Transformer} from "Sdk.Transformers";
import {BatchScript} from "BatchScript";

namespace Build.CppWinRT {
    const base_headers: StaticDirectory = Transformer.sealSourceDirectory(
        d`../strings/base`,
        Transformer.SealSourceDirectoryOption.topDirectoryOnly);
        
    const print_headers: StaticDirectory = Transformer.sealSourceDirectory(
        d`../strings/print`,
        Transformer.SealSourceDirectoryOption.topDirectoryOnly);
        
    const write_headers: StaticDirectory = Transformer.sealSourceDirectory(
        d`../strings/write`,
        Transformer.SealSourceDirectoryOption.topDirectoryOnly);
        
    const strings_directory = Context.getNewOutputDirectory("strings");
    const strings_h_file = strings_directory.combine("strings.h");
    const strings_cpp_file = strings_directory.combine("strings.cpp");

    const strings_h = BatchScript.runScript({
        tool: { exe: f`../strings/make_strings.cmd` },
        dependencies: [
            base_headers,
            print_headers,
            write_headers,
        ],
        arguments: [
            Cmd.argument("h"),
            Cmd.argument(">"),
            Cmd.argument(Artifact.output(strings_h_file)),
        ],
        workingDirectory: d`.`,
    });

    const strings_h_sealdir = Transformer.sealPartialDirectory(strings_directory, strings_h.getOutputFiles());
    
    const strings_cpp = BatchScript.runScript({
        tool: { exe: f`../strings/make_strings.cmd` },
        dependencies: [
            base_headers,
            print_headers,
            write_headers,
        ],
        arguments: [
            Cmd.argument("cpp"),
            Cmd.argument(">"),
            Cmd.argument(Artifact.output(strings_cpp_file)),
        ],
        workingDirectory: d`.`,
    });        

    // DEF: Build.CppWinRT.cppwinrt_exe
    export const cppwinrt_exe = NativeFacade.buildNativeExe(
        {
            innerTemplates: {
                clRunner: {
                    disableSpecificWarnings: [4702],
                    enableCoroutines: true,
                    enablePreFast: false,
                    languageVersion: NativeSdk.Cl.LanguageVersion.cppLatest,
					optimizations: ((): NativeSdk.Cl.Optimizations => {
						if (qualifier.configuration === "debug") return {optimizationMode: NativeSdk.Cl.OptimizationMode.disabled};
						// Temporary: Disable optimizations to work around coroutine stack overflow
						return { optimizationMode: NativeSdk.Cl.OptimizationMode.disabled };
						// return { optimizationMode: NativeSdk.Cl.OptimizationMode.maximizeSpeed };
					})(),
					runtimeLibrary: (() => {
                        if (qualifier.configuration === "debug") return NativeSdk.Cl.RuntimeLibrary.multithreadedDebug;
                        return NativeSdk.Cl.RuntimeLibrary.multithreaded;
                    })(),
                    treatWchartAsBuiltInType: true,
                },
                linkRunner: {
                    ignoreAllDefaultLibraries: false,
			        ignoreWarnings: [4099],
                    subsystem: importFrom("CompilerTools.Sdk.Native").SubsystemType.console,
                    //verbose: NativeSdk.Link.Verbose.enabled,
                },
            },
            outputFileName: PathAtom.create("cppwinrt"),
//            precompiledHeaderName: a`pch.h`,
            sources: [
                f`code_writer.cpp`,
                f`component_writer.cpp`,
                f`main_cppwinrt.cpp`,
                f`projection_writer.cpp`,
                f`settings.cpp`,
                f`winmd_reader.cpp`,
                strings_cpp.getOutputFile(strings_cpp_file),
                f`version.rc`,
            ],
            includes: [
                f`base.h`,
                f`code_writer.h`,
                f`component_writer.h`,
                f`generator.h`,
                f`helpers.h`,
                f`pch.h`,
                f`projection_writer.h`,
                f`reference_writer.h`,
                f`sdk.h`,
                f`settings.h`,
                f`text_writer.h`,
                f`version.h`,
                f`winmd_reader.h`,
                base_headers,
                strings_h_sealdir,
                importFrom("Net_Framework_SDK").Microsoft.CompilerTools.include,
                importFrom("VisualCpp.Corext").Microsoft.CompilerTools.VisualCpp.include,
                importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.Shared.include,
                importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.Ucrt.include,
                importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.UM.include,
                importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.Winrt.include,
            ],
            libraries: [
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/advapi32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/gdi32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/kernel32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/odbc32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/ole32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/oleaut32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/rometadata.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/shell32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/user32.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/uuid.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/WindowsApp_downlevel.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/OneCoreUAP.lib`,
                f`${importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.libFolder}/shlwapi.lib`,
                f`${importFrom("VisualCpp.Corext").Microsoft.CompilerTools.VisualCpp.lib}/app/oldnames.lib`,
                importFrom("VisualCpp.Corext").Microsoft.CompilerTools.VisualCpp.lib,
                importFrom("WindowsSdk.Corext").Microsoft.CompilerTools.WindowsSdk.Ucrt.lib,
            ],
        }
    );
    
    export const deploy_cppwinrt_exe = Sdk.targetDeployment({binaryObjects: [cppwinrt_exe]});
}