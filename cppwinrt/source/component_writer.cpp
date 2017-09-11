#include "pch.h"
#include "code_writer.h"
#include "settings.h"
#include "text_writer.h"
#include "strings.h"
#include "version.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    void write_component_headers(std::set<std::string> const& projected_namespaces)
    {
        meta::index_type const& index = meta::get_index();
        std::vector<meta::type const*> types;

        for (meta::index_pair const& pair : index)
        {
            for (meta::type const& type : pair.second.classes)
            {
                if (type.is_filtered())
                {
                    types.push_back(&type);
                }
            }
        }

        write_component_header(types, projected_namespaces);
        write_component_source(types);
        write_component_project(types);
        write_component_project_filters(types);
        write_component_pch_source();
        write_component_pch_header();
        write_component_def();

        for (meta::type const* type : types)
        {
            write_component_class_generated_header(*type);
            write_component_class_header(*type);
            write_component_class_source(*type);
        }
    }
}
