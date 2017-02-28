#pragma once

#include "Output.h"

namespace Modern {

void WriteEnumerations(Output & out);
void WriteStructures(Output & out);
void WriteAbiClassDeclarations(Output & out);
void WriteAbiInterfaces(Output & out);
void WriteInterfacesMethodDefinitions(Output & out);
void WriteInterfaceConsumers(Output & out);
void WriteGenericInterfaces(Output & out);
void WriteClassDeclarations(Output & out);
void WriteClassDefinitions(Output & out);
void WriteDelegates(Output & out);
void WriteInterfaceTraits(Output & out);
void WriteInterfaceDefinitions(Output & out);
bool WriteOverrides(Output & out);
bool WriteComposable(Output & out);
void WriteInterfaceProducers(Output & out);
void WriteForwards(Output & out);
void WriteInterfaceImplForwards(Output & out);
void WriteRequiredAbiHeadersForAbi(Output & out);
void WriteRequiredAbiHeadersForInterface(Output & out);
void WriteRequiredForwards(Output & out);
void WriteRequiredInterfaceIncludes(Output & out);
void WriteRequiredClasses(Output & out);
void WriteDelegateShims(Output & out);
void WriteRequiredOverrides(Output & out);
void WriteDefinitionsForRequiredInterfaces(Output & out);
void WriteHashes(Output & out);
}
