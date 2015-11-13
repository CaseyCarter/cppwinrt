#pragma once

#include "Output.h"

namespace Modern {

void WriteEnumerations(Output & out);
void WriteStructures(Output & out);
void WriteDeclarations(Output & out);
void WriteAbiInterfaceDeclarations(Output & out);
void WriteAbiClassDeclarations(Output & out);
void WriteInterfaces(Output & out, Output & methods, Output & abi);
void WriteGenericInterfaces(Output & abi);
void WriteClasses(Output & out, Output & methods);
void WriteDelegates(Output & out);
void WriteImplementation(Output & out);
void WriteInterfaceDefinitions(Output & out);
void WriteOverrides(Output & output);
void WriteComposable(Output & output);

void WriteComponentClassHeader(Output & output);
void WriteComponentClassSource(Output & output);

}
