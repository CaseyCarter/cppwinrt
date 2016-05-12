#pragma once

#include "Output.h"

namespace Modern {

void WriteEnumerations(Output & out);
void WriteStructures(Output & out);
void WriteDeclarations(Output & out);
void WriteAbiInterfaceDeclarations(Output & out);
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
void WriteOverrides(Output & out);
void WriteComposable(Output & out);
void WriteInterfaceProducers(Output & out);

}
