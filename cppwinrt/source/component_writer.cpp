#include "pch.h"
#include "code_writer.h"
#include "settings.h"
#include "text_writer.h"
#include "strings.h"
#include "version.h"

using namespace std::experimental::filesystem;

namespace cppwinrt
{
    void write_header()
    {
        output out;
        write_projection(out);

        path filename = settings::output / settings::first_input.filename();
        filename.replace_extension(".h");
        out.save_as(filename.string());
    }

    void create_natvis(std::vector<meta::type const*> types)
    {
        output out;
        write_natvis(out, types);
        path filename = settings::output / settings::first_input.filename();
        filename.replace_extension(".natvis");
        out.save_as(filename.string());
    }

    void write_component()
    {
        write_header();

        meta::index_type const& index = meta::get_index();
        std::vector<meta::type const*> types;

        for (meta::index_pair const& ns : index)
        {
            for (meta::type const& type : ns.second)
            {
                if (!type.is_filtered())
                {
                    types.push_back(&type);
                }
            }
        }

        write_component_header(types);
        write_component_source(types);

        for (meta::type const* type : types)
        {
            if (type->is_class())
            {
                write_component_class_generated_header(*type);
                write_component_class_header(*type);
                write_component_class_source(*type);
            }
        }

        if (settings::create_natvis)
        {
            create_natvis(types);
        }
    }
}
