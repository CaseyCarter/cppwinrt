#include "pch.h"
#include "code_writer.h"
#include "reference_writer.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    void write_component_headers()
    {
        meta::index_type const& index = meta::get_index();
        std::vector<meta::type const*> types;
        std::map<std::string, reference_writer> ref_writers;
        std::set<std::string> ref_namespaces;

        for (meta::index_pair const& pair : index)
        {
            for (meta::type const& type : pair.second.classes)
            {
                if (type.is_filtered())
                {
                    std::string type_ns{ type.name_space() };
                    if (ref_writers.find(type_ns) == ref_writers.end())
                    {
                        auto& ref_writer = ref_writers.emplace(type_ns, 
                            reference_writer{ type_ns, index.at(type_ns), false }).first->second;
                        auto& method_namespaces = ref_writer.get_method_namespaces();
                        ref_namespaces.insert(method_namespaces.begin(), method_namespaces.end());
                        auto& required_namespaces = ref_writer.get_required_namespaces();
                        ref_namespaces.insert(required_namespaces.begin(), required_namespaces.end());
                    }
                    types.push_back(&type);
                }
            }
        }

        write_component_header(types);
        write_component_source(types);
        for (meta::type const* type : types)
        {
            std::string type_ns(type->name_space());
            write_component_class_generated_header(*type, ref_writers.at(type_ns));
            write_component_class_header(*type);
            write_component_class_source(*type);
        }
    }
}
